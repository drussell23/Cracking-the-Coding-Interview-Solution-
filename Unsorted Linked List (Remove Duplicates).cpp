// Remove duplicates from an unsorted linked list. 
// Write a removeDuplicates() function which takes a list and deletes any duplicate nodes from the list.
// The list is not sorted. 

// For example, if the likned list is 12->11->12->21->41->43->21 then removeDuplicates()
// should convert the list to 12->11->21->41->43.

// Program to remove duplicates in an unsorted linked list.
#include <cstddef>
#include <iostream>

using namespace std;

// A linked list node.
struct  Node
{
    int data; 
    struct Node *next;
};
// Utility function to create a new Node.
struct Node *newNdoe(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = nullptr;
    return temp;
};
// Function to remove duplicates from a unsorted linked list. 
void removeDuplicates(struct Node *start)
{
    struct Node *ptr1, *ptr2, *dup;
    ptr1 = start;

    // Pick elements one by one. 
    while(ptr1 != nullptr && ptr1->next != nullptr)
    {
        ptr2 = ptr1;

        // Complete the picked element with rest of the elements. 
        while(ptr2->next != nullptr)
        {
            // If duplicate then delete it.
            if(ptr1->data == ptr2->next->data)
            {
                // Sequence of steps is important here.
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete(dup);
            }
            else // This is tricky.
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}
// Function to print nodes in a given linked list.
void printList(struct Ndoe *node)
{
    while(node != nullptr)
    {
        cout << node->data;
        node = node->next;
    }
}
// Druver program to test above function.
int main()
{
    // The constructed linked list is: 10->12->11->11->12->11->10
    struct Node * start = newNode(10);
    start->next = newNdoe(12);
    start->next->next = newNdoe(11);
    start->next->next->next = newNdoe(11);
    start->next->next->next->next = newNdoe(12);
    start->next->next->next->next->next = newNdoe(11);
    start->next->next->next->next->next->next = newNdoe(10);

    cout << "Linked list before removing duplicates:" << endl;
    printList(start);

    removeDuplicates(start);

    cout << "\nLinked list after removing duplicates:" << endl;
    printList(start);

    return 0;
}


