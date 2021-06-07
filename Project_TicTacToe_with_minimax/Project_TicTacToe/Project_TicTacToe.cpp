#include <iostream>
#include <iomanip>
#include <algorithm>
#include <limits>

using namespace std;

class Game
{
    enum class Player
    {
        none = '-',
        human = 'X',
        computer = 'O'
    };

    struct Move
    {
        unsigned int x = 0;
        unsigned int y = 0;
    };

    Player board[3][3];

public:
    Game()
    {
        for (unsigned int i = 0; i < 3; i++)
        {
            for (unsigned int j = 0; j < 3; j++)
            {
                board[i][j] = Player::none;
            }
        }
    }

    void printBoard()
    {
        cout << "+-----------------+";
        for (unsigned int i = 0; i < 3; i++)
        {
            cout << "\n|";
            for (unsigned int j = 0; j < 3; j++)
            {
                cout << setw(3) << static_cast<char>(board[i][j]) << setw(3) << " |";
            }
        }
        cout << "\n+-----------------+\n";
    }

    bool isTie()
    {
        for (unsigned int i = 0; i < 3; i++)
        {
            if (board[i][0] == Player::none || board[i][1] == Player::none || board[i][2] == Player::none)
                return false;
        }
        return true;
    }

    bool checkWin(Player player)
    {
        for (unsigned int i = 0; i < 3; i++)
        {
            // Horizontale
            if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
                return true;

            // Vertikale
            if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
                return true;
        }

        // Dijagonale
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
            return true;

        if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
            return true;

        return false;
    }

    Move minimax()
    {
        int rez = numeric_limits<int>::max();
        Move move;

        for (unsigned int i = 0; i < 3; i++)
        {
            for (unsigned int j = 0; j < 3; j++)
            {
                if (board[i][j] == Player::none)
                {
                    board[i][j] = Player::computer;

                    int temp = maxSearch();

                    if (temp < rez)
                    {
                        rez = temp;
                        move.x = i;
                        move.y = j;
                    }
                    board[i][j] = Player::none;
                }
            }
        }
        return move;
    }

    int maxSearch()
    {
        if (checkWin(Player::human)) { return 10; }
        else if (checkWin(Player::computer)) { return -10; }
        else if (isTie()) { return 0; }

        int score = numeric_limits<int>::min();

        for (unsigned int i = 0; i < 3; i++)
        {
            for (unsigned int j = 0; j < 3; j++)
            {
                if (board[i][j] == Player::none)
                {
                    board[i][j] = Player::human;
                    score = max(score, minSearch());
                    board[i][j] = Player::none;
                }
            }
        }

        return score;
    }

    int minSearch()
    {
        if (checkWin(Player::human)) { return 10; }
        else if (checkWin(Player::computer)) { return -10; }
        else if (isTie()) { return 0; }

        int score = numeric_limits<int>::max();

        for (unsigned int i = 0; i < 3; i++)
        {
            for (unsigned int j = 0; j < 3; j++)
            {
                if (board[i][j] == Player::none)
                {
                    board[i][j] = Player::computer;
                    score = min(score, maxSearch());
                    board[i][j] = Player::none;
                }
            }
        }

        return score;
    }

    void getHumanMove()
    {
        bool fail = true;
        unsigned int x = -1, y = -1;

        do
        {
            cout << "Vas potez: ";

            char c;
            cin >> c;
            x = c - '0';
            cin >> c;
            y = c - '0';

            fail = board[x][y] != Player::none;

            cin.clear();
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');

        } while (fail);

        board[x][y] = Player::human;
    }

    void play()
    {
        unsigned int turn = 0;
        bool exit = false;

        printBoard();
        cout << "Unesite potez preko koordinata: (npr. 02) " << endl;
        do
        {
            // red na covjeku
            if (turn == 0)
            {
                getHumanMove();

                if (checkWin(Player::human))
                {
                    cout << "Covjek je pobjedio\n";
                    exit = true;
                }
            }
            else // red na kompjuteru
            {
                cout << "\nKompjuter je na redu: ";

                Move aimove = minimax();
                cout << aimove.x << aimove.y << "\n";
                board[aimove.x][aimove.y] = Player::computer;

                if (checkWin(Player::computer))
                {
                    cout << "Kompjuter je pobjedio" << endl;
                    exit = true;
                }
            }

            if (isTie())
            {
                cout << "\n*** Nerijeseno ***\n";
                exit = true;
            }

            turn ^= 1;
            printBoard();

        } while (!exit);
    }
};

int main()
{
    Game tictactoe;
    tictactoe.play();
}