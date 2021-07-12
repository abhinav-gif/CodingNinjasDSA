#include <iostream>
#include <vector>
using namespace std;

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

int main()
{
    int n;
    cin >> n;
    vector<string> v;
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        v.push_back(temp);
    }
    vector<string> ans = subsetArr(v);
    for (auto i : ans)
    {
        cout << i << endl;
    }
}