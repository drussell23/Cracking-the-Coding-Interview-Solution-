// Cracking the Coding Interview - Interview Questions 
// (2.3) - Delete Middle Node: Implement an algorithm to delete a node in the middle (i.e., any node but
//         the first and last node, not necessarily the exact middle) of a singly linked list, given only access to 
//         that node. 

//         EXAMPLE
//         Input: the node c from the linked list a->b->c->d->e->f
//         Result: nothing is returned, but the new linked list looks like a->b->d->e->f

// Solution - In this problem, you are not given access to the head of the linked list. You only have access to
//            that node. The solution is simply to copy the data from the next node over to the current node, 
//            and then to delete the next node.
/*
    bool deleteNode(LinkedListNode n)
    {
        if(n == nullptr || n.next == nullptr)
        {
            return false; // Failure. 
        }
        LinkedListNode next = n.next;
        n.data = next.data;
        n.next = next.next;
        return true;
    }
*/
#include <iostream>
#include <cstddef>

using namespace std;

struct Node
{
    char data;
    Node * next;
    Node(char c) : data{ c }, next{ nullptr } { }
};
// printList - Helper routine to print the list.
// head [head of the list]
void printList(Node * head)
{
    while(head)
    {
        cout << head->data << " -->";
        head = head->next;
    }
    cout << "nullptr" << endl;
}
// deleteNode - delete the "node" from the list.
// node [node to be deleted]
void deleteNode(Node * node)
{
    if(node == nullptr || node->next == nullptr)
    {
        return;
    }
    Node * nextNode = node->next;
    node->data = nextNode->data;
    node->next = nextNode->next;
    delete nextNode;
}
int main()
{
    Node * head = new Node('a');
    head->next = new Node('b');
    head->next->next = new Node('c');
    head->next->next->next = new Node('d');
    head->next->next->next->next = new Node('e');
    
    cout << "List before deletion:" << endl;

    printList(head);

    cout << "Deleting node containing data as 'c'" << endl;

    deleteNode(head->next->next);

    cout << "List after deletion:" << endl;

    printList(head);

    return 0;
}