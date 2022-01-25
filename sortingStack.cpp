// Recursive sorting algorithm on stack(decreasing order) 

#include <iostream>
#include <stack>
#include <climits>

void sort(std::stack<int>& stack, int size) {
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

int main()
{
    std::stack<int> stack;
    stack.push(99);
    stack.push(877);
    stack.push(76);
    stack.push(1);
    stack.push(0);
    stack.push(77);
    stack.push(-99);
    stack.push(-787);
    stack.push(88);
    sort(stack, stack.size());
    std::cout << stack.top() << std::endl;
}