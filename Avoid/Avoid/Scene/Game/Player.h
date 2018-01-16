#pragma once
#include "../Figure/Figure.h"
#include "../Move/Move.h"
#include "../Easing/easing.hpp"
class Player
{
private:
	bool isDead;
public:
	Circle body;
	Move move;
	Easing ease;
	Player();			//‰Šú‰»
	~Player() {};		//‰ğ•úˆ—
	void Dead();		//Player‚ğE‚·
	void Update();	//XVBå‚ÉˆÚ“®Œn
	void Draw();		//•`‰æ
};