#include <iostream>
using namespace std;

void printPermutation(string ques, string ans)
{
    if (ques.length()==0)
    {
        cout << ans << endl;
        return;
    }
    for (int i = 0; i < ques.length(); i++)
    {
        char ch = ques[i];
        string roq=ques.substr(0,i)+ques.substr(i+1);
        printPermutation(roq, ans + ch);
    }
}

int main()
{
    string ques;
    cin >> ques;   
    printPermutation(ques, "");
    
}