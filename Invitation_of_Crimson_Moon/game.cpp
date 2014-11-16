#include "game.h"

extern const int Hero_H = 45;//自机的高度
extern const int Hero_W = 25;//自机的宽度

extern bool IS_GAME_RUN = true;

typedef struct Game_Pth
{
	SDL_Thread *Refr = nullptr;//刷新
	SDL_Thread *Fid_Run = nullptr;//背景滚动指针
};

typedef struct Game_Field
{
	int Pic_Height = 1000;
	int x = 32;
	int y = 16;
	int Width = 384;
	int Height = 448;//==>
};

typedef struct
{
	SDL_Texture *Win;
	SDL_Texture *Fid;
}Game_BackGround;

Game_Field Field;
Game_BackGround BackGround;
Game_Pth Thread;

void Init_Game(void)
{
	Init_Window(480, 640, "Invitation of Crimson Moon!");
	BackGround.Fid = LoadImage("src\\background\\GameField_BackGround.png");
	BackGround.Win = LoadImage("src\\background\\GameWindows_BackGround.png");
}

void Refresh_BkPic_Windows(void)
{
	Draw_TexPic(0, 0, BackGround.Win);
	Refresh_Window();
}

int Refresh_Field_BackGround_Pic(void *data)
{
	int i;
	SDL_Rect clip[1];
	while (IS_GAME_RUN)
	{
		for (i = 0; IS_GAME_RUN&&(i <= Field.Pic_Height); i++)
		{
			if ((Field.Height - i) < Field.Height)
			{
				clip[0].h = Field.Pic_Height - i;
				clip[0].w = Field.Width;
				clip[0].x = 0;
				clip[0].y = i;
				Draw_TexPic(Field.x, Field.y, BackGround.Fid, &clip[0]);
				clip[0].h = Field.Height - (Field.Height - i);
				clip[0].y = 0;
				Draw_TexPic(Field.x, Field.y + (Field.Pic_Height - i), BackGround.Fid, &clip[0]);
			}
			else
			{
				clip[0].h = Field.Height;
				clip[0].w = Field.Width;
				clip[0].x = 0;
				clip[0].y = i;//从背景图片中截取448x384背景图片的起始位置纵坐标,x总为0;
				Draw_TexPic(Field.x, Field.y, BackGround.Fid, &clip[0]);
			}
			//out_text(400, 200, Game_Screen, "Nice to meet you", "src\\SCP_L.ttf", { 0, 0, 0 }, 12);
			Refresh_Window();
		}
	}
	return 0;
}

void Scr_Field(int sw)
{
	//thread = SDL_CreateThread(Refresh_Field_BackGround_Pic, NULL);
	Thread.Fid_Run = SDL_CreateThread(Refresh_Field_BackGround_Pic, "RunFieldBackGround", NULL);
}

void Quit_Game(void)
{

	//SDL_KillThread();
}


