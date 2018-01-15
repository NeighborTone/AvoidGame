#include "Back.h"

BackGround::BackGround()
{
	sky.handle = LoadGraph("./resource/Graph/Sky.png");
	sky.pos.SetPos(0, 0);
	mountain.handle = LoadGraph("./resource/Graph/Mountain.png");
	mountain.pos.SetPos(0, 150);
}
void BackGround::Updata()
{

}
void BackGround::Draw()
{
	DrawGraphF(sky.pos.x, sky.pos.y, sky.handle, true);
	DrawGraphF(mountain.pos.x, mountain.pos.y, mountain.handle, true);
}
BackGround::~BackGround()
{
	InitGraph();
}