#include <iostream>
using namespace std;

bool isQueenSafe(int **chess, int n, int row, int col)
{
    for (int i = row - 1; i >= 0; i--)
    {
        if (chess[i][col] == 1)
        {
            return false;
        }
    }
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (chess[i][j] == 1)
        {
            return false;
        }
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
        if (chess[i][j] == 1)
        {
            return false;
        }
    }
    return true;
}

void nQueens(int **chess, int n, int row, int col, string ans)
{
    if (row == n)
    {
        cout << ans + "." << endl;
        return;
    }
    for (int col = 0; col < n; col++)
    {
        if (isQueenSafe(chess, n, row, col) == true)
        {
            chess[row][col] = 1;
            if (row + 1 == n)
            {
                nQueens(chess, n, row + 1, col, ans + to_string(row) + "-" + to_string(col) + "");
            }
            else
            {
                nQueens(chess, n, row + 1, col, ans + to_string(row) + "-" + to_string(col) + ",");
            }

            chess[row][col] = 0;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int **chess = new int *[n];
    for (int i = 0; i < n; i++)
    {
        chess[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            chess[i][j] = 0;
        }
    }
    nQueens(chess, n, 0, 0, "");
    for (int i = 0; i < n; i++)
    {
        delete[] chess[i];
    }
    delete chess;
}