#include <iostream>
using namespace std;

void printTargetSum(int *arr, int n, int x, string str, int sum)
{
    if (sum == x)
    {
        cout << str.substr(0, str.length() - 2) + '.' << endl;
        return;
    }
    if (n == 0)
    {
        return;
    }
    printTargetSum(arr + 1, n - 1, x, str + to_string(arr[0]) + ", ", sum + arr[0]);
    printTargetSum(arr + 1, n - 1, x, str, sum);
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
    printTargetSum(arr, n, x, "", 0);
    delete[] arr;
}