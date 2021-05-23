#include <iostream>
#include <cstdlib>

using namespace std;

class TTT {
private:
	char Board[3][3] = { '1','2','3','4','5','6','7','8','9' };
	char Igrac = 'X';
	int brojPoteza = 0;
public:
	void Play();
	void Draw();
	void Toggle();
	void Input();
	char CheckWin();
};



//iscrt ploce na zaslon
void TTT:: Draw()
{
	system("cls");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << Board[i][j] << " | ";
		}
		cout << endl;
	}
	
}



void TTT::Play()
{	
	Draw();
	while (1)
	{
		brojPoteza++;
		Input();
		Draw();

		if (CheckWin() == 'X')
		{
			cout << "Igrac X je pobjedio!";
			break;
		}
		else if (CheckWin() == 'O')
		{
			cout << "Igrac O je pobjedio!";
			break;
		}
		else if (CheckWin() == '/' && brojPoteza == 9)
		{
			cout << "Nitko nije pobjedio!";
			break;
		}
		Toggle();
	}
}

//izmjena igraca (X u O i obrnuto)
void TTT:: Toggle()
{
	if (Igrac == 'X')
	{
		Igrac = 'O';
	}
	else
	{
		Igrac = 'X';
	}
}

//unos znaka na plocu zamjenjivanjem broja na ploci sa odgovarajucim znakom
void TTT::Input()
{
	int broj;
	cout << "Na redu je " << Igrac << ". " << "Upisite broj za zamjenu broja znakom: ";
	cin >> broj;

	if (broj == 1)
	{
		if (Board[0][0] == '1')
		{
			Board[0][0] = Igrac;
		}
		else
		{
			cout << "Polje se vec koristi!" << endl;
			brojPoteza--;
		}
	}
	else if (broj == 2)
	{
		if (Board[0][1] == '2')
		{
			Board[0][1] = Igrac;
		}
		else
		{
			cout << "Polje se vec koristi!" << endl;
			brojPoteza--;
		}
	}
	else if (broj == 3)
	{
		if (Board[0][2] == '3')
		{
			Board[0][2] = Igrac;
		}
		else
		{
			cout << "Polje se vec koristi!" << endl;
			brojPoteza--;
		}
	}
	else if (broj == 4)
	{
		if (Board[1][0] == '4')
		{
			Board[1][0] = Igrac;
		}
		else
		{
			cout << "Polje se vec koristi!" << endl;
			brojPoteza--;
		}
	}
	else if (broj == 5)
	{
		if (Board[1][1] == '5')
		{
			Board[1][1] = Igrac;
		}
		else
		{
			cout << "Polje se vec koristi!" << endl;
			brojPoteza--;
		}
	}
	else if (broj == 6)
	{
		if (Board[1][2] == '6')
		{
			Board[1][2] = Igrac;
		}
		else
		{
			cout << "Polje se vec koristi!" << endl;
			brojPoteza--;
		}
	}
	else if (broj == 7)
	{
		if (Board[2][0] == '7')
		{
			Board[2][0] = Igrac;
		}
		else
		{
			cout << "Polje se vec koristi!" << endl;
			brojPoteza--;
		}
	}
	else if (broj == 8)
	{
		if (Board[2][1] == '8')
		{
			Board[2][1] = Igrac;
		}
		else
		{
			cout << "Polje se vec koristi!" << endl;
			brojPoteza--;
		}
	}
	else if (broj == 9)
	{
		if (Board[2][2] == '9')
		{
			Board[2][2] = Igrac;
		}
		else
		{
			cout << "Polje se vec koristi!" << endl;
			brojPoteza--;
		}
	}
}

char TTT::CheckWin()
{
	//provjera za pobjedu u horizontalama x
	if (Board[0][0] == 'X' && Board[0][1] == 'X' && Board[0][2] == 'X')
	{
		return 'X';
	}
	if (Board[1][0] == 'X' && Board[1][1] == 'X' && Board[1][2] == 'X')
	{
		return 'X';
	}
	if (Board[2][0] == 'X' && Board[2][1] == 'X' && Board[2][2] == 'X')
	{
		return 'X';
	}

	//provjera vertikali x
	if (Board[0][0] == 'X' && Board[1][0] == 'X' && Board[2][0] == 'X')
	{
		return 'X';
	}
	if (Board[0][1] == 'X' && Board[1][1] == 'X' && Board[2][1] == 'X')
	{
		return 'X';
	}
	if (Board[0][2] == 'X' && Board[1][2] == 'X' && Board[2][2] == 'X')
	{
		return 'X';
	}
	//provjera dijagonali x
	if (Board[0][0] == 'X' && Board[1][1] == 'X' && Board[2][2] == 'X')
	{
		return 'X';
	}
	if (Board[0][2] == 'X' && Board[1][1] == 'X' && Board[2][0] == 'X')
	{
		return 'X';
	}

	//provjera za pobjedu u horizontalama O
	if (Board[0][0] == 'O' && Board[0][1] == 'O' && Board[0][2] == 'O')
	{
		return 'O';
	}
	if (Board[1][0] == 'O' && Board[1][1] == 'O' && Board[1][2] == 'O')
	{
		return 'O';
	}
	if (Board[2][0] == 'O' && Board[2][1] == 'O' && Board[2][2] == 'O')
	{
		return 'O';
	}

	//provjera vertikali O
	if (Board[0][0] == 'O' && Board[1][0] == 'O' && Board[2][0] == 'O')
	{
		return 'O';
	}
	if (Board[0][1] == 'O' && Board[1][1] == 'O' && Board[2][1] == 'O')
	{
		return 'O';
	}
	if (Board[0][2] == 'O' && Board[1][2] == 'O' && Board[2][2] == 'O')
	{
		return 'O';
	}
	//provjera dijagonali O
	if (Board[0][0] == 'O' && Board[1][1] == 'O' && Board[2][2] == 'O')
	{
		return 'O';
	}
	if (Board[0][2] == 'O' && Board[1][1] == 'O' && Board[2][0] == 'O')
	{
		return 'O';
	}
	return '/';
}

int main()
{
	TTT Game;

	Game.Play();
}