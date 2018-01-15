#pragma once
#include "../Figure/Figure.h"
#include "../Move/Move.h"

class Player
{
private:
	bool isDead;
public:
	Circle body;
	Move move;
	Player();
	~Player() {};
	void Updata();
	void Draw();
};