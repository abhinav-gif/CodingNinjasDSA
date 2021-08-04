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

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

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
        tail->next = h1;
    }
    if (h2 != NULL)
    {
        tail->next = h2;
    }
    return head;
}

Node *mergeSort(Node *head)
{
    Node *head1=NULL;
    if (head == NULL || head->next ==NULL)
    {
        return head;
    }
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL)
    {
        if (fast->next == NULL)
        {
            head1 = slow->next;
            slow->next = NULL;
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    if (slow->next != NULL)
    {
        head1 = slow->next;
        slow->next = NULL;
    }
    Node *h1 = mergeSort(head);
    Node *h2 = mergeSort(head1);
    return merge(h1, h2);
}

int main()
{
    Node *head = takeInput();
    head = mergeSort(head);
    print(head);
}