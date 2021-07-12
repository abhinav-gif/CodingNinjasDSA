#include <iostream>
using namespace std;

string rmDup(string s)
{
    if (s.empty())
    {
        return "";
    }
    char first = s[0];
    string ssf = rmDup(s.substr(1));
    if (first == ssf[0])
    {
        return ssf;
    }
    else
    {
        return first + ssf;
    }
}

int main()
{
    string s;
    cin >> s;
    cout << rmDup(s) << endl;
}