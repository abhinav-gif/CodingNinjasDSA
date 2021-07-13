#include <iostream>
using namespace std;

bool splitArr(int *arr, int n, int si, int lsum, int rsum)
{
    if (si == n)
    {
        return lsum == rsum;
    }
    if (arr[si] % 5 == 0)
    {
        lsum += arr[si];
    }
    else if (arr[si] % 3 == 0)
    {
        rsum += arr[si];
    }
    else
    {
        bool left = splitArr(arr, n, si + 1, lsum + arr[si], rsum);
        bool right = splitArr(arr, n, si + 1, lsum, rsum + arr[si]);
        return left || right;
    }
    return (arr, n, si + 1, lsum, rsum);
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
    if (splitArr(arr, n, 0, 0, 0))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
    delete[] arr;
}