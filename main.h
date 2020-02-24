#include "stdio.h"
#include "string.h"
#include "lua/lua.h"
#include "lua/lauxlib.h"
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
#define luax_optstring(L, idx, default)  lua_isstring(L, idx) ? luaL_checkstring(L, idx)  : default

#define luax_typename(L, idx)  luaL_typename(L, idx)


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
	luaL_newmetatable(L, classname); /* mt */
	lua_pushstring(L, "__index");    /* mt,"__index" */
	lua_newtable(L);                 /* mt,"__index",it */
	lua_pushstring(L, "class");      /* mt,"__index",it,"class" */
	lua_pushstring(L, classname);    /* mt,"__index",it,"class",classname */
	lua_rawset(L, -3);               /* mt,"__index",it */
	/* pass all methods that start with _ to the metatable, and all others
	 * to the index table */
	for (; func->name; func++) {     /* mt,"__index",it */
		lua_pushstring(L, func->name);
		lua_pushcfunction(L, func->func);
		bool v = func->name[0] == '_';
		printf("Push method %s to %s\n", func->name, v ? "meta" : "base");
		lua_rawset(L, v ? -5 : -3);
	}
	lua_rawset(L, -3);               /* mt */
	lua_pop(L, 1);
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

