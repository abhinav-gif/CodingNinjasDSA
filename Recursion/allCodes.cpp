#include <iostream>
#include <vector>
using namespace std;

vector<string> code(string s, vector<string> const &codes)
{
    if (s.empty())
    {
        vector<string> v;
        v.push_back("");
        return v;
    }
    vector<string> ans;
    int first1 = s[0] - '0';
    vector<string> ssf1 = code(s.substr(1), codes);
    for (auto i : ssf1)
    {
        ans.push_back(codes[first1-1] + i);
    }
    if (s.length() > 1)
    {
        int first2 = stoi(s.substr(0, 2));
        vector<string> ssf2 = code(s.substr(2), codes);
        for (auto i : ssf2)
        {if(first2-1>26){
            continue;
        }
            ans.push_back(codes[first2-1] + i);
        }
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    vector<string> codes = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
    vector<string> ans = code(s, codes);
    for (auto i : ans)
    {
        cout << i << endl;
    }
}