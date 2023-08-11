#include "Player.cpp"
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <limits>
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

	void playGame()
	{
		string name;
		Player p;

		cout << "Number of players: ";
		cin >> numPlayers;
		while (numPlayers < 0 || numPlayers > 10)
		{
			cout << "Number of players must be between 1 and 10: ";
			cin >> numPlayers;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			system("CLS");
		}
		
		cout << "Enter Date (xx-xx-xxxx): ";
		cin >> date;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << endl;

		for (int i = 0; i < numPlayers; i++)
		{
			cout << "Enter player " << i + 1 << " name: ";
			cin >> name;
			p.setName(name);
			playerList.push_back(p);
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		cout << endl;
		cout << "Enter -1 for any score to end the game\n\n";

		int score = 0;
		int index = 0;

		while (score != -1)
		{
			cout << "How many points did " << playerList[index].getName() << " score? ";
			cin >> score;

			if (score == -1) { break; }

			playerList[index].addScore(score);
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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

public:
	void menu()
	{
		int choice = 0;
		do
		{
			cout << "Option 1: Start New Game\n";
			cout << "Option 2: Quit\n";
			cout << "Choice: ";
			cin >> choice;
			system("CLS");

			if (choice == 1)
			{
				playGame();
				system("CLS");
				break;
			}
			else
				break;

		} while (choice == 1);
	}
};
