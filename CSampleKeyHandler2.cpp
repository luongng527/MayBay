#include "CSampleKeyHandler2.h"

#include "debug.h"
#include "Game.h"

#include "CPlant.h"

extern CPlant* plant;

void CSampleKeyHandler2::OnKeyDown(int KeyCode)
{
	DebugOut(L"[INFO] KeyDown: %d\n", KeyCode);
	switch (KeyCode)
	{
	
		break;
	}
}

void CSampleKeyHandler2::OnKeyUp(int KeyCode)
{
	DebugOut(L"[INFO] KeyUp: %d\n", KeyCode);
	switch (KeyCode)
	{
	
		break;
	}
}

void CSampleKeyHandler2::KeyState(BYTE* states)
{
	CGame* game = CGame::GetInstance();

	// 1. Xử lý trục Ngang (X)
	if (game->IsKeyDown(DIK_RIGHT))
	{
		plant->SetState(PLANT_MOVE_STRANGT);
	}
	else if (game->IsKeyDown(DIK_LEFT))
	{
		plant->SetState(PLANT_MOVE_LUI);
	}
	else 
	{
		plant->SetState(PLANT_STOP_X); // Định nghĩa thêm state này
	}

	// 2. Xử lý trục Dọc (Y)
	if (game->IsKeyDown(DIK_DOWN))
	{
		plant->SetState(PLANT_MOVE_DOWN);
	}
	else if (game->IsKeyDown(DIK_UP))
	{
		plant->SetState(PLANT_MOVE_UP);
	}
	else 
	{
		plant->SetState(PLANT_STOP_Y); // Định nghĩa thêm state này
	}
}