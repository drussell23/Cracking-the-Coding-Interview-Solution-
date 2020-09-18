// Starting out with >>> C++ From Control Structures through Objects - (8th Edition)
// Chapter 18 - Stacks and Queues 
/*
    1. Static Stack Template 
        - Write your own version of a class template that will create a static stack of any data
          type. Demonstrate the class with a driver program. 
*/
#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <string>

using namespace std;

// Stack template.
template <class Static_Stack_Template>
class Stack
{
    private:
            Static_Stack_Template * stackArray;
            int stackSize, top;
    
    public:
            Stack(int); // Constructor.
            Stack(const Stack &); // Copy constructor.
            ~Stack(); // Destructor.

            // Stack operations. 
            void push(Static_Stack_Template);
            void pop(Static_Stack_Template &);
            bool isFull();
            bool isEmpty();
};
// Constructor.
template <class Static_Stack_Template>
Stack<Static_Stack_Template>::Stack(int size)
{
    stackArray = new Static_Stack_Template[size];
    stackSize = size;
    top = -1;
}
// Copy constructor.
template <class Static_Stack_Template>
Stack<Static_Stack_Template>::Stack(const Stack & object)
{
    // Create the stack array.
    if(object.stackSize > 0)
        stackArray = new Static_Stack_Template[object.stackSize];
    else
        stackArray = nullptr;

    // Copy the stackSize attribute.
    stackSize = object.stackSize;

    // Copy the stack contents.
    for(int count = 0; count < stackSize; count++)
        stackArray[count] = object.stackArray[count];
    
    // Set the top of the stack.
    top = object.top;
}
// Destructor. 
template <class Static_Stack_Template>
Stack<Static_Static_Template>::~Stack()
{
    if(stackSize > 0)
        delete [] stackArray;
}
// Member function push pushes the argument onto the stack.
template < class Static_Stack_Template>::push(Static_Stack_Template item)
{
    if(isFull())
    {
        cout << "The stack is full." << endl;
    }
    else
    {
        top++;
        stackArray[top] = item;
    }
}
/*
    - Member function pop pops the value at the top 
      of the stack off, and copies it into the variable 
      passed as an argument.
*/
template <class Static_Stack_Template>
void Stack<Static_Stack_Template>::pop(Static_Stack_Template & item)
{
    if(isEmpty())
    {
        cout << "The stack is empty." << endl;
    }
    else
    {
        item = stackArray[top];
        top--;
    }
}
// Member function isFull returns true if the stack is full, or false otherwise.
template <class Static_Stack_Template>
bool Stack<Static_Stack_Template>::isFull()
{
    bool status;

    if(top == stackSize - 1)
        status = true;
    else
        status = false;
    
    return status;
}
// Member function isEmpty returns true if the stack is empty, or false otherwise.
template <class Static_Stack_Template>
bool Stack<Static_Stack_Template>::isEmpty()
{
    bool status;

    if (top == -1)
        status = true;
    else
        status = false;
    return status;
}
#endif

// Constants for the menu choices.
const int PUSH_CHOICE = 1, POP_CHOICE = 2, QUIT_CHOICE = 3;

// Function Prototypes.
void menu(int &);
void getStackSize(int &);
void pushItem(Stack<string> &);
void popItem(Stack<string> &);

/* The menu function displays the menu and gets the user's 
   choice, which is assigned to the reference parameter. */
void menu(int & choice)
{
    // Display the menu and get the user's choice.
    cout << "\nWhat do you want to do?\n" << PUSH_CHOICE 
         << " - Push an item onto the stack\n" << POP_CHOICE 
         << " - Pop an item off the stack\n" << QUIT_CHOICE 
         << " - Quit the program\n" 
         << "Enter your choice: ";
    
    cin >> choice;

    // Validate the choices.
    while(choice < PUSH_CHOICE || choice > QUIT_CHOICE)
    {
        cout << "Enter a valid choice: ";
        cin >> choice;
    }
}
/* The getStackSize function get the desired stack
   size, which is assigned to the reference parameter. */
void getStackSize(int & size)
{
    // Get the desired stack size.
    cout << "How big should I make the stack? ";
    cin >> size;

    // Validate the size.
    while(size < 1)
    {
        cout << "Enter 1 or greater: ";
        cin >> size;
    }
}
/* The pushItem function gets an item from the 
   user and pushes it onto the stack. */
void pushItem(Stack<string> & stack)
{
    string item;

    // Get an item to push onto the stack.
    cin.ignore();

    cout << "\nEnter an item: ";
    getline(cin, item);
    stack.push(item);
}
// The popItem function pops an item from the stack.
void popItem(Stack<string> & stack)
{
    string item = "";

    // Pop the item. 
    stack.pop(item);

    // Display the item. 
    if(item != "")
    cout << item << " was popped.\n";
}
int main()
{
    int stackSize;  // The stack size.
    int choice;     // To hold a menu choice.

    // Get the stack size.
    getStackSize(stackSize);

    // Create the stack.
    Stack<string> stack(stackSize);

    do
    {
        // Get the user's menu choice.
        menu(choice);

        // Perform the user's choice.
        if(choice != QUIT_CHOICE)
        {
            switch(choice)
            {
                case PUSH_CHOICE:
                    pushItem(stack);
                    break;
                
                case POP_CHOICE:
                popItem(stack);
            }
        }
    } while(choice != QUIT_CHOICE);
    
    return 0;
}
