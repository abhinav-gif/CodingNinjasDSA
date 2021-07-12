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
    int k = 0, flag = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            k++;
            cout << k << endl;
            flag = 1;
            break;
        }
        k++;
    }
    if (flag == 0)
    {
        cout << 0 << endl;
    }
    delete[] arr;
}