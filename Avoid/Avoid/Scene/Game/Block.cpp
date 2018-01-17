#include "Block.h"
#include "DxLib.h"
#include <random>

void Obstacle::Bar::SetBar()
{
	//呼び出されたらランダムな高さで配置
	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<> b_rand(240,380);
	std::uniform_int_distribution<> t_rand(-400, -270);
	bottomHit.SetBox(750.f, float(b_rand(mt)), 30.f, 480.f, Violet);		//0~480の間にランダムで配置
	topHit.SetBox(750.f, float(t_rand(mt)), 30.f, 480.f, Violet);
}
void Obstacle::Ice::SetIce(const POS player)
{
	//呼び出されたらプレイヤーの頭上に配置
	tri.p3.x = player.x;
	tri.p3.y = 0;
	tri.p2.x = tri.p3.x + 50;
	tri.p2.y = tri.p3.y - 300;
	tri.p1.x = tri.p3.x - 50;
	tri.p1.y = tri.p3.y - 300;
	tri.color.SetColor(Green);

}
Obstacle::Obstacle()
{
	under.handle = LoadGraph("./resource/Graph/Under.png");
	under.draw.SetBox(0, 390,640, 90, Blue);
	under.hit.SetBox(0, 390, 640, 90, Blue);
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
	//ice.tri.p1.y = ice.ease.quart.In(ice.ease.Time(20), 0, 600, 20);
	//ice.tri.p2.y = ice.ease.quart.In(ice.ease.Time(20), -50, 550, 20);
	//ice.tri.p3.y = ice.ease.quart.In(ice.ease.Time(20), -50, 550, 20);
	ice.tri.p3.y += 5;
	ice.tri.p2.y += 5;
	ice.tri.p1.y += 5;
}

void Obstacle::Draw()
{
	under.move.BackScroll(1,under.draw.x,under.draw.y,640, -2.7f, under.handle);
	ice.tri.My_DrawTriangle();
	for (unsigned i = 0; i < bar.size();++i)
	{
		bar[i].bottomHit.My_DrawBox();
		bar[i].topHit.My_DrawBox();
#if _DEBUG
		DrawFormatString(0, 0, GetColor(0,0,0), "%.2f", bar[0].topHit.x);
		DrawFormatString(0, 15, GetColor(0,0,0), "%.2f", bar[3].topHit.x);
#endif]
	}
}