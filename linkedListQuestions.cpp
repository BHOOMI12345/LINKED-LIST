#include <iostream>
#include <map>
#include<vector>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node *&head, Node *&tail, int d)
{
    Node *nn = new Node(d);
    if (head == NULL)
    {
        head = nn;
        tail = nn;
    }

    else
    {
        nn->next = head;
        head = nn;
    }
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

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

// Q1 REVERSE THE SINGLY LINKED LIST

Node *reverse1(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *chotaHead = reverse1(head->next);
    head->next->next = head;
    head->next = NULL;

    return chotaHead;
}

Node *reverseLinkedList(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;

    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}

// Q2 FIND THE MIDDLE ELEMENT OF THE LINKED LIST

Node *middle2(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    else
    {
        Node *slow = head;
        Node *fast = head->next;

        while (fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                fast = fast->next;
            }
            slow = slow->next;
        }

        return slow;
    }
}

void middle(Node *head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }

    Node *temp1 = head;
    for (int i = 0; i < len / 2; i++)
    {
        temp1 = temp1->next;
    }
    if (len % 2 != 0)
    {
        cout << temp1->data << " ";
    }
    else
    {
        cout << temp1->next->data << " ";
    }
}

// Q3 REVERSE THE LINKED LIST IN K GROUPS OF ELEMENT.

int getLength(Node *&head)
{
    Node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }

    return len;
}

Node *reverseKGroup(Node *&head, int k)
{
    int length = getLength(head);
    if (length >= k)
    {
        if (head == NULL)
        {
            return head;
        }

        Node *prev = NULL;
        Node *curr = head;
        Node *forward = NULL;
        int count = 0;

        while (curr != NULL && count < k)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            count++;
        }

        if (forward != NULL)
        {
            head->next = reverseKGroup(forward, k);
        }
        return prev;
    }

    else
    {
        return head;
    }
}

// Q4 CHECK WHETHER GIVEN LINKED LIST IS CIRCULAR OR NOT.

bool IsCircular(Node *head)
{
    if (head == NULL)
    {
        return true;
    }

    else if (head->next == NULL)
    {
        return false;
    }

    else
    {
        Node *temp = head->next;
        while (temp != NULL && temp != head)
        {
            temp = temp->next;
        }

        if (temp == head)
        {
            return true;
        }

        return false;
    }
}

// Q5 DETECT & REMOVE THE LOOP IN THE LINKED LIST

/////////DETECTING LOOP////////////////

bool detectApp(Node *head)
{
    if (head == NULL)
    {
        return false;
    }

    map<Node *, bool> visited;
    Node *temp = head;
    while (temp != NULL)
    {
        if (visited[temp] == true)
        {
            return true;
        }

        visited[temp] = true;
        temp = temp->next;
    }

    return false;
}

Node *FloydDetect(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    Node *slow = head;
    Node *fast = head;

    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }

        slow = slow->next;

        if (slow == fast)
        {
            return slow;
        }
    }
    return NULL;
}

/////////GETTING THE STARTING ELEMENT OF THE LOOP////////////////

Node *startingNodeOfLoop(Node *&head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *slow = head;
    Node *intersection = FloydDetect(head);

    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}

//////REMOVE THE CYCLE FROM THE LINKED LIST//////////

void removeLoop(Node *&head)
{
    if (head == NULL)
    {
        return;
    }

    Node *startN = startingNodeOfLoop(head);
    Node *temp = startN;
    while (temp->next != startN)
    {
        temp = temp->next;
    }

    temp->next = NULL;
}

// Q6 REMOVE THE DUPLICATES FROM A SORTED LINKED LIST

Node *removeDuplicates(Node *head)
{
    if (head == NULL)
    {
        return head;
    }

    Node *curr = head;

    while (curr != NULL)
    {
        if ((curr->next != NULL) && curr->data == curr->next->data)
        {
            Node *next_next = curr->next->next;
            Node *nodeToDelete = curr->next;

            delete (nodeToDelete);
            curr->next = next_next;
        }

        else
        {
            curr = curr->next;
        }
    }

    return head;
}

// Q7 REMOVE THE DUPLICATED FROM A UNSORTED LINKED LIST

Node *removeDuplicatesUnsorted(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        Node *temp = curr->next;
        while (temp != NULL)
        {
            if (curr->data == temp->data)
            {
                Node *next_next = curr->next->next;
                Node *nodeToDelete = curr->next;

                delete (nodeToDelete);
                curr->next = next_next;
            }
            else
            {
                curr = curr->next;
            }
            temp = temp->next;
        }
        curr = curr->next;
    }

    return head;
}

