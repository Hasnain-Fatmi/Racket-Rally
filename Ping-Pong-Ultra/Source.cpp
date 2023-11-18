#include "raylib.h"

const int screenWidth = 800;
const int screenHeight = 450;

struct Player
{
    Vector2 position;
    int points;
};

Player player1;
Player player2;

Vector2 ballPosition;
Vector2 ballSpeed;

int main()
{
    // Initialize the game
    InitWindow(screenWidth, screenHeight, "Ping Pong");

    SetTargetFPS(60);

    // Initialize the players and ball
    player1.position = { 25, screenHeight / 2 - 50 };
    player2.position = { screenWidth - 25, screenHeight / 2 - 50 };
    ballPosition = { screenWidth / 2, screenHeight / 2 };
    ballSpeed = { 5, 3 };

    // Main game loop
    while (!WindowShouldClose())
    {
        // Update
        player1.position.y = GetMouseY();
        player2.position.y = ballPosition.y;

        ballPosition.x += ballSpeed.x;
        ballPosition.y += ballSpeed.y;

        // Check for ball collision with the screen edges
        if (ballPosition.y > screenHeight || ballPosition.y < 0)
        {
            ballSpeed.y *= -1;
        }

        if (ballPosition.x > screenWidth)
        {
            player1.points++;
            ballPosition = { screenWidth / 2, screenHeight / 2 };
            ballSpeed = { 5, 3 };
        }

        if (ballPosition.x < 0)
        {
            player2.points++;
            ballPosition = { screenWidth / 2, screenHeight / 2 };
            ballSpeed = { 5, 3 };
        }

        // Check for ball collision with the players
        if (CheckCollisionRecs({ ballPosition.x, ballPosition.y, 10, 10 },
            { player1.position.x, player1.position.y, 10, 50 }))
        {
            ballSpeed.x *= -1;
        }

        if (CheckCollisionRecs({ ballPosition.x, ballPosition.y, 10, 10 },
            { player2.position.x, player2.position.y, 10, 50 }))
        {
            ballSpeed.x *= -1;
        }

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawRectangle(player1.position.x, player1.position.y, 10, 50, BLACK);
        DrawRectangle(player2.position.x, player2.position.y, 10, 50, BLACK);
        DrawCircle(ballPosition.x, ballPosition.y, 5, BLACK);

         DrawText(TextFormat("%i", player1.points), screenWidth / 4 - 30, 20, 40, BLACK);
        DrawText(TextFormat("%i", player2.points), screenWidth / 4 * 3 - 30, 20, 40, BLACK);

        EndDrawing();
    }

    // Cleanup
    CloseWindow();

    return 0;
}