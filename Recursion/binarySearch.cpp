#include <iostream>
using namespace std;

int binarySearch(int *arr, int s, int e, int x)
{
    if (s <= e)
    {
        int mid = (s + e) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }else if(arr[mid]>x){
            binarySearch(arr,s,mid-1,x);
        }else{
            binarySearch(arr,mid+1,e,x);
        }
    }else{
        return -1;
    }
}

int main()
{
    int n, x;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> x;
    cout << binarySearch(arr, 0, n - 1, x) << endl;
}