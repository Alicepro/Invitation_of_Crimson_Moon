#include <iostream>
#undef main
#include "game.h"


int main(int argc,char *argv[])
{
	SDL_Event event;
	Init_Game();
	Refresh_BkPic_Windows();
	Scr_Field(1);
	while (1)
	{
		while (SDL_PollEvent(&event))
		{

			if (event.type == SDL_QUIT)
			{
				IS_GAME_RUN = false;
				SDL_Quit();
				exit(1);
			}
		}
	}
	IS_GAME_RUN = false;
	SDL_Quit();
	return 0;
}