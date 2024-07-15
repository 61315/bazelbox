#include "raylib.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    // Camera camera = { 0 };
    // camera.position = (Vector3){ 0.0f, 10.0f, 10.0f };
    // camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    // camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    Camera camera;
    camera.position = Vector3{0,10,10};
    camera.target = Vector3{0,0,0};
    camera.up = Vector3{0, 1, 0};
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(camera);
                DrawCube(Vector3{-4.0f, 0.0f, 2.0f}, 2.0f, 5.0f, 2.0f, RED);
                DrawCubeWires(Vector3{-4.0f, 0.0f, 2.0f}, 2.0f, 5.0f, 2.0f, GOLD);
                DrawCubeWires(Vector3{-4.0f, 0.0f, -2.0f}, 3.0f, 6.0f, 2.0f, MAROON);
            EndMode3D();

            // DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}