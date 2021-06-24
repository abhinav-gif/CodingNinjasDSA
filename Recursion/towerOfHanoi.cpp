#include<iostream>
using namespace std;

void tower(int n,char start,char dest,char helper){
if(n==0){
    return;
}   tower(n-1,start,helper,dest);
    cout<<n<<" "<<start<<" -> "<<dest<<endl;
    tower(n-1,helper,dest,start);
}

int main(){
    int n;
    cin>>n;
    tower(n,'a','b','c');
}