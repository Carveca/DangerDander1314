// ScoreManager.h

#include <fstream>
#include <ostream>
#include <string>

class ScoreManager
{
public:

	ScoreManager();
	~ScoreManager();

	void setScore(int value);
	void setHighscore(int value);
		
	int getScore();
	int getHighscore();
	
private:

	std::fstream stream;	
	std::ofstream myfile;

	std::string score_name;
	std::string high_score_name;

	int score;
	int highscore;
};