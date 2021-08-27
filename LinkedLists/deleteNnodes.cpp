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

Node *deleteN(Node *head, int m, int n)
{
    if (head == NULL)
    {
        return head;
    }
    Node *t1 = head;
    Node *t2 = head;
    int c1 = 1, c2 = 1;
    while (t1 != NULL && t2 != NULL)
    {
        while (c1 < m)
        {
            t1 = t1->next;
            c1++;
        }
        if (t1 != NULL)
        {
            t2 = t1->next;
        }
        c1 = 1;
        while (c2 <= n)
        {
            Node *nxt = t2->next;
            delete t2;
            t2 = nxt;
            if (nxt != NULL)
            {
                nxt = nxt->next;
            }
            c2++;
        }
        c2 = 1;
        t1->next = t2;
    }
    return head;
}

int main()
{
    Node *head = input();
    int m, n;
    cin >> m >> n;
    head = deleteN(head, m, n);
    print(head);
}