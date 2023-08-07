#pragma once
#include <string>
using namespace std;

const int MAX_SCORES = 20;
class Player
{
private:
	string name;
	int score_list[MAX_SCORES] = { -1 };
	int scoreIndex = 0;
	int player_total;

public:

	void setName(string n)
	{
		name = n;
	}

	string getName()
	{
		return name;
	}

	void addScore(int s)
	{
		score_list[scoreIndex] = s;
		scoreIndex++;
		player_total += s;
	}

	int getPlayerScore()
	{
		return player_total;
	}
};