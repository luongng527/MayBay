#include "CPlant.h"

CPlant::CPlant(float x, float y) : CGameObject(x, y) {
	ax = 0;
	ay = 0;
}

void CPlant::Update(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;

	vx += ax * dt;
	vy += ay * dt;

	DebugOutTitle(L"vx = %0.5f", this->vx);
	DebugOutTitle(L"vy = %0.5f", this->vy);

	if (abs(vx) > abs(maxV)) vx = maxV;
	if (abs(vy) > abs(maxV)) vy = maxV;

	// simple screen edge collision!!!
	if (vx > 0 && x > 290) x = 290;
	if (vx < 0 && x < 15) x = 15;
	if (vy > 0 && y > 190) y = 190;
	if (vy < 0 && y < 0) y = 0;
}


void CPlant::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	int aniId = -10;

	// Mario is still on air check, this will not work when Mario is just stand up

	if (ay > 0)
		aniId = ID_ANI_PLANT_DOWN;
	else if (ay < 0)
		aniId = ID_ANI_PLANT_UP;
	else if (abs(ax) > 0)
		aniId = ID_ANI_PLANT_STRANGT;
	else 
		aniId = ID_ANI_PLANT_NOTMOVE;

	if (aniId == -10) aniId = ID_ANI_PLANT_NOTMOVE;

	animations->Get(aniId)->Render(x, y);
}

void CPlant::SetState(int state)
{
	switch (state)
	{
	case PLANT_NOTMOVE:
		vx = 0.0f;
		vy = 0.0f;
		ax = 0.0f;
		ay = 0.0f;
		break;
	case PLANT_MOVE_STRANGT:
		maxV = PLANT_SPEED;
		ax = PLANT_ACCEL;
		break;
	case PLANT_MOVE_LUI:
		maxV = -PLANT_SPEED;
		ax = -PLANT_ACCEL;
		break;
	case PLANT_MOVE_DOWN:
		maxV = PLANT_SPEED;
		ay = PLANT_ACCEL;
		break;
	case PLANT_MOVE_UP:
		maxV = -PLANT_SPEED;
		ay = -PLANT_ACCEL;
		break;
	}

	CGameObject::SetState(state);
}