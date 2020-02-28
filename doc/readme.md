
## Table of content
* [Core](#Core)
  * [InitWindow](#InitWindow)
  * [WindowShouldClose](#WindowShouldClose)
  * [CloseWindow](#CloseWindow)
  * [IsWindowReady](#IsWindowReady)
  * [IsWindowMinimized](#IsWindowMinimized)
  * [IsWindowResized](#IsWindowResized)
  * [IsWindowHidden](#IsWindowHidden)
  * [ToggleFullscreen](#ToggleFullscreen)
  * [UnhideWindow](#UnhideWindow)
  * [HideWindow](#HideWindow)
  * [SetWindowIcon](#SetWindowIcon)
  * [SetWindowTitle](#SetWindowTitle)
  * [SetWindowPosition](#SetWindowPosition)
  * [SetWindowMonitor](#SetWindowMonitor)
  * [SetWindowMinSize](#SetWindowMinSize)
  * [SetWindowSize](#SetWindowSize)
  * [GetWindowHandle](#GetWindowHandle)
  * [GetScreenWidth](#GetScreenWidth)
  * [GetScreenHeight](#GetScreenHeight)
  * [GetScreenDimensions](#GetScreenDimensions)
  * [GetMonitorCount](#GetMonitorCount)
  * [GetMonitorWidth](#GetMonitorWidth)
  * [GetMonitorHeight](#GetMonitorHeight)
  * [GetMonitorDimensions](#GetMonitorDimensions)
  * [GetMonitorPhysicalWidth](#GetMonitorPhysicalWidth)
  * [GetMonitorPhysicalHeight](#GetMonitorPhysicalHeight)
  * [GetMonitorPhysicalDimensions](#GetMonitorPhysicalDimensions)
  * [GetMonitors](#GetMonitors)
  * [GetWindowPosition](#GetWindowPosition)
  * [GetMonitorName](#GetMonitorName)
  * [GetClipboardText](#GetClipboardText)
  * [SetClipboardText](#SetClipboardText)
  * [ShowCursor](#ShowCursor)
  * [HideCursor](#HideCursor)
  * [IsCursorHidden](#IsCursorHidden)
  * [EnableCursor](#EnableCursor)
  * [DisableCursor](#DisableCursor)
  * [ClearBackground](#ClearBackground)
  * [BeginDrawing](#BeginDrawing)
  * [EndDrawing](#EndDrawing)
  * [BeginMode2D](#BeginMode2D)
  * [EndMode2D](#EndMode2D)
  * [BeginMode3D](#BeginMode3D)
  * [EndMode3D](#EndMode3D)
  * [BeginTextureMode](#BeginTextureMode)
  * [EndTextureMode](#EndTextureMode)
  * [BeginScissorMode](#BeginScissorMode)
  * [EndScissorMode](#EndScissorMode)
  * [GetMouseRay](#GetMouseRay)
  * [GetCameraMatrix](#GetCameraMatrix)
  * [GetCameraMatrix2D](#GetCameraMatrix2D)
  * [GetWorldToScreen](#GetWorldToScreen)
  * [GetWorldToScreenEx](#GetWorldToScreenEx)
  * [GetWorldToScreen2D](#GetWorldToScreen2D)
  * [GetScreenToWorld2D](#GetScreenToWorld2D)
  * [SetTargetFPS](#SetTargetFPS)
  * [GetFPS](#GetFPS)
  * [GetFrameTime](#GetFrameTime)
  * [GetTime](#GetTime)
  * [ColorToInt](#ColorToInt)
  * [ColorNormalize](#ColorNormalize)
  * [ColorFromNormalized](#ColorFromNormalized)
  * [ColorToHSV](#ColorToHSV)
  * [ColorFromHSV](#ColorFromHSV)
  * [GetColor](#GetColor)
  * [Fade](#Fade)
  * [SetConfigFlags](#SetConfigFlags)
  * [SetTraceLogLevel](#SetTraceLogLevel)
  * [SetTraceLogExit](#SetTraceLogExit)
  * [SetTraceLogCallback](#SetTraceLogCallback)
  * [TraceLog](#TraceLog)
  * [TakeScreenshot](#TakeScreenshot)
  * [GetRandomValue](#GetRandomValue)
  * [FileExists](#FileExists)
  * [IsFileExtension](#IsFileExtension)
  * [DirectoryExists](#DirectoryExists)
  * [GetExtension](#GetExtension)
  * [GetFileName](#GetFileName)
  * [GetFileNameWithoutExt](#GetFileNameWithoutExt)
  * [GetDirectoryPath](#GetDirectoryPath)
  * [GetPrevDirectoryPath](#GetPrevDirectoryPath)
  * [GetWorkingDirectory](#GetWorkingDirectory)
  * [GetDirectoryFiles](#GetDirectoryFiles)
  * [ChangeDirectory](#ChangeDirectory)
  * [IsFileDropped](#IsFileDropped)
  * [GetDroppedFiles](#GetDroppedFiles)
  * [GetFileModTime](#GetFileModTime)
  * [GetFileInfo](#GetFileInfo)
  * [CompressData](#CompressData)
  * [DecompressData](#DecompressData)
  * [OpenURL](#OpenURL)
  * [StorageSaveValue](#StorageSaveValue)
  * [StorageLoadValue](#StorageLoadValue)
  * [IsKeyPressed](#IsKeyPressed)
  * [IsKeyDown](#IsKeyDown)
  * [IsKeyReleased](#IsKeyReleased)
  * [IsKeyUp](#IsKeyUp)
  * [GetKeyPressed](#GetKeyPressed)
  * [GetKeyPressedString](#GetKeyPressedString)
  * [GetAllKeysPressedString](#GetAllKeysPressedString)
  * [SetExitKey](#SetExitKey)
  * [IsGamepadAvailable](#IsGamepadAvailable)
  * [IsGamepadName](#IsGamepadName)
  * [GetGamepadName](#GetGamepadName)
  * [IsGamepadButtonPressed](#IsGamepadButtonPressed)
  * [IsGamepadButtonDown](#IsGamepadButtonDown)
  * [IsGamepadButtonReleased](#IsGamepadButtonReleased)
  * [IsGamepadButtonUp](#IsGamepadButtonUp)
  * [GetGamepadButtonPressed](#GetGamepadButtonPressed)
  * [GetGamepadAxisCount](#GetGamepadAxisCount)
  * [GetGamepadAxisMovement](#GetGamepadAxisMovement)
  * [IsMouseButtonPressed](#IsMouseButtonPressed)
  * [IsMouseButtonDown](#IsMouseButtonDown)
  * [IsMouseButtonReleased](#IsMouseButtonReleased)
  * [IsMouseButtonUp](#IsMouseButtonUp)
  * [GetMouseX](#GetMouseX)
  * [GetMouseY](#GetMouseY)
  * [GetMousePosition](#GetMousePosition)
  * [SetMousePosition](#SetMousePosition)
  * [SetMouseOffset](#SetMouseOffset)
  * [SetMouseScale](#SetMouseScale)
  * [GetMouseWheelMove](#GetMouseWheelMove)
  * [GetTouchX](#GetTouchX)
  * [GetTouchY](#GetTouchY)
  * [GetTouch](#GetTouch)
  * [GetTouchPosition](#GetTouchPosition)
  * [GetTouches](#GetTouches)
  * [SetGesturesEnabled](#SetGesturesEnabled)
  * [IsGestureDetected](#IsGestureDetected)
  * [GetGestureDetected](#GetGestureDetected)
  * [GetTouchPointsCount](#GetTouchPointsCount)
  * [GetGestureHoldDuration](#GetGestureHoldDuration)
  * [GetGestureDragVector](#GetGestureDragVector)
  * [GetGestureDragAngle](#GetGestureDragAngle)
  * [GetGesturePinchVector](#GetGesturePinchVector)
  * [GetGesturePinchAngle](#GetGesturePinchAngle)
  * [SetCameraMode](#SetCameraMode)
  * [UpdateCamera](#UpdateCamera)
  * [SetCameraPanControl](#SetCameraPanControl)
  * [SetCameraAltControl](#SetCameraAltControl)
  * [SetCameraSmoothZoomControl](#SetCameraSmoothZoomControl)
  * [SetCameraMoveControls](#SetCameraMoveControls)
* Text
  * Text functions
  * ...


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
Setup canvas (framebuffer) to start drawing


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
Vector2 ScreenV = Matrix rl.core.GetWorldToScreen(Vector3 Vector, Camera3D Camera)
```
Returns the screen space position for a 3d world space position.
See [Vector2](#Vector2), [Vector3](#Vector3), [Camera3D](#Camera3D).


#### GetWorldToScreenEx
```lua
Vector2 ScreenV = Matrix rl.core.GetWorldToScreenEx(Vector3 Vector, Camera3D Camera, integer Width, integer Height)
```
Returns size position for a 3d world space position.
See [Vector2](#Vector2), [Vector3](#Vector3), [Camera3D](#Camera3D).


#### GetWorldToScreen2D
```lua
Vector2 ScreenV = Matrix rl.core.GetWorldToScreen2D(Vector2 Vector, Camera2D Camera)
```
Returns the screen space position for a 2d camera world space position.
See [Vector2](#Vector2), [Camera2D](#Camera2D).


#### GetScreenToWorld2D
```lua
Vector2 ScreenV = Matrix rl.core.GetScreenToWorld2D(Vector2 Vector, Camera2D Camera)
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
integer FPS = Matrix rl.core.GetFPS()
```
Returns current FPS


#### GetFrameTime
```lua
float DT = Matrix rl.core.GetFrameTime()
```
Returns time in seconds for last frame drawn


#### GetTime
```lua
float Time = Matrix rl.core.GetTime()
```
Returns elapsed time in seconds since InitWindow()


### Color-related functions
#### ColorToInt
```lua
integer iColor = rl.core.ColorToInt(Color Color)
```
Returns hexadecimal value for a Color


#### ColorNormalize
```lua
-- variants
Vector4 vColor = rl.core.ColorNormalize(Color Color)
integer NR, integer NG, integer NB, integer NA = rl.core.ColorNormalize(Color Color, "n")
table tColor = rl.core.ColorNormalize(Color Color, "t") -- Array {float r, float g, float b, float a}
```
Returns color normalized as float [0..1].
See [Vector4](#Vector4), [Color](#Color)


#### ColorFromNormalized
```lua
-- variants
Color Color = rl.core.ColorFromNormalized(Vector4 vColor)
Color Color = rl.core.ColorFromNormalized(float R, float G, float B[, float A])
Color Color = rl.core.ColorFromNormalized(table tColor) -- Array {float r, float g, float b[, float a]}
```
Returns color from normalized values [0..1].
See [Vector4](#Vector4), [Color](#Color)


#### ColorToHSV
```lua
-- variants
Vector3 vColor = rl.core.ColorToHSV(Color Color)
float Hue, float Saturation, float Value = rl.core.ColorToHSV(Color Color, "n")
table hsvColor = rl.core.ColorNormalize(Color Color, "t") -- Array {float h, float s, float v}
```
Returns HSV values for a Color.
See [Vector3](#Vector3), [Color](#Color)


#### ColorFromHSV
```lua
-- variants
Color Color = rl.core.ColorFromHSV(Vector3 vColor)
Color Color = rl.core.ColorFromHSV(float H, float S, float V)
Color Color = rl.core.ColorFromHSV(table hsvColor) -- Array {float h, float s, float v}
```
Returns a Color from HSV values.
See [Vector3](#Vector3), [Color](#Color)


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
Available flags:
* `"FULLSCREEN_MODE"`    Set to run program in fullscreen
* `"WINDOW_RESIZABLE"`   Set to allow resizable window
* `"WINDOW_UNDECORATED"` Set to disable window decoration (frame and buttons)
* `"WINDOW_TRANSPARENT"` Set to allow transparent window
* `"WINDOW_HIDDEN"`      Set to create the window initially hidden
* `"WINDOW_ALWAYS_RUN"`  Set to allow windows running while minimized
* `"MSAA_4X_HINT"`       Set to try enabling MSAA 4X
* `"VSYNC_HINT"`         Set to try enabling V-Sync on GPU


#### SetTraceLogLevel
```lua
rl.core.SetTraceLogLevel(string Mode)
```
Set the current threshold (minimum) log level.
Available Modes:
* `"ALL"`     Set to run program in fullscreen
* `"TRACE"`   Set to allow resizable window
* `"DEBUG"`   Set to disable window decoration (frame and buttons)
* `"INFO"`    Set to allow transparent window
* `"WARNING"` Set to create the window initially hidden
* `"ERROR"`   Set to allow windows running while minimized
* `"FATAL"`   Set to try enabling MSAA 4X
* `"NONE"`    Set to try enabling V-Sync on GPU


#### SetTraceLogExit
```lua
rl.core.SetTraceLogExit(string Mode)
```
Set the exit threshold (minimum) log level.
Available Modes:
* `"ALL"`     Set to run program in fullscreen
* `"TRACE"`   Set to allow resizable window
* `"DEBUG"`   Set to disable window decoration (frame and buttons)
* `"INFO"`    Set to allow transparent window
* `"WARNING"` Set to create the window initially hidden
* `"ERROR"`   Set to allow windows running while minimized
* `"FATAL"`   Set to try enabling MSAA 4X
* `"NONE"`    Set to try enabling V-Sync on GPU


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
logLevel is string constant `"TRACE"`, `"DEBUG"`, `"INFO"`, `"WARNING"`, `"ERROR"` or `"FATAL"`.


#### TraceLog
```lua
rl.core.TraceLog(string logLevel, string Message)
```
Show trace log messages. logLevel is string constant `"TRACE"`, `"DEBUG"`, `"INFO"`, `"WARNING"`, `"ERROR"` or `"FATAL"`.


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
Table Files contains string names like `{"file1.png", "directory1", "file2.lua", ...}`


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
Table Files contains string names like `{"file1.png", "file2.lua", ...}`


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
Save integer value to storage file (to defined position)


#### StorageLoadValue
```lua
integer Value = rl.core.StorageLoadValue(integer Position)
```
Load integer value from storage file (from defined position)


### Input-related functions: keyb
#### IsKeyPressed
```lua
boolean State = rl.core.IsKeyPressed(integer Key)
```
Detect if a key has been pressed once


#### IsKeyDown
```lua
boolean State = rl.core.IsKeyDown(integer Key)
```
Detect if a key is being pressed


#### IsKeyReleased
```lua
boolean State = rl.core.IsKeyReleased(integer Key)
```
Detect if a key has been released once


#### IsKeyUp
```lua
boolean State = rl.core.IsKeyUp(integer Key)
```
Detect if a key is NOT being pressed


#### GetKeyPressed
```lua
integer Key = rl.core.GetKeyPressed()
```
Get latest key scancode pressed


#### GetKeyPressedString
```lua
string Char = rl.core.GetKeyPressedString()
```
Get user input utf8-string char


#### GetAllKeysPressedString
```lua
string Text = rl.core.GetAllKeysPressedString()
```
Get all user utf8-input chars


#### SetExitKey
```lua
rl.core.SetExitKey(integer Key)
```
Set a custom key to exit program (default is ESC)


### Input-related functions: gamepads
#### IsGamepadAvailable
```lua
boolean State = rl.core.IsGamepadAvailable(integer Gamepad)
```
Detect if a gamepad is available


#### IsGamepadName
```lua
boolean State = rl.core.IsGamepadName(integer Gamepad, string GamepadName)
```
Check gamepad name (if available)


#### GetGamepadName
```lua
string GamepadName = rl.core.GetGamepadName(integer Gamepad)
```
Check gamepad name (if available)


#### IsGamepadButtonPressed
```lua
boolean Status = rl.core.IsGamepadButtonPressed(integer Gamepad)
```
Detect if a gamepad button has been pressed once


#### IsGamepadButtonDown
```lua
boolean Status = rl.core.IsGamepadButtonDown(integer Gamepad)
```
Detect if a gamepad button is being pressed


#### IsGamepadButtonReleased
```lua
boolean Status = rl.core.IsGamepadButtonReleased(integer Gamepad)
```
Detect if a gamepad button has been released once


#### IsGamepadButtonUp
```lua
boolean Status = rl.core.IsGamepadButtonUp(integer Gamepad)
```
Detect if a gamepad button is NOT being pressed


#### GetGamepadButtonPressed
```lua
integer Key = rl.core.GetGamepadButtonPressed()
```
Get the last gamepad button pressed


#### GetGamepadAxisCount
```lua
integer Count = rl.core.GetGamepadAxisCount()
```
Return gamepad axis count for a gamepad


#### GetGamepadAxisMovement
```lua
float Movement = rl.core.GetGamepadAxisMovement(integer Gamepad)
```
Return axis movement value for a gamepad axis


### Input-related functions: mouse
#### IsMouseButtonPressed
```lua
boolean State = rl.core.IsMouseButtonPressed(integer Button)
```
Detect if a mouse button has been pressed once


#### IsMouseButtonDown
```lua
boolean State = rl.core.IsMouseButtonDown(integer Button)
```
Detect if a mouse button is being pressed


#### IsMouseButtonReleased
```lua
boolean State = rl.core.IsMouseButtonReleased(integer Button)
```
Detect if a mouse button has been released once


#### IsMouseButtonUp
```lua
boolean State = rl.core.IsMouseButtonUp(integer Button)
```
Detect if a mouse button is NOT being pressed


#### GetMouseX
```lua
integer X = rl.core.GetMouseX()
```
Returns mouse position X


#### GetMouseY
```lua
integer Y = rl.core.GetMouseY()
```
Returns mouse position Y


#### GetMousePosition
```lua
-- variants
Vector2 Position     = rl.core.GetMousePosition()
integer X, integer Y = rl.core.GetMousePosition('n')
```
Returns mouse position XY


#### SetMousePosition
```lua
-- variants
rl.core.SetMousePosition(Vector2 Position)
rl.core.SetMousePosition(integer X, integer Y)
```
Set mouse position XY


#### SetMouseOffset
```lua
-- variants
rl.core.SetMouseOffset(Vector2 Offset)
rl.core.SetMouseOffset(integer X, integer Y)
```
Set mouse offset


#### SetMouseScale
```lua
-- variants
rl.core.SetMouseScale(Vector2 Scale)
rl.core.SetMouseScale(integer X, integer Y)
```
Set mouse scaling


#### GetMouseWheelMove
```lua
-- variants
integer WheelMove = rl.core.GetMouseWheelMove()
```
Returns mouse wheel movement Y


### Input-related functions: touch
#### GetTouchX
```lua
integer X = rl.core.GetTouchX()
```
Returns touch position X for touch point 1 (relative to screen size)


#### GetTouchY
```lua
integer Y = rl.core.GetTouchY()
```
Returns touch position Y for touch point 1 (relative to screen size)


#### GetTouch
```lua
integer X, integer Y = rl.core.GetTouch()
```
Returns touch position XY for a touch point 1 (relative to screen size)


#### GetTouchPosition
```lua
-- veriants
Vector2 Position     = rl.core.GetTouchPosition(integer Index)
integer X, integer Y = rl.core.GetTouchPosition(integer Index, 'n')
```
Returns touch position XY for a touch point index (relative to screen size)


#### GetTouches
```lua
-- veriants
table Touches = rl.core.GetTouches(integer Index)      -- {Vector2 t1, Vector2 t2, ...}
table Touches = rl.core.GetTouches(integer Index, 'n') -- {{integer X1, integer Y1}, {integer X2, integer Y2}, ...}
```
Returns all touches positions XY (relative to screen size)


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
* `"PINCH_IN"` returns integer PinchVectorX, integer PinchVectorY, float PinchAngle if 'n' is passed
* `"PINCH_OUT"` same as `"PINCH_IN"`.


#### GetTouchPointsCount
```lua
integer Count = rl.core.GetTouchPointsCount()
```
Get touch points count


#### GetGestureHoldDuration
```lua
float Duration = rl.core.GetGestureHoldDuration()
```
Get gesture hold time in milliseconds


#### GetGestureHoldDuration
```lua
-- variants
Vector2 DragVector     = rl.core.GetGestureDragVector()
integer vX, integer vY = rl.core.GetGestureDragVector('n')
```
Get gesture drag vector


#### GetGestureDragAngle
```lua
float Angle = rl.core.GetGestureDragAngle()
```
Get gesture drag angle


#### GetGesturePinchVector
```lua
-- variants
Vector2 PinchVector    = rl.core.GetGesturePinchVector()
integer dX, integer dY = rl.core.GetGesturePinchVector('n')
```
Get gesture pinch delta


#### GetGesturePinchAngle
```lua
float Angle = rl.core.GetGesturePinchAngle()
```
Get gesture pinch angle


### Camera System Functions (Module: camera)
#### SetCameraMode
```lua
rl.core.SetCameraMode(Camera3D Camera, string Mode)
```
Set camera mode. Availabke modes: 
* `"CUSTOM"` - default
* `"FREE"`
* `"ORBITAL"`
* `"FIRST_PERSON"`
* `"THIRD_PERSON"`


#### UpdateCamera
```lua
rl.core.UpdateCamera(Camera3D Camera)
```
Update camera position for selected mode


#### SetCameraPanControl
```lua
rl.core.SetCameraPanControl(integer panKey)
```
Set camera pan key to combine with mouse movement (free camera)


#### SetCameraAltControl
```lua
rl.core.SetCameraAltControl(integer altKey)
```
Set camera alt key to combine with mouse movement (free camera)


#### SetCameraSmoothZoomControl
```lua
rl.core.SetCameraSmoothZoomControl(integer szKey)
```
Set camera smooth zoom key to combine with mouse (free camera)


#### SetCameraMoveControls
```lua
rl.core.SetCameraMoveControls(integer frontKey, integer backKey, integer rightKey, integer leftKey, integer upKey, integer downKey)
```
Set camera move controls (1st person and 3rd person cameras)


# Classes

## Vector2
### Initialization
```lua
-- variants
Vector2 Vec = rl.Vector2(number x, number y) --> vec2[x, y]
Vector2 Vec = rl.Vector2(number x)           --> vec2[x, x]
Vector2 Vec = rl.Vector2(table t)            --> vec2[ t[1], t[2] ]
```
Creates new Vector2 object.


### Methods

#### Clone
```lua
Vector2 Vec2 = Vector2:clone()
```
Clones Vector2 object.


#### Get
```lua
-- variants
float x, float y = Vector2:get()
table t = Vector2:get('t') --> {x, y}
```
Get Vector2 components.


#### Set
```lua
-- variants
Vector2:set(float x, float y)
Vector2:set(table t) -- [x, y]
```
Set Vector2 components.


## Vector3
### Initialization
```lua
-- variants
Vector3 Vec3 = rl.Vector3(number x, number y, , number z) --> vec3[x, y, z]
Vector3 Vec3 = rl.Vector3(number x)                       --> vec3[x, x, x]
Vector3 Vec3 = rl.Vector3(table t)                        --> vec3[ t[1], t[2], t[3] ]
```
Creates new Vector3 object.


## Matrix
### Initialization
```lua
-- variants
Matrix Mat = rl.Matrix(number m1, number m2, ..., number m16) --> Matrix[m1, m2, ... m16]
Matrix Mat = rl.Matrix(table t)                        --> Matrix[ t[1], t[2], ... t[16] ]
```
Creates new Matrix object.


## Vector4
### Initialization
```lua
-- variants
Vector4 Vec4 = rl.Vector4(number x, number y, number z,  number w) --> Vec4[x, y, z, w]
Vector4 Vec4 = rl.Vector4(number x)                       --> Vec4[x, x, x, x]
Vector4 Vec4 = rl.Vector4(table t)                        --> Vec4[ t[1], t[2], t[3], t[4] ]
```
Creates new Vector4 object.


## Color
### Initialization
```lua
-- variants
Color Color = rl.Color(number r, number g, number b,  number a) --> Color[r, g, b, a]
Color Color = rl.Color(table t)                                 --> Color[ t[1], t[2], t[3], t[4] ]
Color Color = rl.Color(string Color)
```
Creates new Color object.
Available string colors:
* `"lightgray"  -> { 200, 200, 200 }`
* `"gray"       -> { 130, 130, 130 }`
* `"darkgray"   -> { 80,  80,  80  }`
* `"yellow"     -> { 253, 249, 0   }`
* `"gold"       -> { 255, 203, 0   }`
* `"orange"     -> { 255, 161, 0   }`
* `"pink"       -> { 255, 109, 194 }`
* `"red"        -> { 230, 41,  55  }`
* `"maroon"     -> { 190, 33,  55  }`
* `"green"      -> { 0,   228, 48  }`
* `"lime"       -> { 0,   158, 47  }`
* `"darkgreen"  -> { 0,   117, 44  }`
* `"skyblue"    -> { 102, 191, 255 }`
* `"blue"       -> { 0,   121, 241 }`
* `"darkblue"   -> { 0,   82,  172 }`
* `"purple"     -> { 200, 122, 255 }`
* `"violet"     -> { 135, 60,  190 }`
* `"darkpurple" -> { 112, 31,  126 }`
* `"beige"      -> { 211, 176, 131 }`
* `"brown"      -> { 127, 106, 79  }`
* `"darkbrown"  -> { 76,  63,  47  }`
* `"white"      -> { 255, 255, 255 }`
* `"black"      -> { 0,   0,   0   }`
* `"blank"      -> { 0,   0,   0   }`
* `"magenta"    -> { 255, 0,   255 }`
* `"raywhite"   -> { 245, 245, 245 }`


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
