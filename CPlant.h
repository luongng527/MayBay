#pragma once
#include "GameObject.h"

#include "Animation.h"
#include "Animations.h"

#include "debug.h"

#define PLANT_SPEED		0.2f
#define PLANT_ACCEL		0.0005f



#define PLANT_NOTMOVE 3000
#define PLANT_MOVE_STRANGT 3001
#define PLANT_MOVE_UP	3002
#define PLANT_MOVE_DOWN 3003
#define PLANT_MOVE_LUI 3004


#pragma region ANIMATION_ID

#define ID_ANI_PLANT_NOTMOVE 5270
#define ID_ANI_PLANT_STRANGT 5271
#define ID_ANI_PLANT_UP 5272
#define ID_ANI_PLANT_DOWN 5273

#pragma endregion



class CPlant : public CGameObject
{
	float vx, vy;
	float ax;				// acceleration on x 
	float maxV;	
	float ay;				// acceleration on x 
public:
	CPlant(float x, float y);
	void Update(DWORD dt);
	void Render();
	void SetState(int state);
};

