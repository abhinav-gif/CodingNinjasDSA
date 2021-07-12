#include<iostream>
using namespace std;

void permutate(string s,string ans){
    if(s.empty()){
        cout<<ans<<endl;
        return;
    }
    for(int i=0;s[i]!='\0';i++){
        permutate(s.substr(0,i)+s.substr(i+1),ans+s[i]);
    }
}

int main(){
    string s;
    cin>>s;
    permutate(s,"");
}