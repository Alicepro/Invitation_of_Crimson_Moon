#ifndef _SDL_EX_H_
#define _SDL_EX_H_

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_thread.h>
#include <string>
#include <iostream>
#include <ctime>
#include <stdexcept>
#include <Windows.h>

#define SDL_EX_IMG

#pragma comment(lib,"SDL2.lib")
#pragma comment(lib,"SDL2main.lib")
#pragma comment(lib,"SDL2test.lib")
#ifdef SDL_EX_IMG
#pragma comment(lib,"SDL2_image.lib")
#endif
#ifdef SDL_EX_MIX
#pragma comment(lib,"SDL2_mixer.lib")
#include <SDL_mixer.h>
#endif
#ifdef SDL_EX_TTF
#pragma comment(lib,"SDL2_ttf.lib")
#include <SDL_ttf.h>
#endif

typedef struct
{
	unsigned int Height;
	unsigned int Width;
	std::string Title;
	SDL_Renderer *Ren;
	SDL_Window *Win;
	SDL_Surface *Sur;
}_Windows_Infomation;

void Init_Window(unsigned int Height, unsigned Width, std::string Title);

void Quit_All(void);

SDL_Texture *LoadImage(std ::string FileName);

void Draw_TexPic(unsigned int x,unsigned int y,SDL_Texture *Tex,SDL_Rect *clip = NULL);

void Refresh_Window(void);

#endif
