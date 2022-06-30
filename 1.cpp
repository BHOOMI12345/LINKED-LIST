#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data= data;
        this->next = NULL;
    }


};

void InsertAtHead(Node * &head, int d){


    //new node creation
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void InsertAtTail(Node* &tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void InsertAtPosition(Node * &tail, Node * &head,int position, int d)
{
    int cnt = 1;
    Node * temp = head;

//for the starting postion
    if(position==1)
    {
        InsertAtHead(head,d);
        return;
    }
    while (cnt < position-1)
    {
        temp = temp->next;
        cnt++;
    }

//for the ending position
    if(temp->next==NULL)
    {
        InsertAtTail(tail,d);
    }
    
    Node * nn = new Node(d);
    nn->next = temp->next;
    temp->next = nn;
}

void deleteNode(int position, Node* &head)
{

    //deleting first node
    if(position==1)
    {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    

    //deleting middle node and last node
    else{
        Node * prev = NULL;
        Node * curr = head;

        int cnt = 1;
        while(cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}


void print(Node *&head)
{
    Node *temp = head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}




int main()
{
    //Statiscally
    // Node n1(1);
    // Node *head= &n1;

    // Node n2(2);
    // Node n3(3);
    // Node n4(4);
    // Node n5(5);

    // n1.next = &n2;
    // n2.next = &n3;
    // n3.next = &n4;
    // n4.next = &n5;

    // print(head);
    // print(head);
    // cout<< n1.data<<" "<<n2.data<<endl;

    //Dynamically

    Node *n1 = new Node(10);
    Node *head = n1;
    Node *tail = n1;

    // Node *n2 = new Node(20);
    // n1->next = n2;

    // Node *n3 = new Node(30);
    // n2->next = n3;

    print(head);
    

    InsertAtHead(head, 15);
    print(head);

    InsertAtHead(head, 25);
    print(head);

    InsertAtTail(tail, 400);
    print(head);

    InsertAtTail(tail, 500);
    print(head);

    InsertAtPosition(tail, head, 3, 1500);
    print(head);


    deleteNode(2,head);
    print(head);
    return 0;
}