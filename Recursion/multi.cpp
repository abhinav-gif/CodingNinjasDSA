#include <iostream>
using namespace std;

int mul(int n1, int n2)
{
    if (n1 == 0 || n2 == 0)
    {
        return 0;
    }
    return n1 + mul(n1, n2 - 1);
}

int main()
{
    int n1, n2;
    cin >> n1 >> n2;
    cout << mul(n1, n2) << endl;
}