#include<iostream>
using namespace std;

int nFib(int n){
    if(n==0||n==1){
        return n;
    }
    return nFib(n-1)+nFib(n-2);
}

int main(){
    int n;
    cin>>n;
    cout<<nFib(n)<<endl;
}