Node *mapsUsing(Node *head)
{
    map<Node *, bool> visited;

    Node *curr = head;
    while (curr != NULL)
    {
        Node *temp = curr->next;
        if (visited[temp] == true)
        {
            Node *next_next = curr->next->next;
            Node *nodeToDelete = curr->next;
            delete (nodeToDelete);
            curr->next = next_next;
        }

        visited[temp] = true;
        curr = curr->next;
    }

    return head;
}

//Q8  SORT 0S 1S 2S IN LINKED LIST

Node *sorting0s(Node *&head)
{
    int zerocount = 0;
    int onecount = 0;
    int twocount = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zerocount++;
        }
        else if (temp->data == 1)
        {
            onecount++;
        }
        else if (temp->data == 2)
        {
            twocount++;
        }
        temp = temp->next;
    }

    temp = head;
    while (temp != NULL)
    {
        if (zerocount != 0)
        {
            temp->data = 0;
            zerocount--;
        }

        else if (onecount != 0)
        {
            temp->data = 1;
            onecount--;
        }
        else if (twocount != 0)
        {
            temp->data = 2;
            twocount--;
        }

        temp = temp->next;
    }

    return head;
}

void InsertAtTail2(Node *&tail, Node *&temp)
{
    tail->next = temp;
    tail = temp;
}

Node *sorting0sApproach2(Node *&head)
{
    Node *zerohead = new Node(-1);
    Node *zerotail = zerohead;
    Node *onehead = new Node(-1);
    Node *onetail = onehead;
    Node *twohead = new Node(-1);
    Node *twotail = twohead;

    // creating three separate nodes for 0,1,2.
    Node *temp = head;
    while (temp != NULL)
    {
        int val = temp->data;
        if (val == 0)
        {
            InsertAtTail2(zerotail, temp);
        }
        else if (val == 1)
        {
            InsertAtTail2(onetail, temp);
        }

        else if (val == 2)
        {
            InsertAtTail2(twotail, temp);
        }
    }

    // merging three lists.

    ///checking if 1s list is not empty
    if (onehead->next != NULL)
    {
        zerotail->next = onehead->next;
    }

    else 
    {
        zerotail->next = twohead->next;
    }

    onetail->next = twohead->next;
    twohead->next = NULL;

   ////setup head
    head = zerohead->next;

    delete zerohead;
    delete onehead;
    delete twohead;

    return head;
}


//Q9 MERGING 2 SORTED LINKED LISTS
Node * solve(Node* & first, Node *& second)
{
    Node *curr1 = first;
    Node * next1 = curr1->next;
    Node * curr2 = second;
    Node * next2 = curr2->next;

    if(next1==NULL)
    {
        curr1->next = curr2;
        return first;
    }

    while (next1!=NULL && curr2!=NULL)
    {
        if((curr2->data>=curr1->data) &&(curr2->data<=next1->data))
        {
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;
            curr1 = curr2;
            curr2 = next2;
        }

        else
        {
            curr1 = next1;
            next1 = next1->next;

            if(next1==NULL)
            {
                curr1->next = curr2;
                return first;
            }
        }
    }
    return first;
}

Node * mergeTwoSortedLists(Node* & first, Node *& second)
{
    if(first==NULL)
    {
        return second;
    }

    if(second==NULL)
    {
        return first;
    }

    if(first->data<=second->data)
    {
        return solve(first,second);
    }
    else
    {
        return solve(second,first);
    }
}

//Q10 CHECK THE PALINDROME IN A LIST OR NOT 

bool checkispalindrome(vector<int> arr)
{
    int n = arr.size();
    int s = 0;
    int e = n-1;

    while (s<=e)
    {
        if(arr[s]!=arr[e])
        {
            return 0;
        }

        s++;
        e--;
    }

    return 1;
    
}

bool ispalindrome(Node * & head)
{
    vector<int> arr;
    Node * temp = head;
    while(temp!=NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }

    return checkispalindrome(arr);
}

