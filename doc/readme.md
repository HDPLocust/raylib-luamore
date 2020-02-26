
# Hello. 
This is Lua binding for raylib.
### All stuff provided by Snooze.

(there should be a table of contents)
* Core
  * Core functions
* Text
  * Text functions

etc


## Core
### Core functions

#### Initialization
```lua
local ray = require("raylib_luamore")
```


### Window-related functions:
#### InitWindow
```lua
ray.core.InitWindow(integer Width, integer Height, string Title)
```
Initialize window and OpenGL context
Should be called before any widnow stuff is used.


#### WindowShouldClose
```lua
boolean Status = ray.core.WindowShouldClose()
```
Check if ESCAPE-key pressed or Close icon pressed. See [SetExitKey](SetExitKey)


#### CloseWindow
```lua
ray.core.CloseWindow()
```
Close window and unload OpenGL context


#### IsWindowReady
```lua
boolean Status = ray.core.IsWindowReady()
```
Check if window has been initialized successfully


#### IsWindowMinimized
```lua
boolean Status = ray.core.IsWindowMinimized()
```
Check if window has been minimized (or lost focus)


#### IsWindowResized
```lua
boolean Status = ray.core.IsWindowResized()
```
Check if window has been resized


#### IsWindowHidden
```lua
boolean Status = ray.core.IsWindowHidden()
```
Check if window is currently hidden


#### ToggleFullscreen
```lua
ray.core.ToggleFullscreen()
```
Toggle fullscreen mode (only PLATFORM_DESKTOP)


#### UnhideWindow
```lua
ray.core.UnhideWindow()
```
Show the window


#### HideWindow
```lua
ray.core.HideWindow()
```
Hide the window


#### SetWindowIcon
```lua
ray.core.SetWindowIcon(Image Icon)
```
Set icon for window (only PLATFORM_DESKTOP)
For additional info [Image]


#### SetWindowTitle
```lua
ray.core.SetWindowTitle(string Title)
```
Set title for window (only PLATFORM_DESKTOP)


#### SetWindowPosition
```lua
ray.core.SetWindowPosition(string Title)
```
Set window position on screen (only PLATFORM_DESKTOP)


#### SetWindowMonitor
```lua
ray.core.SetWindowMonitor(integer Monitor)
```
Set monitor for the current window (fullscreen mode)


#### SetWindowMinSize
```lua
ray.core.SetWindowMinSize(integer Width, integer Height)
```
Set window minimum dimensions (for flag WINDOW_RESIZABLE)


#### SetWindowSize
```lua
ray.core.SetWindowSize(integer Width, integer Height)
```
Set window dimensions


#### GetWindowHandle
```lua
userdata Handle = ray.core.GetWindowHandle()
```
Get native window handle
Using for FFI or something


#### GetScreenWidth
```lua
integer Width = ray.core.GetScreenWidth()
```
Get current screen width


#### GetScreenHeight
```lua
integer Height = ray.core.GetScreenHeight()
```
Get current screen height


#### GetScreenDimensions
```lua
integer Width, integer Height = ray.core.GetScreenDimensions()
```
Get current screen dimensions


#### GetMonitorCount
```lua
integer Count = ray.core.GetMonitorCount()
```
Get number of connected monitors


#### GetMonitorWidth
```lua
integer Width = ray.core.GetMonitorWidth(integer Monitor)
```
Get selected monitor width


#### GetMonitorHeight
```lua
integer Height = ray.core.GetMonitorHeight(integer Monitor)
```
Get selected monitor height


#### GetMonitorDimensions
```lua
integer Width, integer Height = ray.core.GetMonitorDimensions(integer Monitor)
```
Get selected monitor dimensions


#### GetMonitorPhysicalWidth
```lua
integer Width = ray.core.GetMonitorPhysicalWidth(integer Monitor)
```
Get selected monitor physical width in millimetres


#### GetMonitorPhysicalHeight
```lua
integer Height = ray.core.GetMonitorPhysicalHeight(integer Monitor)
```
Get selected monitor physical height in millimetres


#### GetMonitorPhysicalDimensions
```lua
integer Width, integer Height = ray.core.GetMonitorPhysicalDimensions(integer Monitor)
```
Get selected monitor physical dimensions in millimetres


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


