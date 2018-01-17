#include "UI.h"
UI::UI()
{
	logo.handle = LoadGraph("./resource/Graph/push.png");
	logo.pos.SetPos(230,480/2);
	
}
UI::Titlelogo::Titlelogo()
{
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
void UI::Draw()
{
	if (!logo.OnOff())
	{
		DrawGraphF(logo.pos.x, logo.pos.y, logo.handle, true);
	}
	
}