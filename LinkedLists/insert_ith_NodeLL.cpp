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

void insert(Node *&head, int i, int data)
{
    Node *temp = head;
    Node *n = new Node(data);
    int curr = 0;
    while (temp != NULL)
    {
        if (i == 0)
        {
            n->next = head;
            head = n;
            return;
        }
        if (i == curr + 1)
        {
            Node *temp2 = temp->next;
            temp->next = n;
            n->next = temp2;
            return;
        }
        temp = temp->next;
        curr++;
    }
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
    insert(head, i, data);
    print(head);
}