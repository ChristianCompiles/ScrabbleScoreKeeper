#include "Player.cpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

const int CHAR_SIZE = 21;
const int MAX_PLAYERS = 4;

class Scrabble
{
private:
	vector<Player> playerList;
	char date[CHAR_SIZE];
	fstream gamestream;

public:

	void playGame()
	{
		string flag = "y";
		int numPlayers = 0;
		Player p;
		string name;

		cout << "Number of players: ";
		cin >> numPlayers;

		cout << "Enter Date (xx-xx-xxxx): ";
		cin >> date;
		cout << endl;

		for (int i = 0; i < numPlayers; i++)
		{
			cout << "Enter player " << i + 1 << " name: ";
			cin >> name;
			p.setName(name);
			playerList.push_back(p);
		}

		cout << "\nEnter -1 for any score when the game ends\n";

		int score = 0;
		int index = 0;

		while (score != -1)
		{
			cout << "How many points did " << playerList[index].getName() << " score? ";
			cin >> score;
			playerList[index].addScore(score);

			if (index < (numPlayers-1))
			{
				index++;
			}
			else
			{
				index = 0;
			}
		}

		system("CLS");
	}

	// Comparison function for sorting Player instances based on their score value
	bool compareMyObjects(Player &obj1, Player &obj2) 
	{
		return obj1.getPlayerScore() < obj2.getPlayerScore();
	}

	void displayWinners()
	{
		std::sort(playerList.begin(), playerList.end(), compareMyObjects);
	}


	//

	void displayWinners()
	{
		std::sort(playerList.begin(), playerList.end(), [](const Player& player1, const Player& player2) {
			return player1.getPlayerScore() < player2.getPlayerScore();
			});

	}



	void addGameToFile()
	{
		gamestream.open("games.dat", ios::out | ios::app | ios::binary);
		if (!gamestream)
		{
			cout << "Error Opening File.\n";
			cin.ignore();
			cin.get();
			exit(1);
		}
		else
		{
			gamestream.write(reinterpret_cast<char*>(&playerList), sizeof(playerList.size()));
			gamestream.write(reinterpret_cast<char*>(&date), sizeof(date[CHAR_SIZE]));
		} 
		gamestream.close();
		cout << endl;
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