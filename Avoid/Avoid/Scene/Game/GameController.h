#pragma once
#include "../Game/Player.h"
#include "../Collision/Collision.h"
#include "../Scene/Game/Back.h"
#include "../MyDxSound/My_DxSound.h"
#include "UI.h"
#include "Block.h"
//ゲームオブジェクト管理
class GameController
{
private:
	float score;
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
	Sound sound;
	UI ui;
	Player player;
	Obstacle obstacle;
	Collision collision;
	BackGround back;
	State GameCheck();					//ゲームの状態をチェック	
	void GameStart();						//Zキーでゲームを開始する
	bool HitCheck();						//障害物との当たり判定
	void AddScore() { score += 1.f / 60.f; };	//スコアは秒数
	bool CheckScore() {
		if (score >= 51.f)
			return true;
		return false;
	};
public:
	GameController();
	~GameController();
    static  int Disp_Widih();			
	static  int Disp_Height();
	bool IsUpdate();
	void Draw();
};