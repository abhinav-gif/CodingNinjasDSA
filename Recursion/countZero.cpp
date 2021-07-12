#include <iostream>
using namespace std;

int count(int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n < 10)
    {
        return 0;
    }
    int csf = count(n / 10);
    if (n % 10 == 0)
    {
        csf = csf + 1;
    }
    return csf;
}

int main()
{
    int n;
    cin >> n;
    cout << count(n) << endl;
}