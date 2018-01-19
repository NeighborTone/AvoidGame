#include "DxLib.h"
#include "../Game/Player.h"
#include "../Collision/Collision.h"
#include "../Game/GameController.h"

Player::Player()
{
	animcnt = 0;
	move.SetDir(move.RIGHT);
	angle = MATH::Radian(0);
	isDead = false;
	ease.SetEnd(500);
	body.SetCircle(100, 100, 5, Cyan);
	LoadDivGraphF("./resource/Graph/player.png", 12, 3, 4, 32, 32, handle);
}

bool Player::IsUpdate()
{
	if (!isDead)
	{
		++animcnt;
		if (animcnt >= MAXANIME)
		{
			animcnt = 0;
		}
		move.InputArrowLR(body.pos.x, 5);
		move.InputFly(body.pos.y, -3);
		ease.SetStart(body.pos.y);
		move.CheckDisp(body.pos, GameController::Disp_Widih(), GameController::Disp_Height(), body.r);
	}
	else
	{ 
		body.pos.y = ease.back.In(ease.Time(10), ease.Start(), ease.End(), 10);
		angle += 0.3f;
		if (body.pos.y >= ease.End())
		{
			return true;
		}
	}
	return false;
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
	const float m_pi = 3.14159265358979323846f;
	const int tableR[MAXANIME] = {6,6,6,6,6,6,7,7,7,7,7,7,8,8,8,8,8,8};
	const int tableL[MAXANIME] = { 3,3,3,3,3,3,4,4,4,4,4,4,5,5,5,5,5,5 };
	if(move.dir == move.RIGHT)
	DrawRotaGraphF(body.pos.x, body.pos.y,1,angle, handle[tableR[animcnt]], true);
	if (move.dir == move.LEFT)
	DrawRotaGraphF(body.pos.x, body.pos.y, 1, angle, handle[tableL[animcnt]], true);
}