//#pragma once
//#ifndef _AI_H
//#define _AI_H
//#include "raylib.h"
//#include "Paddle.h"
//#include "Ball.h"
//#include "Court.h"
//#include"iostream"
//
//class AI
//{
//	int Player_Score;
//	int Computer_Score;
//	int Max_Hits;
//	Ball* pong;
//	Paddle* RightPaddle;
//	Paddle* LeftPaddle;
//	Court* table;
//
//public:
//
//	const char* WinnerText1 = nullptr;
//	const char* WinnerText2 = nullptr;
//	const char* WinnerText3 = nullptr;
//	float TempYL = (GetScreenHeight() / 2.0);
//	float TempYR = (GetScreenHeight() / 2.0);
//	float TempBX = (GetScreenWidth() / 2.0);
//	float TempBY = (GetScreenHeight() / 2.0);
//	float TempBSX = 300;
//	float TempBSY = 300;
//
//
//	AI()
//	{
//		this->pong = pong;
//		this->RightPaddle = RightPaddle;
//		this->LeftPaddle = LeftPaddle;
//		this->table = table;
//		Player_Score = 0;
//		Computer_Score = 0;
//		Max_Hits = 0;
//	}
//	int LoadMax_Hits()
//	{
//		int maxhits = 0;
//		std::ifstream scoreReader;
//		scoreReader.open("sc3.txt");
//		if (!scoreReader.fail() && scoreReader.good())
//		{
//			scoreReader >> maxhits;
//		}
//		scoreReader.close();
//		return maxhits;
//	}
//	void SaveHits(int& Hits, int& maxhits)
//	{
//		if (Hits > maxhits)
//		{
//			maxhits = Hits;
//			std::ofstream scorewriter;
//			scorewriter.open("sc3.txt");
//			scorewriter << maxhits;
//			scorewriter.close();
//		}
//
//	}
//
//	void PlayerVSComputer(Paddle* RightPaddle, Paddle* LeftPaddle, Ball* pong)
//	{
//		int maxhits = LoadMax_Hits();
//
//		if (Player_Score >= 12 && (Player_Score - Computer_Score) > 1)
//		{
//			WinnerText1 = "You Wins!";
//			WinnerText3 = "Press Space Bar to start again";
//		}
//		if (Computer_Score >= 12 && (Computer_Score - Player_Score) > 1)
//		{
//			WinnerText2 = "AI Win!";
//			WinnerText3 = "Press Space Bar to Start again";
//		}
//		SaveHits(Max_Hits, maxhits);
//
//		if (WinnerText1 && IsKeyPressed(KEY_SPACE))
//		{
//			pong->SetX(GetScreenWidth() / 2.0);
//			pong->SetY(GetScreenHeight() / 2.0);
//			pong->SetSpeedX(300);
//			pong->SetSpeedY(0);
//			WinnerText1 = nullptr;
//			WinnerText2 = nullptr;
//			WinnerText3 = nullptr;
//
//			TempBX = (GetScreenWidth() / 2.0);
//			TempBY = (GetScreenHeight() / 2.0);
//			TempBSX = 300;
//			TempBSY = 300;
//			Player_Score = 0;
//			Computer_Score = 0;
//		}
//		if (WinnerText2 && IsKeyPressed(KEY_SPACE))
//		{
//			pong->SetX(GetScreenWidth() / 2.0);
//			pong->SetY(GetScreenHeight() / 2.0);
//			pong->SetSpeedX(-300);
//			pong->SetSpeedY(0);
//			WinnerText1 = nullptr;
//			WinnerText2 = nullptr;
//			WinnerText3 = nullptr;
//
//			TempBX = (GetScreenWidth() / 2.0);
//			TempBY = (GetScreenHeight() / 2.0);
//			TempBSX = 300;
//			TempBSY = 300;
//			Player_Score = 0;
//			Computer_Score = 0;
//
//		}
//		if (!WinnerText1 && !WinnerText2)
//		{
//			TempBX += pong->GetSpeedX() * GetFrameTime();
//			pong->SetX(TempBX);
//			TempBY += pong->GetSpeedY() * GetFrameTime();
//			pong->SetY(TempBY);
//
//			if (pong->GetY() < 149)
//			{
//				pong->SetY(150);
//				pong->SetSpeedY(TempBSY);
//			}
//			if (pong->GetY() > 499)
//			{
//				pong->SetY(500);
//				pong->SetSpeedY(-TempBSY);
//			}
//			LeftPaddle->SetY(TempBY);
//
//			if (IsKeyDown(KEY_UP))
//			{
//				TempYR = TempYR - (RightPaddle->GetSpeed() * GetFrameTime());
//				RightPaddle->SetY(TempYR);
//			}
//			if (IsKeyDown(KEY_DOWN))
//			{
//				TempYR = TempYR + (RightPaddle->GetSpeed() * GetFrameTime());
//				RightPaddle->SetY(TempYR);
//			}
//
//			if (CheckCollisionCircleRec(pong->Vect(), pong->GetRadius(), LeftPaddle->GetRect()))
//			{
//				if (pong->GetSpeedX() < 0)
//				{
//					TempBSX *= -1.1;
//					pong->SetSpeedX(TempBSX);
//				}
//			}
//			if (CheckCollisionCircleRec(pong->Vect(), pong->GetRadius(), RightPaddle->GetRect()))
//			{
//				Max_Hits = Max_Hits + 1;
//
//				if (pong->GetSpeedX() > 0)
//				{
//					TempBSX *= -1.1;
//					pong->SetSpeedX(TempBSX);
//					pong->SetSpeedY(((pong->GetY() - RightPaddle->GetY()) / (RightPaddle->GetHeight() / 2) * -pong->GetSpeedX()));
//				}
//			}
//
//
//
//			if (pong->GetX() < -1)
//			{
//				Player_Score = Player_Score + 1;
//				pong->SetX(GetScreenWidth() / 2.0);
//				pong->SetY(GetScreenHeight() / 2.0);
//				pong->SetSpeedX(300);
//				pong->SetSpeedY(0);
//
//				TempBX = (GetScreenWidth() / 2.0);
//				TempBY = (GetScreenHeight() / 2.0);
//				TempBSX = 300;
//				TempBSY = 300;
//
//			}
//			if (pong->GetX() > GetScreenWidth() + 1)
//			{
//				Computer_Score = Computer_Score + 1;
//
//
//				pong->SetX(GetScreenWidth() / 2.0);
//				pong->SetY(GetScreenHeight() / 2.0);
//				pong->SetSpeedX(-300);
//				pong->SetSpeedY(0);
//
//				TempBX = (GetScreenWidth() / 2.0);
//				TempBY = (GetScreenHeight() / 2.0);
//				TempBSX = 300;
//				TempBSY = 300;
//			}
//		}
//		//Reset
//		if (IsKeyPressed(KEY_R))
//		{
//			pong->SetX(GetScreenWidth() / 2.0);
//			pong->SetY(GetScreenHeight() / 2.0);
//			pong->SetSpeedX(300);
//			pong->SetSpeedY(0);
//			WinnerText1 = nullptr;
//			WinnerText2 = nullptr;
//			WinnerText3 = nullptr;
//
//			TempBX = (GetScreenWidth() / 2.0);
//			TempBY = (GetScreenHeight() / 2.0);
//			TempBSX = 300;
//			TempBSY = 300;
//			Player_Score = 0;
//			Computer_Score = 0;
//			Max_Hits = 0;
//		}
//
//
//
//		BeginDrawing();
//		ClearBackground(LIGHTGRAY);
//		table->Draw();
//		pong->Draw();
//		LeftPaddle->Draw();
//		RightPaddle->Draw();
//
//		DrawText(TextFormat("Player Score: %d", Player_Score), 600, 550, 20, WHITE);
//		DrawText(TextFormat("AI Score: %d", Computer_Score), 40, 550, 20, WHITE);
//		DrawText(TextFormat("Hits Returned: %d", Max_Hits), 600, 50, 20, WHITE);
//		DrawText(TextFormat("Max Hits Returned: %d", maxhits), 40, 50, 20, WHITE);
//		if (WinnerText1)
//		{
//			int TextWidth1 = MeasureText(WinnerText1, 60);
//			int TextWidth2 = MeasureText(WinnerText2, 60);
//			int TextWidth3 = MeasureText(WinnerText3, 60);
//			DrawText(WinnerText1, 325, 50, 30, BLUE);
//			DrawText(WinnerText2, 325, 50, 30, BLUE);
//			DrawText(WinnerText3, 225, 90, 25, BLUE);
//		}
//		if (WinnerText2)
//		{
//			int TextWidth1 = MeasureText(WinnerText1, 60);
//			int TextWidth2 = MeasureText(WinnerText2, 60);
//			int TextWidth3 = MeasureText(WinnerText3, 60);
//			DrawText(WinnerText1, 325, 50, 30, BLUE);
//			DrawText(WinnerText2, 325, 50, 30, BLUE);
//			DrawText(WinnerText3, 225, 90, 25, BLUE);
//
//		}
//		EndDrawing();
//
//	}
//
//};
//#endif