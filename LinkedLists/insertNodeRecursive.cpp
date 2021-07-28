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

Node *insert(Node *head, int i, int data)
{
    if (i == 0 || head == NULL)
    {
        if (head == NULL && i != 0)
        {
            return head;
        }
        Node *n = new Node(data);
        n->next = head;
        head = n;
        return head;
    }
    Node *sh = insert(head->next, i - 1, data);
    head->next = sh;
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
    Node *head = input();
    int i, data;
    cin >> i >> data;
    head = insert(head, i, data);
    print(head);
}