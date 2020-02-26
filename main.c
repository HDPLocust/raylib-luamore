#include "main.h"
#include "classes.h"


/*!MD
# Hello. 
This is Lua binding for raylib.
### All stuff provided by Snooze.

(there should be a table of contents)
* Core
  * Core functions
* Text
  * Text functions

etc
*/


// Modules
/*!MD
## Core
### Core functions

#### Initialization
```lua
local ray = require("raylib_luamore")
```
*/

/*!MD
### Window-related functions:
#### InitWindow
```lua
ray.core.InitWindow(integer Width, integer Height, string Title)
```
Initialize window and OpenGL context
Should be called before any widnow stuff is used.
*/

int lua_core_InitWindow(lua_State *L){
  int w = luaL_checknumber(L, 1);
  int h = luaL_checknumber(L, 2);
  const char * title = luaL_checkstring(L, 3);
  InitWindow(w, h, title);
  return 0;
}

/*!MD
#### WindowShouldClose
```lua
boolean Status = ray.core.WindowShouldClose()
```
Check if KEY_ESCAPE pressed or Close icon pressed
*/

int lua_core_WindowShouldClose(lua_State *L){
  lua_pushboolean(L, WindowShouldClose());
  return 1;
}

/*!MD
#### CloseWindow
```lua
ray.core.CloseWindow()
```
Close window and unload OpenGL context
*/

int lua_core_CloseWindow(lua_State *L){
  CloseWindow();
  return 0;
}

/*!MD
#### IsWindowReady
```lua
boolean Status = ray.core.IsWindowReady()
```
Check if window has been initialized successfully
*/

int lua_core_IsWindowReady(lua_State *L){
  lua_pushboolean(L, IsWindowReady());
  return 1;
}

/*!MD
#### IsWindowMinimized
```lua
boolean Status = ray.core.IsWindowMinimized()
```
Check if window has been minimized (or lost focus)
*/

int lua_core_IsWindowMinimized(lua_State *L){
  lua_pushboolean(L, IsWindowMinimized());
  return 1;
}

/*!MD
#### IsWindowResized
```lua
boolean Status = ray.core.IsWindowResized()
```
Check if window has been resized
*/

int lua_core_IsWindowResized(lua_State *L){
  lua_pushboolean(L, IsWindowResized());
  return 1;
}

/*!MD
#### IsWindowHidden
```lua
boolean Status = ray.core.IsWindowHidden()
```
Check if window is currently hidden
*/

int lua_core_IsWindowHidden(lua_State *L){
  lua_pushboolean(L, IsWindowHidden());
  return 1;
}

/*!MD
#### ToggleFullscreen
```lua
ray.core.ToggleFullscreen()
```
Toggle fullscreen mode (only PLATFORM_DESKTOP)
*/

int lua_core_ToggleFullscreen(lua_State *L){
  ToggleFullscreen();
  return 0;
}

/*!MD
#### UnhideWindow
```lua
ray.core.UnhideWindow()
```
Show the window
*/

int lua_core_UnhideWindow(lua_State *L){
  UnhideWindow();
  return 0;
}

/*!MD
#### HideWindow
```lua
ray.core.HideWindow()
```
Hide the window
*/

int lua_core_HideWindow(lua_State *L){
  HideWindow();
  return 0;
}

/*!MD
#### SetWindowIcon
```lua
ray.core.SetWindowIcon(ray_image Icon)
```
Set icon for window (only PLATFORM_DESKTOP)
For additional info [ray_image]
*/

int lua_core_SetWindowIcon(lua_State *L){
  Image* i = (Image*)luaL_checkudata(L, 1, "ray_image");
  SetWindowIcon(*i);
  return 0;
}

/*!MD
#### SetWindowTitle
```lua
ray.core.SetWindowTitle(string Title)
```
Set title for window (only PLATFORM_DESKTOP)
*/

int lua_core_SetWindowTitle(lua_State *L){
  SetWindowTitle(luaL_checkstring(L, 1));
  return 0;
}

/*!MD
#### SetWindowPosition
```lua
ray.core.SetWindowPosition(string Title)
```
Set window position on screen (only PLATFORM_DESKTOP)
*/

int lua_core_SetWindowPosition(lua_State *L){
  SetWindowPosition(luaL_checkinteger(L, 1), luaL_checkinteger(L, 2));
  return 0;
}

/*!MD
#### SetWindowMonitor
```lua
ray.core.SetWindowMonitor(integer Monitor)
```
Set monitor for the current window (fullscreen mode)
*/

int lua_core_SetWindowMonitor(lua_State *L){
  SetWindowMonitor(luaL_checkinteger(L, 1) - 1);
  return 0;
}

/*!MD
#### SetWindowMinSize
```lua
ray.core.SetWindowMinSize(integer Width, integer Height)
```
Set window minimum dimensions (for FLAG_WINDOW_RESIZABLE)
*/

int lua_core_SetWindowMinSize(lua_State *L){
  SetWindowMinSize(luaL_checkinteger(L, 1), luaL_checkinteger(L, 2));
  return 0;
}

/*!MD
#### SetWindowSize
```lua
ray.core.SetWindowSize(integer Width, integer Height)
```
Set window dimensions
*/

int lua_core_SetWindowSize(lua_State *L){
  SetWindowSize(luaL_checkinteger(L, 1), luaL_checkinteger(L, 2));
  return 0;
}

/*!MD
#### GetWindowHandle
```lua
userdata Handle = ray.core.GetWindowHandle()
```
Get native window handle
Using for FFI or something
*/

int lua_core_GetWindowHandle(lua_State *L){
  void* h = GetWindowHandle();
  lua_pushlightuserdata(L, h);
  return 1;
}

/*!MD
#### GetScreenWidth
```lua
integer Width = ray.core.GetScreenWidth()
```
Get current screen width
*/

int lua_core_GetScreenWidth(lua_State *L){
  lua_pushnumber(L, GetScreenWidth());
  return 1;
}

/*!MD
#### GetScreenHeight
```lua
integer Height = ray.core.GetScreenHeight()
```
Get current screen height
*/

int lua_core_GetScreenHeight(lua_State *L){
  lua_pushnumber(L, GetScreenHeight());
  return 1;
}

/*!MD
#### GetScreenDimensions
```lua
integer Width, integer Height = ray.core.GetScreenDimensions()
```
Get current screen dimensions
*/

int lua_core_GetScreenDimensions(lua_State *L){
  lua_pushnumber(L, GetScreenWidth());
  lua_pushnumber(L, GetScreenHeight());
  return 2;
}

/*!MD
#### GetMonitorCount
```lua
integer Count = ray.core.GetMonitorCount()
```
Get number of connected monitors
*/

int lua_core_GetMonitorCount(lua_State *L){
  lua_pushnumber(L, GetMonitorCount());
  return 1;
}

/*!MD
#### GetMonitorWidth
```lua
integer Width = ray.core.GetMonitorWidth(integer Monitor)
```
Get selected monitor width
*/

int lua_core_GetMonitorWidth(lua_State *L){
  lua_pushnumber(L, GetMonitorWidth(luaL_checkinteger(L, 1) + 1));
  return 1;
}

/*!MD
#### GetMonitorHeight
```lua
integer Height = ray.core.GetMonitorHeight(integer Monitor)
```
Get selected monitor height
*/

int lua_core_GetMonitorHeight(lua_State *L){
  lua_pushnumber(L, GetMonitorHeight(luaL_checkinteger(L, 1) + 1));
  return 1;
}

/*!MD
#### GetMonitorDimensions
```lua
integer Width, integer Height = ray.core.GetMonitorDimensions(integer Monitor)
```
Get selected monitor dimensions
*/

int lua_core_GetMonitorDimensions(lua_State *L){
  lua_pushnumber(L, GetMonitorWidth(luaL_checkinteger(L, 1)  + 1));
  lua_pushnumber(L, GetMonitorHeight(luaL_checkinteger(L, 1) + 1));
  return 2;
}

/*!MD
#### GetMonitorPhysicalWidth
```lua
integer Width = ray.core.GetMonitorPhysicalWidth(integer Monitor)
```
Get selected monitor physical width in millimetres
*/

int lua_core_GetMonitorPhysicalWidth(lua_State *L){
  lua_pushnumber(L, GetMonitorPhysicalWidth(luaL_checkinteger(L, 1) + 1));
  return 1;
}

/*!MD
#### GetMonitorPhysicalHeight
```lua
integer Height = ray.core.GetMonitorPhysicalHeight(integer Monitor)
```
Get selected monitor physical height in millimetres
*/

