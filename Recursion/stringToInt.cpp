#include<iostream>
using namespace std;

int sti(string s){
   if(s.empty()){
       return 0;
   }
    char last=s[s.length()-1];
   int smallOp= sti(s.substr(0,s.length()-1));
   int li=last-'0';
   return smallOp*10 + li;
}

int main(){
    string s;
    cin>>s;
    cout<<sti(s)<<endl;
}