// used for __index and __newindex metamethods
#define lua_class_GetFieldIfCompared(L, obj, key, cmpkey, structfield)\
        if(!strcmp(key, cmpkey)){              \
          lua_pushnumber(L, obj->structfield); \
          return 1;                            \
        }
#define lua_class_SetFieldIfCompared(L, obj, key, value, cmpkey, structfield) \
        if(!strcmp(key, cmpkey)){   \
          obj->structfield = value; \
          return 0;                 \
        }

/*!MD
# Classes
## Vector2

Structure:

| Field  | Type  |
| :----- | :---- |
| x      | float |
| y      | float |

| **Methods**                      | description 
| :-----                           | :-----------
| [clone](#Vector2clone)           | Creates copy of vector
| [get](#Vector2get)               | Returns vector fields
| [set](#Vector2set)               | Assing values to vector
| [add](#Vector2add)               | Add vector to vector (modifying it)
| [subtract](#Vector2subtract)     | Subtract vector from vector (modifying it)
| [length](#Vector2length)         | Returns vector scalar length
| [dotProcuct](#Vector2dotProduct) | Returns vector scalar dot product
| [distance](#Vector2distance)     | Returns scalar distance between two vectors
| [angle](#Vector2angle)           | Returns scalar angle between two vectors (degrees)
| [angleRad](#Vector2angleRad)     | Returns scalar angle between two vectors (radians)
| [scale](#Vector2scale)           | Multiply each component of vector to scalar
| [multiplyV](#Vector2multiplyV)   | Multiply vector to another vector (modifying it)
| [multiply](#Vector2multiply)     | Multiply vector to scalar or another vector (modifying it)
| [negate](#Vector2negate)         | Negate each component of vector (-Vec2.x, -Vec2.y)
| [divide](#Vector2divide)         | Divide vector to scalar or another vector (modifying it)
| [divideV](#Vector2divideV)       | Divide vector to another vector (modifying it)
| [normalize](#Vector2normalize)   | Normalize vector (divide each component lo vector length)
| [lerp](#Vector2lerp)             | Interpolate vector to another by given interpolant
| **Overloads**                    | Note: In the mul/div methods with numbers, the vector should be in FIRST place, `NewVec2 = Vec2 * 5` is ok `NewVec2 = 5 * Vec2` raises error
| +: `NewVec2 = Vec2A + Vec2B`     | Create a new vector that is the sum of two vectors
| -: `NewVec2 = Vec2A - Vec2B`     | Create a new vector that is the subtraction of two vectors
| *: `NewVec2 = Vec2A * Vec2B`     | Create a new vector that is the multiplication of two vectors
| *: `NewVec2 = Vec2 * Num`        | Create a new vector that is the multiplication of vector by number (scale)
| /: `NewVec2 = Vec2A / Vec2B`     | Create a new vector that is the division of two vectors
| /: `NewVec2 = Vec2 / Num`        | Create a new vector that is the division of vector by number (divide each vector component)
| #: `Len = #Vec2A`                | Returns vector scalar length (:length shortcut)
| ^: `NewVec2 = Vec2A ^ VecB`      | Create a new vector that is the power of two vectors
| ^: `NewVec2 = Vec2 ^ Num`        | Create a new vector that is the power of vector to number
| =: `isEqual = Vec2A == Vec2B`    | Checks vectors equality
| -: `negVec2 = -Vec2`             | Creates new vector that is negate of another

### Initialization
```lua
-- variants
Vector2 Vec = rl.Vector2(number x, number y) --> vec2[x, y]
Vector2 Vec = rl.Vector2(number x)           --> vec2[x, x]
Vector2 Vec = rl.Vector2(table t)            --> vec2[ t[1], t[2] ]
```
Creates new Vector2 object
*/
int lua_class_vector2_new(lua_State *L){
  Vector2 * v = (Vector2 *)luax_newobject(L, "Vector2", sizeof(Vector2));
  if (lua_isnumber(L, 1)) {
    v->x = luaL_checkinteger(L, 1);
    v->y = luax_optnumber(L, 2, v->x);
    return 1;
  }
  if (lua_istable(L, 1)) {
    lua_rawgeti (L, 1, 1); lua_rawgeti (L, 1, 2);
    v->x = luax_optnumber(L, -2, 0);
    v->y = luax_optnumber(L, -1, 0);
    lua_pop(L, 2);
    return 1;
  }
  else{
    v->x = 0; 
    v->y = 0;
  }
  return 1;
}

/*!MD
### Methods

#### Vector2:clone
```lua
Vector2 Vec2 = Vector2:clone()
```
Clones Vector2 object.
*/
int lua_class_vector2_Clone(lua_State *L){
  Vector2 * v1 = (Vector2 *)luaL_checkudata(L, 1, "Vector2");
  Vector2 * v2 = (Vector2 *)luax_newobject(L, "Vector2", sizeof(Vector2));
  v2->x = v1->x; v2->y = v1->y;
  return 1;
}

/*!MD
#### Vector2:get
```lua
-- variants
number x, number y = Vector2:get()
table t = Vector2:get('t') --> {x, y}
```
Get Vector2 components.
*/
int lua_class_vector2_Get(lua_State *L){
  Vector2 * v = (Vector2 *)luaL_checkudata(L, 1, "Vector2");
  if (luax_optstring(L, 2, "\0")[0] == 't'){
    lua_newtable(L);
    luax_tnnumber(L, 1, (float)v->x);
    luax_tnnumber(L, 2, (float)v->y);
    return 1;
  }
  lua_pushnumber(L, v->x);
  lua_pushnumber(L, v->y);
  return 2;
}

