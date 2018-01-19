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
		std::ofstream("ハイスコア.txt");
	}
}
float Score::LoadScore()
{
	FILE *fs = fopen("ハイスコア","r");
	return 0;
}

float Score::GetHighScore()
{
	return highscore;
}