#include <iostream>
#include <fstream>
using namespace std;

class Player
{
private:
	char date[30];
	int score[10] = { -1 };
	int scoreIndex = 0;


public:

	void addScore(int s)
	{
		score[scoreIndex] = s;
		scoreIndex++;
	}

	int returnScore()
	{
		int total = 0;

		for (int i = 0; i < 10; i++)
		{
			if (score[i] == -1)
			{
				return total;
			}
			else
				total += score[i];
		}
		return total;
	}
};

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

int main()
{
	Player Ani, Dad, Christian;
	
	Ani.addScore(5);
	Ani.addScore(20);
	
	cout << Ani.returnScore();



	return 0;
}