int lua_core_GetMonitorPhysicalHeight(lua_State *L){
  lua_pushnumber(L, GetMonitorPhysicalHeight(luaL_checkinteger(L, 1) + 1));
  return 1;
}

/*!MD
#### GetMonitorPhysicalDimensions
```lua
integer Width, integer Height = ray.core.GetMonitorPhysicalDimensions(integer Monitor)
```
Get selected monitor physical dimensions in millimetres
*/

int lua_core_GetMonitorPhysicalDimensions(lua_State *L){
  lua_pushnumber(L, GetMonitorPhysicalWidth(luaL_checkinteger(L, 1)  + 1));
  lua_pushnumber(L, GetMonitorPhysicalHeight(luaL_checkinteger(L, 1) + 1));
  return 2;
}

/*!MD
#### GetMonitors
```lua
table Monitors = ray.core.GetMonitors()
```
Get all monitors and it's stats using this layout:
```lua
Monitors = {
    { -- first monitor info
      string  name,    -- human-readable monitor name
      integer width,   -- monitor width in pixels
      integer height   -- monitor height in pixels
      integer pwidth,  -- monitor physical width in millimetres
      integer pheight, -- monitor physical height in millimetres
    },
    { -- second monitor
    }
  }
 ```
*/

int lua_core_GetMonitors(lua_State *L){
  lua_newtable(L);
  for (int i = 0; i < GetMonitorCount(); i++) {
    lua_pushinteger(L, i + 1);
    lua_newtable(L);
      luax_tsnumber(L, "width",   GetMonitorWidth(i));
      luax_tsnumber(L, "height",  GetMonitorHeight(i));
      luax_tsnumber(L, "pwidth",  GetMonitorPhysicalWidth(i));
      luax_tsnumber(L, "pheight", GetMonitorPhysicalHeight(i));
      luax_tsstring(L, "name",    GetMonitorName(i));
    lua_rawset(L, -3);
  }
  return 1;
}


/*!MD
#### GetWindowPosition
```lua
ray_vector2 Position = ray.core.GetWindowPosition()
```
Get window position XY on monitor.
See [Vector2](#Ray_vector2)
*/

int lua_core_GetWindowPosition(lua_State *L){
  Vector2 * v = luax_newobject(L, "ray_vector2", sizeof(Vector2));
  *v = GetWindowPosition();
  return 1;
}

/*!MD
#### GetMonitorName
```lua
string Name = ray.core.GetMonitorName()
```
Get the human-readable, UTF-8 encoded name of the primary monitor
*/

int lua_core_GetMonitorName(lua_State *L){
  lua_pushstring(L, GetMonitorName(luaL_checkinteger(L, 1)));
  return 1;
}

/*!MD
#### GetClipboardText
```lua
string Text = ray.core.GetClipboardText()
```
Get clipboard text content
*/

int lua_core_GetClipboardText(lua_State *L){
  lua_pushstring(L, GetClipboardText());
  return 1;
}

/*!MD
#### SetClipboardText
```lua
ray.core.SetClipboardText(string Text)
```
Set clipboard text content
*/

int lua_core_SetClipboardText(lua_State *L){
  SetClipboardText(luaL_checkstring(L, 1));
  return 0;
}

/*!MD
### Cursor-related functions
#### ShowCursor
```lua
ray.core.ShowCursor()
```
Shows cursor
*/

int lua_core_ShowCursor(lua_State* L) {
  ShowCursor();
  return 0;
}

/*!MD
#### HideCursor
```lua
ray.core.HideCursor()
```
Hides cursor
*/

int lua_core_HideCursor(lua_State* L) {
  HideCursor();
  return 0;
}

/*!MD
#### IsCursorHidden
```lua
boolean Status = ray.core.IsCursorHidden()
```
Check if cursor is not visible
*/

int lua_core_IsCursorHidden(lua_State* L) {
  lua_pushboolean(L, IsCursorHidden());
  return 1;
}

/*!MD
#### EnableCursor
```lua
ray.core.EnableCursor()
```
Enables cursor (unlock cursor)
*/

int lua_core_EnableCursor(lua_State* L) {
  EnableCursor();
  return 0;
}

/*!MD
#### DisableCursor
```lua
ray.core.DisableCursor()
```
Disables cursor (lock cursor)
*/

int lua_core_DisableCursor(lua_State* L) {
  DisableCursor();
  return 0;
}

/*!MD
### Drawing-related functions
#### ClearBackground
```lua
ray.core.ClearBackground(ray_color Color)
```
Set background color (framebuffer clear color).
See [Color](#Ray_color)
*/

int lua_core_ClearBackground(lua_State *L){
  Color * c = luaL_checkudata(L, 1, "ray_color");
  ClearBackground(*c);
  return 0;
}

/*!MD
#### BeginDrawing
```lua
ray.core.BeginDrawing()
```
Setup canvas (framebuffer) to start drawing
*/

int lua_core_BeginDrawing(lua_State *L){
  BeginDrawing();
  return 0;
}

/*!MD
#### EndDrawing
```lua
ray.core.EndDrawing()
```
End canvas drawing and swap buffers (double buffering)
*/

int lua_core_EndDrawing(lua_State *L){
  EndDrawing();
  return 0;
}

/*!MD
#### BeginMode2D
```lua
ray.core.BeginMode2D(ray_camera2d Camera)
```
Initialize 2D mode with custom camera (2D).
See [Camera2D](#Ray_camera2d)
*/

int lua_core_BeginMode2D(lua_State *L){
  Camera2D * c = luaL_checkudata(L, 1, "ray_camera2d");
  BeginMode2D(*c);
  return 0;
}

/*!MD
#### EndMode2D
```lua
ray.core.EndMode2D()
```
Ends 2D mode with custom camera
*/

int lua_core_EndMode2D(lua_State *L){
  EndMode2D();
  return 0;
}

/*!MD
#### BeginMode3D
```lua
ray.core.BeginMode3D(ray_camera3d Camera)
```
Initializes 3D mode with custom camera (3D).
See [Camera3D](#Ray_camera3d)
*/

int lua_core_BeginMode3D(lua_State *L){
  Camera3D * c = luaL_checkudata(L, 1, "ray_camera3d");
  BeginMode3D(*c);
  return 0;
}

/*!MD
#### EndMode3D
```lua
ray.core.EndMode3D()
```
Ends 3D mode and returns to default 2D orthographic mode
*/

int lua_core_EndMode3D(lua_State *L){
  EndMode3D();
  return 0;
}

/*!MD
#### BeginTextureMode
```lua
ray.core.BeginTextureMode(ray_rendertexture Texture)
```
Initializes render texture for drawing.
See [RenderTexture](#Ray_rendertexture)
*/

int lua_core_BeginTextureMode(lua_State *L){
  RenderTexture2D  * t = luaL_checkudata(L, 1, "ray_rendertexture");
  BeginTextureMode(*t);
  return 0;
}

/*!MD
#### EndTextureMode
```lua
ray.core.EndTextureMode()
```
Ends drawing to render texture
*/

int lua_core_EndTextureMode(lua_State *L){
  EndTextureMode();
  return 0;
}

/*!MD
#### BeginScissorMode
```lua
ray.core.BeginScissorMode(integer X, integer Y, integer Width, integer Height)
```
Begin scissor mode (define screen area for following drawing)
*/

int lua_core_BeginScissorMode(lua_State *L){
  int x = luaL_checkinteger(L, 1);
  int y = luaL_checkinteger(L, 2);
  int w = luaL_checkinteger(L, 3);
  int h = luaL_checkinteger(L, 4);
  BeginScissorMode(x, y, w, h);
  return 0;
}

/*!MD
#### EndScissorMode
```lua
ray.core.EndScissorMode()
```
End scissor mode
*/

int lua_core_EndScissorMode(lua_State *L){
  EndScissorMode();
  return 0;
}

/*!MD
### Screen-space-related functions
#### GetMouseRay
```lua
ray.core.GetMouseRay(ray_vector2 Vector, ray_camera3d Camera)
```
Set background color (framebuffer clear color).
See [Color](#Ray_color)
*/

int lua_core_GetMouseRay(lua_State *L){
  Vector2  * v = luaL_checkudata(L, 1, "ray_vector2");
  Camera3D * c = luaL_checkudata(L, 2, "ray_camera3d");
  if (lua_isstring(L, 3) && luaL_checkstring(L, 3)[0] == 'v') {
    Ray r = GetMouseRay(*v, *c);
    Vector3 * position  = luax_newobject(L, "ray_vector3", sizeof(Vector3));
    Vector3 * direction = luax_newobject(L, "ray_vector3", sizeof(Vector3));
    *position  = r.position;
    *direction = r.direction;
    return 2;
  }

  Ray * r = luax_newobject(L, "ray_object", sizeof(Ray));
  *r = GetMouseRay(*v, *c);
  return 1;
}

