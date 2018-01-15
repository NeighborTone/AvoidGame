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


void GameController::Updata()
{
	back.Updata();
	player.Updata();
}

void GameController::Draw()
{
	back.Draw();
	player.Draw();

}