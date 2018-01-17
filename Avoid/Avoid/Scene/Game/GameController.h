#pragma once
#include "../Game/Player.h"
#include "../Collision/Collision.h"
#include "../Scene/Game/Back.h"
#include "UI.h"
#include "Block.h"
//�Q�[���I�u�W�F�N�g�Ǘ�
class GameController
{
private:
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
public:
	UI ui;
	Player player;
	Obstacle obstacle;
	Collision collision;
	BackGround back;
	GameController();
    static  int Disp_Widih();			//��ʃT�C�Y�̏��͏�ɕێ�
	static  int Disp_Height();
	State GameCheck();					//�Q�[���̏�Ԃ��`�F�b�N	
	void GameStart();						//Z�L�[�ŃQ�[�����J�n����
	bool HitCheck();						//��Q���Ƃ̓����蔻��
	bool GameEnd();						//�Q�[���I�[�o�[�Ȃ�Q�[�����I��������
	void Update();
	void Draw();
};