#include <iostream>
using namespace std;

string rmChar(string s, char a, char x)
{
    if (s.empty())
    {
        return "";
    }
    char first = s[0];
    string ssf = rmChar(s.substr(1), a, x);
    if (first == a)
    {
        return x + ssf;
    }
    else
    {
        return first + ssf;
    }
}

int main()
{
    string s;
    char a, x;
    cin >> s >> a >> x;
    cout << rmChar(s, a, x) << endl;
}