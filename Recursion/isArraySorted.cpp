#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int> v)
{
    if (v.size() == 1)
    {
        return true;
    }
    int last = v.back();
    v.pop_back();
    bool temp = check(v);
    if (last > v.back() && temp)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    vector<int> v;
    int n;
    cin >> n;
    while (n--)
    {
        int t;
        cin >> t;
        v.push_back(t);
    }
    if (check(v))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
}