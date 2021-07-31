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
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

Node *rmDup(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *p = head->next;
    Node *temp = head;
    while (temp != NULL)
    {
        while (p != NULL && temp->data == p->data)
        {
            Node *q = p;
            p = p->next;
            delete q;
        }
        temp->next = p;
        temp = temp->next;
        if (p != NULL)
            p = p->next;
    }
    return head;
}

Node *takeInput()
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

int main()
{
    Node *head = takeInput();
    head = rmDup(head);
    print(head);
}