#### GetWindowPosition
```lua
Vector2 Position = ray.core.GetWindowPosition()
```
Get window position XY on monitor.
See [Vector2](#Vector2)


#### GetMonitorName
```lua
string Name = ray.core.GetMonitorName()
```
Get the human-readable, UTF-8 encoded name of the primary monitor


#### GetClipboardText
```lua
string Text = ray.core.GetClipboardText()
```
Get clipboard text content


#### SetClipboardText
```lua
ray.core.SetClipboardText(string Text)
```
Set clipboard text content


### Cursor-related functions
#### ShowCursor
```lua
ray.core.ShowCursor()
```
Shows cursor


#### HideCursor
```lua
ray.core.HideCursor()
```
Hides cursor


#### IsCursorHidden
```lua
boolean Status = ray.core.IsCursorHidden()
```
Check if cursor is not visible


#### EnableCursor
```lua
ray.core.EnableCursor()
```
Enables cursor (unlock cursor)


#### DisableCursor
```lua
ray.core.DisableCursor()
```
Disables cursor (lock cursor)


### Drawing-related functions
#### ClearBackground
```lua
ray.core.ClearBackground(Color Color)
```
Set background color (framebuffer clear color).
See [Color](#Color)


#### BeginDrawing
```lua
ray.core.BeginDrawing()
```
Setup canvas (framebuffer) to start drawing


#### EndDrawing
```lua
ray.core.EndDrawing()
```
End canvas drawing and swap buffers (double buffering)


#### BeginMode2D
```lua
ray.core.BeginMode2D(Camera2D Camera)
```
Initialize 2D mode with custom camera (2D).
See [Camera2D](#Camera2D)


#### EndMode2D
```lua
ray.core.EndMode2D()
```
Ends 2D mode with custom camera


#### BeginMode3D
```lua
ray.core.BeginMode3D(Camera3D Camera)
```
Initializes 3D mode with custom camera (3D).
See [Camera3D](#Camera3D)


#### EndMode3D
```lua
ray.core.EndMode3D()
```
Ends 3D mode and returns to default 2D orthographic mode


#### BeginTextureMode
```lua
ray.core.BeginTextureMode(RenderTexture Texture)
```
Initializes render texture for drawing.
See [RenderTexture](#RenderTexture)


#### EndTextureMode
```lua
ray.core.EndTextureMode()
```
Ends drawing to render texture


#### BeginScissorMode
```lua
ray.core.BeginScissorMode(integer X, integer Y, integer Width, integer Height)
```
Begin scissor mode (define screen area for following drawing)


#### EndScissorMode
```lua
ray.core.EndScissorMode()
```
End scissor mode


### Screen-space-related functions
#### GetMouseRay
```lua
-- variations
Ray Ray = ray.core.GetMouseRay(Vector2 Vector, Camera3D Camera)
Vector2 Position, Vector2 Direction = ray.core.GetMouseRay(Vector2 Vector, Camera3D Camera, "v")
```
Returns a ray trace from mouse position. See [Ray](Ray), [Vector2](Vector2).


#### GetCameraMatrix
```lua
Matrix View = ray.core.GetCameraMatrix(Camera3D Camera)
```
Returns camera transform matrix (view matrix). See [Matrix](Matrix)


#### GetCameraMatrix2D
```lua
Matrix View = ray.core.GetCameraMatrix2D(Camera2D Camera)
```
Returns camera 2d transform matrix. See [Matrix](Matrix), [Camera2D](Camera2D)


#### GetWorldToScreen
```lua
Vector2 ScreenV = Matrix ray.core.GetWorldToScreen(Vector3 Vector, Camera3D Camera)
```
Returns the screen space position for a 3d world space position.  See [Vector2](Vector2), [Vector3](Vector3), [Camera3D](Camera3D)


#### GetWorldToScreenEx
```lua
Vector2 ScreenV = Matrix ray.core.GetWorldToScreenEx(Vector3 Vector, Camera3D Camera, integer Width, integer Height)
```
Returns size position for a 3d world space position.  See [Vector2](Vector2), [Vector3](Vector3), [Camera3D](Camera3D)


#### GetWorldToScreen2D
```lua
Vector2 ScreenV = Matrix ray.core.GetWorldToScreen2D(Vector2 Vector, Camera2D Camera)
```
Returns the screen space position for a 2d camera world space position.  See [Vector2](Vector2), [Camera2D](Camera2D)


#### GetScreenToWorld2D
```lua
Vector2 ScreenV = Matrix ray.core.GetScreenToWorld2D(Vector2 Vector, Camera2D Camera)
```
Returns the world space position for a 2d camera screen space position.  See [Vector2](Vector2), [Camera2D](Camera2D)


### Timing-related functions
#### SetTargetFPS
```lua
ray.core.SetTargetFPS(integer FPS)
```
Set target FPS (maximum)


#### GetFPS
```lua
integer FPS = Matrix ray.core.GetFPS()
```
Returns current FPS


#### GetFrameTime
```lua
float DT = Matrix ray.core.GetFrameTime()
```
Returns time in seconds for last frame drawn


#### GetTime
```lua
float Time = Matrix ray.core.GetTime()
```
Returns elapsed time in seconds since InitWindow()


### Color-related functions
#### ColorToInt
```lua
integer iColor = ray.core.ColorToInt(Color Color)
```
Returns hexadecimal value for a Color


#### ColorNormalize
```lua
-- variations
Vector4 vColor = ray.core.ColorNormalize(Color Color)
integer NR, integer NG, integer NB, integer NA = ray.core.ColorNormalize(Color Color, "n")
table tColor = ray.core.ColorNormalize(Color Color, "t") -- Array {float r, float g, float b, float a}
```
Returns color normalized as float [0..1]. See [Vector4](Vector4), [Color](Color)


#### ColorFromNormalized
```lua
-- variations
Color Color = ray.core.ColorFromNormalized(Vector4 vColor)
Color Color = ray.core.ColorFromNormalized(float R, float G, float B[, float A])
Color Color = ray.core.ColorFromNormalized(table tColor) -- Array {float r, float g, float b[, float a]}
```
Returns color from normalized values [0..1]. See [Vector4](Vector4), [Color](Color)


#### ColorToHSV
```lua
-- variations
Vector3 vColor = ray.core.ColorToHSV(Color Color)
float Hue, float Saturation, float Value = ray.core.ColorToHSV(Color Color, "n")
table hsvColor = ray.core.ColorNormalize(Color Color, "t") -- Array {float h, float s, float v}
```
Returns HSV values for a Color. See [Vector3](Vector3), [Color](Color)


#### ColorFromHSV
```lua
-- variations
Color Color = ray.core.ColorFromHSV(Vector3 vColor)
Color Color = ray.core.ColorFromHSV(float H, float S, float V)
Color Color = ray.core.ColorFromHSV(table hsvColor) -- Array {float h, float s, float v}
```
Returns a Color from HSV values. See [Vector3](Vector3), [Color](Color)


#### GetColor
```lua
-- variations
Color Color = ray.core.GetColor(integer hColor)
```
Returns a Color struct from hexadecimal value. See [Color](Color)


#### Fade
```lua
-- variations
Color fColor = ray.core.Fade(Color Color, float alpha)
```
Color fade-in or fade-out, alpha goes from 0.0f to 1.0f. See [Color](Color)


### Misc. functions
#### SetConfigFlags
```lua
ray.core.SetConfigFlags(string flag1, string flag2, string flag3, ...)
```
Setup window configuration flags
Available flags:
* `"FULLSCREEN_MODE"   ` Set to run program in fullscreen
* `"WINDOW_RESIZABLE"  ` Set to allow resizable window
* `"WINDOW_UNDECORATED"` Set to disable window decoration (frame and buttons)
* `"WINDOW_TRANSPARENT"` Set to allow transparent window
* `"WINDOW_HIDDEN"     ` Set to create the window initially hidden
* `"WINDOW_ALWAYS_RUN" ` Set to allow windows running while minimized
* `"MSAA_4X_HINT"      ` Set to try enabling MSAA 4X
* `"VSYNC_HINT"        ` Set to try enabling V-Sync on GPU


#### SetTraceLogLevel
```lua
ray.core.SetTraceLogLevel(string Mode)
```
Set the current threshold (minimum) log level.
Available Modes:
* `"ALL"     ` Set to run program in fullscreen
* `"TRACE"   ` Set to allow resizable window
* `"DEBUG"   ` Set to disable window decoration (frame and buttons)
* `"INFO"    ` Set to allow transparent window
* `"WARNING" ` Set to create the window initially hidden
* `"ERROR"   ` Set to allow windows running while minimized
* `"FATAL"   ` Set to try enabling MSAA 4X
* `"NONE"    ` Set to try enabling V-Sync on GPU


### Files management functions
#### FileExists
```lua
ray.core.FileExists(string Filename)
```
Check if file exists


### Persistent storage management
#### StorageSaveValue
```lua
ray.core.StorageSaveValue(integer Position, integer Value)
```
Save integer value to storage file (to defined position)


### Input-related functions: keyb
#### IsKeyPressed
```lua
boolean State = ray.core.IsKeyPressed(integer Key)
```
Detect if a key has been pressed once


### Input-related functions: gamepads
#### IsGamepadAvailable
```lua
boolean State = ray.core.IsGamepadAvailable(integer Gamepad)
```
Detect if a gamepad is available


### Input-related functions: mouse
#### IsMouseButtonPressed
```lua
boolean State = ray.core.IsMouseButtonPressed(integer Button)
```
Detect if a mouse button has been pressed once


### Input-related functions: touch
#### GetTouchX
```lua
boolean State = ray.core.GetTouchX()
```
Returns touch position X for touch point 0 (relative to screen size)


### Camera System Functions (Module: camera)
#### SetCameraMode
```lua
ray.core.SetCameraMode(Camera3D Camera, string Mode)
```
Set camera mode. Availabke modes: 
* `"CUSTOM"` - default
* `"FREE"`
* `"ORBITAL"`
* `"FIRST_PERSON"`
* `"THIRD_PERSON"`


# Classes

## Vector2
### Initialization
```lua
-- variations
Vector2 vec = ray.Vector2(number x, number y) --> vec2[x, y]
Vector2 vec = ray.Vector2(number x)           --> vec2[x, x]
Vector2 vec = ray.Vector2(table t)            --> vec2[ t[1], t[2] ]
```
Creates new Vector2 object.


### Methods

#### Clone
```lua
Vector2 = Vector2:clone()
```
Clones Vector2 object.


#### Get
```lua
-- variations
float x, float y = Vector2:get()
table t = Vector2:get('t') --> {x, y}
```
Get Vector2 components.


#### Set
```lua
-- variations
float x, float y = Vector2:get()
table t = Vector2:get('t') --> {x, y}
```
Set Vector2 components.
