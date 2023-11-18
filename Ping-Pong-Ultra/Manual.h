//#pragma once
//#ifndef _MANUAL_H
//#define _MANUAL_H
//#include "raylib.h"
//#include "Paddle.h"
//#include "Ball.h"
//#include "Court.h"
//#include"iostream"
//#include<fstream>
//
//class Manual
//{
//	int PlayerOne_Score;
//	int PlayerTwo_Score;
//	int Max_Score_P1;
//	int Max_Score_P2;
//	Ball *ball;
//	Paddle *rightPaddle;
//	Paddle *leftPaddle;
//	Court* court;
//	
//
//public:
//
//
//	const char* winnerText1 = nullptr;
//	const char* winnerText2 = nullptr;
//	const char* winnerText3 = nullptr;
//	float tempYL = (GetScreenHeight() / 2.0);
//	float tempYR = (GetScreenHeight() / 2.0);
//	float tempBX = (GetScreenWidth() / 2.0);
//	float tempBY = (GetScreenHeight() / 2.0);
//	float tempBSX = 300;
//	float tempBSY = 300;
//
//
//	Manual()
//	{
//		this->ball = ball;		
//		this->rightPaddle = rightPaddle;
//		this->leftPaddle = leftPaddle;
//		this->court = court;
//		PlayerOne_Score = 0;
//		PlayerTwo_Score = 0;
//		Max_Score_P1 = 0;
//		Max_Score_P2 = 0;
//	}
//
//	int LoadHighScoreP1()
//	{
//		int highscoreP1 = 0;
//		std::ifstream scoreReader;
//		scoreReader.open("sc1.txt");
//		if (!scoreReader.fail() && scoreReader.good())
//		{
//			scoreReader >> highscoreP1;
//		}
//		scoreReader.close();
//		return highscoreP1;
//	}
//	int LoadHighScoreP2()
//	{
//		int highscoreP2 = 0;
//		std::ifstream scoreReader;
//		scoreReader.open("sc2.txt");
//		if (!scoreReader.fail() && scoreReader.good())
//		{
//			scoreReader >> highscoreP2;
//		}
//		scoreReader.close();
//		return highscoreP2;
//	}
//	void SaveHighScoreP1(int& Score, int& highscore)
//	{
//		if (Score > highscore)
//		{
//			highscore = Score;
//			std::ofstream scorewriter;
//			scorewriter.open("sc1.txt");
//				scorewriter << highscore;
//			scorewriter.close();
//		}
//
//	}
//	void SaveHighScoreP2(int& Score, int& highscore)
//	{
//		if (Score > highscore)
//		{
//			highscore = Score;
//			std::ofstream scorewriter;
//			scorewriter.open("sc2.txt");
//				scorewriter << highscore;
//			scorewriter.close();
//		}
//
//	}
//
//	
//	void PlayerVSPlayer(Paddle* rightPaddle, Paddle* leftPaddle, Ball* ball)
//	{
//		int highscoreP1 = LoadHighScoreP1();
//		int highscoreP2 = LoadHighScoreP2();
//
//		if (PlayerOne_Score >= 12 && (PlayerOne_Score - PlayerTwo_Score) > 1)
//		{
//			Max_Score_P1 = PlayerOne_Score;
//			winnerText1 = "Player One Wins!";
//			winnerText3 = "Press Space Bar to start again";
//		}
//		if (PlayerTwo_Score >= 12 && (PlayerTwo_Score - PlayerOne_Score) > 1)
//		{
//			Max_Score_P2 = PlayerTwo_Score;
//			winnerText2 = "Player Two Wins!";
//			winnerText3 = "Press Space Bar to Start again";
//		}
//		SaveHighScoreP1(Max_Score_P1, highscoreP1);
//		SaveHighScoreP2(Max_Score_P2, highscoreP2);
//
//		if (winnerText1 && IsKeyPressed(KEY_SPACE))
//		{
//			ball->SetX(GetScreenWidth() / 2.0);
//			ball->SetY(GetScreenHeight() / 2.0);
//			ball->SetSpeedX(300);
//			ball->SetSpeedY(0);
//			winnerText1 = nullptr;
//			winnerText2 = nullptr;
//			winnerText3 = nullptr;
//			tempBX = (GetScreenWidth() / 2.0);
//			tempBY = (GetScreenHeight() / 2.0);
//			tempBSX = 300;
//			tempBSY = 300;
//			PlayerOne_Score = 0;
//			PlayerTwo_Score = 0;
//		}
//		if (winnerText2 && IsKeyPressed(KEY_SPACE))
//		{
//
//			ball->SetX(GetScreenWidth() / 2.0);
//			ball->SetY(GetScreenHeight() / 2.0);
//			ball->SetSpeedX(-300);
//			ball->SetSpeedY(0);
//			winnerText1 = nullptr;
//			winnerText2 = nullptr;
//			winnerText3 = nullptr;
//			tempBX = (GetScreenWidth() / 2.0);
//			tempBY = (GetScreenHeight() / 2.0);
//			tempBSX = 300;
//			tempBSY = 300;
//			PlayerOne_Score = 0;
//			PlayerTwo_Score = 0;
//
//		}
//		if (!winnerText1 && !winnerText2)
//		{
//			tempBX = tempBX + ball->GetSpeedX() * GetFrameTime();
//			ball->SetX(tempBX);
//			tempBY = tempBY + ball->GetSpeedY() * GetFrameTime();
//			ball->SetY(tempBY);
//
//			if (ball->GetY() < 149)
//			{
//				ball->SetY(150);
//				ball->SetSpeedY(tempBSY);
//			}
//			if (ball->GetY() > 499)
//			{
//				ball->SetY(500);
//				ball->SetSpeedY(-tempBSY);
//			}
//			if (IsKeyDown(KEY_W))
//			{
//				tempYL = tempYL - (leftPaddle->GetSpeed() * GetFrameTime());
//				leftPaddle->SetY(tempYL);
//
//				if (leftPaddle->GetY() < 149)
//				{
//					tempYL = 150;
//					leftPaddle->SetY(tempYL);
//				}
//			}
//			if (IsKeyDown(KEY_S))
//			{
//				tempYL = tempYL + (leftPaddle->GetSpeed() * GetFrameTime());
//				leftPaddle->SetY(tempYL);
//
//				if (leftPaddle->GetY() > 499)
//				{
//					tempYL = 500;
//					leftPaddle->SetY(tempYL);
//				}
//			}
//
//			if (IsKeyDown(KEY_UP))
//			{
//				tempYR = tempYR - (rightPaddle->GetSpeed() * GetFrameTime());
//				rightPaddle->SetY(tempYR);
//
//				if (rightPaddle->GetY() < 149)
//				{
//					tempYR = 150;
//					rightPaddle->SetY(tempYR);
//				}
//
//			}
//			if (IsKeyDown(KEY_DOWN))
//			{
//				tempYR = tempYR + (rightPaddle->GetSpeed() * GetFrameTime());
//				rightPaddle->SetY(tempYR);
//				if (rightPaddle->GetY() > 499)
//				{
//					tempYR = 500;
//					rightPaddle->SetY(tempYR);
//				}
//
//			}
//
//			if (CheckCollisionCircleRec(ball->Vect(), ball->GetRadius(), leftPaddle->GetRect()))
//			{
//				if (ball->GetSpeedX() < 0)
//				{
//					tempBSX *= -1.1;
//					ball->SetSpeedX(tempBSX);
//					ball->SetSpeedY(((ball->GetY() - leftPaddle->GetY()) / (leftPaddle->GetHeight() / 2) * ball->GetSpeedX()));
//				}
//			}
//			if (CheckCollisionCircleRec(ball->Vect(), ball->GetRadius(), rightPaddle->GetRect()))
//			{
//				if (ball->GetSpeedX() > 0)
//				{
//					tempBSX *= -1.1;
//					ball->SetSpeedX(tempBSX);
//					ball->SetSpeedY(((ball->GetY() - rightPaddle->GetY()) / (rightPaddle->GetHeight() / 2) * -ball->GetSpeedX()));
//				}
//			}
//
//			if (ball->GetX() < -1)
//			{
//				PlayerOne_Score = PlayerOne_Score + 1;
//				Max_Score_P1 = PlayerOne_Score;
//				ball->SetX(GetScreenWidth() / 2.0);
//				ball->SetY(GetScreenHeight() / 2.0);
//				ball->SetSpeedX(300);
//				ball->SetSpeedY(0);
//				tempBX = (GetScreenWidth() / 2.0);
//				tempBY = (GetScreenHeight() / 2.0);
//				tempBSX = 300;
//				tempBSY = 300;
//
//			}
//			if (ball->GetX() > GetScreenWidth() + 1)
//			{
//				PlayerTwo_Score = PlayerTwo_Score + 1;
//				Max_Score_P2 = PlayerTwo_Score;
//
//				ball->SetX(GetScreenWidth() / 2.0);
//				ball->SetY(GetScreenHeight() / 2.0);
//				ball->SetSpeedX(-300);
//				ball->SetSpeedY(0);
//				tempBX = (GetScreenWidth() / 2.0);
//				tempBY = (GetScreenHeight() / 2.0);
//				tempBSX = 300;
//				tempBSY = 300;
//			}
//		}
//
//		//Reset
//		if (IsKeyPressed(KEY_R))
//		{
//			ball->SetX(GetScreenWidth() / 2.0);
//			ball->SetY(GetScreenHeight() / 2.0);
//			ball->SetSpeedX(300);
//			ball->SetSpeedY(0);
//			winnerText1 = nullptr;
//			winnerText2 = nullptr;
//			winnerText3 = nullptr;
//			tempBX = (GetScreenWidth() / 2.0);
//			tempBY = (GetScreenHeight() / 2.0);
//			tempBSX = 300;
//			tempBSY = 300;
//			PlayerOne_Score = 0;
//			PlayerTwo_Score = 0;
//		}
//
//		BeginDrawing();
//		ClearBackground(LIGHTGRAY);
//		court->Draw();
//		ball->Draw();
//		leftPaddle->Draw();
//		rightPaddle->Draw();
//		
//		DrawText(TextFormat("P2 Score: %d", PlayerOne_Score), 660, 550, 20, WHITE);
//		DrawText(TextFormat("P1 Score: %d", PlayerTwo_Score), 40, 550, 20, WHITE);
//		DrawText(TextFormat("P2 High Score: %d", highscoreP1), 600, 50, 20, WHITE);
//		DrawText(TextFormat("P1 High Score: %d", highscoreP2), 40, 50, 20, WHITE);
//
//
//		if (winnerText1)
//		{
//			int textWidth1 = MeasureText(winnerText1, 60);
//			int textWidth2 = MeasureText(winnerText2, 60);
//			int textWidth3 = MeasureText(winnerText3, 60);
//			DrawText(winnerText1, 250 ,50, 30, BLUE);
//			DrawText(winnerText2, 250,50, 30, BLUE);
//			DrawText(winnerText3, 175,90, 25, BLUE);
//		}
//		if (winnerText2)
//		{
//			int textWidth1 = MeasureText(winnerText1, 60);
//			int textWidth2 = MeasureText(winnerText2, 60);
//			int textWidth3 = MeasureText(winnerText3, 60);
//			DrawText(winnerText1, 250, 50, 30, BLUE);
//			DrawText(winnerText2, 250, 50, 30, BLUE);
//			DrawText(winnerText3, 175, 90, 25, BLUE);
//
//		}
//		EndDrawing();
//
//	}
//
//
//};
//#endif