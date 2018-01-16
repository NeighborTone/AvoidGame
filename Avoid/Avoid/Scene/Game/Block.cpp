#include "Block.h"
#include "DxLib.h"
#include <random>

void Blocks::Bar::SetBar()
{
	//呼び出されたらランダムな高さで生成
	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<> b_rand(340,440);
	std::uniform_int_distribution<> t_rand(-400, -200);
	bottomHit.SetBox(660.f, float(b_rand(mt)), 30.f, 480.f, Violet);		//0~480の間にランダムで配置
	topHit.SetBox(660.f, float(t_rand(mt)), 30.f, 480.f, Violet);
}

Blocks::Blocks()
{
	under.handle = LoadGraph("./resource/Graph/Under.png");
	under.draw.SetBox(0, 390,640, 90, Blue);
	under.hit.SetBox(0, 390, 640, 90, Blue);
	bar.SetBar();
	bar.speed = -1;
}

void Blocks::Update()
{
	bar.move.L_R_Move(bar.bottomHit.x, bar.speed);
	bar.move.L_R_Move(bar.topHit.x, bar.speed);
	if (bar.bottomHit.x <= -30)
	{
		bar.speed -= 0.05f;
		bar.SetBar();
	}
}

void Blocks::Draw()
{
	under.move.BackScroll(1,under.draw.x,under.draw.y,640, -2.7f, under.handle);
	under.hit.My_DrawBox(false);
	bar.bottomHit.My_DrawBox();
	bar.topHit.My_DrawBox();
}