#include "UI.h"
UI::UI()
{

}
UI::Titlelogo::Titlelogo()
{
	handle = LoadGraph("./resource/Graph/push.png");
	pos.SetPos(230, 480 / 2);
	flag = false;
}
void UI::Titlelogo::Hide()
{
	flag = true;
}
void UI::Titlelogo::Show()
{
	flag = false;
}
bool UI::Titlelogo::OnOff()
{
	return flag;
}
UI::Retry::Retry()
{
	handle = LoadGraph("./resource/Graph/Retry.png");
	pos.SetPos(230, 480 / 2);
	flag = false;
}
void UI::Retry::Hide()
{
	flag = true;
}
void UI::Retry::Show()
{
	flag = false;
}
bool UI::Retry::OnOff()
{
	return flag;
}
void UI::Draw()
{
	if (!logo.OnOff())
	{
		DrawGraphF(logo.pos.x, logo.pos.y, logo.handle, true);
	}
	if (!retry.OnOff())
	{
		DrawGraphF(retry.pos.x, retry.pos.y, retry.handle, true);
	}
}
UI::~UI()
{
	InitGraph();
}