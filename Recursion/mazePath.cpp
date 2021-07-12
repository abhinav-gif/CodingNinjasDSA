#include <iostream>
#include <vector>
using namespace std;

vector<string> mazePath(int sr, int sc, int dr, int dc)
{
    if (dr == sr && dc == sc)
    {
        vector<string> v;
        v.push_back("");
        return v;
    }
    vector<string> vp;
    vector<string> hp;
    if (sr < dr)
    {
        vp = mazePath(sr + 1, sc, dr, dc);
    }

    if (sc < dc)
    {
        hp = mazePath(sr, sc + 1, dr, dc);
    }

    vector<string> ans;
    for (auto i : vp)
    {
        ans.push_back("v" + i);
    }
    for (auto i : hp)
    {
        ans.push_back("h" + i);
    }
    return ans;
}

int main()
{
    int sr, sc, n, m;
    cin >> n >> m >> sr >> sc;
    vector<string> ans = mazePath(sr, sc, n - 1, m - 1);
    for (auto i : ans)
    {
        cout << i << endl;
    }
}