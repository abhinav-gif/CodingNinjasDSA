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

int get(Node *head, int i)
{
    Node *temp = head;
    int l = 0;
    while (temp != NULL)
    {
        if (i == l)
        {
            return temp->data;
        }
        temp = temp->next;
        l++;
    }
    return -1;
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

int main()
{
    Node *head = input();
    int i;
    cin >> i;
    cout << get(head, i) << endl;
}