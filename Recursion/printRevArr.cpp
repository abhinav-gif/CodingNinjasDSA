#include <iostream>
using namespace std;

void printRev(int *arr, int n)
{
    if (n == 0)
    {
        return;
    }
    cout << arr[n - 1] << " ";
    printRev(arr, n - 1);
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
    printRev(arr, n);
}