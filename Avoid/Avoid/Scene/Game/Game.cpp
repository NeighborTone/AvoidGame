#include "Game.h"
#include "../Input/Input.h"
#include "../Scene/SceneManager.h"
#include "DxLib.h"
bool Game::Initialize()
{

	return true;
}

void Game::Update()
{
	if (controller.IsUpdate() && Key(KEY_INPUT_Z) == 1)
	{
		SceneManeger::GetInstance()->ChangeScene(new Game);
	}

}

void Game::Draw()
{
	controller.Draw();
}

void Game::Finalize()
{
	
}