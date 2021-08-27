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

Node *input()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *n = new Node(data);
        if (head == NULL)
        {
            head = n;
            tail = n;
        }
        else
        {
            tail->next = n;
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}

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

Node *swapNode(Node *head, int i, int j)
{
    Node *temp = head;
    Node *temp2 = head;
    for (int k = 1; k < i; k++)
    {
        temp = temp->next;
    }
    for (int k = 1; k < j; k++)
    {
        temp2 = temp2->next;
    }
}

int main()
{
    Node *head = input();
    int i, j;
    cin >> i >> j;
    head = swapNode(head, i, j);
    print(head);
}