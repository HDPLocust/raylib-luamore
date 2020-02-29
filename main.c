#include "main.h"
#include "classes.h"
#include "enums.h"

/*!MD
## Table of content
| [Core](#Core)                                                 | Core module, provides basic config, window, drawing, color manipulating etc functions.
| :------------------------------------------------------------ | :-----------------------------------------------------------
| **Window-related functions**                                  | 
| [InitWindow](#InitWindow)                                     | Initialize window and OpenGL context
| [WindowShouldClose](#WindowShouldClose)                       | Check if KEY_ESCAPE pressed or Close icon pressed
| [CloseWindow](#CloseWindow)                                   | Close window and unload OpenGL context
| [IsWindowReady](#IsWindowReady)                               | Check if window has been initialized successfully
| [IsWindowMinimized](#IsWindowMinimized)                       | Check if window has been minimized (or lost focus)
| [IsWindowResized](#IsWindowResized)                           | Check if window has been resized
| [IsWindowHidden](#IsWindowHidden)                             | Check if window is currently hidden
| [ToggleFullscreen](#ToggleFullscreen)                         | oggle fullscreen mode (only PLATFORM_DESKTOP)
| [UnhideWindow](#UnhideWindow)                                 | Show the window
| [HideWindow](#HideWindow)                                     | Hide the window
| [SetWindowIcon](#SetWindowIcon)                               | Set icon for window (only PLATFORM_DESKTOP)
| [SetWindowTitle](#SetWindowTitle)                             | Set title for window (only PLATFORM_DESKTOP)
| [SetWindowPosition](#SetWindowPosition)                       | Set window position on screen (only PLATFORM_DESKTOP)
| [SetWindowMonitor](#SetWindowMonitor)                         | Set monitor for the current window (fullscreen mode)
| [SetWindowMinSize](#SetWindowMinSize)                         | Set window minimum dimensions (for FLAG_WINDOW_RESIZABLE)
| [SetWindowSize](#SetWindowSize)                               | Set window dimensions
| [GetWindowHandle](#GetWindowHandle)                           | Get native window handle
| [GetScreenWidth](#GetScreenWidth)                             | Get current screen width
| [GetScreenHeight](#GetScreenHeight)                           | Get current screen height
| [GetScreenDimensions](#GetScreenDimensions)                   | Get current screen dimensions
| [GetMonitorCount](#GetMonitorCount)                           | Get number of connected monitors
| [GetMonitorWidth](#GetMonitorWidth)                           | Get selected monitor width
| [GetMonitorHeight](#GetMonitorHeight)                         | Get selected monitor height
| [GetMonitorDimensions](#GetMonitorDimensions)                 | Get selected monitor dimensions
| [GetMonitorPhysicalWidth](#GetMonitorPhysicalWidth)           | Get selected monitor physical width in millimetres
| [GetMonitorPhysicalHeight](#GetMonitorPhysicalHeight)         | Get selected monitor physical height in millimetres
| [GetMonitorPhysicalDimensions](#GetMonitorPhysicalDimensions) | Get selected monitor physical dimensions in millimetres
| [GetMonitors](#GetMonitors)                                   | Get all currently available monitor stats
| [GetWindowPosition](#GetWindowPosition)                       | Get window position XY on monitor
| [GetMonitorName](#GetMonitorName)                             | Get the human-readable, UTF-8 encoded name of the primary monitor
| [GetClipboardText](#GetClipboardText)                         | Get clipboard text content
| [SetClipboardText](#SetClipboardText)                         | Set clipboard text content
| **Cursor-related functions**                                  | 
| [ShowCursor](#ShowCursor)                                     | Shows cursor
| [HideCursor](#HideCursor)                                     | Hides cursor
| [IsCursorHidden](#IsCursorHidden)                             | Check if cursor is not visible
| [EnableCursor](#EnableCursor)                                 | Enables cursor (unlock cursor)
| [DisableCursor](#DisableCursor)                               | Disables cursor (lock cursor)
| **Drawing-related functions**                                 | 
| [ClearBackground](#ClearBackground)                           | Set background color (framebuffer clear color)
| [BeginDrawing](#BeginDrawing)                                 | Setup canvas (framebuffer) to start drawing
| [EndDrawing](#EndDrawing)                                     | End canvas drawing and swap buffers (double buffering)
| [BeginMode2D](#BeginMode2D)                                   | Initialize 2D mode with custom camera (2D)
| [EndMode2D](#EndMode2D)                                       | Ends 2D mode with custom camera
| [BeginMode3D](#BeginMode3D)                                   | Initializes 3D mode with custom camera (3D)
| [EndMode3D](#EndMode3D)                                       | Ends 3D mode and returns to default 2D orthographic mode
| [BeginTextureMode](#BeginTextureMode)                         | Initializes render texture for drawing
| [EndTextureMode](#EndTextureMode)                             | Ends drawing to render texture
| [BeginScissorMode](#BeginScissorMode)                         | Begin scissor mode (define screen area for following drawing)
| [EndScissorMode](#EndScissorMode)                             | End scissor mode
| **Screen-space-related functions**                            | 
| [GetMouseRay](#GetMouseRay)                                   | Returns a ray trace from mouse position
| [GetCameraMatrix](#GetCameraMatrix)                           | Returns camera transform matrix (view matrix)
| [GetCameraMatrix2D](#GetCameraMatrix2D)                       | Returns camera 2d transform matrix
| [GetWorldToScreen](#GetWorldToScreen)                         | Returns the screen space position for a 3d world space position
| [GetWorldToScreenEx](#GetWorldToScreenEx)                     | Returns size position for a 3d world space position
| [GetWorldToScreen2D](#GetWorldToScreen2D)                     | Returns the screen space position for a 2d camera world space position
| [GetScreenToWorld2D](#GetScreenToWorld2D)                     | Returns the world space position for a 2d camera screen space position
| **Timing-related functions**                                  | 
| [SetTargetFPS](#SetTargetFPS)                                 | Set target FPS (maximum)
| [GetFPS](#GetFPS)                                             | Returns current FPS
| [GetFrameTime](#GetFrameTime)                                 | Returns time in seconds for last frame drawn (delta time)
| [GetTime](#GetTime)                                           | Returns elapsed time in seconds since InitWindow()
| **Color-related functions**                                   | 
| [ColorToInt](#ColorToInt)                                     | Returns hexadecimal value for a Color
| [ColorNormalize](#ColorNormalize)                             | Returns color normalized as float [0..1]
| [ColorFromNormalized](#ColorFromNormalized)                   | Returns color from normalized values [0..1]
| [ColorToHSV](#ColorToHSV)                                     | Returns HSV values for a Color
| [ColorFromHSV](#ColorFromHSV)                                 | Returns a Color from HSV values
| [GetColor](#GetColor)                                         | Returns a Color struct from hexadecimal value
| [Fade](#Fade)                                                 | Color fade-in or fade-out, alpha goes from 0.0f to 1.0f
| **Misc. functions**                                           | 
| [SetConfigFlags](#SetConfigFlags)                             | Setup window configuration flags
| [SetTraceLogLevel](#SetTraceLogLevel)                         | Set the current threshold (minimum) log level
| [SetTraceLogExit](#SetTraceLogExit)                           | Set the exit threshold (minimum) log level
| [SetTraceLogCallback](#SetTraceLogCallback)                   | Set a trace log callback to enable custom logging
| [TraceLog](#TraceLog)                                         | Show trace log messages (DEBUG, INFO, WARNING, ERROR)
| [TakeScreenshot](#TakeScreenshot)                             | Takes a screenshot of current screen (saved a .png)
| [GetRandomValue](#GetRandomValue)                             | Returns a random value between min and max (both included)
| **Files management functions**                                | 
| [FileExists](#FileExists)                                     | Check if file exists
| [IsFileExtension](#IsFileExtension)                           | Check file extension
| [DirectoryExists](#DirectoryExists)                           | Check if a directory path exists
| [GetExtension](#GetExtension)                                 | Get string extension for a filename string
| [GetFileName](#GetFileName)                                   | Get string filename for a path string
| [GetFileNameWithoutExt](#GetFileNameWithoutExt)               | Get filename string without extension
| [GetDirectoryPath](#GetDirectoryPath)                         | Get full path for a given fileName with path
| [GetPrevDirectoryPath](#GetPrevDirectoryPath)                 | Get previous directory path for a given path
| [GetWorkingDirectory](#GetWorkingDirectory)                   | Get current working directory
| [GetDirectoryFiles](#GetDirectoryFiles)                       | Get filenames in a directory path
| [ClearDirectoryFiles](#ClearDirectoryFiles)                   | Clear directory files paths buffers (deprecated)
| [ChangeDirectory](#ChangeDirectory)                           | Change working directory, returns true if success
| [IsFileDropped](#IsFileDropped)                               | Check if a file has been dropped into window
| [GetDroppedFiles](#GetDroppedFiles)                           | Get dropped files names
| [ClearDroppedFiles](#ClearDroppedFiles)                       | Clear dropped files paths buffer
| [GetFileModTime](#GetFileModTime)                             | Get file modification time (last write time)
| [GetFileInfo](#GetFileInfo)                                   | Get info table for a given path
| [CompressData](#CompressData)                                 | Compress data (DEFLATE algorythm)
| [DecompressData](#DecompressData)                             | Decompress data (DEFLATE algorythm)
| [OpenURL](#OpenURL)                                           | Open URL with default system browser (if available)
| **Persistent storage management**                             | 
| [StorageSaveValue](#StorageSaveValue)                         | Save integer value to storage file (to defined position)
| [StorageLoadValue](#StorageLoadValue)                         | Load integer value from storage file (from defined position)
| **Input-related functions: keyboard**                         | 
| [IsKeyPressed](#IsKeyPressed)                                 | Detect if a key has been pressed once
| [IsKeyDown](#IsKeyDown)                                       | Detect if a key is being pressed
| [IsKeyReleased](#IsKeyReleased)                               | Detect if a key has been released once
| [IsKeyUp](#IsKeyUp)                                           | Detect if a key is NOT being pressed
| [GetKeyPressed](#GetKeyPressed)                               | Get latest key pressed (scancode)
| [GetKeyPressedString](#GetKeyPressedString)                   | Get latest key pressed (UTF-8 encoded)
| [GetAllKeysPressedString](#GetAllKeysPressedString)           | Get all latest keys pressed (UTF-8 encoded)
| [SetExitKey](#SetExitKey)                                     | Set a custom key to exit program (default is ESC)
| **Input-related functions: gamepads**                         | 
| [IsGamepadAvailable](#IsGamepadAvailable)                     | Detect if a gamepad is available
| [IsGamepadName](#IsGamepadName)                               | Check gamepad name (if available)
| [GetGamepadName](#GetGamepadName)                             | Return gamepad internal name id
| [IsGamepadButtonPressed](#IsGamepadButtonPressed)             | Detect if a gamepad button has been pressed once
| [IsGamepadButtonDown](#IsGamepadButtonDown)                   | Detect if a gamepad button is being pressed
| [IsGamepadButtonReleased](#IsGamepadButtonReleased)           | Detect if a gamepad button has been released once
| [IsGamepadButtonUp](#IsGamepadButtonUp)                       | Detect if a gamepad button is NOT being pressed
| [GetGamepadButtonPressed](#GetGamepadButtonPressed)           | Get the last gamepad button pressed
| [GetGamepadAxisCount](#GetGamepadAxisCount)                   | Return gamepad axis count for a gamepad
| [GetGamepadAxisMovement](#GetGamepadAxisMovement)             | Return axis movement value for a gamepad axis
| **Input-related functions: mouse**                            | 
| [IsMouseButtonPressed](#IsMouseButtonPressed)                 | Detect if a mouse button has been pressed once
| [IsMouseButtonDown](#IsMouseButtonDown)                       | Detect if a mouse button is being pressed
| [IsMouseButtonReleased](#IsMouseButtonReleased)               | Detect if a mouse button has been released once
| [IsMouseButtonUp](#IsMouseButtonUp)                           | Detect if a mouse button is NOT being pressed
| [GetMouseX](#GetMouseX)                                       | Returns mouse position X
| [GetMouseY](#GetMouseY)                                       | Returns mouse position Y
| [GetMousePosition](#GetMousePosition)                         | Returns mouse position XY
| [SetMousePosition](#SetMousePosition)                         | Set mouse position XY
| [SetMouseOffset](#SetMouseOffset)                             | Set mouse offset
| [SetMouseScale](#SetMouseScale)                               | Set mouse scaling
| [GetMouseWheelMove](#GetMouseWheelMove)                       | Returns mouse wheel movement Y
| **Input-related functions: touch**                            | 
| [GetTouchX](#GetTouchX)                                       | Returns touch position X for touch point 1 (relative to screen size)
| [GetTouchY](#GetTouchY)                                       | Returns touch position Y for touch point 1 (relative to screen size)
| [GetTouch](#GetTouch)                                         | Returns touch position XY for touch point 1 (relative to screen size)
| [GetTouchPosition](#GetTouchPosition)                         | Returns touch position XY for a touch point index (relative to screen size)
| [GetTouches](#GetTouches)                                     | Returns all available touches positions XY (relative to screen size)
| [SetGesturesEnabled](#SetGesturesEnabled)                     | Enable a set of gestures using flags
| [IsGestureDetected](#IsGestureDetected)                       | Check if a gesture have been detected
| [GetGestureDetected](#GetGestureDetected)                     | Get latest detected gesture
| [GetTouchPointsCount](#GetTouchPointsCount)                   | Get touch points count
| [GetGestureHoldDuration](#GetGestureHoldDuration)             | Get gesture hold time in milliseconds
| [GetGestureDragVector](#GetGestureDragVector)                 | Get gesture drag vector
| [GetGestureDragAngle](#GetGestureDragAngle)                   | Get gesture drag angle
| [GetGesturePinchVector](#GetGesturePinchVector)               | Get gesture pinch delta
| [GetGesturePinchAngle](#GetGesturePinchAngle)                 | Get gesture pinch angle
| **Camera System Functions**                                   | 
| [SetCameraMode](#SetCameraMode)                               | Set camera mode (multiple camera modes available)
| [UpdateCamera](#UpdateCamera)                                 | Update camera position for selected mode
| [SetCameraPanControl](#SetCameraPanControl)                   | Set camera pan key to combine with mouse movement (free camera)
| [SetCameraAltControl](#SetCameraAltControl)                   | Set camera alt key to combine with mouse movement (free camera)
| [SetCameraSmoothZoomControl](#SetCameraSmoothZoomControl)     | Set camera smooth zoom key to combine with mouse (free camera)
| [SetCameraMoveControls](#SetCameraMoveControls)               | Set camera move controls (1st person and 3rd person cameras)


| [Shapes](#Shapes)     | Description
| :-------------------- | :------------
|  --                   | --

| [Textures](#Textures) | Description
| :-------------------- | :------------
|  --                   | --

| [Text](#Text)         | Description
| :-------------------- | :------------
|  --                   | --


| [Models](#Models)     | Description
| :-------------------- | :------------
|  --                   | --

| [Shaders](#Shaders)   | Description
| :-------------------- | :------------
|  --                   | --


| [Audio](#Audio)       | Description
| :-------------------- | :------------
|  --                   | --

| [Classes](#Classes)               | Description
| :--------------------             | :------------
| [Vector2](#Vector2)               | Vector2 type
| [Vector3](#Vector3)               | Vector3 type
| [Vector4](#Vector4)               | Vector4 (Quaternion) type
| [Matrix](#Matrix)                 | Matrix type (OpenGL style 4x4)
| [Color](#Color)                   | Color type, RGBA (32bit)
| [Rectangle](#Rectangle)           | Rectangle type
| [Image](#Image)                   | Image type (multiple pixel formats supported), stored in CPU memory (RAM)
| [Texture](#Texture)               | Texture type (multiple internal formats supported), stored in GPU memory (VRAM)
| [RenderTexture](#RenderTexture)   | RenderTexture type, for texture rendering
| [NPatchInfo](#NPatchInfo)         | N-Patch layout info
| [CharInfo](#CharInfo)             | Font character info
| [Font](#Font)                     | Font type, includes texture and chars data
| [Camera](#Camera3D)               | Camera3D type, defines 3d camera position/orientation
| [Camera2D](#Camera2D)             | Camera2D type, defines a 2d camera
| [Mesh](#Mesh)                     | Vertex data definning a mesh
| [Shader](#Shader)                 | Shader type (generic shader)
| [MaterialMap](#MaterialMap)       | Material texture map
| [Material](#Material)             | Material type
| [Model](#Model)                   | Basic 3d Model type
| [Transform](#Transform)           | Transformation (used for bones)
| [BoneInfo](#BoneInfo)             | Bone information
| [ModelAnimation](#ModelAnimation) | Model animation data (bones and frames)
| [Ray](#Ray)                       | Ray type (useful for raycast)
| [RayHitInfo](#RayHitInfo)         | Raycast hit information
| [BoundingBox](#BoundingBox)       | Bounding box type for 3d mesh
| [Wave](#Wave)                     | Wave type, defines audio wave data
| [Sound](#Sound)                   | Basic Sound source and buffer
| [Music](#Music)                   | Music type (file streaming from memory)
| [AudioStream](#AudioStream)       | Raw audio stream type
| [VrDeviceInfo](#VrDeviceInfo)     | VR device parameters

*/

