// Cracking the Coding Interview - Interview Questions
/* 
    (2.7) - Intersection: Given two (singly) linked lists, determine if the two lists intersect.
           Return the intersecting node. Note that the intersection is defined based on reference,
           not value. That is, if the kth node of the first linked list is the exact same node
           (by reference) as the jth node of the second linked list, then they are intersecting.
*/
/*
    - Given two linked lists, if they both intersect at some point.
      Find out the intersecting point else return nullptr.
      Intersection is defined based on reference not value.
*/
#include <iostream>
#include <cmath>

using namespace std;

struct Node
{
    int data;
    Node * next;
    Node(int d) : data { d }, next{ nullptr } { }
};
void printList(Node * head)
{
    while(head)
    {
        cout << head->data << "-->";
        head = head->next;
    }
    cout << "NULL" << endl << endl;
}
int listLen(Node * head)
{
    int count = 0;

    while(head)
    {
        head = head->next;
        count++;
    }
    return count;
}
Node * intersectionPoint(Node * head1, Node * head2)
{
    int len1 = listLen(head1);
    int len2 = listLen(head2);
    Node * ptr1 = (len1 > len2) ? head1 : head2;
    Node * ptr2 = (len1 > len2) ? head2 : head1;
    int i = 0;

    while(i < abs(len1 - len2) && ptr1)
    {
        ptr1 = ptr1->next;
        ++i;
    }
    while(ptr1 && ptr2)
    {
        if(ptr1 == ptr2)
        {
            return ptr1;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return nullptr;
}
int main()
{
    Node * list1 = new Node(3);
    list1->next = new Node(6);
    list1->next->next = new Node(9);
    list1->next->next->next = new Node(12);
    list1->next->next->next->next = new Node(15);
    list1->next->next->next->next->next = new Node(18);

    Node * list2 = new Node(7);
    list2->next = new Node(10);
    list2->next->next = list1->next->next->next;

    printList(list1);
    printList(list2);

    Node * intersectingNode = intersectionPoint(list1, list2);

    if(intersectingNode)
    {
        cout << "Intersecting Node of lists is: " << intersectingNode->data << endl;
    }
    else
    {
        cout << "Lists do not interest." << endl;
    }
    return 0;
}
