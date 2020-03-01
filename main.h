#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "lua/lua.h"
#include "lua/lauxlib.h"
#include "raylib/raylib.h"
#include "raylib/raylib.h"
#include "raylib/raymath.h"
#define luax_tnfunction(L, index, func)  lua_pushnumber(L, index); lua_pushcfunction(L, func); lua_rawset(L, -3)
#define luax_tsfunction(L, name,  func)  lua_pushstring(L, name);  lua_pushcfunction(L, func); lua_rawset(L, -3)
#define luax_tnnumber(L,   index, value) lua_pushnumber(L, index); lua_pushnumber(L, value);   lua_rawset(L, -3)
#define luax_tsnumber(L,   name,  value) lua_pushstring(L, name);  lua_pushnumber(L, value);   lua_rawset(L, -3)
#define luax_tnstring(L,   index, value) lua_pushnumber(L, index); lua_pushstring(L, value);   lua_rawset(L, -3)
#define luax_tsstring(L,   name,  value) lua_pushstring(L, name);  lua_pushstring(L, value);   lua_rawset(L, -3)

#define luax_optnumber(L,  idx, default) lua_isnumber(L, idx) ? luaL_checknumber(L, idx)  : default
#define luax_optinteger(L, idx, default) lua_isnumber(L, idx) ? luaL_checkinteger(L, idx) : default
#define luax_optstring(L,  idx, default) lua_isstring(L, idx) ? luaL_checkstring(L, idx)  : default

#define luax_typename(L, idx)  luaL_typename(L, idx)
#define luax_type(L, idx, typeenum)  lua_type(L, idx) == typeenum


void luax_printstack(lua_State * L, const char * msg) {
	printf("Stack start: %s\n", msg);
	for (int i = 1; i <= lua_gettop(L); i++) {
		printf("  %d: %s - ", i, luaL_typename(L, i));
		int t = lua_type(L, i);

		switch (t) {
		case LUA_TSTRING:
			printf("%20s", lua_tostring(L, i));
		case LUA_TBOOLEAN:
			printf("%s", (lua_toboolean(L, i) ? "true" : "false"));
		case LUA_TNUMBER:
			printf("%f", lua_tonumber(L, i));
		}
		printf("\n");
	}
}

// stealed from luasocket repo
// https://github.com/diegonehab/luasocket/blob/master/src/auxiliar.c

void luax_newclass(lua_State *L, char * classname, luaL_Reg *func) {
	luaL_newmetatable(L, classname); // mt
	lua_newtable(L);                 // mt, ct
	lua_setfield(L, -2, "class_t");  // mt.class_t = ct
	lua_pushstring(L, "__index");    // mt, "__index"
	lua_getfield(L, -2, "class_t");  // mt, "__index", ct
	lua_pushstring(L, "class");      // mt, "__index", ct, "class"
	lua_pushstring(L, classname);    // mt, "__index", ct, "class", classname
	lua_rawset(L, -3);               // mt, "__index", ct
	// pass all methods that start with _ to the metatable, and all others to the index table
	bool usedIndex = 0;              // Checks custom index function
	for (; func->name; func++) {
		if (!strcmp(func->name, "__index")) usedIndex = true;
		lua_pushstring(L, func->name);
		lua_pushcfunction(L, func->func);
		bool v = func->name[0] == '_'; // if it is metamethod
		lua_rawset(L, v ? -5 : -3);    // assign it to metatable, otherwise assign to class table
	}
	if (usedIndex) return lua_pop(L, 3); // don't use class table as __index if custom index function provided

	lua_rawset(L, -3);               // mt.__index = classtable 
	lua_pop(L, 1);
}

int luax_getclasskeystr(lua_State *L, int objidx, const char * key){
  luaL_getmetafield(L, objidx, "class_t");
  lua_getfield(L, -1, key);
  lua_remove(L, -2); lua_remove(L, -2);
  return 1;
}

// used for __index metamethod (consumes given key), key should be on top of stack.
void luax_getclasskey(lua_State *L, int objidx, int keyidx){
  lua_settop(L, keyidx);
  luaL_getmetafield(L, objidx, "class_t"); // obj, .., key, class_t
  lua_insert(L, -2);   // obj, ... class_t, key
  lua_gettable(L, -2); // obj, class, class_t[key] = value
  lua_remove(L, -2); // obj, value
}

void luax_setclass(lua_State *L, const char *classname, int objidx) {
	luaL_getmetatable(L, classname);
	if (objidx < 0) objidx--;
	lua_setmetatable(L, objidx);
}

void * luax_newobject(lua_State *L, const char *classname, int size) {
	void * p = (void * )lua_newuserdata(L, size);
	luax_setclass(L, classname, -1);
	return p;
}

void * luax_checkclass(lua_State * L, int index, const char * classname) {
	return luaL_checkudata(L, index, classname);
}

// compare metatables
int luaobject_isclass(lua_State * L, int index, const char * classname) {
	if (lua_type(L, index) != LUA_TUSERDATA) return 0;
	if (!lua_getmetatable(L, index)) return 0; // mt
	luaL_getmetatable(L, classname);

	int res = lua_rawequal(L, -2, -1);
	lua_pop(L, 2);
	
	return res;
}

void luax_pushfunctable(lua_State *L, luaL_Reg *func){
	lua_newtable(L);
	for (; func->name; func++) {
		lua_pushstring(L,    func->name);
		lua_pushcfunction(L, func->func);
		lua_rawset(L, -3);
	}
}
