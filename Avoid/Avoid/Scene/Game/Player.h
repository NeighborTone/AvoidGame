#pragma once
#include "../Figure/Figure.h"
#include "../Move/Move.h"
#include "../Easing/easing.hpp"
class Player
{
private:
	bool isDead;
public:
	Circle body;
	Move move;
	Easing ease;
	Player();			//������
	~Player() {};		//�������
	void Dead();		//Player���E��
	bool IsDead();		//�v���C���[�̏�ԃ`�F�b�N
	bool Update();		//�X�V�B��Ɉړ��n
	void Draw();		//�`��
};