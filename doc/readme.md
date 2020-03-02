
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



## Core
### Core functions

#### Initialization
```lua
local rl = require("raylib_luamore")
```


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


#### WindowShouldClose
```lua
boolean Status = rl.core.WindowShouldClose()
```
Check if ESCAPE-key pressed or Close icon pressed.
See [SetExitKey](#SetExitKey).


#### CloseWindow
```lua
rl.core.CloseWindow()
```
Close window and unload OpenGL context.


#### IsWindowReady
```lua
boolean Status = rl.core.IsWindowReady()
```
Check if window has been initialized successfully.


#### IsWindowMinimized
```lua
boolean Status = rl.core.IsWindowMinimized()
```
Check if window has been minimized (or lost focus).


#### IsWindowResized
```lua
boolean Status = rl.core.IsWindowResized()
```
Check if window has been resized.


#### IsWindowHidden
```lua
boolean Status = rl.core.IsWindowHidden()
```
Check if window is currently hidden.


#### ToggleFullscreen
```lua
rl.core.ToggleFullscreen()
```
Toggle fullscreen mode (only PLATFORM_DESKTOP).


#### UnhideWindow
```lua
rl.core.UnhideWindow()
```
Show the window.


#### HideWindow
```lua
rl.core.HideWindow()
```
Hide the window.


#### SetWindowIcon
```lua
rl.core.SetWindowIcon(Image Icon)
```
Set icon for window (only PLATFORM_DESKTOP).
See [Image](#Image).


#### SetWindowTitle
```lua
rl.core.SetWindowTitle(string Title)
```
Set title for window (only PLATFORM_DESKTOP).


#### SetWindowPosition
```lua
rl.core.SetWindowPosition(string Title)
```
Set window position on screen (only PLATFORM_DESKTOP).


#### SetWindowMonitor
```lua
rl.core.SetWindowMonitor(integer Monitor)
```
Set monitor for the current window (fullscreen mode).


#### SetWindowMinSize
```lua
rl.core.SetWindowMinSize(integer Width, integer Height)
```
Set window minimum dimensions, for flag ["WINDOW_RESIZABLE"](#SetConfigFlags).


#### SetWindowSize
```lua
rl.core.SetWindowSize(integer Width, integer Height)
```
Set window dimensions.


#### GetWindowHandle
```lua
userdata Handle = rl.core.GetWindowHandle()
```
Get native window handle.
Use for FFI or something.


#### GetScreenWidth
```lua
integer Width = rl.core.GetScreenWidth()
```
Get current screen width.


#### GetScreenHeight
```lua
integer Height = rl.core.GetScreenHeight()
```
Get current screen height.


#### GetScreenDimensions
```lua
integer Width, integer Height = rl.core.GetScreenDimensions()
```
Get current screen dimensions.


#### GetMonitorCount
```lua
integer Count = rl.core.GetMonitorCount()
```
Get number of connected monitors.


#### GetMonitorWidth
```lua
integer Width = rl.core.GetMonitorWidth(integer Monitor)
```
Get selected monitor width.


#### GetMonitorHeight
```lua
integer Height = rl.core.GetMonitorHeight(integer Monitor)
```
Get selected monitor height.


#### GetMonitorDimensions
```lua
integer Width, integer Height = rl.core.GetMonitorDimensions(integer Monitor)
```
Get selected monitor dimensions.


#### GetMonitorPhysicalWidth
```lua
integer Width = rl.core.GetMonitorPhysicalWidth(integer Monitor)
```
Get selected monitor physical width in millimetres.


#### GetMonitorPhysicalHeight
```lua
integer Height = rl.core.GetMonitorPhysicalHeight(integer Monitor)
```
Get selected monitor physical height in millimetres.


#### GetMonitorPhysicalDimensions
```lua
integer Width, integer Height = rl.core.GetMonitorPhysicalDimensions(integer Monitor)
```
Get selected monitor physical dimensions in millimetres.


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


#### GetWindowPosition
```lua
Vector2 Position = rl.core.GetWindowPosition()
```
Get window position XY on monitor.
See [Vector2](#Vector2).


#### GetMonitorName
```lua
string Name = rl.core.GetMonitorName()
```
Get the human-readable, UTF-8 encoded name of the primary monitor.


#### GetClipboardText
```lua
string Text = rl.core.GetClipboardText()
```
Get clipboard text content.


#### SetClipboardText
```lua
rl.core.SetClipboardText(string Text)
```
Set clipboard text content.


### Cursor-related functions
#### ShowCursor
```lua
rl.core.ShowCursor()
```
Shows cursor.


#### HideCursor
```lua
rl.core.HideCursor()
```
Hides cursor.


#### IsCursorHidden
```lua
boolean Status = rl.core.IsCursorHidden()
```
Check if cursor is not visible.


#### EnableCursor
```lua
rl.core.EnableCursor()
```
Enables cursor (unlock cursor).


#### DisableCursor
```lua
rl.core.DisableCursor()
```
Disables cursor (lock cursor).


### Drawing-related functions
#### ClearBackground
```lua
rl.core.ClearBackground(Color Color)
```
Set background color (framebuffer clear color).
See [Color](#Color).


#### BeginDrawing
```lua
rl.core.BeginDrawing()
```
Setup canvas (framebuffer) to start drawing.


#### EndDrawing
```lua
rl.core.EndDrawing()
```
End canvas drawing and swap buffers (double buffering).


#### BeginMode2D
```lua
rl.core.BeginMode2D(Camera2D Camera)
```
Initialize 2D mode with custom camera (2D).
See [Camera2D](#Camera2D).


#### EndMode2D
```lua
rl.core.EndMode2D()
```
Ends 2D mode with custom camera.


#### BeginMode3D
```lua
rl.core.BeginMode3D(Camera3D Camera)
```
Initializes 3D mode with custom camera (3D).
See [Camera3D](#Camera3D).


#### EndMode3D
```lua
rl.core.EndMode3D()
```
Ends 3D mode and returns to default 2D orthographic mode.


#### BeginTextureMode
```lua
rl.core.BeginTextureMode(RenderTexture Texture)
```
Initializes render texture for drawing.
See [RenderTexture](#RenderTexture).


#### EndTextureMode
```lua
rl.core.EndTextureMode()
```
Ends drawing to render texture.


#### BeginScissorMode
```lua
rl.core.BeginScissorMode(integer X, integer Y, integer Width, integer Height)
```
Begin scissor mode (define screen area for following drawing).


#### EndScissorMode
```lua
rl.core.EndScissorMode()
```
End scissor mode.


### Screen-space-related functions
#### GetMouseRay
```lua
-- variants
Ray Ray = rl.core.GetMouseRay(Vector2 Vector, Camera3D Camera)
Vector2 Position, Vector2 Direction = rl.core.GetMouseRay(Vector2 Vector, Camera3D Camera, "v")
```
Returns a ray trace from mouse position.
See [Ray](#Ray), [Vector2](#Vector2).


#### GetCameraMatrix
```lua
Matrix View = rl.core.GetCameraMatrix(Camera3D Camera)
```
Returns camera transform matrix (view matrix).
See [Matrix](#Matrix).


#### GetCameraMatrix2D
```lua
Matrix View = rl.core.GetCameraMatrix2D(Camera2D Camera)
```
Returns camera 2d transform matrix.
See [Matrix](#Matrix), [Camera2D](#Camera2D).


#### GetWorldToScreen
```lua
Vector2 ScreenV = rl.core.GetWorldToScreen(Vector3 Vector, Camera3D Camera)
```
Returns the screen space position for a 3d world space position.
See [Vector2](#Vector2), [Vector3](#Vector3), [Camera3D](#Camera3D).


#### GetWorldToScreenEx
```lua
Vector2 ScreenV = rl.core.GetWorldToScreenEx(Vector3 Vector, Camera3D Camera, integer Width, integer Height)
```
Returns size position for a 3d world space position.
See [Vector2](#Vector2), [Vector3](#Vector3), [Camera3D](#Camera3D).


#### GetWorldToScreen2D
```lua
Vector2 ScreenV = rl.core.GetWorldToScreen2D(Vector2 Vector, Camera2D Camera)
```
Returns the screen space position for a 2d camera world space position.
See [Vector2](#Vector2), [Camera2D](#Camera2D).


#### GetScreenToWorld2D
```lua
Vector2 ScreenV = rl.core.GetScreenToWorld2D(Vector2 Vector, Camera2D Camera)
```
Returns the world space position for a 2d camera screen space position.
See [Vector2](#Vector2), [Camera2D](#Camera2D).


### Timing-related functions
#### SetTargetFPS
```lua
rl.core.SetTargetFPS(integer FPS)
```
Set target FPS (maximum).


#### GetFPS
```lua
integer FPS = rl.core.GetFPS()
```
Returns current FPS.


#### GetFrameTime
```lua
float DT = rl.core.GetFrameTime()
```
Returns time in seconds for last frame drawn.


#### GetTime
```lua
float Time = rl.core.GetTime()
```
Returns elapsed time in seconds since InitWindow().


### Color-related functions
#### ColorToInt
```lua
integer iColor = rl.core.ColorToInt(Color Color)
```
Returns hexadecimal value for a Color.


#### ColorNormalize
```lua
-- variants
Vector4 vColor = rl.core.ColorNormalize(Color Color)
integer NR, integer NG, integer NB, integer NA = rl.core.ColorNormalize(Color Color, "n")
table tColor = rl.core.ColorNormalize(Color Color, "t") -- Array {float r, float g, float b, float a}
```
Returns color normalized as float [0..1].
See [Vector4](#Vector4), [Color](#Color).


#### ColorFromNormalized
```lua
-- variants
Color Color = rl.core.ColorFromNormalized(Vector4 vColor)
Color Color = rl.core.ColorFromNormalized(float R, float G, float B[, float A])
Color Color = rl.core.ColorFromNormalized(table tColor) -- Array {float r, float g, float b[, float a]}
```
Returns color from normalized values [0..1].
See [Vector4](#Vector4), [Color](#Color).


#### ColorToHSV
```lua
-- variants
Vector3 vColor = rl.core.ColorToHSV(Color Color)
float Hue, float Saturation, float Value = rl.core.ColorToHSV(Color Color, "n")
table hsvColor = rl.core.ColorNormalize(Color Color, "t") -- Array {float h, float s, float v}
```
Returns HSV values for a Color.
See [Vector3](#Vector3), [Color](#Color).


#### ColorFromHSV
```lua
-- variants
Color Color = rl.core.ColorFromHSV(Vector3 vColor)
Color Color = rl.core.ColorFromHSV(float H, float S, float V)
Color Color = rl.core.ColorFromHSV(table hsvColor) -- Array {float h, float s, float v}
```
Returns a Color from HSV values.
See [Vector3](#Vector3), [Color](#Color).


#### GetColor
```lua
-- variants
Color Color = rl.core.GetColor(integer hColor)
```
Returns a Color struct from hexadecimal value.
See [Color](#Color)


#### Fade
```lua
-- variants
Color fColor = rl.core.Fade(Color Color, float alpha)
```
Color fade-in or fade-out, alpha goes from 0.0f to 1.0f.
See [Color](#Color)


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


#### TraceLog
```lua
rl.core.TraceLog(string logLevel, string Message)
```
Show trace log messages.
logLevel is string constant 
`"TRACE"`, `"DEBUG"`, `"INFO"`, `"WARNING"`, 
`"ERROR"` or `"FATAL"`.

`"DEBUG"` is default.


#### TakeScreenshot
```lua
rl.core.TakeScreenshot(string fName)
```
Takes a screenshot of current screen (saved a .png).


#### GetRandomValue
```lua
-- variat
integer RndValue = rl.core.GetRandomValue(integer Min, integer Max) -- [Mix .. Max]
integer RndValue = rl.core.GetRandomValue(integer Max)              -- [1   .. Max]
```
Returns a random value between min and max (both included).


### Files management functions
#### FileExists
```lua
boolean Status = rl.core.FileExists(string FileName)
```
Check if file exists.


#### IsFileExtension
```lua
boolean Status = rl.core.IsFileExtension(string FileName, string Ext)
```
Check file extension.


#### DirectoryExists
```lua
boolean Status = rl.core.DirectoryExists(string DirectoryPath)
```
Check if a directory path exists.


#### DirectoryExists
```lua
string Ext = rl.core.GetExtension(string FileName)
```
Get a extension for a filename string.


#### GetFileName
```lua
string FileName = rl.core.GetFileName(string FilePath)
```
Get a filename for a path string.


#### GetFileNameWithoutExt
```lua
string FileName = rl.core.GetFileNameWithoutExt(string FilePath)
```
Get filename string without extension.


#### GetDirectoryPath
```lua
string DirectoryPath = rl.core.GetDirectoryPath(string FilePath)
```
Get full path for a given fileName with path.


#### GetPrevDirectoryPath
```lua
string DirectoryPath = rl.core.GetPrevDirectoryPath(string FilePath)
```
Get previous directory path for a given path.


#### GetWorkingDirectory
```lua
string DirectoryPath = rl.core.GetWorkingDirectory()
```
Get current working directory.


#### GetDirectoryFiles
```lua
table Files = rl.core.GetDirectoryFiles(string DirectoryPath)
```
Get filenames in a directory path. [ClearDirectoryFiles](#ClearDirectoryFiles) is called automatically.
Table Files contains string names like `{"file1.png", "directory1", "file2.lua", ...}`.


#### ClearDirectoryFiles
```lua
rl.core.ClearDirectoryFiles()
```
Clear directory files paths buffers (free memory). Deprecated.


#### ChangeDirectory
```lua
boolean Status = rl.core.ChangeDirectory(string DirectoryPath)
```
Change working directory, returns true if success.


#### IsFileDropped
```lua
boolean Status = rl.core.IsFileDropped()
```
Check if a file has been dropped into window.


#### GetDroppedFiles
```lua
table Files = rl.core.GetDroppedFiles()
```
Get dropped files names. [ClearDroppedFiles](#ClearDroppedFiles) is called automatically.
Table Files contains string names like `{"file1.png", "file2.lua", ...}`.


#### ClearDroppedFiles
```lua
rl.core.ClearDroppedFiles()
```
Clear dropped files paths buffer (free memory). Deprecated.


#### GetFileModTime
```lua
integer Time = rl.core.GetFileModTime(string FilePath)
```
Get file modification time (last write timestamp).


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


#### CompressData
```lua
string CompressedData = rl.core.CompressData(string Data)
```
Compress data (DEFLATE algorythm).


#### DecompressData
```lua
string Data = rl.core.DecompressData(string CompressedData)
```
Deompress data (DEFLATE algorythm).


#### OpenURL
```lua
rl.core.OpenURL(string URL)
```
Open URL with default system browser (if available).


### Persistent storage management
#### StorageSaveValue
```lua
rl.core.StorageSaveValue(integer Position, integer Value)
```
Save integer value to storage file (to defined position).


#### StorageLoadValue
```lua
integer Value = rl.core.StorageLoadValue(integer Position)
```
Load integer value from storage file (from defined position).


### Input-related functions: keyb
#### IsKeyPressed
```lua
boolean State = rl.core.IsKeyPressed(eKey Key[, ekey Key2, ...])
```
Detect if a key has been pressed once. See [eKey](#eKey).


#### IsKeyDown
```lua
boolean State = rl.core.IsKeyDown(eKey Key[, eKey Key2, ...])
```
Detect if a key is being pressed. See [eKey](#eKey).


#### IsKeyReleased
```lua
boolean State = rl.core.IsKeyReleased(eKey Key[, eKey Key2, ...])
```
Detect if a key has been released once. See [eKey](#eKey).


#### IsKeyUp
```lua
boolean State = rl.core.IsKeyUp(eKey Key[, eKey Key2, ...])
```
Detect if a key is NOT being pressed. See [eKey](#eKey).


#### GetKeyPressed
```lua
integer Key = rl.core.GetKeyPressed()
```
Get latest key scancode pressed.


#### GetKeyPressedString
```lua
string Char = rl.core.GetKeyPressedString()
```
Get user input UTF-8 encoded string char.


#### GetAllKeysPressedString
```lua
string Text = rl.core.GetAllKeysPressedString()
```
Get all user UTF-8 encoded string input chars.


#### SetExitKey
```lua
rl.core.SetExitKey(eKey Key)
```
Set a custom key to exit program (default is ESC). See [eKey](#eKey).


### Input-related functions: gamepads
#### IsGamepadAvailable
```lua
boolean State = rl.core.IsGamepadAvailable(integer Gamepad)
```
Detect if a gamepad is available.


#### IsGamepadName
```lua
boolean State = rl.core.IsGamepadName(integer Gamepad, string GamepadName)
```
Check gamepad name (if available).


#### GetGamepadName
```lua
string GamepadName = rl.core.GetGamepadName(integer Gamepad)
```
Check gamepad name (if available).


#### IsGamepadButtonPressed
```lua
boolean Status = rl.core.IsGamepadButtonPressed(integer Gamepad)
```
Detect if a gamepad button has been pressed once.


#### IsGamepadButtonDown
```lua
boolean Status = rl.core.IsGamepadButtonDown(integer Gamepad)
```
Detect if a gamepad button is being pressed.


#### IsGamepadButtonReleased
```lua
boolean Status = rl.core.IsGamepadButtonReleased(integer Gamepad)
```
Detect if a gamepad button has been released once.


#### IsGamepadButtonUp
```lua
boolean Status = rl.core.IsGamepadButtonUp(integer Gamepad)
```
Detect if a gamepad button is NOT being pressed.


#### GetGamepadButtonPressed
```lua
integer Key = rl.core.GetGamepadButtonPressed()
```
Get the last gamepad button pressed.


#### GetGamepadAxisCount
```lua
integer Count = rl.core.GetGamepadAxisCount()
```
Return gamepad axis count for a gamepad.


#### GetGamepadAxisMovement
```lua
float Movement = rl.core.GetGamepadAxisMovement(integer Gamepad)
```
Return axis movement value for a gamepad axis.


### Input-related functions: mouse
#### IsMouseButtonPressed
```lua
boolean State = rl.core.IsMouseButtonPressed(integer Button)
```
Detect if a mouse button has been pressed once.


#### IsMouseButtonDown
```lua
boolean State = rl.core.IsMouseButtonDown(integer Button)
```
Detect if a mouse button is being pressed.


#### IsMouseButtonReleased
```lua
boolean State = rl.core.IsMouseButtonReleased(integer Button)
```
Detect if a mouse button has been released once.


#### IsMouseButtonUp
```lua
boolean State = rl.core.IsMouseButtonUp(integer Button)
```
Detect if a mouse button is NOT being pressed.


#### GetMouseX
```lua
integer X = rl.core.GetMouseX()
```
Returns mouse position X.


#### GetMouseY
```lua
integer Y = rl.core.GetMouseY()
```
Returns mouse position Y.


#### GetMousePosition
```lua
-- variants
Vector2 Position     = rl.core.GetMousePosition()
integer X, integer Y = rl.core.GetMousePosition('n')
```
Returns mouse position XY.


#### SetMousePosition
```lua
-- variants
rl.core.SetMousePosition(Vector2 Position)
rl.core.SetMousePosition(integer X, integer Y)
```
Set mouse position XY.


#### SetMouseOffset
```lua
-- variants
rl.core.SetMouseOffset(Vector2 Offset)
rl.core.SetMouseOffset(integer X, integer Y)
```
Set mouse offset.


#### SetMouseScale
```lua
-- variants
rl.core.SetMouseScale(Vector2 Scale)
rl.core.SetMouseScale(integer X, integer Y)
```
Set mouse scaling.


#### GetMouseWheelMove
```lua
-- variants
integer WheelMove = rl.core.GetMouseWheelMove()
```
Returns mouse wheel movement Y.


### Input-related functions: touch
#### GetTouchX
```lua
integer X = rl.core.GetTouchX()
```
Returns touch position X for touch point 1 (relative to screen size).


#### GetTouchY
```lua
integer Y = rl.core.GetTouchY()
```
Returns touch position Y for touch point 1 (relative to screen size).


#### GetTouch
```lua
integer X, integer Y = rl.core.GetTouch()
```
Returns touch position XY for a touch point 1 (relative to screen size).


#### GetTouchPosition
```lua
-- veriants
Vector2 Position     = rl.core.GetTouchPosition(integer Index)
integer X, integer Y = rl.core.GetTouchPosition(integer Index, 'n')
```
Returns touch position XY for a touch point index (relative to screen size).


#### GetTouches
```lua
-- veriants
table Touches = rl.core.GetTouches(integer Index)      -- {Vector2 t1, Vector2 t2, ...}
table Touches = rl.core.GetTouches(integer Index, 'n') -- {{integer X1, integer Y1}, {integer X2, integer Y2}, ...}
```
Returns all touches positions XY (relative to screen size).


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
* `"PINCH_IN"` returns float PinchVectorX, float PinchVectorY, float PinchAngle if 'n' is passed
* `"PINCH_OUT"` same as `"PINCH_IN"`.


#### GetTouchPointsCount
```lua
integer Count = rl.core.GetTouchPointsCount()
```
Get touch points count.


#### GetGestureHoldDuration
```lua
float Duration = rl.core.GetGestureHoldDuration()
```
Get gesture hold time in milliseconds.


#### GetGestureHoldDuration
```lua
-- variants
Vector2 DragVector = rl.core.GetGestureDragVector()
float vX, float vY = rl.core.GetGestureDragVector('n')
```
Get gesture drag vector.


#### GetGestureDragAngle
```lua
float Angle = rl.core.GetGestureDragAngle()
```
Get gesture drag angle.


#### GetGesturePinchVector
```lua
-- variants
Vector2 PinchVector = rl.core.GetGesturePinchVector()
float dX, float dY  = rl.core.GetGesturePinchVector('n')
```
Get gesture pinch delta.


#### GetGesturePinchAngle
```lua
float Angle = rl.core.GetGesturePinchAngle()
```
Get gesture pinch angle.


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


#### UpdateCamera
```lua
rl.core.UpdateCamera(Camera3D Camera)
```
Update camera position for selected mode.


#### SetCameraPanControl
```lua
rl.core.SetCameraPanControl(eKey panKey)
```
Set camera pan key to combine with mouse movement (free camera). See [Camera](#Camera), [eKey](#eKey).


#### SetCameraAltControl
```lua
rl.core.SetCameraAltControl(eKey altKey)
```
Set camera alt key to combine with mouse movement (free camera). See [Camera](#Camera), [eKey](#eKey).


#### SetCameraSmoothZoomControl
```lua
rl.core.SetCameraSmoothZoomControl(integer szKey)
```
Set camera smooth zoom key to combine with mouse (free camera). See [Camera](#Camera), [eKeyboard](#eKeyboard).


#### SetCameraMoveControls
```lua
rl.core.SetCameraMoveControls(eKey frontKey, eKey backKey, eKey rightKey, eKey leftKey, eKey upKey, eKey downKey)
```
Set camera move controls (1st person and 3rd person cameras). See [Camera](#Camera), [eKey](#eKey).


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


### Methods

#### Vector2:clone
```lua
Vector2 Vec2 = Vector2:clone()
```
Clones Vector2 object.


#### Vector2:get
```lua
-- variants
number x, number y = Vector2:get()
table t = Vector2:get('t') --> {x, y}
```
Get Vector2 components.


#### Vector2:set
```lua
-- variants
Vector2:set(float x, float y)
Vector2:set(table t) -- [x, y]
```
Set Vector2 components.


#### Vector2:add
```lua
Vector2:add(Vector2 Vector)
```
Add vector to vector (modifying it)


#### Vector2:subtract
```lua
Vector2:subtract(Vector2 Vector)
```
Subtract vector from vector (modifying it)


#### Vector2:length
```lua
number Length = Vector2:length()
```
Returns vector scalar length


#### Vector2:dotProduct
```lua
number Dot = Vector2:dotProduct(Vector2 Vector)
```
Returns vector scalar dot product


#### Vector2:distance
```lua
number Distance = Vector2:distance(Vector2 Vector)
```
Returns scalar distance between two vectors


#### Vector2:angle
```lua
number Angle = Vector2:angle(Vector2 Vector)
```
Returns scalar angle between two vectors (degrees)


#### Vector2:angleRad
```lua
number Angle = Vector2:angleRad(Vector2 Vector)
```
Returns scalar angle between two vectors (radians)


#### Vector2:scale
```lua
Vector2:scale(number Scale)
```
Multiply each component of vector to scalar


#### Vector2:multiplyV
```lua
Vector2:multiplyV(Vector2 Vector)
```
Multiply vector to another vector (modifying it)


#### Vector2:multiply
```lua
-- variants
Vector2:multiply(Vector2 Vector)
Vector2:multiply(number Scale)
```
Multiply vector to scalar or another vector (modifying it)


#### Vector2:negate
```lua
Vector2:negate()
```
Negate each component of vector (-Vec2.x, -Vec2.y)


#### Vector2:divide
```lua
-- variants
Vector2:divide(Vector2 Vector)
Vector2:divide(number Scale)
```
Divide vector to scalar or another vector (modifying it)


#### Vector2:divideV
```lua
Vector2:divideV(Vector2 Vector)
```
Divide vector to another vector (modifying it)


#### Vector2:normalize
```lua
Vector2:normalize()
```
Normalize vector (divide each component lo vector length)


#### Vector2:lerp
```lua
Vector2:lerp(Vector2 Vector, number Amount)
```
Interpolate vector to another by given interpolant


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


### Methods

#### Vector3:clone
```lua
Vector3 Vec3 = Vector3:clone()
```
Clones Vector3 object.


#### Vector3:get
```lua
-- variants
number x, number y, number z = Vector3:get()
table t = Vector3:get('t') --> {x, y, z}
```
Get Vector3 components.


#### Vector3:set
```lua
-- variants
Vector3:set(number x, number y, number z)
Vector3:set(table t) -- [x, y, z]
```
Set Vector3 components.


#### Vector3:add
```lua
Vector3:add(Vector3 Vector)
```
Add vector to vector (modifying it)


#### Vector3:subtract
```lua
Vector3:subtract(Vector3 Vector)
```
Subtract vector to vector (modifying it)


#### Vector3:scale
```lua
Vector3:scale(number Scale)
```
Multiply each component of vector to scalar


#### Vector3:multiplyV
```lua
Vector3:multiplyV(Vector3 Vector)
```
Multiply vector to another vector (modifying it)


#### Vector3:multiply
```lua
-- variants
Vector3:multiply(Vector3 Vector)
Vector3:multiply(number Scale)
```
Multiply vector to scalar or another vector (modifying it)


#### Vector3:crossProduct
```lua
Vector3:crossProduct(Vector3 Vector)
```
Transform vector to cross product of two vectors


#### Vector3:perpendicular
```lua
Vector3:perpendicular(Vector3 Vector)
```
Calculate one vector perpendicular vector


#### Vector3:length
```lua
number Length = Vector3:length()
```
Returns vector scalar length


#### Vector3:dotProduct
```lua
number Dot = Vector3:dotProduct(Vector3 Vector)
```
Returns scalar dot product of two vectors


#### Vector3:distance
```lua
number Distance = Vector3:distance(Vector3 Vector)
```
Returns scalar distance between two vectors


#### Vector3:negate
```lua
Vector3:negate()
```
Negate each component of vector (-Vec3.x, -Vec3.y, -Vec3.z)


#### Vector3:divide
```lua
-- variants
Vector3:divide(Vector3 Vector)
Vector3:divide(number Scale)
```
Divide vector to scalar or another vector (modifying it)


#### Vector3:divideV
```lua
Vector3:divideV(Vector3 Vector)
```
Divide vector to another vector (modifying it)


#### Vector3:normalize
```lua
Vector3:normalize()
```
Normalize vector (divide each component lo vector length)


#### Vector3:orthoNormalize
```lua
Vector3:orthoNormalize(Vector3 Vector)
```
Makes vectors normalized and orthogonal to each other modifying both


#### Vector3:transform
```lua
Vector3:transform(Matrix Matrix)
```
Transforms a vector by a given Matrix


#### Vector3:rotateByQuaternion
```lua
Vector3:rotateByQuaternion(Vector4 Quaternion)
```
Transform a vector by quaternion rotation


#### Vector3:lerp
```lua
Vector3:lerp(Vector3 Vector, number Amount)
```
Interpolate vector to another by given interpolant


#### Vector3:reflect
```lua
Vector3:reflect(Vector3 Normal)
```
Calculate reflected vector to normal


#### Vector3:min
```lua
number Min = Vector3:min()
```
Return min value for each pair of components


#### Vector3:max
```lua
number max = Vector3:min()
```
Return max value for each pair of components


#### Vector3:barycenter
```lua
Vector3 Barycenter = Vector3:barycenter(Vector3 A, Vector3 B, Vector3 C)
```
Create new vector that is barycenter coordinates (u, v, w) for point p with respect to triangle (A, B, C)


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


#### Matrix:clone
```lua
Matrix Matrix = Matrix:clone()
```
Creates copy of matrix


#### Matrix:get
```lua
-- variants
number m1, number m2, ... number m16 = Matrix:get()
table Table = Matrix:get('t') --> Table[m1, m2, ... m16]
```
Returns matrix fields


#### Matrix:set
```lua
-- variants
Matrix:set(number m1, number m2, ... number m16)
Matrix:set(table Table) -- Table[m1, m2, ... m16]
```
Assing values to matrix


#### Matrix:determinant
```lua
number Determinant = Matrix:determinant()
```
Compute matrix determinant


#### Matrix:trace
```lua
number Trace = Matrix:trace()
```
Returns the trace of the matrix (sum of the values along the diagonal)


#### Matrix:transpose
```lua
Matrix:transpose()
```
Transposes provided matrix (modifying it)


#### Matrix:invert
```lua
Matrix:invert()
```
Transposes provided matrix (modifying it)


#### Matrix:normalize
```lua
Matrix:normalize()
```
Normalize provided matrix (modifying it)


#### Matrix:identity
```lua
Matrix:identity()
```
Modify matrix to identity matrix


#### Matrix:add
```lua
Matrix:add(Matrix Matrix)
```
Add matrix to matrix (modifying it)


#### Matrix:subtract
```lua
Matrix:subtract(Matrix Matrix)
```
Subtract matrix from matrix (modifying it)


#### Matrix:translate
```lua
-- variants
Matrix:translate(number x, number y, number z)
Matrix:translate(table Translate) -- Translate[x, y, z]
Matrix:translate(Vector3 Vector)
```
Modify matrix to translation by given vector matrix


#### Matrix:rotate
```lua
Matrix:rotate(Vector3 Vector, number Angle)
```
Modify matrix to rotation matrix from axis and angle (radians)


#### Matrix:rotateXYZ
```lua
Matrix:rotateXYZ(Vector3 Vector)
```
Rotate matrix to given Vector3 (angles in radians)


#### Matrix:rotateX
```lua
Matrix:rotateX(number Angle)
```
Rotate matrix to given angle along X-axis. (angle in radians)


#### Matrix:rotateY
```lua
Matrix:rotateY(number Angle)
```
Rotate matrix to given angle along Y-axis. (angle in radians)


#### Matrix:rotateZ
```lua
Matrix:rotateZ(number Angle)
```
Rotate matrix to given angle along Z-axis. (angle in radians)


#### Matrix:scale
```lua
-- variants
Matrix:scale(number x, number y, number z)
Matrix:scale(table Scale)    -- Scale[x, y, z]
Matrix:scale(Vector3 Vector)

```
Scale matrix by given vector


#### Matrix:multiply
```lua
-- variants
Matrix:multiply(Matrix Matrix)
```
Multiply matrix to another (modifying it)


#### Matrix:frustrum
```lua
Matrix:frustum(number Left, number Right, number Bottom, numner Top, number Near, number Far)
```
Modify matrix to perspective projection matrix


#### Matrix:perspective
```lua
Matrix:perspective(number FovY, number Aspect, number Near, numner Far, number Top)
```
Modify matrix to perspective projection matrix (by angles in radians)


#### Matrix:ortho
```lua
Matrix:ortho(number Left, number Right, number Bottom, numner Top, number Near, number Far)
```
Modify matrix to orthographic projection matrix


#### Matrix:lookAt
```lua
Matrix:lookAt(Vector3 Eye, Vector3 Target, Vector3 Up)
```
Modify matrix to look-at point by three vectors


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


#### Vector4:clone
```lua
Vector4 Vec4 = Vector4:clone()
```
Creates copy of vector


#### Vector4:get
```lua
-- variants
number x, number y, number z, number w = Vector4:get()
table t = Vector4:get('t') --> {x, y, z, w}
```
Get Vector4 components.


#### Vector4:set
```lua
-- variants
Vector4:set(number x, number y, number z, number w)
Vector4:set(table t) -- [x, y, z, w]
```
Set Vector4 components.


#### Vector4:add
```lua
Vector4:add(Vector4 Vector)
```
Add vector to vector (modifying it)


#### Vector4:subtract
```lua
Vector4:subtract(Vector4 Vector)
```
Subtract vector from vector (modifying it)


#### Vector4:scale
```lua
Vector4:subtract(number Scale)
```
Multiply each component of vector to scalar


#### Vector4:multiplyV
```lua
Vector4:multiplyV(Vector4 Vector)
```
Multiply vector to another vector (modifying it)


#### Vector4:multiply
```lua
-- variants
Vector4:multiply(number Scale)
Vector4:multiply(Vector4 Vector)
```
Multiply vector to scalar or another vector (modifying it)


#### Vector4:identity
```lua
Vector4:identity()
```
Set vector components to quaternion identity


#### Vector4:length
```lua
number Length = Vector4:length()
```
Returns vector scalar length


#### Vector4:normalize
```lua
Vector4:normalize()
```
Normalize provided quaternion


#### Vector4:qInvert
```lua
Vector4:qInvert()
```
Invert provided quaternion


#### Vector4:qMultiply
```lua
Vector4:qMultiply(Vector4 Vector)
```
Multiply quaternion to another (modifying it)


#### Vector4:qLerp
```lua
Vector4:qLerp(Vector4 Vector, scale Amount)
```
Linear interpolate quaternion to another by given interpolant


#### Vector4:qNlerp
```lua
Vector4:qNlerp(Vector4 Vector, scale Amount)
```
Linear interpolate quaternion to another by given interpolant, and normalize it


#### Vector4:qSlerp
```lua
Vector4:qSlerp(Vector4 Vector, scale Amount)
```
Spherical interpolate quaternion to another by given interpolant


#### Vector4:qFromVector3ToVector3
```lua
Vector4:qFromVector3ToVector3(Vector3 Vector1, Vector3 Vector2)
```
Calculate quaternion based on the rotation from one vector to another


#### Vector4:qFromMatrix
```lua
Vector4:qFromMatrix(Matrix Matrix)
```
Set vector components to a quaternion for a given rotation matrix


#### Vector4:qToMatrix
```lua
Matrix Matrix = Vector4:qToMatrix()
```
Returns a matrix for a given quaternion


#### Vector4:qFromAxisAngle
```lua
Vector4:qFromAxisAngle(Vector3 Vector, number Angle)
```
Set vector components to a rotation quaternion for an angle and axis (radians)


#### Vector4:qToAxisAngle
```lua
Vector3 Vector, number Angle = Vector4:qToAxisAngle()
```
Returns the rotation angle and axis for a given quaternion


#### Vector4:qFromEuler
```lua
Vector4:qFromEuler(number Roll, number Pitch, number Yaw)
```
Set vector components to a quaternion equivalent of Euler angles


#### Vector4:qToEuler
```lua
number Roll, number Pitch, number Yaw = Vector4:qToEuler()
```
Return the Euler angles equivalent to quaternion (roll, pitch, yaw)


#### Vector4:qTransform
```lua
Vector4:qTransform(Matrix Matrix)
```
Transform a quaternion given a transformation matrix


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



#### Color:clone
```lua
Color Color = Color:clone()
```
Creates copy of color


#### Color:get
```lua
-- variants
integer r, integer g, integer b, integer a = Color:get()
table t = Color:get('t') -- t[r, g, b, a]
```
Return vector fields


#### Color:set
```lua
-- variants
Color:set(integer r, integer g, integer b[, integer a])
Color:set(table t) -- t[r, g, b, a]
```
Assing values to color components


#### Color:toInt
```lua
integer Color = Color:toInt()
```
Return color integer representation


#### Color:fromInt
```lua
Color:fromInt(integer Color)
```
Set color components from a given integer


#### Color:normalize
```lua
-- variants
Vector4 Vector = Color:normalize()
float r, float g, float b, float a = Color:normalize('n')
table t = Color:normalize('t')
```
Return normalized color components [float r/255, float g/255, float b/255, float a/255]


#### Color:fromNormalized
```lua
-- variants
Color:fromNormalized(Vector4 Vector)
Color:fromNormalized(float r, float g, float b, float a)
Color:fromNormalized(table t)
```
Set color components from a given normalized values


#### Color:toHSV
```lua
number Hue, number Value, number Saturation = Color:toHSV()
```
Return color hue, value and saturation


#### Color:fromHSV
```lua
Color:fromHSV(number Hue, number Value, number Saturation)
```
Set color components from a given hue, value and saturation


#### Color:fade
```lua
Color:fade(number Alpha)
```
Color fade-in or fade-out, alpha goes from 0.0f to 1.0f


## Rectangle
### Initialization
```lua
-- variants
Rectangle Rect = rl.Rectangle(number x, number y, number width,  number height)
Rectangle Rect = rl.Rectangle(table t) --> Rectangle[ x = t[1], y = t[2], width = t[3], height = t[4] ]
```


## Image
### Initialization
```lua
--
```


## Texture
### Initialization
```lua
--
```


## RenderTexture
### Initialization
```lua
--
```


## NPatchInfo
### Initialization
```lua
--
```


## CharInfo
### Initialization
```lua
--
```


## Font
### Initialization
```lua
--
```


## Camera3D
### Initialization
```lua
--
```


## Camera2D
### Initialization
```lua
--
```


## Mesh
### Initialization
```lua
--
```


## Shader
### Initialization
```lua
--
```


## MaterialMap
### Initialization
```lua
--
```


## Material
### Initialization
```lua
--
```


## Model
### Initialization
```lua
--
```


## Transform
### Initialization
```lua
--
```


## BoneInfo
### Initialization
```lua
--
```


## ModelAnimation
### Initialization
```lua
--
```


## Ray
### Initialization
```lua
--
```


## RayHitInfo
### Initialization
```lua
--
```


## BoundingBox
### Initialization
```lua
--
```


## Wave
### Initialization
```lua
--
```


## Sound
### Initialization
```lua
--
```


## Music
### Initialization
```lua
--
```


## AudioStream
### Initialization
```lua
--
```


## VrDeviceInfo
### Initialization
```lua
--
```


## Enums
### eKey
eKey is the string or integer representation of keyboard scancode in American layout.
Any keyboard function accepts strings and integers both.
Representation layout:

| integer                  | string     | description
| :------                  | :--------- | :-----------
| **Character keys**       |            |
| -1                       | unknown    | The pressed key is unknown (used if user tries to use unknown string as key)
| 32                       | space      | Space key
| 39                       | '          | Single quote key
| 44                       | ,          | Comma key
| 45                       | -          | Hyphen-minus key
| 46                       | .          | Full stop key
| 47                       | /          | Slash key
| 48                       | 0          | The zero key
| 49                       | 1          | The one key
| 50                       | 2          | The two key
| 51                       | 3          | The three key
| 52                       | 4          | The four key
| 53                       | 5          | The five key
| 54                       | 6          | The six key
| 55                       | 7          | The seven key
| 56                       | 8          | The eight key
| 57                       | 9          | The nine key
| 59                       | ;          | Semicolon key
| 61                       | =          | Equal key
| 65                       | a          | The A key
| 66                       | b          | The B key
| 67                       | c          | The C key
| 68                       | d          | The D key
| 69                       | e          | The E key
| 70                       | f          | The F key
| 71                       | g          | The G key
| 72                       | h          | The H key
| 73                       | i          | The I key
| 74                       | j          | The J key
| 75                       | k          | The K key
| 76                       | l          | The L key
| 77                       | m          | The M key
| 78                       | n          | The N key
| 79                       | o          | The O key
| 80                       | p          | The P key
| 81                       | q          | The Q key
| 82                       | r          | The R key
| 83                       | s          | The S key
| 84                       | t          | The T key
| 85                       | u          | The U key
| 86                       | v          | The V key
| 87                       | w          | The W key
| 88                       | x          | The X key
| 89                       | y          | The Y key
| 90                       | z          | The Z key
| 91                       | \[         | Left square bracket key
| 92                       | \\         | Backslash key
| 93                       | \]         | Right square bracket key
| 96                       | \`         | Grave accent key, also known as the "Back tick" key
| **Editing keys**         |            | 
| 258                      | tab        | Tab key
| 259                      | backspace  | Backspace key
| 260                      | insert     | Insert key
| 261                      | delete     | Delete key
| **Navigation keys**      |            |
| 256                      | escape     | Escape key
| 257                      | enter      | Enter key, also known as the Return key
| 257                      | return     | Return key, also known as the Enter key
| 262                      | right      | Right arrow key
| 263                      | left       | Left arrow key
| 264                      | down       | Down arrow key
| 265                      | up         | Up arrow key
| 266                      | pageup     | Page up key
| 267                      | pagedown   | Page down key
| 268                      | home       | Home key
| 269                      | end        | End key
| **Miscellaneous keys**   |            |
| 280                      | capslock   | Caps-lock key, caps-on is a key press. Caps-off is a key release.
| 281                      | scrolllock | Scroll-lock key
| 282                      | numlock    | Num-lock key, clear on Mac keyboards.
| 283                      | prtscr     | Printscreen key
| 284                      | pause      | Pause key
| 348                      | menu       | Menu key
| **Function keys**        |            |
| 290                      | f1         | The 1st function key
| 291                      | f2         | The 2nd function key
| 292                      | f3         | The 3rd function key
| 293                      | f4         | The 4th function key
| 294                      | f5         | The 5th function key
| 295                      | f6         | The 6th function key
| 296                      | f7         | The 7th function key
| 297                      | f8         | The 8th function key
| 298                      | f9         | The 9th function key
| 299                      | f10        | The 10th function key
| 300                      | f11        | The 11th function key	
| 301                      | f12        | The 12th function key
| **Modifier keys**        |            |
| 340                      | lshift     | Left shift key
| 341                      | lctrl      | Left control key
| 342                      | lalt       | Left alt key
| 343                      | lsuper     | Left command key in OS X, Windows key in Windows.
| 344                      | rshift     | Right shift key
| 345                      | rctrl      | Right control key
| 346                      | ralt       | Right alt key
| 347                      | rsuper     | Right command key in OS X, Windows key in Windows.
| **Numpad keys**          |            |
| 320                      | kp0        | The numpad zero key
| 321                      | kp1        | The numpad one key
| 322                      | kp2        | The numpad two key
| 323                      | kp3        | The numpad three key
| 324                      | kp4        | The numpad four key
| 325                      | kp5        | The numpad five key
| 326                      | kp6        | The numpad six key
| 327                      | kp7        | The numpad seven key
| 328                      | kp8        | The numpad eight key
| 329                      | kp9        | The numpad nine key
| 330                      | kp.        | The numpad decimal point key	
| 331                      | kp/        | The numpad division key
| 332                      | kp*        | The numpad multiplication key	
| 333                      | kp-        | The numpad substraction key	
| 334                      | kp+        | The numpad addition key
| 335                      | kpenter    | The numpad enter key
| 336                      | kp=        | The numpad equals key	

Translating of representations provides by `rl.ekey` table:
```lua
key = "space"
ikey = rl.ekey[key]  --> 32
skey = rl.ekey[ikey] --> "space"
```
This table is used internally in the library, so do not modify it if you don't know what is happens.
