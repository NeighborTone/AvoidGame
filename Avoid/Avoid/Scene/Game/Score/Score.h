class Score
{
private:
	float score;
	float highscore;
	void SaveScore();
public:
	Score();
	float LoadScore();
	float GetHighScore();
	void AddScore() { score += 1.f / 60.f; };	//スコアは秒数
	float GetScore() { return score; }
	bool CheckScore() 
	{
		if (score >= 51.f)
			return true;
		return false;
	};
};