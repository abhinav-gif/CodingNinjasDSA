#include <iostream>
using namespace std;

int fio(int *arr, int n, int x)
{
    if (n == 0)
    {
        return -1;
    }
    int smallOp = fio(arr, n - 1, x);
    if (smallOp != -1)
    {
        return smallOp;
    }
    else if (x == arr[n - 1])
    {
        return n - 1;
    }
    else
    {
        return -1;
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
    int x;
    cin >> x;
    cout << fio(arr, n, x) << endl;
}