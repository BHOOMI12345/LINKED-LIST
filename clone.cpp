#include<iostream>
#include<unordered_map>
using namespace std;

class Node {
    public:
    int data;
    Node * next;
    Node * random;

    Node(int d)
    {
        this->data = d;
        this->next = next;
    }
};

void InsertAtTail(Node *&head, Node *&tail, int d)
{
    Node *temp = new Node(d);

    if (tail == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}


Node * cloningLinkedList(Node *head)
{
    if(head==NULL || head->next)
    {
        return head;
    }

    Node * cloneHead = NULL;
    Node * cloneTail = NULL;

    Node * temp = head;
    while (temp!=NULL)
    {
        InsertAtTail(cloneHead,cloneTail,temp->data);
        temp = temp->next;
    }

    unordered_map<Node * ,Node *> mapping;
    Node * originalNode = head;
    Node * cloneNode = cloneHead;
    while (originalNode!=NULL && cloneNode !=NULL)
    {
        mapping[originalNode] = cloneNode;
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }

    originalNode = head;
    cloneNode = cloneHead;
    while (originalNode!=NULL)
    {
        cloneNode->random = mapping[originalNode->random];
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }

    return cloneHead;
    
    
    
}


