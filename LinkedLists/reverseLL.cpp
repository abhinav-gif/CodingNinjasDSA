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

Node *reverse(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *sh = reverse(head->next);
    Node *temp = head;
    head = sh;
    temp->next = NULL;
    while (sh->next != NULL)
    {
        sh = sh->next;
    }
    sh->next = temp;
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
    head = reverse(head);
    print(head);
}