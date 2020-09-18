// Simple Append Operation on a Linked List. 
// This program demonstrates a simple append operation on a linked list. 

/*
    - In this section we will develop an abstract data type (ADT) that performs basic linked list
      operations using the ListNode structure and head pointer defined in the previous section. We
      will use the following class declaration, which is stored in NumberList.h.
*/
#include <iostream>

using namespace std;

class NumberList
{
    private: 
            // Declare a structure for the list.
            struct ListNode
            {
                double value;            // The value in this node.
                struct ListNode * next;  // To point to the next node. 
            };
            ListNode * head; // List head pointer.

    public:
           NumberList() // Constructor.
           {
               /*
                    - Notice that the constructor initializes the head pointer to nullptr. This establishes an 
                      empty linked list. The class has member functions for appending, inserting, and deleting 
                      nodes, as well as a displayList function that displays all the values stored in the list. 
               */
               head = nullptr;
           }
           
           ~NumberList(); // Destructor: The destructor destroys the list by deleting all its nodes.

           // Linked List operations. 
           void appendNode(double);
           void insertNode(double);
           void deleteNode(double);
           void displayList() const;
};
void NumberList::appendNode(double num)
{
   /*
        - The newNode pointer will be used to allocate and point to the new node. 
          The nodePtr pointer will be used to travel down the linked list, in 
          search of the last node.
   */
    ListNode * newNode; // To point to a new node.
    ListNode * nodePtr; // To move through the list. 

    // Allocate a new node and store num there.
    newNode = new ListNode;
    newNode->value = num;
    newNode->next = nullptr; //This node will become the last node in the list, its next pointer must be a null pointer. 

    // If there are no nodes in the list, make newNode the the first node.
    /*
        - We test the head pointer to determine whether there are any nodes already in the list.
          If head ponits to nullptr, we make the new node the first in the list. Making head
          point to the new node does this.
    */
    if(!head)
    {
        head = newNode;
    }
    /*
        - If head does not point to nullptr, however, there are nodes in the list. The else part of 
          the if statement must contain code to find the end of the list and insert the new node.
    */
    else // Otherwise, insert newNode at end.
    {
        // Initialize nodePtr to head of list.
        nodePtr = head;

        /*
            - The while loop is used to traverse (or travel through) the list searching for the last node.
              The last node will be the one whose next member points to nullptr.
        */
        // Find the last node in the list. 
        while (nodePtr->next)
            nodePtr = nodePtr->next; // When nodePtr points to the last node in the list, we make its next number point to newNode.

        // Insert newNode as the last node.
        nodePtr->next = newNode;
    }
}
void NumberList::displayList() const
{
    // Traversing a Linked List

    /*
        - The appendNode function demonstrated in the previous section contains a while loop 
          that traverses, or travels through the linked list. In this section, we will demonstrate
          the displayList member function that traverses the list, displaying the value member of
          each node. 
    */
    
    ListNode * nodePtr; // To move through the list.

    // Position nodePtr at the head of the list. 
    nodePtr = head;

    // While nodePtr points to a node, traverse the list.
    while(nodePtr)
    {
        // Display the value in this node.
        cout << nodePtr->value << endl;

        // Move to the next node.
        nodePtr = nodePtr->next;
    }
}
void NumberList::insertNode(double num)
{
    ListNode * newNode;                 // A new node.
    ListNode * nodePtr;                 // To traverse the list.
    ListNode * previousNode = nullptr;  // The previous node.

    // Allocate a new node and store num there. 
    newNode = new ListNode;
    newNode->value = num;

    // If there are no nodes in the list make newNode the first node.
    if(!head)
    {
        head = newNode;
        newNode->next = nullptr;
    }
    else // Otherwise, insert newNode.
    {
        // Position nodePtr at the head of list.
        nodePtr = head;

        // Initialize previousNode to nullptr. 
        previousNode = nullptr;

        // Skip all nodes whose value is less than num.
        while(nodePtr != nullptr && nodePtr->value < num)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        /*
            - If the new node is to be the 1st in the list, 
              insert it before all other nodes.
        */
       if(previousNode == nullptr)
       {
           head = newNode;
           newNode->next = nodePtr;
       }
       else // Otherwise insert after the previous node.
       {
           previousNode->next = newNode;
           newNode->next = nodePtr;
       }
    }
}
void NumberList::deleteNode(double num)
{
    ListNode * nodePtr;         // To traverse the list.
    ListNode * previousNode;    // To point to the previous node.

    // If the list is empty, do nothing.
    if(!head)
        return;

    // Determine if the first node is the one. 
    if(head->value == num)
    {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }
    else
    {
        // Initialize nodePtr to head of list.
        nodePtr = head;

        // Skip all nodes whose value is not equal to num.
        while(nodePtr != nullptr && nodePtr->value != num)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        /*
            - If nodePtr is not at the end of the list, 
              link the previous node to the node after
              nodePtr, then delete nodePtr.
        */
       if(nodePtr)
       {
           previousNode->next = nodePtr->next;
           delete nodePtr;
       }
    }
}
NumberList::~NumberList()
{
    ListNode * nodePtr;     // To traverse the list.
    ListNode * nextNode;    // To point to the next node.

    // Position nodePtr at the head of the list.
    nodePtr = head;

    // While nodePtr is not at the end of the list...
    while(nodePtr != nullptr)
    {
        // Save a pointer to the next node.
        nextNode = nodePtr->next;

        // Delete the current node.
        delete nodePtr;

        // Position nodePtr at the next node.
        nodePtr = nextNode;
    }
}
int main()
{
    // Define a NumberList object.
    NumberList list;

    // Append some values to the list.
    list.appendNode(2.5);
    list.appendNode(7.9);
    list.appendNode(12.6);

    // Insert a node in the middle of the list.
    list.insertNode(10.5);

    // Display the list.
    cout << "Here are the initial values:" << endl;
    list.displayList();
    cout << endl;

    // Delete the middle node.
    cout << "Now deleting the node in the middle." << endl;
    list.deleteNode(7.9);

    // Display the list.
    cout << "Here are the noddes left." << endl;
    list.displayList();
    cout << endl;

    // Display the last node.
    cout << "Now deleting the last node." << endl;
    list.deleteNode(12.6);

    // Display the list.
    cout << "Here are the nodes left." << endl;
    list.displayList();
    cout << endl;

    // Delete the only node left in the list.
    cout << "Now deleting the only remaining node." << endl;
    list.deleteNode(2.5);

    // Display the list.
    cout << "Here are the nodes left." << endl;
    list.displayList();

    return 0;
}