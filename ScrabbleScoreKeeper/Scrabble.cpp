#include "Player.cpp"
#include <vector>;
#include <iostream>
using namespace std;

const int CHAR_SIZE = 21;

class Scrabble
{
private:
	Player* playersArray;
	char date[CHAR_SIZE];

public:

	void playGame()
	{
		string flag = "y";
		int numPlayers = 0;
		Player p;
		string name;

		cout << "Number of players: ";
		cin >> numPlayers;

		playersArray = new Player[numPlayers];

		for (int i = 0; i < numPlayers; i++)
		{
			cout << "Enter player " << i << "name: ";
			cin >> name;
			p.setName(name);
			playersArray[i] = p;
		}

		cout << "Enter -1 for any score when the game ends\n";

		int score = 0;
		int index = 0;

		while (score != -1)
		{
			cout << "How many points did " << playersArray[index].getName() << "score? ";
			cin >> score;
			playersArray[index].addScore(score);

			if (index < 2)
			{
				index++;
			}
			else
			{
				index = 0;
			}




		}
	}

	void menu()
	{
		int choice = 0;

		while (choice != 0)
		{
			cout << "Option 1: Start New Game\n";
			cout << "Option 2: View Previous Games\n";
		}

		while (choice != 3)
		{
			cout << "Option 1: Add Score\n";
			cout << "Option 2: Edit Score\n";
			cout << "Option 3: End Game\n";
			cin >> choice;

		}
	}
	

};