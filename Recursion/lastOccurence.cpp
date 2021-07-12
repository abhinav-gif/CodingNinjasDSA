#include <iostream>
using namespace std;

int lio(int *arr, int n, int x, int idx)
{
    if (idx == -1)
    {
        return -1;
    }
    if (arr[idx] == x)
    {
        return idx;
    }
    else
    {
        return lio(arr, n, x, idx - 1);
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
    cout << lio(arr, n, x, n - 1) << endl;
}