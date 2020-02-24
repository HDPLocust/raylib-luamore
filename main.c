#include "main.h"
#include "classes.h"


/*!MD
# Hello. 
This is Lua binding for raylib.
### All stuff provided by Snooze.

Read the [Core] 
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
Boolean = ray.core.WindowShouldClose()
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
boolean res = ray.core.IsWindowReady()
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
boolean res = ray.core.IsWindowMinimized()
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
boolean res = ray.core.IsWindowResized()
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
boolean res = ray.core.IsWindowHidden()
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
Get window position XY on monitor
See [ray_vector2]
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
Set background color (framebuffer clear color)
See [ray_color]
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
Initialize 2D mode with custom camera (2D)
See [ray_camera2d]
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
Initializes 3D mode with custom camera (3D)
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
Initializes render texture for drawing
See [ray_rendertexture]
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

// Screen-space-related functions

// Timing-related functions

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
  // Timing-related functions
  {NULL, NULL}
};

int lua_shapes_DrawPixel(lua_State *L){
  int x = luaL_checknumber(L, 1);
  int y = luaL_checknumber(L, 2);
  Color * c = (Color *)luaL_checkudata(L, 3, "ray_color");
  DrawPixel(x, y, *c);
  return 0;
}

// SHAPES
// Basic shapes drawing functions

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

