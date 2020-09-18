// Cracking the Coding Interview - Interview Questions
// (2.6) - Palindrome: Implement a function to check if a linked list is a palindrome.

#include <iostream>
#include <stack>

using namespace std;

struct Node
{
    char data;
    Node * next;
    Node ( char c) : data { c }, next{ nullptr } { }
};
// insert helper routine to insert new node at head.
void insert(Node * & head, char c)
{
    Node * newNode = new Node(c);
    newNode->next = head;
    head = newNode;
}
// printList = helper routine to print the list.
void printList(Node * head)
{
    while(head)
    {
        cout << head->data << "-->";
        head = head->next;
    }
    cout << "NULL" << endl;
}
// reversed helper routine to reverse a list.
void reverse(Node * & head)
{
    if(head == nullptr || (head && (head->next == nullptr)))
    {
        return;
    }
    Node * newHead  = nullptr;
    Node * nextNode = nullptr;

    while (head)
    {
        nextNode = head->next;
        head->next = newHead;
        newHead = head;
        head = nextNode;
    }
    head = newHead;
}
// isPalindromeIter1 - Iteratively determine if list is palindrome using reversing the list.
bool isPalindromeIter1(Node * head)
{
    // If list is empty or just contains one node.
    if(head == nullptr || head->next == nullptr)
    {
        return true;
    }

    // Step 1 figure out middle node.
    Node * ptr1 = head;
    Node * ptr2 = head;
    Node * middleNode = nullptr;

    while(ptr2 && ptr1 && ptr1->next)
    {
        ptr1 = ptr1->next->next;
        ptr2 = ptr2->next;
    }

    // In case of odd number of nodes, skip the middle one.
    if(ptr1 && ptr1->next == nullptr)
    {
        ptr2 = ptr2->next;
    }

    // Reverse the second half of the list.
    reverse(ptr2);

    middleNode = ptr2;

    // Now compare the two halves.
    ptr1 = head;

    while(ptr1 && ptr2 && ptr1->data == ptr2->data)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    // Reverse the list again.
    reverse(middleNode);

    if(ptr2 == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// isPalindromeIter2 - Iteratively determine if list is palindrome using a stack.
bool isPalindromeIter2(Node * head)
{
    // If list is empty or just contains 1 node.
    if(head == nullptr || head->next == nullptr)
    {
        return true;
    }

    Node * ptr1 = head;
    Node * ptr2 = head;

    // Pushing the 1st half of list to stack.
    stack<Node *> nodeStack;

    while(ptr2 && ptr1 && ptr1->next)
    {
        ptr1 = ptr1->next->next;
        nodeStack.push(ptr2);
        ptr2 = ptr2->next;
    }

    // In case of odd number of nodes, skip the middle one.
    if(ptr1 && ptr1->next == nullptr)
    {
        ptr2 = ptr2->next;
    }

    /* Now compare the other half of the
       list with nodes we just pushed in stack. */

    while(!nodeStack.empty() && ptr2)
    {
        Node * current = nodeStack.top();
        nodeStack.pop();

        if(current->data != ptr2->data)
        {
            return false;
        }
        ptr2 = ptr2->next;
    }
    return true;
}
/*
    isPalindromeRecurHelper - Recursive approach to determine if list is palindrome.

    - Idea is to use two pointers left and right, we move left and right to reduce
      problem size in each recursive call, for a list to be palindrome, we need these
      two conditions to be true in each recursive call.

        a.) Data of left and right should match.
        b.) Remaining Sub-list is palindrome.

    - We are using function call stack for right to reach at last node and then compare
      it with first node (which is left).
*/
bool isPalindromeRecurHelper(Node * & left, Node * right)
{
    // Base case Stop when right becomes nullptr.
    if(right == nullptr)
    {
        return true;
    }

    // Rest of the list should be panlindrome.
    bool isPalindrome = isPalindromeRecurHelper(left, right->next);

    if(!isPalindrome)
    {
        return false;
    }

    // Check values at current node.
    isPalindrome = (left->data == right->data);

    // Move left to next for next call.
    left = left->next;

    return isPalindrome;
}
bool isPalindromeRecur(Node * head)
{
    return isPalindromeRecurHelper(head, head);
}
int main()
{
    Node * head1 = nullptr;

    insert(head1, 'a');
    insert(head1, 'b');
    insert(head1, 'c');
    insert(head1, 'c');
    insert(head1, 'b');
    insert(head1, 'a');

    cout << "List 1: ";

    printList(head1);

    if(isPalindromeIter1(head1))
    {
        cout << "List 1 is palindrome list." << endl;
    }
    else
    {
        cout << "List 1 is not a palindrome list." << endl;
    }

    cout << "List 1: ";
    printList(head1);
    cout << endl;

    Node * head2 = nullptr;

    insert(head2, 'r');
    insert(head2, 'a');
    insert(head2, 'd');
    insert(head2, 'a');
    insert(head2, 'r');

    cout << "List 2: ";
    printList(head2);

    if(isPalindromeIter2(head2))
    {
        cout << "List 2 is palindrome list." << endl;
    }
    else
    {
        cout << "List 2 is not a palindrome list." << endl;
    }

    cout << "List 2: ";
    printList(head2);
    cout << endl;

    Node * head = nullptr;

    insert(head, 'a');
    insert(head, 'b');
    insert(head, 'c');
    insert(head, 'd');
    insert(head, 'b');
    insert(head, 'd');

    cout << "List 3: ";
    printList(head);

    if(isPalindromeRecur(head))
    {
        cout << "List 3 is palindrome list." << endl;
    }
    else
    {
        cout << "List 3 is not a palindrome list." << endl;
    }
    cout << "List 3: ";
    printList(head);

    return 0;
}
