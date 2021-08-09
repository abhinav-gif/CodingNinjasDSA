#include <iostream>
using namespace std;

class DynamicArr
{
    int *arr;
    int size;
    int capacity;

public:
    DynamicArr()
    {
        arr = new int[1];
        size = 0;
        capacity = 1;
    }
    DynamicArr(DynamicArr const &d)
    {
        this->size = d.size;
        this->capacity = d.capacity;
        int *newArr = new int[d.capacity];
        for (int i = 0; i < d.size; i++)
        {
            newArr[i] = d.arr[i];
        }
        this->arr = newArr;
    }
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
    void print() const
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    int length() const
    {
        return size;
    }
    int cap() const
    {
        return capacity;
    }
    int get(int i)
    {
        if (i >= size)
        {
            return -1;
        }
        return arr[i];
    }
    void insert(int index, int element)
    {
        if (index > size || index < 0)
        {
            return;
        }
        if (size == capacity)
        {
            int *newArr = new int[2 * capacity];
            capacity = 2 * capacity;
            for (int i = 0; i < size; i++)
            {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
            for (int i = size; i > index; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[index] = element;
            size++;
        }
        else
        {
            for (int i = size; i > index; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[index] = element;
            size++;
        }
    }
    void operator=(DynamicArr const &d)
    {
        this->size = d.size;
        this->capacity = d.capacity;
        int *newArr = new int[d.capacity];
        for (int i = 0; i < d.size; i++)
        {
            newArr[i] = d.arr[i];
        }
        this->arr = newArr;
    }
};

int main()
{
    DynamicArr abc;
    abc.push_back(10);
    abc.push_back(20);
    abc.push_back(30);
    DynamicArr d1(abc);
    abc.push_back(40);
    d1.print();
    abc.print();
}