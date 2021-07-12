#include<iostream>
using namespace std;

string rp(string s){
  if(s.empty()){
      return s;
  }
  char first=s[0];
  string sOp= rp(s.substr(1));
  if(first=='p'&&sOp[0]=='i'){
      return "3.14"+sOp.substr(1);
  }else{
     return first+sOp;
  }
}

int main(){
    string s;
    cin>>s;
    cout<<rp(s)<<endl;
}