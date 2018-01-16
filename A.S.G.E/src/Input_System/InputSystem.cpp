#include "InputSystem.hpp"

InputSystem::InputSystem()
{
	_startUp();
}
InputSystem::~InputSystem()
{
	_shutDown();
}

InputSystem& InputSystem::getInstance()
{
	static InputSystem *instance = new InputSystem();
	return *instance;
}

void InputSystem::_startUp()
{
	printf("\033[?1003h\n");// Enable mouse events (h=high)
	mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION,NULL);
}

void InputSystem::_shutDown()
{
	printf("\033[?1003l\n"); // Disable mouse movement events (l=low)
}

void InputSystem::fillInputBuffer(WINDOW* win)
{
	int i = wgetch(win);
	bool flag = false;
	if (i!=ERR)
	{
		mvwprintw(win,1,2,"Input: %d",i);
		flag = false;
		if (i!=-103)
		{
			for (std::list<InputEvent>::const_iterator iterator = inputBuffer.begin(), end = inputBuffer.end(); iterator != end; ++iterator)
			{
				if ((*iterator).type==i)
				{
					flag = true;
				}
			}
		}
		if (flag==false)
		{
			InputEvent* e = new (InputEvent);
			if (i==KEY_MOUSE)
			{
				MEVENT m;
				e->type=KEY_MOUSE;
				getmouse(&m);
				e->mbutton_state = m.bstate;
				e->mpos.push_back(m.x);
				e->mpos.push_back(m.y);
				inputBuffer.push_back(*e);
			}
			else
			{
				e->type=i;
				inputBuffer.push_back(*e);
			}
		}
	}
}

void InputSystem::flushInputBuffer()
{
	inputBuffer.clear();
}

bool InputSystem::isKeyPressed(int scancode)
{

	for (std::list<InputEvent>::const_iterator iterator = inputBuffer.begin(), end = inputBuffer.end(); iterator != end; ++iterator)
	{
		if ((*iterator).type==scancode)
		{
			return true;
		}
	}
    return false;
}

bool InputSystem::isMouseKeyPressed(int scancode)
{

	for (std::list<InputEvent>::const_iterator iterator = inputBuffer.begin(), end = inputBuffer.end(); iterator != end; ++iterator)
	{
		if (iterator->type==KEY_MOUSE)
		{
			if (iterator->mbutton_state & scancode)
			{
				// printw("%d %d",iterator->mpos[0],iterator->mpos[1]);
				return true;
			}
		}
	}
    return false;
}
