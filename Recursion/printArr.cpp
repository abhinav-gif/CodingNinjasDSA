#include <iostream>
using namespace std;

void printUsingIndex(int *arr, int n, int index)
{
    if (n == 0)
    {
        return;
    }
    cout << arr[index] << " ";
    printUsingIndex(arr, n - 1, index + 1);
}

void print(int *arr, int n)
{
    if (n == 0)
    {
        return;
    }
    cout << arr[0] << " ";
    print(arr + 1, n - 1);
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
    printUsingIndex(arr, n, 0);
    cout << endl;
    print(arr, n);
}