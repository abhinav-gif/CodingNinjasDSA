#include <iostream>
#include <vector>
using namespace std;

void printKeypad(string str, string ans)
{
    if (str.size() == 0)
    {
        cout << ans << endl;
        return;
    }
    vector<string> keywords = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int chIndex = str[0] - '0';
    string key = keywords[chIndex-1];
    for (int i = 0; i < key.size(); i++)
    {
        printKeypad(str.substr(1), ans + key[i]);
    }
}

int main()
{
    string str;
    cin >> str;
    printKeypad(str, "");
}