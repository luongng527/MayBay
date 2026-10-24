#pragma once

#include "KeyEventHandler.h"

class CSampleKeyHandler2 : public CKeyEventHandler
{
	virtual void KeyState(BYTE* states);
	virtual void OnKeyDown(int KeyCode);
	virtual void OnKeyUp(int KeyCode);
};