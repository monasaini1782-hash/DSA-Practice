#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

int N;
vector<vector<int>> board;
int solutions = 0;

bool isSafe(int row, int col)
{
    // Check column
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
            return false;
    }

    // Check left diagonal
    for (int i = row - 1, j = col - 1;
         i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
            return false;
    }

    // Check right diagonal
    for (int i = row - 1, j = col + 1;
         i >= 0 && j < N; i--, j++)
    {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

void printBoard()
{
    cout << "\nSolution " << solutions << ":\n";

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void solveNQueen(int row)
{
    if (row == N)
    {
        solutions++;
        printBoard();
        return;
    }

    for (int col = 0; col < N; col++)
    {
        if (isSafe(row, col))
        {
            board[row][col] = 1;

            solveNQueen(row + 1);

            board[row][col] = 0;
        }
    }
}

int main()
{
    cout << "Enter value of N: ";
    cin >> N;

    board.assign(N, vector<int>(N, 0));

    auto start = high_resolution_clock::now();

    solveNQueen(0);

    auto stop = high_resolution_clock::now();

    auto duration =
        duration_cast<microseconds>(stop - start);

    cout << "\nTotal Solutions = " << solutions << endl;

    cout << "Execution Time = "
         << duration.count()
         << " microseconds" << endl;

    // TIME COMPLEXITY
    cout << "\nTime Complexity:" << endl;
    cout << "Best Case    : O(N)" << endl;
    cout << "Average Case : O(N!)" << endl;
    cout << "Worst Case   : O(N!)" << endl;

    cout << "Space Complexity : O(N^2)" << endl;

    return 0;
}