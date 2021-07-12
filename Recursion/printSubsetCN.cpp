#include <iostream>
using namespace std;

void printss(int *arr, int n, string ans)
{
    if (n == 0)
    {
        cout << ans << endl;
        return;
    }
    string f =to_string(arr[0]);
    printss(arr + 1, n - 1, ans);
    printss(arr + 1, n - 1, ans + f+" ");
    
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
    printss(arr, n, "");
    delete[] arr;
}