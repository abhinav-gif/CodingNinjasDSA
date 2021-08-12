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

Node *oddEven(Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    Node *oHead = NULL;
    Node *otail = NULL;
    Node *eHead = NULL;
    Node *etail = NULL;
    Node *temp = head;
    while (temp != NULL)
    {
        Node *n = new Node(temp->data);
        if (temp->data % 2 == 1)
        {
            if (oHead == NULL)
            {
                oHead = n;
                otail = n;
            }
            else
            {
                otail->next = n;
                otail = otail->next;
            }
        }
        else
        {
            if (eHead == NULL)
            {
                eHead = n;
                etail = n;
            }
            else
            {
                etail->next = n;
                etail = etail->next;
            }
        }
        temp = temp->next;
    }
    if (oHead == NULL)
    {
        return eHead;
    }
    otail->next = eHead;
    return oHead;
}

int main()
{
    Node *head = input();
    head = oddEven(head);
    print(head);
}