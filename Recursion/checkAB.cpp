#include <iostream>
using namespace std;

bool checkAB(string s)
{
   if (s.empty())
    {
        return true;
    }
    char first = s[0];
    if (first != 'a')
    {
        return false;
    }
    if (s.length()>2&&s.substr(1).find("bb") == 0)
    {
        return checkAB(s.substr(3));
    }return checkAB(s.substr(1));
}

int main()
{
    string s;
    cin >> s;
    bool ans = checkAB(s);
    if (ans == true)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
}