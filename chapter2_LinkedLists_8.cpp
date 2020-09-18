// Cracking the Coding Interview - Interview Questions
/* 
    (2.8) - Loop Detection: Given a circular linked list, implement an algorithm 
            that returns the node at the beginning of the loop.
    
    DEFINITION 
    ----------
                - Circular Linked List: A (corrupt) linked list in which a node's next 
                  pointer points to an earlier node, so as to make a loop in the linked
                  list.
    
    EXAMPLE
    -------
                - Input: A -> B -> C -> D -> E -> C [the same C as earlier]
                - Ouput: C
*/
#include <iostream>

using namespace std;

struct Node
{
    int data; 
    Node * next;
    Node (int d) : data{ d }, next{ nullptr } { }
};
void removeLoop(Node * loopNode, Node * head)
{
    Node * ptr1 = head;
    Node * ptr2 = loopNode;

    while(ptr1->next != ptr2->next)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    // ptr2 has reached start of loop, now removing the loop.
    ptr2->next = nullptr;
}
bool detectAndRemoveCycle(Node * head)
{
    if(head == nullptr)
    {
        return false;
    }
    Node * fastPtr = head;
    Node * slowPtr = head;

    while(slowPtr && fastPtr && fastPtr->next)
    {
        fastPtr = fastPtr->next->next;
        slowPtr = slowPtr->next;

        if(fastPtr == slowPtr)
        {
            removeLoop(slowPtr, head);
            return true;
        }
    }
    return false;
}
void insert(Node * & head, int data)
{
    Node * newNode = new Node(data);

    if(head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node * temp = head;

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void printList(Node * head)
{
    while(head)
    {
        cout << head->data << "-->";
        head = head->next;
    }
    cout << "NULL" << endl;
}
int main()
{
    Node * head = nullptr;

    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);

    cout << "Current List:" << endl;

    printList(head);

    cout << "Inserting loop, connecting 5 to 2" << endl;

    head->next->next->next->next->next = head->next;

    cout << "Detecting and deleting loop" << endl;

    detectAndRemoveCycle(head);

    cout << "Back to the same old list" << endl;

    printList(head);

    return 0;
}