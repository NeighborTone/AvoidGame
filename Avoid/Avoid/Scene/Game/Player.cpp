#include "../Game/Player.h"
#include "../Game/GameController.h"
Player::Player()
{
	isDead = false;
	ease.SetEnd(500);
	body.SetCircle(100, 100, 5, Cyan);
}

void Player::Update()
{
	if (!isDead)
	{
		move.InputArrowLR(body.pos.x, 5);
		move.InputFly(body.pos.y, -3);
		ease.SetStart(body.pos.y);
		move.CheckDisp(body.pos, 640, 480, body.r);
	}
	else
	{ 
		body.pos.y = ease.back.In(ease.Time(10), ease.Start(), ease.End(), 10);
	}
}
void Player::Dead()
{
	isDead = true;
}
bool Player::IsDead()
{
	if (isDead)
	{
		return true;
	}
	return false;
}
void Player::Draw()
{
	body.My_DrawCircle();
}