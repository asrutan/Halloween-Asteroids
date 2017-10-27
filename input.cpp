// input.cpp
// Alex Rutan
// 10/19/17
#include <iostream>
#include "input.h"

using namespace std;

Input::Input()
{
	SDL_Event event;
	quit = false;
	keyboard[0] = false;
	keyboard[1] = false;
	keyboard[2] = false;
} //end constructor

Input::~Input()
{
} //end destructor

void Input::keyEvents()
{
	while (SDL_PollEvent(&event) != 0)
	{
		if (event.type == SDL_MOUSEBUTTONDOWN && event.key.repeat == 0)
		{
			click = true;
			//SDL_GetMouseState(&mousex, &mousey);
		}
		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_RIGHT)
			{
				(keyboard[0] = true);
			} //end if
			if (event.key.keysym.sym == SDLK_LEFT)
			{
				(keyboard[1] = true);
			} //end if
			if (event.key.keysym.sym == SDLK_SPACE)
			{
				(keyboard[2] = true);
			} //end if
		}
		if (event.type == SDL_KEYUP)
		{
			if (event.key.keysym.sym == SDLK_RIGHT)
			{
				(keyboard[0] = false);
			} //end if
			if (event.key.keysym.sym == SDLK_LEFT)
			{
				(keyboard[1] = false);
			} //end if
			if (event.key.keysym.sym == SDLK_SPACE)
			{
				(keyboard[2] = false);
			} //end if
		}
	} //end if
} //end while
  //end keyEvents

bool Input::getMouseClick()
{
	if (click)
	{
		click = false;
		return(true);
	}
	else return false;
}

int Input::getMousePos()
{

	SDL_GetMouseState(&mousex, &mousey);
	return(mousex, mousey);
}

bool Input::getKeys(int x)
{
	return keyboard[x];
}

