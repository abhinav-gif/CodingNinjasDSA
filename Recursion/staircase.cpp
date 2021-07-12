#include <iostream>
using namespace std;

int stairCase(int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }
   int ans= stairCase(n-1)+stairCase(n-2)+stairCase(n-3);
   return ans;
}

int main()
{
    int n;
    cin >> n;
    cout << stairCase(n) << endl;
}