#include <iostream>
#include <vector>
using namespace std;

void subsetSumK(int *arr, int n, int k, string ans, int sum, vector<string> &v)
{
    if (n == 0)
    {
        if (sum == k)
        {
            v.push_back(ans);
        }
        return;
    }
    subsetSumK(arr + 1, n - 1, k, ans + to_string(arr[0]) + " ", sum + arr[0], v);
    subsetSumK(arr + 1, n - 1, k, ans, sum, v);
}

int main()
{
    int n, k;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> k;
    vector<string> v;
    subsetSumK(arr, n, k, "", 0, v);
    for (auto i : v)
    {
        cout << i << endl;
    }
}