// Cracking the Coding Interview - Interview Questions
// (2.5) - Sum Lists: You have two numbers represented by a linked list, where each node contains a single 
//         digit. The digits are stored in reverse order, such that the 1's digit is at the head of the list. 
//         Write a function that adds the two numbers and returns the sum as a linked list. 
//         
//         EXAMPLE
//         Input: (7-> 1 -> 6) + (5 -> 9 -> 2). That is, 617 + 295.
//         Output: 2 -> 1 -> 9. That is, 912.
//         FOLLOW UP
//         Suppose the digits are stored in forward order. Repeat the above problem. 
//         EXAMPLE 
//         Input: (6 -> 1 -> 7) + (2 -> 9 -> 5). That is, 617 + 295.
//         Output: 9 -> 1 -> 2. That is, 912.

/*
    - Approach: 
                - We will solve the problem recursively and iteratively. 
                  Add numbers at same digits place, store the 1's digit of 
                  of the output in new list and add carry in next place's 
                  addition.
*/
#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node * next;
    Node( int d ) : data{ d }, next{ nullptr } { }
};
// insert - insert a new node at head of the list.
void insert (Node * & head, int data)
{
    Node * newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}
// printList - print the list.
void printList(Node * head)
{
    while(head)
    {
        cout << head->data << "-->";
        head = head->next;
    }
    cout << "nullptr" << endl;
}
// add_iterative - iterative approach to add two given lists.
Node * add_iterative(Node * list1, Node * list2)
{
    if(list1 == nullptr)
    {
        return list2;
    }
    if(list2 == nullptr)
    {
        return list1;
    }
    // list3 will store result.
    Node * list3 = nullptr;

    // For adding new nodes to tail of list3.
    Node * list3Tail = nullptr;

    int value = 0, carry = 0;

    while(list1 || list2)
    {
        // Add the values, if one of the list has already been traversed, add 0.
        value = carry + (list1 ? list1->data : 0) + (list2 ? list2->data : 0)

        // Get the new value and carry.
        if(value > 9)
        {
            carry = 1;
            value = value % 10;
        }
        else
        {
            carry = 0;
        }

        // New node.
        Node * temp = new Node(value);

        // If this is the first node, populate the result, else add to the tail.
        if(list3 == nullptr)
        {
            list3 = temp;
        }
        else
        {
            list3Tail->next = temp;
        }

        // Make new tail.
        list3Tail = temp;

        if(list1)
        {
            list1 = list1->next;
        }
        if(list2)
        {
            list2 = list2->next;
        }
    }
    if(carry > 0)
    {
        list3Tail->next = new Node(carry);
    }
    return list3;
}
// add_recursive - recursive addition of two lists.
Node * add_recursive(Node * list1, Node * list2, int carry)
{
    if(list1 = nullptr && list2 == nullptr && carry == 0)
    {
        return nullptr;
    }
    int value = carry;

    if(list1)
    {
        value += list1->data;
    }
    if(list2)
    {
        value += list2->data;
    }
    
    Node * resultNode = new Node(value % 10);

    resultNode->next = add_recursive(list1 ? (list1->next) : nullptr, 
                                     list2 ? (list2->next) : nullptr, 
                                     value > 9 ? 1 : 0);
    return resultNode;
}
// padList - Helper routine for padding the shorter list.
void padList(Node * & list, int padding)
{
    for(int i = 0; i < padding; ++i)
    {
        insert(list, 0);
    }
}
// length - helper routine to return length of list.
int length(Node * head)
{
    int len = 0;

    while(head)
    {
        len++;
        head = head->next;
    }
    return len;
}
Node * add_followup_helper(Node * list1, Node * list2, int & carry)
{
    if(list1 == nullptr && list2 == nullptr && carry == 0)
    {
        return nullptr;
    }
    Node * result = add_followup_helper(list1 ? (list1->next) : nullptr, 
                                        list2 ? (list2->next) : nullptr, 
                                        carry);
    
    int value = carry + (list1 ? list1->data : 0) + (list2 ? list2->data : 0);
    insert(result, value % 10);
    carry = (value > 9) ? 1 : 0;
    return result;
}
// add_followup - adding list such that 1's digit is at tail (follow up part of question)
Node * add_followup(Node * list1, Node * list2)
{
    int len1 = length(list1);
    int len2 = length(list2);

    // Pad the smaller list.
    if(len1 > len2)
    {
        padList(list2, len1 - len2);
    }
    else
    {
        padList(list1, len2 - len1);
    }
    int carry = 0;
    Node * list3 = add_followup_helper(list1, list2, carry);

    if(carry)
    {
        insert(list3, carry);
    }
    return list3;
}
void deleteList(Node * & head)
{
    Node * nextNode;
    while (head)
    {
        nextNode = head->next;
        delete (head);
        head = nextNode;
    }
}
int main()
{
    // Making list 1 for number 617.
    Node * list1 = nullptr;
    insert(list1, 6);
    insert(list1, 1);
    insert(list1, 7);
    cout << "List1: ";
    printList(list1);

    // Making list2 for number 295.
    Node * list2 = nullptr;
    insert(list2, 2);
    insert(list2, 9);
    insert(list2, 5);
    cout << "List2: ";
    printList(list2);

    Node * list3 = add_iterative(list1, list2);
    cout << "Iterative Solution: " << endl;
    cout << "List3: ";
    printList(list3);

    Node * list4 = add_recursive(list1, list2, 0);
    cout << "Recursive Solution: " << endl;
    cout << "List4: ";
    printList(list4);

    deleteList(list1);
    deleteList(list2);
    deleteList(list3);
    deleteList(list4);

    cout << "\n\nNow follow up case, lists are stored such that 1's digit is at the tail of list" << endl;
    // Node * listx = nullptr;

    insert(list1, 4);
    insert(list1, 3);
    insert(list1, 2);
    insert(list1, 9);
    cout << "List1: ";
    printList(list1);

    insert(list2, 9);
    insert(list2, 9);
    insert(list2, 8);
    cout << "List2: ";
    printList(list2);

    list3 = add_followup(list1, list2);
    cout << "Adding two above lists." << endl;
    cout << "List3: ";
    printList(list3);

    deleteList(list1);
    deleteList(list2);
    deleteList(list3);

    return 0;
}