#include <bits/stdc++.h>
using namespace std;

void ssk(int *arr, int n, string s, int k, int sum, vector<string> &ans)
{
    if (sum == k)
    {
        ans.push_back(s);
        return;
    }
    if (n == 0)
    {
        return;
    }
    ssk(arr + 1, n - 1, s + to_string(arr[0]) + " ", k, sum + arr[0], ans);
    ssk(arr + 1, n - 1, s, k, sum, ans);
}

int subsetSumToK(int input[], int n, int output[][50], int k)
{
    // Write your code here
    for (int i = 0; i < 10000; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            output[i][j] = 0;
        }
    }
    vector<string> ans;
    ssk(input, n, "", k, 0, ans);
    reverse(ans.begin(),ans.end());
    int row = 0;
    for (auto str : ans)
    {
        if (str == "")
        {
            continue;
        }
        int j = 1;
        int len = 1;
        for (int i = 0; str[i] != '\0'; i++)
        {
            if (str[i] == ' ')
            {
                j++;
                len++;
                continue;
            }
            else
            {
                output[row][j] = output[row][j] * 10 + str[i] - '0';
            }
        }
        output[row][0] = len-1;
        row++;
    }
    return row;
}
int main()
{
    int input[20], length, output[10000][50], k;
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];

    cin >> k;

    int size = subsetSumToK(input, length, output, k);

    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j <= output[i][0]; j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
}
