#pragma once
#include "../Figure/Figure.h"
#include "../Move/Move.h"
#include "../Easing/easing.hpp"
class Player
{
private:
	enum{MAXANIME=18};
	float angle;
	int animcnt;
	bool isDead;
	int handle[12];
public:
	Circle body;
	Move move;
	Easing ease;
	Player();				//初期化
	~Player() {};			//解放処理
	void Dead();			//Playerを殺す
	POS GetPos() { return body.pos; }
	bool IsDead();		//プレイヤーの状態チェック
	bool IsUpdate();		//更新。主に移動系
	void Draw();			//描画
};