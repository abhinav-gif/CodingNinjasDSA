#include <iostream>
using namespace std;
template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node(T data)
    {
        next = NULL;
        this->data = data;
    }
};
template <typename T>
class Stack
{
    int size;
    Node<T> *head;

public:
    Stack()
    {
        size = 0;
        head = NULL;
    }
    void push(T data)
    {
        Node<T> *temp = new Node<T>(data);
        temp->next = head;
        head = temp;
        size++;
    }
    T top()
    {
        if (head == NULL)
        {
            cout << "List empty" << endl;
            return 0;
        }
        return head->data;
    }
    void pop()
    {
        if (head == NULL)
        {
            cout << "List empty" << endl;
            return;
        }
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    bool isEmpty()
    {
        if (head == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int Getsize()
    {
        return size;
    }
};

int main()
{
    Stack<char> s;
    s.pop();
    cout << s.top() << endl;
    cout << s.Getsize() << endl;
    cout << s.isEmpty() << endl;
}