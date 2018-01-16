#include "Back.h"

BackGround::BackGround()
{
	sky.handle = LoadGraph("./resource/Graph/Sky.png");
	sky.pos.SetPos(0, 0);
	mountain.handle = LoadGraph("./resource/Graph/Mountain.png");
	mountain.pos.SetPos(0, 220);
	cloud.handle = LoadGraph("./resource/Graph/cloud.png");
	cloud.pos.SetPos(0, 0);
}
void BackGround::Draw()
{

	DrawGraphF(sky.pos.x, sky.pos.y, sky.handle, true);
	cloud.move.BackScroll(1, cloud.pos, 640, -1.7f, cloud.handle);
	DrawGraphF(mountain.pos.x, mountain.pos.y, mountain.handle, true);
	
}
BackGround::~BackGround()
{
	InitGraph();
}