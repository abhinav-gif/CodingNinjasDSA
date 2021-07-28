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

void deleteNode(Node *&head, int i)
{
    Node *temp = head;
    int curr = 0;
    while (temp != NULL)
    {
        if (i == 0)
        {
            head = head->next;
            delete temp;
            return;
        }
        if (i == curr + 1)
        {
            Node *a = temp->next;
            temp->next = temp->next->next;
            delete a;
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
    cin >> i;
    deleteNode(head, i);
    print(head);
}