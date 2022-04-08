#include<iostream>
#include<ctime>
using namespace std;

const int Rows = 8;
const int Columns = 8;
int Board[Rows][Columns];
int Ships = 5;
int r, c;
int AIrg, AIcg;
bool Hit;

void ClearBoard()
{
	for (int r = 0; r < Rows; r++)
	{
		for (int c = 0; c < Columns; c++)
		{
			Board[r][c] = 0;
		}
	}
}

void SetShipPosition(int r, int c)
{
	Board[r][c] = 1;
}

void SetAllPositions()
{
	cout << "To place a ship, type a number from 0 to 7, tap the spacebar, and then type another number from 0 to 7. Do not use the same coordinates twice. ";
	
	for (int p = 0; p < Ships; p++)
	{
		cout << "Where would you like to place your ship?";
		cin >> r >> c;
		SetShipPosition(r, c);
	}
}

void RandomizeGuess()
{
	AIrg = rand() % Rows;
	AIcg = rand() % Columns;
}

bool NPCGuess(int r, int c)
{
	while (Ships != 0)
	{
		if (Board[r][c] == 1)
		{
			Ships--;
			cout << "Your ship was HIT. ";
			Board[r][c] == 0;
			return true;
		}
		else
		{
			cout << "They MISSED. ";
			return false;
		}
	}
}

void CheckSurroundings()
{
	if(Board[AIrg][AIcg] == 0)
	{
		if (Board[AIrg - 1][AIcg] == 1 || Board[AIrg + 1][AIcg] == 1)
		{
			cout << "But they were close. ";
		}
		if (Board[AIrg][AIcg - 1] == 1 || Board[AIrg][AIcg + 1] == 1)
		{
			cout << "But they were close. ";
		}
		if (Board[AIrg - 1][AIcg - 1] == 1 || Board[AIrg - 1][AIcg + 1] == 1)
		{
			cout << "But they were close. ";
		}
		if (Board[AIrg + 1][AIcg - 1] == 1 || Board[AIrg + 1][AIcg + 1] == 1)
		{
			cout << "But they were close. ";
		}
	}
}

void NewGame()
{
	ClearBoard();
	SetAllPositions();
}

void OverallTurn()
{
	RandomizeGuess();
	NPCGuess(AIrg, AIcg);
	CheckSurroundings();
	system("pause");
}

int main()
{
	srand(time(NULL));
	NewGame();
	while (Ships > 0)
	{
		OverallTurn();
	}
	cout << "All of your ships have been HIT. ";
	return 0;
}