int lua_core_GetCameraMatrix(lua_State *L){
  Camera3D * c = luaL_checkudata(L, 1, "ray_camera3d");
  Matrix * m = luax_newobject(L, "ray_matrix", sizeof(Matrix));
  *m = GetCameraMatrix(*c);
  return 1;
}

int lua_core_GetCameraMatrix2D(lua_State *L){
  Camera2D * c = luaL_checkudata(L, 1, "ray_camera2d");
  Matrix   * m = luax_newobject(L, "ray_matrix", sizeof(Matrix));
  *m = GetCameraMatrix2D(*c);
  return 1;
}

int lua_core_GetWorldToScreen(lua_State *L){
  Vector3  * v = luaL_checkudata(L, 1, "ray_vector3");
  Camera3D * c = luaL_checkudata(L, 2, "ray_camera3d");
  Vector2 * p  = luax_newobject(L, "ray_vector2", sizeof(Vector2));
  *p = GetWorldToScreen(*v, *c);
  return 1;
}

int lua_core_GetWorldToScreenEx(lua_State *L){
  Vector3  * v = luaL_checkudata(L, 1, "ray_vector3");
  Camera3D * c = luaL_checkudata(L, 2, "ray_camera3d");
  int w = luaL_checkinteger(L, 3);
  int h = luaL_checkinteger(L, 4);
  Vector2 * p  = luax_newobject(L, "ray_vector2", sizeof(Vector2));
  *p = GetWorldToScreenEx(*v, *c, w, h);
  return 1;
}

int lua_core_GetWorldToScreen2D(lua_State *L){
  Vector2  * v = luaL_checkudata(L, 1, "ray_vector2");
  Camera2D * c = luaL_checkudata(L, 2, "ray_camera2d");
  Vector2 * p  = luax_newobject(L, "ray_vector2", sizeof(Vector2));
  *p = GetWorldToScreen2D(*v, *c);
  return 1;
}

int lua_core_GetScreenToWorld2D(lua_State *L){
  Vector2  * v = luaL_checkudata(L, 1, "ray_vector2");
  Camera2D * c = luaL_checkudata(L, 2, "ray_camera2d");
  Vector2 *  p = luax_newobject(L, "ray_vector2", sizeof(Vector2));
  *p = GetScreenToWorld2D(*v, *c);
  return 1;
}

/*!MD
### Timing-related functions
#### SetTargetFPS
```lua
ray.core.SetTargetFPS(integer FPS)
```
Set target FPS (maximum)
*/

int lua_core_SetTargetFPS(lua_State *L){
  int fps = luaL_checkinteger(L, 1);
  SetTargetFPS(fps);
  return 0;
}

int lua_core_GetFPS(lua_State *L){
  lua_pushinteger(L, GetFPS());
  return 1;
}

int lua_core_GetFrameTime(lua_State *L){
  lua_pushnumber(L, GetFrameTime());
  return 1;
}

int lua_core_GetTime(lua_State *L){
  lua_pushnumber(L, GetTime());
  return 1;
}


/*!MD
### Color-related functions
#### ColorToInt
```lua
integer iColor = ray.core.ColorToInt(ray_color Color)
```
Returns hexadecimal value for a Color
*/

int lua_core_ColorToInt(lua_State *L){
  Color * c = luaL_checkudata(L, 1, "ray_color");
  lua_pushnumber(L, ColorToInt(*c));
  return 1;
}

int lua_core_ColorNormalize(lua_State *L){
  Color   * c = luaL_checkudata(L, 1, "ray_color");
  Vector4   v = ColorNormalize(*c);

   if (lua_isstring(L, 2)) {
     const char c = luaL_checkstring(L, 2)[0];
     if (c == 'n'){
         lua_pushnumber(L, v.x); 
         lua_pushnumber(L, v.y);
         lua_pushnumber(L, v.z);
         lua_pushnumber(L, v.w);
         return 4;
     }
     else if (c == 't'){
       lua_newtable(L);
       luax_tnnumber(L, 1, v.x);
       luax_tnnumber(L, 2, v.y);
       luax_tnnumber(L, 3, v.z);
       luax_tnnumber(L, 4, v.w);
       return 1;
     }
   }

  Vector4 * res = luax_newobject(L, "ray_vector4", sizeof(Vector4));
  *res = v;
  return 1;
}

int lua_core_ColorFromNormalized(lua_State *L){
  Color   * c = luax_newobject(L, "ray_color", sizeof(Color));
  if (luax_checkclass(L, 1, "ray_vector4")) {
    Vector4 * v = luaL_checkudata(L, 1, "ray_vector4");
    *c = ColorFromNormalized(*v);
    return 1;
  }

  Vector4 v = {0};
  if (lua_istable(L, 1)){
      for (int i = 0; i < 4; i++) lua_rawgeti(L, 1, i + 1);
      v.x = luax_optnumber(L, -4, 0.0f);
      v.y = luax_optnumber(L, -3, 0.0f);
      v.z = luax_optnumber(L, -2, 0.0f);
      v.w = luax_optnumber(L, -1, 1.0f);
      lua_pop(L, 4);
      *c = ColorFromNormalized(v);
      return 1;
  } else if (lua_isnumber(L, 1)){
    v.x = luax_optnumber(L, 1, 0.0f);
    v.y = luax_optnumber(L, 2, 0.0f);
    v.z = luax_optnumber(L, 3, 0.0f);
    v.w = luax_optnumber(L, 4, 1.0f);
    *c  = ColorFromNormalized(v);
    return 1;
  }
  return luaL_typerror(L, 1, "ray_vector4 or table or number");
}

int lua_core_ColorToHSV(lua_State *L){
  Color   * c = luaL_checkudata(L, 1, "ray_color");
  Vector3   v = ColorToHSV(*c);

   if (lua_isstring(L, 2)) {
     const char c = luaL_checkstring(L, 2)[0];
     if (c == 'n'){
         lua_pushnumber(L, v.x); 
         lua_pushnumber(L, v.y);
         lua_pushnumber(L, v.z);
         return 4;
     }
     else if (c == 't'){
       lua_newtable(L);
       luax_tnnumber(L, 1, v.x);
       luax_tnnumber(L, 2, v.y);
       luax_tnnumber(L, 3, v.z);
       return 1;
     }
   }

  Vector3 * res = luax_newobject(L, "ray_vector3", sizeof(Vector3));
  *res = v;
  return 1;
}

int lua_core_ColorFromHSV(lua_State *L){
  Color   * c = luax_newobject(L, "ray_color", sizeof(Color));
  if (luax_checkclass(L, 1, "ray_vector3")) {
    Vector3 * v = luaL_checkudata(L, 1, "ray_vector3");
    *c = ColorFromHSV(*v);
    return 1;
  }

  Vector3 v = {0};
  if (lua_istable(L, 1)){
      for (int i = 0; i < 3; i++) lua_rawgeti(L, 1, i + 1);
      v.x = luax_optnumber(L, -4, 0.0f);
      v.y = luax_optnumber(L, -3, 0.0f);
      v.z = luax_optnumber(L, -2, 0.0f);
      lua_pop(L, 3);
      *c = ColorFromHSV(v);
      return 1;
  } else if (lua_isnumber(L, 1)){
    v.x = luax_optnumber(L, 1, 0.0f);
    v.y = luax_optnumber(L, 2, 0.0f);
    v.z = luax_optnumber(L, 3, 0.0f);
    *c  = ColorFromHSV(v);
    return 1;
  }
  return luaL_typerror(L, 1, "ray_vector3 or table or number");
}

int lua_core_GetColor(lua_State *L){
  int hex = luaL_checkinteger(L, 1);
  Color * c = luax_newobject(L, "ray_color", sizeof(Color));
  *c = GetColor(hex);
  return 1;
}

int lua_core_Fade(lua_State *L){
  Color * c = luaL_checkudata(L, 1, "ray_color");
  float a   = luaL_checknumber(L, 2);
  Color * r = luax_newobject(L, "ray_color", sizeof(Color));
  *r = Fade(*c, a);
  return 1;
}

