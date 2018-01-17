#include "GameController.h"


GameController::GameController()
{
	state = Ready;
};
int GameController::Disp_Widih()
{
	return SCREEN_WIDIH;
}

int GameController::Disp_Height()
{
	return SCREEN_HEIGHT;
}

GameController::State GameController::GameCheck()
{
	return state;
}
void GameController::GameStart()
{
	if (state == Ready && Key(KEY_INPUT_Z) == 1)
	{
		ui.logo.Hide();
		state = Play;
	}
}
bool GameController::GameEnd()
{
	if (state == GameOver)
	{
		return true;
	}
	return false;
}

bool GameController::HitCheck()
{
	for (unsigned i = 0; i < obstacle.bar.size();++i)
	{
		const bool isHitUnder = collision.CircleAndBox(player.body, obstacle.under.hit);
		const bool isHitBarbottom = collision.CircleAndBox(player.body, obstacle.bar[i].bottomHit);
		const bool isHitBartop = collision.CircleAndBox(player.body, obstacle.bar[i].topHit);
		const bool isHitIce = collision.CircleAndTriangle(player.body, obstacle.ice.tri);
		if (isHitUnder || isHitBarbottom || isHitBartop || isHitIce)
		{
			return true;
		}
	}
	return false;
}
void GameController::Update()
{
	GameStart();
	if (GameCheck() == Play)
	{
		for (unsigned i = 0; i < obstacle.bar.size();++i)
		{
			
			if (HitCheck())
			{
				player.Dead();
			}
		}
		if (!player.IsDead())
		{
			obstacle.Update();
			//‚±‚±‚ÍÝŒvƒ~ƒX
			if (obstacle.ice.tri.p1.y >= 600)
				obstacle.ice.SetIce(player.GetPos());
			
		}
		if (player.IsUpdate())
		{
			state = GameOver;
		}
	}
	
	
}

void GameController::Draw()
{
	
	back.Draw();
	obstacle.Draw();
	player.Draw();
	ui.Draw();

}