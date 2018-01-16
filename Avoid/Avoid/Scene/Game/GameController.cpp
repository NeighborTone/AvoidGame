#include "GameController.h"

int GameController::SCREEN_WIDIH;
int GameController::SCREEN_HEIGHT;
GameController::GameController()
{
	SCREEN_WIDIH = 640;
	SCREEN_HEIGHT = 480;
	score = 0;
};
int GameController::Disp_Widih()
{
	return SCREEN_WIDIH;
}

int GameController::Disp_Height()
{
	return SCREEN_HEIGHT;
}


void GameController::Update()
{
	blocks.Update();
	player.Update();
	if (collision.CircleAndBox(player.body, blocks.under.hit) ||
		collision.CircleAndBox(player.body,blocks.bar.bottomHit) ||
		collision.CircleAndBox(player.body, blocks.bar.topHit))
	{
		player.Dead();
	}
}

void GameController::Draw()
{
	back.Draw();
	blocks.Draw();
	player.Draw();

}