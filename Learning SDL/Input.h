#pragma once
#include <SDL.h>

struct MousePos
{
	int x;
	int y;
};

class Input
{

public:
	Input();
	void Update();

	char GetKeyUp();
	char GetKeyDown();

	int GetMouseButtonDown();
	int GetMouseButtonUp();

	bool KeyPress();
	bool MouseClick();
	bool ClosedWindow();

	const MousePos& GetMousePosition();

private:

	char m_keyUp;
	char m_keyDown;

	bool m_KeyPress = false;
	bool m_MouseClick = false;
	bool m_ClosedWindow = false;

	int m_mouseButtonUp;
	int m_mouseButtonDown;

	MousePos m_mousePosition;

};