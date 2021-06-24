#include<iostream>
using namespace std;

int power(int x,int n){
    if(n==0){
        return 1;
    }
    int xn=power(x,n/2);
    xn=xn*xn;
    if(n%2==1){
        xn=x*xn;
    }return xn;
  
}

int main(){
    int n,x;
    cin>>x>>n;
    cout<<power(x,n)<<endl;
}