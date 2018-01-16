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
	void Update();	//�X�V�B��Ɉړ��n
	void Draw();		//�`��
};