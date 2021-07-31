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

Node *merge(Node *h1, Node *h2)
{
    Node *head = NULL;
    Node *tail = NULL;
    while (h1 != NULL && h2 != NULL)
    {

        if (h1->data < h2->data)
        {
            if (head == NULL)
            {
                head = h1;
                tail = h1;
            }
            else
            {
                tail->next = h1;
                tail = tail->next;
            }
            h1 = h1->next;
        }
        else
        {
            if (head == NULL)
            {
                head = h2;
                tail = h2;
            }
            else
            {
                tail->next = h2;
                tail = tail->next;
            }

            h2 = h2->next;
        }
    }
    if (h1 != NULL)
    {
        tail->next=h1;
    }
    if (h2 != NULL)
    {
        tail->next=h2;
    }
    return head;
}

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

int main()
{
    Node *head1 = input();
    Node *head2 = input();
    Node *head = merge(head1, head2);
    print(head);
}