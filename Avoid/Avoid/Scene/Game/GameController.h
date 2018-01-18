#pragma once
#include "../Game/Player.h"
#include "../Collision/Collision.h"
#include "../Scene/Game/Back.h"
#include "../MyDxSound/My_DxSound.h"
#include "UI.h"
#include "Block.h"
//�Q�[���I�u�W�F�N�g�Ǘ�
class GameController
{
private:
	float score;
	enum
	{
		SCREEN_WIDIH = 640,		
		SCREEN_HEIGHT = 480,
	};
	enum State
	{
		Ready,
		Play,
		GameOver,
	}state;
	Sound sound;
	UI ui;
	Player player;
	Obstacle obstacle;
	Collision collision;
	BackGround back;
	State GameCheck();					//�Q�[���̏�Ԃ��`�F�b�N	
	void GameStart();						//Z�L�[�ŃQ�[�����J�n����
	bool HitCheck();						//��Q���Ƃ̓����蔻��
	void AddScore() { score += 1.f / 60.f; };	//�X�R�A�͕b��
	bool CheckScore() {
		if (score >= 51.f)
			return true;
		return false;
	};
public:
	GameController();
	~GameController();
    static  int Disp_Widih();			
	static  int Disp_Height();
	bool IsUpdate();
	void Draw();
};