#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int* arr=new int[n];
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }int ans=sum-((n-2)*(n-1))/2;
    cout<<ans<<endl;
}