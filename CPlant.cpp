#include "CPlant.h"

CPlant::CPlant(float x, float y) : CGameObject(x, y) {
	ax = 0;
	ay = 0;
}

void CPlant::Update(DWORD dt)
{
	// 1. Cập nhật vận tốc (v = v + a*t) TRƯỚC
	vx += ax * dt;
	vy += ay * dt;

	// Giảm tốc trục X (Ngang) khi thả phím
	if (ax == 0.0f)
	{
		if (vx > 0) // Đang trượt sang phải
		{
			vx -= PLANT_ACCEL * dt;
			if (vx < 0) vx = 0; // Tránh bị trôi lố ngược lại
		}
		else if (vx < 0) // Đang trượt sang trái
		{
			vx += PLANT_ACCEL * dt;
			if (vx > 0) vx = 0; // Tránh bị trôi lố ngược lại
		}
	}

	// Giảm tốc trục Y (Dọc) khi thả phím
	if (ay == 0.0f)
	{
		if (vy > 0) // Đang trượt xuống
		{
			vy -= PLANT_ACCEL * dt;
			if (vy < 0) vy = 0;
		}
		else if (vy < 0) // Đang trượt lên
		{
			vy += PLANT_ACCEL * dt;
			if (vy > 0) vy = 0;
		}
	}

	// 2. Giới hạn vận tốc (Phải giữ đúng dấu âm/dương để không bị giật ngược)
	if (abs(vx) > PLANT_SPEED)
	{
		if (vx > 0) vx = PLANT_SPEED;       // Đang bay phải -> max tốc độ phải
		else        vx = -PLANT_SPEED;      // Đang bay trái -> max tốc độ trái
	}

	if (abs(vy) > PLANT_SPEED)
	{
		if (vy > 0) vy = PLANT_SPEED;       // Đang bay xuống -> max tốc độ xuống
		else        vy = -PLANT_SPEED;      // Đang bay lên   -> max tốc độ lên
	}

	// 3. Cập nhật tọa độ (x = x + v*t) SAU KHI vận tốc đã chuẩn xác
	x += vx * dt;
	y += vy * dt;

	// Debug xem log
	DebugOutTitle(L"vx = %0.5f | vy = %0.5f", this->vx, this->vy);

	// 4. Va chạm biên màn hình (Chặn không cho bay ra ngoài)
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
	case PLANT_STOP_X:
		ax = 0.0f;
		//vx = 0.0f; // Nếu muốn máy bay trượt theo quán tính thì xóa dòng vx = 0 này đi
		break;
	case PLANT_STOP_Y:
		ay = 0.0f;
		//vy = 0.0f; // Nếu muốn máy bay trượt theo quán tính thì xóa dòng vy = 0 này đi
		break;

	case PLANT_MOVE_STRANGT: // Sang phải
		ax = PLANT_ACCEL;
		break;
	case PLANT_MOVE_LUI: // Sang trái
		ax = -PLANT_ACCEL;
		break;
	case PLANT_MOVE_DOWN: // Đi xuống
		ay = PLANT_ACCEL;
		break;
	case PLANT_MOVE_UP: // Đi lên
		ay = -PLANT_ACCEL;
		break;
	}

	CGameObject::SetState(state);
}