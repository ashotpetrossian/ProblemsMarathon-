// Recursive sorting algorithm on stack(decreasing order) 

#include <iostream>
#include <stack>
#include <climits>

void sort(std::stack<int>& stack, int size) { // stack size: pass with stack.size()
    if (size == 1) { return; }
    std::stack<int> helper;
    int max{INT_MIN};
    while (size != 0) {
        if (stack.top() > max) { max = stack.top(); }
        helper.push(stack.top());
        stack.pop();
        --size;
    }
    stack.push(max);
    while (!helper.empty()) {
        if (helper.top() == max) { 
            helper.pop(); 
            continue; 
        }
        stack.push(helper.top());
        helper.pop();
        ++size;
    }
    sort(stack, size);
}