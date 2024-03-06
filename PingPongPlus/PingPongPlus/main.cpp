
#include "raylib.h"
#include "Paddle.h"
#include "Ball.h"
#include "GameMenu.h"
#include "Manual.h"
#include "AI.h"


int main()
{
	InitWindow(800, 600, "Ping Pong Game");
	SetWindowState(FLAG_VSYNC_HINT);

	Vector2D BSpeed(300, 0);
	Vector2D BPosition(GetScreenWidth() / 2.0, GetScreenHeight() / 2.0);
	Ball ball(&BPosition,&BSpeed, 8);
	GameMenu GM;

	InitAudioDevice();
	Music music = LoadMusicStream("sound1.mp3");
	Music music1 = LoadMusicStream("sound.mp3");
	PlayMusicStream(music);
	PlayMusicStream(music1);
	float timePlayed = 0.0f;
	bool pause = false;

	RectangleShape Left(50, GetScreenHeight() / 2, 15, 75);
	Paddle LeftPaddle(&Left, 500);

	RectangleShape Right(GetScreenWidth() - 50, GetScreenHeight() / 2, 15, 75);
	Paddle RightPaddle(&Right, 500);
	Manual TwoPlayer;
	AI OnePlayer;

	while (!WindowShouldClose())
	{
		UpdateMusicStream(music);
		PlayMusicStream(music);
		const char* About1 = nullptr;
		const char* About2 = nullptr;
		const char* About3 = nullptr;
		const char* About4 = nullptr;
		const char* About5 = nullptr;
		const char* About6 = nullptr;
		const char* About7 = nullptr;
		const char* About8 = nullptr;
		const char* About9 = nullptr;
		const char* About10 = nullptr;
			GM.drawMain();
			while (!GM.GetMenu())
			{
				UpdateMusicStream(music1);
				PlayMusicStream(music1);

				if (GM.GetPVP() == true)
				{
					TwoPlayer.PlayerVSPlayer(&RightPaddle, &LeftPaddle, &ball);
				}

				if (GM.GetPVC() == true)
				{
					OnePlayer.PlayerVSComputer(&RightPaddle, &LeftPaddle, &ball);
				}
				if (GM.GetABT() == true)
				{
					BeginDrawing();
					ClearBackground(LIGHTGRAY);

					About1 = "1. Start Game will take you to Player Vs Player!";
					About2 = "2. In Practice, Set yourself a highscore by returning shots from AI!";
					About3 = "3. The Game will Always Start from your last check Point!";
					About4 = "4. Press 'R' to reset Whenever you want a new game!";
					About5 = "5. Press BackSpace to go Back to Main Menu!";
					About6 = "6. Press Escape to exit!";
					About7 = "7. Player can win by score at least 12 points with difference of 2 points!";
					About8 = " Credits: ";
					About9 = " M. Hasnain Fatmi  (21l-1773)";
					About10= " Saad Hussain Kazmi (21l-5178)";

					int textWidth1 = MeasureText(About1, 50);
					int textWidth2 = MeasureText(About2, 50);
					int textWidth3 = MeasureText(About3, 50);
					int textWidth4 = MeasureText(About4, 50);
					int textWidth5 = MeasureText(About5, 50);
					int textWidth6 = MeasureText(About6, 50);
					int textWidth7 = MeasureText(About7, 50);
					int textWidth8 = MeasureText(About8, 50);
					int textWidth9 = MeasureText(About9, 50);
					int textWidth10 = MeasureText(About10, 50);
					DrawText(About1, 50,50, 20, BLUE);
					DrawText(About2, 50, 110, 20, BLUE);
					DrawText(About3, 50, 170, 20, BLUE);
					DrawText(About4, 50, 230, 20, BLUE);
					DrawText(About5, 50, 290, 20, BLUE);
					DrawText(About6, 50, 350, 20, BLUE);
					DrawText(About7, 50, 410, 20, BLUE);
					DrawText(About8, 50, 470, 20, BLUE);
					DrawText(About9, 50, 500, 20, BLUE);
					DrawText(About10, 50,530, 20, BLUE);

					EndDrawing();
				}
				if (IsKeyPressed(KEY_BACKSPACE))
				{
					GM.SetMenu(true);
				}
				if (IsKeyPressed(KEY_ESCAPE))
				{
					break;
				}
			}
			if (GM.GetQuit())
			{
				break;
			}

	}
	UnloadMusicStream(music);
	UnloadMusicStream(music1);
	CloseAudioDevice();
	CloseWindow();

	return 0;
}
