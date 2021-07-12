#include <iostream>
#include <vector>
using namespace std;

vector<string> stair(int n)
{
    if (n == 0)
    {
        vector<string> v;
        v.push_back("");
        return v;
    }
    if (n < 0)
    {
        vector<string> v;
        return v;
    }
    vector<string> path1 = stair(n - 1);
    vector<string> path2 = stair(n - 2);
    vector<string> path3 = stair(n - 3);
    vector<string> ans;
    for (auto i : path1)
    {
        ans.push_back("1" + i);
    }
    for (auto i : path2)
    {
        ans.push_back("2" + i);
    }
    for (auto i : path3)
    {
        ans.push_back("3" + i);
    }
    return ans;
}

int main()
{   //program to find paths of n to 0 stair
    //1,2,3 steps can be taken at a time
    int n;
    cin >> n;
    vector<string> ans = stair(n);
    for (auto i : ans)
    {
        cout << i << endl;
    }
}