/*!MD
### Misc. functions
#### SetConfigFlags
```lua
ray.core.SetConfigFlags(string flag1, string flag2, string flag3, ...)
```
Setup window configuration flags
Available flags:
`"FULLSCREEN_MODE"   ` Set to run program in fullscreen
`"WINDOW_RESIZABLE"  ` Set to allow resizable window
`"WINDOW_UNDECORATED"` Set to disable window decoration (frame and buttons)
`"WINDOW_TRANSPARENT"` Set to allow transparent window
`"WINDOW_HIDDEN"     ` Set to create the window initially hidden
`"WINDOW_ALWAYS_RUN" ` Set to allow windows running while minimized
`"MSAA_4X_HINT"      ` Set to try enabling MSAA 4X
`"VSYNC_HINT"        ` Set to try enabling V-Sync on GPU
*/

int lua_core_SetConfigFlags(lua_State *L){
  int flag = 1;
  for (int i = 1; i <= lua_gettop(L); i++){
      if (lua_isstring(L, i)){
          const char * s = luaL_checkstring(L, i);
               if (!strcmp(s, "FULLSCREEN_MODE"))    flag |= FLAG_FULLSCREEN_MODE;
          else if (!strcmp(s, "WINDOW_RESIZABLE"))   flag |= FLAG_WINDOW_RESIZABLE;
          else if (!strcmp(s, "WINDOW_UNDECORATED")) flag |= FLAG_WINDOW_UNDECORATED;
          else if (!strcmp(s, "WINDOW_TRANSPARENT")) flag |= FLAG_WINDOW_TRANSPARENT;
          else if (!strcmp(s, "WINDOW_HIDDEN"))      flag |= FLAG_WINDOW_HIDDEN;
          else if (!strcmp(s, "WINDOW_ALWAYS_RUN"))  flag |= FLAG_WINDOW_ALWAYS_RUN;
          else if (!strcmp(s, "MSAA_4X_HINT"))       flag |= FLAG_MSAA_4X_HINT;
          else if (!strcmp(s, "VSYNC_HINT"))         flag |= FLAG_VSYNC_HINT;
      }
  }
  
  SetConfigFlags(flag);
  return 0;
}

/*
    LOG_ALL = 0,        // Display all logs
    LOG_TRACE,
    LOG_DEBUG,
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR,
    LOG_FATAL,
    LOG_NONE            // Disable logging
*/

int lua_core_SetTraceLogLevel(lua_State *L){
  int flag = LOG_NONE;
  if (lua_isstring(L, 1)){
     const char * s = luaL_checkstring(L, 1);
           if (!strcmp(s, "ALL"))     flag = LOG_ALL;
      else if (!strcmp(s, "TRACE"))   flag = LOG_TRACE;
      else if (!strcmp(s, "DEBUG"))   flag = LOG_DEBUG;
      else if (!strcmp(s, "INFO"))    flag = LOG_INFO;
      else if (!strcmp(s, "WARNING")) flag = LOG_WARNING;
      else if (!strcmp(s, "ERROR"))   flag = LOG_ERROR;
      else if (!strcmp(s, "FATAL"))   flag = LOG_FATAL;
      else if (!strcmp(s, "NONE"))    flag = LOG_NONE;
  }
  SetTraceLogLevel(flag);
  return 0;
}

int lua_core_SetTraceLogExit(lua_State *L){
  int flag = LOG_NONE;
  if (!lua_isstring(L, 1)){
     const char * s = luaL_checkstring(L, 1);
           if (!strcmp(s, "ALL"))     flag = LOG_ALL;
      else if (!strcmp(s, "TRACE"))   flag = LOG_TRACE;
      else if (!strcmp(s, "DEBUG"))   flag = LOG_DEBUG;
      else if (!strcmp(s, "INFO"))    flag = LOG_INFO;
      else if (!strcmp(s, "WARNING")) flag = LOG_WARNING;
      else if (!strcmp(s, "ERROR"))   flag = LOG_ERROR;
      else if (!strcmp(s, "FATAL"))   flag = LOG_FATAL;
      else if (!strcmp(s, "NONE"))    flag = LOG_NONE;
  }
  SetTraceLogExit(flag);
  return 0;
}


lua_State * _lua_state;    // keeping lua_State that user for function
int _lua_trace_callback_ref; // and reference to function
// va_list are unused because we can't generate va_list dynamicly by Lua
void _lua_callback(int logType, const char * text, va_list args ){
  if (!_lua_trace_callback_ref) return;
  const char * level = "NONE";

  switch(logType){
  case(LOG_TRACE):   level = "TRACE";
  case(LOG_DEBUG):   level = "DEBUG";
  case(LOG_INFO):    level = "INFO";
  case(LOG_WARNING): level = "WARNING";
  case(LOG_ERROR):   level = "ERROR";
  case(LOG_FATAL):   level = "FATAL";
  }

  lua_rawgeti(_lua_state, LUA_REGISTRYINDEX, _lua_trace_callback_ref);
  lua_pushstring(_lua_state, level);
  lua_pushstring(_lua_state, text);
  lua_call(_lua_state, 2, 0);
}

int lua_core_SetTraceLogCallback(lua_State *L){
  if (lua_isfunction(L, 1)){
    _lua_state = L;
    _lua_trace_callback_ref = lua_ref(L, 1);
    SetTraceLogCallback(_lua_callback);
    return 0;
  }
  lua_unref(L, _lua_trace_callback_ref);
  _lua_state = NULL;
  SetTraceLogCallback(NULL);
  return 0;
}

int lua_core_TakeScreenshot(lua_State *L){
  if (lua_isstring(L, 1)){
    const char * fname = luaL_checkstring(L, 1);
    TakeScreenshot(fname);
    return 0;
  }
  return 0;
}

int lua_core_TraceLog(lua_State *L){
  const char * s     = luaL_checkstring(L, 1);
  const char * text  = luaL_checkstring(L, 2);
  int flag = LOG_INFO;
         if (!strcmp(s, "TRACE"))   flag = LOG_TRACE;
    else if (!strcmp(s, "DEBUG"))   flag = LOG_DEBUG;
    else if (!strcmp(s, "INFO"))    flag = LOG_INFO;
    else if (!strcmp(s, "WARNING")) flag = LOG_WARNING;
    else if (!strcmp(s, "ERROR"))   flag = LOG_ERROR;
    else if (!strcmp(s, "FATAL"))   flag = LOG_FATAL;
  TraceLog(flag, text);
  return 0;
}

int lua_core_GetRandomValue(lua_State *L){
  int min = 1;
  int max = luaL_checkinteger(L, 1);
  if (lua_isnumber(L, 2)){
    min = max;
    max = luaL_checkinteger(L, 2);
  }
  lua_pushnumber(L, GetRandomValue(min, max));
  return 1;
}

/*!MD
### Files management functions
#### FileExists
```lua
ray.core.FileExists(string Filename)
```
Check if file exists
*/

int lua_core_FileExists(lua_State *L){
  const char * fname = luaL_checkstring(L, 1);
  lua_pushboolean(L, FileExists(fname));
  return 1;
}

int lua_core_IsFileExtension(lua_State *L){
  const char * fname = luaL_checkstring(L, 1);
  const char * fext  = luaL_checkstring(L, 2);
  lua_pushboolean(L, IsFileExtension(fname, fext));
  return 1;
}

int lua_core_DirectoryExists(lua_State *L){
  const char * dname = luaL_checkstring(L, 1);
  lua_pushboolean(L, DirectoryExists(dname));
  return 1;
}

int lua_core_GetExtension(lua_State *L){
  const char * fname = luaL_checkstring(L, 1);
  lua_pushstring(L, GetExtension(fname));
  return 1;
}

int lua_core_GetFileName(lua_State *L){
  const char * fpath = luaL_checkstring(L, 1);
  lua_pushstring(L, GetFileName(fpath));
  return 1;
}

int lua_core_GetFileNameWithoutExt(lua_State *L){
  const char * fpath = luaL_checkstring(L, 1);
  lua_pushstring(L, GetFileNameWithoutExt(fpath));
  return 1;
}

int lua_core_GetDirectoryPath(lua_State *L){
  const char * fpath = luaL_checkstring(L, 1);
  lua_pushstring(L, GetDirectoryPath(fpath));
  return 1;
}

int lua_core_GetPrevDirectoryPath(lua_State *L){
  const char * dpath = luaL_checkstring(L, 1);
  lua_pushstring(L, GetPrevDirectoryPath(dpath));
  return 1;
}

int lua_core_GetWorkingDirectory(lua_State *L){
  lua_pushstring(L, GetWorkingDirectory());
  return 1;
}

