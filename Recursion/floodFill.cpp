//using smart calls
#include <iostream>
using namespace std;

void floodFill(int **matrix, int sr, int sc, int dr, int dc, string ans)
{
    if (matrix[sr][sc] == 1)
    {
        return;
    }
    else
    {
        if (sr == dr && sc == dc)
        {
            cout << ans << endl;
            return;
        }
        matrix[sr][sc] = 2;
        //top
        if (sr > 0 && matrix[sr - 1][sc] != 2)
        {
            floodFill(matrix, sr - 1, sc, dr, dc, ans + "t");
        }

        //left
        if (sc > 0 && matrix[sr][sc - 1] != 2)
        {
            floodFill(matrix, sr, sc - 1, dr, dc, ans + "l");
        }

        //down
        if (sr < dr && matrix[sr + 1][sc] != 2)
        {
            floodFill(matrix, sr + 1, sc, dr, dc, ans + "d");
        }

        //right
        if (sc < dc && matrix[sr][sc + 1] != 2)
        {
            floodFill(matrix, sr, sc + 1, dr, dc, ans + "r");
        }
        matrix[sr][sc] = 0;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    //initialize matrix
    int **matrix = new int *[n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    floodFill(matrix, 0, 0, n - 1, m - 1, "");
}
//smart base case dumb calls

/*#include <iostream>
using namespace std;

void floodFill(int **matrix, int sr, int sc, int dr, int dc, string ans, bool **visited)
{
    if (sr < 0 || sc < 0 || sr > dr || sc > dc || matrix[sr][sc] == 1 || visited[sr][sc] == true)
    {
        return;
    }

    if (sr == dr && sc == dc)
    {
        cout << ans << endl;
        return;
    }
    visited[sr][sc] = true;
    //top
    floodFill(matrix, sr - 1, sc, dr, dc, ans + "t", visited);
    //left
    floodFill(matrix, sr, sc - 1, dr, dc, ans + "l", visited);
    //down
    floodFill(matrix, sr + 1, sc, dr, dc, ans + "d", visited);
    //right
    floodFill(matrix, sr, sc + 1, dr, dc, ans + "r", visited);
    visited[sr][sc] = false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    //initialize matrix
    int **matrix = new int *[n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    bool **visited = new bool *[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = new bool[m];
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = false;
        }
    }

    floodFill(matrix, 0, 0, n - 1, m - 1, "", visited);
}*/