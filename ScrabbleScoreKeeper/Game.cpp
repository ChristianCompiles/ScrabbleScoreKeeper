#include "Player.cpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

const int CHAR_SIZE = 21;
const int MAX_PLAYERS = 4;

class Game
{
private:
	vector<Player> playerList;
	char date[CHAR_SIZE];
	fstream gamestream;
	int numPlayers;

	void saveGame()
	{
		gamestream.open("games.txt", ios::out | ios::app);
		if (!gamestream)
		{
			cout << "Error Opening File.\n";
			cin.ignore();
			cin.get();
			exit(1);
		}
		else
		{
			gamestream << "Date: " << date << endl;
			for (int i = 0; i < numPlayers; i++)
			{
				gamestream << playerList[i].getName() << ": " << playerList[i].getPlayerScore() << endl;
			}
			gamestream << endl;
		}
		gamestream.close();
		cout << endl;
	}

	void menu()
	{
		int choice = 0;
		while (choice != 2)
		{
			cout << "Option 1: Start New Game\n";
			cout << "Option 2: Quit\n";
			cin >> choice;

			if (choice == 1)
			{
				playGame();
				system("CLS");
				break;
			}
		}
	}

public:
	void playGame()
	{
		string flag = "y";
		string name;
		Player p;

		menu();

		cout << "Number of players: ";
		cin >> numPlayers;
		while (numPlayers < 0 || numPlayers > 10)
		{
			cout << "Number of players must be between 1 and 10: ";
			cin >> numPlayers;
		}

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
			
			if (score == -1){break;}

			playerList[index].addScore(score);

			if (index < (numPlayers - 1))
			{
				index++;
			}
			else
			{
				index = 0;
			}
			system("CLS");
			
		}
		saveGame();
	}
};
