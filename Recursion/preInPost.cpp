#include <iostream>
using namespace std;

void pip(int n)
{
    if (n == 0)
    {
        return;
    }//when two calls are there they are divided into left call and right call
    //code above left call is called pre section
    //code between left and  right call is called In section
    //code below right call is called post section 
    //we anayalize the code with Euler tree
    cout << "Pre " << n << endl;
    pip(n - 1);
    cout << "In " << n << endl;
    pip(n - 1);
    cout << "Post " << n << endl;
}

int main()
{
    int n;
    cin >> n;
    pip(n);
}