int lua_core_GetDirectoryFiles(lua_State *L){
  const char * dpath = luaL_checkstring(L, 1);
  int count;
  char ** paths = GetDirectoryFiles(dpath, &count);
  lua_newtable(L);
  for (int i = 0; i < count; i++) lua_pushstring(L, paths[i]);
  ClearDirectoryFiles();
  return 1;
}

int lua_core_ClearDirectoryFiles(lua_State *L){
  ClearDirectoryFiles();
  return 0;
}

int lua_core_ChangeDirectory(lua_State *L){
  const char * dpath = luaL_checkstring(L, 1);
  lua_pushboolean(L, ChangeDirectory(dpath));
  return 1;
}

int lua_core_IsFileDropped(lua_State *L){
  lua_pushboolean(L, IsFileDropped());
  return 1;
}

int lua_core_GetDroppedFiles(lua_State *L){
  int count;
  char ** files = GetDroppedFiles(&count);
  lua_newtable(L);
  for (int i = 0; i < count; i++) lua_pushstring(L, files[i]);
  ClearDroppedFiles();
  return 1;
}

int lua_core_ClearDroppedFiles(lua_State *L){
  ClearDroppedFiles();
  return 0;
}

int lua_core_GetFileModTime(lua_State *L){
  const char * fpath = luaL_checkstring(L, 1);
  lua_pushnumber(L, GetFileModTime(fpath));
  return 1;
}

int lua_core_GetFileInfo(lua_State *L){
  const char * fpath = luaL_checkstring(L, 1);
  lua_newtable(L);
  luax_tsstring(L, "fullname",  GetFileName(fpath));
  luax_tsstring(L, "name",      GetFileNameWithoutExt(fpath));
  luax_tsstring(L, "ext",       GetExtension(fpath));
  luax_tsstring(L, "directory", GetDirectoryPath(fpath));
  luax_tsnumber(L, "modtime",   GetFileModTime(fpath));
  return 1;
}

int lua_core_CompressData(lua_State *L){
  int srclen, dstlen;
  const char * src = luaL_checklstring(L, 1, &srclen);
  const char * dst = CompressData((unsigned char *)src, srclen, &dstlen);
  lua_pushlstring(L, dst, dstlen);
  return 1;
}

int lua_core_DecompressData(lua_State *L){
  int srclen, dstlen;
  const char * src = luaL_checklstring(L, 1, &srclen);
  const char * dst = DecompressData((unsigned char *)src, srclen, &dstlen);
  lua_pushlstring(L, dst, dstlen);
  return 1;
}

int lua_core_OpenURL(lua_State *L){
  const char * url = luaL_checkstring(L, 1);
  OpenURL(url);
  return 0;
}

/*!MD
### Persistent storage management
#### StorageSaveValue
```lua
ray.core.StorageSaveValue(integer Position, integer Value)
```
Save integer value to storage file (to defined position)
*/

int lua_core_StorageSaveValue(lua_State *L){
  int key   = luaL_checkinteger(L, 1);
  int value = luaL_checkinteger(L, 2);
  StorageSaveValue(key, value);
  return 0;
}

int lua_core_StorageLoadValue(lua_State *L){
  int key = luaL_checkinteger(L, 1);
  lua_pushinteger(L, StorageLoadValue(key));
  return 1;
}

/*!MD
### Input-related functions: keyb
#### IsKeyPressed
```lua
boolean State = ray.core.IsKeyPressed(integer Key)
```
Detect if a key has been pressed once
*/

int lua_core_IsKeyPressed(lua_State *L){
  int key = luaL_checkinteger(L, 1);
  lua_pushboolean(L, IsKeyPressed(key));
  return 1;
}

int lua_core_IsKeyDown(lua_State *L){
  int key = luaL_checkinteger(L, 1);
  lua_pushboolean(L, IsKeyDown(key));
  return 1;
}

int lua_core_IsKeyReleased(lua_State *L){
  int key = luaL_checkinteger(L, 1);
  lua_pushboolean(L, IsKeyReleased(key));
  return 1;
}

int lua_core_IsKeyUp(lua_State *L){
  int key = luaL_checkinteger(L, 1);
  lua_pushboolean(L, IsKeyUp(key));
  return 1;
}

// TODO: CHECK AND FINISH
int lua_core_GetKeyPressed(lua_State *L){
  char _key[8];
  int i = 0;
  int key = GetKeyPressed();
  while(key){
      i++;
      printf("Pressed key: [%d]", key);
      lua_pushnumber(L, key);
      key = GetKeyPressed();
  }

  return i;
}

int lua_core_SetExitKey(lua_State *L){
  int key = luaL_checkinteger(L, 1);
  SetExitKey(key);
  return 0;
}

/*!MD
### Input-related functions: gamepads
#### IsGamepadAvailable
```lua
boolean State = ray.core.IsGamepadAvailable(integer Gamepad)
```
Detect if a gamepad is available
*/

int lua_core_IsGamepadAvailable(lua_State *L){
  int gamepad = luaL_checkinteger(L, 1);
  lua_pushboolean(L, IsGamepadAvailable(gamepad + 1));
  return 1;
}

int lua_core_IsGamepadName(lua_State *L){
  int gamepad = luaL_checkinteger(L, 1);
  const char * name = luaL_checkstring(L, 2);
  lua_pushboolean(L, IsGamepadName(gamepad + 1, name));
  return 1;
}

int lua_core_GetGamepadName(lua_State *L){
  int gamepad = luaL_checkinteger(L, 1);
  lua_pushstring(L, GetGamepadName(gamepad + 1));
  return 1;
}

int lua_core_IsGamepadButtonPressed(lua_State *L){
  int gamepad = luaL_checkinteger(L, 1);
  int button  = luaL_checkinteger(L, 2);
  lua_pushboolean(L, IsGamepadButtonPressed(gamepad + 1, button));
  return 1;
}

int lua_core_IsGamepadButtonDown(lua_State *L){
  int gamepad = luaL_checkinteger(L, 1);
  int button  = luaL_checkinteger(L, 2);
  lua_pushboolean(L, IsGamepadButtonDown(gamepad + 1, button));
  return 1;
}

int lua_core_IsGamepadButtonReleased(lua_State *L){
  int gamepad = luaL_checkinteger(L, 1);
  int button  = luaL_checkinteger(L, 2);
  lua_pushboolean(L, IsGamepadButtonReleased(gamepad + 1, button));
  return 1;
}

int lua_core_IsGamepadButtonUp(lua_State *L){
  int gamepad = luaL_checkinteger(L, 1);
  int button  = luaL_checkinteger(L, 2);
  lua_pushboolean(L, IsGamepadButtonUp(gamepad + 1, button));
  return 1;
}

int lua_core_GetGamepadButtonPressed(lua_State *L){
  lua_pushnumber(L, GetGamepadButtonPressed());
  return 1;
}

int lua_core_GetGamepadAxisCount(lua_State *L){
  int gamepad = luaL_checkinteger(L, 1);
  lua_pushnumber(L, GetGamepadAxisCount(gamepad + 1));
  return 1;
}

int lua_core_GetGamepadAxisMovement(lua_State *L){
  int gamepad = luaL_checkinteger(L, 1);
  int axis    = luaL_checkinteger(L, 2);
  lua_pushnumber(L, GetGamepadAxisMovement(gamepad + 1, axis));
  return 1;
}

/*!MD
### Input-related functions: mouse
#### IsMouseButtonPressed
```lua
boolean State = ray.core.IsMouseButtonPressed(integer Button)
```
Detect if a mouse button has been pressed once
*/

int lua_core_IsMouseButtonPressed(lua_State *L){
  int button  = luaL_checkinteger(L, 1);
  lua_pushboolean(L, IsMouseButtonPressed(button + 1));
  return 1;
}

int lua_core_IsMouseButtonDown(lua_State *L){
  int button  = luaL_checkinteger(L, 1);
  lua_pushboolean(L, IsMouseButtonDown(button + 1));
  return 1;
}

int lua_core_IsMouseButtonReleased(lua_State *L){
  int button  = luaL_checkinteger(L, 1);
  lua_pushboolean(L, IsMouseButtonReleased(button + 1));
  return 1;
}

int lua_core_IsMouseButtonUp(lua_State *L){
  int button  = luaL_checkinteger(L, 1);
  lua_pushboolean(L, IsMouseButtonUp(button + 1));
  return 1;
}

int lua_core_GetMouseX(lua_State *L){
  lua_pushnumber(L, GetMouseX());
  return 1;
}

int lua_core_GetMouseY(lua_State *L){
  lua_pushnumber(L, GetMouseY());
  return 1;
}

