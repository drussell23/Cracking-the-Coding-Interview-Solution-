// Cracking the Coding Interview - Interview Questions
/*
    (3.2) - Stack Min: How would you design a stack which, in addition to push and pop, has a function min
            which returns the minimum element? Push, pop and min should all operate in O(1) time.
*/
#include <iostream>
#include <cstdlib>
#include <utility>

using namespace std;

template<typename T>
class Stack
{
    public:
            Stack() : top(nullptr), stackSize(0)
            {

            }
            Stack(Stack && other) : top(move(other.top)), stackSize(move(other.stackSize))
            {

            }
            ~Stack()
            {
                while(!isEmpty())
                    pop();
            }
            template <typename U>
            void push(U && value)
            {
                auto n = new Node(forward<U>(value), top);
                top = n;
                ++stackSize;
            }
            T & peek()
            {
                if(!top)
                    throw StackIsEmptyException();
                return (top->value);
            }
            T pop()
            {
                if(!top)
                    throw StackIsEmptyException();
                auto value(move(top->value));
                auto n = top;
                top = n->next;
                delete n;
                --stackSize;
                return value;
            }
            bool isEmpty() const
            {
                return (!top);
            }
            size_t size() const
            {
                return stackSize;
            }
            class StackIsEmptyException
            {

            };

    private:
            struct Node
            {
                Node(T && v, Node * n) : value(move(v)), next(n)
                {

                }
                Node(const T &v, Node * n) : value(v), next(n)
                {

                }
                T value;
                Node * next;
            };
            Node * top;
            size_t stackSize;
};
class Stack;

class StackNode
{
    private:
            int data;
            StackNode * next;
            StackNode * minimum;

    public:
            friend class Stack;
            StackNode(int data, StackNode * next);
};
template<typename T>
class StackMin
{
    public:
            template<typename U>
            void push(U && value)
            {
                if(minStack.isEmpty() || value <= minStack.peek())
                    minStack.push(value);
                stack.push(forward<U>(value));
            }
            T & peek()
            {
                return (stack.peek());
            }
            T & min()
            {
                return (minStack.peek());
            }
            T pop()
            {
                auto value = stack.pop();

                if(value == min())
                    minStack.pop();
                return value;
            }
            bool isEmpty()
            {
                return stack.isEmpty();
            }

    private:
            Stack<T> stack;
            Stack<T> minStack;
};
template<typename T>
class Stack_1
{
    public:
            Stack_1() : top(nullptr), stackSize(0) {}
            Stack_1(Stack && other) : top(move(other.top)), stackSize(move(other.stackSize)) {}
            ~Stack_1()
            {
                while(!isEmpty())
                    pop();
            }
            template<typename U>
            void push(U && value)
            {
                auto n = new Node(forward<U>(value), top);
                top = n;
                ++stackSize;
            }
            T & peek()
            {
                if(!top())
                    throw StackIsEmptyException();
                return top->value;
            }
            T pop()
            {
                if(!top)
                    throw StackIsEmptyException();
                auto value(move(top->value));
                auto n = top;
                top = n->next;
                delete n;
                --stackSize;
                return value;
            }
            bool isEmpty() const
            {
                return !top;
            }
            size_t size() const
            {
                return stackSize;
            }
            class StackIsEmptyException
            {

            };

    private:
            struct Node
            {
                Node(T && v, Node *n) : value(move(v)), next(n) {}
                Node(const T & v, Node * n) : value(v), next(n) {}
                T value;
                Node * next;
            };
            Node * top;
            size_t stackSize;
};
Stack::Stack()
{
    head = nullptr;
    stackSize = 0;
}
Stack::~Stack()
{
    StackNode * discard;

    while(head != nullptr)
    {
        discard = head;
        head = head->next;
        delete discard;
    }
}
void Stack::push(int item)
{
    if(isEmpty())
    {
        head = new StackNode(item, nullptr);
        head->minimum = head;
    }
    else if(item <= head->minimum->data)
    {
        head = new StackNode(item, head);
        head->minimum = head;
    }
    else
    {
        head = new StackNode(item, head);
        head->minimum = head->next->minimum;
    }
    stackSize++;
}
void Stack::pop()
{
    if(stacSize == 0 || head == nullptr)
        return;

    StackNode * discard = head;
    head = head->next;
    delete discard;
    stackSize--;
}
int Stack::top()const
{
    // Or throw an exception.
    if(stackSize == 0 || head == nullptr)
    {
        cout << "Stack is empty." << endl;
        exit(1);
    }
    return (head->data);
}
int Stack::getMinimum() const
{
    // Or throw an exception.
    if(stackSize == 0 || head == nullptr)
    {
        cout << "Stack is empty." << endl;
        exit(1);
    }
    return (head->minimum->data);
}
bool Stack::isEmpty() const
{
    return (stackSize == 0 || head == nullptr);
}
int Stack::getSize() const
{
    return (stackSize);
}
StackNode::StackNode(int data, StackNode * next)
{
    this->data = data;
    this->next = next;
    minimum = nullptr;
}
int main()
{
    StackMin<int> stack;

    for(auto v: {5, 10, 4, 9, 3, 3, 8, 2, 2, 7, 6})
    {
        stack.push(v);
        cout << "Pushed value: " << v << ", min value: " << stack.min() << endl;
    }
    while(!stack.isEmpty())
    {
        auto v = stack.pop();

        cout << "Popped value: " << v;

        if(stack.isEmpty())
            cout << ", stack is empty" << endl;
        else
            cout << ", min value: " << stack.min() << endl;
    }
    return 0;
}
