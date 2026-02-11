#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
const int Size = 5;
void showinstructions() {
    cout << endl << "************* Bingo Game Instructions ***************" << endl;
    cout << " This is a 2 player Bingo Game." << endl;
    cout << " Each player enters a 5x5 board (1 to 25)numbers." << endl;
    cout << " Players take turns calling a number." << endl;
    cout << " The called number is marked as X on both boards if found." << endl << endl;
    cout << " Lines:" << endl;
    cout << " A line is complete when all 5 spots become X." << endl;
    cout << " There are 12 lines: 5 horizontal, 5 vertical, 2 diagonal" << endl << endl;
    cout << " Win rule: \n which player complete 5 lines wins." << endl;
    cout << "*************************************************************" << endl << endl;
}

void printboard(int board[5][5],bool mark[5][5],string name)
{
    cout << endl << name << " board:" << endl;
    for (int i = 0; i < Size; i++)
     {
        for (int j = 0; j < Size; j++)
            {
            if (mark[i][j])
                cout << setw(3) << "X";
            else
                cout << setw(3) << board[i][j];
            }
        cout << endl;
     }
}

void marknumber(int board[5][5], bool mark[5][5], int num) {
    for (int i = 0; i < Size; i++)
       {
            for (int j = 0; j < Size; j++)
           {
                if (board[i][j] == num)
               {
                    mark[i][j] = true;
               }
           }
       }
}
int countlines(bool mark[5][5])
{
    int lines = 0;

    //Count Rows
    for (int i = 0; i < 5; i++)
        {
        bool fullRow = true;
        for (int j = 0; j < 5; j++)
         {
            if (mark[i][j] == false)
            {
                fullRow = false;
            }
        }
        if (fullRow)
            {
            lines++;
            }
    }

    // Count Columns
    for (int j = 0; j < 5; j++)
    {
        bool fullColumn = true;
        for (int i = 0; i < 5; i++)
        {
            if (mark[i][j] == false)
            {
                fullColumn = false;
            }
        }
        if (fullColumn)
        {
            lines++;
        }
    }

    //Count Diagonal 1 (top to left and  bottom to right)
    bool diagonal1 = true;
    for (int i = 0; i < 5; i++)
     {
        if (mark[i][i] == false)
            {
            diagonal1 = false;
            }
     }
    if (diagonal1)
        {
        lines++;
        }

    //Count Diagonal 2 (top to right and  bottom to left)
    bool diagonal2 = true;
    for (int i = 0; i < 5; i++)
    {
        if (mark[i][4 - i] == false)
        {
            diagonal2 = false;
        }
    }
    if (diagonal2)
    {
        lines++;
    }

    return lines;
}

// main function
int main()
{

    showinstructions();

    int player1[5][5], player2[5][5];
    bool m1[5][5] = {false};
    bool m2[5][5] = {false};

    cout << "Player 1 Enter your 5x5 numbers(1 to 25):" << endl;
    for (int i = 0; i < Size; i++)
        for (int j = 0; j < Size; j++)
            cin >> player1[i][j];

    printboard(player1, m1, "Player 1");

    cout << endl << "Player 2 Enter your 5x5 numbers(1 to 25):" << endl;
    for (int i = 0; i < Size; i++)
        for (int j = 0; j < Size; j++)
            cin >> player2[i][j];

    printboard(player2, m2, "Player 2");

    cout << endl << "*******Game start(make 5 lines to win)!********" << endl;

    while(true)
        {
        int num;
        cout << endl << "Call a number alternatively : ";
        cin >> num;

        marknumber(player1, m1, num);
        marknumber(player2, m2, num);

        printboard(player1, m1, "Player 1");
        printboard(player2, m2, "Player 2");

        int linesplayer1 = countlines(m1);
        int linesplayer2 = countlines(m2);

        cout << endl << "Lines completed:" << endl;
        cout << "Player 1: " << linesplayer1 << endl;
        cout << "Player 2: " << linesplayer2 << endl;

        if (linesplayer1 >= 5)
            {
            cout << endl << "Player 1 wins." << endl;
            break;
            }

        if (linesplayer2 >= 5)
            {
            cout << endl << "Player 2 wins." << endl;
            break;
            }
    }

    return 0;
}
