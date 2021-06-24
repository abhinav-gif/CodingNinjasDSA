#include <iostream>
using namespace std;

int maxArr(int *arr, int n)
{
    if (n == 1)
    {
        return arr[n];
    }
    int smallOp = maxArr(arr, n - 1);
    if (smallOp < arr[n - 1])
    {
        return arr[n - 1];
    }
    else
    {
        return smallOp;
    }
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << maxArr(arr, n) << endl;
}