bool ispalindromeApp2(Node * head)
{
    if(head==NULL || head->next==NULL)
    {
        return true;
    }

    Node * mid = middle2(head);
    Node * temp = mid->next;
    mid->next = reverse1(temp);

    Node * head1 = head;
    Node * head2 = mid->next;

    while (head2!=NULL)
    {
        if(head1->data!=head2->data)
        {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    return true;
    
}

//Q11 ADD 2 NUMBERS 

Node * add(Node * first, Node * second)
{
    int carry = 0;
    Node * ansHead = 0;
    Node * ansTail = 0;
    int val1 = 0, val2 = 0;
    while (first!=NULL || second!=NULL || carry!=0)
    {
        if(first!=NULL)
        {
            val1 = first->data;
        }

        if(second!=NULL)
        {
            val2 = second->data;
        }

        int sum = carry+ val1 + val2;
        int digit = sum/10;
        InsertAtTail(ansHead,ansTail,digit);

        carry = sum/10;
    }

    return ansHead;
    
}

Node * addTwoLists(Node * first , Node * second)
{
    first = reverse1(first);
    second = reverse1(second);

    Node * ans = add(first, second);
    ans = reverse1(ans);

    return ans;
}

//Q12 MERGE SORT IN LINKED LIST

Node * merge(Node * &left,Node * & right)
{
    if(left==NULL)
    {
        return right;
    }
    if(right==NULL)
    {
        return left;
    }
    
    Node * ans = new Node (-1);
    Node * temp = ans;
    while (left!=NULL && right!=NULL)
    {
        if(left->data<=right->data)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while (left!=NULL)
    {
        temp->next = left;
        temp = left;
        left = left->next;
    }
    while (right!=NULL)
    {
        temp->next = right;
        temp = right;
        right = right->next;
    }
    
    ans = ans->next;
    return ans;
    
}
Node * mergesort(Node * & head)
{

    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    //step1 divide linked list into two halves.
    Node * mid = middle2(head);
    Node * left = head;
    Node *right = mid->next;
    mid->next = NULL;

    //sort two linked list .
    Node * left = mergesort(left);
    Node * right = mergesort(right);

    //merge two sorted linked list.
    Node * ans = merge(left,right);
    return ans;  

}

int main()
{
    Node *head1 = NULL;
    Node *tail1 = NULL;
    Node *head2 = NULL;
    Node *tail2 = NULL;

    // insertAtHead(head,tail, 2);
    // // print (head);
    // InsertAtTail(head,tail, 2000);
    // InsertAtTail(head,tail, 20);
    // // print (head);
    // InsertAtTail(head,tail, 20);

    // InsertAtTail(head,tail, 200);
    // // print (head);
    // InsertAtTail(head,tail, 200);
    // InsertAtTail(head,tail, 2000);
    // InsertAtTail(head,tail, 20);
    // InsertAtTail(head,tail, 2000);
    // // print (head);

    // InsertAtTail(head,tail, 20000);
    // print(head);

    // tail->next = head->next;    to make cycle

    // print(head);

    // head = reverseLinkedList(head);
    // print(head);

    // head = reverseKGroup(head,2);

    // if (IsCircular(head))
    // {
    //     cout << "Circular linked list" << endl;
    // }
    // else
    // {
    //     cout << "Not circular" << endl;
    // }

    // if(detectApp(head)==true)
    // {
    //     cout<<"Cycle is present"<<endl;
    // }
    // else
    // {
    //     cout<<"Cycle is not present"<<endl;
    // }

    // Node * start = startingNodeOfLoop(head);
    // cout<<start->data<<endl;

    // removeLoop(head);
    // print(head);

    // head = removeDuplicatesUnsorted(head);
    // print(head);


///for sorting wala part
    // InsertAtTail(head, tail, 0);
    // InsertAtTail(head, tail, 1);
    // InsertAtTail(head, tail, 2);

    // InsertAtTail(head, tail, 1);
    // InsertAtTail(head, tail, 2);
    // print(head);

    // head = sorting0sApproach2(head);
    // print(head);


//for merging code

    InsertAtTail(head1, tail1, 1);
    InsertAtTail(head1, tail1, 3);
    InsertAtTail(head1, tail1, 5);
    print(head1);

    InsertAtTail(head2, tail2, 2);
    InsertAtTail(head2, tail2, 4);
    InsertAtTail(head2, tail2, 5);
    print(head2);

    Node * ans = addTwoLists(head1,head2);
    print(ans);

    // head1 = mergeTwoSortedLists(head1,head2);
    // print(head1);

//palindrome or not
    // InsertAtTail(head1, tail1, 1);
    // InsertAtTail(head1, tail1, 3);
    // InsertAtTail(head1, tail1, 5);
    // InsertAtTail(head1, tail1, 5);
    // InsertAtTail(head1, tail1, 3);
    // InsertAtTail(head1, tail1, 1);
    // print(head1);

    // if(ispalindromeApp2(head1))

    // {
    //     cout<<"Palindrome"<<endl;
    // }
    // else
    // {
    //     cout<<"Not palindrome"<<endl;
    // }

    return 0;
}