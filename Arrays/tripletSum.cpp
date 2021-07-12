#include <iostream>
#include <algorithm>
using namespace std;

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
    sort(arr, arr + n);
    for (int k = 0; k < n; k++)
    {
        int i = k + 1, j = n - 1, temp = n - 1;
        int y = x - arr[k];
        while (i < j)
        {
            int sum = arr[i] + arr[j];
            if (sum == y)
            {
                //    if(arr[i]<arr[j]){
                //        if(arr[k]<arr[i]){
                //            cout<<arr[k]<<" "<<arr[i]<<" "<<arr[j]<<endl;
                //        }else if(arr[k]<arr[j]){
                //            cout<<arr[i]<<" "<<arr[k]<<" "<<arr[j]<<endl;
                //        }else{
                //            cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl;
                //        }

                //    }else{
                //        if(arr[k]<arr[j]){
                //            cout<<arr[k]<<" "<<arr[j]<<" "<<arr[i]<<endl;
                //        }
                //        else if(arr[k]<arr[i]){
                //            cout<<arr[j]<<" "<<arr[k]<<" "<<arr[i]<<endl;
                //        }else{
                //            cout<<arr[j]<<" "<<arr[i]<<" "<<arr[k]<<endl;
                //        }
                //    }
                int min1 = min(arr[k], min(arr[i], arr[j]));
                int max1 = max(arr[k], max(arr[i], arr[j]));
                int mid = x - min1 - max1;
                cout << min1 << " " << mid << " " << max1 << endl;
                j--;
                
            }
            else if (sum > y)
            {
                j--;
                temp = j;
            }
            else
            {
                i++;
                j = temp;
            }
        }
    }
}