// Modules
/*!MD
## Core
### Core functions

#### Initialization
```lua
local rl = require("raylib_luamore")
```
*/

/*!MD
### Window-related functions:
#### InitWindow
```lua
rl.core.InitWindow(integer Width, integer Height, string Title)
```
Initialize window and OpenGL context
Should be called before any widnow stuff is used.
* Default Width is 800
* Default Height is 600
* Default Title is "Untitled"
*/
int lua_core_InitWindow(lua_State *L){
  int w = luax_optnumber(L, 1, 800);
  int h = luax_optnumber(L, 2, 600);
  const char * title = luax_optstring(L, 3, "Untitled");
  InitWindow(w, h, title);
  return 0;
}

/*!MD
#### WindowShouldClose
```lua
boolean Status = rl.core.WindowShouldClose()
```
Check if ESCAPE-key pressed or Close icon pressed.
See [SetExitKey](#SetExitKey).
*/
int lua_core_WindowShouldClose(lua_State *L){
  lua_pushboolean(L, WindowShouldClose());
  return 1;
}

/*!MD
#### CloseWindow
```lua
rl.core.CloseWindow()
```
Close window and unload OpenGL context.
*/
int lua_core_CloseWindow(lua_State *L){
  CloseWindow();
  return 0;
}

/*!MD
#### IsWindowReady
```lua
boolean Status = rl.core.IsWindowReady()
```
Check if window has been initialized successfully.
*/
int lua_core_IsWindowReady(lua_State *L){
  lua_pushboolean(L, IsWindowReady());
  return 1;
}

/*!MD
#### IsWindowMinimized
```lua
boolean Status = rl.core.IsWindowMinimized()
```
Check if window has been minimized (or lost focus).
*/
int lua_core_IsWindowMinimized(lua_State *L){
  lua_pushboolean(L, IsWindowMinimized());
  return 1;
}

/*!MD
#### IsWindowResized
```lua
boolean Status = rl.core.IsWindowResized()
```
Check if window has been resized.
*/
int lua_core_IsWindowResized(lua_State *L){
  lua_pushboolean(L, IsWindowResized());
  return 1;
}

/*!MD
#### IsWindowHidden
```lua
boolean Status = rl.core.IsWindowHidden()
```
Check if window is currently hidden.
*/
int lua_core_IsWindowHidden(lua_State *L){
  lua_pushboolean(L, IsWindowHidden());
  return 1;
}

/*!MD
#### ToggleFullscreen
```lua
rl.core.ToggleFullscreen()
```
Toggle fullscreen mode (only PLATFORM_DESKTOP).
*/
int lua_core_ToggleFullscreen(lua_State *L){
  ToggleFullscreen();
  return 0;
}

/*!MD
#### UnhideWindow
```lua
rl.core.UnhideWindow()
```
Show the window.
*/
int lua_core_UnhideWindow(lua_State *L){
  UnhideWindow();
  return 0;
}

/*!MD
#### HideWindow
```lua
rl.core.HideWindow()
```
Hide the window.
*/
int lua_core_HideWindow(lua_State *L){
  HideWindow();
  return 0;
}

/*!MD
#### SetWindowIcon
```lua
rl.core.SetWindowIcon(Image Icon)
```
Set icon for window (only PLATFORM_DESKTOP).
See [Image](#Image).
*/
int lua_core_SetWindowIcon(lua_State *L){
  Image* i = (Image*)luaL_checkudata(L, 1, "Image");
  SetWindowIcon(*i);
  return 0;
}

