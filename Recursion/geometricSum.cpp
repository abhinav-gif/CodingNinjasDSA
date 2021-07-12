#include<iostream>
#include<cmath>
using namespace std;

double gSum(int n){
   if(n==0){
       return 1;
   }
   return (1/pow(2,n))+ gSum(n-1);
}

int main(){
    int n;
    cin>>n;
    cout<<gSum(n)<<endl;
}