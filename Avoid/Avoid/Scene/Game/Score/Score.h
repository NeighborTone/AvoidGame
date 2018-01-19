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
	void AddScore() { score += 1.f / 60.f; };	//ƒXƒRƒA‚Í•b”
	float GetScore() { return score; }
	bool CheckScore() 
	{
		if (score >= 51.f)
			return true;
		return false;
	};
};