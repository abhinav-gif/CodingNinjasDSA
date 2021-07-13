#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int maxProfit(int *arr, int n)
{
    if (n == 0)
    {
        return 0;
    }
    int first = arr[0];
    int smallOp = maxProfit(arr + 1, n - 1);
    if (first * n > smallOp)
    {
        return first * n;
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
    int *list = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> list[i];
    }
    sort(list, list + n);
    int maxPro = maxProfit(list, n);
    cout << maxPro << endl;
    // int *profits = new int[n];
    // for (int i = 0; i < n; i++)
    // {
    //     profits[i] = list[i] * (n - i);
    // }
    // int maxProfit = INT_MIN;
    // for (int i = 0; i < n; i++)
    // {
    //     if (maxProfit < profits[i])
    //     {
    //         maxProfit = profits[i];
    //     }
    // }
    // cout << maxProfit << endl;
    delete[] list;
}