int lua_core_GetMousePosition(lua_State *L){
  if (luax_optstring(L, 1, "\0")[0] == 'n') {
    lua_pushnumber(L, GetMouseX());
    lua_pushnumber(L, GetMouseY());
    return 2;
  }
  Vector2 * v = luax_newobject(L, "ray_vector2", sizeof(Vector2));
  *v = GetMousePosition();
  return 1;
}

int lua_core_SetMousePosition(lua_State *L){
  if (luax_checkclass(L, 1, "ray_vector2")){
    Vector2 * v = luaL_checkudata(L, 1, "ray_vector2");
    SetMousePosition(v->x, v->y);
    return 0;
  }
  int x = luaL_checkinteger(L, 1);
  int y = luaL_checkinteger(L, 2);
  SetMousePosition(x, y);
  return 0;
}

int lua_core_SetMouseOffset(lua_State *L){
  if (luax_checkclass(L, 1, "ray_vector2")){
    Vector2 * v = luaL_checkudata(L, 1, "ray_vector2");
    SetMouseOffset(v->x, v->y);
    return 0;
  }
  int x = luaL_checkinteger(L, 1);
  int y = luaL_checkinteger(L, 2);
  SetMouseOffset(x, y);
  return 0;
}

int lua_core_SetMouseScale(lua_State *L){
  if (luax_checkclass(L, 1, "ray_vector2")){
    Vector2 * v = luaL_checkudata(L, 1, "ray_vector2");
    SetMouseScale(v->x, v->y);
    return 0;
  }
  int x = luaL_checkinteger(L, 1);
  int y = luaL_checkinteger(L, 2);
  SetMouseScale(x, y);
  return 0;
}

int lua_core_GetMouseWheelMove(lua_State *L){
  lua_pushnumber(L, GetMouseWheelMove());
  return 1;
}

/*!MD
### Input-related functions: touch
#### GetTouchX
```lua
boolean State = ray.core.GetTouchX()
```
Returns touch position X for touch point 0 (relative to screen size)
*/

int lua_core_GetTouchX(lua_State *L){
  lua_pushnumber(L, GetTouchX());
  return 1;
}

int lua_core_GetTouchY(lua_State *L){
  lua_pushnumber(L, GetTouchY());
  return 1;
}

int lua_core_GetTouch(lua_State *L){
  lua_pushnumber(L, GetTouchX());
  lua_pushnumber(L, GetTouchY());
  return 2;
}

int lua_core_GetTouchPosition(lua_State *L){
  int touch = luaL_checkinteger(L, 1);
  Vector2 v = GetTouchPosition(touch + 1);
  if (luax_optstring(L, 2, "\0")[0] == 'n') {
    lua_pushnumber(L, v.x);
    lua_pushnumber(L, v.y);
    return 2;
  }
  Vector2 * lv = luax_newobject(L, "ray_vector2", sizeof(Vector2));
  *lv = v;
  return 1;
}

int lua_core_GetTouches(lua_State *L){
  int touch = luaL_checkinteger(L, 1);
  lua_newtable(L); // result
  bool isNumbers = luax_optstring(L, 1, "\0")[0] == 'n';
  for (int i = 0; i < GetTouchPointsCount(); i++){
    lua_pushnumber(L, i + 1); // index
    Vector2 v = GetTouchPosition(i);
    if (isNumbers){
        lua_newtable(L);
        luax_tnnumber(L, 1, v.x);
        luax_tnnumber(L, 1, v.y);
    }
    else{
      Vector2 * lv = luax_newobject(L, "ray_vector2", sizeof(Vector2));
      *lv = v;
    }
    lua_rawset(L, -3);
  }
  return 1;
}

int lua_core_SetGesturesEnabled(lua_State *L){
  int flag = GESTURE_NONE;
  for (int i = 1; i <= lua_gettop(L); i++){
    if (lua_isstring(L, i)){
      const char * s = luaL_checkstring(L, i);
           if (!strcmp(s, "NONE"))        flag |= GESTURE_NONE;
      else if (!strcmp(s, "TAP"))         flag |= GESTURE_TAP;
      else if (!strcmp(s, "DOUBLETAP"))   flag |= GESTURE_DOUBLETAP;
      else if (!strcmp(s, "HOLD"))        flag |= GESTURE_HOLD;
      else if (!strcmp(s, "DRAG"))        flag |= GESTURE_DRAG;
      else if (!strcmp(s, "SWIPE_RIGHT")) flag |= GESTURE_SWIPE_RIGHT;
      else if (!strcmp(s, "SWIPE_LEFT"))  flag |= GESTURE_SWIPE_LEFT;
      else if (!strcmp(s, "SWIPE_UP"))    flag |= GESTURE_SWIPE_UP;
      else if (!strcmp(s, "SWIPE_DOWN"))  flag |= GESTURE_SWIPE_DOWN;
      else if (!strcmp(s, "PINCH_IN"))    flag |= GESTURE_PINCH_IN;
      else if (!strcmp(s, "PINCH_OUT"))   flag |= GESTURE_PINCH_OUT;
    }
  }
  SetGesturesEnabled(flag);
  return 0;
}

int lua_core_IsGestureDetected(lua_State *L){
  const char * s = luaL_checkstring(L, 1);
  int flag = GESTURE_NONE;
       if (!strcmp(s, "TAP"))         flag = GESTURE_TAP;
  else if (!strcmp(s, "DOUBLETAP"))   flag = GESTURE_DOUBLETAP;
  else if (!strcmp(s, "HOLD"))        flag = GESTURE_HOLD;
  else if (!strcmp(s, "DRAG"))        flag = GESTURE_DRAG;
  else if (!strcmp(s, "SWIPE_RIGHT")) flag = GESTURE_SWIPE_RIGHT;
  else if (!strcmp(s, "SWIPE_LEFT"))  flag = GESTURE_SWIPE_LEFT;
  else if (!strcmp(s, "SWIPE_UP"))    flag = GESTURE_SWIPE_UP;
  else if (!strcmp(s, "SWIPE_DOWN"))  flag = GESTURE_SWIPE_DOWN;
  else if (!strcmp(s, "PINCH_IN"))    flag = GESTURE_PINCH_IN;
  else if (!strcmp(s, "PINCH_OUT"))   flag = GESTURE_PINCH_OUT;
  lua_pushboolean(L, IsGestureDetected(flag));
  return 1;
}

int lua_core_GetGestureDetected(lua_State *L){
  int flag = GetGestureDetected();
  const char * c = "NONE";
       if (flag ==  GESTURE_TAP)         c = "TAP";
  else if (flag ==  GESTURE_DOUBLETAP)   c = "DOUBLETAP";
  else if (flag ==  GESTURE_HOLD)        c = "HOLD";
  else if (flag ==  GESTURE_DRAG)        c = "DRAG";
  else if (flag ==  GESTURE_SWIPE_RIGHT) c = "SWIPE_RIGHT";
  else if (flag ==  GESTURE_SWIPE_LEFT)  c = "SWIPE_LEFT";
  else if (flag ==  GESTURE_SWIPE_UP)    c = "SWIPE_UP";
  else if (flag ==  GESTURE_SWIPE_DOWN)  c = "SWIPE_DOWN";
  else if (flag ==  GESTURE_PINCH_IN)    c = "PINCH_IN";
  else if (flag ==  GESTURE_PINCH_OUT)   c = "PINCH_OUT";
  lua_pushstring(L, c); // 1

  if (flag == GESTURE_HOLD) {
    lua_pushnumber(L, GetGestureHoldDuration()); // 2
    return 2;
  }

  if (flag == GESTURE_DRAG) {
    Vector2 v = GetGestureDragVector();
    if (luax_optstring(L, 1, "\0")[0] == 'n'){
      lua_pushnumber(L, v.x);                   // 2
      lua_pushnumber(L, v.y);                   // 3
      lua_pushnumber(L, GetGestureDragAngle()); // 4
      return 4;
    }
    Vector2 * lv = luax_newobject(L, "ray_vector2", sizeof(Vector2)); // 2
    *lv = v;
    lua_pushnumber(L, GetGestureDragAngle()); // 3
    return 3;
  }

  if ((flag == GESTURE_PINCH_IN) || (flag == GESTURE_PINCH_OUT)) {
    Vector2 v = GetGesturePinchVector();
    if (luax_optstring(L, 1, "\0")[0] == 'n'){
      lua_pushnumber(L, v.x);                    // 2
      lua_pushnumber(L, v.y);                    // 3
      lua_pushnumber(L, GetGesturePinchAngle()); // 4
      return 4;
    }
    Vector2 * lv = luax_newobject(L, "ray_vector2", sizeof(Vector2)); // 2
    *lv = v;
    lua_pushnumber(L, GetGesturePinchAngle()); // 3
    return 3;
  }

  return 1;
}

