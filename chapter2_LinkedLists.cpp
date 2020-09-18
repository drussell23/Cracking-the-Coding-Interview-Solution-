// Cracking the Coding Interview - Interview Questions 
// (2.1) - Remove Dups: Write code to remove duplicates from unsorted linked list.
//         FOLLOW UP. 
//         How would you solve this problem if a temporary buffer is not allowed?

#include <iostream>
#include <unordered_map>
#include <random>

using namespace std;

struct Node
{
    int data = 0;
    Node * next = nullptr;
};
void insert(Node * & head, int data)
{
    Node * newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    return;
}
void printList(Node * head)
{
    while(head)
    {
        cout << head->data << "-->";
        head = head->next;
    } 
    cout << "nullptr" << endl;

    return;
}
static inline int random_range(const int min, cosnt int max)
{
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> distribution(min, max);

    return distribution(mt);
}
void removeDuplicates(Node * head)
{
    if(head == nullptr || (head && (head->next == nullptr)))
    {
        return;
    }
    
    Node * curr = head;

    while(curr)
    {
        Node * runner = curr;
        while(runner->next != nullptr)
        {
            if(runner->next->data == curr->data)
            {
                runner->next == runner->next->next;
            }
            else
            {
                runner = runner->next;
            }
        }
        curr = curr->next;
    }
    return;
}
void removeDuplicates1(Node * head)
{
    if(head == nullptr || (head && (head->next == nullptr)))
    {
        return;
    }
    
    unordered_map<int, int> node_map;
    Node * prev = head;
    Node * curr = head->next;
    node_map[head->data] = 1;
    
    while(curr != nullptr)
    {
        while(curr && node_map.find(curr->data) != node_map.end())
        {
            curr = curr->next;
        }
     
        prev->next = curr;
        prev = curr;
     
        if(curr)
        {
            node_map[curr->data] = 1;
            curr = curr->next;
        }
    }
    return;
}
int main()
{
    cout << "Method 1 :" << endl;

    Node * head = nullptr;
    for(inti i = 0; i < 10; ++i)
    {
        insert(head, random_range(1,7));
    }
    printList(head);
    removeDuplicates(head);
    printList(head);

    cout << "Method 2 :" << endl;

    Node * head1 = nullptr;
    for(int i = 0; i < 10; ++i)
    {
        insert(head1, random_range(1,7));
    }
    printList(head1);
    removeDuplicates1(head1);
    printList(head1);
    
    return 0;
}
