#include <iostream>
using namespace std;

void printChess(int **chess, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << chess[i][j] << " ";
        }
        cout << endl;
    }
}

void kTour(int **chess, int n, int i, int j, int count)
{

    if (i < 0 || j < 0 || i >= n || j >= n || chess[i][j] > 0)
    {
        return;
    }
    else if (count == n * n)
    {
        chess[i][j] = count;
        printChess(chess, n);
        chess[i][j] = 0;
        return;
    }

    //8 choices for knight
    chess[i][j] = count;
    kTour(chess, n, i - 2, j + 1, count + 1);

    kTour(chess, n, i - 1, j + 2, count + 1);

    kTour(chess, n, i + 1, j + 2, count + 1);

    kTour(chess, n, i + 2, j + 1, count + 1);

    kTour(chess, n, i + 2, j - 1, count + 1);

    kTour(chess, n, i + 1, j - 2, count + 1);

    kTour(chess, n, i - 1, j - 2, count + 1);

    kTour(chess, n, i - 2, j - 1, count + 1);
    chess[i][j] = 0;
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
    int sRow, sCol;
    cin >> sRow >> sCol;
    kTour(chess, n, sRow, sCol, 1);
    for (int i = 0; i < n; i++)
    {
        delete[] chess[i];
    }
    delete[] chess;
}