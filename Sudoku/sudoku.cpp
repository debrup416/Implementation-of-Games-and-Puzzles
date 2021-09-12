#include <bits/stdc++.h>
#include "sudoku.hpp"

using namespace std;

bool checkRow(board &b1, int row, int num, int N)
{
    for (int col = 0; col < N; col++)
        if (b1.mat[row][col] == num)
            return true;
    return false;
}

bool checkCol(board &b1, int col, int num, int N)
{
    for (int row = 0; row < N; row++)
        if (b1.mat[row][col] == num)
            return true;
    return false;
}

bool checkBox(board &b1, int strow, int stcol, int num, int N)
{
    for (int row = 0; row < sqrt(N); row++)
    {
        for (int col = 0; col < sqrt(N); col++)
        {
            if (b1.mat[row + strow][col + stcol] == num)
                return true;
        }
    }
    return false;
}

bool isSafe(board &b1, int row, int col, int num, int N)
{
    return !checkRow(b1, row, num, N) && !checkCol(b1, col, num, N) && !checkBox(b1, row - row % 3, col - col % 3, num, N);
}

bool findUnassigned(board &b1, int &row, int &col, int N)
{
    for (row = 0; row < N; row++)
    {
        for (col = 0; col < N; col++)
        {
            if (b1.mat[row][col] == 0)
                return true;
        }
    }
    return false;
}

bool sudoku_solver(board &b1, int N)
{
    int row, col;
    if (!findUnassigned(b1, row, col, N))
        return true;
    for (int num = 1; num <= N; num++)
    {

        if (isSafe(b1, row, col, num, N))
        {
            b1.mat[row][col] = num;
            if (sudoku_solver(b1, N))
                return true;

            b1.mat[row][col] = 0;
        }
    }
    return false;
}

void print(board b1)
{
    cout << "\n    ";
    for (int i = 0; i < 9; i++)
        cout << i + 1 << " ";
    cout << "\n    ";
    for (int i = 0; i < 9; i++)
        cout << "-"
             << " ";
    cout << "\n";
    for (int i = 0; i < 9; i++)
    {
        cout << i + 1 << " | ";
        for (int j = 0; j < 9; j++)
        {
            cout << b1.mat[i][j] << " ";
        }
        cout << "\n";
    }
}

void fill(board &b1)
{
    char ch = 'Y';
    while (ch == 'Y')
    {
        print(b1);
        cout << "Enter position and value [ x y value ]\n";
        cout << "Write Y to continue or N to stop\n";
        cin >> ch;
        if(ch!='Y')
            return ;
        int x, y, val;
        cin >> x >> y >> val;
        if (x < 1 || x > 9 || y < 1 || y > 9 || val < 0 || val > 9)
            cout << "Enter correct value\n";
        else
            b1.mat[x - 1][y - 1] = val;
    }
}

int get_hint(board &b1)
{
    int x, y;
    cout << "Enter x and y value to know the value\n";
    cin >> x >> y;
    if (x < 1 || x > 9 || y < 1 || y > 9)
    {
        cout << "Enter valid data\n";
        return -1;
    }
    return b1.mat[x - 1][y - 1];
}

void solve()
{
    board b1;
    cout << "\nLets Fill the board\n";
    fill(b1);
    sudoku_solver(b1, 9);
        
    cout<< "1.Lets take hint\n";
    cout << "2.Fully Solve\n";
    
    int choice;
    cin>>choice;
    if(choice==2){
        print(b1);
        return;
    }
    while(choice==1)
    {
        cout << get_hint(b1);
        cout<<"Prees 1 for more hint\nPress 0 for exit\n";
        cin>>choice;
    }
    return ;
}

void show()
{
    std::cout << "1.Solve the game\n";
    std::cout << "2.Exit()\n";
}