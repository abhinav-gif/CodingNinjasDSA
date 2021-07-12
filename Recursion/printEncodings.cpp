#include <iostream>
#include <vector>
using namespace std;

void printEn(string str, string ans)
{
    vector<string> encodes = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
    if (str.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    if (str.length() >= 1)
    {
        int chIndex = str[0] - '0';
        if (chIndex > 0)
        {
            printEn(str.substr(1), ans + encodes[chIndex - 1]);
        }
        else
        {
            return;
        }
    }
    if (str.length() >= 2)
    {
        int strIndex = stoi(str.substr(0, 2));
        if (strIndex < 26)
        {
            printEn(str.substr(2), ans + encodes[strIndex - 1]);
        }
    }
}

int main()
{
    string str;
    cin >> str;
    printEn(str, "");
}