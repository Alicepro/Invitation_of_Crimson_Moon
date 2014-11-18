#ifndef _GAME_H_
#define _GAME_H_

#include "SDL_EX.h"
#include "move_hero.h"

//Th06��Ļ��:640 ��: 480
//Th06��Ϸ���򵽶���:16
//�ײ�:16
//�Ҳ�:32
//��Ϸ����߶�:448
//���:384

//�Ի����� 45*25

typedef struct Game_Pth
{
	SDL_Thread *Refr = nullptr;//ˢ��
	SDL_Thread *Fid_Run = nullptr;//��������ָ��
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
	SDL_Window *wWind;
}Game_BackGround;

extern const int Game_Width;//��Ϸ���ڿ��
extern const int Game_Height;//��Ϸ���ڸ߶�

extern const int Hero_H;//�Ի��ĸ߶�
extern const int Hero_W;//�Ի��Ŀ��

extern bool IS_GAME_RUN;//��Ϸ�Ƿ�����

typedef struct Game_Field;



/***********************************************************************
��������:Init_Game
��������:��ʼ����Ϸ
�����β�:��
��������ֵ:��
***********************************************************************/
void Init_Game(void);

/***********************************************************************
��������:Refresh_BkPic_Windows
��������:ˢ�´��ڱ���ͼƬ
�����β�:��
��������ֵ:��
***********************************************************************/
void Refresh_BkPic_Windows(void);

/***********************************************************************
��������:Refresh_Field_BackGround_Pic
��������:ˢ����Ϸ����,����ˢ��,ʹ���̲߳���
�����β�:ͼƬ�߶�
��������ֵ:��
***********************************************************************/
int Refresh_Field_BackGround_Pic(void *data);

/***********************************************************************
��������:Scr_Field
��������:��Ϸ���򱳾�ͼƬ������
�����β�:������,����������Ϊ1,��������,����رս���
��������ֵ:��
***********************************************************************/
void Scr_Field(int sw);

/***********************************************************************
��������:Quit_Game
��������:�ر���Ϸ���ͷ���Դ
�����β�:��
��������ֵ:��
***********************************************************************/
void Quit_Game(void);

void SetSDLWindowIcon(SDL_Window *win);
#endif