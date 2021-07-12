#include <iostream>
using namespace std;

string ps(string s)
{
    if (s.empty())
    {
        return "";
    }
    char first = s[0];
    string ssf = ps(s.substr(1));
    if (first == ssf[0])
    {
        ssf = "*" + ssf;
    }
    return first + ssf;
}

int main()
{
    string s;
    cin >> s;
    cout << ps(s) << endl;
}