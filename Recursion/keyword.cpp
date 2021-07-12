#include <iostream>
#include <vector>
using namespace std;

vector<string> keypad(const vector<string> &keywords, string str)
{
    if (str.size() == 0)
    {
        vector<string> ev;
        ev.push_back("");
        return ev;
    }
    int chIndex = str[0] - '0';
    vector<string> smallOp = keypad(keywords, str.substr(1));
    string keyStr = keywords[chIndex-1];
    vector<string> ans;
    for (int i = 0; i < keyStr.size(); i++)
    {
        for (auto it : smallOp)
        {
            ans.push_back(keyStr[i] + it);
        }
    }
    return ans;
}

int main()
{
    string str;
    cin >> str;
    vector<string> keywords = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans = keypad(keywords, str);
    for (const auto &i : ans)
    {
        cout << i << endl;
    }
}