#include <iostream>
using namespace std;

int fio(int *arr, int n, int x, int idx)
{
    if (idx == n)
    {
        return -1;
    }
    if (arr[idx] == x)
    {
        return idx;
    }
    else
    {
        return fio(arr, n, x, idx + 1);
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
    cout << fio(arr, n, x, 0) << endl;
}