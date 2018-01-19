#include "GameController.h"

GameController::GameController()
{
	sound.SetBGM("./resource/Sound/深緑の舞.mp3");
	sound.SetSE("./resource/Sound/ぼよよんソフト.ogg");
	sound.SetSE("./resource/Sound/ice01_long.ogg");
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
	if (state == Ready && 
		Key(KEY_INPUT_R) >= 1 &&
		Key(KEY_INPUT_E) == 1)
	{
		score.ResetHighScore();
	}
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
bool GameController::IsUpdate()
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
			//ここは設計ミス。実際はobstacle.Update()内で行うようにする
			const bool icePosCheak = obstacle.ice.tri.p1.y >= 600;
			if (icePosCheak && score.CheckScore())
			{
				obstacle.ice.SetIce(player.GetPos());
				sound.PlaySE(1,70);
			}
			//
			score.AddScore();
		}
		if (player.IsUpdate())
		{
			score.SaveHighScore();
			ui.retry.Show();
			sound.DeleteBGM();
			sound.DeleteSE();
			state = GameOver;
		}
	}
	if (state == GameOver)
	{
		return true;
	}
	return false;
}

void GameController::Draw()
{
	back.Draw();
	obstacle.Draw();
	player.Draw();
	ui.Draw();
	score.Draw();
}
GameController::~GameController()
{
	InitGraph();
	InitSoundMem();
}