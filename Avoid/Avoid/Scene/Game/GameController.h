#pragma once
#include "../Game/Player.h"
#include "../Collision/Collision.h"
#include "../Scene/Game/Back.h"
#include "../MyDxSound/My_DxSound.h"
#include "UI.h"
#include "Block.h"
#include "../Game/Score/Score.h"
#include <stdio.h>
//ゲームオブジェクト管理
class GameController
{
private:
	enum
	{
		SCREEN_WIDIH = 640,		
		SCREEN_HEIGHT = 480,
	};
	enum State
	{
		Ready,
		Play,
		GameOver,
	}state;
	Score score;
	Sound sound;
	UI ui;
	Player player;
	Obstacle obstacle;
	Collision collision;
	BackGround back;
	State GameCheck();					//ゲームの状態をチェック	
	void GameStart();						//Zキーでゲームを開始する
	bool HitCheck();						//障害物との当たり判定
public:
	GameController();
	~GameController();
    static  int Disp_Widih();			
	static  int Disp_Height();
	bool IsUpdate();
	void Draw();
};