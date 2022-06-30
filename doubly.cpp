#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node * prev;
    Node * next;

    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

};

void print(Node* &head)
{
    Node * temp = head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    
}

int getlength(Node *&head)
{
    int len = 0;
    Node * temp = head;
    while (temp!=NULL)
    {
        len++;
        temp = temp->next;
    }
    
    return len;
}

void InsertAtHead(Node *&tail,Node *&head,int d)
{

    if(head==NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
   
}

void InsertAtTail(Node *&tail,Node *&head, int d)
{
    if(tail==NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    
}

void InsertAtPosition(Node *&tail, Node *&head, int position , int d)
{   
    
    if(position==1)
    {
        InsertAtHead(tail,head,d);
        return;
    }

    Node *temp = head;
    int cnt = 1;
    while(cnt < position-1)
    {
        temp = temp->next;
        cnt++;
    }

    if(temp->next==NULL)
    {
        InsertAtTail(tail,head,d);
        return;
    }

    Node *nn = new Node(d);

    nn->next = temp->next;
    temp->next->prev = nn;
    temp->next = nn;
    nn->prev = temp;

}


void deleteNode(int position, Node * head)
{
    if(position==1)
    {
        Node * temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }

    else
    {
        Node * previous = NULL;
        Node * current = head;
        int cnt = 1;
        while(cnt < position)
        {
            previous = current;
            current = current->next;
            cnt++;
        }

        previous->next = current->next;
        current->next->prev = previous;
        current->next = NULL;
        current->prev = NULL;
        delete current;
    }
}

int main()
{
    // Node * n1 = new Node(10);
    Node *head = NULL;
    Node *tail = NULL;
    // print(head);

    // cout<<getlength(head)<<endl;


    InsertAtHead(tail,head,100);
    print(head);

    InsertAtHead(tail,head,20);
    print(head);

    InsertAtHead(tail,head,30);
    print(head);

    InsertAtTail(tail,head,90);
    print(head);

    InsertAtPosition(tail,head,2,555);
    print(head);


    deleteNode(3,head);
    print(head);

    return 0;

}