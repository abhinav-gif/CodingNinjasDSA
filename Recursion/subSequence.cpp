#include <iostream>
#include <vector>
using namespace std;

vector<string> ss(string str)
{
    if (str.size() == 0)
    {
        vector<string> res;
        res.push_back("");
        return res;
    }
    char ch = str[0];
    vector<string> smallRes = ss(str.substr(1));
    vector<string> ans;
    for (auto i : smallRes)
    {
        ans.push_back(""+i);
    }

    for (auto i : smallRes)
    {
        ans.push_back(ch+i);
    }
    return ans;
}

int main()
{
    string str;
    cin >> str;
    vector<string> ans = ss(str);
    for (const auto &i : ans)
    {
        cout << i << endl;
    }
}