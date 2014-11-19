#include "SDL_EX.h"
#include "game.h"

extern const int Hero_H = 45;//自机的高度
extern const int Hero_W = 25;//自机的宽度

extern bool IS_GAME_RUN = true;

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
	SDL_Rect clip[2];
	Game_Field Field;
	int i = Field.y + Field.Height;

	clip[0].x = 0;
	clip[0].y = 0;
	clip[0].h = Field.Height;
	clip[0].w = Field.Width;

	clip[1].x = 0;
	clip[1].y = 0;
	clip[1].h = 0;
	clip[1].w = Field.Width;;
	while (1)
	{
// 		for (i = 0; i <= Field.Pic_Height; i++)
// 		{
// 			if ((Field.Height - i) < Field.Height)
// 			{
// 				clip.h = Field.Pic_Height - i;
// 				clip.w = Field.Width;
// 				clip.x = 0;
// 				clip.y = i;
// 				Draw_TexPic(Field.x, Field.y, BackGround.Fid, &clip);
// 				clip.h = Field.Height - (Field.Height - i);
// 				clip.y = 0;
// 				Draw_TexPic(Field.x, Field.y + (Field.Pic_Height - i), BackGround.Fid, &clip);
// 			}
// 			else
// 			{
// 				clip.h = Field.Height;
// 				clip.w = Field.Width;
// 				clip.x = 0;
// 				clip.y = i;//从背景图片中截取448x384背景图片的起始位置纵坐标,x总为0;
// 				Draw_TexPic(Field.x, Field.y, BackGround.Fid, &clip);
// 			}
			//out_text(400, 200, Game_Screen, "Nice to meet you", "src\\SCP_L.ttf", { 0, 0, 0 }, 12);
		if (clip[0].y < (Field.Pic_Height - Field.Height))
		{
			Draw_TexPic(Field.x, Field.y, BackGround.Fid, &clip[0]);
			clip[0].y++;
		}
		
		if (clip[0].y >= (Field.Pic_Height - Field.Height) )
		{
			Draw_TexPic(Field.x, Field.y, BackGround.Fid, &clip[0]);
			Draw_TexPic(Field.x, i, BackGround.Fid, &clip[1]);
			i--;
			clip[0].h--;
			clip[0].y++;
			clip[1].h++;

			if (clip[0].h == 0)
			{
				clip[0].h = Field.Height;
				clip[0].y = 0;
				clip[1].h = 0;
				i = Field.y + Field.Height;
			}
		}
		Refresh_Window();
		
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