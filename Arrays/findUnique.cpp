#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int xorArr = 0;
    for (int i = 0; i < n; i++)
    {
        xorArr ^= arr[i];
    }
    cout << xorArr << endl;
}