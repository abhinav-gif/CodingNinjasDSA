#include<iostream>
#include<vector>
using namespace std;

void permute(string s,string ans,vector<string>& v){
    if(s.empty()){
        v.push_back(ans);
        return;
    }for(int i=0;i<s.length();i++){
         permute(s.substr(0,i)+s.substr(i+1),ans+s[i],v);
    }
   
}

int main(){
string s;
cin>>s;
vector<string> ans;
permute(s,"",ans);
for(auto i:ans){
    cout<<i<<endl;
}
}