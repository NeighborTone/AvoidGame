#pragma once
#include "../Game/Player.h"
#include "../Collision/Collision.h"
#include "../Scene/Game/Back.h"
#include "Block.h"
//ゲームオブジェクト管理
class GameController
{
private:
	static int SCREEN_WIDIH,		//ゲームの情報は常に保持する
				 SCREEN_HEIGHT;
	int score;
	bool GameOver;
public:
	Player player;
	Obstacle obstacle;
	Collision collision;
	BackGround back;
	GameController();
    static  int Disp_Widih();
	static  int Disp_Height();
	void AddScore(int score) { this->score += score; };
	int  GetScore() { return score; };
	bool GameEnd();		//ゲームオーバーかチェック
	void Update();
	void Draw();
};