int lua_core_GetTouchPointsCount(lua_State *L){
  lua_pushnumber(L, GetTouchPointsCount());
  return 1;
}

int lua_core_GetGestureHoldDuration(lua_State *L){
  lua_pushnumber(L, GetGestureHoldDuration());
  return 1;
}

int lua_core_GetGestureDragVector(lua_State *L){
  Vector2 v = GetGestureDragVector();
  if (luax_optstring(L, 1, "\0")[0] == 'n'){
    lua_pushnumber(L, v.x);
    lua_pushnumber(L, v.y);
    return 2;
  }
  Vector2 * lv = luax_newobject(L, "ray_vector2", sizeof(Vector2));
  *lv = v;
  return 1;
}

int lua_core_GetGestureDragAngle(lua_State *L){
  lua_pushnumber(L, GetGestureDragAngle());
  return 1;
}

int lua_core_GetGesturePinchVector(lua_State *L){
  Vector2 v = GetGesturePinchVector();
  if (luax_optstring(L, 1, "\0")[0] == 'n'){
    lua_pushnumber(L, v.x);
    lua_pushnumber(L, v.y);
    return 2;
  }
  Vector2 * lv = luax_newobject(L, "ray_vector2", sizeof(Vector2));
  *lv = v;
  return 1;
}

int lua_core_GetGesturePinchAngle(lua_State *L){
  lua_pushnumber(L, GetGesturePinchAngle());
  return 1;
}

/*!MD
### Camera System Functions (Module: camera)
#### SetCameraMode
```lua
ray.core.SetCameraMode(ray_camera3d Camera, string Mode)
```
Set camera mode. Availabke modes: 
* `"CUSTOM"` - default
* `"FREE"`
* `"ORBITAL"`
* `"FIRST_PERSON"`
* `"THIRD_PERSON"`
*/

int lua_core_SetCameraMode(lua_State *L){
  Camera3D * c = luaL_checkudata(L, 1, "ray_camera3d");
  int mode = CAMERA_CUSTOM;

   if (lua_isstring(L, 2)){
     const char * s = luaL_checkstring(L, 2);
          if (!strcmp(s, "CUSTOM"))       mode = CAMERA_CUSTOM;
     else if (!strcmp(s, "FREE"))         mode = CAMERA_FREE;
     else if (!strcmp(s, "ORBITAL"))      mode = CAMERA_ORBITAL;
     else if (!strcmp(s, "FIRST_PERSON")) mode = CAMERA_FIRST_PERSON;
     else if (!strcmp(s, "THIRD_PERSON")) mode = CAMERA_THIRD_PERSON;
   }

  SetCameraMode(*c, mode);
  return 0;
}

int lua_core_UpdateCamera(lua_State *L){
  Camera3D * c = luaL_checkudata(L, 1, "ray_camera3d");
  UpdateCamera(c);
  return 0;
}

int lua_core_SetCameraPanControl(lua_State *L){
  int key = luaL_checkinteger(L, 1);
  SetCameraPanControl(key);
  return 0;
}

int lua_core_SetCameraAltControl(lua_State *L){
  int key = luaL_checkinteger(L, 1);
  SetCameraAltControl(key);
  return 0;
}

int lua_core_SetCameraSmoothZoomControl(lua_State *L){
  int key = luaL_checkinteger(L, 1);
  SetCameraSmoothZoomControl(key);
  return 0;
}

int lua_core_SetCameraMoveControls(lua_State *L){
  int front = luaL_checkinteger(L, 1);
  int back  = luaL_checkinteger(L, 2);
  int right = luaL_checkinteger(L, 3);
  int left  = luaL_checkinteger(L, 4);
  int up    = luaL_checkinteger(L, 5);
  int down  = luaL_checkinteger(L, 6);
  SetCameraMoveControls(front, back, right, left, up, down);
  return 0;
}

