#pragma once
#include "../Figure/Figure.h"
#include "../Move/Move.h"
#include "../Easing/easing.hpp"
class Player
{
private:
	enum{MAXANIME=18};
	float angle;
	int animcnt;
	bool isDead;
	int handle[12];
public:
	Circle body;
	Move move;
	Easing ease;
	Player();				//������
	~Player() {};			//�������
	void Dead();			//Player���E��
	POS GetPos() { return body.pos; }
	bool IsDead();		//�v���C���[�̏�ԃ`�F�b�N
	bool IsUpdate();		//�X�V�B��Ɉړ��n
	void Draw();			//�`��
};