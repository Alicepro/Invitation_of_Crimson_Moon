#ifndef _GAME_H_
#define _GAME_H_

#include <SDL.h>
#include <SDL_thread.h>

//Th06屏幕宽:640 高: 480
//Th06游戏区域到顶部:16
//底部:16
//右侧:32
//游戏区域高度:448
//宽度:384

//自机长宽 45*25

typedef struct Game_Pth
{
	SDL_Thread *Refr = nullptr;//刷新
	SDL_Thread *Fid_Run = nullptr;//背景滚动指针
};

typedef struct Game_Field
{
	int Pic_Height = 1007;//图片长度
	int x = 32;//贴图x坐标
	int y = 16;//贴图y坐标
	int Width = 385;//区域宽度
	int Height = 448;//区域高度
};

typedef struct
{
	SDL_Texture *Win;
	SDL_Texture *Fid;
	SDL_Window *wWind;
}Game_BackGround;

extern const int Game_Width;//游戏窗口宽度
extern const int Game_Height;//游戏窗口高度

extern const int Hero_H;//自机的高度
extern const int Hero_W;//自机的宽度

extern bool IS_GAME_RUN;//游戏是否运行

typedef struct Game_Field;

/***********************************************************************
函数名称:Init_Game
函数作用:初始化游戏
函数形参:无
函数返回值:无
***********************************************************************/
void Init_Game(void);

/***********************************************************************
函数名称:Refresh_BkPic_Windows
函数作用:刷新窗口背景图片
函数形参:无
函数返回值:无
***********************************************************************/
void Refresh_BkPic_Windows(void);

/***********************************************************************
函数名称:Refresh_Field_BackGround_Pic
函数作用:刷新游戏区域,反复刷新,使用线程操作
函数形参:图片高度
函数返回值:无
***********************************************************************/
int Refresh_Field_BackGround_Pic(void *data);

/***********************************************************************
函数名称:Scr_Field
函数作用:游戏区域背景图片滚滚滚
函数形参:正整数,如果传入参数为1,启动进程,否则关闭进程
函数返回值:无
***********************************************************************/
void Scr_Field(int sw);

/***********************************************************************
函数名称:Quit_Game
函数作用:关闭游戏并释放资源
函数形参:无
函数返回值:无
***********************************************************************/
void Quit_Game(void);

void SetSDLWindowIcon(SDL_Window *win);
#endif