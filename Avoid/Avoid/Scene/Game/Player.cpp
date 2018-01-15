#include "../Game/Player.h"
#include "../Game/GameController.h"
Player::Player()
{
	isDead = false;
	body.SetCircle(static_cast<float>(GameController::Disp_Widih() / 2), static_cast<float>(GameController::Disp_Widih() / 2), 5, Violet);
}

void Player::Updata()
{
	move.InputArrowLR(body.pos.x, 5);
	move.InputFly(body.pos.y, -5);
}

void Player::Draw()
{
	body.My_DrawCircle();
}