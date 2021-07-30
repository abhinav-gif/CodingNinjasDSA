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

Node* append(Node* head,int i){
    int l=length(head);
    int curr=0;
    Node* temp2=head;
    while(curr<l-i-1){
        head=head->next;
        curr++;
    }Node* temp=head->next;
    head->next=NULL;
    head=temp;
    while(temp->next!=NULL){
        temp=temp->next;
    }temp->next=temp2;
    return head;
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
    int i;
    cin >> i;
    head = append(head, i);
    print(head);
}