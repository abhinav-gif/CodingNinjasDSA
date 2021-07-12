#include <iostream>
using namespace std;

string rmX(string s)
{
    if (s.empty())
    {
        return "";
    }
    char first = s[0];
    string ssf = rmX(s.substr(1));
    if (first != 'x')
    {
        return first + ssf;
    }else{
        return ssf;
    }
}

int main()
{
    string s;
    cin >> s;
    cout << rmX(s) << endl;
}