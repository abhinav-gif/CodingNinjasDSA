#include <iostream>
using namespace std;

void printMaze(int sr, int sc, int dr, int dc, string ans)
{
    if (sr == dr && sc == dc)
    {
        cout << ans << endl;
        return;
    }
    if (sr > dr || sc > dc)
    {
        return;
    }
    printMaze(sr + 1, sc, dr, dc, ans + "v");
    printMaze(sr, sc + 1, dr, dc, ans + "h");
}

int main()
{
    int n, m, sr, sc;
    cin >> sr >> sc >> n >> m;
    printMaze(sr, sc, n - 1, m - 1, "");
}