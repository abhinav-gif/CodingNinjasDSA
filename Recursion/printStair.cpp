#include <iostream>
using namespace std;

void printStair(int n, string ans)
{
    if (n == 0)
    {
        cout << ans<<endl;
        return;
    }
    if (n < 0)
    {
        return;
    }
    printStair(n - 1, ans + "1");
    printStair(n - 2, ans + "2");
    printStair(n - 3, ans + "3");
}

int main()
{
    int n;
    cin >> n;
    printStair(n, "");
}