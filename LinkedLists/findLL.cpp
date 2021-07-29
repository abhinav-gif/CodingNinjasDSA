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
//Iterative
// int find(Node *head, int x)
// {
//     int i = 0;
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         if (temp->data == x)
//         {
//             return i;
//         }
//         temp = temp->next;
//         i++;
//     }
//     return -1;
// }
//recursively
int find(Node *head, int x, int i)
{
    if (head == NULL)
    {
        return -1;
    }
    if (head->data == x)
    {
        return i;
    }
    return find(head->next, x, i + 1);
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
    int x;
    cin >> x;
    cout << find(head, x,0) << endl;
}