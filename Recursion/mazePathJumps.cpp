#include <iostream>
#include <vector>
using namespace std;

vector<string> mazePathJumps(int sr, int sc, int dr, int dc)
{
    if (sr > dr || sc > dc)
    {
        vector<string> v;
        return v;
    }
    if (sr == dr && sc == dc)
    {
        vector<string> v;
        v.push_back("");
        return v;
    }
    vector<string> ans;
    //horizontal movement

    for (int i = 1; i <= dc - sc; i++)
    {
        vector<string> hpaths = mazePathJumps(sr, sc + i, dr, dc);
       char ch = i + '0';
        for (string j : hpaths)
        {
            ans.push_back("h" + ch + j);
        }
    }
    //vertical movement

    for (int i = 1; i <= dr - sr; i++)
    {
        vector<string> vpaths = mazePathJumps(sr + i, sc, dr, dc);
       char ch = i + '0';
        for (string j : vpaths)
        {
            ans.push_back("v" + ch + j);
        }
    }
    //diagonal movement

    for (int i = 1; i <= dr - sr && i <= dc - sc; i++)
    {
        vector<string> dpaths = mazePathJumps(sr + i, sc + i, dr, dc);
        char ch = i + '0';
        for (string j : dpaths)
        {
            ans.push_back("d" + ch + j);
        }
    }

    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> res = mazePathJumps(0, 0, n - 1, m - 1);
    for (auto it : res)
    {
        cout << it << endl;
    }
}