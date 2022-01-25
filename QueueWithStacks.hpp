// Queue represented in combination of two stacks

#ifndef QUEUEWITHSTACKS_H_
#define QUEUEWITHSTACKS_H_

#include <iostream>
#include <stack>

template<typename T>
class MyQueue {
public:
    // Member functions
    MyQueue() = default;
    MyQueue(const MyQueue& other) {
        main_stack = other.main_stack;
        helper_stack = other.helper_stack;
    }
    MyQueue(MyQueue&& other) {
        main_stack = std::move(other.main_stack);
        helper_stack = std::move(other.helper_stack);
    }
    MyQueue& operator=(const MyQueue& other) {
        if (this == &other) { return *this; }
        main_stack = other.main_stack;
        helper_stack = other.helper_stack;
        return *this;
    }
    MyQueue& operator=(MyQueue&& other) {
        if (this == &other) { return *this; }
        main_stack = std::move(other.main_stack);
        helper_stack = std::move(other.helper_stack);
        return *this;
    }
    // Element access
    T front() {
        while(!main_stack.empty()) {
            helper_stack.push(main_stack.top());
            main_stack.pop();
        }
        T tmp = helper_stack.top();
        while(!helper_stack.empty()) {
            main_stack.push(helper_stack.top());
            helper_stack.pop();
        }
        return tmp;
    }
    T end() const {
        return main_stack.top();
    }
    // Capacity
    bool empty() const {
        return main_stack.empty();
    }
    size_t size() const {
        return main_stack.size();
    }
    // Modifiers
    void push(const T& value) {
        while (!main_stack.empty()) {
            helper_stack.push(main_stack.top());
            main_stack.pop();
        }
        main_stack.push(value);
        while (!helper_stack.empty()) {
            main_stack.push(helper_stack.top());
            helper_stack.pop();
        }
    }
    void pop() {
        main_stack.pop();
    }
private:
    std::stack<T> main_stack;
    std::stack<T> helper_stack;
};

#endif