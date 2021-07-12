#include <iostream>
#include <vector>
using namespace std;

vector<string> kp(string n, vector<string> keywords)
{
    if (n.empty())
    {
        vector<string> v;
        v.push_back("");
        return v;
    }
    int first = n[0] - '0';
    vector<string> ssf = kp(n.substr(1), keywords);
    vector<string> ans;
    for (auto i : ssf)
    {
        for (int j = 0; j < keywords[first].length(); j++)
        {
            ans.push_back(keywords[first][j] + i);
        }
    }
    return ans;
}

int main()
{
    string n;
    cin >> n;
    vector<string> keywords = {"","","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans = kp(n, keywords);
    for (auto i : ans)
    {
        cout << i << endl;
    }
}