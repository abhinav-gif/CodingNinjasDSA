#include <iostream>
using namespace std;

void merge(int *arr, int s, int mid, int end)
{
    int *leftArr = new int[mid - s + 1];
    int *rightArr = new int[end - mid];
    for (int i = 0; i < mid - s + 1; i++)
    {
        leftArr[i] = arr[s + i];
    }
    for (int i = 0; i < end - mid; i++)
    {
        rightArr[i] = arr[mid + 1 + i];
    }
    int lIndex = 0;
    int rIndex = 0;
    int curr = s;
    while (lIndex < mid - s + 1 && rIndex < end - mid)
    {
        if (leftArr[lIndex] <= rightArr[rIndex])
        {
            arr[curr] = leftArr[lIndex];
            lIndex++;
        }
        else
        {
            arr[curr] = rightArr[rIndex];
            rIndex++;
        }
        curr++;
    }
    while (lIndex < mid - s + 1)
    {
        arr[curr] = leftArr[lIndex];
        lIndex++;
        curr++;
    }
    while (rIndex < end - mid)
    {
        arr[curr] = rightArr[rIndex];
        rIndex++;
        curr++;
    }
}

void msort(int *arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int mid = (s + e) / 2;
    msort(arr, s, mid);
    msort(arr, mid + 1, e);
   merge(arr,s,mid,e);
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
    msort(arr, 0, n - 1);
    cout << "sorted array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    delete[] arr;
}