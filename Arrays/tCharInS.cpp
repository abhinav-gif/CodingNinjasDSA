#include <iostream>
using namespace std;

bool find(string s, string t)
{

    if (s.empty())
    {
        return false;
    }
    if (t.empty())
    {
        return true;
    }

    char firstS = s[0];
    char firstT = t[0];
    if (firstS == firstT)
    {

        return find(s.substr(1), t.substr(1));
    }
    else
    {
        return find(s.substr(1), t);
    }
}

int main()
{
    string s, t;
    cin >> s >> t;
    if (find(s, t))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
}