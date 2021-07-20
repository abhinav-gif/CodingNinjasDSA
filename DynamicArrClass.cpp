#include <iostream>
using namespace std;

class DynamicArr
{
    int *arr = new int[1];
    int size = 0;
    int capacity = 1;

public:
    void push_back(int n)
    {
        if (size == capacity)
        {
            int *newArr = new int[2 * capacity];
            capacity = 2 * capacity;
            int i;
            for (i = 0; i < size; i++)
            {
                newArr[i] = arr[i];
            }
            newArr[i] = n;
            delete[] arr;
            arr = newArr;
        }
        else
        {
            arr[size] = n;
        }
        size++;
    }
    void pop_back()
    {
        if (size == 0)
        {
            return;
        }
        size--;
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    int length()
    {
        return size;
    }
    int cap()
    {
        return capacity;
    }
};

int main()
{
    DynamicArr abc;
    abc.push_back(1);
    abc.push_back(2);
    abc.push_back(3);
    abc.push_back(4);
    cout << abc.length() << " " << abc.cap() << endl;
    abc.pop_back();
     cout << abc.length() << " " << abc.cap() << endl;
    abc.print();
}