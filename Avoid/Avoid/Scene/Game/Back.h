#pragma once
#include "../Figure/Figure.h"
#include "../Move/Move.h"
//�w�i�̕`��̂�.�����蔻��͖����B�_�̂ݓ���
class BackGround
{
public:
	struct Sky
	{
		int handle;
		POS pos;
	}sky;
	struct Mountain
	{
		int handle;
		POS pos;
	}mountain;
	struct Cloud
	{
		int handle;
		POS pos;
		Move move;
	}cloud;
	BackGround();
	~BackGround();
	void Updata();
	void Draw();
};