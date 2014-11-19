#include <iostream>
#undef main
#include "SDL_EX.h"
#include "game.h"
int main(int argc,char *argv[])
{
	SDL_Event event;
	Init_Game();
	Refresh_BkPic_Windows();
	Scr_Field(1);
	while (event.type != SDL_QUIT)
	{
		if (SDL_PollEvent(&event))
		{
			//event.type = handle_events();
		}
	}
	SDL_Quit();
	return 0;
}