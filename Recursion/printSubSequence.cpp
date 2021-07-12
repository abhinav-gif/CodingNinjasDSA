#include <iostream>
using namespace std;

void printSS(string str, string ans)
{
    if (str.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    char ch = str[0];
    printSS(str.substr(1), ans + ch);
    printSS(str.substr(1), ans + "");
    
}

int main()
{
    string str;
    cin >> str;
    printSS(str, "");
}