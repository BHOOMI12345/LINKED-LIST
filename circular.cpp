#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node * next;

    Node(int data)
    {
        this->data = data;
        this->next = next;
    }
};

void print(Node * & tail)
{
    Node * temp = tail;
    do
    {
        cout<<tail->data<<" ";
        tail = tail->next;

    } while (temp!=tail);
    cout<<endl;
}

void InsertElement(Node * &tail, int element , int d)
{
    if(tail==NULL)
    {
        Node * nn = new Node(d);
        nn->next = nn;
        tail = nn;
    }

    else
    {
        Node *curr = tail;
        while(curr->data!=element)
        {
            curr = curr->next;
        }

        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void deleteNode(Node * &tail,int val)
{
    if(tail==NULL)
    {
        cout<<"List is Empty"<<endl;
    }

    else
    {
        Node *prev = tail;
        Node *curr = prev->next;

        while(curr->data!=val)
        {
            prev = curr;
            curr = curr->next;
        }

        if(prev==curr)
        {
            tail = NULL;
        }

        if(tail==curr)
        {
            tail = curr->next;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main()
{

    Node * tail = NULL;

    InsertElement(tail,5,4);
    print(tail);

    InsertElement(tail,4,6);
    print(tail);

    InsertElement(tail,6,7);
    print(tail);
    InsertElement(tail,7,8);
    print(tail);
    InsertElement(tail,7,6);
    print(tail);
    

    deleteNode(tail,8);
    print(tail);

    return 0;
}