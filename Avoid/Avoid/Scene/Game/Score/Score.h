class Score
{
private:
	float score;
	float highscore;
	int hFont;
public:
	Score();
	void LoadHighScore();
	void ResetHighScore();
	void SaveHighScore();
	float GetHighScore() { return highscore; };
	void  AddScore() { score += 1.f / 60.f; };		//ƒXƒRƒA‚Í•b”
	float GetScore() { return score; }
	bool CheckScore() 
	{
		if (score >= 51.f)
			return true;
		return false;
	};
	void Draw();
};