/*!MD
#### SetWindowTitle
```lua
rl.core.SetWindowTitle(string Title)
```
Set title for window (only PLATFORM_DESKTOP).
*/
int lua_core_SetWindowTitle(lua_State *L){
  SetWindowTitle(luaL_checkstring(L, 1));
  return 0;
}

/*!MD
#### SetWindowPosition
```lua
rl.core.SetWindowPosition(string Title)
```
Set window position on screen (only PLATFORM_DESKTOP).
*/
int lua_core_SetWindowPosition(lua_State *L){
  SetWindowPosition(luaL_checkinteger(L, 1), luaL_checkinteger(L, 2));
  return 0;
}

/*!MD
#### SetWindowMonitor
```lua
rl.core.SetWindowMonitor(integer Monitor)
```
Set monitor for the current window (fullscreen mode).
*/
int lua_core_SetWindowMonitor(lua_State *L){
  SetWindowMonitor(luaL_checkinteger(L, 1) - 1);
  return 0;
}

/*!MD
#### SetWindowMinSize
```lua
rl.core.SetWindowMinSize(integer Width, integer Height)
```
Set window minimum dimensions, for flag ["WINDOW_RESIZABLE"](#SetConfigFlags).
*/
int lua_core_SetWindowMinSize(lua_State *L){
  SetWindowMinSize(luaL_checkinteger(L, 1), luaL_checkinteger(L, 2));
  return 0;
}

/*!MD
#### SetWindowSize
```lua
rl.core.SetWindowSize(integer Width, integer Height)
```
Set window dimensions.
*/
int lua_core_SetWindowSize(lua_State *L){
  SetWindowSize(luaL_checkinteger(L, 1), luaL_checkinteger(L, 2));
  return 0;
}

/*!MD
#### GetWindowHandle
```lua
userdata Handle = rl.core.GetWindowHandle()
```
Get native window handle.
Use for FFI or something.
*/
int lua_core_GetWindowHandle(lua_State *L){
  void* h = GetWindowHandle();
  lua_pushlightuserdata(L, h);
  return 1;
}

/*!MD
#### GetScreenWidth
```lua
integer Width = rl.core.GetScreenWidth()
```
Get current screen width.
*/
int lua_core_GetScreenWidth(lua_State *L){
  lua_pushnumber(L, GetScreenWidth());
  return 1;
}

/*!MD
#### GetScreenHeight
```lua
integer Height = rl.core.GetScreenHeight()
```
Get current screen height.
*/
int lua_core_GetScreenHeight(lua_State *L){
  lua_pushnumber(L, GetScreenHeight());
  return 1;
}

/*!MD
#### GetScreenDimensions
```lua
integer Width, integer Height = rl.core.GetScreenDimensions()
```
Get current screen dimensions.
*/
int lua_core_GetScreenDimensions(lua_State *L){
  lua_pushnumber(L, GetScreenWidth());
  lua_pushnumber(L, GetScreenHeight());
  return 2;
}

/*!MD
#### GetMonitorCount
```lua
integer Count = rl.core.GetMonitorCount()
```
Get number of connected monitors.
*/
int lua_core_GetMonitorCount(lua_State *L){
  lua_pushnumber(L, GetMonitorCount());
  return 1;
}

/*!MD
#### GetMonitorWidth
```lua
integer Width = rl.core.GetMonitorWidth(integer Monitor)
```
Get selected monitor width.
*/
int lua_core_GetMonitorWidth(lua_State *L){
  lua_pushnumber(L, GetMonitorWidth(luaL_checkinteger(L, 1) + 1));
  return 1;
}

/*!MD
#### GetMonitorHeight
```lua
integer Height = rl.core.GetMonitorHeight(integer Monitor)
```
Get selected monitor height.
*/
int lua_core_GetMonitorHeight(lua_State *L){
  lua_pushnumber(L, GetMonitorHeight(luaL_checkinteger(L, 1) + 1));
  return 1;
}

/*!MD
#### GetMonitorDimensions
```lua
integer Width, integer Height = rl.core.GetMonitorDimensions(integer Monitor)
```
Get selected monitor dimensions.
*/
int lua_core_GetMonitorDimensions(lua_State *L){
  lua_pushnumber(L,  GetMonitorWidth(luaL_checkinteger(L, 1) + 1));
  lua_pushnumber(L, GetMonitorHeight(luaL_checkinteger(L, 1) + 1));
  return 2;
}

/*!MD
#### GetMonitorPhysicalWidth
```lua
integer Width = rl.core.GetMonitorPhysicalWidth(integer Monitor)
```
Get selected monitor physical width in millimetres.
*/
int lua_core_GetMonitorPhysicalWidth(lua_State *L){
  lua_pushnumber(L, GetMonitorPhysicalWidth(luaL_checkinteger(L, 1) + 1));
  return 1;
}

/*!MD
#### GetMonitorPhysicalHeight
```lua
integer Height = rl.core.GetMonitorPhysicalHeight(integer Monitor)
```
Get selected monitor physical height in millimetres.
*/
int lua_core_GetMonitorPhysicalHeight(lua_State *L){
  lua_pushnumber(L, GetMonitorPhysicalHeight(luaL_checkinteger(L, 1) + 1));
  return 1;
}

/*!MD
#### GetMonitorPhysicalDimensions
```lua
integer Width, integer Height = rl.core.GetMonitorPhysicalDimensions(integer Monitor)
```
Get selected monitor physical dimensions in millimetres.
*/
int lua_core_GetMonitorPhysicalDimensions(lua_State *L){
  lua_pushnumber(L, GetMonitorPhysicalWidth(luaL_checkinteger(L, 1)  + 1));
  lua_pushnumber(L, GetMonitorPhysicalHeight(luaL_checkinteger(L, 1) + 1));
  return 2;
}

/*!MD
#### GetMonitors
```lua
table Monitors = rl.core.GetMonitors()
```
Get all monitors and it's stats, using this layout:
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
Vector2 Position = rl.core.GetWindowPosition()
```
Get window position XY on monitor.
See [Vector2](#Vector2).
*/
int lua_core_GetWindowPosition(lua_State *L){
  Vector2 * v = luax_newobject(L, "Vector2", sizeof(Vector2));
  *v = GetWindowPosition();
  return 1;
}

/*!MD
#### GetMonitorName
```lua
string Name = rl.core.GetMonitorName()
```
Get the human-readable, UTF-8 encoded name of the primary monitor.
*/
int lua_core_GetMonitorName(lua_State *L){
  lua_pushstring(L, GetMonitorName(luaL_checkinteger(L, 1)));
  return 1;
}

/*!MD
#### GetClipboardText
```lua
string Text = rl.core.GetClipboardText()
```
Get clipboard text content.
*/
int lua_core_GetClipboardText(lua_State *L){
  lua_pushstring(L, GetClipboardText());
  return 1;
}

/*!MD
#### SetClipboardText
```lua
rl.core.SetClipboardText(string Text)
```
Set clipboard text content.
*/
int lua_core_SetClipboardText(lua_State *L){
  SetClipboardText(luaL_checkstring(L, 1));
  return 0;
}

/*!MD
### Cursor-related functions
#### ShowCursor
```lua
rl.core.ShowCursor()
```
Shows cursor.
*/
int lua_core_ShowCursor(lua_State* L) {
  ShowCursor();
  return 0;
}

/*!MD
#### HideCursor
```lua
rl.core.HideCursor()
```
Hides cursor.
*/
int lua_core_HideCursor(lua_State* L) {
  HideCursor();
  return 0;
}

/*!MD
#### IsCursorHidden
```lua
boolean Status = rl.core.IsCursorHidden()
```
Check if cursor is not visible.
*/
int lua_core_IsCursorHidden(lua_State* L) {
  lua_pushboolean(L, IsCursorHidden());
  return 1;
}

/*!MD
#### EnableCursor
```lua
rl.core.EnableCursor()
```
Enables cursor (unlock cursor).
*/
int lua_core_EnableCursor(lua_State* L) {
  EnableCursor();
  return 0;
}

/*!MD
#### DisableCursor
```lua
rl.core.DisableCursor()
```
Disables cursor (lock cursor).
*/
int lua_core_DisableCursor(lua_State* L) {
  DisableCursor();
  return 0;
}

/*!MD
### Drawing-related functions
#### ClearBackground
```lua
rl.core.ClearBackground(Color Color)
```
Set background color (framebuffer clear color).
See [Color](#Color).
*/
int lua_core_ClearBackground(lua_State *L){
  Color * c = luaL_checkudata(L, 1, "Color");
  ClearBackground(*c);
  return 0;
}

/*!MD
#### BeginDrawing
```lua
rl.core.BeginDrawing()
```
Setup canvas (framebuffer) to start drawing.
*/
int lua_core_BeginDrawing(lua_State *L){
  BeginDrawing();
  return 0;
}

/*!MD
#### EndDrawing
```lua
rl.core.EndDrawing()
```
End canvas drawing and swap buffers (double buffering).
*/
int lua_core_EndDrawing(lua_State *L){
  EndDrawing();
  return 0;
}

/*!MD
#### BeginMode2D
```lua
rl.core.BeginMode2D(Camera2D Camera)
```
Initialize 2D mode with custom camera (2D).
See [Camera2D](#Camera2D).
*/
int lua_core_BeginMode2D(lua_State *L){
  Camera2D * c = luaL_checkudata(L, 1, "Camera2D");
  BeginMode2D(*c);
  return 0;
}

/*!MD
#### EndMode2D
```lua
rl.core.EndMode2D()
```
Ends 2D mode with custom camera.
*/
int lua_core_EndMode2D(lua_State *L){
  EndMode2D();
  return 0;
}

/*!MD
#### BeginMode3D
```lua
rl.core.BeginMode3D(Camera3D Camera)
```
Initializes 3D mode with custom camera (3D).
See [Camera3D](#Camera3D).
*/
int lua_core_BeginMode3D(lua_State *L){
  Camera3D * c = luaL_checkudata(L, 1, "Camera3D");
  BeginMode3D(*c);
  return 0;
}

/*!MD
#### EndMode3D
```lua
rl.core.EndMode3D()
```
Ends 3D mode and returns to default 2D orthographic mode.
*/
int lua_core_EndMode3D(lua_State *L){
  EndMode3D();
  return 0;
}

