#include <iostream>
#include <algorithm>
using namespace std;

void pairSum(int *arr, int n, int x)
{
    sort(arr, arr + n);
   int i=0,j=n-1,temp=n-1;
   while(i<j){
       int sum=arr[i]+arr[j];
       if(sum==x){
           if(arr[i]<arr[j]){
               cout<<arr[i]<<" "<<arr[j]<<endl;
           }else{
               cout<<arr[j]<<" "<<arr[i]<<endl;
           }
           j--;
       }else if(sum>x){
           j--;
           temp=j;
       }else{
           i++;
           j=temp;
       }
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
    pairSum(arr, n, x);
}