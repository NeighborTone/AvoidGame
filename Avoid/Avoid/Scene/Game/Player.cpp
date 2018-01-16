#include "../Game/Player.h"
#include "../Game/GameController.h"
Player::Player()
{
	isDead = false;
	body.SetCircle(static_cast<float>(GameController::Disp_Widih() / 2), static_cast<float>(GameController::Disp_Widih() / 2), 5, Cyan);
}

void Player::Update()
{
	if (!isDead)
	{
		move.InputArrowLR(body.pos.x, 5);
		move.InputFly(body.pos.y, -5);
	}
	else
	{ 
		float tempy = body.pos.y;
		body.pos.y = ease.quart.In(ease.Time(14), tempy, 500, 14);
	}
}
void Player::Dead()
{
	isDead = true;
}
void Player::Draw()
{
	body.My_DrawCircle();
}