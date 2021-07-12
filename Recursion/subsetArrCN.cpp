#include <bits/stdc++.h>
using namespace std;

vector<string> arrTostr(int *arr, int n)
{
    vector<string> ans;
    for (int i = 0; i < n; i++)
    {
        string s = "";
        s = to_string(arr[i]);
        ans.push_back(s);
    }
    return ans;
}

vector<string> subsetArr(vector<string> v)
{
    if (v.empty())
    {
        vector<string> v;
        v.push_back("");
        return v;
    }
    string last = v[v.size() - 1];
    vector<string> ans;
    v.pop_back();
    vector<string> ssf = subsetArr(v);
    for (auto i : ssf)
    {
        ans.push_back(i);
    }
    for (auto i : ssf)
    {
        ans.push_back(i + last + ",");
    }
    return ans;
}

int subset(int input[], int n, int output[][20])
{
    for (int i = 0; i < 35; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            output[i][j] = 0;
        }
    }
    vector<string> s = arrTostr(input, n);
    vector<string> ans = subsetArr(s);
    int row = 0;
    for (auto str : ans)
    {
        if (str == "")
        {
            continue;
        }
        else
        {
            int length = 0;
            for (int j = 0, k = 1; str[j] != '\0'; j++)
            {
                if (str[j] == ',')
                {
                    length++;
                    k++;
                }
                else
                {
                    output[row][k] = output[row][k] * 10 + str[j] - '0';
                }
            }
            output[row][0] = length;
            row++;
        }
    }
    return row;
}

int main()
{
    int input[20], length, output[35][20];
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];

    int size = subset(input, length, output);

    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j <= output[i][0]; j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
}
