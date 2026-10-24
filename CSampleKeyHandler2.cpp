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
	case DIK_S:
		plant->SetState(PLANT_NOTMOVE);
		break;
	}
}

void CSampleKeyHandler2::OnKeyUp(int KeyCode)
{
	DebugOut(L"[INFO] KeyUp: %d\n", KeyCode);
	switch (KeyCode)
	{
	case DIK_S:
		plant->SetState(PLANT_NOTMOVE);
		break;
	}
}

void CSampleKeyHandler2::KeyState(BYTE* states)
{
	CGame* game = CGame::GetInstance();

	if (game->IsKeyDown(DIK_RIGHT))
	{
		plant->SetState(PLANT_MOVE_STRANGT);
	}
	else if (game->IsKeyDown(DIK_LEFT))
	{
		plant->SetState(PLANT_MOVE_LUI);
	}
	else if (game->IsKeyDown(DIK_UP))
	{
		plant->SetState(PLANT_MOVE_UP);
	}
	else if (game->IsKeyDown(DIK_DOWN))
	{
		plant->SetState(PLANT_MOVE_DOWN);
	}
	else 
		plant->SetState(PLANT_NOTMOVE);
}