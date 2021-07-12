#include <iostream>
#include <vector>
using namespace std;

void allindex(int *arr, int n, int x, vector<int> &ans)
{
    if (n == 0)
    {
        return;
    }
    allindex(arr, n - 1, x, ans);
    if (arr[n - 1] == x)
    {
        ans.push_back(n - 1);
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
    vector<int> ans;
    allindex(arr, n, x, ans);
    if (ans.empty())
    {
        ans.push_back(-1);
    }
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}