/*!MD
#### BeginTextureMode
```lua
rl.core.BeginTextureMode(RenderTexture Texture)
```
Initializes render texture for drawing.
See [RenderTexture](#RenderTexture).
*/
int lua_core_BeginTextureMode(lua_State *L){
  RenderTexture2D  * t = luaL_checkudata(L, 1, "RenderTexture");
  BeginTextureMode(*t);
  return 0;
}

/*!MD
#### EndTextureMode
```lua
rl.core.EndTextureMode()
```
Ends drawing to render texture.
*/
int lua_core_EndTextureMode(lua_State *L){
  EndTextureMode();
  return 0;
}

/*!MD
#### BeginScissorMode
```lua
rl.core.BeginScissorMode(integer X, integer Y, integer Width, integer Height)
```
Begin scissor mode (define screen area for following drawing).
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
rl.core.EndScissorMode()
```
End scissor mode.
*/
int lua_core_EndScissorMode(lua_State *L){
  EndScissorMode();
  return 0;
}

/*!MD
### Screen-space-related functions
#### GetMouseRay
```lua
-- variants
Ray Ray = rl.core.GetMouseRay(Vector2 Vector, Camera3D Camera)
Vector2 Position, Vector2 Direction = rl.core.GetMouseRay(Vector2 Vector, Camera3D Camera, "v")
```
Returns a ray trace from mouse position.
See [Ray](#Ray), [Vector2](#Vector2).
*/
int lua_core_GetMouseRay(lua_State *L){
  Vector2  * v = luaL_checkudata(L, 1, "Vector2");
  Camera3D * c = luaL_checkudata(L, 2, "Camera3D");
  if (lua_isstring(L, 3) && luaL_checkstring(L, 3)[0] == 'v') {
    Ray r = GetMouseRay(*v, *c);
    Vector3 * position  = luax_newobject(L, "Vector3", sizeof(Vector3));
    Vector3 * direction = luax_newobject(L, "Vector3", sizeof(Vector3));
    *position  = r.position;
    *direction = r.direction;
    return 2;
  }

  Ray * r = luax_newobject(L, "Ray", sizeof(Ray));
  *r = GetMouseRay(*v, *c);
  return 1;
}

/*!MD
#### GetCameraMatrix
```lua
Matrix View = rl.core.GetCameraMatrix(Camera3D Camera)
```
Returns camera transform matrix (view matrix).
See [Matrix](#Matrix).
*/
int lua_core_GetCameraMatrix(lua_State *L){
  Camera3D * c = luaL_checkudata(L, 1, "Camera3D");
  Matrix * m   = luax_newobject(L, "Matrix", sizeof(Matrix));
  *m = GetCameraMatrix(*c);
  return 1;
}

/*!MD
#### GetCameraMatrix2D
```lua
Matrix View = rl.core.GetCameraMatrix2D(Camera2D Camera)
```
Returns camera 2d transform matrix.
See [Matrix](#Matrix), [Camera2D](#Camera2D).
*/
int lua_core_GetCameraMatrix2D(lua_State *L){
  Camera2D * c = luaL_checkudata(L, 1, "Camera2D");
  Matrix   * m = luax_newobject(L, "Matrix", sizeof(Matrix));
  *m = GetCameraMatrix2D(*c);
  return 1;
}
/*!MD
#### GetWorldToScreen
```lua
Vector2 ScreenV = Matrix rl.core.GetWorldToScreen(Vector3 Vector, Camera3D Camera)
```
Returns the screen space position for a 3d world space position.
See [Vector2](#Vector2), [Vector3](#Vector3), [Camera3D](#Camera3D).
*/
int lua_core_GetWorldToScreen(lua_State *L){
  Vector3  * v = luaL_checkudata(L, 1, "Vector3");
  Camera3D * c = luaL_checkudata(L, 2, "Camera3D");
  Vector2 * p  = luax_newobject(L, "Vector2", sizeof(Vector2));
  *p = GetWorldToScreen(*v, *c);
  return 1;
}

/*!MD
#### GetWorldToScreenEx
```lua
Vector2 ScreenV = Matrix rl.core.GetWorldToScreenEx(Vector3 Vector, Camera3D Camera, integer Width, integer Height)
```
Returns size position for a 3d world space position.
See [Vector2](#Vector2), [Vector3](#Vector3), [Camera3D](#Camera3D).
*/
int lua_core_GetWorldToScreenEx(lua_State *L){
  Vector3  * v = luaL_checkudata(L, 1, "Vector3");
  Camera3D * c = luaL_checkudata(L, 2, "Camera3D");
  int w = luaL_checkinteger(L, 3);
  int h = luaL_checkinteger(L, 4);
  Vector2 * p  = luax_newobject(L, "Vector2", sizeof(Vector2));
  *p = GetWorldToScreenEx(*v, *c, w, h);
  return 1;
}

/*!MD
#### GetWorldToScreen2D
```lua
Vector2 ScreenV = Matrix rl.core.GetWorldToScreen2D(Vector2 Vector, Camera2D Camera)
```
Returns the screen space position for a 2d camera world space position.
See [Vector2](#Vector2), [Camera2D](#Camera2D).
*/
int lua_core_GetWorldToScreen2D(lua_State *L){
  Vector2  * v = luaL_checkudata(L, 1, "Vector2");
  Camera2D * c = luaL_checkudata(L, 2, "Camera2D");
  Vector2  * p = luax_newobject(L, "Vector2", sizeof(Vector2));
  *p = GetWorldToScreen2D(*v, *c);
  return 1;
}

/*!MD
#### GetScreenToWorld2D
```lua
Vector2 ScreenV = Matrix rl.core.GetScreenToWorld2D(Vector2 Vector, Camera2D Camera)
```
Returns the world space position for a 2d camera screen space position.
See [Vector2](#Vector2), [Camera2D](#Camera2D).
*/
int lua_core_GetScreenToWorld2D(lua_State *L){
  Vector2  * v = luaL_checkudata(L, 1, "Vector2");
  Camera2D * c = luaL_checkudata(L, 2, "Camera2D");
  Vector2 *  p = luax_newobject(L, "Vector2", sizeof(Vector2));
  *p = GetScreenToWorld2D(*v, *c);
  return 1;
}

/*!MD
### Timing-related functions
#### SetTargetFPS
```lua
rl.core.SetTargetFPS(integer FPS)
```
Set target FPS (maximum).
*/
int lua_core_SetTargetFPS(lua_State *L){
  int fps = luaL_checkinteger(L, 1);
  SetTargetFPS(fps);
  return 0;
}

/*!MD
#### GetFPS
```lua
integer FPS = Matrix rl.core.GetFPS()
```
Returns current FPS.
*/
int lua_core_GetFPS(lua_State *L){
  lua_pushinteger(L, GetFPS());
  return 1;
}

/*!MD
#### GetFrameTime
```lua
float DT = Matrix rl.core.GetFrameTime()
```
Returns time in seconds for last frame drawn.
*/
int lua_core_GetFrameTime(lua_State *L){
  lua_pushnumber(L, GetFrameTime());
  return 1;
}

/*!MD
#### GetTime
```lua
float Time = Matrix rl.core.GetTime()
```
Returns elapsed time in seconds since InitWindow().
*/
int lua_core_GetTime(lua_State *L){
  lua_pushnumber(L, GetTime());
  return 1;
}

/*!MD
### Color-related functions
#### ColorToInt
```lua
integer iColor = rl.core.ColorToInt(Color Color)
```
Returns hexadecimal value for a Color.
*/
int lua_core_ColorToInt(lua_State *L){
  Color * c = luaL_checkudata(L, 1, "Color");
  lua_pushnumber(L, ColorToInt(*c));
  return 1;
}

/*!MD
#### ColorNormalize
```lua
-- variants
Vector4 vColor = rl.core.ColorNormalize(Color Color)
integer NR, integer NG, integer NB, integer NA = rl.core.ColorNormalize(Color Color, "n")
table tColor = rl.core.ColorNormalize(Color Color, "t") -- Array {float r, float g, float b, float a}
```
Returns color normalized as float [0..1].
See [Vector4](#Vector4), [Color](#Color).
*/
int lua_core_ColorNormalize(lua_State *L){
  Color   * c = luaL_checkudata(L, 1, "Color");
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

  Vector4 * res = luax_newobject(L, "Vector4", sizeof(Vector4));
  *res = v;
  return 1;
}

