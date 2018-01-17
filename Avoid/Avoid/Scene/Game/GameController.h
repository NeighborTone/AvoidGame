#pragma once
#include "../Game/Player.h"
#include "../Collision/Collision.h"
#include "../Scene/Game/Back.h"
#include "UI.h"
#include "Block.h"
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
public:
	UI ui;
	Player player;
	Obstacle obstacle;
	Collision collision;
	BackGround back;
	GameController();
    static  int Disp_Widih();			//画面サイズの情報は常に保持
	static  int Disp_Height();
	State GameCheck();					//ゲームの状態をチェック	
	void GameStart();						//Zキーでゲームを開始する
	bool HitCheck();						//障害物との当たり判定
	bool GameEnd();						//ゲームオーバーならゲームを終了させる
	void Update();
	void Draw();
};