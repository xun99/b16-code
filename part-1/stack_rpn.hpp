#ifndef __stack_rpn__
#define __stack_rpn__

#include "stack.hpp"
#include <cassert>
#include <functional>

// WRITE YOUR CODE HERE
template <typename T>
void plus(Stack<T> &stack)
{
    auto val1 = stack.top();
    stack.pop();
    auto val2 = stack.top();
    stack.pop();
    stack.push(val1 + val2);
}

template <typename T>
void minus(Stack<T> &stack)
{
    auto val1 = stack.top();
    stack.pop();
    auto val2 = stack.top();
    stack.pop();
    stack.push(val2 - val1);
}

template <typename T>
void multiplies(Stack<T> &stack)
{
    auto val1 = stack.top();
    stack.pop();
    auto val2 = stack.top();
    stack.pop();
    stack.push(val1 * val2);
}

template <typename T>
void divides(Stack<T> &stack)
{
    auto val1 = stack.top();
    stack.pop();
    auto val2 = stack.top();
    stack.pop();
    stack.push(val2 / val1);
}

// Overload the << operator to add elements to the stack
template <typename T>
Stack<T>& operator<<(Stack<T>& stack, void (*func)(Stack<T>&)) {
    func(stack);
    return stack;
}

// Overload the << operator to add elements to the stack
template <typename T>
Stack<T>& operator<<(Stack<T>& stack, const T& x) {
    stack.push(x);
    return stack;
}

#endif // __stack_rpn__