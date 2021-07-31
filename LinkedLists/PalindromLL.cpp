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

bool isP(Node *h1, Node *h2)
{
    while (h1 != NULL && h2 != NULL)
    {
        if (h1->data != h2->data)
        {
            return false;
        }
        h1 = h1->next;
        h2 = h2->next;
    }
    return true;
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

int length(Node *head)
{
    Node *temp = head;
    int l = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        l++;
    }
    return l;
}
int main()
{
    Node *head = takeInput();
    int l = length(head);
    int i = 0;
    Node *head2 = head;
    while (i < l / 2)
    {
        head2 = head2->next;
        i++;
    }
    head2 = reverse(head2);
    if (isP(head, head2))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
}