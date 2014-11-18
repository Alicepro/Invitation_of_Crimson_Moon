#include "SDL_EX.h"

_Windows_Infomation Window_Info;

void SetSDLWindowIcon(SDL_Window *win)
{
	SDL_Surface *icon = NULL;

	icon = SDL_LoadBMP("src\\31.bmp");
	//设置图片中的透明色
	SDL_SetColorKey(icon, SDL_TRUE, SDL_MapRGB(icon->format, 0xFF, 0, 0xFF));
	SDL_SetWindowIcon(win, icon); // win 是之前 SDL_CreateWindow()创建的窗口
	SDL_FreeSurface(icon);
}

void Init_Window(unsigned int Height, unsigned Width, std::string Title)
{
	Window_Info.Height = Height;
	Window_Info.Width = Width;
	Window_Info.Title = Title;
	Window_Info.Ren = nullptr;
	Window_Info.Win = nullptr;
	Window_Info.Sur = nullptr;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		throw std::runtime_error("SDL Init Failed!!");
#ifdef SDL_EX_TTF
	if (TTF_Init() < 0)
		throw std::runtime_error("TTF Init Failed!!");
#endif
	if (SDL_CreateWindowAndRenderer(Window_Info.Width, Window_Info.Height, SDL_WINDOW_SHOWN, &Window_Info.Win, &Window_Info.Ren) < 0)
	{
		std::cout << "Fuck!!" << SDL_GetError() << std::endl;
	}
	

	std::cout << "Fuck!!" << SDL_GetError() << std::endl;

	SDL_SetWindowTitle(Window_Info.Win, Title.c_str());
	Window_Info.Sur = SDL_GetWindowSurface(Window_Info.Win);

	SetSDLWindowIcon(Window_Info.Win);
	if (Window_Info.Sur == nullptr)
		throw std::runtime_error("Failed to Get Window Surface!!");
}

void Quit_All(void)
{
#ifdef SDL_EX_TTF
	TTF_Quit();
#endif
#ifdef SDL_EX_IMG
	IMG_Quit();
#endif
	SDL_Quit();
}

SDL_Texture *LoadImage(std::string FileName)
{
#ifdef SDL_EX_IMG
	SDL_Texture *Tex = nullptr;
	SDL_Surface *Sur = nullptr;
	Sur = IMG_Load(FileName.c_str());
	if (Sur == nullptr)
		throw std::runtime_error("Failed to load Image: " + FileName + IMG_GetError());
	SDL_Surface *Sur_2 = nullptr;
	Sur_2 = SDL_ConvertSurface(Sur, Window_Info.Sur->format, 0);
	if (Sur_2 == nullptr)
		throw std::runtime_error("Failed to optimize image: " + FileName + SDL_GetError());
	SDL_FreeSurface(Sur);
	Tex = SDL_CreateTextureFromSurface(Window_Info.Ren, Sur_2);
	if (Tex == nullptr)
		throw std::runtime_error("Failed to create texture from surface: " + FileName + SDL_GetError());
	return Tex;
#endif
	throw std::runtime_error("You did not chose the Img Model!!");
	return nullptr;
}

void Draw_TexPic(unsigned int x, unsigned int y, SDL_Texture *Tex, SDL_Rect *clip)
{
	SDL_Rect pos;
	pos.x = x;
	pos.y = y;
	if (clip != NULL){
		pos.w = clip->w;
		pos.h = clip->h;
	}
	else {
		SDL_QueryTexture(Tex, NULL, NULL, &pos.w, &pos.h);
	}
	SDL_RenderCopy(Window_Info.Ren, Tex, clip, &pos);
}

void Refresh_Window(void)
{
	SDL_RenderPresent(Window_Info.Ren);
}



