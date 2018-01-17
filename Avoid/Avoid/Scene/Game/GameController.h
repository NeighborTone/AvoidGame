#pragma once
#include "../Game/Player.h"
#include "../Collision/Collision.h"
#include "../Scene/Game/Back.h"
#include "Block.h"
//�Q�[���I�u�W�F�N�g�Ǘ�
class GameController
{
private:
	static int SCREEN_WIDIH,		//�Q�[���̏��͏�ɕێ�����
				 SCREEN_HEIGHT;
	int score;
	bool GameOver;
public:
	Player player;
	Obstacle obstacle;
	Collision collision;
	BackGround back;
	GameController();
    static  int Disp_Widih();
	static  int Disp_Height();
	void AddScore(int score) { this->score += score; };
	int  GetScore() { return score; };
	bool GameEnd();		//�Q�[���I�[�o�[���`�F�b�N
	void Update();
	void Draw();
};