luaL_Reg luaray_core[] = {
  // Window-related functions
  {"InitWindow",                   lua_core_InitWindow},
  {"WindowShouldClose",            lua_core_WindowShouldClose},
  {"CloseWindow",                  lua_core_CloseWindow},
  {"IsWindowReady",                lua_core_IsWindowReady},
  {"IsWindowMinimized",            lua_core_IsWindowMinimized},
  {"IsWindowResized",              lua_core_IsWindowResized},
  {"IsWindowHidden",               lua_core_IsWindowHidden},
  {"ToggleFullscreen",             lua_core_ToggleFullscreen},
  {"UnhideWindow",                 lua_core_UnhideWindow},
  {"HideWindow",                   lua_core_HideWindow},
  {"SetWindowIcon",                lua_core_SetWindowIcon},
  {"SetWindowTitle",               lua_core_SetWindowTitle},
  {"SetWindowPosition",            lua_core_SetWindowPosition},
  {"SetWindowMonitor",             lua_core_SetWindowMonitor},
  {"SetWindowMinSize",             lua_core_SetWindowMinSize},
  {"SetWindowSize",                lua_core_SetWindowSize},
  {"GetWindowHandle",              lua_core_GetWindowHandle},
  {"GetScreenWidth",               lua_core_GetScreenWidth},
  {"GetScreenHeight",              lua_core_GetScreenHeight},
  {"GetScreenDimensions",          lua_core_GetScreenDimensions},
  {"GetMonitorCount",              lua_core_GetMonitorCount},
  {"GetMonitorWidth",              lua_core_GetMonitorWidth},
  {"GetMonitorHeight",             lua_core_GetMonitorHeight},
  {"GetMonitorDimensions",         lua_core_GetMonitorDimensions},
  {"GetMonitorPhysicalWidth",      lua_core_GetMonitorPhysicalWidth},
  {"GetMonitorPhysicalHeight",     lua_core_GetMonitorPhysicalHeight},
  {"GetMonitorPhysicalDimensions", lua_core_GetMonitorPhysicalDimensions},
  {"GetMonitors",                  lua_core_GetMonitors},
  {"GetWindowPosition",            lua_core_GetWindowPosition},
  {"GetMonitorName",               lua_core_GetMonitorName},
  {"GetClipboardText",             lua_core_GetClipboardText},
  {"SetClipboardText",             lua_core_SetClipboardText},
  // Cursor-related functions
  {"ShowCursor",                   lua_core_ShowCursor},
  {"HideCursor",                   lua_core_HideCursor},
  {"IsCursorHidden",               lua_core_IsCursorHidden},
  {"EnableCursor",                 lua_core_EnableCursor},
  {"DisableCursor",                lua_core_DisableCursor},
  // Drawing-related functions
  {"ClearBackground",              lua_core_ClearBackground},
  {"BeginDrawing",                 lua_core_BeginDrawing},
  {"EndDrawing",                   lua_core_EndDrawing},
  {"BeginMode2D",                  lua_core_BeginMode2D},
  {"EndMode2D",                    lua_core_EndMode2D},
  {"BeginMode3D",                  lua_core_BeginMode3D},
  {"EndMode3D",                    lua_core_EndMode3D},
  {"BeginTextureMode",             lua_core_BeginTextureMode},
  {"EndTextureMode",               lua_core_EndTextureMode},
  {"BeginScissorMode",             lua_core_BeginScissorMode},
  {"EndScissorMode",               lua_core_EndScissorMode},
  // Screen-space-related functions
  {"GetMouseRay",                  lua_core_GetMouseRay},
  {"GetCameraMatrix",              lua_core_GetCameraMatrix},
  {"GetCameraMatrix2D",            lua_core_GetCameraMatrix2D},
  {"GetWorldToScreen",             lua_core_GetWorldToScreen},
  {"GetWorldToScreenEx",           lua_core_GetWorldToScreenEx},
  {"GetWorldToScreen2D",           lua_core_GetWorldToScreen2D},
  {"GetScreenToWorld2D",           lua_core_GetScreenToWorld2D},
  // Timing-related functions
  {"SetTargetFPS",                 lua_core_SetTargetFPS},
  {"GetFPS",                       lua_core_GetFPS},
  {"GetFrameTime",                 lua_core_GetFrameTime},
  {"GetTime",                      lua_core_GetTime},
  // Color-related functions
  {"ColorToInt",                   lua_core_ColorToInt},
  {"ColorNormalize",               lua_core_ColorNormalize},
  {"ColorFromNormalized",          lua_core_ColorFromNormalized},
  {"ColorToHSV",                   lua_core_ColorToHSV},
  {"ColorFromHSV",                 lua_core_ColorFromHSV},
  {"GetColor",                     lua_core_GetColor},
  {"Fade",                         lua_core_Fade},
  // Misc. functions
  {"SetConfigFlags",               lua_core_SetConfigFlags},
  {"SetTraceLogLevel",             lua_core_SetTraceLogLevel},
  {"SetTraceLogExit",              lua_core_SetTraceLogExit},
  {"SetTraceLogCallback",          lua_core_SetTraceLogCallback}, // typedef void (*TraceLogCallback)(int logType, const char *text, va_list args);
  {"TakeScreenshot",               lua_core_TakeScreenshot},
  {"TraceLog",                     lua_core_TraceLog},
  {"GetRandomValue",               lua_core_GetRandomValue},
  // Files management functions
  {"FileExists",                   lua_core_FileExists},
  {"IsFileExtension",              lua_core_IsFileExtension},
  {"DirectoryExists",              lua_core_DirectoryExists},
  {"GetExtension",                 lua_core_GetExtension},
  {"GetFileName",                  lua_core_GetFileName},
  {"GetFileNameWithoutExt",        lua_core_GetFileNameWithoutExt},
  {"GetDirectoryPath",             lua_core_GetDirectoryPath},
  {"GetPrevDirectoryPath",         lua_core_GetPrevDirectoryPath},
  {"GetWorkingDirectory",          lua_core_GetWorkingDirectory},
  {"GetDirectoryFiles",            lua_core_GetDirectoryFiles},
  //{"ClearDirectoryFiles",          lua_core_ClearDirectoryFiles}, binding will do it automaticly
  {"ChangeDirectory",              lua_core_ChangeDirectory},
  {"IsFileDropped",                lua_core_IsFileDropped},
  {"GetDroppedFiles",              lua_core_GetDroppedFiles},
  //{"ClearDroppedFiles",            lua_core_ClearDroppedFiles}, binding will do it automaticly
  {"GetFileModTime",               lua_core_GetFileModTime},
  {"GetFileInfo",                  lua_core_GetFileInfo},
  {"CompressData",                 lua_core_CompressData},
  {"DecompressData",               lua_core_DecompressData},
  {"OpenURL",                      lua_core_OpenURL},
  // Persistent storage management
  {"StorageSaveValue",             lua_core_StorageSaveValue},
  {"StorageLoadValue",             lua_core_StorageLoadValue},
  // Input-related functions: keyb
  {"IsKeyPressed",                 lua_core_IsKeyPressed},
  {"IsKeyDown",                    lua_core_IsKeyDown},
  {"IsKeyReleased",                lua_core_IsKeyReleased},
  {"IsKeyUp",                      lua_core_IsKeyUp},
  {"GetKeyPressed",                lua_core_GetKeyPressed},
  {"SetExitKey",                   lua_core_SetExitKey},
  // Input-related functions: gamepads
  {"IsGamepadAvailable",           lua_core_IsGamepadAvailable},
  {"IsGamepadName",                lua_core_IsGamepadName},
  {"GetGamepadName",               lua_core_GetGamepadName},
  {"IsGamepadButtonPressed",       lua_core_IsGamepadButtonPressed},
  {"IsGamepadButtonDown",          lua_core_IsGamepadButtonDown},
  {"IsGamepadButtonReleased",      lua_core_IsGamepadButtonReleased},
  {"IsGamepadButtonUp",            lua_core_IsGamepadButtonUp},
  {"GetGamepadButtonPressed",      lua_core_GetGamepadButtonPressed},
  {"GetGamepadAxisCount",          lua_core_GetGamepadAxisCount},
  {"GetGamepadAxisMovement",       lua_core_GetGamepadAxisMovement},
  // Input-related functions: mouse
  {"IsMouseButtonPressed",         lua_core_IsMouseButtonPressed},
  {"IsMouseButtonDown",            lua_core_IsMouseButtonDown},
  {"IsMouseButtonReleased",        lua_core_IsMouseButtonReleased},
  {"IsMouseButtonUp",              lua_core_IsMouseButtonUp},
  {"GetMouseX",                    lua_core_GetMouseX},
  {"GetMouseY",                    lua_core_GetMouseY},
  {"GetMousePosition",             lua_core_GetMousePosition},
  {"SetMousePosition",             lua_core_SetMousePosition},
  {"SetMouseOffset",               lua_core_SetMouseOffset},
  {"SetMouseScale",                lua_core_SetMouseScale},
  {"GetMouseWheelMove",            lua_core_GetMouseWheelMove},
  // Input-related functions: touch
  {"GetTouchX",                    lua_core_GetTouchX},
  {"GetTouchY",                    lua_core_GetTouchY},
  {"GetTouch",                     lua_core_GetTouch},
  {"GetTouchPosition",             lua_core_GetTouchPosition},
  {"GetTouches",                   lua_core_GetTouches},
  {"SetGesturesEnabled",           lua_core_SetGesturesEnabled},
  {"IsGestureDetected",            lua_core_IsGestureDetected},
  {"GetGestureDetected",           lua_core_GetGestureDetected},
  {"GetTouchPointsCount",          lua_core_GetTouchPointsCount},
  {"GetGestureHoldDuration",       lua_core_GetGestureHoldDuration},
  {"GetGestureDragVector",         lua_core_GetGestureDragVector},
  {"GetGestureDragAngle",          lua_core_GetGestureDragAngle},
  {"GetGesturePinchVector",        lua_core_GetGesturePinchVector},
  {"GetGesturePinchAngle",         lua_core_GetGesturePinchAngle},
  // Camera System Functions (Module: camera)
  {"SetCameraMode",                lua_core_SetCameraMode},
  {"UpdateCamera",                 lua_core_UpdateCamera},
  {"SetCameraPanControl",          lua_core_SetCameraPanControl},
  {"SetCameraAltControl",          lua_core_SetCameraAltControl},
  {"SetCameraSmoothZoomControl",   lua_core_SetCameraSmoothZoomControl},
  {"SetCameraMoveControls",        lua_core_SetCameraMoveControls},

  {NULL, NULL}
};

// SHAPES
// Basic shapes drawing functions
int lua_shapes_DrawPixel(lua_State* L) {
    int x = luaL_checknumber(L, 1);
    int y = luaL_checknumber(L, 2);
    Color* c = (Color*)luaL_checkudata(L, 3, "ray_color");
    DrawPixel(x, y, *c);
    return 0;
}


// Basic shapes collision detection functions

luaL_Reg luaray_shapes[] = {
  {"DrawPixel",         lua_shapes_DrawPixel},
  {NULL, NULL}
};


// TEXTURES
// Image/Texture2D data loading/unloading/saving functions

// Image manipulation functions 

// Image generation functions

// Texture2D configuration functions

// Texture2D drawing functions

luaL_Reg luaray_textures[] = {
  {NULL, NULL}
};


// TEXT

// Font loading/unloading functions

// Text drawing functions
int lua_text_DrawFPS(lua_State *L){
  int x = luaL_checknumber(L, 1);
  int y = luaL_checknumber(L, 2);
  DrawFPS(x, y);
  return 0;
}

int lua_text_DrawText(lua_State *L){
  const char * text = luaL_checkstring(L, 1);
  int x = luaL_checknumber(L, 2);
  int y = luaL_checknumber(L, 3);
  int s = luaL_checknumber(L, 4);
  Color * c = (Color *)luaL_checkudata(L, 5, "ray_color");
  DrawText(text, x, y, s, *c);
  return 0;
}

// Text misc. functions

// Text strings management functions (no utf8 strings, only byte chars)

// UTF8 text strings management functions

luaL_Reg luaray_text[] = {
  {"DrawFPS",  lua_text_DrawFPS},
  {"DrawText", lua_text_DrawText},
  {NULL, NULL}
};


#if defined(_WIN32) || defined(_WIN64)
__declspec(dllexport)
#endif
int luaopen_raylib_luamore(lua_State *L) {
  SetConfigFlags(FLAG_MSAA_4X_HINT);
  lua_newtable(L);
  lua_class_register(L);
  
  lua_pushstring(L, "core");   
    luax_pushfunctable(L, luaray_core); lua_rawset(L, -3);
  lua_pushstring(L, "shapes"); 
    luax_pushfunctable(L, luaray_shapes); lua_rawset(L, -3);
  lua_pushstring(L, "textures"); 
    luax_pushfunctable(L, luaray_textures); lua_rawset(L, -3);
  lua_pushstring(L, "text"); 
    luax_pushfunctable(L, luaray_text); lua_rawset(L, -3);
  
  return 1;
}

