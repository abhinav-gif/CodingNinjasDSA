#include <iostream>
using namespace std;

void printMazeJump(int sr, int sc, int dr, int dc, string ans)
{
    if (sr > dr || sc > dc)
    {
        return;
    }
    if (sr == dr && sc == dc)
    {
        cout << ans << endl;
        return;
    }
    //vertical paths
    for (int i = 1; i <= dr; i++)
    {
        char ch = i + '0';
        printMazeJump(sr + i, sc, dr, dc, ans + "v" + ch);
    } //horizontal paths
    for (int i = 1; i <= dc; i++)
    {
        char ch = i + '0';
        printMazeJump(sr, sc + i, dr, dc, ans + "h" + ch);
    } //diagonal paths
    for (int i = 1; i <= dr && i <= dc; i++)
    {
        char ch = i + '0';
        printMazeJump(sr + i, sc + i, dr, dc, ans + "d" + ch);
    }
}

int main()
{
    int n, m, sr, sc;
    cin >>sr >> sc >> n >> m;
    printMazeJump(sr, sc, n - 1, m - 1, "");
}