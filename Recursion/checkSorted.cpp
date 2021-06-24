#include<iostream>
using namespace std;

bool sorted(int *arr,int n){
    if(n==0||n==1){
        return true;
    }
    if(arr[0]>arr[1]){
        return false;
    }
       return sorted(arr+1,n-1);
}

int main(){
    int arr[]={1,2,3,6,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<sorted(arr,n);
}