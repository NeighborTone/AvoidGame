#include "Block.h"
#include "DxLib.h"
#include <random>

Obstacle::Under::Under()
{
	handle = LoadGraph("./resource/Graph/Under.png");
	draw.SetBox(0, 390, 640, 90, Blue);
	hit.SetBox(0, 390, 640, 90, Blue);
}
Obstacle::Bar::Bar()
{
	handle = LoadGraph("./resource/Graph/Bar2.png");
}
Obstacle::Ice::Ice()
{
	isDraw = false;
	handle = LoadGraph("./resource/Graph/Ice.png");
}
void Obstacle::Bar::SetBar()
{
	//呼び出されたらランダムな高さで配置
	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<> b_rand(240,380);
	std::uniform_int_distribution<> t_rand(-400, -270);
	bottomHit.SetBox(750.f, float(b_rand(mt)), 32.f, 478.f, Violet);		//0~480の間にランダムで配置
	topHit.SetBox(750.f, float(t_rand(mt)), 32.f, 478.f, Violet);
}
void Obstacle::Ice::SetIce(const POS player)
{
	//呼び出されたらプレイヤーの頭上に配置
	tri.p3.x = player.x;
	tri.p3.y = 0;
	tri.p2.x = tri.p3.x + 20;
	tri.p2.y = tri.p3.y - 270;
	tri.p1.x = tri.p3.x - 50;
	tri.p1.y = tri.p3.y - 270;
	fallspeed = 0;
	isDraw = true;
	tri.color.SetColor(Green);
}
void Obstacle::Ice::MoveIce()
{
	fallspeed += 0.1567f;
	tri.p3.y += fallspeed;
	tri.p2.y += fallspeed;
	tri.p1.y += fallspeed;
}
Obstacle::Obstacle()
{
	
	for (unsigned i = 0; i < bar.size();++i)
	{
		bar[i].SetBar();
		bar[i].bottomHit.x += i * interval;
		bar[i].topHit.x += i * interval;
		bar[i].speed = -3;
	}
	
}

void Obstacle::Update()
{
	for (unsigned i = 0; i < bar.size();++i)
	{
		bar[i].move.L_R_Move(bar[i].bottomHit.x, bar[i].speed);
		bar[i].move.L_R_Move(bar[i].topHit.x, bar[i].speed);
		if (bar[i].bottomHit.x <= -interval)
		{
			bar[i].SetBar();
		}
	}
	ice.MoveIce();
}

void Obstacle::Draw()
{
	for (unsigned i = 0; i < bar.size();++i)
	{
		DrawGraphF(bar[i].bottomHit.x, bar[i].bottomHit.y, bar[i].handle, true);
		DrawGraphF(bar[i].topHit.x, bar[i].topHit.y, bar[i].handle, true);
	}
	if (ice.isDraw)
	{
		DrawGraphF(ice.tri.p1.x, ice.tri.p1.y, ice.handle, true);
	}
	under.move.BackScroll(1, under.draw.x, under.draw.y, 640, -2.7f, under.handle);
}