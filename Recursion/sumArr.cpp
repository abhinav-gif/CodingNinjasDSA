#include <iostream>
#include <vector>
using namespace std;

int sum(vector<int> v)
{
    if (v.size() == 0)
    {
        return 0;
    }
    int last = v.back();
    v.pop_back();
    return last + sum(v);
}

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    while (n--)
    {
        int t;
        cin >> t;
        v.push_back(t);
    }
    cout<<sum(v)<<endl;
}