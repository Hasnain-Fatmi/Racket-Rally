//#ifndef _GAMEMENU_H
//#define _GAMEMENU_H
//#include "raylib.h"
//#define RAYGUI_IMPLEMENTATION
//#include "raygui.h"
//
//class GameMenu
//{
// bool QUIT;
// bool PVP;
// bool PVC;
// bool ABOUT;
// bool Menu;
//
//public:
//	GameMenu() 
//	{
//		Menu = true;
//		PVC = false;
//		PVP = false;
//		QUIT = false;
//		ABOUT = false;
//
//	}
//	~GameMenu() {}
//	void drawMain() 
//	{
//		BeginDrawing();
//		ClearBackground(SKYBLUE);
//		EndDrawing();
//
//		GuiSetStyle(BUTTON, TEXT_ALIGNMENT, TEXT_ALIGN_CENTER);
//
//		if (GuiButton(Rectangle{ 325, 125, 135, 75 }, "PLAY GAME")) 
//		{
//			ABOUT = false;
//			Menu = false;
//			PVC = false;
//			PVP = true;
//			QUIT = false;
//		}		
//		if (GuiButton(Rectangle{ 325, 205, 135, 75 }, "PRACTICE")) 
//		{
//			ABOUT = false;
//			Menu = false;
//			PVP = false;
//			PVC = true;
//			QUIT = false;
//		}
//		if (GuiButton(Rectangle{ 325, 285, 135, 75 }, "ABOUT")) 
//		{
//			ABOUT = true;
//			Menu = false;
//			PVP = false;
//			PVC = false;
//			QUIT = false;
//
//		}
//		if (GuiButton(Rectangle{ 325, 365, 135, 75 }, "Quit")) 
//		{
//			QUIT = true;
//		}
//
//	}
//	bool GetPVP()
//	{
//		return PVP;
//	}
//	bool GetPVC()
//	{
//		return PVC;
//	}
//	bool SetABT(bool about)
//	{
//		ABOUT = about;
//	}
//	bool GetABT()
//	{
//		return ABOUT;
//	}
//	void SetPVP(bool pvp)
//	{
//		PVP = pvp;
//	}
//	void SetPVC(bool pvc)
//	{
//		PVC = pvc;
//	}
//	void SetQuit(bool quit)
//	{
//		QUIT = quit;
//	}
//	bool GetQuit()
//	{
//		return QUIT;
//	}
//
//	void SetMenu(bool menu)
//	{
//		PVC = false;
//		PVP = false;
//		Menu = menu;
//	}
//	bool GetMenu()
//	{
//		return Menu;
//	}
//
//};
//#endif