#include<iostream>
using namespace std;

int partition(int* arr,int s,int e){
    int i=s;
    int pivot=arr[e];
    for(int j=s;j<=e-1;j++){
        if(pivot>arr[j]){
            swap(arr[i],arr[j]);
            i++;
        }
    }swap(arr[i],arr[e]);
    return i;
}

void quickSort(int*arr,int s,int e){
    if(s>=e){
        return;
    }int pi=partition(arr,s,e);
    quickSort(arr,s,pi-1);
    quickSort(arr,pi+1,e);
}

int main(){
    int n;
    cin>>n;
    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }quickSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}