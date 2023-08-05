#pragma once
#include <string>
using namespace std;

class Player
{
private:
	string name;
	int score_list[10] = { -1 };
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
	}

	int calculate_score()
	{
		int sum = 0;

		for (int i = 0; i < 10; i++)
		{
			if (score_list[i] == -1)
			{
				break;
			}
			else
				sum += score_list[i];
		}
	}
};