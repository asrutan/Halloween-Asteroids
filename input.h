//movement.h
//Alex Rutan
//11/21/15

#ifndef INPUT_EXIST
#define INPUT_EXIST

#include <SDL2/SDL.h>

class Input
{
private:
	SDL_Event event;
	bool quit;
	bool click;
	bool keyboard[3];

public:
	Input();
	~Input();

	int mousex;
	int mousey;

	void keyEvents();

	int getMousePos();
	bool getMouseClick();
	bool getKeys(int);

}; //end Input

#endif //INPUT_EXISTS
