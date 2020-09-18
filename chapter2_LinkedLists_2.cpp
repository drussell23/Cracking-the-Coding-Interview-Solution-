// (2.2) - Return Kth to Last: Implement an algorithm to find the kth to last element of a singly linked list. 

#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node * next;
    Node(int d) : data{ d }, next{ nullptr } { }
}
void insert(Node * & head, int data)
{
    Node * newNode = new Ndoe(data);
    newNode->next = head;
    head = newNode;
}
void deleteList(Node * & head)
{
    Node * nextNode;
    
    while(head)
    {
        nextNode = head->next;
        delete(head);
        head = nextNode;
    }
}
void printList(Node * head)
{
     // Helper routine to print the list. 
     // Current head of the list. 
    while(head)
    {
        cout << head->data << "-->";
        head = head->next;
    }
    cout << "null" << endl;
}
Node * kthToLastHelper(Node * head, int k, int & i)
{
    // kthToLastHelper - helper routine to find nth node for recursive approach.
    // head - head of the list.
    // k    - the k value for finding kth element from last of the list.
    // i    - an index maintained to keep track of current node. 
    if(head == nullptr)
    {
        return nullptr;
    }

    Node * node = kthToLastHelper(head->next, k, i);
    i += 1;

    // If we have solved problem k times from last. 
    if(i == k)
    {
        return head;
    }
    return node;
}
Node * kthToLastRecursive(Node * head, int k)
{
    // kthToLastRecursive - Recursive approach for finding kth to last element of list.
    // head     - head of node. 
    // k        - the k value for finding kth element from last of the list.
    // reutrn   - kth node from last. 
    int i = 0;
    return kthToLastHelper(head, k, i); 
}
Node * kthLastIterative(Node * head, int k)
{
    if(head == nullptr)
    {
        return head;
    }

    Node * ptr1 = head;
    Node * ptr2 = head;

    int i = 0;

    while(i < k && ptr1)
    {
        ptr1 = ptr1->next;
        ++i;
    }

    // Out of bounds.
    if(i < k)
    {
        return nullptr;
    }

    while (ptr1 != nullptr)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return ptr2;
}
int main()
{
    Node * head = nullptr;

    for(int i = 7; i > 0; i--)
    {
        insert(head, i);
    }
    
    cout << "List: ";
    printList(head);

    cout << "4th node from last (Recursive) : ";
    Node * node4 = kthToLastRecursive(head, 4);

    if(node4 != nullptr)
    {
        cout << node4->data << endl;
    }
    else
    {
        cout << "NULL NODE" << endl;
    }

    cout << " 4th node from last (Iterative) : ";

    node4 = kthLastIterative(head, 4);

    if(node4 != nullptr)
    {
        cout << node4->data << endl;
    }
    else
    {
        cout << "NULL NODE" << endl;    
    }

    deleteList(head);

    return 0;
    
    
}
