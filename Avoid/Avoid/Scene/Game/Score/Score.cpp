#include "Score.h"
#include <fstream>
Score::Score()
{
	highscore = 0;
	score = 0;
}
void Score::SaveScore()
{
	if (score > highscore)
	{
		std::ofstream("�n�C�X�R�A.txt");
	}
}
float Score::LoadScore()
{
	FILE *fs = fopen("�n�C�X�R�A","r");
	return 0;
}

float Score::GetHighScore()
{
	return highscore;
}