/*!MD
#### Vector2:set
```lua
-- variants
Vector2:set(float x, float y)
Vector2:set(table t) -- [x, y]
```
Set Vector2 components.
*/
int lua_class_vector2_Set(lua_State *L){
  Vector2 * v = (Vector2 *)luaL_checkudata(L, 1, "Vector2");
  v->x = luax_optnumber(L, 2, v->x);
  v->y = luax_optnumber(L, 3, v->y);
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Vector2:add
```lua
Vector2:add(Vector2 Vector)
```
Add vector to vector (modifying it)
*/
int lua_class_vector2_Add(lua_State *L){
  Vector2 * v1 = (Vector2 *)luaL_checkudata(L, 1, "Vector2");
  Vector2 * v2 = (Vector2 *)luaL_checkudata(L, 2, "Vector2");
  v1->x += v2->x; v1->y += v2->y;
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Vector2:subtract
```lua
Vector2:subtract(Vector2 Vector)
```
Subtract vector from vector (modifying it)
*/
int lua_class_vector2_Subtract(lua_State *L){
  Vector2 * v1 = (Vector2 *)luaL_checkudata(L, 1, "Vector2");
  Vector2 * v2 = (Vector2 *)luaL_checkudata(L, 2, "Vector2");
  v1->x -= v2->x; v1->y -= v2->y;
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Vector2:length
```lua
number Length = Vector2:length()
```
Returns vector scalar length
*/
int lua_class_vector2_Length(lua_State *L){
  Vector2 * v = (Vector2 *)luaL_checkudata(L, 1, "Vector2");
  float result = sqrtf((v->x * v->x) + (v->y * v->y));
  lua_pushnumber(L, result);
  return 1;
}

/*!MD
#### Vector2:dotProduct
```lua
number Dot = Vector2:dotProduct(Vector2 Vector)
```
Returns vector scalar dot product
*/
int lua_class_vector2_DotProduct(lua_State *L){
  Vector2 * v1 = (Vector2 *)luaL_checkudata(L, 1, "Vector2");
  Vector2 * v2 = (Vector2 *)luaL_checkudata(L, 2, "Vector2");
  float result = (v1->x * v2->x + v1->y * v2->y);
  lua_pushnumber(L, result);
  return 1;
}

/*!MD
#### Vector2:distance
```lua
number Distance = Vector2:distance(Vector2 Vector)
```
Returns scalar distance between two vectors
*/
int lua_class_vector2_Distance(lua_State *L){
  Vector2 * v1 = (Vector2 *)luaL_checkudata(L, 1, "Vector2");
  Vector2 * v2 = (Vector2 *)luaL_checkudata(L, 2, "Vector2");
  float result = sqrtf((v1->x - v2->x)*(v1->x - v2->x) + (v1->y - v2->y)*(v1->y - v2->y));
  lua_pushnumber(L, result);
  return 1;
}

/*!MD
#### Vector2:angle
```lua
number Angle = Vector2:angle(Vector2 Vector)
```
Returns scalar angle between two vectors (degrees)
*/
int lua_class_vector2_Angle(lua_State *L){
  Vector2 * v1 = (Vector2 *)luaL_checkudata(L, 1, "Vector2");
  Vector2 * v2 = (Vector2 *)luaL_checkudata(L, 2, "Vector2");
  float result = atan2f(v2->y - v1->y, v2->x - v1->x)*(180.0f/PI);
  if (result < 0) result += 360.0f;
  lua_pushnumber(L, result);
  return 1;
}

/*!MD
#### Vector2:angleRad
```lua
number Angle = Vector2:angleRad(Vector2 Vector)
```
Returns scalar angle between two vectors (radians)
*/
int lua_class_vector2_AngleRad(lua_State *L){
  Vector2 * v1 = (Vector2 *)luaL_checkudata(L, 1, "Vector2");
  Vector2 * v2 = (Vector2 *)luaL_checkudata(L, 2, "Vector2");
  float result = atan2f(v2->y - v1->y, v2->x - v1->x);
  if (result < 0) result += 2*PI;
  lua_pushnumber(L, result);
  return 1;
}

/*!MD
#### Vector2:scale
```lua
Vector2:scale(number Scale)
```
Multiply each component of vector to scalar
*/
int lua_class_vector2_Scale(lua_State *L){
  Vector2 * v1 = (Vector2 *)luaL_checkudata(L, 1, "Vector2");
  float n = luaL_checknumber(L, 2);
  v1->x *= n; v1->y *= n;
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Vector2:multiplyV
```lua
Vector2:multiplyV(Vector2 Vector)
```
Multiply vector to another vector (modifying it)
*/
int lua_class_vector2_MultiplyV(lua_State *L){
  Vector2 * v1 = (Vector2 *)luaL_checkudata(L, 1, "Vector2");
  Vector2 * v2 = (Vector2 *)luaL_checkudata(L, 2, "Vector2");
  v1->x *= v2->x; v1->y *= v2->y;
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Vector2:multiply
```lua
-- variants
Vector2:multiply(Vector2 Vector)
Vector2:multiply(number Scale)
```
Multiply vector to scalar or another vector (modifying it)
*/
int lua_class_vector2_Multiply(lua_State *L){
  Vector2 * v1 = (Vector2 *)luaL_checkudata(L, 1, "Vector2");
  if (lua_isnumber(L, 2)){
    float n = luaL_checknumber(L, 2);
    v1->x *= n; v1->y *= n;
    lua_settop(L, 1);
    return 1;
  }

  Vector2 * v2 = (Vector2 *)luaL_checkudata(L, 2, "Vector2");
  v1->x *= v2->x; v1->y *= v2->y;
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Vector2:negate
```lua
Vector2:negate()
```
Negate each component of vector (-Vec2.x, -Vec2.y)
*/
int lua_class_vector2_Negate(lua_State *L){
  Vector2 * v = (Vector2 *)luaL_checkudata(L, 1, "Vector2");
  v->x = -v->x; v->y = -v->y;
  return 1;
}

/*!MD
#### Vector2:divide
```lua
-- variants
Vector2:divide(Vector2 Vector)
Vector2:divide(number Scale)
```
Divide vector to scalar or another vector (modifying it)
*/
int lua_class_vector2_Divide(lua_State *L){
  Vector2 * v1 = (Vector2 *)luaL_checkudata(L, 1, "Vector2");
  if (lua_isnumber(L, 2)){
    float n = luaL_checknumber(L, 2);
    v1->x /= n; v1->y /= n;
    lua_settop(L, 1);
    return 1;
  }

  Vector2 * v2 = (Vector2 *)luaL_checkudata(L, 2, "Vector2");
  v1->x /= v2->x; v1->y /= v2->y;
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Vector2:divideV
```lua
Vector2:divideV(Vector2 Vector)
```
Divide vector to another vector (modifying it)
*/
int lua_class_vector2_DivideV(lua_State *L){
  Vector2 * v1 = (Vector2 *)luaL_checkudata(L, 1, "Vector2");
  Vector2 * v2 = (Vector2 *)luaL_checkudata(L, 2, "Vector2");
  v1->x /= v2->x;
  v1->y /= v2->y;
  lua_pop(L, 1);
  return 1;
}

/*!MD
#### Vector2:normalize
```lua
Vector2:normalize()
```
Normalize vector (divide each component lo vector length)
*/
int lua_class_vector2_Normalize(lua_State *L){
  Vector2 * v   = (Vector2 *)luaL_checkudata(L, 1, "Vector2");
  float     len = sqrtf((v->x * v->x) + (v->y * v->y));
  v->x /= len; v->y /= len;
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Vector2:lerp
```lua
Vector2:lerp(Vector2 Vector, number Amount)
```
Interpolate vector to another by given interpolant
*/
int lua_class_vector2_Lerp(lua_State *L){
  Vector2 * v1 = (Vector2 *)luaL_checkudata(L, 1, "Vector2");
  Vector2 * v2 = (Vector2 *)luaL_checkudata(L, 2, "Vector2");
  float amount = luaL_checknumber(L, 3);

  v1->x = v1->x + amount * (v2->x - v1->x);
  v1->y = v1->y + amount * (v2->y - v1->y);
  lua_settop(L, 1);
  return 1;
}

int lua_class_vector2__Index(lua_State *L){
  if (!luax_type(L, 2, LUA_TSTRING)) return 0;
  Vector2 *    v   = (Vector2 *)luaL_checkudata(L, 1, "Vector2");
  const char * key = luaL_checkstring(L, 2);

  lua_class_GetFieldIfCompared(L, v, key, "x", x); // calls "return" from this function on success
  lua_class_GetFieldIfCompared(L, v, key, "y", y);
  
  luax_getclasskey(L, 1, 2);
  return 1;
}

int lua_class_vector2__Newindex(lua_State *L){
  if (!luax_type(L, 2, LUA_TSTRING)) return 0;
  Vector2 *    v     = (Vector2 *)luaL_checkudata(L, 1, "Vector2");
  const char * key   = luaL_checkstring(L, 2);
  float        value = luaL_checknumber(L, 3);
  lua_class_SetFieldIfCompared(L, v, key, value, "x", x);
  lua_class_SetFieldIfCompared(L, v, key, value, "y", y);
  return 0;
}

int lua_class_vector2__Add(lua_State *L){
  Vector2 * v1 = (Vector2 *)luaL_checkudata(L, 1, "Vector2");
  Vector2 * v2 = (Vector2 *)luaL_checkudata(L, 2, "Vector2");
  Vector2 * v3 = (Vector2 *)luax_newobject(L, "Vector2", sizeof(Vector2));
  *v3 = Vector2Add(*v1, *v2);
  return 1;
}

int lua_class_vector2__Sub(lua_State *L){
  Vector2 * v1 = (Vector2 *)luaL_checkudata(L, 1, "Vector2");
  Vector2 * v2 = (Vector2 *)luaL_checkudata(L, 2, "Vector2");
  Vector2 * v3 = (Vector2 *)luax_newobject(L, "Vector2", sizeof(Vector2));
  *v3 = Vector2Subtract(*v1, *v2);
  return 1;
}

int lua_class_vector2__Mul(lua_State *L){
  Vector2 * v1 = (Vector2 *)luaL_checkudata(L, 1, "Vector2");
  Vector2 * v3 = (Vector2 *)luax_newobject(L, "Vector2", sizeof(Vector2));
  if ( lua_isnumber(L, 2) ){
    *v3 = Vector2Scale(*v1, luaL_checknumber(L, 2));
    return 1;
  }
  Vector2 * v2 = (Vector2 *)luaL_checkudata(L, 2, "Vector2");
  *v3 = Vector2MultiplyV(*v1, *v2);
  return 1;
}

int lua_class_vector2__Div(lua_State *L){
  Vector2 * v1 = (Vector2 *)luaL_checkudata(L, 1, "Vector2");
  Vector2 * v2 = (Vector2 *)luaL_checkudata(L, 2, "Vector2");
  Vector2 * v3 = (Vector2 *)luax_newobject(L, "Vector2", sizeof(Vector2));
  *v3 = Vector2DivideV(*v1, *v2);
  return 1;
}

int lua_class_vector2__Pow(lua_State *L){
  Vector2 * v1 = (Vector2 *)luaL_checkudata(L, 1, "Vector2");
  Vector2 * v3 = (Vector2 *)luax_newobject(L, "Vector2", sizeof(Vector2));
  if ( lua_isnumber(L, 2) ){
    float n = luaL_checknumber(L, 2);
    v3->x = pow(v3->x, n);
    v3->y = pow(v3->y, n);
    return 1;
  }
  Vector2 * v2 = (Vector2 *)luaL_checkudata(L, 2, "Vector2");
  v3->x = pow(v3->x, v2->x);
  v3->y = pow(v3->y, v2->y);

  return 1;
}

int lua_class_vector2__Neg(lua_State *L){
  Vector2 * v1 = (Vector2 *)luaL_checkudata(L, 1, "Vector2");
  Vector2 * v2 = (Vector2 *)luax_newobject(L, "Vector2", sizeof(Vector2));
  *v2 = Vector2Negate(*v1);
  return 1;
}

int lua_class_vector2__Eq(lua_State *L){
  Vector2 * v1 = (Vector2 *)luaL_checkudata(L, 1, "Vector2");
  Vector2 * v2 = (Vector2 *)luaL_checkudata(L, 2, "Vector2");
  lua_pushboolean(L, (v1->x == v2->x) && (v1->y == v2->y));
  return 1;
}

int lua_class_vector2__ToString(lua_State *L){
  Vector2 * v = (Vector2 *)luaL_checkudata(L, 1, "Vector2");
  lua_pushfstring(L, "Vector2[%f, %f]: 0x%0.8x", v->x, v->y, v);
  return 1;
}

luaL_Reg luaray_class_vector2[] = {
  {"clone",      lua_class_vector2_Clone},
  {"get",        lua_class_vector2_Get},
  {"set",        lua_class_vector2_Set},
  {"add",        lua_class_vector2_Add},
  {"subtract",   lua_class_vector2_Subtract},
  {"length",     lua_class_vector2_Length},
  {"dotProduct", lua_class_vector2_DotProduct},
  {"distance",   lua_class_vector2_Distance},
  {"angle",      lua_class_vector2_Angle},
  {"angleRad",   lua_class_vector2_AngleRad},
  {"scale",      lua_class_vector2_Scale},
  {"multiplyV",  lua_class_vector2_MultiplyV},
  {"multiply",   lua_class_vector2_Multiply},
  {"negate",     lua_class_vector2_Negate},
  {"divide",     lua_class_vector2_Divide},
  {"divideV",    lua_class_vector2_DivideV},
  {"normalize",  lua_class_vector2_Normalize},
  {"lerp",       lua_class_vector2_Lerp},
  // meta
  {"__index",    lua_class_vector2__Index},
  {"__newindex", lua_class_vector2__Newindex},
  {"__add",      lua_class_vector2__Add},
  {"__sub",      lua_class_vector2__Sub},
  {"__mul",      lua_class_vector2__Mul},
  {"__div",      lua_class_vector2__Div},
  {"__pow",      lua_class_vector2__Pow},
  {"__unm",      lua_class_vector2__Neg},
  {"__eq",       lua_class_vector2__Eq},
  {"__len",      lua_class_vector2_Length},
  {"__tostring", lua_class_vector2__ToString},
  {NULL, NULL}
};

/*!MD
## Vector3

Structure:

| Field  | Type  |
| :----- | :---- |
| x      | float |
| y      | float |
| z      | float |

| **Methods**                                      | description 
| :-----                                           | :-----------
| [clone](#Vector3clone)                           | Creates copy of vector
| [get](#Vector3get)                               | Returns vector fields
| [set](#Vector3set)                               | Assing values to vector
| [add](#Vector3add)                               | Add vector to vector (modifying it)
| [subtract](#Vector3subtract)                     | Subtract vector from vector (modifying it)
| [scale](#Vector3scale)                           | Multiply each component of vector to scalar
| [multiplyV](#Vector3multiplyV)                   | Multiply vector to another vector (modifying it)
| [multiply](#Vector3multiply)                     | Multiply vector to scalar or another vector (modifying it)
| [crossProduct](#Vector3crossProduct)             | Transform vector to cross product of two vectors
| [perpendicular](#Vector3perpendicular)           | Calculate one vector perpendicular vector
| [length](#Vector3length)                         | Returns vector scalar length
| [dotProduct](#Vector3dotProduct)                 | Returns scalar dot product of two vectors
| [distance](#Vector3distance)                     | Returns scalar distance between two vectors
| [negate](#Vector3negate)                         | Negate each component of vector (-Vec3.x, -Vec3.y, -Vec3.z)
| [divide](#Vector3divide)                         | Divide vector to scalar or another vector (modifying it)
| [divideV](#Vector3divideV)                       | Divide vector to another vector (modifying it)
| [normalize](#Vector3normalize)                   | Normalize vector (divide each component lo vector length)
| [orthoNormalize](#Vector3orthoNormalize)         | Makes vectors normalized and orthogonal to each other
| [transform](#Vector3transform)                   | Transforms a vector by a given Matrix
| [rotateByQuaternion](#Vector3rotateByQuaternion) | Transform a vector by quaternion rotation
| [lerp](#Vector3lerp)                             | Interpolate vector to another by given interpolant
| [reflect](#Vector3reflect)                       | Calculate reflected vector to normal
| [min](#Vector3min)                               | Return min value for each pair of components
| [max](#Vector3max)                               | Return max value for each pair of components
| [barycenter](#Vector3barycenter)                 | Create new vector that is barycenter coordinates (u, v, w) for point p with respect to triangle (a, b, c)
| [angle](#Vector3angle)                           | Returns scalar angle between two vectors (degrees)
| [angleRad](#Vector3angleRad)                     | Returns scalar angle between two vectors (radians)
| **Overloads**                                    | Note: In the mul/div methods with numbers, the vector should be in FIRST place, `NewVec3 = Vec3 * 5` is ok `NewVec3 = 5 * Vec3` raises error
| +: `NewVec3 = Vec3A + Vec3B`                     | Create a new vector that is the sum of two vectors
| -: `NewVec3 = Vec3A - Vec3B`                     | Create a new vector that is the subtraction of two vectors
| *: `NewVec3 = Vec3A * Vec3B`                     | Create a new vector that is the multiplication of two vectors
| *: `NewVec3 = Vec3 * Num`                        | Create a new vector that is the multiplication of vector by number (scale)
| /: `NewVec3 = Vec3A / Vec3B`                     | Create a new vector that is the division of two vectors
| /: `NewVec3 = Vec3 / Num`                        | Create a new vector that is the division of vector by number (divide each vector component)
| #: `Len = #Vec3`                                 | Returns vector scalar length (:length shortcut)
| ^: `NewVec3 = Vec3A ^ Vec3B`                     | Create a new vector that is the power of two vectors
| ^: `NewVec3 = Vec3 ^ Num`                        | Create a new vector that is the power of vector to number
| =: `isEqual = Vec3A == Vec3B`                    | Checks vectors equality
| -: `NegVec3 = -Vec3`                             | Creates new vector that is negate of another

### Initialization
```lua
-- variants
Vector3 Vec3 = rl.Vector3(number x, number y, , number z) --> vec3[x, y, z]
Vector3 Vec3 = rl.Vector3(number x)                       --> vec3[x, x, x]
Vector3 Vec3 = rl.Vector3(table t)                        --> vec3[ t[1], t[2], t[3] ]
```
Creates new Vector3 object.
*/

int lua_class_vector3_new(lua_State *L){
  Vector3 * v = (Vector3 *)luax_newobject(L, "Vector3", sizeof(Vector3));
  if (lua_isnumber(L, 1)) {
    v->x = luaL_checkinteger(L, 1);
    v->y = luax_optnumber(L, 2, v->x);
    v->z = luax_optnumber(L, 3, v->x);
    return 1;
  }
  if (lua_istable(L, 1)) {
    lua_rawgeti (L, 1, 1); lua_rawgeti (L, 1, 2); lua_rawgeti (L, 1, 3);
    v->x = luax_optnumber(L, -3, 0.0f);
    v->y = luax_optnumber(L, -2, 0.0f);
    v->z = luax_optnumber(L, -1, 0.0f);
    lua_pop(L, 3);
    return 1;
  }
  else {
    v->x = 0.0f; v->y = 0.0f; v->z = 0.0f;
  }

  return 1;
}

/*!MD
### Methods

#### Vector3:clone
```lua
Vector3 Vec3 = Vector3:clone()
```
Clones Vector3 object.
*/
int lua_class_vector3_Clone(lua_State *L){
  Vector3 * v1 = (Vector3 *)luaL_checkudata(L, 1, "Vector3");
  Vector3 * v2 = (Vector3 *)luax_newobject(L, "Vector3", sizeof(Vector3));
  v2->x = v1->x; v2->y = v1->y; v2->z = v1->z;
  return 1;
}

/*!MD
#### Vector3:get
```lua
-- variants
number x, number y, number z = Vector3:get()
table t = Vector3:get('t') --> {x, y, z}
```
Get Vector3 components.
*/
int lua_class_vector3_Get(lua_State *L){
  Vector3 * v = (Vector3 *)luaL_checkudata(L, 1, "Vector3");
  if (luax_optstring(L, 2, "\0")[0] == 't'){
    lua_newtable(L);
    luax_tnnumber(L, 1, (float)v->x);
    luax_tnnumber(L, 2, (float)v->y);
    luax_tnnumber(L, 3, (float)v->z);
    return 1;
  }
  lua_pushnumber(L, v->x);
  lua_pushnumber(L, v->y);
  lua_pushnumber(L, v->z);
  return 3;
}

/*!MD
#### Vector3:set
```lua
-- variants
Vector3:set(number x, number y, number z)
Vector3:set(table t) -- [x, y, z]
```
Set Vector3 components.
*/
int lua_class_vector3_Set(lua_State *L){
  Vector3 * v = (Vector3 *)luaL_checkudata(L, 1, "Vector3");
  v->x = luax_optnumber(L, 2, v->x);
  v->y = luax_optnumber(L, 3, v->y);
  v->z = luax_optnumber(L, 4, v->z);
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Vector3:add
```lua
Vector3:add(Vector3 Vector)
```
Add vector to vector (modifying it)
*/
int lua_class_vector3_Add(lua_State *L){
  Vector3 * v1 = (Vector3 *)luaL_checkudata(L, 1, "Vector3");
  Vector3 * v2 = (Vector3 *)luaL_checkudata(L, 2, "Vector3");
  v1->x += v2->x;
  v1->y += v2->y;
  v1->z += v2->z;
  lua_settop(L, 1);
  return 1;
}

Vector3 * _ptr_vector3_Subtract(Vector3 * v1, Vector3 * v2){
  v1->x -= v2->x; v1->y -= v2->y; v1->z -= v2->z;
  return v1;
}

/*!MD
#### Vector3:subtract
```lua
Vector3:subtract(Vector3 Vector)
```
Subtract vector to vector (modifying it)
*/
int lua_class_vector3_Subtract(lua_State *L){
  Vector3 * v1 = (Vector3 *)luaL_checkudata(L, 1, "Vector3");
  Vector3 * v2 = (Vector3 *)luaL_checkudata(L, 2, "Vector3");
  _ptr_vector3_Subtract(v1, v2);
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Vector3:scale
```lua
Vector3:scale(number Scale)
```
Multiply each component of vector to scalar
*/
int lua_class_vector3_Scale(lua_State *L){
  Vector3 * v1 = (Vector3 *)luaL_checkudata(L, 1, "Vector3");
  float n = luaL_checknumber(L, 2);
  v1->x *= n; v1->y *= n; v1->z *= n;
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Vector3:multiplyV
```lua
Vector3:multiplyV(Vector3 Vector)
```
Multiply vector to another vector (modifying it)
*/
int lua_class_vector3_MultiplyV(lua_State *L){
  Vector3 * v1 = (Vector3 *)luaL_checkudata(L, 1, "Vector3");
  Vector3 * v2 = (Vector3 *)luaL_checkudata(L, 2, "Vector3");
  v1->x *= v2->x; v1->y *= v2->y; v1->z *= v2->z;
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Vector3:multiply
```lua
-- variants
Vector3:multiply(Vector3 Vector)
Vector3:multiply(number Scale)
```
Multiply vector to scalar or another vector (modifying it)
*/
int lua_class_vector3_Multiply(lua_State *L){
  Vector3 * v1 = (Vector3 *)luaL_checkudata(L, 1, "Vector3");
  if (lua_isnumber(L, 2)){
    float n = luaL_checknumber(L, 2);
    v1->x *= n; v1->y *= n; v1->z *= n;
    lua_settop(L, 1);
    return 1;
  }

  Vector3 * v2 = (Vector3 *)luaL_checkudata(L, 2, "Vector3");
  v1->x *= v2->x; v1->y *= v2->y; v1->z *= v2->z;
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Vector3:crossProduct
```lua
Vector3:crossProduct(Vector3 Vector)
```
Transform vector to cross product of two vectors
*/
Vector3 * _ptr_vector3_CrossProduct(Vector3 * v1, Vector3 * v2){
  v1->x = v1->y*v2->z - v1->z*v2->y;
  v1->y = v1->z*v2->x - v1->x*v2->z;
  v1->z = v1->x*v2->y - v1->y*v2->x;
  return v1;
}

int lua_class_vector3_CrossProduct(lua_State *L){
  Vector3 * v1 = (Vector3 *)luaL_checkudata(L, 1, "Vector3");
  Vector3 * v2 = (Vector3 *)luaL_checkudata(L, 2, "Vector3");
  _ptr_vector3_CrossProduct(v1, v2);
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Vector3:perpendicular
```lua
Vector3:perpendicular(Vector3 Vector)
```
Calculate one vector perpendicular vector
*/
int lua_class_vector3_Perpendicular(lua_State *L){
  Vector3 * v = (Vector3 *)luaL_checkudata(L, 1, "Vector3");
  Vector3   c = {1.0f, 0.0f, 0.0f};

  float min  = (float)fabs(v->x);
  float miny = (float)fabs(v->y);
  float minz = (float)fabs(v->z);

  if (miny < min){
    min = miny;
    Vector3 tmp = {0.0f, 1.0f, 0.0f};
    c = tmp;
  }

  if (minz < min){
    Vector3 tmp = {0.0f, 0.0f, 1.0f};
    c = tmp;
  }

  v->x = v->y*c.z - v->z*c.y;
  v->y = v->z*c.x - v->x*c.z;
  v->z = v->x*c.y - v->y*c.x;
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Vector3:length
```lua
number Length = Vector3:length()
```
Returns vector scalar length
*/
int lua_class_vector3_Length(lua_State *L){
  Vector3 * v = (Vector3 *)luaL_checkudata(L, 1, "Vector3");
  float result = sqrtf(v->x*v->x + v->y*v->y + v->z*v->z);
  lua_pushnumber(L, result);
  return 1;
}

/*!MD
#### Vector3:dotProduct
```lua
number Dot = Vector3:dotProduct(Vector3 Vector)
```
Returns scalar dot product of two vectors
*/
float _ptr_vector3_DotProduct(Vector3 * v1, Vector3 * v2){
  return sqrtf(v1->x*v2->x + v1->y*v2->y + v1->z*v2->z);
}

int lua_class_vector3_DotProduct(lua_State *L){
  Vector3 * v1 = (Vector3 *)luaL_checkudata(L, 1, "Vector3");
  Vector3 * v2 = (Vector3 *)luaL_checkudata(L, 2, "Vector3");
  float result = _ptr_vector3_DotProduct(v1, v2);
  lua_pushnumber(L, result);
  return 1;
}

/*!MD
#### Vector3:distance
```lua
number Distance = Vector3:distance(Vector3 Vector)
```
Returns scalar distance between two vectors
*/
int lua_class_vector3_Distance(lua_State *L){
  Vector3 * v1 = (Vector3 *)luaL_checkudata(L, 1, "Vector3");
  Vector3 * v2 = (Vector3 *)luaL_checkudata(L, 2, "Vector3");
  float dx = v2->x - v1->x;
  float dy = v2->y - v1->y;
  float dz = v2->z - v1->z;
  float result = sqrtf(dx*dx + dy*dy + dz*dz);
  lua_pushnumber(L, result);
  return 1;
}

/*!MD
#### Vector3:negate
```lua
Vector3:negate()
```
Negate each component of vector (-Vec3.x, -Vec3.y, -Vec3.z)
*/
int lua_class_vector3_Negate(lua_State *L){
  Vector3 * v = (Vector3 *)luaL_checkudata(L, 1, "Vector3");
  v->x = -v->x; v->y = -v->y; v->z = -v->z;
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Vector3:divide
```lua
-- variants
Vector3:divide(Vector3 Vector)
Vector3:divide(number Scale)
```
Divide vector to scalar or another vector (modifying it)
*/
int lua_class_vector3_Divide(lua_State *L){
  Vector3 * v1 = (Vector3 *)luaL_checkudata(L, 1, "Vector3");
  if (lua_isnumber(L, 2)){
    float n = luaL_checknumber(L, 2);
    v1->x /= n; v1->y /= n; v1->z /= n;
    lua_settop(L, 1);
    return 1;
  }

  Vector3 * v2 = (Vector3 *)luaL_checkudata(L, 2, "Vector3");
  v1->x /= v2->x; v1->y /= v2->y; v1->z /= v2->z;
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Vector3:divideV
```lua
Vector3:divideV(Vector3 Vector)
```
Divide vector to another vector (modifying it)
*/
int lua_class_vector3_DivideV(lua_State *L){
  Vector3 * v1 = (Vector3 *)luaL_checkudata(L, 1, "Vector3");
  Vector3 * v2 = (Vector3 *)luaL_checkudata(L, 2, "Vector3");
  v1->x /= v2->x; v1->y /= v2->y; v1->z /= v2->z;
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Vector3:normalize
```lua
Vector3:normalize()
```
Normalize vector (divide each component lo vector length)
*/
Vector3 * _ptr_vector3_Normalize(Vector3 * v){
  float l, il;
  l = Vector3Length(*v);
  if (l == 0.0f) l = 1.0f;
  il = 1.0f/l;

  v->x *= il; v->y *= il; v->z *= il;
  return v;
}

int lua_class_vector3_Normalize(lua_State *L){
  Vector3 * v = (Vector3 *)luaL_checkudata(L, 1, "Vector3");
  _ptr_vector3_Normalize(v);
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Vector3:orthoNormalize
```lua
Vector3:orthoNormalize(Vector3 Vector)
```
Makes vectors normalized and orthogonal to each other modifying both
*/
int lua_class_vector3_OrthoNormalize(lua_State *L){
  Vector3 * v1 = (Vector3 *)luaL_checkudata(L, 1, "Vector3");
  Vector3 * v2 = (Vector3 *)luaL_checkudata(L, 2, "Vector3");

  _ptr_vector3_Normalize(v1);
  Vector3 vn = {v1->x, v1->y, v1->z};
  _ptr_vector3_CrossProduct(&vn, v2);
  _ptr_vector3_Normalize(&vn);
  _ptr_vector3_CrossProduct(&vn, v1);
  *v2 = vn;
  lua_settop(L, 2);
  return 2;
}

/*!MD
#### Vector3:transform
```lua
Vector3:transform(Matrix Matrix)
```
Transforms a vector by a given Matrix
*/
int lua_class_vector3_Transform(lua_State *L){
  Vector3 * v = (Vector3 *)luaL_checkudata(L, 1, "Vector3");
  Matrix  * m =  (Matrix *)luaL_checkudata(L, 2, "Matrix");
  float x = v->x, y = v->y, z = v->z;
  v->x = m->m0*x + m->m4*y + m->m8*z  + m->m12;
  v->y = m->m1*x + m->m5*y + m->m9*z  + m->m13;
  v->z = m->m2*x + m->m6*y + m->m10*z + m->m14;
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Vector3:rotateByQuaternion
```lua
Vector3:rotateByQuaternion(Vector4 Quaternion)
```
Transform a vector by quaternion rotation
*/
int lua_class_vector3_RotateByQuaternion(lua_State *L){
  Vector3 * v = (Vector3 *)luaL_checkudata(L, 1, "Vector3");
  Vector4 * q = (Vector4 *)luaL_checkudata(L, 2, "Vector4");
  float vx = v->x, vy = v->y, vz = v->z;
  float qx = q->x, qy = q->y, qz = q->z, qw = q->w;

  v->x = vx*(qx*qx + qw*qw - qy*qy - qz*qz) + vy*(2*qx*qy - 2*qw*qz) + vz*(2*qx*qz + 2*qw*qy);
  v->y = vx*(2*qw*qz + 2*qx*qy) + vy*(qw*qw - qx*qx  + qy*qy - qz*qz) + vz*(-2*qw*qx + 2*qy*qz);
  v->z = vx*(-2*qw*qy + 2*qx*qz) + vy*(2*qw*qx + 2*qy*qz) + vz*  (qw*qw - qx*qx - qy*qy + qz*qz);
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Vector3:lerp
```lua
Vector3:lerp(Vector3 Vector, number Amount)
```
Interpolate vector to another by given interpolant
*/
int lua_class_vector3_Lerp(lua_State *L){
  Vector3 * v1 = (Vector3 *)luaL_checkudata(L, 1, "Vector3");
  Vector3 * v2 = (Vector3 *)luaL_checkudata(L, 2, "Vector3");
  float amount = luaL_checknumber(L, 3);
  v1->x = v1->x + amount*(v2->x - v1->x);
  v1->y = v1->y + amount*(v2->y - v1->y);
  v1->z = v1->z + amount*(v2->z - v1->z);
	
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Vector3:reflect
```lua
Vector3:reflect(Vector3 Normal)
```
Calculate reflected vector to normal
*/
int lua_class_vector3_Reflect(lua_State *L){
  Vector3 * v      = (Vector3 *)luaL_checkudata(L, 1, "Vector3");
  Vector3 * normal = (Vector3 *)luaL_checkudata(L, 2, "Vector3");
  float dotProduct = _ptr_vector3_DotProduct(v, normal);

  v->x = v->x - (2.0f*normal->x)*dotProduct;
  v->y = v->y - (2.0f*normal->y)*dotProduct;
  v->z = v->z - (2.0f*normal->z)*dotProduct;
	
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Vector3:min
```lua
number Min = Vector3:min()
```
Return min value for each pair of components
*/
int lua_class_vector3_Min(lua_State *L){
  Vector3 * v1 = (Vector3 *)luaL_checkudata(L, 1, "Vector3");
  Vector3 * v2 = (Vector3 *)luaL_checkudata(L, 2, "Vector3");

  v1->x = fminf(v1->x, v2->x);
  v1->y = fminf(v1->y, v2->y);
  v1->z = fminf(v1->z, v2->z);
	
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Vector3:max
```lua
number max = Vector3:min()
```
Return max value for each pair of components
*/
int lua_class_vector3_Max(lua_State *L){
  Vector3 * v1 = (Vector3 *)luaL_checkudata(L, 1, "Vector3");
  Vector3 * v2 = (Vector3 *)luaL_checkudata(L, 2, "Vector3");

  v1->x = fmaxf(v1->x, v2->x);
  v1->y = fmaxf(v1->y, v2->y);
  v1->z = fmaxf(v1->z, v2->z);
	
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Vector3:barycenter
```lua
Vector3 Barycenter = Vector3:barycenter(Vector3 A, Vector3 B, Vector3 C)
```
Create new vector that is barycenter coordinates (u, v, w) for point p with respect to triangle (A, B, C)
*/
int lua_class_vector3_Barycenter(lua_State *L){
  Vector3 * p = (Vector3 *)luaL_checkudata(L, 1, "Vector3");
  Vector3 * a = (Vector3 *)luaL_checkudata(L, 2, "Vector3");
  Vector3 * b = (Vector3 *)luaL_checkudata(L, 3, "Vector3");
  Vector3 * c = (Vector3 *)luaL_checkudata(L, 4, "Vector3");

  Vector3 v0 = Vector3Subtract(*b, *a);
  Vector3 v1 = Vector3Subtract(*c, *a);
  Vector3 v2 = Vector3Subtract(*p, *a);
  float d00 = Vector3DotProduct(v0, v0);
  float d01 = Vector3DotProduct(v0, v1);
  float d11 = Vector3DotProduct(v1, v1);
  float d20 = Vector3DotProduct(v2, v0);
  float d21 = Vector3DotProduct(v2, v1);

  float denom = d00*d11 - d01*d01;

  Vector3 * result = (Vector3 *)luax_newobject(L, "Vector3", sizeof(Vector3));

  result->y = (d11*d20 - d01*d21)/denom;
  result->z = (d00*d21 - d01*d20)/denom;
  result->x = 1.0f - (result->z + result->y);
  return 1;
}

// Meta
int lua_class_vector3__Index(lua_State *L){
  if (!luax_type(L, 2, LUA_TSTRING)) return 0;
  Vector3 *    v   = (Vector3 *)luaL_checkudata(L, 1, "Vector3");
  const char * key = luaL_checkstring(L, 2);

  lua_class_GetFieldIfCompared(L, v, key, "x", x); // calls "return" from this function on success
  lua_class_GetFieldIfCompared(L, v, key, "y", y);
  lua_class_GetFieldIfCompared(L, v, key, "z", z);
  
  luax_getclasskey(L, 1, 2);
  return 1;
}

int lua_class_vector3__Newindex(lua_State *L){
  if (!luax_type(L, 2, LUA_TSTRING)) return 0;
  Vector3 *    v     = (Vector3 *)luaL_checkudata(L, 1, "Vector3");
  const char * key   = luaL_checkstring(L, 2);
  float        value = luaL_checknumber(L, 3);
  lua_class_SetFieldIfCompared(L, v, key, value, "x", x);
  lua_class_SetFieldIfCompared(L, v, key, value, "y", y);
  lua_class_SetFieldIfCompared(L, v, key, value, "z", z);
  return 0;
}

int lua_class_vector3__Add(lua_State *L){
  Vector3 * v1 = (Vector3 *)luaL_checkudata(L, 1, "Vector3");
  Vector3 * v2 = (Vector3 *)luaL_checkudata(L, 2, "Vector3");
  Vector3 * v3 = (Vector3 *)luax_newobject(L, "Vector3", sizeof(Vector3));
  *v3 = Vector3Add(*v1, *v2);
  return 1;
}

int lua_class_vector3__Sub(lua_State *L){
  Vector3 * v1 = (Vector3 *)luaL_checkudata(L, 1, "Vector3");
  Vector3 * v2 = (Vector3 *)luaL_checkudata(L, 2, "Vector3");
  Vector3 * v3 = (Vector3 *)luax_newobject(L, "Vector3", sizeof(Vector3));
  *v3 = Vector3Subtract(*v1, *v2);
  return 1;
}

int lua_class_vector3__Mul(lua_State *L){
  Vector3 * v1 = (Vector3 *)luaL_checkudata(L, 1, "Vector3");
  Vector3 * v3 = (Vector3 *)luax_newobject(L, "Vector3", sizeof(Vector3));
  if ( lua_isnumber(L, 2) ){
    *v3 = Vector3Scale(*v1, luaL_checknumber(L, 2));
    return 1;
  }
  Vector3 * v2 = (Vector3 *)luaL_checkudata(L, 2, "Vector3");
  *v3 = Vector3Multiply(*v1, *v2);
  return 1;
}

int lua_class_vector3__Div(lua_State *L){
  Vector3 * v1 = (Vector3 *)luaL_checkudata(L, 1, "Vector3");
  Vector3 * v3 = (Vector3 *)luax_newobject(L, "Vector3", sizeof(Vector3));
  if ( lua_isnumber(L, 2) ){
    *v3 = Vector3Divide(*v1, luaL_checknumber(L, 2));
    return 1;
  }
  Vector3 * v2 = (Vector3 *)luaL_checkudata(L, 2, "Vector3");
  *v3 = Vector3DivideV(*v1, *v2);
  return 1;
}

int lua_class_vector3__Pow(lua_State *L){
  Vector3 * v1 = (Vector3 *)luaL_checkudata(L, 1, "Vector3");
  Vector3 * v3 = (Vector3 *)luax_newobject(L, "Vector3", sizeof(Vector3));
  if ( lua_isnumber(L, 2) ){
    float n = luaL_checknumber(L, 2);
    v3->x = pow(v3->x, n);
    v3->y = pow(v3->y, n);
    v3->z = pow(v3->z, n);
    return 1;
  }
  Vector3 * v2 = (Vector3 *)luaL_checkudata(L, 2, "Vector3");
  v3->x = pow(v3->x, v2->x);
  v3->y = pow(v3->y, v2->y);
  v3->z = pow(v3->z, v2->z);

  return 1;
}

int lua_class_vector3__Neg(lua_State *L){
  Vector3 * v1 = (Vector3 *)luaL_checkudata(L, 1, "Vector3");
  Vector3 * v2 = (Vector3 *)luax_newobject(L, "Vector3", sizeof(Vector3));
  *v2 = Vector3Negate(*v1);
  return 1;
}

int lua_class_vector3__Eq(lua_State *L){
  Vector3 * v1 = (Vector3 *)luaL_checkudata(L, 1, "Vector3");
  Vector3 * v2 = (Vector3 *)luaL_checkudata(L, 2, "Vector3");
  lua_pushboolean(L, (v1->x == v2->x) && (v1->y == v2->y) && (v1->z == v2->z) );
  return 1;
}

int lua_class_vector3__ToString(lua_State *L){
  Vector3 * v = (Vector3 *)luaL_checkudata(L, 1, "Vector3");
  lua_pushfstring(L, "Vector3[%f, %f, %f]: 0x%0.8x", v->x, v->y, v->z, v);
  return 1;
}

luaL_Reg luaray_class_vector3[] = {
  {"clone",              lua_class_vector3_Clone},
  {"get",                lua_class_vector3_Get},
  {"set",                lua_class_vector3_Set},
  {"add",                lua_class_vector3_Add},
  {"subtract",           lua_class_vector3_Subtract},
  {"scale",              lua_class_vector3_Scale},
  {"multiplyV",          lua_class_vector3_MultiplyV},
  {"multiply",           lua_class_vector3_Multiply},
  {"crossProduct",       lua_class_vector3_CrossProduct},
  {"perpendicular",      lua_class_vector3_Perpendicular},
  {"length",             lua_class_vector3_Length},
  {"dotProduct",         lua_class_vector3_DotProduct},
  {"distance",           lua_class_vector3_Distance},
  {"negate",             lua_class_vector3_Negate},
  {"divide",             lua_class_vector3_Divide},
  {"divideV",            lua_class_vector3_DivideV},
  {"normalize",          lua_class_vector3_Normalize},
  {"orthoNormalize",     lua_class_vector3_OrthoNormalize},
  {"transform",          lua_class_vector3_Transform},
  {"rotateByQuaternion", lua_class_vector3_RotateByQuaternion},
  {"lerp",               lua_class_vector3_Lerp},
  {"reflect",            lua_class_vector3_Reflect},
  {"min",                lua_class_vector3_Min},
  {"max",                lua_class_vector3_Max},
  {"barycenter",         lua_class_vector3_Barycenter},
  // meta
  {"__index",            lua_class_vector3__Index},
  {"__newindex",         lua_class_vector3__Newindex},
  {"__add",              lua_class_vector3__Add},
  {"__sub",              lua_class_vector3__Sub},
  {"__mul",              lua_class_vector3__Mul},
  {"__div",              lua_class_vector3__Div},
  {"__pow",              lua_class_vector3__Pow},
  {"__unm",              lua_class_vector3__Neg},
  {"__eq",               lua_class_vector3__Eq},
  {"__len",              lua_class_vector3_Length},
  {"__tostring",         lua_class_vector3__ToString},
  {NULL, NULL}
};



/*!MD
## Matrix

Structure:

| Field  | Type  |
| :----- | :---- |
| m1     | float |
| m2     | float |
| m3     | float |
| m4     | float |
| m5     | float |
| m6     | float |
| m7     | float |
| m8     | float |
| m9     | float |
| m10    | float |
| m11    | float |
| m12    | float |
| m13    | float |
| m14    | float |
| m15    | float |
| m16    | float |

| **Methods**                                     | description 
| :-----                                          | :-----------
| [clone](#Matrixclone)                           | Creates copy of matrix
| [get](#Matrixget)                               | Returns matrix fields
| [set](#Matrixset)                               | Assing values to matrix
| [determinant](#Matrixdeterminant)               | Compute matrix determinant
| [trace](#Matrixtrace)                           | Returns the trace of the matrix (sum of the values along the diagonal)
| [transpose](#Matrixtranspose)                   | Transposes provided matrix (modifying it)
| [invert](#Matrixinvert)                         | Invert provided matrix (modifying it)
| [normalize](#Matrixnormalize)                   | Normalize provided matrix (modifying it)
| [identity](#Matrixidentity)                     | Modify matrix to identity matrix
| [add](#Matrixadd)                               | Add matrix to matrix (modifying it)
| [subtract](#Matrixsubtract)                     | Subtract matrix from matrix (modifying it)
| [translate](#Matrixtranslate)                   | Modify matrix to translation by given vector matrix
| [rotate](#Matrixrotate)                         | Modify matrix to rotation matrix from axis and angle (radians)
| [rotateXYZ](#MatrixrotateXYZ)                   | Rotate matrix to given Vector3 along XYZ-axes (angles in radians)
| [rotateX](#MatrixrotateX)                       | Rotate matrix to given angle along X-axis (angle in radians)
| [rotateY](#MatrixrotateY)                       | Rotate matrix to given angle along Y-axis. (angle in radians)
| [rotateZ](#MatrixrotateZ)                       | Rotate matrix to given angle along Z-axis. (angle in radians)
| [scale](#Matrixscale)                           | Scale matrix by given vector
| [multiply](#Matrixmultiply)                     | Multiply matrix to another (modifying it)
| [frustum](#Matrixfrustum)                       | Modify matrix to perspective projection matrix
| [perspective](#Matrixperspective)               | Modify matrix to perspective projection matrix (by angles in radians)
| [ortho](#Matrixortho)                           | Modify matrix to orthographic projection matrix
| [lookAt](#MatrixlookAt)                         | Modify matrix to look-at point by three vectors
| **Overloads**                                   | 
| +: `NewVec3 = MatrixA + MatrixB`                | Create a new matrix that is the sum of two matrices
| -: `NewVec3 = MatrixA - MatrixB`                | Create a new matrix that is the subtraction of two matrices
| *: `NewVec3 = MatrixA * MatrixB`                | Create a new matrix that is the multiplication of two matrices
| =: `isEqual = MatrixA == MatrixB`               | Checks matrices is equal

### Initialization
```lua
-- variants
Matrix Mat = rl.Matrix(number m1, number m2, ..., number m16) --> Matrix[m1, m2, ... m16]
Matrix Mat = rl.Matrix(table t)                        --> Matrix[ t[1], t[2], ... t[16] ]
```
Creates new Matrix object.
*/
Matrix * _ptr_matrix_Fill(lua_State *L, Matrix * m, int t){
  if (lua_istable(L, t)){
    for (int i = 0; i < 16; i++) lua_rawgeti (L, t, i + 1);
    m->m0  = luax_optnumber(L, -16, 0.0f);
    m->m1  = luax_optnumber(L, -15, 0.0f);
    m->m2  = luax_optnumber(L, -14, 0.0f);
    m->m3  = luax_optnumber(L, -13, 0.0f);
    m->m4  = luax_optnumber(L, -12, 0.0f);
    m->m5  = luax_optnumber(L, -11, 0.0f);
    m->m6  = luax_optnumber(L, -10, 0.0f);
    m->m7  = luax_optnumber(L,  -9, 0.0f);
    m->m8  = luax_optnumber(L,  -8, 0.0f);
    m->m9  = luax_optnumber(L,  -7, 0.0f);
    m->m10 = luax_optnumber(L,  -6, 0.0f);
    m->m11 = luax_optnumber(L,  -5, 0.0f);
    m->m12 = luax_optnumber(L,  -4, 0.0f);
    m->m13 = luax_optnumber(L,  -3, 0.0f);
    m->m14 = luax_optnumber(L,  -2, 0.0f);
    m->m15 = luax_optnumber(L,  -1, 0.0f);
    lua_pop(L, 16);
    return m;
  }
  m->m0  = luax_optnumber(L, t +  0, 0.0f);
  m->m1  = luax_optnumber(L, t +  1, 0.0f);
  m->m2  = luax_optnumber(L, t +  2, 0.0f);
  m->m3  = luax_optnumber(L, t +  3, 0.0f);
  m->m4  = luax_optnumber(L, t +  4, 0.0f);
  m->m5  = luax_optnumber(L, t +  5, 0.0f);
  m->m6  = luax_optnumber(L, t +  6, 0.0f);
  m->m7  = luax_optnumber(L, t +  7, 0.0f);
  m->m8  = luax_optnumber(L, t +  8, 0.0f);
  m->m9  = luax_optnumber(L, t +  9, 0.0f);
  m->m10 = luax_optnumber(L, t + 10, 0.0f);
  m->m11 = luax_optnumber(L, t + 11, 0.0f);
  m->m12 = luax_optnumber(L, t + 12, 0.0f);
  m->m13 = luax_optnumber(L, t + 13, 0.0f);
  m->m14 = luax_optnumber(L, t + 14, 0.0f);
  m->m15 = luax_optnumber(L, t + 15, 0.0f);
  return m;
}

int lua_class_matrix_new(lua_State *L){
  Matrix * m = (Matrix *)luax_newobject(L, "Matrix", sizeof(Matrix));
  _ptr_matrix_Fill(L, m, 1);
  return 1;
}

/*!MD
#### Matrix:clone
```lua
Matrix Matrix = Matrix:clone()
```
Creates copy of matrix
*/
int lua_class_matrix_Clone(lua_State *L){
  Matrix * m1 = (Matrix *)luaL_checkudata(L, 1, "Matrix");
  Matrix * m2 = (Matrix *)luax_newobject(L, "Matrix", sizeof(Matrix));
  m1->m0  = m2->m0;  m1->m1  = m2->m1;  m1->m2  = m2->m2;  m1->m3  = m2->m3;
  m1->m4  = m2->m4;  m1->m5  = m2->m5;  m1->m6  = m2->m6;  m1->m7  = m2->m7;
  m1->m8  = m2->m8;  m1->m9  = m2->m9;  m1->m10 = m2->m10; m1->m11 = m2->m11;
  m1->m12 = m2->m12; m1->m13 = m2->m13; m1->m14 = m2->m14; m1->m15 = m2->m15;
  return 1;
}

/*!MD
#### Matrix:get
```lua
-- variants
number m1, number m2, ... number m16 = Matrix:get()
table Table = Matrix:get('t') --> Table[m1, m2, ... m16]
```
Returns matrix fields
*/
int lua_class_matrix_Get(lua_State *L){
  Matrix * m = (Matrix *)luaL_checkudata(L, 1, "Matrix");
  if (luax_optstring(L, 2, "\0")[0] == 't'){
    lua_newtable(L);
    luax_tnnumber(L,  1, (float)m->m0);
    luax_tnnumber(L,  2, (float)m->m1);
    luax_tnnumber(L,  3, (float)m->m2);
    luax_tnnumber(L,  4, (float)m->m3);
    luax_tnnumber(L,  5, (float)m->m4);
    luax_tnnumber(L,  6, (float)m->m5);
    luax_tnnumber(L,  7, (float)m->m6);
    luax_tnnumber(L,  8, (float)m->m7);
    luax_tnnumber(L,  9, (float)m->m8);
    luax_tnnumber(L, 10, (float)m->m9);
    luax_tnnumber(L, 11, (float)m->m10);
    luax_tnnumber(L, 12, (float)m->m11);
    luax_tnnumber(L, 13, (float)m->m12);
    luax_tnnumber(L, 14, (float)m->m13);
    luax_tnnumber(L, 15, (float)m->m14);
    luax_tnnumber(L, 16, (float)m->m15);
    return 1;
  }
  lua_pushnumber(L, (float)m->m0);
  lua_pushnumber(L, (float)m->m1);
  lua_pushnumber(L, (float)m->m2);
  lua_pushnumber(L, (float)m->m3);
  lua_pushnumber(L, (float)m->m4);
  lua_pushnumber(L, (float)m->m5);
  lua_pushnumber(L, (float)m->m6);
  lua_pushnumber(L, (float)m->m7);
  lua_pushnumber(L, (float)m->m8);
  lua_pushnumber(L, (float)m->m9);
  lua_pushnumber(L, (float)m->m10);
  lua_pushnumber(L, (float)m->m11);
  lua_pushnumber(L, (float)m->m12);
  lua_pushnumber(L, (float)m->m13);
  lua_pushnumber(L, (float)m->m14);
  lua_pushnumber(L, (float)m->m15);
  return 16;
}

/*!MD
#### Matrix:set
```lua
-- variants
Matrix:set(number m1, number m2, ... number m16)
Matrix:set(table Table) -- Table[m1, m2, ... m16]
```
Assing values to matrix
*/
int lua_class_matrix_Set(lua_State *L){
  Matrix * m = (Matrix *)luaL_checkudata(L, 1, "Matrix");
  _ptr_matrix_Fill(L, m, 2);
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Matrix:determinant
```lua
number Determinant = Matrix:determinant()
```
Compute matrix determinant
*/
float _ptr_matrix_Determinant(Matrix * m){
  float result = 0;
  float a00 = m->m0,  a01 = m->m1,  a02 = m->m2,  a03 = m->m3;
  float a10 = m->m4,  a11 = m->m5,  a12 = m->m6,  a13 = m->m7;
  float a20 = m->m8,  a21 = m->m9,  a22 = m->m10, a23 = m->m11;
  float a30 = m->m12, a31 = m->m13, a32 = m->m14, a33 = m->m15;

  result = a30*a21*a12*a03 - a20*a31*a12*a03 - a30*a11*a22*a03 + a10*a31*a22*a03 +
           a20*a11*a32*a03 - a10*a21*a32*a03 - a30*a21*a02*a13 + a20*a31*a02*a13 +
           a30*a01*a22*a13 - a00*a31*a22*a13 - a20*a01*a32*a13 + a00*a21*a32*a13 +
           a30*a11*a02*a23 - a10*a31*a02*a23 - a30*a01*a12*a23 + a00*a31*a12*a23 +
           a10*a01*a32*a23 - a00*a11*a32*a23 - a20*a11*a02*a33 + a10*a21*a02*a33 +
           a20*a01*a12*a33 - a00*a21*a12*a33 - a10*a01*a22*a33 + a00*a11*a22*a33;
  return result;
}

int lua_class_matrix_Determinant(lua_State *L){
  Matrix * m = (Matrix *)luaL_checkudata(L, 1, "Matrix");
  float result = _ptr_matrix_Determinant(m);
  lua_pushnumber(L, result);
  return 1;
}

/*!MD
#### Matrix:trace
```lua
number Trace = Matrix:trace()
```
Returns the trace of the matrix (sum of the values along the diagonal)
*/
float _ptr_matrix_Trace(Matrix * m){
  return (float)(m->m0 + m->m5 + m->m10 + m->m15);
}

int lua_class_matrix_Trace(lua_State *L){
  Matrix * m = (Matrix *)luaL_checkudata(L, 1, "Matrix");
  float result = _ptr_matrix_Trace(m);
  lua_pushnumber(L, result);
  return 1;
}

/*!MD
#### Matrix:transpose
```lua
Matrix:transpose()
```
Transposes provided matrix (modifying it)
*/
int lua_class_matrix_Transpose(lua_State *L){
  Matrix * m = (Matrix *)luaL_checkudata(L, 1, "Matrix");
  float m1  = m->m1,  m2  = m->m2,  m3  = m->m3;
  float m4  = m->m4,  m6  = m->m6,  m7  = m->m7;
  float m8  = m->m8,  m9  = m->m9,  m11 = m->m11;
  float m12 = m->m12, m13 = m->m13, m14 = m->m14;
  m->m1  = m4; m->m2  = m8; m->m3  = m12;
  m->m4  = m1; m->m6  = m9; m->m7  = m13;
  m->m8  = m2; m->m9  = m6; m->m11 = m14;
  m->m12 = m3; m->m13 = m7; m->m14 = m11;
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Matrix:invert
```lua
Matrix:invert()
```
Transposes provided matrix (modifying it)
*/
Matrix * _ptr_matrix_Invert(Matrix * m){
  float a00 = m->m0,  a01 = m->m1,  a02 = m->m2,  a03 = m->m3;
  float a10 = m->m4,  a11 = m->m5,  a12 = m->m6,  a13 = m->m7;
  float a20 = m->m8,  a21 = m->m9,  a22 = m->m10, a23 = m->m11;
  float a30 = m->m12, a31 = m->m13, a32 = m->m14, a33 = m->m15;

  float b00 = a00*a11 - a01*a10;
  float b01 = a00*a12 - a02*a10;
  float b02 = a00*a13 - a03*a10;
  float b03 = a01*a12 - a02*a11;
  float b04 = a01*a13 - a03*a11;
  float b05 = a02*a13 - a03*a12;
  float b06 = a20*a31 - a21*a30;
  float b07 = a20*a32 - a22*a30;
  float b08 = a20*a33 - a23*a30;
  float b09 = a21*a32 - a22*a31;
  float b10 = a21*a33 - a23*a31;
  float b11 = a22*a33 - a23*a32;

  // Calculate the invert determinant (inlined to avoid double-caching)
  float invDet = 1.0f/(b00*b11 - b01*b10 + b02*b09 + b03*b08 - b04*b07 + b05*b06);

  m->m0  = ( a11*b11 - a12*b10 + a13*b09)*invDet;
  m->m1  = (-a01*b11 + a02*b10 - a03*b09)*invDet;
  m->m2  = ( a31*b05 - a32*b04 + a33*b03)*invDet;
  m->m3  = (-a21*b05 + a22*b04 - a23*b03)*invDet;
  m->m4  = (-a10*b11 + a12*b08 - a13*b07)*invDet;
  m->m5  = ( a00*b11 - a02*b08 + a03*b07)*invDet;
  m->m6  = (-a30*b05 + a32*b02 - a33*b01)*invDet;
  m->m7  = ( a20*b05 - a22*b02 + a23*b01)*invDet;
  m->m8  = ( a10*b10 - a11*b08 + a13*b06)*invDet;
  m->m9  = (-a00*b10 + a01*b08 - a03*b06)*invDet;
  m->m10 = ( a30*b04 - a31*b02 + a33*b00)*invDet;
  m->m11 = (-a20*b04 + a21*b02 - a23*b00)*invDet;
  m->m12 = (-a10*b09 + a11*b07 - a12*b06)*invDet;
  m->m13 = ( a00*b09 - a01*b07 + a02*b06)*invDet;
  m->m14 = (-a30*b03 + a31*b01 - a32*b00)*invDet;
  m->m15 = ( a20*b03 - a21*b01 + a22*b00)*invDet;

  return m;
}

int lua_class_matrix_Invert(lua_State *L){
  Matrix * m = (Matrix *)luaL_checkudata(L, 1, "Matrix");
  _ptr_matrix_Invert(m);
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Matrix:normalize
```lua
Matrix:normalize()
```
Normalize provided matrix (modifying it)
*/
int lua_class_matrix_Normalize(lua_State *L){
  Matrix * m = (Matrix *)luaL_checkudata(L, 1, "Matrix");
  float det = _ptr_matrix_Determinant(m);

  m->m0  /= det; m->m1  /= det; m->m2  /= det; m->m3  /= det;
  m->m4  /= det; m->m5  /= det; m->m6  /= det; m->m7  /= det;
  m->m8  /= det; m->m9  /= det; m->m10 /= det; m->m11 /= det;
  m->m12 /= det; m->m13 /= det; m->m14 /= det; m->m15 /= det;

  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Matrix:identity
```lua
Matrix:identity()
```
Modify matrix to identity matrix
*/
Matrix * _ptr_matrix_Identity(Matrix * m){
  m->m0  = 1.0f; m->m1  = 0.0f; m->m2  = 0.0f; m->m3  = 0.0f;
  m->m4  = 0.0f; m->m5  = 1.0f; m->m6  = 0.0f; m->m7  = 0.0f;
  m->m8  = 0.0f; m->m9  = 0.0f; m->m10 = 1.0f; m->m11 = 0.0f;
  m->m12 = 0.0f; m->m13 = 0.0f; m->m14 = 0.0f; m->m15 = 1.0f;
  return m;
}

int lua_class_matrix_Identity(lua_State *L){
  Matrix * m = (Matrix *)luaL_checkudata(L, 1, "Matrix");
  _ptr_matrix_Identity(m);
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Matrix:add
```lua
Matrix:add(Matrix Matrix)
```
Add matrix to matrix (modifying it)
*/
int lua_class_matrix_Add(lua_State *L){
  Matrix * m1 = (Matrix *)luaL_checkudata(L, 1, "Matrix");
  Matrix * m2 = (Matrix *)luaL_checkudata(L, 2, "Matrix");

  m1->m0  = m1->m0  + m2->m0;
  m1->m1  = m1->m1  + m2->m1;
  m1->m2  = m1->m2  + m2->m2;
  m1->m3  = m1->m3  + m2->m3;
  m1->m4  = m1->m4  + m2->m4;
  m1->m5  = m1->m5  + m2->m5;
  m1->m6  = m1->m6  + m2->m6;
  m1->m7  = m1->m7  + m2->m7;
  m1->m8  = m1->m8  + m2->m8;
  m1->m9  = m1->m9  + m2->m9;
  m1->m10 = m1->m10 + m2->m10;
  m1->m11 = m1->m11 + m2->m11;
  m1->m12 = m1->m12 + m2->m12;
  m1->m13 = m1->m13 + m2->m13;
  m1->m14 = m1->m14 + m2->m14;
  m1->m15 = m1->m15 + m2->m15;

  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Matrix:subtract
```lua
Matrix:subtract(Matrix Matrix)
```
Subtract matrix from matrix (modifying it)
*/
int lua_class_matrix_Subtract(lua_State *L){
  Matrix * m1 = (Matrix *)luaL_checkudata(L, 1, "Matrix");
  Matrix * m2 = (Matrix *)luaL_checkudata(L, 2, "Matrix");

  m1->m0  = m1->m0  - m2->m0;
  m1->m1  = m1->m1  - m2->m1;
  m1->m2  = m1->m2  - m2->m2;
  m1->m3  = m1->m3  - m2->m3;
  m1->m4  = m1->m4  - m2->m4;
  m1->m5  = m1->m5  - m2->m5;
  m1->m6  = m1->m6  - m2->m6;
  m1->m7  = m1->m7  - m2->m7;
  m1->m8  = m1->m8  - m2->m8;
  m1->m9  = m1->m9  - m2->m9;
  m1->m10 = m1->m10 - m2->m10;
  m1->m11 = m1->m11 - m2->m11;
  m1->m12 = m1->m12 - m2->m12;
  m1->m13 = m1->m13 - m2->m13;
  m1->m14 = m1->m14 - m2->m14;
  m1->m15 = m1->m15 - m2->m15;

  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Matrix:translate
```lua
-- variants
Matrix:translate(number x, number y, number z)
Matrix:translate(table Translate) -- Translate[x, y, z]
Matrix:translate(Vector3 Vector)
```
Modify matrix to translation by given vector matrix
*/
int lua_class_matrix_Translate(lua_State *L){
  Matrix * m = (Matrix *)luaL_checkudata(L, 1, "Matrix");
  float x, y, z;
  if (lua_istable(L, 2)){
    lua_rawgeti(L, 2, 1); lua_rawgeti(L, 2, 2); lua_rawgeti(L, 2, 3);
    x = luax_optnumber(L, -3, 0);
    y = luax_optnumber(L, -2, 0);
    z = luax_optnumber(L, -1, 0);
  }
  else if (lua_isnumber(L, 2) && lua_isnumber(L, 3) && lua_isnumber(L, 4)) {
    x = luaL_checknumber(L, 2);
    y = luaL_checknumber(L, 3);
    z = luaL_checknumber(L, 4);
  }
  else {
    Vector3 * v = (Vector3 *)luaL_checkudata(L, 2, "Vector3");
    x = v->x; y = v->y; z = v->z;
  }
  _ptr_matrix_Identity(m);
  m->m3 = x; m->m7 = y; m->m11 = z;
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Matrix:rotate
```lua
Matrix:rotate(Vector3 Vector, number Angle)
```
Modify matrix to rotation matrix from axis and angle (radians)
*/
int lua_class_matrix_Rotate(lua_State *L){
  Matrix  * m =  (Matrix *)luaL_checkudata(L, 1, "Matrix");
  Vector3 * v = (Vector3 *)luaL_checkudata(L, 2, "Vector3");
  float a = luaL_checknumber(L, 3); // angle
  float x = v->x, y = v->y, z = v->z;
  float l = sqrtf(x*x + y*y + z*z);
  if ((l != 1.0f) && (l != 0.0f)){
    l = 1.0f/l; x *= l; y *= l; z *= l;
  }

  float s = sinf(a);
  float c = cosf(a);
  float t = 1.0f - c;

  m->m0  = x*x*t + c;   m->m1  = y*x*t + z*s; m->m2  = z*x*t - y*s; m->m3  = 0.0f;
  m->m4  = x*y*t - z*s; m->m5  = y*y*t + c;   m->m6  = z*y*t + x*s; m->m7  = 0.0f;
  m->m8  = x*z*t + y*s; m->m9  = y*z*t - x*s; m->m10 = z*z*t + c;   m->m11 = 0.0f;
  m->m12 = 0.0f;        m->m13 = 0.0f;        m->m14 = 0.0f;        m->m15 = 1.0f;

  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Matrix:rotateXYZ
```lua
Matrix:rotateXYZ(Vector3 Vector)
```
Rotate matrix to given Vector3 (angles in radians)
*/
int lua_class_matrix_RotateXYZ(lua_State *L){
  Matrix  * m =  (Matrix *)luaL_checkudata(L, 1, "Matrix");
  Vector3 * v = (Vector3 *)luaL_checkudata(L, 2, "Vector3");
  _ptr_matrix_Identity(m);

  float cosz = cosf(-v->z), sinz = sinf(-v->z);
  float cosy = cosf(-v->y), siny = sinf(-v->y);
  float cosx = cosf(-v->x), sinx = sinf(-v->x);

  m->m0 =  cosz * cosy;
  m->m4 = (cosz * siny * sinx) - (sinz * cosx);
  m->m8 = (cosz * siny * cosx) + (sinz * sinx);

  m->m1 =  sinz * cosy;
  m->m5 = (sinz * siny * sinx) + (cosz * cosx);
  m->m9 = (sinz * siny * cosx) - (cosz * sinx);

  m->m2 = -siny;
  m->m6 = cosy * sinx;
  m->m10= cosy * cosx;

  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Matrix:rotateX
```lua
Matrix:rotateX(number Angle)
```
Rotate matrix to given angle along X-axis. (angle in radians)
*/
int lua_class_matrix_RotateX(lua_State *L){
  Matrix  * m =  (Matrix *)luaL_checkudata(L, 1, "Matrix");
  float angle = luaL_checknumber(L, 2);

  _ptr_matrix_Identity(m);
  float cosres = cosf(angle);
  float sinres = sinf(angle);

  m->m5  =  cosres;
  m->m6  = -sinres;
  m->m9  =  sinres;
  m->m10 =  cosres;

  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Matrix:rotateY
```lua
Matrix:rotateY(number Angle)
```
Rotate matrix to given angle along Y-axis. (angle in radians)
*/
int lua_class_matrix_RotateY(lua_State *L){
  Matrix  * m =  (Matrix *)luaL_checkudata(L, 1, "Matrix");
  float angle = luaL_checknumber(L, 2);

  _ptr_matrix_Identity(m);
  float cosres = cosf(angle);
  float sinres = sinf(angle);

  m->m0  =  cosres;
  m->m2  =  sinres;
  m->m8  = -sinres;
  m->m10 =  cosres;

  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Matrix:rotateZ
```lua
Matrix:rotateZ(number Angle)
```
Rotate matrix to given angle along Z-axis. (angle in radians)
*/
int lua_class_matrix_RotateZ(lua_State *L){
  Matrix  * m =  (Matrix *)luaL_checkudata(L, 1, "Matrix");
  float angle = luaL_checknumber(L, 2);
  _ptr_matrix_Identity(m);
  float cosres = cosf(angle);
  float sinres = sinf(angle);

  m->m0 =  cosres;
  m->m1 = -sinres;
  m->m4 =  sinres;
  m->m5 =  cosres;

  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Matrix:scale
```lua
-- variants
Matrix:scale(number x, number y, number z)
Matrix:scale(table Scale)    -- Scale[x, y, z]
Matrix:scale(Vector3 Vector)

```
Scale matrix by given vector
*/
int lua_class_matrix_Scale(lua_State *L){
  Matrix * m = (Matrix *)luaL_checkudata(L, 1, "Matrix");
  float x, y, z;
  if (lua_istable(L, 2)){
    lua_rawgeti(L, 2, 1); lua_rawgeti(L, 2, 2); lua_rawgeti(L, 2, 3);
    x = luax_optnumber(L, -3, 0);
    y = luax_optnumber(L, -2, 0);
    z = luax_optnumber(L, -1, 0);
  }
  else if (lua_isnumber(L, 2) && lua_isnumber(L, 3) && lua_isnumber(L, 4)) {
    x = luaL_checknumber(L, 2);
    y = luaL_checknumber(L, 3);
    z = luaL_checknumber(L, 4);
  }
  else {
    Vector3 * v = (Vector3 *)luaL_checkudata(L, 2, "Vector3");
    x = v->x; y = v->y; z = v->z;
  }

  _ptr_matrix_Identity(m);
  m->m0 = x; m->m5 = y; m->m10 = z;

  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Matrix:multiply
```lua
-- variants
Matrix:multiply(Matrix Matrix)
```
Multiply matrix to another (modifying it)
*/
int lua_class_matrix_Multiply(lua_State *L){
  Matrix * m1 = (Matrix *)luaL_checkudata(L, 1, "Matrix");
  Matrix * m2 = (Matrix *)luaL_checkudata(L, 2, "Matrix");
  Matrix m3 = {0};

  m3.m0  = m1->m0*m2->m0  + m1->m1*m2->m4  + m1->m2*m2->m8   + m1->m3*m2->m12;
  m3.m1  = m1->m0*m2->m1  + m1->m1*m2->m5  + m1->m2*m2->m9   + m1->m3*m2->m13;
  m3.m2  = m1->m0*m2->m2  + m1->m1*m2->m6  + m1->m2*m2->m10  + m1->m3*m2->m14;
  m3.m3  = m1->m0*m2->m3  + m1->m1*m2->m7  + m1->m2*m2->m11  + m1->m3*m2->m15;
  m3.m4  = m1->m4*m2->m0  + m1->m5*m2->m4  + m1->m6*m2->m8   + m1->m7*m2->m12;
  m3.m5  = m1->m4*m2->m1  + m1->m5*m2->m5  + m1->m6*m2->m9   + m1->m7*m2->m13;
  m3.m6  = m1->m4*m2->m2  + m1->m5*m2->m6  + m1->m6*m2->m10  + m1->m7*m2->m14;
  m3.m7  = m1->m4*m2->m3  + m1->m5*m2->m7  + m1->m6*m2->m11  + m1->m7*m2->m15;
  m3.m8  = m1->m8*m2->m0  + m1->m9*m2->m4  + m1->m10*m2->m8  + m1->m11*m2->m12;
  m3.m9  = m1->m8*m2->m1  + m1->m9*m2->m5  + m1->m10*m2->m9  + m1->m11*m2->m13;
  m3.m10 = m1->m8*m2->m2  + m1->m9*m2->m6  + m1->m10*m2->m10 + m1->m11*m2->m14;
  m3.m11 = m1->m8*m2->m3  + m1->m9*m2->m7  + m1->m10*m2->m11 + m1->m11*m2->m15;
  m3.m12 = m1->m12*m2->m0 + m1->m13*m2->m4 + m1->m14*m2->m8  + m1->m15*m2->m12;
  m3.m13 = m1->m12*m2->m1 + m1->m13*m2->m5 + m1->m14*m2->m9  + m1->m15*m2->m13;
  m3.m14 = m1->m12*m2->m2 + m1->m13*m2->m6 + m1->m14*m2->m10 + m1->m15*m2->m14;
  m3.m15 = m1->m12*m2->m3 + m1->m13*m2->m7 + m1->m14*m2->m11 + m1->m15*m2->m15;
  *m1 = m3;

  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Matrix:frustrum
```lua
Matrix:frustum(number Left, number Right, number Bottom, numner Top, number Near, number Far)
```
Modify matrix to perspective projection matrix
*/
Matrix * _ptr_matrix_Frustrum(Matrix * m, double left, double right, double bottom, double top, double near, double far){
  _ptr_matrix_Identity(m);

  float rl = (float)(right - left);
  float tb = (float)(top - bottom);
  float fn = (float)(far - near);
  m->m0  =  ((float)near*2.0f)/rl;
  m->m5  =  ((float)near*2.0f)/tb;
  m->m8  =  ((float)right + (float)left)   / rl;
  m->m9  =  ((float)top   + (float)bottom) / tb;
  m->m10 = -((float)far   + (float)near)   / fn;
  m->m11 = -1.0f;
  m->m14 = -((float)far*(float)near*2.0f)/fn;
  m->m15 = 0.0f;
  return m;
}

int lua_class_matrix_Frustum(lua_State *L){
  Matrix * m = (Matrix *)luaL_checkudata(L, 1, "Matrix");
  double left   = luaL_checknumber(L, 2);
  double right  = luaL_checknumber(L, 3);
  double bottom = luaL_checknumber(L, 4);
  double top    = luaL_checknumber(L, 5);
  double near   = luaL_checknumber(L, 6);
  double far    = luaL_checknumber(L, 7);
  _ptr_matrix_Frustrum(m, left, right, bottom, top, near, far);

  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Matrix:perspective
```lua
Matrix:perspective(number FovY, number Aspect, number Near, numner Far, number Top)
```
Modify matrix to perspective projection matrix (by angles in radians)
*/
int lua_class_matrix_Perspective(lua_State *L){
  Matrix * m = (Matrix *)luaL_checkudata(L, 1, "Matrix");
  double fovy   = luaL_checknumber(L, 2);
  double aspect = luaL_checknumber(L, 3);
  double near   = luaL_checknumber(L, 4);
  double far    = luaL_checknumber(L, 5);
  double top    = near*tan(fovy*0.5);
  double right  = top*aspect;

  _ptr_matrix_Frustrum(m, -right, right, -top, top, near, far);

  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Matrix:ortho
```lua
Matrix:ortho(number Left, number Right, number Bottom, numner Top, number Near, number Far)
```
Modify matrix to orthographic projection matrix
*/
int lua_class_matrix_Ortho(lua_State *L){
  Matrix * m = (Matrix *)luaL_checkudata(L, 1, "Matrix");
  double left   = luaL_checknumber(L, 2);
  double right  = luaL_checknumber(L, 3);
  double bottom = luaL_checknumber(L, 4);
  double top    = luaL_checknumber(L, 5);
  double near   = luaL_checknumber(L, 6);
  double far    = luaL_checknumber(L, 7);

  float rl = (float)(right - left);
  float tb = (float)(top   - bottom);
  float fn = (float)(far   - near);

  m->m0  = 2.0f/rl;
  m->m1  = 0.0f;
  m->m2  = 0.0f;
  m->m3  = 0.0f;
  m->m4  = 0.0f;
  m->m5  = 2.0f/tb;
  m->m6  = 0.0f;
  m->m7  = 0.0f;
  m->m8  = 0.0f;
  m->m9  = 0.0f;
  m->m10 = -2.0f/fn;
  m->m11 = 0.0f;
  m->m12 = -((float)left + (float)right)  / rl;
  m->m13 = -((float)top  + (float)bottom) / tb;
  m->m14 = -((float)far  + (float)near)   / fn;
  m->m15 = 1.0f;

  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Matrix:lookAt
```lua
Matrix:lookAt(Vector3 Eye, Vector3 Target, Vector3 Up)
```
Modify matrix to look-at point by three vectors
*/
int lua_class_matrix_LookAt(lua_State *L){
  Matrix  * m  =  (Matrix *)luaL_checkudata(L, 1, "Matrix");
  Vector3 * eye    = (Vector3 *)luaL_checkudata(L, 2, "Vector3");
  Vector3 * target = (Vector3 *)luaL_checkudata(L, 3, "Vector3");
  Vector3 * up     = (Vector3 *)luaL_checkudata(L, 4, "Vector3");

  Vector3 z = Vector3Subtract(*eye, *target);
  _ptr_vector3_Normalize(&z);
  Vector3 x = Vector3CrossProduct(*up, z);
  _ptr_vector3_Normalize(&x);
  Vector3 y = Vector3CrossProduct(z, x);
  _ptr_vector3_Normalize(&y);

  m->m0  = x.x;    m->m1  = x.y;    m->m2  = x.z;    m->m3  = 0.0f;
  m->m4  = y.x;    m->m5  = y.y;    m->m6  = y.z;    m->m7  = 0.0f;
  m->m8  = z.x;    m->m9  = z.y;    m->m10 = z.z;    m->m11 = 0.0f;
  m->m12 = eye->x; m->m13 = eye->y; m->m14 = eye->z; m->m15 = 1.0f;
  _ptr_matrix_Invert(m);

  lua_settop(L, 1);
  return 1;
}


int lua_class_matrix__Index(lua_State *L){
  if (!luax_type(L, 2, LUA_TSTRING)) return 0;
  Matrix *     m   = (Matrix *)luaL_checkudata(L, 1, "Matrix");
  const char * key = luaL_checkstring(L, 2);

  lua_class_GetFieldIfCompared(L, m, key, "m1",  m0);
  lua_class_GetFieldIfCompared(L, m, key, "m2",  m1);
  lua_class_GetFieldIfCompared(L, m, key, "m3",  m2);
  lua_class_GetFieldIfCompared(L, m, key, "m4",  m3);
  lua_class_GetFieldIfCompared(L, m, key, "m5",  m4);
  lua_class_GetFieldIfCompared(L, m, key, "m6",  m5);
  lua_class_GetFieldIfCompared(L, m, key, "m7",  m6);
  lua_class_GetFieldIfCompared(L, m, key, "m8",  m7);
  lua_class_GetFieldIfCompared(L, m, key, "m9",  m8);
  lua_class_GetFieldIfCompared(L, m, key, "m10", m9);
  lua_class_GetFieldIfCompared(L, m, key, "m11", m10);
  lua_class_GetFieldIfCompared(L, m, key, "m12", m11);
  lua_class_GetFieldIfCompared(L, m, key, "m13", m12);
  lua_class_GetFieldIfCompared(L, m, key, "m14", m13);
  lua_class_GetFieldIfCompared(L, m, key, "m15", m14);
  lua_class_GetFieldIfCompared(L, m, key, "m16", m15);
  
  luax_getclasskey(L, 1, 2);
  return 1;
}

int lua_class_matrix__Newindex(lua_State *L){
  if (!luax_type(L, 2, LUA_TSTRING)) return 0;
  Matrix *     m     = (Matrix *)luaL_checkudata(L, 1, "Matrix");
  const char * key   = luaL_checkstring(L, 2);
  float        value = luaL_checknumber(L, 3);
  lua_class_SetFieldIfCompared(L, m, key, value, "m1",  m0);
  lua_class_SetFieldIfCompared(L, m, key, value, "m2",  m1);
  lua_class_SetFieldIfCompared(L, m, key, value, "m3",  m2);
  lua_class_SetFieldIfCompared(L, m, key, value, "m4",  m3);
  lua_class_SetFieldIfCompared(L, m, key, value, "m5",  m4);
  lua_class_SetFieldIfCompared(L, m, key, value, "m6",  m5);
  lua_class_SetFieldIfCompared(L, m, key, value, "m7",  m6);
  lua_class_SetFieldIfCompared(L, m, key, value, "m8",  m7);
  lua_class_SetFieldIfCompared(L, m, key, value, "m9",  m8);
  lua_class_SetFieldIfCompared(L, m, key, value, "m10", m9);
  lua_class_SetFieldIfCompared(L, m, key, value, "m11", m10);
  lua_class_SetFieldIfCompared(L, m, key, value, "m12", m11);
  lua_class_SetFieldIfCompared(L, m, key, value, "m13", m12);
  lua_class_SetFieldIfCompared(L, m, key, value, "m14", m13);
  lua_class_SetFieldIfCompared(L, m, key, value, "m15", m14);
  lua_class_SetFieldIfCompared(L, m, key, value, "m16", m15);
  return 0;
}

int lua_class_matrix__Add(lua_State *L){
  Matrix * m1 = (Matrix *)luaL_checkudata(L, 1, "Matrix");
  Matrix * m2 = (Matrix *)luaL_checkudata(L, 2, "Matrix");
  Matrix * m3 = (Matrix *)luax_newobject(L, "Matrix", sizeof(Matrix));
  *m3 = MatrixAdd(*m1, *m2);
  return 1;
}

int lua_class_matrix__Sub(lua_State *L){
  Matrix * m1 = (Matrix *)luaL_checkudata(L, 1, "Matrix");
  Matrix * m2 = (Matrix *)luaL_checkudata(L, 2, "Matrix");
  Matrix * m3 = (Matrix *)luax_newobject(L, "Matrix", sizeof(Matrix));
  *m3 = MatrixSubtract(*m1, *m2);
  return 1;
}

int lua_class_matrix__Mul(lua_State *L){
  Matrix * m1 = (Matrix *)luaL_checkudata(L, 1, "Matrix");
  Matrix * m2 = (Matrix *)luaL_checkudata(L, 2, "Matrix");
  Matrix * m3 = (Matrix *)luax_newobject(L, "Matrix", sizeof(Matrix));
  *m3 = MatrixMultiply(*m1, *m2);
  return 1;
}

int lua_class_matrix__Eq(lua_State *L){
  Matrix * m1 = (Matrix *)luaL_checkudata(L, 1, "Matrix");
  Matrix * m2 = (Matrix *)luaL_checkudata(L, 2, "Matrix");

  bool eq = (m1->m0  == m2->m0 ) && (m1->m1  == m2->m1 ) &&
            (m1->m2  == m2->m2 ) && (m1->m3  == m2->m3 ) &&
            (m1->m4  == m2->m4 ) && (m1->m5  == m2->m5 ) &&
            (m1->m6  == m2->m6 ) && (m1->m7  == m2->m7 ) &&
            (m1->m8  == m2->m8 ) && (m1->m9  == m2->m9 ) &&
            (m1->m10 == m2->m10) && (m1->m11 == m2->m11) &&
            (m1->m12 == m2->m12) && (m1->m13 == m2->m13) &&
            (m1->m14 == m2->m14) && (m1->m15 == m2->m15);
  lua_pushboolean(L, eq);
  return 1;
}

int lua_class_matrix__ToString(lua_State *L){
  Matrix * m = (Matrix *)luaL_checkudata(L, 1, "Matrix");
  lua_pushfstring(L, "Matrix[[%f, %f, %f, %f], [%f, %f, %f, %f], [%f, %f, %f, %f], [%f, %f, %f, %f]]: 0x%0.8x",
    m->m0,  m->m1,  m->m2,  m->m3,
    m->m4,  m->m5,  m->m6,  m->m7,
    m->m8,  m->m9,  m->m10, m->m11,
    m->m12, m->m13, m->m14, m->m15,
    m);
  return 1;
}

luaL_Reg luaray_class_matrix[] = {
  {"clone",       lua_class_matrix_Clone},
  {"get",         lua_class_matrix_Get},
  {"set",         lua_class_matrix_Set},
  {"determinant", lua_class_matrix_Determinant},
  {"trace",       lua_class_matrix_Trace},
  {"transpose",   lua_class_matrix_Transpose},
  {"invert",      lua_class_matrix_Invert},
  {"normalize",   lua_class_matrix_Normalize},
  {"identity",    lua_class_matrix_Identity},
  {"add",         lua_class_matrix_Add},
  {"subtract",    lua_class_matrix_Subtract},
  {"translate",   lua_class_matrix_Translate},
  {"rotate",      lua_class_matrix_Rotate},
  {"rotateXYZ",   lua_class_matrix_RotateXYZ},
  {"rotateX",     lua_class_matrix_RotateX},
  {"rotateY",     lua_class_matrix_RotateY},
  {"rotateZ",     lua_class_matrix_RotateZ},
  {"scale",       lua_class_matrix_Scale},
  {"multiply",    lua_class_matrix_Multiply},
  {"frustum",     lua_class_matrix_Frustum},
  {"perspective", lua_class_matrix_Perspective},
  {"ortho",       lua_class_matrix_Ortho},
  {"lookAt",      lua_class_matrix_LookAt},
  {"toFloatV",    lua_class_matrix_Get},
  // meta
  {"__add",       lua_class_matrix__Add},
  {"__sub",       lua_class_matrix__Sub},
  {"__mul",       lua_class_matrix__Mul},
  {"__eq",        lua_class_matrix__Eq},
  {"__tostring",  lua_class_matrix__ToString},
  {NULL, NULL}
};

/*!MD
## Vector4
Vector4 also Quaternion, so it have Quaternion methods.
Structure:

| Field  | Type  |
| :----- | :---- |
| x      | float |
| y      | float |
| z      | float |
| w      | float |

| **Methods**                                            | description 
| :-----                                                 | :-----------
| [clone](#Vector4clone)                                 | Creates copy of vector
| [get](#Vector4get)                                     | Returns vector fields
| [set](#Vector4set)                                     | Assing values to vector
| [add](#Vector4add)                                     | Add vector to vector (modifying it)
| [subtract](#Vector4subtract)                           | Subtract vector from vector (modifying it)
| [scale](#Vector4scale)                                 | Multiply each component of vector to scalar
| [multiplyV](#Vector4multiplyV)                         | Multiply vector to another vector (modifying it)
| [multiply](#Vector4multiply)                           | Multiply vector to scalar or another vector (modifying it)
| [identity](#Vector4identity)                           | Set vector components to quaternion identity
| [length](#Vector4length)                               | Returns vector scalar length
| [normalize](#Vector4normalize)                         | Normalize provided quaternion
| [qInvert](#Vector4qInvert)                             | Invert provided quaternion
| [qMultiply](#Vector4qMultiply)                         | Multiply quaternion to another (modifying it)
| [qLerp](#Vector4qLerp)                                 | Linear interpolate quaternion to another by given interpolant
| [qNlerp](#Vector4qNlerp)                               | Linear interpolate quaternion to another by given interpolant, and normalize it
| [qSlerp](#Vector4qSlerp)                               | Spherical interpolate quaternion to another by given interpolant
| [qFromVector3ToVector3](#Vector4qFromVector3ToVector3) | Calculate quaternion based on the rotation from one vector to another
| [qFromMatrix](#Vector4qFromMatrix)                     | Set vector components to a quaternion for a given rotation matrix
| [qToMatrix](#Vector4qToMatrix)                         | Returns a matrix for a given quaternion
| [qFromAxisAngle](#Vector4qFromAxisAngle)               | Set vector components to a rotation quaternion for an angle and axis (radians)
| [qToAxisAngle](#Vector4qToAxisAngle)                   | Returns the rotation angle and axis for a given quaternion
| [qFromEuler](#Vector4qFromEuler)                       | Set vector components to a quaternion equivalent of Euler angles
| [qToEuler](#Vector4qToEuler)                           | Return the Euler angles equivalent to quaternion (roll, pitch, yaw)
| [qTransform](#Vector4qTransform)                       | Transform a quaternion given a transformation matrix
| **Overloads**                                          | Note: In the mul/div methods with numbers, the vector should be in FIRST place, `NewVec4 = Vec4 * 5` is ok `NewVec4 = 5 * Vec4` raises error
| +: `NewVec4 = Vec4A + Vec4B`                           | Create a new vector that is the sum of two vectors
| -: `NewVec4 = Vec4A - Vec4B`                           | Create a new vector that is the subtraction of two vectors
| *: `NewVec4 = Vec4A * Vec4B`                           | Create a new vector that is the multiplication of two vectors
| *: `NewVec4 = Vec4A * NumB`                            | Create a new vector that is the multiplication of vector by number (scale)
| /: `NewVec4 = Vec4A / Vec4B`                           | Create a new vector that is the division of two vectors
| /: `NewVec4 = Vec4A / NumB`                            | Create a new vector that is the division of vector by number (divide each vector component)
| #: `Len = #Vec4`                                       | Returns vector scalar length (:length shortcut)
| ^: `NewVec4 = Vec4A ^ Vec4B`                           | Create a new vector that is the power of two vectors
| ^: `NewVec4 = Vec4A ^ NumB`                            | Create a new vector that is the power of vector to number
| =: `isEqual = Vec4A == Vec4B`                          | Checks vectors equality
| -: `NegVec4 = -Vec4`                                   | Creates new vector that is negate of another

### Initialization
```lua
-- variants
Vector4 Vec4 = rl.Vector4(number x, number y, number z,  number w) --> Vec4[x, y, z, w]
Vector4 Vec4 = rl.Vector4(number x)                       --> Vec4[x, x, x, x]
Vector4 Vec4 = rl.Vector4(table t)                        --> Vec4[ t[1], t[2], t[3], t[4] ]
```
Creates new Vector4 object.
*/
int lua_class_vector4_new(lua_State *L){
  Vector4 * v = (Vector4 *)luax_newobject(L, "Vector4", sizeof(Vector4));
  if (lua_isnumber(L, 1)) {
    v->x = luaL_checkinteger(L, 1);
    v->y = luax_optnumber(L, 2, v->x);
    v->z = luax_optnumber(L, 3, v->x);
    v->w = luax_optnumber(L, 4, v->x);
    return 1;
  }
  if (lua_istable(L, 1)) {
		for (int i = 0; i < 4; i++) lua_rawgeti (L, 1, i + 1);
    v->x = luax_optnumber(L, -4, 0);
    v->y = luax_optnumber(L, -3, 0);
    v->z = luax_optnumber(L, -2, 0);
    v->w = luax_optnumber(L, -1, 0);
    lua_pop(L, 4);
    return 1;
  }

  return 1;
}

/*!MD
#### Vector4:clone
```lua
Vector4 Vec4 = Vector4:clone()
```
Creates copy of vector
*/
int lua_class_vector4_Clone(lua_State *L){
  Vector4 * v1 = (Vector4 *)luaL_checkudata(L, 1, "Vector4");
  Vector4 * v2 = (Vector4 *)luax_newobject(L, "Vector4", sizeof(Vector4));
  v2->x = v1->x; v2->y = v1->y; v2->z = v1->z; v2->w = v1->w;
  return 1;
}


/*!MD
#### Vector4:get
```lua
-- variants
number x, number y, number z, number w = Vector4:get()
table t = Vector4:get('t') --> {x, y, z, w}
```
Get Vector4 components.
*/
int lua_class_vector4_Get(lua_State *L){
  Vector4 * v = (Vector4 *)luaL_checkudata(L, 1, "Vector4");
  if (luax_optstring(L, 2, "\0")[0] == 't'){
    lua_newtable(L);
    luax_tnnumber(L, 1, (float)v->x);
    luax_tnnumber(L, 2, (float)v->y);
    luax_tnnumber(L, 3, (float)v->z);
    luax_tnnumber(L, 4, (float)v->w);
    return 1;
  }
  lua_pushnumber(L, v->x);
  lua_pushnumber(L, v->y);
  lua_pushnumber(L, v->z);
  lua_pushnumber(L, v->w);
  return 4;
}

/*!MD
#### Vector4:set
```lua
-- variants
Vector4:set(number x, number y, number z, number w)
Vector4:set(table t) -- [x, y, z, w]
```
Set Vector4 components.
*/
int lua_class_vector4_Set(lua_State *L){
  Vector4 * v = (Vector4 *)luaL_checkudata(L, 1, "Vector4");
  v->x = luax_optnumber(L, 2, v->x);
  v->y = luax_optnumber(L, 3, v->y);
  v->z = luax_optnumber(L, 4, v->z);
  v->w = luax_optnumber(L, 5, v->w);

  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Vector4:add
```lua
Vector4:add(Vector4 Vector)
```
Add vector to vector (modifying it)
*/
int lua_class_vector4_Add(lua_State *L){
  Vector4 * v1 = (Vector4 *)luaL_checkudata(L, 1, "Vector4");
  Vector4 * v2 = (Vector4 *)luaL_checkudata(L, 2, "Vector4");
  v1->x += v2->x;
  v1->y += v2->y;
  v1->z += v2->z;
  v1->w += v2->w;

  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Vector4:subtract
```lua
Vector4:subtract(Vector4 Vector)
```
Subtract vector from vector (modifying it)
*/
int lua_class_vector4_Subtract(lua_State *L){
  Vector4 * v1 = (Vector4 *)luaL_checkudata(L, 1, "Vector4");
  Vector4 * v2 = (Vector4 *)luaL_checkudata(L, 2, "Vector4");
  v1->x -= v2->x;
  v1->y -= v2->y;
  v1->z -= v2->z;
  v1->w -= v2->w;

  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Vector4:scale
```lua
Vector4:subtract(number Scale)
```
Multiply each component of vector to scalar
*/
int lua_class_vector4_Scale(lua_State *L){
  Vector4 * v1 = (Vector4 *)luaL_checkudata(L, 1, "Vector4");
  float n = luaL_checknumber(L, 2);
  v1->x *= n;
  v1->y *= n;
  v1->z *= n;
  v1->w *= n;

  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Vector4:multiplyV
```lua
Vector4:multiplyV(Vector4 Vector)
```
Multiply vector to another vector (modifying it)
*/
int lua_class_vector4_MultiplyV(lua_State *L){
  Vector4 * v1 = (Vector4 *)luaL_checkudata(L, 1, "Vector4");
  Vector4 * v2 = (Vector4 *)luaL_checkudata(L, 2, "Vector4");
  v1->x *= v2->x;
  v1->y *= v2->y;
  v1->z *= v2->z;
  v1->w *= v2->w;

  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Vector4:multiply
```lua
-- variants
Vector4:multiply(number Scale)
Vector4:multiply(Vector4 Vector)
```
Multiply vector to scalar or another vector (modifying it)
*/
int lua_class_vector4_Multiply(lua_State *L){
  Vector4 * v1 = (Vector4 *)luaL_checkudata(L, 1, "Vector4");
  if (lua_isnumber(L, 2)){
    float n = luaL_checknumber(L, 2);
    v1->x *= n; v1->y *= n; v1->z *= n; v1->w *= n;

    lua_settop(L, 1);
    return 1;
  }

  Vector4 * v2 = (Vector4 *)luaL_checkudata(L, 2, "Vector4");
  v1->x *= v2->x; v1->y *= v2->y; v1->z *= v2->z; v1->w *= v2->w;

  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Vector4:identity
```lua
Vector4:identity()
```
Set vector components to quaternion identity
*/
int lua_class_vector4_Identity(lua_State *L){
  Vector4 * v = (Vector4 *)luaL_checkudata(L, 1, "Vector4");
  v->x = 0.0;
  v->y = 0.0;
  v->z = 0.0;
  v->w = 1.0;
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Vector4:length
```lua
number Length = Vector4:length()
```
Returns vector scalar length
*/
int lua_class_vector4_Length(lua_State *L){
  Vector4 * v = (Vector4 *)luaL_checkudata(L, 1, "Vector4");
  float x = v->x, y = v->y, z = v->z, w = v->w;
  float result = (float)sqrt(x*x + y*y + z*z + w*w);
  lua_pushnumber(L, result);
  return 1;
}

/*!MD
#### Vector4:normalize
```lua
Vector4:normalize()
```
Normalize provided quaternion
*/
Vector4 * _ptr_vector4_QuaternionNormalize(Vector4 * v){
  float l, il;
  float x = v->x, y = v->y, z = v->z, w = v->w;

  l = (float)sqrt(x*x + y*y + z*z + w*w);
  if (l == 0.0f) l = 1.0f;
  il = 1.0f/l;

  v->x *= il; v->y *= il; v->z *= il; v->w *= il;
  return v;
}

int lua_class_vector4_Normalize(lua_State *L){
  Vector4 * v = (Vector4 *)luaL_checkudata(L, 1, "Vector4");
  _ptr_vector4_QuaternionNormalize(v);

  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Vector4:qInvert
```lua
Vector4:qInvert()
```
Invert provided quaternion
*/
int lua_class_vector4_QuaternionInvert(lua_State *L){
  Vector4 * v = (Vector4 *)luaL_checkudata(L, 1, "Vector4");
  float l, il;
  l = QuaternionLength(*v);
  float lengthSq = l*l;
  if (lengthSq != 0.0) {
    float i = 1.0f/lengthSq;
    v->x *= -i; v->y *= -i; v->z *= -i; v->w *= i;
  }

  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Vector4:qMultiply
```lua
Vector4:qMultiply(Vector4 Vector)
```
Multiply quaternion to another (modifying it)
*/
int lua_class_vector4_QuaternionMultiply(lua_State *L){
  Vector4 * v1 = (Vector4 *)luaL_checkudata(L, 1, "Vector4");
  Vector4 * v2 = (Vector4 *)luaL_checkudata(L, 2, "Vector4");
  float vax = v1->x, vay = v1->y, vaz = v1->z, vaw = v1->w;
  float vbx = v2->x, vby = v2->y, vbz = v2->z, vbw = v2->w;

  v1->x = vax*vbw + vaw*vbx + vay*vbz - vaz*vby;
  v1->y = vay*vbw + vaw*vby + vaz*vbx - vax*vbz;
  v1->z = vaz*vbw + vaw*vbz + vax*vby - vay*vbx;
  v1->w = vaw*vbw - vax*vbx - vay*vby - vaz*vbz;

  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Vector4:qLerp
```lua
Vector4:qLerp(Vector4 Vector, scale Amount)
```
Linear interpolate quaternion to another by given interpolant
*/
int lua_class_vector4_QuaternionLerp(lua_State *L){
  Vector4 * v1 = (Vector4 *)luaL_checkudata(L, 1, "Vector4");
  Vector4 * v2 = (Vector4 *)luaL_checkudata(L, 2, "Vector4");
  float amount = luaL_checknumber(L, 3);

  v1->x = v1->x + amount*(v2->x - v1->x);
  v1->y = v1->y + amount*(v2->y - v1->y);
  v1->z = v1->z + amount*(v2->z - v1->z);
  v1->w = v1->w + amount*(v2->w - v1->w);

  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Vector4:qNlerp
```lua
Vector4:qNlerp(Vector4 Vector, scale Amount)
```
Linear interpolate quaternion to another by given interpolant, and normalize it
*/
Vector4 * _ptr_vector4_QuaternionNlerp(Vector4 * v1, Vector4 * v2, float amount){
  v1->x = v1->x + amount*(v2->x - v1->x);
  v1->y = v1->y + amount*(v2->y - v1->y);
  v1->z = v1->z + amount*(v2->z - v1->z);
  v1->w = v1->w + amount*(v2->w - v1->w);
  float x = v1->x, y = v1->y, z = v1->z, w = v1->w;

  float length = (float)sqrt(x*x + y*y + z*z + w*w);
  v1->x /= length;
  v1->y /= length;
  v1->z /= length;
  v1->w /= length;
  return v1;
}

int lua_class_vector4_QuaternionNlerp(lua_State *L){
  Vector4 * v1 = (Vector4 *)luaL_checkudata(L, 1, "Vector4");
  Vector4 * v2 = (Vector4 *)luaL_checkudata(L, 2, "Vector4");
  float amount = luaL_checknumber(L, 3);
  _ptr_vector4_QuaternionNlerp(v1, v2, amount);

  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Vector4:qSlerp
```lua
Vector4:qSlerp(Vector4 Vector, scale Amount)
```
Spherical interpolate quaternion to another by given interpolant
*/
int lua_class_vector4_QuaternionSlerp(lua_State *L){
  Vector4 * v1 = (Vector4 *)luaL_checkudata(L, 1, "Vector4");
  Vector4 * v2 = (Vector4 *)luaL_checkudata(L, 2, "Vector4");
  float amount = luaL_checknumber(L, 3);

  float cosHalfTheta =  v1->x*v2->x + v1->y*v2->y + v1->z*v2->z + v1->w*v2->w;

  if (fabs(cosHalfTheta) >= 1.0f){
    lua_settop(L, 1);
    return 1;
  }
  else if (cosHalfTheta > 0.95f){
    _ptr_vector4_QuaternionNlerp(v1, v2, amount);
    lua_settop(L, 1);
    return 1;
  }
  else {
    float halfTheta    = (float)acos(cosHalfTheta);
    float sinHalfTheta = (float)sqrt(1.0f - cosHalfTheta*cosHalfTheta);

    if (fabs(sinHalfTheta) < 0.001f) {
        v1->x = (v1->x*0.5f + v2->x*0.5f);
        v1->y = (v1->y*0.5f + v2->y*0.5f);
        v1->z = (v1->z*0.5f + v2->z*0.5f);
        v1->w = (v1->w*0.5f + v2->w*0.5f);
    }
    else {
      float ratioA = sinf((1 - amount)*halfTheta)/sinHalfTheta;
      float ratioB = sinf(amount*halfTheta)/sinHalfTheta;

      v1->x = (v1->x*ratioA + v2->x*ratioB);
      v1->y = (v1->y*ratioA + v2->y*ratioB);
      v1->z = (v1->z*ratioA + v2->z*ratioB);
      v1->w = (v1->w*ratioA + v2->w*ratioB);
    }
  }

  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Vector4:qFromVector3ToVector3
```lua
Vector4:qFromVector3ToVector3(Vector3 Vector1, Vector3 Vector2)
```
Calculate quaternion based on the rotation from one vector to another
*/
int lua_class_vector4_QuaternionFromVector3ToVector3(lua_State *L){
  Vector4 * v1 = (Vector4 *)luaL_checkudata(L, 1, "Vector4");
  Vector3 * v2 = (Vector3 *)luaL_checkudata(L, 2, "Vector3");
  Vector3 * v3 = (Vector3 *)luaL_checkudata(L, 3, "Vector3");

  float cos2Theta = Vector3DotProduct(*v2, *v3);
  _ptr_vector3_CrossProduct(v2, v3);

  v1->x = v2->x;
  v1->y = v2->y;
  v1->z = v2->z;
  v1->w = 1.0f + cos2Theta;     // NOTE: Added QuaternioIdentity()

  // Normalize to essentially nlerp the original and identity to 0.5
  _ptr_vector4_QuaternionNormalize(v1);

  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Vector4:qFromMatrix
```lua
Vector4:qFromMatrix(Matrix Matrix)
```
Set vector components to a quaternion for a given rotation matrix
*/
int lua_class_vector4_QuaternionFromMatrix(lua_State *L){
  Vector4 * v = (Vector4 *)luaL_checkudata(L, 1, "Vector4");
  Matrix  * m = (Matrix  *)luaL_checkudata(L, 2, "Matrix");

  float trace = MatrixTrace(*m);

  if (trace > 0.0f) {
    float s = (float)sqrt(trace + 1)*2.0f;
    float invS = 1.0f/s;

    v->w = s*0.25f;
    v->x = (m->m6 - m->m9)*invS;
    v->y = (m->m8 - m->m2)*invS;
    v->z = (m->m1 - m->m4)*invS;
    lua_settop(L, 1);
    return 1;
  }
  else {
    float m00 = m->m0, m11 = m->m5, m22 = m->m10;

    if (m00 > m11 && m00 > m22) {
      float s = (float)sqrt(1.0f + m00 - m11 - m22)*2.0f;
      float invS = 1.0f/s;
      v->w = (m->m6 - m->m9)*invS;
      v->x = s*0.25f;
      v->y = (m->m4 + m->m1)*invS;
      v->z = (m->m8 + m->m2)*invS;
    }
    else if (m11 > m22) {
      float s = (float)sqrt(1.0f + m11 - m00 - m22)*2.0f;
      float invS = 1.0f/s;

      v->w = (m->m8 - m->m2)*invS;
      v->x = (m->m4 + m->m1)*invS;
      v->y = s*0.25f;
      v->z = (m->m9 + m->m6)*invS;
    }
    else {
      float s = (float)sqrt(1.0f + m22 - m00 - m11)*2.0f;
      float invS = 1.0f/s;

      v->w = (m->m1 - m->m4)*invS;
      v->x = (m->m8 + m->m2)*invS;
      v->y = (m->m9 + m->m6)*invS;
      v->z = s*0.25f;
    }
  }

  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Vector4:qToMatrix
```lua
Matrix Matrix = Vector4:qToMatrix()
```
Returns a matrix for a given quaternion
*/
int lua_class_vector4_QuaternionToMatrix(lua_State *L){
  Vector4 * v = (Vector4 *)luaL_checkudata(L, 1, "Vector4");
  Matrix  * m = (Matrix *)luax_newobject(L, "Matrix", sizeof(Matrix));

  float x = v->x, y = v->y, z = v->z, w = v->w;

  float x2 = x + x, y2 = y + y, z2 = z + z;

  float length = QuaternionLength(*v);
  float lengthSquared = length*length;

  float xx = x*x2/lengthSquared;
  float xy = x*y2/lengthSquared;
  float xz = x*z2/lengthSquared;
  float yy = y*y2/lengthSquared;
  float yz = y*z2/lengthSquared;
  float zz = z*z2/lengthSquared;
  float wx = w*x2/lengthSquared;
  float wy = w*y2/lengthSquared;
  float wz = w*z2/lengthSquared;

  m->m0  = 1.0f - (yy + zz); m->m1  = xy - wz;          m->m2  = xz + wy;          m->m3  = 0.0f;
  m->m4  = xy + wz;          m->m5  = 1.0f - (xx + zz); m->m6  = yz - wx;          m->m7  = 0.0f;
  m->m8  = xz - wy;          m->m9  = yz + wx;          m->m10 = 1.0f - (xx + yy); m->m11 = 0.0f;
  m->m12 = 0.0f;             m->m13 = 0.0f;             m->m14 = 0.0f;             m->m15 = 1.0f;

  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Vector4:qFromAxisAngle
```lua
Vector4:qFromAxisAngle(Vector3 Vector, number Angle)
```
Set vector components to a rotation quaternion for an angle and axis (radians)
*/
int lua_class_vector4_QuaternionFromAxisAngle(lua_State *L){
  Vector4 * v1 = (Vector4 *)luaL_checkudata(L, 1, "Vector4");
  Vector3 * v2 = (Vector3 *)luaL_checkudata(L, 2, "Vector3");
  float angle  = luaL_checknumber(L, 3);

  if (Vector3Length(*v2) != 0.0f) angle *= 0.5f;
  _ptr_vector3_Normalize(v2);

  float sinres = sinf(angle);
  float cosres = cosf(angle);

  v1->x = v2->x*sinres;
  v1->y = v2->y*sinres;
  v1->z = v2->z*sinres;
  v1->w = cosres;
  _ptr_vector4_QuaternionNormalize(v1);

  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Vector4:qToAxisAngle
```lua
Vector3 Vector, number Angle = Vector4:qToAxisAngle()
```
Returns the rotation angle and axis for a given quaternion
*/
int lua_class_vector4_QuaternionToAxisAngle(lua_State *L){
  lua_settop(L, 1);
  Vector4 * v1 = (Vector4 *)luaL_checkudata(L, 1, "Vector4");
  Vector3 * v2 = (Vector3 *)luax_newobject(L, "Vector3", sizeof(Vector3));

  if (fabs(v1->w) > 1.0f) _ptr_vector4_QuaternionNormalize(v1);
  float resAngle = 0.0f;

  resAngle = 2.0f*(float)acos(v1->w);
  float den = (float)sqrt(1.0f - v1->w*v1->w);

  if (den > 0.0001f) {
    v2->x = v1->x/den;
    v2->y = v1->y/den;
    v2->z = v1->z/den;
  }
  else {
      // This occurs when the angle is zero.
      // Not a problem: just set an arbitrary normalized axis.
      v2->x = 1.0f;
  }

  lua_pushnumber(L, resAngle);
  return 2;
}

/*!MD
#### Vector4:qFromEuler
```lua
Vector4:qFromEuler(number Roll, number Pitch, number Yaw)
```
Set vector components to a quaternion equivalent of Euler angles
*/
int lua_class_vector4_QuaternionFromEuler(lua_State *L){
  Vector4 * v = (Vector4 *)luaL_checkudata(L, 1, "Vector4");
  float roll  = luaL_checknumber(L, 2);
  float pitch = luaL_checknumber(L, 3);
  float yaw   = luaL_checknumber(L, 4);

  float x0 = cosf(roll  * 0.5f);
  float x1 = sinf(roll  * 0.5f);
  float y0 = cosf(pitch * 0.5f);
  float y1 = sinf(pitch * 0.5f);
  float z0 = cosf(yaw   * 0.5f);
  float z1 = sinf(yaw   * 0.5f);

  v->x = x1*y0*z0 - x0*y1*z1;
  v->y = x0*y1*z0 + x1*y0*z1;
  v->z = x0*y0*z1 - x1*y1*z0;
  v->w = x0*y0*z0 + x1*y1*z1;

  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Vector4:qToEuler
```lua
number Roll, number Pitch, number Yaw = Vector4:qToEuler()
```
Return the Euler angles equivalent to quaternion (roll, pitch, yaw)
*/
int lua_class_vector4_QuaternionToEuler(lua_State *L){
  Vector4 * v = (Vector4 *)luaL_checkudata(L, 1, "Vector4");

  // roll (x-axis rotation)
  float x0 = 2.0f*(v->w*v->x + v->y*v->z);
  float x1 = 1.0f - 2.0f*(v->x*v->x + v->y*v->y);
  lua_pushnumber(L, atan2f(x0, x1)*RAD2DEG);

  // pitch (y-axis rotation)
  float y0 = 2.0f*(v->w*v->y - v->z*v->x);
  y0 = y0 > 1.0f ? 1.0f : y0;
  y0 = y0 < -1.0f ? -1.0f : y0;
  lua_pushnumber(L, asinf(y0)*RAD2DEG);

  // yaw (z-axis rotation)
  float z0 = 2.0f*(v->w*v->z + v->x*v->y);
  float z1 = 1.0f - 2.0f*(v->y*v->y + v->z*v->z);
  lua_pushnumber(L, atan2f(z0, z1)*RAD2DEG);
  return 3;
}

/*!MD
#### Vector4:qTransform
```lua
Vector4:qTransform(Matrix Matrix)
```
Transform a quaternion given a transformation matrix
*/
int lua_class_vector4_QuaternionTransform(lua_State *L){
  Vector4 * v = (Vector4 *)luaL_checkudata(L, 1, "Vector4");
  Matrix  * m = (Matrix  *)luaL_checkudata(L, 2, "Matrix");
  v->x = m->m0*v->x + m->m4*v->y + m->m8*v->z + m->m12*v->w;
  v->y = m->m1*v->x + m->m5*v->y + m->m9*v->z + m->m13*v->w;
  v->z = m->m2*v->x + m->m6*v->y + m->m10*v->z + m->m14*v->w;
  v->w = m->m3*v->x + m->m7*v->y + m->m11*v->z + m->m15*v->w;

  lua_settop(L, 1);
  return 1;
}

int lua_class_vector4__Index(lua_State *L){
  if (!luax_type(L, 2, LUA_TSTRING)) return 0;
  Vector4 *    v   = (Vector4 *)luaL_checkudata(L, 1, "Vector4");
  const char * key = luaL_checkstring(L, 2);

  lua_class_GetFieldIfCompared(L, v, key, "x", x); // calls "return" from this function on success
  lua_class_GetFieldIfCompared(L, v, key, "y", y);
  lua_class_GetFieldIfCompared(L, v, key, "z", z);
  lua_class_GetFieldIfCompared(L, v, key, "w", w);
  
  luax_getclasskey(L, 1, 2);
  return 1;
}

int lua_class_vector4__Newindex(lua_State *L){
  if (!luax_type(L, 2, LUA_TSTRING)) return 0;
  Vector4 *    v     = (Vector4 *)luaL_checkudata(L, 1, "Vector4");
  const char * key   = luaL_checkstring(L, 2);
  float        value = luaL_checknumber(L, 3);
  lua_class_SetFieldIfCompared(L, v, key, value, "x", x);
  lua_class_SetFieldIfCompared(L, v, key, value, "y", y);
  lua_class_SetFieldIfCompared(L, v, key, value, "z", z);
  lua_class_SetFieldIfCompared(L, v, key, value, "w", w);
  return 0;
}

int lua_class_vector4__Add(lua_State *L){
  Vector4 * v1 = (Vector4 *)luaL_checkudata(L, 1, "Vector4");
  Vector4 * v2 = (Vector4 *)luaL_checkudata(L, 2, "Vector4");
  Vector4 * v3 = (Vector4 *)luax_newobject(L, "Vector4", sizeof(Vector4));
  v3->x = v1->x + v2->x;
  v3->y = v1->y + v2->y;
  v3->z = v1->z + v2->z;
  v3->w = v1->w + v2->w;
  return 1;
}

int lua_class_vector4__Sub(lua_State *L){
  Vector4 * v1 = (Vector4 *)luaL_checkudata(L, 1, "Vector4");
  Vector4 * v2 = (Vector4 *)luaL_checkudata(L, 2, "Vector4");
  Vector4 * v3 = (Vector4 *)luax_newobject(L, "Vector4", sizeof(Vector4));
  v3->x = v1->x - v2->x;
  v3->y = v1->y - v2->y;
  v3->z = v1->z - v2->z;
  v3->w = v1->w - v2->w;
  return 1;
}

int lua_class_vector4__Mul(lua_State *L){
  Vector4 * v1 = (Vector4 *)luaL_checkudata(L, 1, "Vector4");
  Vector4 * v3 = (Vector4 *)luax_newobject(L, "Vector4", sizeof(Vector4));
  if ( lua_isnumber(L, 2) ){
    float n = luaL_checknumber(L, 2);
    v3->x = v1->x * n;
    v3->y = v1->y * n;
    v3->z = v1->z * n;
    v3->w = v1->w * n;
    return 1;
  }
  Vector4 * v2 = (Vector4 *)luaL_checkudata(L, 2, "Vector4");
  v3->x = v1->x * v2->x;
  v3->y = v1->y * v2->y;
  v3->z = v1->z * v2->z;
  v3->w = v1->w * v2->w;
  return 1;
}

int lua_class_vector4__Div(lua_State *L){
  Vector4 * v1 = (Vector4 *)luaL_checkudata(L, 1, "Vector4");
  Vector4 * v3 = (Vector4 *)luax_newobject(L, "Vector4", sizeof(Vector4));
  if ( lua_isnumber(L, 2) ){
    float n = luaL_checknumber(L, 2);
    v3->x = v1->x / n;
    v3->y = v1->y / n;
    v3->z = v1->z / n;
    v3->w = v1->w / n;
    return 1;
  }
  Vector4 * v2 = (Vector4 *)luaL_checkudata(L, 2, "Vector4");
  v3->x = v1->x / v2->x;
  v3->y = v1->y / v2->y;
  v3->z = v1->z / v2->z;
  v3->w = v1->w / v2->w;
  return 1;
}

int lua_class_vector4__Pow(lua_State *L){
  Vector4 * v1 = (Vector4 *)luaL_checkudata(L, 1, "Vector4");
  Vector4 * v3 = (Vector4 *)luax_newobject(L, "Vector4", sizeof(Vector4));
  if ( lua_isnumber(L, 2) ){
    float n = luaL_checknumber(L, 2);
    v3->x = pow(v3->x, n);
    v3->y = pow(v3->y, n);
    v3->z = pow(v3->z, n);
    v3->w = pow(v3->w, n);
    return 1;
  }
  Vector4 * v2 = (Vector4 *)luaL_checkudata(L, 2, "Vector4");
  v3->x = pow(v3->x, v2->x);
  v3->y = pow(v3->y, v2->y);
  v3->z = pow(v3->z, v2->z);
  v3->w = pow(v3->w, v2->w);

  return 1;
}

int lua_class_vector4__Neg(lua_State *L){
  Vector4 * v1 = (Vector4 *)luaL_checkudata(L, 1, "Vector4");
  Vector4 * v2 = (Vector4 *)luax_newobject(L, "Vector4", sizeof(Vector4));
  v2->x = -v2->x; v2->y = -v2->y; v2->z = -v2->z; v2->w = -v2->w;
  return 1;
}

int lua_class_vector4__Eq(lua_State *L){
  Vector4 * v1 = (Vector4 *)luaL_checkudata(L, 1, "Vector4");
  Vector4 * v2 = (Vector4 *)luaL_checkudata(L, 2, "Vector4");
	bool eq = (v1->x == v2->x) && (v1->y == v2->y) && (v1->z == v2->z) && (v1->w == v2->w);
  lua_pushboolean(L, eq);
  return 1;
}

int lua_class_vector4__ToString(lua_State *L){
  Vector4 * v = (Vector4 *)luaL_checkudata(L, 1, "Vector4");
  lua_pushfstring(L, "Vector4[%f, %f, %f, %f]: 0x%0.8x", v->x, v->y, v->z, v->w, v);
  return 1;
}

luaL_Reg luaray_class_vector4[] = {
  {"clone",                 lua_class_vector4_Clone},
  {"get",                   lua_class_vector4_Get},
  {"set",                   lua_class_vector4_Set},
  {"add",                   lua_class_vector4_Add},
  {"subtract",              lua_class_vector4_Subtract},
  {"scale",                 lua_class_vector4_Scale},
  {"multiplyV",             lua_class_vector4_MultiplyV},
  {"multiply",              lua_class_vector4_Multiply},
  {"identity",              lua_class_vector4_Identity},
  {"length",                lua_class_vector4_Length},
  {"normalize",             lua_class_vector4_Normalize},
  {"qInvert",               lua_class_vector4_QuaternionInvert},
  {"qMultiply",             lua_class_vector4_QuaternionMultiply},
  {"qLerp",                 lua_class_vector4_QuaternionLerp},
  {"qNlerp",                lua_class_vector4_QuaternionNlerp},
  {"qSlerp",                lua_class_vector4_QuaternionSlerp},
  {"qFromVector3ToVector3", lua_class_vector4_QuaternionFromVector3ToVector3},
  {"qFromMatrix",           lua_class_vector4_QuaternionFromMatrix},
  {"qToMatrix",             lua_class_vector4_QuaternionToMatrix},
  {"qFromAxisAngle",        lua_class_vector4_QuaternionFromAxisAngle},
  {"qToAxisAngle",          lua_class_vector4_QuaternionToAxisAngle},
  {"qFromEuler",            lua_class_vector4_QuaternionFromEuler},
  {"qToEuler",              lua_class_vector4_QuaternionToEuler},
  {"qTransform",            lua_class_vector4_QuaternionTransform},
  // meta
  {"__index",               lua_class_vector4__Index},
  {"__newindex",            lua_class_vector4__Newindex},
  {"__add",                 lua_class_vector4__Add},
  {"__sub",                 lua_class_vector4__Sub},
  {"__mul",                 lua_class_vector4__Mul},
  {"__div",                 lua_class_vector4__Div},
  {"__pow",                 lua_class_vector4__Pow},
  {"__unm",                 lua_class_vector4__Neg},
  {"__len",                 lua_class_vector4_Length},
  {"__tostring",            lua_class_vector4__ToString},
  {NULL, NULL}
};

/*!MD
## Color
Color component ranges is 0-255
Structure:

| Field  | Type    |
| :----- | :------ |
| r      | integer |
| g      | integer |
| b      | integer |
| a      | integer |

| **Methods**                            | description 
| :-----                                 | :-----------
| [clone](#Colorclone)                   | Create copy of color
| [get](#Colorget)                       | Return vector fields
| [set](#Colorset)                       | Assing values to color components
| [toInt](#ColortoInt)                   | Return color integer representation
| [fromInt](#ColorfromInt)               | Set color components from a given integer
| [normalize](#Colornormalize)           | Return normalized color components [float r/255, float g/255, float b/255, float a/255]
| [fromNormalized](#ColorfromNormalized) | Set color components from a given normalized values
| [toHSV](#ColortoHSV)                   | Return color hue, value and saturation
| [fromHSV](#ColorfromHSV)               | Set color components from a given hue, value and saturation
| [fade](#Colorfade)                     | Color fade-in or fade-out, alpha goes from 0.0f to 1.0f

### Initialization
```lua
-- variants
Color Color = rl.Color(number r, number g, number b,  number a) --> Color[r, g, b, a]
Color Color = rl.Color(table t)                                 --> Color[ t[1], t[2], t[3], t[4] ]
Color Color = rl.Color(string Color)
```
Creates new Color object.
Available string colors:

| string name   | color value         | hexadecimal
| :------------ | :------------------ | :--------
| `"lightgray"` | `{ 200, 200, 200 }` | #c8c8c8
| `"gray"`      | `{ 130, 130, 130 }` | #828282
| `"darkgray"`  | `{ 80,  80,  80  }` | #505050
| `"yellow"`    | `{ 253, 249, 0   }` | #fdf900
| `"gold"`      | `{ 255, 203, 0   }` | #ffcb00
| `"orange"`    | `{ 255, 161, 0   }` | #ffa100
| `"pink"`      | `{ 255, 109, 194 }` | #ff6dc2
| `"red"`       | `{ 230, 41,  55  }` | #e62937
| `"maroon"`    | `{ 190, 33,  55  }` | #be2137
| `"green"`     | `{ 0,   228, 48  }` | #00e430
| `"lime"`      | `{ 0,   158, 47  }` | #009e2f
| `"darkgreen"` | `{ 0,   117, 44  }` | #00752c
| `"skyblue"`   | `{ 102, 191, 255 }` | #66bfff
| `"blue"`      | `{ 0,   121, 241 }` | #0079f1
| `"darkblue"`  | `{ 0,   82,  172 }` | #0052ac
| `"purple"`    | `{ 200, 122, 255 }` | #c87aff
| `"violet"`    | `{ 135, 60,  190 }` | #873cbe
| `"darkpurple"`| `{ 112, 31,  126 }` | #701f7e
| `"beige"`     | `{ 211, 176, 131 }` | #d3b083
| `"brown"`     | `{ 127, 106, 79  }` | #7f6a4f
| `"darkbrown"` | `{ 76,  63,  47  }` | #4c3f2f
| `"white"`     | `{ 255, 255, 255 }` | #ffffff
| `"black"`     | `{ 0,   0,   0   }` | #000000
| `"blank"`     | `{ 0,   0,   0   }` | #000000
| `"magenta"`   | `{ 255, 0,   255 }` | #ff00ff
| `"raywhite"`  | `{ 245, 245, 245 }` | #f5f5f5

*/
int lua_class_color_new(lua_State *L){
  Color * c = (Color *)luax_newobject(L, "Color", sizeof(Color));

  if (lua_istable(L, 1)){
    for (int i = 0; i < 4; i++) lua_rawgeti(L, 1, i + 1);
    c->r = luax_optinteger(L, -4, 0);
    c->g = luax_optinteger(L, -3, 0);
    c->b = luax_optinteger(L, -2, 0);
    c->a = luax_optinteger(L, -1, 255);
    lua_pop(L, 4);
    return 1;
  }

  if (lua_type(L, 1) == LUA_TSTRING) {
    const char * s = luaL_checkstring(L, 1);
         if (!strcmp(s, "lightgray"))  *c = LIGHTGRAY;
    else if (!strcmp(s, "gray"))       *c = GRAY;
    else if (!strcmp(s, "darkgray"))   *c = DARKGRAY;
    else if (!strcmp(s, "yellow"))     *c = YELLOW;
    else if (!strcmp(s, "gold"))       *c = GOLD;
    else if (!strcmp(s, "orange"))     *c = ORANGE;
    else if (!strcmp(s, "pink"))       *c = PINK;
    else if (!strcmp(s, "red"))        *c = RED;
    else if (!strcmp(s, "maroon"))     *c = MAROON;
    else if (!strcmp(s, "green"))      *c = GREEN;
    else if (!strcmp(s, "lime"))       *c = LIME;
    else if (!strcmp(s, "darkgreen"))  *c = DARKGREEN;
    else if (!strcmp(s, "skyblue"))    *c = SKYBLUE;
    else if (!strcmp(s, "blue"))       *c = BLUE;
    else if (!strcmp(s, "darkblue"))   *c = DARKBLUE;
    else if (!strcmp(s, "purple"))     *c = PURPLE;
    else if (!strcmp(s, "violet"))     *c = VIOLET;
    else if (!strcmp(s, "darkpurple")) *c = DARKPURPLE;
    else if (!strcmp(s, "beige"))      *c = BEIGE;
    else if (!strcmp(s, "brown"))      *c = BROWN;
    else if (!strcmp(s, "darkbrown"))  *c = DARKBROWN;
    else if (!strcmp(s, "white"))      *c = WHITE;
    else if (!strcmp(s, "black"))      *c = BLACK;
    else if (!strcmp(s, "blank"))      *c = BLANK;
    else if (!strcmp(s, "magenta"))    *c = MAGENTA;
    else if (!strcmp(s, "raywhite"))   *c = RAYWHITE;
    return 1;
  }

  c->r = luax_optinteger(L, 1, 0);
  c->g = luax_optinteger(L, 2, 0);
  c->b = luax_optinteger(L, 3, 0);
  c->a = luax_optinteger(L, 4, 255);

  return 1;
}

/*!MD
#### Color:clone
```lua
Color Color = Color:clone()
```
Creates copy of color
*/
int lua_class_color_Clone(lua_State *L){
  Color * c1 = (Color *)luaL_checkudata(L, 1, "Color");
  Color * c2 = (Color *)luax_newobject(L, "Color", sizeof(Color));
  c2->r = c1->r; c2->g = c1->g; c2->b = c1->b; c2->a = c1->a;
  return 1;
}

/*!MD
#### Color:get
```lua
-- variants
integer r, integer g, integer b, integer a = Color:get()
table t = Color:get('t') -- t[r, g, b, a]
```
Return vector fields
*/
int lua_class_color_Get(lua_State *L){
  Color * c = (Color *)luaL_checkudata(L, 1, "Color");
  if (luax_optstring(L, 2, "\0")[0] == 't'){
    lua_newtable(L);
		luax_tnnumber(L, 1, (float)c->r / 255.0f);
		luax_tnnumber(L, 2, (float)c->g / 255.0f);
		luax_tnnumber(L, 3, (float)c->b / 255.0f);
		luax_tnnumber(L, 4, (float)c->a / 255.0f);
    return 1;
  }
  lua_pushnumber(L, c->r);
  lua_pushnumber(L, c->g);
  lua_pushnumber(L, c->b);
  lua_pushnumber(L, c->a);
  return 4;
}

/*!MD
#### Color:set
```lua
-- variants
Color:set(integer r, integer g, integer b[, integer a])
Color:set(table t) -- t[r, g, b, a]
```
Assing values to color components
*/
int lua_class_color_Set(lua_State *L){
  Color * c = (Color *)luaL_checkudata(L, 1, "Color");
	c->r = luax_optinteger(L, 2, c->r);
	c->g = luax_optinteger(L, 3, c->g);
	c->b = luax_optinteger(L, 4, c->b);
	c->a = luax_optinteger(L, 5, c->a);

  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Color:toInt
```lua
integer Color = Color:toInt()
```
Return color integer representation
*/
int lua_class_color_ToInteger(lua_State *L){
  Color * c = (Color *)luaL_checkudata(L, 1, "Color");
  int ic = ColorToInt(*c);
  lua_pushnumber(L, ic);
  return 1;
}

/*!MD
#### Color:fromInt
```lua
Color:fromInt(integer Color)
```
Set color components from a given integer
*/
int lua_class_color_FromInteger(lua_State *L){
  Color * c = (Color *)luaL_checkudata(L, 1, "Color");
  int hex   = luaL_checkinteger(L, 2);
  *c = GetColor(hex); lua_pop(L, 1);

  lua_settop(L, 1);
  return 1;
}

int lua_class_color_ToString(lua_State *L){
  Color * c = (Color *)luaL_checkudata(L, 1, "Color");
  int ic = ColorToInt(*c);
  lua_pushfstring(L, "%0.8x", ic);
  return 1;
}

/*!MD
#### Color:normalize
```lua
-- variants
Vector4 Vector = Color:normalize()
float r, float g, float b, float a = Color:normalize('n')
table t = Color:normalize('t')
```
Return normalized color components [float r/255, float g/255, float b/255, float a/255]
*/
int lua_class_color_Normalize(lua_State *L){
  Color *   c =   (Color *)luaL_checkudata(L, 1, "Color");
  if (lua_isstring(L, 2)){
    const char * s = luaL_checkstring(L, 2);
    if (s[0] == 'n'){ // to numbers
      lua_pushnumber(L, (float)c->r / 255.0f);
      lua_pushnumber(L, (float)c->g / 255.0f);
      lua_pushnumber(L, (float)c->b / 255.0f);
      lua_pushnumber(L, (float)c->a / 255.0f);
      return 4;
    }
    if (s[0] == 't'){ // to table
      lua_newtable(L);
      luax_tnnumber(L, 1, (float)c->r / 255.0f);
      luax_tnnumber(L, 2, (float)c->g / 255.0f);
      luax_tnnumber(L, 3, (float)c->b / 255.0f);
      luax_tnnumber(L, 4, (float)c->a / 255.0f);
      return 1;
    }
  }
  Vector4 * v = (Vector4 *)luax_newobject(L, "Vector4", sizeof(Vector4));
  *v = ColorNormalize(*c);
  return 1;
}

/*!MD
#### Color:fromNormalized
```lua
-- variants
Color:fromNormalized(Vector4 Vector)
Color:fromNormalized(float r, float g, float b, float a)
Color:fromNormalized(table t)
```
Set color components from a given normalized values
*/
int lua_class_color_FromNormalized(lua_State *L){
  Color *   c = (Color *)luaL_checkudata(L, 1, "Color");
  if (lua_isnumber(L, 2)){
    c->r = luaL_checkinteger(L, 2);
    c->g = luax_optinteger(L, 3, 0);
    c->b = luax_optinteger(L, 4, 0);
    c->a = luax_optinteger(L, 5, 255);
    lua_settop(L, 1);
    return 1;
  }

  if (lua_istable(L, 2)){
    for (int i = 0; i < 4; i++) lua_rawgeti (L, 1, i + 1);
    c->r = luax_optinteger(L, -4, 0);
    c->g = luax_optinteger(L, -3, 0);
    c->b = luax_optinteger(L, -2, 0);
    c->a = luax_optinteger(L, -1, 255);
    lua_settop(L, 1);
    return 1;
  }

  Vector4 * v = (Vector4 *)luaL_checkudata(L, 2, "Vector4");
  *c = ColorFromNormalized(*v); lua_pop(L, 1);
	
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Color:toHSV
```lua
number Hue, number Value, number Saturation = Color:toHSV()
```
Return color hue, value and saturation
*/
int lua_class_color_ToHSV(lua_State *L){
  Color *   c =   (Color *)luaL_checkudata(L, 1, "Color");
  Vector3 * v = (Vector3 *)luax_newobject(L, "Vector3", sizeof(Vector3));
  *v = ColorToHSV(*c);
  return 1;
}

/*!MD
#### Color:fromHSV
```lua
Color:fromHSV(number Hue, number Value, number Saturation)
```
Set color components from a given hue, value and saturation
*/
int lua_class_color_FromHSV(lua_State *L){
  Color *   c =   (Color *)luaL_checkudata(L, 1, "Color");
  Vector3 * v = (Vector3 *)luaL_checkudata(L, 2, "Vector3");
  *c = ColorFromHSV(*v);
	
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Color:fade
```lua
Color:fade(number Alpha)
```
Color fade-in or fade-out, alpha goes from 0.0f to 1.0f
*/
int lua_class_color_Fade(lua_State *L){
  Color * c =   (Color *)luaL_checkudata(L, 1, "Color");
  int alpha = luaL_checkinteger(L, 2);
  *c = Fade(*c, alpha);
	
  lua_settop(L, 1);
  return 1;
}

// metamethods mostly creates new objects
int lua_class_color__Index(lua_State *L){
  if (!luax_type(L, 2, LUA_TSTRING)) return 0;
  Color * c        = (Color *)luaL_checkudata(L, 1, "Color");
  const char * key = luaL_checkstring(L, 2);

  lua_class_GetFieldIfCompared(L, c, key, "r", r);
  lua_class_GetFieldIfCompared(L, c, key, "g", g);
  lua_class_GetFieldIfCompared(L, c, key, "b", b);
  lua_class_GetFieldIfCompared(L, c, key, "a", a);

  luax_getclasskey(L, 1, 2);
  return 1;
}

// metamethods mostly creates new objects
int lua_class_color__Newindex(lua_State *L){
  if (!luax_type(L, 2, LUA_TSTRING)) return 0;
  Color * c        = (Color *)luaL_checkudata(L, 1, "Color");
  const char * key = luaL_checkstring(L, 2);
  int value        = luaL_checkinteger(L, 3);
  lua_class_SetFieldIfCompared(L, c, key, value, "r", r);
  lua_class_SetFieldIfCompared(L, c, key, value, "g", g);
  lua_class_SetFieldIfCompared(L, c, key, value, "b", b);
  lua_class_SetFieldIfCompared(L, c, key, value, "a", a);
  return 0;
}

int lua_class_color__ToString(lua_State *L){
  Color * c = (Color *)luaL_checkudata(L, 1, "Color");
  lua_pushfstring(L, "Color[#%0.8x]: 0x%0.8x", ColorToInt(*c), c);
  return 1;
}

luaL_Reg luaray_class_color[] = {
  {"clone",          lua_class_color_Clone},
  {"get",            lua_class_color_Get},
  {"set",            lua_class_color_Set},
  {"toInt",          lua_class_color_ToInteger},
  {"fromInt",        lua_class_color_FromInteger},
  {"toHex",          lua_class_color_ToString},
  {"normalize",      lua_class_color_Normalize},
  {"fromNormalized", lua_class_color_FromNormalized},
  {"toHSV",          lua_class_color_ToHSV},
  {"fromHSV",        lua_class_color_FromHSV},
  {"fade",           lua_class_color_Fade},
  // meta
  {"__index",        lua_class_color__Index},
  {"__newindex",     lua_class_color__Newindex},
  {"__tostring",     lua_class_color__ToString},
  {NULL, NULL}
};


/*!MD
## Rectangle
Structure:

| Field  | Type  |
| :----- | :---- |
| x      | float |
| y      | float |
| width  | float |
| height | float |

| **Methods**                                    | description
| :---------------------------------------       | :-----------
| [clone](#Rectangleclone)                       | Create copy of rectangle
| [get](#Rectangleget)                           | Return vector fields
| [set](#Rectangleset)                           | Assing values to rectangle fields
| [move](#Rectanglemove)                         | Move rectangle by vector
| [getPosition](#RectanglegetPosition)           | Return rectangle position
| [setPosition](#RectanglesetPosition)           | Set rectangle position
| [getDimensions](#RectanglegetDimensions)       | Return rectangle width and height
| [setDimensions](#RectanglesetDimensions)       | Set rectangle width and height
| [draw](#Rectangledraw)                         | Draw rectangle
| [drawPro](#RectangledrawPro)                   | Draw rectangle with angle and offset
| [drawRounded](#RectangledrawRounded)           | Draw rectangle with rounded corners
| [drawGradient](#RectangledrawGradient)         | Draw rectangular color gradient
| [collideRect](#RectanglecollideRect)           | Check collision between two rectangles
| [collideCircle](#RectanglecollideCircle)       | Check collision between circle and rectangle
| [getCollisionRect](#RectanglegetCollisionRect) | Get collision rectangle for two rectangles collision
| [collidePoint](#RectanglecollidePoint)         | Check if point is inside rectangle

### Initialization
```lua
-- variants
Rectangle Rect = rl.Rectangle(number x, number y, number width,  number height)
Rectangle Rect = rl.Rectangle(table t) --> Rectangle[ x = t[1], y = t[2], width = t[3], height = t[4] ]
```
*/
int lua_class_rectangle_new(lua_State *L){
  Rectangle * r = (Rectangle *)luax_newobject(L, "Rectangle", sizeof(Rectangle));
  int top = lua_gettop(L);

  if (lua_isnumber(L, 1)) {
    r->x      = luaL_checknumber(L, 1);
    r->y      = luax_optnumber(L, 2, r->x);
    r->width  = luaL_checknumber(L, 3);
    r->height = luax_optnumber(L, 4, r->width);
    return 1;
  }
  else if (lua_istable(L, 1)){
    for (int i = 0; i < 4; i++) lua_rawgeti (L, 1, i + 1);
    r->x      = luaL_checknumber(L, -4);
    r->y      = luax_optnumber(L, 2, r->x);
    r->width  = luaL_checknumber(L, -2);
    r->height = luax_optnumber(L, 2, r->width);
    lua_settop(L, top);
    return 1;
  }
  else {
    lua_pushfstring(L, "Arg#1 number or table expected, got %s.", lua_typename(L, lua_type(L, 1)));
    lua_error(L);
  }

  return 1;
}

/*!MD
#### Rectangle:clone
```lua
Rectangle rec = Rectangle:clone()
```
Create copy of rectangle
*/
int lua_class_rectangle_Clone(lua_State *L){
  Rectangle * r1 = (Color *)luaL_checkudata(L, 1, "Rectangle");
  Rectangle * r2 = (Color *)luax_newobject(L, "Rectangle", sizeof(Rectangle));
  r2->x      = r1->x;
  r2->y      = r1->y;
  r2->width  = r1->width;
  r2->height = r1->height;
  return 1;
}

/*!MD
#### Rectangle:get
```lua
-- variants
number x, number y, number width, number height = Rectangle:get()
table Table = Rectangle:get('t') -- Table[x, y, width, height]
```
Return vector fields
*/
int lua_class_rectangle_Get(lua_State *L){
  Rectangle * r = (Color *)luaL_checkudata(L, 1, "Rectangle");
  if (luax_optstring(L, 2, "\0")[0] == 't'){
    lua_newtable(L);
    luax_tnnumber(L, 1, r->x);
    luax_tnnumber(L, 2, r->y);
    luax_tnnumber(L, 3, r->width);
    luax_tnnumber(L, 4, r->height);
    return 1;
  }
  lua_pushnumber(L, r->x);
  lua_pushnumber(L, r->y);
  lua_pushnumber(L, r->width);
  lua_pushnumber(L, r->height);
  return 1;
}

/*!MD
#### Rectangle:set
```lua
Rectangle:set(number x, number y, number width, number height)
```
Assing values to rectangle fields
*/
int lua_class_rectangle_Set(lua_State *L){
  Rectangle * r = (Color *)luaL_checkudata(L, 1, "Rectangle");

  r->x      = luax_optinteger(L, 2, r->x);
  r->y      = luax_optinteger(L, 3, r->y);
  r->width  = luax_optinteger(L, 4, r->width);
  r->height = luax_optinteger(L, 5, r->height);

  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Rectangle:move
```lua
Rectangle:move(number vx, number vy)
```
Move rectangle by vector
*/
int lua_class_rectangle_Move(lua_State *L){
  Rectangle * r = (Color *)luaL_checkudata(L, 1, "Rectangle");
	float vx = luax_optinteger(L, 2, 0.0f);
	float vy = luax_optinteger(L, 3, 0.0f);
	if (lua_type(L, 2) == LUA_TUSERDATA){
		Vector2 * v = (Vector2 *)luaL_checkudata(L, 2, "Vector2");
		vx = v->x; vy = v->y;
	}
	
  r->x += vx; r->y += vy;

  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Rectangle:getPosition
```lua
-- variants
number x, number y = Rectangle:getPosition()
Vector2 Position = Rectangle:getPosition('v')
table Position = Rectangle:getPosition('t')
```
Return rectangle position
*/
int lua_class_rectangle_GetPosition(lua_State *L){
  Rectangle * r = (Rectangle *)luaL_checkudata(L, 1, "Rectangle");
	if (lua_type(L, 2) == LUA_TSTRING){
		char c = luaL_checkstring(L, 1)[0];
		if (c == 'v'){ // return Vector2
			Vector2 * v = luax_newobject(L, "Vector2", sizeof(Vector2));
			v->x = r->x; v->y = r->y;
			return 1;
		}
		else if (c == 't'){ // return table
			lua_newtable(L);
			luax_tnnumber(L, 1, r->x);
			luax_tnnumber(L, 2, r->y);
			return 1;
		}
	}
	
	// return two numbers
	lua_pushnumber(L, r->x);
	lua_pushnumber(L, r->y);
  return 2;
}

/*!MD
#### Rectangle:setPosition
```lua
-- variants
Rectangle:setPosition(number x, number y)
Rectangle:setPosition(Vector2 Position)
Rectangle:setPosition(table Position)
```
Set rectangle position
*/
int lua_class_rectangle_SetPosition(lua_State *L){
  Rectangle * r = (Rectangle *)luaL_checkudata(L, 1, "Rectangle");
	float vx = luax_optinteger(L, 2, r->x);
	float vy = luax_optinteger(L, 3, r->y);
	if (luax_isclass(L, 2, "Vector2")){
		Vector2 * v = (Vector2 *)luaL_checkudata(L, 2, "Vector2");
		vx = v->x; vy = v->y;
	}
	if (lua_type(L, 2) == LUA_TTABLE){
		lua_rawgeti(L, 2, 1); lua_rawgeti(L, 2, 2);
		vx = luax_optnumber(L, -2, r->x); 
		vy = luax_optnumber(L, -1, r->y);
	}

  r->x = vx; r->y = vy;

  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Rectangle:getDimensions
```lua
-- variants
number x, number y = Rectangle:getDimensions()
Vector2 Position = Rectangle:getDimensions('v')
table Position = Rectangle:getDimensions('t')
```
Return rectangle width and height
*/
int lua_class_rectangle_GetDimensions(lua_State *L){
  Rectangle * r = (Rectangle *)luaL_checkudata(L, 1, "Rectangle");
	if (lua_type(L, 2) == LUA_TSTRING){
		char c = luaL_checkstring(L, 1)[0];
		if (c == 'v'){ // return Vector2
			Vector2 * v = luax_newobject(L, "Vector2", sizeof(Vector2));
			v->x = r->width; v->y = r->height;
			return 1;
		}
		else if (c == 't'){ // return table
			lua_newtable(L);
			luax_tnnumber(L, 1, r->width);
			luax_tnnumber(L, 2, r->height);
			return 1;
		}
	}
	
	// return two numbers
	lua_pushnumber(L, r->width);
	lua_pushnumber(L, r->height);
  return 2;
}

/*!MD
#### Rectangle:setDimensions
```lua
-- variants
Rectangle:setDimensions(number x, number y)
Rectangle:setDimensions(Vector2 Position)
Rectangle:setDimensions(table Position)
```
Set rectangle width and height
*/
int lua_class_rectangle_SetDimensions(lua_State *L){
  Rectangle * r = (Rectangle *)luaL_checkudata(L, 1, "Rectangle");
	float vx = luax_optinteger(L, 2, r->x);
	float vy = luax_optinteger(L, 3, r->y);
	if (luax_checkclass(L, 2, "Vector2")){
		Vector2 * v = (Vector2 *)luaL_checkudata(L, 2, "Vector2");
		vx = v->x; vy = v->y;
	}
	if (lua_type(L, 2) == LUA_TTABLE){
		lua_rawgeti(L, 2, 1); lua_rawgeti(L, 2, 2);
		vx = luax_optnumber(L, -2, r->x); 
		vy = luax_optnumber(L, -1, r->y);
	}

  r->width = vx; r->height = vy;

  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Rectangle:draw
```lua
Rectangle:draw(string Mode, Color Color)
```
Draw rectangle.
Available modes: `"fill"`, `"line"`
*/
int lua_class_rectangle_Draw(lua_State *L){
  Rectangle * r = (Rectangle *)luaL_checkudata(L, 1, "Rectangle");
  const char * mode = luaL_checkstring(L, 2);
  Color * c = (Color *)luaL_checkudata(L, 3, "Color");

       if (!strcmp(mode, "fill")) DrawRectangle(r->x, r->y, r->width, r->height, *c);
  else if (!strcmp(mode, "line")) DrawRectangleLines(r->x, r->y, r->width, r->height, *c);
  else return luaL_error(L, "bad argument #1: string \"fill\" or \"line\" expected");
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Rectangle:drawPro
```lua
-- variants
Rectangle:drawPro(Color Color[, Vector2 OriginOffset, number Angle])
Rectangle:drawPro(Color Color[, number OffsetX, number OffsetY, number Angle])
```
Draw filled rectangle with angle and offset
*/
int lua_class_rectangle_DrawPro(lua_State *L){
  Rectangle * r = (Rectangle *)luaL_checkudata(L, 1, "Rectangle");
  Color * c     = (Color *)luaL_checkudata(L, 2, "Color");
  float angle = luaL_checknumber(L, 3);
  Vector2 v = {0};

  if (lua_isnumber(L, 4)){
    v.x = luaL_checknumber(L, 4);
    v.y = luaL_checknumber(L, 5);
  }
  else if (luax_isclass(L, 4, "Vector2")){
    v = *(Vector2 *)luaL_checkudata(L, 4, "Vector2");
  }

  DrawRectanglePro(*r, v, angle, *c);
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Rectangle:drawRounded
```lua
Rectangle:drawRounded(string Mode, Color Color, number Roundness[, integer Segments, float LineThick])
```
Draw rectangle with rounded corners
Available modes: `"fill"`, `"line"`
*/
int lua_class_rectangle_DrawRounded(lua_State *L){
  Rectangle * r = (Rectangle *)luaL_checkudata(L, 1, "Rectangle");
  const char * mode = luaL_checkstring(L, 2);
  Color * c = (Color *)luaL_checkudata(L, 3, "Color");
  float roundness = luaL_checknumber(L, 4);
  int   segments  = luax_optnumber(L, 5, roundness / 2.0);
  int   lineThick = luax_optnumber(L, 6, 1);

       if (!strcmp(mode, "fill")) DrawRectangleRounded(*r, roundness, segments, *c);
  else if (!strcmp(mode, "line")) DrawRectangleRoundedLines(*r, roundness, segments, lineThick, *c);
  else return luaL_error(L, "bad argument #1: string \"fill\" or \"line\" expected");
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Rectangle:drawGradient
```lua
-- variants
Rectangle:drawGradient(string Mode, Color A, Color B)
Rectangle:drawGradient(Color A, Color B, Color C, Color D)
```
Draw rectangular color gradient
Available modes: `"h"`, `"v"` for horizontal and vertical gradients
*/
int lua_class_rectangle_DrawGradient(lua_State *L){
  Rectangle * r = (Rectangle *)luaL_checkudata(L, 1, "Rectangle");

  if (luax_type(L, 2, LUA_TSTRING)){
    Color * c1 = (Color *)luaL_checkudata(L, 3, "Color");
    Color * c2 = (Color *)luaL_checkudata(L, 4, "Color");
    if (luaL_checkstring(L, 2)[0] == 'v')  DrawRectangleGradientV(r->x, r->y, r->width, r->height, *c1, *c2);
    else                                   DrawRectangleGradientH(r->x, r->y, r->width, r->height, *c1, *c2);
    lua_settop(L, 1);
    return 1;
  }

  Color * c1 = (Color *)luaL_checkudata(L, 2, "Color");
  Color * c2 = (Color *)luaL_checkudata(L, 3, "Color");
  Color * c3 = (Color *)luaL_checkudata(L, 4, "Color");
  Color * c4 = (Color *)luaL_checkudata(L, 5, "Color");
  DrawRectangleGradientEx(*r, *c1, *c2, *c3, *c4);
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Rectangle:collideRect
```lua
boolean isCollide = Rectangle:collideRect(Rectangle Rect)
```
Check collision between two rectangles
*/
int lua_class_rectangle_CollideRect(lua_State *L){
  Rectangle * r1 = (Rectangle *)luaL_checkudata(L, 1, "Rectangle");
  Rectangle * r2 = (Rectangle *)luaL_checkudata(L, 2, "Rectangle");
  bool result = CheckCollisionRecs(*r1, *r2);
  lua_pushboolean(L, result);
  return 1;
}

/*!MD
#### Rectangle:collideCircle
```lua
-- variants
boolean isCollide = Rectangle:collideCircle(Vector2 Center, number Radius)
boolean isCollide = Rectangle:collideCircle(number CenterX, number CenterY, number Radius)
```
Check collision between circle and rectangle
*/
int lua_class_rectangle_CollideCircle(lua_State *L){
  Rectangle * r = (Rectangle *)luaL_checkudata(L, 1, "Rectangle");
  Vector2 cPos = {0};
  float   cRad = 0.0f;
  if (luax_isclass(L, 2, "Vector2")){
    cPos = *(Vector2 *)luaL_checkudata(L, 2, "Vector2");
    cRad = luaL_checknumber(L, 3);
  }
  else if (lua_isnumber(L, 2)){
    cPos.x = luaL_checknumber(L, 2);
    cPos.y = luaL_checknumber(L, 3);
    cRad   = luaL_checknumber(L, 4);
  }

  bool result = CheckCollisionCircleRec(cPos, cRad, *r);
  lua_pushboolean(L, result);
  return 1;
}

/*!MD
#### Rectangle:getCollisionRect
```lua
Rectangle CollRect = Rectangle:getCollisionRect(Rectangle Rect)
```
Get collision rectangle for two rectangles collision
*/
int lua_class_rectangle_GetCollisionRec(lua_State *L){
  Rectangle * r1 = (Rectangle *)luaL_checkudata(L, 1, "Rectangle");
  Rectangle * r2 = (Rectangle *)luaL_checkudata(L, 2, "Rectangle");
  Rectangle * r3 = (Rectangle *)luax_newobject(L, "Rectangle", sizeof(Rectangle));
  *r3 = GetCollisionRec(*r1, *r2);
  return 1;
}

/*!MD
#### Rectangle:collidePoint
```lua
-- variants
boolean isCollide = Rectangle:collidePoint(Vector2 Point)
boolean isCollide = Rectangle:collidePoint(number PointX, number PointY)
```
Check if point is inside rectangle
*/
int lua_class_rectangle_CollidePoint(lua_State *L){
  Rectangle * r = (Rectangle *)luaL_checkudata(L, 1, "Rectangle");
  Vector2 point = {0};
  if (luax_isclass(L, 2, "Vector2")){
    point = *(Vector2 *)luaL_checkudata(L, 2, "Vector2");
  }
  else if (lua_isnumber(L, 2)){
    point.x = luaL_checknumber(L, 2);
    point.y = luaL_checknumber(L, 3);
  }

  bool result = CheckCollisionPointRec(point, *r);
  lua_pushboolean(L, result);
  return 1;
}


// meta
int lua_class_rectangle__Index(lua_State *L){
  if (!luax_type(L, 2, LUA_TSTRING)) return 0;
  Rectangle * r    = (Rectangle *)luaL_checkudata(L, 1, "Rectangle");
  const char * key = luaL_checkstring(L, 2);

  lua_class_GetFieldIfCompared(L, r, key, "x",      x);
  lua_class_GetFieldIfCompared(L, r, key, "y",      y);
  lua_class_GetFieldIfCompared(L, r, key, "width",  width);
  lua_class_GetFieldIfCompared(L, r, key, "height", height);

  luax_getclasskey(L, 1, 2);
  return 1;
}

int lua_class_rectangle__Newindex(lua_State *L){
  if (!luax_type(L, 2, LUA_TSTRING)) return 0;
  Rectangle * r    = (Rectangle *)luaL_checkudata(L, 1, "Rectangle");
  const char * key = luaL_checkstring(L, 2);
  int value        = luaL_checknumber(L, 3);
  lua_class_SetFieldIfCompared(L, r, key, value, "x",      x);
  lua_class_SetFieldIfCompared(L, r, key, value, "y",      y);
  lua_class_SetFieldIfCompared(L, r, key, value, "width",  width);
  lua_class_SetFieldIfCompared(L, r, key, value, "height", height);
  return 0;
}

int lua_class_rectangle__ToString(lua_State *L){
  Rectangle * r = (Rectangle *)luaL_checkudata(L, 1, "Rectangle");
  lua_pushfstring(L, "Rectangle[%f, %f, %f, %f]: %0.8x", r->x, r->y, r->width, r->height, r);
  return 1;
}

luaL_Reg luaray_class_rectangle[] = {
  {"clone",            lua_class_rectangle_Clone},
  {"get",              lua_class_rectangle_Get},
  {"set",              lua_class_rectangle_Set},
  {"move",             lua_class_rectangle_Move},
  {"getPosition",      lua_class_rectangle_GetPosition},
  {"setPosition",      lua_class_rectangle_SetPosition},
  {"getDimensions",    lua_class_rectangle_GetDimensions},
  {"setDimensions",    lua_class_rectangle_SetDimensions},
  {"draw",             lua_class_rectangle_Draw},
  {"drawPro",          lua_class_rectangle_DrawPro},
  {"drawRounded",      lua_class_rectangle_DrawRounded},
  {"drawGradient",     lua_class_rectangle_DrawGradient},
  {"collideRect",      lua_class_rectangle_CollideRect},
  {"collideCircle",    lua_class_rectangle_CollideCircle},
  {"getCollisionRect", lua_class_rectangle_GetCollisionRec},
  {"collidePoint",     lua_class_rectangle_CollidePoint},
  // meta
  {"__index",          lua_class_rectangle__Index},
  {"__newindex",       lua_class_rectangle__Newindex},
  {"__tostring",       lua_class_rectangle__ToString},
  {NULL, NULL}
};

/*!MD
## Image
Structure:

| Field   | Type    |
| :------ | :------ |
| data    | string  |
| width   | integer |
| height  | integer |
| mipmaps | integer |
| format  | integer |

Structure is read-only.
Data stored in CPU memory (RAM), cannot be drawed directly.

| **Methods**                                | description
| :---------------------------------------   | :-----------
| [clone](#Imageclone)                       | Create copy of image
| [subImage](#ImagesubImage)                 | Create an image from another image piece
| [toPOT](#ImagetoPOT)                       | Convert image to POT (power-of-two)
| [getFormat](#ImagegetFormat)               | Get image data format
| [setFormat](#ImagesetFormat)               | Convert image data to desired format
| [alphaMask](#ImagealphaMask)               | Apply alpha mask to image
| [alphaClear](#ImagealphaClear)             | Clear alpha channel to desired color
| [alphaCrop](#ImagealphaCrop)               | Crop image depending on alpha value
| [alphaPremultiply](#ImagealphaPremultiply) | Premultiply alpha channel
| [crop](#Imagecrop)                         | Crop an image to a defined rectangle
| [resize](#Imageresize)                     | Resize image (Bicubic scaling algorithm)
| [resizeNN](#ImageresizeNN)                 | Resize image (Nearest-Neighbor scaling algorithm)
| [resizeCanvas](#ImageresizeCanvas)         | Resize canvas and fill with color
| [genMipmaps](#ImagegenMipmaps)             | Generate all mipmap levels for a provided image
| [dither](#Imagedither)                     | Dither image data to 16bpp or lower (Floyd-Steinberg dithering)
| [extractPalette](#ImageextractPalette)     | Extract color palette from image to maximum size
| [drawImage](#ImagedrawImage)               | Draw a source image within a destination image (tint applied to source)
| [drawRectangle](#ImagedrawRectangle)       | Draw rectangle within an image
| [drawText](#ImagedrawText)                 | Draw text within an image
| [flip](#Imageflip)                         | Flip image
| [rotate](#Imagerotate)                     | Rotate image
| [tint](#Imagetint)                         | Modify image color: tint
| [invert](#Imageinvert)                     | Modify image color: invert
| [grayscale](#Imagegrayscale)               | Modify image color: grayscale
| [contrast](#Imagecontrast)                 | Modify image color: contrast (-100 to 100)
| [brightness](#Imagebrightness)             | Modify image color: brightness (-255 to 255)
| [replaceColor](#ImagereplaceColor)         | Modify image color: replace color

### Initialization
```lua
-- variants
Image Img = rl.Image(string Filename)
Image Img = rl.Image(integer Width, integer Height, eTexture Format[, Color FillColor])
```
Creates new Image object.
See [eTexture](eTexture).
*/
int lua_class_image_new(lua_State *L){
  if (luax_type(L, 1, LUA_TSTRING)){
    const char * fname = luaL_checkstring(L, 1);
    if (!FileExists(fname))
      return luaL_error(L, "Can't load image \"%s\", file is not exists", fname);
    Image * img = (Image *)luax_newobject(L, "Image", sizeof(Image));
    *img = LoadImage(fname);
    return 1;
  }
  int width  = luaL_checkinteger(L, 1);
  int height = luaL_checkinteger(L, 2);
  int format = ray_enums_getFromStack(L, 3, ray_lua_enum_texturefmt);
  Color color = luax_isclass(L, 4, "Color") ? *(Color *)luaL_checkudata(L, 4, "Color") : BLANK;
  Image * img = (Image *)luax_newobject(L, "Image", sizeof(Image));
  *img = LoadImagePro(NULL, 0, 0, format);
  ImageResizeCanvas(img, width, height, 0, 0, color);
  return 1;
}

/*!MD
#### Image:clone
```lua
Image Img = Image:clone()
```
Create copy of image
*/
int lua_class_image_Clone(lua_State *L){
  Image * img  = (Image *)luaL_checkudata(L, 1, "Image");
  Image * copy = (Image *)luax_newobject(L, "Image", sizeof(Image));
  *copy = ImageCopy(*img);
  return 1;
}

/*!MD
#### Image:subImage
```lua
-- variants
Image subImage = Image:subImage(integer X, integer Y, integer Width, integer Height)
Image subImage = Image:subImage(Rectangle Rect)
```
Create an image from another image piece
See [Rectangle](Rectangle).
*/
int lua_class_image_SubImage(lua_State *L){
  Image *   src  = (Image *)luaL_checkudata(L, 1, "Image");
  Rectangle rect = {0};

  if (luax_type(L, 2, LUA_TNUMBER)){
    rect.x      = luaL_checknumber(L, 2);
    rect.y      = luaL_checknumber(L, 3);
    rect.width  = luaL_checknumber(L, 4);
    rect.height = luaL_checknumber(L, 5);
  }
  else rect = *(Rectangle *)luaL_checkudata(L, 2, "Rectangle");
  
  Image * dst = (Image *)luax_newobject(L, "Image", sizeof(Image));
  *dst = ImageFromImage(*src, rect);
  return 1;
}

/*!MD
#### Image:toPOT
```lua
Image subImgage = Image:toPOT(Color Color)
```
Convert image to POT (power-of-two).
See [Color](Color).
*/
int lua_class_image_toPOT(lua_State *L){
  Image * img   = (Image *)luaL_checkudata(L, 1, "Image");
  Color * color = luax_checkclass(L, 2, "Color");
  ImageToPOT(img, *color);
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Image:getFormat
```lua
eTexture ImageFormat = Image:getFormat()
```
Get image data format
See [eTexture](eTexture)
*/
int lua_class_image_GetFormat(lua_State *L){
  Image * img  = (Image *)luaL_checkudata(L, 1, "Image");
  const char * fmt = ray_enums_string(L, img->format, ray_lua_enum_texturefmt);
  lua_pushstring(L, fmt);
  return 1;
}

/*!MD
#### Image:setFormat
```lua
Image:setFormat(eTexture ImageFormat)
```
Convert image data to desired format
See [eTexture](eTexture)
*/
int lua_class_image_SetFormat(lua_State *L){
  Image * img  = (Image *)luaL_checkudata(L, 1, "Image");
  int eFmt = ray_enums_getFromStack(L, 2, ray_lua_enum_texturefmt);
  ImageFormat(img, eFmt);
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Image:alphaMask
```lua
Image Image = Image:alphaMask(Image Mask)
```
Apply alpha mask to image, returns modified image for chaining.
*/
int lua_class_image_AlphaMask(lua_State *L){
  Image * img  = (Image *)luaL_checkudata(L, 1, "Image");
  Image * mask = (Image *)luaL_checkudata(L, 2, "Image");
  ImageAlphaMask(img, *mask);
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Image:alphaClear
```lua
Image Image = Image:alphaClear(number Treshold, Color Color)
```
Clear alpha channel to desired color, returns modified image for chaining.
See [Color](Color).
*/
int lua_class_image_AlphaClear(lua_State *L){
  Image * img      = (Image *)luaL_checkudata(L, 1, "Image");
  float   treshold = luaL_checknumber(L, 2);
  Color * color    = luax_checkclass(L, 3, "Color");
  ImageAlphaClear(img, *color, treshold);
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Image:alphaCrop
```lua
Image Image = Image:alphaCrop(number Treshold)
```
Crop image depending on alpha value, returns modified image for chaining.
*/
int lua_class_image_AlphaCrop(lua_State *L){
  Image * img      = (Image *)luaL_checkudata(L, 1, "Image");
  float   treshold = luaL_checknumber(L, 2);
  ImageAlphaCrop(img, treshold);
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Image:alphaPremultiply
```lua
Image Image = Image:alphaPremultiply(number Treshold)
```
Premultiply alpha channel, returns modified image for chaining.
*/
int lua_class_image_AlphaPremultiply(lua_State *L){
  Image * img = (Image *)luaL_checkudata(L, 1, "Image");
  ImageAlphaPremultiply(img);
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Image:crop
```lua
-- variants
Image croppedImage = Image:crop(integer X, integer Y, integer Width, integer Height)
Image croppedImage = Image:crop(Rectangle Rect)
```
Crop an image to a defined rectangle.
See [Rectangle](Rectangle).
*/
int lua_class_image_Crop(lua_State *L){
  Image *   img  = (Image *)luaL_checkudata(L, 1, "Image");
  Rectangle rect = {0};
  if (luax_type(L, 2, LUA_TNUMBER)){
    rect.x      = luaL_checkinteger(L, 2);
    rect.y      = luaL_checkinteger(L, 3);
    rect.width  = luaL_checkinteger(L, 4);
    rect.height = luaL_checkinteger(L, 5);
  }
  else rect = *(Rectangle *)luax_checkclass(L, 2, "Rectangle");
  ImageCrop(img, rect);
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Image:resize
```lua
Image Image = Image:resize(integer Width, integer Height)
```
Resize image (Bicubic scaling algorithm), returns modified image for chaining.
*/
int lua_class_image_Resize(lua_State *L){
  Image * img = (Image *)luaL_checkudata(L, 1, "Image");
  int width   = luaL_checkinteger(L, 2);
  int height  = luaL_checkinteger(L, 3);
  ImageResize(img, width, height);
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Image:resizeNN
```lua
Image Image = Image:resizeNN(integer Width, integer Height)
```
Resize image (Bicubic scaling algorithm), returns modified image for chaining.
*/
int lua_class_image_ResizeNN(lua_State *L){
  Image * img = (Image *)luaL_checkudata(L, 1, "Image");
  int width   = luaL_checkinteger(L, 2);
  int height  = luaL_checkinteger(L, 3);
  ImageResizeNN(img, width, height);
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Image:resizeCanvas
```lua
Image Image = Image:resizeCanvas(integer Width, integer Height[, integer OffsetX, integer OffsetY, Color FillColor])
```
Resize canvas and fill with color, returns modified image for chaining.
See [Color](Color).
*/
int lua_class_image_ResizeCanvas(lua_State *L){
  Image * img  = (Image *)luaL_checkudata(L, 1, "Image");
  int width    = luaL_checkinteger(L, 2);
  int height   = luaL_checkinteger(L, 3);
  int offsetX  = luax_optinteger(L, 4, 0);
  int offsetY  = luax_optinteger(L, 5, 0);
  Color color  = BLANK;
  if (luax_isclass(L, 6, "Color")) color = *(Color *)luax_checkclass(L, 6, "Color");
  ImageResizeCanvas(img, width, height, offsetX, offsetY, color);
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Image:genMipmaps
```lua
Image Image = Image:genMipmaps()
```
Generate all mipmap levels for a provided image, returns modified image for chaining.
*/
int lua_class_image_Mipmaps(lua_State *L){
  Image * img  = (Image *)luaL_checkudata(L, 1, "Image");
  ImageMipmaps(img);
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Image:dither
```lua
Image Image = Image:dither(integer rBpp, integer gBpp, integer bBpp, integer aBpp)
```
Dither image data to 16bpp or lower (Floyd-Steinberg dithering), returns modified image for chaining.
*/
int lua_class_image_Dither(lua_State *L){
  Image * img  = (Image *)luaL_checkudata(L, 1, "Image");
  int rBpp = luaL_checkinteger(L, 2);
  int gBpp = luaL_checkinteger(L, 3);
  int bBpp = luaL_checkinteger(L, 4);
  int aBpp = luaL_checkinteger(L, 5);
  ImageDither(img, rBpp, gBpp, bBpp, aBpp);
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Image:extractPalette
```lua
table Colors = Image:extractPalette([integer MaxColorCount = 256])
```
Extract color palette from image to maximum size.
See [Color](Color).
*/
int lua_class_image_ExtractPalette(lua_State *L){
  Image * img   = (Image *)luaL_checkudata(L, 1, "Image");
  int     max   = luax_optnumber(L, 2, 256);
  int     count = 0;
  Color*  palette = ImageExtractPalette(*img, max, &count);
  lua_newtable(L);
  for (int i = 1; i <= count; i++){
    lua_pushnumber(L, i);
    Color * c = luax_newobject(L, "Color", sizeof(Color));
    *c = palette[i];
    lua_rawset(L, -3);
  }
  RL_FREE(palette);
  return 1;
}

/*!MD
#### Image:drawImage
```lua
Image Image = Image:drawImage(Image Src, Rectangle SrcRect, Rectangle DstRect[, Color Tint])
```
Draw a source image within a destination image (tint applied to source), returns modified image for chaining.
See [Rectangle](Rectangle), [Color](Color).
*/
int lua_class_image_DrawImage(lua_State *L){
  Image     * dst     = (Image *)luaL_checkudata(L, 1, "Image");
  Image     * src     = (Image *)luaL_checkudata(L, 2, "Image");
  Rectangle * srcRect = (Rectangle *)luaL_checkudata(L, 3, "Rectangle");
  Rectangle * dstRect = (Rectangle *)luaL_checkudata(L, 4, "Rectangle");
  Color     * tInt    = luax_isclass(L, 5, "Color") ? (Color *)luaL_checkudata(L, 5, "Color") : &WHITE;
  ImageDraw(dst, *src, *srcRect, *dstRect, *tInt);
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Image:drawRectangle
```lua
Image Image = Image:drawRectangle(string Mode, Rectangle Rect[, Color Color[, Integer LineThick])
```
Draw a source image within a destination image (tint applied to source), returns modified image for chaining.
See [Rectangle](Rectangle), [Color](Color).
Available modes: `"fill"`, `"line"`.
*/
int lua_class_image_DrawRectangle(lua_State *L){
  Image      * dst   = (Image *)luaL_checkudata(L, 1, "Image");
  const char * mode  = luaL_checkstring(L, 2);
  Rectangle  * rect  = (Rectangle *)luaL_checkudata(L, 3, "Rectangle");
  Color      * col   = luax_isclass(L, 4, "Color") ? (Color *)luaL_checkudata(L, 4, "Color") : &WHITE;
  int          thick = luax_optinteger(L, 5, 1);

       if (!strcmp(mode, "fill")) ImageDrawRectangle(dst, *rect, *col);
  else if (!strcmp(mode, "line")) ImageDrawRectangleLines(dst, *rect, thick, *col);
  else return luaL_error(L, "bad argument #1: string \"fill\" or \"line\" expected");
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Image:drawText
```lua
-- variants
Image Image = Image:drawText(integer X, integer Y, string Text, Color Color, number FontSize) -- defaut font
Image Image = Image:drawText(integer X, integer Y, string Text, Font Font, number FontSize, number Spacing, Color Color)

Image Image = Image:drawText(Vector2 Position, string Text, Color Color, number FontSize) -- defaut font
Image Image = Image:drawText(Vector2 Position, string Text, Font Font, number FontSize, number Spacing, Color Color)
```
Draw text within an image, returns modified image for chaining.
See [Vector2](Vector2), [Color](Color), [Font](Font).
*/
int lua_class_image_DrawText(lua_State *L){
  Image      * dst      = (Image *)luaL_checkudata(L, 1, "Image");
  Vector2      position = {0};
  const char * text     = "\0";
  int          fontSize = 12;
  Color        color    = BLACK;

  if (luax_type(L, 2, LUA_TNUMBER)){
    position.x = luaL_checknumber(L, 2);
    position.y = luaL_checknumber(L, 3);
    text       = luaL_checkstring(L, 4);
    // skip 5 (font)
    fontSize = luaL_checknumber(L, 6);
    if (luax_isclass(L, 5, "Font")){
      Font * font   = (Font *)luaL_checkudata(L, 5, "Font");
      float spacing = luaL_checknumber(L, 7);
      color         = luax_isclass(L, 8, "Color") ? *(Color *)luaL_checkudata(L, 8, "Color") : color;
      ImageDrawTextEx(dst, position, *font, text, fontSize, spacing, color);
    }
    else {
      color = luax_isclass(L, 5, "Color") ? *(Color *)luaL_checkudata(L, 5, "Color") : color;
      ImageDrawText(dst, position, text, fontSize, color);
    }
    lua_settop(L, 1);
    return 1;
  }

  position = *(Vector2 *)luaL_checkudata(L, 2, "Vector2");
  text     = luaL_checkstring(L, 3);
  // skip 4 (font)
  fontSize = luaL_checknumber(L, 5);

  if (luax_isclass(L, 4, "Font")){
    Font * font   = (Color *)luaL_checkudata(L, 4, "Font");
    float spacing = luaL_checknumber(L, 6);
    color    = luax_isclass(L, 7, "Color") ? *(Color *)luaL_checkudata(L, 7, "Color") : color;
    ImageDrawTextEx(dst, position, *font, text, fontSize, spacing, color);
  }
  else {
    color    = luax_isclass(L, 4, "Color") ? *(Color *)luaL_checkudata(L, 4, "Color") : color;
    ImageDrawText(dst, position, text, fontSize, color);
  }
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Image:flip
```lua
Image Image = Image:flip(string Mode)
```
Flip image, returns modified image for chaining.
Available modes: `"horizontal"`, `"vertical"`.
*/
int lua_class_image_Flip(lua_State *L){
  Image      * dst   = (Image *)luaL_checkudata(L, 1, "Image");
  const char * mode  = luaL_checkstring(L, 2);
       if (!strcmp(mode, "horizontal")) ImageFlipHorizontal(dst);
  else if (!strcmp(mode, "vertical"))   ImageFlipVertical(dst);
  else return luaL_error(L, "bad argument #1: string \"horizontal\" or \"vertical\" expected");
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Image:rotate
```lua
Image Image = Image:rotate(string Mode)
```
Rotate image, returns modified image for chaining.
Available modes: `"right"`, `"left"` (clockwise 90deg and counter-clockwise 90deg).
*/
int lua_class_image_Rotate(lua_State *L){
  Image      * dst   = (Image *)luaL_checkudata(L, 1, "Image");
  const char * mode  = luaL_checkstring(L, 2);
       if (!strcmp(mode, "left"))  ImageRotateCCW(dst);
  else if (!strcmp(mode, "right")) ImageRotateCW(dst);
  else return luaL_error(L, "bad argument #1: string \"left\" or \"right\" expected");
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Image:tint
```lua
Image Image = Image:tint(Color Color)
```
Modify image color: tint, returns modified image for chaining.
See [Color](Color).
*/
int lua_class_image_Tint(lua_State *L){
  Image * dst = (Image *)luaL_checkudata(L, 1, "Image");
  Color * clr = (Color *)luaL_checkudata(L, 2, "Color");
  ImageColorTint(dst, *clr);
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Image:invert
```lua
Image Image = Image:invert()
```
Modify image color: invert, returns modified image for chaining.
*/
int lua_class_image_Invert(lua_State *L){
  Image * dst = (Image *)luaL_checkudata(L, 1, "Image");
  ImageColorInvert(dst);
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Image:grayscale
```lua
Image Image = Image:grayscale()
```
Modify image color: grayscale, returns modified image for chaining.
*/
int lua_class_image_Grayscale(lua_State *L){
  Image * dst = (Image *)luaL_checkudata(L, 1, "Image");
  ImageColorGrayscale(dst);
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Image:contrast
```lua
Image Image = Image:contrast(number Contrast)
```
Modify image color: contrast (-100 to 100), returns modified image for chaining.
*/
int lua_class_image_Contrast(lua_State *L){
  Image * dst      = (Image *)luaL_checkudata(L, 1, "Image");
  float   contrast = luaL_checknumber(L, 2);
  ImageColorContrast(dst, contrast);
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Image:brightness
```lua
Image Image = Image:brightness(integer Brightness)
```
Modify image color: brightness (-255 to 255), returns modified image for chaining.
*/
int lua_class_image_Brightness(lua_State *L){
  Image * dst        = (Image *)luaL_checkudata(L, 1, "Image");
  int     brightness = luaL_checknumber(L, 2);
  ImageColorBrightness(dst, brightness);
  lua_settop(L, 1);
  return 1;
}

/*!MD
#### Image:replaceColor
```lua
Image Image = Image:replaceColor(Color Src, Color Dst)
```
Modify image color: replace color, returns modified image for chaining.
See [Color](Color).
*/
int lua_class_image_ColorReplace(lua_State *L){
  Image * dst     = (Image *)luaL_checkudata(L, 1, "Image");
  Color * clrFrom = (Color *)luaL_checkudata(L, 2, "Color");
  Color * clrTo   = (Color *)luaL_checkudata(L, 3, "Color");
  ImageColorReplace(dst, *clrFrom, *clrTo);
  lua_settop(L, 1);
  return 1;
}


// meta
int lua_class_image__Index(lua_State *L){
  if (!luax_type(L, 2, LUA_TSTRING)) return 0;
  Image * img    = (Image *)luaL_checkudata(L, 1, "Image");
  const char * key = luaL_checkstring(L, 2);

  lua_class_GetFieldIfCompared(L, img, key, "width",   width);
  lua_class_GetFieldIfCompared(L, img, key, "height",  height);
  lua_class_GetFieldIfCompared(L, img, key, "mipmaps", mipmaps);
  lua_class_GetFieldIfCompared(L, img, key, "format",  format);
  if (!strcmp(key, "format")) {
    const char * fmt = ray_enums_string(L, img->format, ray_lua_enum_texturefmt);
    lua_pushstring(L, fmt);
    return 1;
  }
  if (!strcmp(key, "data")) { lua_pushstring(L, img->data); return 1; }

  luax_getclasskey(L, 1, 2);
  return 1;
}

int lua_class_image__Newindex(lua_State *L){
  return 0;
}

int lua_class_image__GC(lua_State *L){
  Image * img = (Image *)luaL_checkudata(L, 1, "Image");
  UnloadImage(*img);
  return 0;
}

int lua_class_image__ToString(lua_State *L){
  Image * img = (Image *)luaL_checkudata(L, 1, "Image");
  lua_pushfstring(L, "Image[%f, %f]: %0.8x", img->width, img->height, img);
  return 1;
}

luaL_Reg luaray_class_image[] = {
  {"clone",            lua_class_image_Clone},
  {"subImage",         lua_class_image_SubImage},
  {"toPOT",            lua_class_image_toPOT},
  {"getFormat",        lua_class_image_GetFormat},
  {"setFormat",        lua_class_image_SetFormat},
  {"alphaMask",        lua_class_image_AlphaMask},
  {"alphaClear",       lua_class_image_AlphaClear},
  {"alphaCrop",        lua_class_image_AlphaCrop},
  {"alphaPremultiply", lua_class_image_AlphaPremultiply},
  {"crop",             lua_class_image_Crop},
  {"resize",           lua_class_image_Resize},
  {"resizeNN",         lua_class_image_ResizeNN},
  {"resizeCanvas",     lua_class_image_ResizeCanvas},
  {"dither",           lua_class_image_Dither},
  {"genMipmaps",       lua_class_image_Mipmaps},
  {"extractPalette",   lua_class_image_ExtractPalette},
  {"drawImage",        lua_class_image_DrawImage},
  {"drawRectangle",    lua_class_image_DrawRectangle},
  {"drawText",         lua_class_image_DrawText},
  {"flip",             lua_class_image_Flip},
  {"rotate",           lua_class_image_Rotate},
  {"tint",             lua_class_image_Tint},
  {"invert",           lua_class_image_Invert},
  {"grayscale",        lua_class_image_Grayscale},
  {"contrast",         lua_class_image_Contrast},
  {"brightness",       lua_class_image_Brightness},
  {"replaceColor",     lua_class_image_ColorReplace},

  // meta
  {"__index",          lua_class_image__Index},
  {"__newindex",       lua_class_image__Newindex},
  {"__gc",             lua_class_image__GC},
  {"__tostring",       lua_class_image__ToString},
  {NULL, NULL}
};


/*!MD
## Texture
### Initialization
```lua
--
```
*/

/*!MD
## RenderTexture
### Initialization
```lua
--
```
*/

/*!MD
## NPatchInfo
### Initialization
```lua
--
```
*/


/*!MD
## CharInfo
### Initialization
```lua
--
```
*/

/*!MD
## Font
### Initialization
```lua
--
```
*/


/*!MD
## Camera3D
### Initialization
```lua
--
```
*/

/*!MD
## Camera2D
### Initialization
```lua
--
```
*/


/*!MD
## Mesh
### Initialization
```lua
--
```
*/

/*!MD
## Shader
### Initialization
```lua
--
```
*/

/*!MD
## MaterialMap
### Initialization
```lua
--
```
*/

/*!MD
## Material
### Initialization
```lua
--
```
*/


/*!MD
## Model
### Initialization
```lua
--
```
*/

/*!MD
## Transform
### Initialization
```lua
--
```
*/


/*!MD
## BoneInfo
### Initialization
```lua
--
```
*/

/*!MD
## ModelAnimation
### Initialization
```lua
--
```
*/


/*!MD
## Ray
### Initialization
```lua
--
```
*/


/*!MD
## RayHitInfo
### Initialization
```lua
--
```
*/


/*!MD
## BoundingBox
### Initialization
```lua
--
```
*/

/*!MD
## Wave
### Initialization
```lua
--
```
*/

/*!MD
## Sound
### Initialization
```lua
--
```
*/

/*!MD
## Music
### Initialization
```lua
--
```
*/


/*!MD
## AudioStream
### Initialization
```lua
--
```
*/


/*!MD
## VrDeviceInfo
### Initialization
```lua
--
```
*/


// register table should be on top of stack
void lua_class_register(lua_State * L){
  luax_newclass(L,   "Vector2",   luaray_class_vector2);
  luax_tsfunction(L, "Vector2",   lua_class_vector2_new);

  luax_newclass(L,   "Vector3",   luaray_class_vector3);
  luax_tsfunction(L, "Vector3",   lua_class_vector3_new);

  luax_newclass(L,   "Matrix",    luaray_class_matrix);
  luax_tsfunction(L, "Matrix",    lua_class_matrix_new);

  luax_newclass(L,   "Vector4",   luaray_class_vector4);
  luax_tsfunction(L, "Vector4",   lua_class_vector4_new);

  luax_newclass(L,   "Color",     luaray_class_color);
  luax_tsfunction(L, "Color",     lua_class_color_new);

  luax_newclass(L,   "Rectangle", luaray_class_rectangle);
  luax_tsfunction(L, "Rectangle", lua_class_rectangle_new);

  luax_newclass(L,   "Image",     luaray_class_image);
  luax_tsfunction(L, "Image",     lua_class_image_new);
}
