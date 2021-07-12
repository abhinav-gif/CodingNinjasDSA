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
    int k;
    cin >> k;
    int *rotate = new int[k];
    for (int i = 0; i < k; i++)
    {
        rotate[i] = arr[i];
    }
    for (int i = k; i < n; i++)
    {
        arr[i - k] = arr[i];
    }
    for (int i = n - k, j = 0; j < k; i++, j++)
    {
        arr[i] = rotate[j];
    }
    //print rotated array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}