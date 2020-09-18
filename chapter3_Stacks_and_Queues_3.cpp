// Cracking the Coding Interview - Interview Questions
/*
    (3.3) - Stack of Plates: Imagine a (literal) stock of plates. If the stack gets too high, it might topple.
            Therefore, in real life, we would likely start a new stack when the previous stack exceeds some
            threshold. Implement a data structure SetOfStacks that mimics this. SetOfStacks should be
            composed of several stacks and should create a new stack once the previous one exceeds capacity.
            SetOfStacks.push() and SetOfStacks.pop() should behave identically to a single stack
            (that is, pop() should return the same values as it would if there were just a single stack).

            * FOLLOW UP
            * Implement a function popAt(int index) which performs a pop operation on a specific sub-stack.
*/
#include <iostream>
#include <deque>

using namespace std;

template <typename T, size_t Capacity>
class SetOfStacks
{
   public:
            template<typename U>
            void pus(U && value)
            {
                if(stacks.empty() || stacks.back().size() >= Capacity)
                    stacks.emplace_back(1, forward<U>(value));
                else
                    stacks.back().push_back(forward<U>(value));
            }
            T & peek()
            {
                return stacks.back().back();
            }
            T pop()
            {
                T value = stacks.back().back();
                stacks.back().pop_back();

                if(stacks.back().empty())
            }

    private:
            void shiftLeftTo(int index)
            {
                if(index == stacks.size() - 1)
                {
                    // Last Stack.
                    if(stacks.back().empty())
                        stacks.pop_back();
                }
                else
                {
                    stacks.[index].push_back(stacks[index + 1].front());
                    stacks.[index + 1].pop_front();
                    shiftLeftTo(index + 1);
                }
            }
            deque<deque<T>> stacks;
};
SetOfStacks::SetOfStacks(/* args */)    
{
}

SetOfStacks::~SetOfStacks()
{
}
