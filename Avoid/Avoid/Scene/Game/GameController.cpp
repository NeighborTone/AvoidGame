#include "GameController.h"


GameController::GameController()
{
	sound.SetBGM("./resource/Sound/深緑の舞.mp3");
	sound.SetSE("./resource/Sound/ぼよよんソフト.ogg");
	ui.retry.Hide();
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
			sound.PlayOneShotSE(0);
			return true;
		}
	}
	return false;
}
void GameController::Update()
{
	GameStart();
	sound.PlayBGM_Loop(70);
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
			//ここは設計ミス
			if (obstacle.ice.tri.p1.y >= 600)
			{
				obstacle.ice.SetIce(player.GetPos());
			}
			//
		}
		if (player.IsUpdate())
		{
			ui.retry.Show();
			sound.DeleteBGM();
			sound.DeleteSE();
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
GameController::~GameController()
{
	InitGraph();
	InitSoundMem();
}