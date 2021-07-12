#include <iostream>
#include <vector>
using namespace std;

void code(string s, vector<string> const &codes, string ans)
{
    if (s.empty())
    {
        cout << ans << endl;
        return;
    }
    int first1 = s[0] - '0';
    code(s.substr(1), codes, ans + codes[first1 - 1]);
    if (s.length() > 1)
    {
        int first2 = stoi(s.substr(0, 2));
        if (first2 - 1 < 26)
        {
            code(s.substr(2), codes, ans + codes[first2 - 1]);
        }
    }
}

int main()
{
    string s;
    cin >> s;
    vector<string> codes = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
    code(s, codes, "");
}