/*!MD
#### ColorFromNormalized
```lua
-- variants
Color Color = rl.core.ColorFromNormalized(Vector4 vColor)
Color Color = rl.core.ColorFromNormalized(float R, float G, float B[, float A])
Color Color = rl.core.ColorFromNormalized(table tColor) -- Array {float r, float g, float b[, float a]}
```
Returns color from normalized values [0..1].
See [Vector4](#Vector4), [Color](#Color).
*/
int lua_core_ColorFromNormalized(lua_State *L){
  Color * c = luax_newobject(L, "Color", sizeof(Color));
  if (luax_checkclass(L, 1, "Vector4")) {
    Vector4 * v = luaL_checkudata(L, 1, "Vector4");
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
  return luaL_typerror(L, 1, "Vector4 or table or number");
}

/*!MD
#### ColorToHSV
```lua
-- variants
Vector3 vColor = rl.core.ColorToHSV(Color Color)
float Hue, float Saturation, float Value = rl.core.ColorToHSV(Color Color, "n")
table hsvColor = rl.core.ColorNormalize(Color Color, "t") -- Array {float h, float s, float v}
```
Returns HSV values for a Color.
See [Vector3](#Vector3), [Color](#Color).
*/
int lua_core_ColorToHSV(lua_State *L){
  Color   * c = luaL_checkudata(L, 1, "Color");
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

  Vector3 * res = luax_newobject(L, "Vector3", sizeof(Vector3));
  *res = v;
  return 1;
}

/*!MD
#### ColorFromHSV
```lua
-- variants
Color Color = rl.core.ColorFromHSV(Vector3 vColor)
Color Color = rl.core.ColorFromHSV(float H, float S, float V)
Color Color = rl.core.ColorFromHSV(table hsvColor) -- Array {float h, float s, float v}
```
Returns a Color from HSV values.
See [Vector3](#Vector3), [Color](#Color).
*/
int lua_core_ColorFromHSV(lua_State *L){
  Color   * c = luax_newobject(L, "Color", sizeof(Color));
  if (luax_checkclass(L, 1, "Vector3")) {
    Vector3 * v = luaL_checkudata(L, 1, "Vector3");
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
  return luaL_typerror(L, 1, "Vector3 or table or number");
}

/*!MD
#### GetColor
```lua
-- variants
Color Color = rl.core.GetColor(integer hColor)
```
Returns a Color struct from hexadecimal value.
See [Color](#Color)
*/
int lua_core_GetColor(lua_State *L){
  int hex = luaL_checkinteger(L, 1);
  Color * c = luax_newobject(L, "Color", sizeof(Color));
  *c = GetColor(hex);
  return 1;
}

/*!MD
#### Fade
```lua
-- variants
Color fColor = rl.core.Fade(Color Color, float alpha)
```
Color fade-in or fade-out, alpha goes from 0.0f to 1.0f.
See [Color](#Color)
*/
int lua_core_Fade(lua_State *L){
  Color * c = luaL_checkudata(L, 1, "Color");
  float   a = luaL_checknumber(L, 2);
  Color * r = luax_newobject(L, "Color", sizeof(Color));
  *r = Fade(*c, a);
  return 1;
}

/*!MD
### Misc. functions
#### SetConfigFlags
```lua
rl.core.SetConfigFlags(string flag1, string flag2, string flag3, ...)
```
Setup window configuration flags
| Available flags:       | Description
| :--------------------- | :-------------
| `"FULLSCREEN_MODE"`    | Set to run program in fullscreen
| `"WINDOW_RESIZABLE"`   | Set to allow resizable window
| `"WINDOW_UNDECORATED"` | Set to disable window decoration (frame and buttons)
| `"WINDOW_TRANSPARENT"` | Set to allow transparent window
| `"WINDOW_HIDDEN"`      | Set to create the window initially hidden
| `"WINDOW_ALWAYS_RUN"`  | Set to allow windows running while minimized
| `"MSAA_4X_HINT"`       | Set to try enabling MSAA 4X
| `"VSYNC_HINT"`         | Set to try enabling V-Sync on GPU
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

/*!MD
#### SetTraceLogLevel
```lua
rl.core.SetTraceLogLevel(string Mode)
```
Set the current threshold (minimum) log level.

| Mode       | Description                              |
| :--------- | :--------------------------------------- |
|`"ALL"`     | Trace all logging messages               |
|`"TRACE"`   | Trace TRACE   and upper logging messages |
|`"DEBUG"`   | Trace DEBUG   and upper logging messages |
|`"INFO"`    | Trace INFO    and upper logging messages |
|`"WARNING"` | Trace WARNING and upper logging messages |
|`"ERROR"`   | Trace ERROR   and upper logging messages |
|`"FATAL"`   | Trace FATAL   and upper logging messages |
|`"NONE"`    | Trace no logging messages                |
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

/*!MD
#### SetTraceLogExit
```lua
rl.core.SetTraceLogExit(string Mode)
```
Set the exit threshold (minimum) log level.

| Mode       | Description                               |
| :--------- | :---------------------------------------- |
|`"ALL"`     | Exit on any logging message               |
|`"TRACE"`   | Exit on TRACE   and upper logging message |
|`"DEBUG"`   | Exit on DEBUG   and upper logging message |
|`"INFO"`    | Exit on INFO    and upper logging message |
|`"WARNING"` | Exit on WARNING and upper logging message |
|`"ERROR"`   | Exit on ERROR   and upper logging message |
|`"FATAL"`   | Exit on FATAL   and upper logging message |
|`"NONE"`    | No exit on logging messages               |
*/
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


/*!MD
#### SetTraceLogCallback
```lua
rl.core.SetTraceLogCallback(function Log)
```
Set a trace log callback to enable custom logging. Log function example:
```lua
function Log(string logLevel, string Message)
  local time = os.date("%H.%M.%S", os.time())
  print(time .. " " .. logLevel .. ': ' .. Message)
end
```
logLevel is string constant
`"TRACE"`, `"DEBUG"`, `"INFO"`, `"WARNING"`,
`"ERROR"` or `"FATAL"`.
*/

lua_State * _lua_state;      // keeping lua_State that called SetTraceLogCallback
int         _lua_trace_ref;  // and reference to callback function

// This function will be called by C, and it should call Lua function.
void _lua_callback(int logType, const char * format, va_list args ){
  if (!_lua_trace_ref || !_lua_state) return;
  const char * level = "DEBUG";
       if (logType == LOG_TRACE)   level = "TRACE";
  else if (logType == LOG_DEBUG)   level = "DEBUG";
  else if (logType == LOG_INFO)    level = "INFO";
  else if (logType == LOG_WARNING) level = "WARNING";
  else if (logType == LOG_ERROR)   level = "ERROR";
  else if (logType == LOG_FATAL)   level = "FATAL";
  
  char buffer[128] = {0}; // MAX_TRACELOG_BUFFER_SIZE
  vsprintf(buffer, format, args);

  lua_rawgeti(_lua_state, LUA_REGISTRYINDEX, _lua_trace_ref);
  lua_pushstring(_lua_state, level);
  lua_pushstring(_lua_state, buffer);
  lua_call(_lua_state, 2, 0);
}

int lua_core_SetTraceLogCallback(lua_State *L){
  if (lua_isfunction(L, 1)){
    _lua_state = L;
    _lua_trace_ref = lua_ref(L, 1);
    SetTraceLogCallback(_lua_callback);
    return 0;
  }
  lua_unref(L, _lua_trace_ref);
  _lua_state     = 0;
  _lua_trace_ref = 0;
  SetTraceLogCallback(NULL);
  SetTraceLogLevel(LOG_NONE);

  return 0;
}

/*!MD
#### TraceLog
```lua
rl.core.TraceLog(string logLevel, string Message)
```
Show trace log messages.
logLevel is string constant 
`"TRACE"`, `"DEBUG"`, `"INFO"`, `"WARNING"`, 
`"ERROR"` or `"FATAL"`.

`"DEBUG"` is default.
*/
int lua_core_TraceLog(lua_State *L){
  int len;
  const char * s     = luaL_checkstring(L, 1);
  const char * text  = luaL_checklstring(L, 2, &len);
  if (len > 128 - 10) return 0; // MAX_TRACELOG_BUFFER_SIZE overflow

  int flag = LOG_DEBUG;
         if (!strcmp(s, "TRACE"))   flag = LOG_TRACE;
    else if (!strcmp(s, "DEBUG"))   flag = LOG_DEBUG;
    else if (!strcmp(s, "INFO"))    flag = LOG_INFO;
    else if (!strcmp(s, "WARNING")) flag = LOG_WARNING;
    else if (!strcmp(s, "ERROR"))   flag = LOG_ERROR;
    else if (!strcmp(s, "FATAL"))   flag = LOG_FATAL;
  TraceLog(flag, text);
  return 0;
}

/*!MD
#### TakeScreenshot
```lua
rl.core.TakeScreenshot(string fName)
```
Takes a screenshot of current screen (saved a .png).
*/
int lua_core_TakeScreenshot(lua_State *L){
  if (lua_isstring(L, 1)){
    const char * fname = luaL_checkstring(L, 1);
    TakeScreenshot(fname);
    return 0;
  }
  return 0;
}

/*!MD
#### GetRandomValue
```lua
-- variat
integer RndValue = rl.core.GetRandomValue(integer Min, integer Max) -- [Mix .. Max]
integer RndValue = rl.core.GetRandomValue(integer Max)              -- [1   .. Max]
```
Returns a random value between min and max (both included).
*/
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
boolean Status = rl.core.FileExists(string FileName)
```
Check if file exists.
*/
int lua_core_FileExists(lua_State *L){
  const char * fname = luaL_checkstring(L, 1);
  lua_pushboolean(L, FileExists(fname));
  return 1;
}

/*!MD
#### IsFileExtension
```lua
boolean Status = rl.core.IsFileExtension(string FileName, string Ext)
```
Check file extension.
*/
int lua_core_IsFileExtension(lua_State *L){
  const char * fname = luaL_checkstring(L, 1);
  const char * fext  = luaL_checkstring(L, 2);
  lua_pushboolean(L, IsFileExtension(fname, fext));
  return 1;
}

/*!MD
#### DirectoryExists
```lua
boolean Status = rl.core.DirectoryExists(string DirectoryPath)
```
Check if a directory path exists.
*/
int lua_core_DirectoryExists(lua_State *L){
  const char * dname = luaL_checkstring(L, 1);
  lua_pushboolean(L, DirectoryExists(dname));
  return 1;
}

/*!MD
#### DirectoryExists
```lua
string Ext = rl.core.GetExtension(string FileName)
```
Get a extension for a filename string.
*/
int lua_core_GetExtension(lua_State *L){
  const char * fname = luaL_checkstring(L, 1);
  lua_pushstring(L, GetExtension(fname));
  return 1;
}

/*!MD
#### GetFileName
```lua
string FileName = rl.core.GetFileName(string FilePath)
```
Get a filename for a path string.
*/
int lua_core_GetFileName(lua_State *L){
  const char * fpath = luaL_checkstring(L, 1);
  lua_pushstring(L, GetFileName(fpath));
  return 1;
}

/*!MD
#### GetFileNameWithoutExt
```lua
string FileName = rl.core.GetFileNameWithoutExt(string FilePath)
```
Get filename string without extension.
*/
int lua_core_GetFileNameWithoutExt(lua_State *L){
  const char * fpath = luaL_checkstring(L, 1);
  lua_pushstring(L, GetFileNameWithoutExt(fpath));
  return 1;
}

/*!MD
#### GetDirectoryPath
```lua
string DirectoryPath = rl.core.GetDirectoryPath(string FilePath)
```
Get full path for a given fileName with path.
*/
int lua_core_GetDirectoryPath(lua_State *L){
  const char * fpath = luaL_checkstring(L, 1);
  lua_pushstring(L, GetDirectoryPath(fpath));
  return 1;
}

/*!MD
#### GetPrevDirectoryPath
```lua
string DirectoryPath = rl.core.GetPrevDirectoryPath(string FilePath)
```
Get previous directory path for a given path.
*/
int lua_core_GetPrevDirectoryPath(lua_State *L){
  const char * dpath = luaL_checkstring(L, 1);
  lua_pushstring(L, GetPrevDirectoryPath(dpath));
  return 1;
}

/*!MD
#### GetWorkingDirectory
```lua
string DirectoryPath = rl.core.GetWorkingDirectory()
```
Get current working directory.
*/
int lua_core_GetWorkingDirectory(lua_State *L){
  lua_pushstring(L, GetWorkingDirectory());
  return 1;
}

/*!MD
#### GetDirectoryFiles
```lua
table Files = rl.core.GetDirectoryFiles(string DirectoryPath)
```
Get filenames in a directory path. [ClearDirectoryFiles](#ClearDirectoryFiles) is called automatically.
Table Files contains string names like `{"file1.png", "directory1", "file2.lua", ...}`.
*/
int lua_core_GetDirectoryFiles(lua_State *L){
  const char * dpath = luaL_checkstring(L, 1);
  int count;
  char ** paths = GetDirectoryFiles(dpath, &count);
  lua_newtable(L);
  for (int i = 0; i < count; i++){
    luax_tnstring(L, i + 1, paths[i]);
  }
  ClearDirectoryFiles();
  return 1;
}

/*!MD
#### ClearDirectoryFiles
```lua
rl.core.ClearDirectoryFiles()
```
Clear directory files paths buffers (free memory). Deprecated.
*/
int lua_core_ClearDirectoryFiles(lua_State *L){
  ClearDirectoryFiles();
  return 0;
}

/*!MD
#### ChangeDirectory
```lua
boolean Status = rl.core.ChangeDirectory(string DirectoryPath)
```
Change working directory, returns true if success.
*/
int lua_core_ChangeDirectory(lua_State *L){
  const char * dpath = luaL_checkstring(L, 1);
  lua_pushboolean(L, ChangeDirectory(dpath));
  return 1;
}

/*!MD
#### IsFileDropped
```lua
boolean Status = rl.core.IsFileDropped()
```
Check if a file has been dropped into window.
*/
int lua_core_IsFileDropped(lua_State *L){
  lua_pushboolean(L, IsFileDropped());
  return 1;
}

/*!MD
#### GetDroppedFiles
```lua
table Files = rl.core.GetDroppedFiles()
```
Get dropped files names. [ClearDroppedFiles](#ClearDroppedFiles) is called automatically.
Table Files contains string names like `{"file1.png", "file2.lua", ...}`.
*/
int lua_core_GetDroppedFiles(lua_State *L){
  int count;
  char ** files = GetDroppedFiles(&count);
  lua_newtable(L);
  for (int i = 0; i < count; i++) {
      luax_tnstring(L, i + 1, files[i]);
  }
  ClearDroppedFiles();
  return 1;
}

/*!MD
#### ClearDroppedFiles
```lua
rl.core.ClearDroppedFiles()
```
Clear dropped files paths buffer (free memory). Deprecated.
*/
int lua_core_ClearDroppedFiles(lua_State *L){
  ClearDroppedFiles();
  return 0;
}

/*!MD
#### GetFileModTime
```lua
integer Time = rl.core.GetFileModTime(string FilePath)
```
Get file modification time (last write timestamp).
*/
int lua_core_GetFileModTime(lua_State *L){
  const char * fpath = luaL_checkstring(L, 1);
  lua_pushnumber(L, GetFileModTime(fpath));
  return 1;
}

/*!MD
#### GetFileInfo
```lua
table Info = rl.core.GetFileInfo(string FilePath)
```
Get file or directory info, using this layout:
```lua
Info = {
  string  name,     -- filename string without extension
  string  fullname, -- filename with ext
  string  ext,      -- file extension
  string  path      -- passed path
  string  directory -- full path for a given file with path
  integer modtime,  -- file modification time (last write time)
  string  mode,     -- it is "directory" or "file"
}
```
*/
int lua_core_GetFileInfo(lua_State *L){
  const char * fpath = luaL_checkstring(L, 1);
  if (!FileExists(fpath)){
      lua_pushnil(L);
      lua_pushfstring(L, "File [%s] is not exists", fpath);
      return 2;
  }

  lua_newtable(L);
  luax_tsstring(L, "path",      fpath);
  luax_tsstring(L, "fullname",  GetFileName(fpath));
  luax_tsstring(L, "name",      GetFileNameWithoutExt(fpath));
  luax_tsstring(L, "ext",       GetExtension(fpath));
  luax_tsstring(L, "directory", GetDirectoryPath(fpath));
  luax_tsnumber(L, "modtime",   GetFileModTime(fpath));
  luax_tsstring(L, "mode",      DirectoryExists(fpath) ? "directory" : "file");
  return 1;
}

/*!MD
#### CompressData
```lua
string CompressedData = rl.core.CompressData(string Data)
```
Compress data (DEFLATE algorythm).
*/
int lua_core_CompressData(lua_State *L){
  int srclen, dstlen;
  unsigned char * src = (unsigned char *)luaL_checklstring(L, 1, &srclen);
  unsigned char * dst = CompressData(src, srclen, &dstlen);
  if (!dst){
    lua_pushnil(L);
    lua_pushstring(L, "Zlib is not included");
    return 2;
  }
  lua_pushlstring(L, dst, dstlen);
  return 1;
}

/*!MD
#### DecompressData
```lua
string Data = rl.core.DecompressData(string CompressedData)
```
Deompress data (DEFLATE algorythm).
*/
int lua_core_DecompressData(lua_State *L){
  int srclen, dstlen;
  unsigned char * src = (unsigned char *)luaL_checklstring(L, 1, &srclen);
  unsigned char * dst = DecompressData(src, srclen, &dstlen);
  if (!dst){
    lua_pushnil(L);
    lua_pushstring(L, "Compressed data is invalid");
    return 2;
  }
  lua_pushlstring(L, dst, dstlen);
  return 1;
}

/*!MD
#### OpenURL
```lua
rl.core.OpenURL(string URL)
```
Open URL with default system browser (if available).
*/
int lua_core_OpenURL(lua_State *L){
  const char * url = luaL_checkstring(L, 1);
  OpenURL(url);
  return 0;
}

/*!MD
### Persistent storage management
#### StorageSaveValue
```lua
rl.core.StorageSaveValue(integer Position, integer Value)
```
Save integer value to storage file (to defined position).
*/
int lua_core_StorageSaveValue(lua_State *L){
  int key   = luaL_checkinteger(L, 1);
  int value = luaL_checkinteger(L, 2);
  StorageSaveValue(key, value);
  return 0;
}

/*!MD
#### StorageLoadValue
```lua
integer Value = rl.core.StorageLoadValue(integer Position)
```
Load integer value from storage file (from defined position).
*/
int lua_core_StorageLoadValue(lua_State *L){
  int key = luaL_checkinteger(L, 1);
  lua_pushinteger(L, StorageLoadValue(key));
  return 1;
}

/*!MD
### Input-related functions: keyb
#### IsKeyPressed
```lua
boolean State = rl.core.IsKeyPressed(integer Key)
```
Detect if a key has been pressed once.
*/
int lua_core_IsKeyPressed(lua_State *L){
  int key = ray_keyboard_getKeyEnumFromStack(L, 1);
  lua_pushboolean(L, IsKeyPressed(key));
  return 1;
}

/*!MD
#### IsKeyDown
```lua
boolean State = rl.core.IsKeyDown(integer Key)
```
Detect if a key is being pressed.
*/
int lua_core_IsKeyDown(lua_State *L){
  int key = ray_keyboard_getKeyEnumFromStack(L, 1);
  lua_pushboolean(L, IsKeyDown(key));
  return 1;
}

/*!MD
#### IsKeyReleased
```lua
boolean State = rl.core.IsKeyReleased(integer Key)
```
Detect if a key has been released once.
*/
int lua_core_IsKeyReleased(lua_State *L){
  int key = ray_keyboard_getKeyEnumFromStack(L, 1);
  lua_pushboolean(L, IsKeyReleased(key));
  return 1;
}

/*!MD
#### IsKeyUp
```lua
boolean State = rl.core.IsKeyUp(integer Key)
```
Detect if a key is NOT being pressed.
*/
int lua_core_IsKeyUp(lua_State *L){
  int key = ray_keyboard_getKeyEnumFromStack(L, 1);
  lua_pushboolean(L, IsKeyUp(key));
  return 1;
}

/*!MD
#### GetKeyPressed
```lua
integer Key = rl.core.GetKeyPressed()
```
Get latest key scancode pressed.
*/
int lua_core_GetKeyPressed(lua_State *L){
  int key = GetKeyPressed();
  if (!key) return 0;
  lua_pushinteger(L, key);
  return 1;
}

/*!MD
#### GetKeyPressedString
```lua
string Char = rl.core.GetKeyPressedString()
```
Get user input UTF-8 encoded string char.
*/
int lua_core_GetKeyPressedString(lua_State *L){
  int len;
  int key = GetKeyPressed();
  if (!key) return 0;
  const char * cutf8 = CodepointToUtf8(key, &len);
  lua_pushstring(L, cutf8);
  return 1;
}

/*!MD
#### GetAllKeysPressedString
```lua
string Text = rl.core.GetAllKeysPressedString()
```
Get all user UTF-8 encoded string input chars.
*/
int lua_core_GetAllKeysPressedString(lua_State *L){
  int codepoints[20]; // max codepoint count per one GetKeyPressed
  int len = 0;
  int key = GetKeyPressed();
  while(key){
    codepoints[len] = key;
    len++;
    if (len == 20) break;
    key = GetKeyPressed();
  }

  if (!len){
    lua_pushnil(L);
    return 1;
  }

  char * text = TextToUtf8(&codepoints, len);
  lua_pushstring(L, text);
  free(text);
  return 1;
}

/*!MD
#### SetExitKey
```lua
rl.core.SetExitKey(integer Key)
```
Set a custom key to exit program (default is ESC).
*/
int lua_core_SetExitKey(lua_State *L){
  int key = ray_keyboard_getKeyEnumFromStack(L, 1);
  SetExitKey(key);
  return 0;
}

/*!MD
### Input-related functions: gamepads
#### IsGamepadAvailable
```lua
boolean State = rl.core.IsGamepadAvailable(integer Gamepad)
```
Detect if a gamepad is available.
*/
int lua_core_IsGamepadAvailable(lua_State *L){
  int gamepad = luaL_checkinteger(L, 1);
  lua_pushboolean(L, IsGamepadAvailable(gamepad - 1));
  return 1;
}

/*!MD
#### IsGamepadName
```lua
boolean State = rl.core.IsGamepadName(integer Gamepad, string GamepadName)
```
Check gamepad name (if available).
*/
int lua_core_IsGamepadName(lua_State *L){
  int gamepad = luaL_checkinteger(L, 1);
  const char * name = luaL_checkstring(L, 2);
  lua_pushboolean(L, IsGamepadName(gamepad - 1, name));
  return 1;
}

/*!MD
#### GetGamepadName
```lua
string GamepadName = rl.core.GetGamepadName(integer Gamepad)
```
Check gamepad name (if available).
*/
int lua_core_GetGamepadName(lua_State *L){
  int gamepad = luaL_checkinteger(L, 1);
  lua_pushstring(L, GetGamepadName(gamepad - 1));
  return 1;
}

/*!MD
#### IsGamepadButtonPressed
```lua
boolean Status = rl.core.IsGamepadButtonPressed(integer Gamepad)
```
Detect if a gamepad button has been pressed once.
*/
int lua_core_IsGamepadButtonPressed(lua_State *L){
  int gamepad = luaL_checkinteger(L, 1);
  int button  = luaL_checkinteger(L, 2);
  lua_pushboolean(L, IsGamepadButtonPressed(gamepad - 1, button));
  return 1;
}

/*!MD
#### IsGamepadButtonDown
```lua
boolean Status = rl.core.IsGamepadButtonDown(integer Gamepad)
```
Detect if a gamepad button is being pressed.
*/
int lua_core_IsGamepadButtonDown(lua_State *L){
  int gamepad = luaL_checkinteger(L, 1);
  int button  = luaL_checkinteger(L, 2);
  lua_pushboolean(L, IsGamepadButtonDown(gamepad - 1, button));
  return 1;
}

/*!MD
#### IsGamepadButtonReleased
```lua
boolean Status = rl.core.IsGamepadButtonReleased(integer Gamepad)
```
Detect if a gamepad button has been released once.
*/
int lua_core_IsGamepadButtonReleased(lua_State *L){
  int gamepad = luaL_checkinteger(L, 1);
  int button  = luaL_checkinteger(L, 2);
  lua_pushboolean(L, IsGamepadButtonReleased(gamepad - 1, button));
  return 1;
}

/*!MD
#### IsGamepadButtonUp
```lua
boolean Status = rl.core.IsGamepadButtonUp(integer Gamepad)
```
Detect if a gamepad button is NOT being pressed.
*/
int lua_core_IsGamepadButtonUp(lua_State *L){
  int gamepad = luaL_checkinteger(L, 1);
  int button  = luaL_checkinteger(L, 2);
  lua_pushboolean(L, IsGamepadButtonUp(gamepad - 1, button));
  return 1;
}

/*!MD
#### GetGamepadButtonPressed
```lua
integer Key = rl.core.GetGamepadButtonPressed()
```
Get the last gamepad button pressed.
*/
int lua_core_GetGamepadButtonPressed(lua_State *L){
  lua_pushnumber(L, GetGamepadButtonPressed());
  return 1;
}

/*!MD
#### GetGamepadAxisCount
```lua
integer Count = rl.core.GetGamepadAxisCount()
```
Return gamepad axis count for a gamepad.
*/
int lua_core_GetGamepadAxisCount(lua_State *L){
  int gamepad = luaL_checkinteger(L, 1);
  lua_pushnumber(L, GetGamepadAxisCount(gamepad - 1));
  return 1;
}

/*!MD
#### GetGamepadAxisMovement
```lua
float Movement = rl.core.GetGamepadAxisMovement(integer Gamepad)
```
Return axis movement value for a gamepad axis.
*/
int lua_core_GetGamepadAxisMovement(lua_State *L){
  int gamepad = luaL_checkinteger(L, 1);
  int axis    = luaL_checkinteger(L, 2);
  lua_pushnumber(L, GetGamepadAxisMovement(gamepad - 1, axis - 1));
  return 1;
}

/*!MD
### Input-related functions: mouse
#### IsMouseButtonPressed
```lua
boolean State = rl.core.IsMouseButtonPressed(integer Button)
```
Detect if a mouse button has been pressed once.
*/
int lua_core_IsMouseButtonPressed(lua_State *L){
  int button  = luaL_checkinteger(L, 1);
  lua_pushboolean(L, IsMouseButtonPressed(button - 1));
  return 1;
}

/*!MD
#### IsMouseButtonDown
```lua
boolean State = rl.core.IsMouseButtonDown(integer Button)
```
Detect if a mouse button is being pressed.
*/
int lua_core_IsMouseButtonDown(lua_State *L){
  int button  = luaL_checkinteger(L, 1);
  lua_pushboolean(L, IsMouseButtonDown(button - 1));
  return 1;
}

/*!MD
#### IsMouseButtonReleased
```lua
boolean State = rl.core.IsMouseButtonReleased(integer Button)
```
Detect if a mouse button has been released once.
*/
int lua_core_IsMouseButtonReleased(lua_State *L){
  int button  = luaL_checkinteger(L, 1);
  lua_pushboolean(L, IsMouseButtonReleased(button - 1));
  return 1;
}

/*!MD
#### IsMouseButtonUp
```lua
boolean State = rl.core.IsMouseButtonUp(integer Button)
```
Detect if a mouse button is NOT being pressed.
*/
int lua_core_IsMouseButtonUp(lua_State *L){
  int button  = luaL_checkinteger(L, 1);
  lua_pushboolean(L, IsMouseButtonUp(button - 1));
  return 1;
}

/*!MD
#### GetMouseX
```lua
integer X = rl.core.GetMouseX()
```
Returns mouse position X.
*/
int lua_core_GetMouseX(lua_State *L){
  lua_pushnumber(L, GetMouseX());
  return 1;
}

/*!MD
#### GetMouseY
```lua
integer Y = rl.core.GetMouseY()
```
Returns mouse position Y.
*/
int lua_core_GetMouseY(lua_State *L){
  lua_pushnumber(L, GetMouseY());
  return 1;
}

/*!MD
#### GetMousePosition
```lua
-- variants
Vector2 Position     = rl.core.GetMousePosition()
integer X, integer Y = rl.core.GetMousePosition('n')
```
Returns mouse position XY.
*/
int lua_core_GetMousePosition(lua_State *L){
  if (luax_optstring(L, 1, "\0")[0] == 'n') {
    lua_pushnumber(L, GetMouseX());
    lua_pushnumber(L, GetMouseY());
    return 2;
  }
  Vector2 * v = luax_newobject(L, "Vector2", sizeof(Vector2));
  *v = GetMousePosition();
  return 1;
}

/*!MD
#### SetMousePosition
```lua
-- variants
rl.core.SetMousePosition(Vector2 Position)
rl.core.SetMousePosition(integer X, integer Y)
```
Set mouse position XY.
*/
int lua_core_SetMousePosition(lua_State *L){
  if (luax_checkclass(L, 1, "Vector2")){
    Vector2 * v = luaL_checkudata(L, 1, "Vector2");
    SetMousePosition(v->x, v->y);
    return 0;
  }
  int x = luaL_checkinteger(L, 1);
  int y = luaL_checkinteger(L, 2);
  SetMousePosition(x, y);
  return 0;
}

/*!MD
#### SetMouseOffset
```lua
-- variants
rl.core.SetMouseOffset(Vector2 Offset)
rl.core.SetMouseOffset(integer X, integer Y)
```
Set mouse offset.
*/
int lua_core_SetMouseOffset(lua_State *L){
  if (luax_checkclass(L, 1, "Vector2")){
    Vector2 * v = luaL_checkudata(L, 1, "Vector2");
    SetMouseOffset(v->x, v->y);
    return 0;
  }
  int x = luaL_checkinteger(L, 1);
  int y = luaL_checkinteger(L, 2);
  SetMouseOffset(x, y);
  return 0;
}

/*!MD
#### SetMouseScale
```lua
-- variants
rl.core.SetMouseScale(Vector2 Scale)
rl.core.SetMouseScale(integer X, integer Y)
```
Set mouse scaling.
*/
int lua_core_SetMouseScale(lua_State *L){
  if (luax_checkclass(L, 1, "Vector2")){
    Vector2 * v = luaL_checkudata(L, 1, "Vector2");
    SetMouseScale(v->x, v->y);
    return 0;
  }
  int x = luaL_checkinteger(L, 1);
  int y = luaL_checkinteger(L, 2);
  SetMouseScale(x, y);
  return 0;
}

/*!MD
#### GetMouseWheelMove
```lua
-- variants
integer WheelMove = rl.core.GetMouseWheelMove()
```
Returns mouse wheel movement Y.
*/
int lua_core_GetMouseWheelMove(lua_State *L){
  lua_pushnumber(L, GetMouseWheelMove());
  return 1;
}

/*!MD
### Input-related functions: touch
#### GetTouchX
```lua
integer X = rl.core.GetTouchX()
```
Returns touch position X for touch point 1 (relative to screen size).
*/
int lua_core_GetTouchX(lua_State *L){
  lua_pushnumber(L, GetTouchX());
  return 1;
}

/*!MD
#### GetTouchY
```lua
integer Y = rl.core.GetTouchY()
```
Returns touch position Y for touch point 1 (relative to screen size).
*/
int lua_core_GetTouchY(lua_State *L){
  lua_pushnumber(L, GetTouchY());
  return 1;
}

/*!MD
#### GetTouch
```lua
integer X, integer Y = rl.core.GetTouch()
```
Returns touch position XY for a touch point 1 (relative to screen size).
*/
int lua_core_GetTouch(lua_State *L){
  lua_pushnumber(L, GetTouchX());
  lua_pushnumber(L, GetTouchY());
  return 2;
}

/*!MD
#### GetTouchPosition
```lua
-- veriants
Vector2 Position     = rl.core.GetTouchPosition(integer Index)
integer X, integer Y = rl.core.GetTouchPosition(integer Index, 'n')
```
Returns touch position XY for a touch point index (relative to screen size).
*/
int lua_core_GetTouchPosition(lua_State *L){
  int touch = luaL_checkinteger(L, 1);
  Vector2 v = GetTouchPosition(touch - 1);
  if (luax_optstring(L, 2, "\0")[0] == 'n') {
    lua_pushnumber(L, v.x);
    lua_pushnumber(L, v.y);
    return 2;
  }
  Vector2 * lv = luax_newobject(L, "Vector2", sizeof(Vector2));
  *lv = v;
  return 1;
}

/*!MD
#### GetTouches
```lua
-- veriants
table Touches = rl.core.GetTouches(integer Index)      -- {Vector2 t1, Vector2 t2, ...}
table Touches = rl.core.GetTouches(integer Index, 'n') -- {{integer X1, integer Y1}, {integer X2, integer Y2}, ...}
```
Returns all touches positions XY (relative to screen size).
*/
int lua_core_GetTouches(lua_State *L){
  lua_newtable(L); // result
  bool useNumbers = (luax_optstring(L, 1, "\0")[0] == 'n');
  for (int i = 0; i < GetTouchPointsCount(); i++){
    lua_pushnumber(L, i + 1); // index
    Vector2 v = GetTouchPosition(i);
    if (useNumbers){
        lua_newtable(L);  // result[i]
        luax_tnnumber(L, 1, v.x);
        luax_tnnumber(L, 1, v.y);
    }
    else{
      Vector2 * lv = luax_newobject(L, "Vector2", sizeof(Vector2));   // result[i]
      *lv = v;
    }
    lua_rawset(L, -3);
  }
  return 1;
}

/*!MD
#### SetGesturesEnabled
```lua
rl.core.SetGesturesEnabled(string Mode1, string Mode2, ...)
```
Enable a set of gestures using modes.
Available Modes:
* `"NONE"` (default if no mode passed)
* `"TAP"`
* `"DOUBLETAP"`
* `"HOLD"`
* `"DRAG"`
* `"SWIPE_RIGHT"`
* `"SWIPE_LEFT"`
* `"SWIPE_UP"`
* `"SWIPE_DOWN"`
* `"PINCH_IN"`
* `"PINCH_OUT"`
*/
int lua_core_SetGesturesEnabled(lua_State *L){
  int flag = GESTURE_NONE;
  for (int i = 1; i <= lua_gettop(L); i++){
    if (lua_isstring(L, i)){
      const char * s = luaL_checkstring(L, i);
           if (!strcmp(s, "TAP"))         flag |= GESTURE_TAP;
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

/*!MD
#### IsGestureDetected
```lua
boolean Status = rl.core.IsGestureDetected(string Mode)
```
Check if a gesture have been detected.
Available Modes to check:
* `"TAP"`
* `"DOUBLETAP"`
* `"HOLD"`
* `"DRAG"`
* `"SWIPE_RIGHT"`
* `"SWIPE_LEFT"`
* `"SWIPE_UP"`
* `"SWIPE_DOWN"`
* `"PINCH_IN"`
* `"PINCH_OUT"`
*/
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

/*!MD
#### GetGestureDetected
```lua
-- variants
string Gesture, ~ A, ~ B, ~ C = rl.core.GetGestureDetected()
string Gesture, ~ A, ~ B, ~ C = rl.core.GetGestureDetected('n')
```
Get latest detected gesture.
A, B, and C is additional info for various gestures:
* `"HOLD"` returns float GestureHoldDuration
* `"DRAG"` returns Vector2 DragVector, float DragAngle if 'n' is not passed
* `"DRAG"` returns integer DragVectorX, integer DragVectorY, float DragAngle if 'n' is passed
* `"PINCH_IN"` returns Vector2 PinchVector, float PinchAngle if 'n' is not passed
* `"PINCH_IN"` returns integer PinchVectorX, integer PinchVectorY, float PinchAngle if 'n' is passed
* `"PINCH_OUT"` same as `"PINCH_IN"`.
*/
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
    Vector2 * lv = luax_newobject(L, "Vector2", sizeof(Vector2)); // 2
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
    Vector2 * lv = luax_newobject(L, "Vector2", sizeof(Vector2)); // 2
    *lv = v;
    lua_pushnumber(L, GetGesturePinchAngle()); // 3
    return 3;
  }

  return 1;
}

/*!MD
#### GetTouchPointsCount
```lua
integer Count = rl.core.GetTouchPointsCount()
```
Get touch points count.
*/
int lua_core_GetTouchPointsCount(lua_State *L){
  lua_pushnumber(L, GetTouchPointsCount());
  return 1;
}

/*!MD
#### GetGestureHoldDuration
```lua
float Duration = rl.core.GetGestureHoldDuration()
```
Get gesture hold time in milliseconds.
*/
int lua_core_GetGestureHoldDuration(lua_State *L){
  lua_pushnumber(L, GetGestureHoldDuration());
  return 1;
}

/*!MD
#### GetGestureHoldDuration
```lua
-- variants
Vector2 DragVector     = rl.core.GetGestureDragVector()
integer vX, integer vY = rl.core.GetGestureDragVector('n')
```
Get gesture drag vector.
*/
int lua_core_GetGestureDragVector(lua_State *L){
  Vector2 v = GetGestureDragVector();
  if (luax_optstring(L, 1, "\0")[0] == 'n'){
    lua_pushnumber(L, v.x);
    lua_pushnumber(L, v.y);
    return 2;
  }
  Vector2 * lv = luax_newobject(L, "Vector2", sizeof(Vector2));
  *lv = v;
  return 1;
}

/*!MD
#### GetGestureDragAngle
```lua
float Angle = rl.core.GetGestureDragAngle()
```
Get gesture drag angle.
*/
int lua_core_GetGestureDragAngle(lua_State *L){
  lua_pushnumber(L, GetGestureDragAngle());
  return 1;
}

/*!MD
#### GetGesturePinchVector
```lua
-- variants
Vector2 PinchVector    = rl.core.GetGesturePinchVector()
integer dX, integer dY = rl.core.GetGesturePinchVector('n')
```
Get gesture pinch delta.
*/
int lua_core_GetGesturePinchVector(lua_State *L){
  Vector2 v = GetGesturePinchVector();
  if (luax_optstring(L, 1, "\0")[0] == 'n'){
    lua_pushnumber(L, v.x);
    lua_pushnumber(L, v.y);
    return 2;
  }
  Vector2 * lv = luax_newobject(L, "Vector2", sizeof(Vector2));
  *lv = v;
  return 1;
}

/*!MD
#### GetGesturePinchAngle
```lua
float Angle = rl.core.GetGesturePinchAngle()
```
Get gesture pinch angle.
*/
int lua_core_GetGesturePinchAngle(lua_State *L){
  lua_pushnumber(L, GetGesturePinchAngle());
  return 1;
}

/*!MD
### Camera System Functions (Module: camera)
#### SetCameraMode
```lua
rl.core.SetCameraMode(Camera3D Camera, string Mode)
```
Set camera mode. Available modes: 
* `"CUSTOM"` - default
* `"FREE"`
* `"ORBITAL"`
* `"FIRST_PERSON"`
* `"THIRD_PERSON"`
*/
int lua_core_SetCameraMode(lua_State *L){
  Camera3D * c = luaL_checkudata(L, 1, "Camera3D");
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

/*!MD
#### UpdateCamera
```lua
rl.core.UpdateCamera(Camera3D Camera)
```
Update camera position for selected mode.
*/
int lua_core_UpdateCamera(lua_State *L){
  Camera3D * c = luaL_checkudata(L, 1, "Camera3D");
  UpdateCamera(c);
  return 0;
}

/*!MD
#### SetCameraPanControl
```lua
rl.core.SetCameraPanControl(integer panKey)
```
Set camera pan key to combine with mouse movement (free camera).
*/
int lua_core_SetCameraPanControl(lua_State *L){
  int key = ray_keyboard_getKeyEnumFromStack(L, 1);
  SetCameraPanControl(key);
  return 0;
}

/*!MD
#### SetCameraAltControl
```lua
rl.core.SetCameraAltControl(integer altKey)
```
Set camera alt key to combine with mouse movement (free camera).
*/
int lua_core_SetCameraAltControl(lua_State *L){
  int key = ray_keyboard_getKeyEnumFromStack(L, 1);
  SetCameraAltControl(key);
  return 0;
}

/*!MD
#### SetCameraSmoothZoomControl
```lua
rl.core.SetCameraSmoothZoomControl(integer szKey)
```
Set camera smooth zoom key to combine with mouse (free camera).
*/
int lua_core_SetCameraSmoothZoomControl(lua_State *L){
  int key = ray_keyboard_getKeyEnumFromStack(L, 1);
  SetCameraSmoothZoomControl(key);
  return 0;
}

/*!MD
#### SetCameraMoveControls
```lua
rl.core.SetCameraMoveControls(integer frontKey, integer backKey, integer rightKey, integer leftKey, integer upKey, integer downKey)
```
Set camera move controls (1st person and 3rd person cameras).
*/
int lua_core_SetCameraMoveControls(lua_State *L){
  int front = ray_keyboard_getKeyEnumFromStack(L, 1);
  int back  = ray_keyboard_getKeyEnumFromStack(L, 2);
  int right = ray_keyboard_getKeyEnumFromStack(L, 3);
  int left  = ray_keyboard_getKeyEnumFromStack(L, 4);
  int up    = ray_keyboard_getKeyEnumFromStack(L, 5);
  int down  = ray_keyboard_getKeyEnumFromStack(L, 6);
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
  {"TraceLog",                     lua_core_TraceLog},
  {"TakeScreenshot",               lua_core_TakeScreenshot},
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
  {"GetKeyPressedString",          lua_core_GetKeyPressedString},
  {"GetAllKeysPressedString",      lua_core_GetAllKeysPressedString},
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
    Color* c = (Color*)luaL_checkudata(L, 3, "Color");
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
  Color * c = (Color *)luaL_checkudata(L, 5, "Color");
  DrawText(text, x, y, s, *c);
  return 0;
}

// Text misc. functions

// Text strings management functions (no UTF-8 encoded strings, only byte chars)

// UTF-8 encoded text strings management functions

luaL_Reg luaray_text[] = {
  {"DrawFPS",  lua_text_DrawFPS},
  {"DrawText", lua_text_DrawText},
  {NULL, NULL}
};


#if defined(_WIN32) || defined(_WIN64)
__declspec(dllexport)
#endif
int luaopen_raylib_luamore(lua_State *L) {
  lua_newtable(L);
  lua_class_register(L);
  
  lua_pushstring(L, "core");     luax_pushfunctable(L, luaray_core);     lua_rawset(L, -3);
  lua_pushstring(L, "shapes");   luax_pushfunctable(L, luaray_shapes);   lua_rawset(L, -3);
  lua_pushstring(L, "textures"); luax_pushfunctable(L, luaray_textures); lua_rawset(L, -3);
  lua_pushstring(L, "text");     luax_pushfunctable(L, luaray_text);     lua_rawset(L, -3);
  lua_pushstring(L, "ekey");     luaray_exportKeyboardKeys(L);           lua_rawset(L, -3);
  
  return 1;
}
