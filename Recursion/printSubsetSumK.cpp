#include <iostream>

using namespace std;

void print(int* arr,int n,int k,string ans,int sum){
    if(n==0){
        if(sum==k){
            cout<<ans<<endl;
        }return;
    }
    print(arr+1,n-1,k,ans+to_string(arr[0])+" ",sum+arr[0]);
    print(arr+1,n-1,k,ans,sum);
}

int main()
{
    int n, k;
    cin >> n;
    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin >> k;
    print(arr,n, k, "",0);
}