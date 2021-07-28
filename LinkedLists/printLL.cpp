#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node n1(1);
    Node *head = &n1;
    Node n2(2);
    n1.next = &n2;
    Node *n3 = new Node(3);
    n2.next = n3;
    Node *n4 = new Node(4);
    n3->next = n4;
    print(head);
    print(head);
}