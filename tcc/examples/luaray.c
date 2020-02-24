/*******************************************************************************************
*
*   Physac - Physics demo
*
*   NOTE 1: Physac requires multi-threading, when InitPhysics() a second thread is created to manage physics calculations.
*   NOTE 2: Physac requires static C library linkage to avoid dependency on MinGW DLL (-static -lpthread)
*
*   Use the following line to compile:
*
*   gcc -o $(NAME_PART).exe $(FILE_NAME) -s -static  /
*       -lraylib -lpthread -lglfw3 -lopengl32 -lgdi32 -lopenal32 -lwinmm /
*       -std=c99 -Wl,--subsystem,windows -Wl,-allow-multiple-definition
*
*   Copyright (c) 2016-2018 Victor Fisac
*
********************************************************************************************/

#include "raylib.h"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth  = 800;
    const int screenHeight = 600;

    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(screenWidth, screenHeight, "Input test");


		Font a = LoadFont("arial.ttf");
    // Physac logo drawing position
    int logoX = screenWidth - MeasureText("Physac", 30) - 10;
    int logoY = 15;
		
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
		char * text = (char *)malloc(60 * sizeof(char));
		memcpy(text, "Hello123\0", 12);
		
    // Main game loop
    while (!WindowShouldClose()) {
			// Draw
			//----------------------------------------------------------------------------------
			BeginDrawing();
				ClearBackground(BLACK);

				DrawFPS(screenWidth - 90, screenHeight - 30);
				DrawTextEx(text, 100, 100, 60, WHITE);
				DrawText("Physac", logoX, logoY, 30, WHITE);
				DrawText("Powered by", logoX + 50, logoY - 7, 10, WHITE);

			EndDrawing();
			//----------------------------------------------------------------------------------
    }


    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
