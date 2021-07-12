#include <iostream>
using namespace std;

int sumD(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n % 10 + sumD(n / 10);
}

int main()
{
    int n;
    cin >> n;
    int ans = sumD(n);
    while (ans >= 10)
    {
        ans=sumD(ans);
    }
    cout << ans << endl;
}