#include<iostream>
#include<algorithm>
using namespace std;

void printIntersection(int* arr1,int n,int* arr2,int m){
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
    int i=0,j=0;
    while(i<n&&j<m){
        if(arr1[i]==arr2[j]){
            cout<<arr1[i]<<endl;
            i++;
            j++;
        }else if(arr1[i]>arr2[j]){
            j++;
        }else{
            i++;
        }
    }
}

int main(){
    int n;
    cin>>n;
    int *arr1=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    int m;
    cin>>m;
    int* arr2=new int[m];
    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }
    printIntersection(arr1,n,arr2,m);
    delete[] arr1;
    delete[] arr2;
}