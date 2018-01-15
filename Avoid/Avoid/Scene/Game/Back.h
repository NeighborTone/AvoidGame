#pragma once
#include "../Figure/Figure.h"
#include "../Move/Move.h"
//”wŒi‚Ì•`‰æ‚Ì‚İ.“–‚½‚è”»’è‚Í–³‚µB‰_‚Ì‚İ“®‚­
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