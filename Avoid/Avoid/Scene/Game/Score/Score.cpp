#include "Score.h"
#include "DxLib.h"
#include <fstream>
Score::Score()
{

	if (AddFontResourceEx("./resource/Font/AMEMUCHIGOTHICMONO-04.ttf", FR_PRIVATE, NULL) == 0)
	{
		printfDx("AddFontResourceEx���s\n");
	}
	hFont = CreateFontToHandle("���ڃS�V�b�N����-04", 20, -1, DX_FONTTYPE_ANTIALIASING_8X8);
	if (hFont == 0) 
	{
		printfDx("CreateFontToHandle���s\n");
	}
	LoadHighScore();
	score = 0;
}
void Score::ResetHighScore()
{
	if (highscore != 0)
	{
		highscore = 0;
	}
}
void Score::SaveHighScore()
{
	if (score > highscore)
	{
		std::ofstream ofs("./resource/Save/�n�C�X�R�A.dat");
		ofs << score;
		ofs.close();
	}
}
void Score::LoadHighScore()
{
	std::ifstream ifs("./resource/Save/�n�C�X�R�A.dat");
	ifs >> highscore;
}

void Score::Draw()
{
	
	DrawFormatStringToHandle(0, 0, GetColor(20, 140, 220), hFont,"Score:%.0f", GetScore());
	DrawFormatStringToHandle(0, 20, GetColor(20, 140, 220), hFont,"HighScore:%.0f", GetHighScore());
}
