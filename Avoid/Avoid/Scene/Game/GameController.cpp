#include "GameController.h"

int GameController::SCREEN_WIDIH;
int GameController::SCREEN_HEIGHT;
GameController::GameController()
{
	SCREEN_WIDIH = 640;
	SCREEN_HEIGHT = 480;
	score = 0;
	GameOver = false;
};
int GameController::Disp_Widih()
{
	return SCREEN_WIDIH;
}

int GameController::Disp_Height()
{
	return SCREEN_HEIGHT;
}

bool GameController::GameEnd()
{
	if (GameOver)
	{
		return true;
	}
	return false;
}
void GameController::Update()
{
	
	for (unsigned i = 0; i < blocks.bar.size();++i)
	{
		if (collision.CircleAndBox(player.body, blocks.under.hit) ||
			collision.CircleAndBox(player.body, blocks.bar[i].bottomHit) ||
			collision.CircleAndBox(player.body, blocks.bar[i].topHit))
		{
			player.Dead();
		}
	}
	if (!player.IsDead())
	{
		blocks.Update();
	}
	if(player.Update())
	{
		GameOver = true;
	}
	
}

void GameController::Draw()
{
	back.Draw();
	blocks.Draw();
	player.Draw();

}