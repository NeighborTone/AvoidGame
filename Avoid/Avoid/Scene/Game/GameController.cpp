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
	
	for (unsigned i = 0; i < obstacle.bar.size();++i)
	{
		const bool isHitUnder = collision.CircleAndBox(player.body, obstacle.under.hit);
		const bool isHitBarbottom = collision.CircleAndBox(player.body, obstacle.bar[i].bottomHit);
		const bool isHitBartop = collision.CircleAndBox(player.body, obstacle.bar[i].topHit);
		const bool isIce = collision.CircleAndTriangle(player.body, obstacle.ice.tri);
		if (isHitUnder || isHitBarbottom || isHitBartop || isIce)
		{
			player.Dead();
		}
	}
	if (!player.IsDead())
	{
		obstacle.Update();
		if(obstacle.ice.tri.p3.y >= 600)
		obstacle.ice.SetIce(player.body.pos);
	}
	if(player.IsUpdate())
	{
		GameOver = true;
	}
	
}

void GameController::Draw()
{
	back.Draw();
	obstacle.Draw();
	player.Draw();

}