#include <iostream>
using namespace std;

bool checkPalindrome(string s)
{
    if (s.empty())
    {
        return true;
    }
    bool psf = checkPalindrome(s.substr(1, s.length() - 2));
    if (psf && s[0] == s[s.length() - 1])
    {
        return true;
    }else{
        return false;
    }
}   

int main()
{
    string s;
    cin >> s;
    if (checkPalindrome(s))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
}