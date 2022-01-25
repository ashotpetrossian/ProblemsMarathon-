// Stack with min() function

#ifndef STACKWITHMIN_H_
#define STACKWITHMIN_H_

#include <iostream>
#include <vector>
#include <set>

template<typename T>
class Stack {
public:
    // Member functions
    Stack() : m_size(0), m_vec(m_size) { }
    Stack(size_t size) : m_size(size), m_vec(m_size) { }
    Stack(const Stack<T>& other) {
        this->m_size = other.m_size;
        this->m_vec = other.m_vec;
    }
    Stack(Stack<T>&& other) {
        this->m_size = other.m_size;
        this->m_vec = other.m_vec;
        other.m_size = 0;
        other->m_vec.clear();
    }
    Stack& operator=(const Stack<T>& other) {
        if (this == &other) { return *this; }
        this->m_size = other.m_size;
        this->m_vec = other.m_vec;
        return *this;
    }
    Stack& operator=(Stack<T>&& other) {
        if (this == &other) { return *this; }
        this->m_size = other.m_size;
        this->m_vec = other.m_vec;
        other->m_size = 0;
        other.m_vec.clear();
        return *this;
    }
    // Element access
    T& top() {
        if (this->empty()) { throw ("The stack is empty\n"); }
        return m_vec[m_size - 1];
    }
    const T& top() const {
        if (this->empty()) { throw ("The stack is empty\n"); }
        return m_vec[m_size - 1];
    }
    // returns the min value of the Stack
    const T& min() const {
        return min_vec[min_vec.size() - 1];
    }
    // Capacity
    bool empty() const {
        return (m_size == 0);
    }
    size_t size() const {
        return m_size;
    }
    // Modifiers
    void push(const T& value) {
        if (min_vec.empty()) {
            min_vec.push_back(value);
        } else {
            if (min_vec[min_vec.size() - 1] > value) {
                min_vec.push_back(value);
            }
        }
        m_vec.push_back(value);
        ++m_size;
    }
    void push(T&& value) {
        if (min_vec.empty()) {
            min_vec.push_back(value);
        } else {
            if (min_vec[min_vec.size() - 1] > value) {
                min_vec.push_back(value);
            }
        }
        m_vec.push_back(std::move(value));
        ++m_size;
    }
    void emplace(T&& value) {
        if (min_vec.empty()) {
            min_vec.push_back(value);
        } else {
            if (min_vec[min_vec.size() - 1] > value) {
                min_vec.push_back(value);
            }
        }
        m_vec.push_back(std::move(value));
        ++m_size;
    }
    void pop() {
        if (m_vec[m_vec.size() - 1] == min_vec[min_vec.size() - 1]) {
            min_vec.pop_back();
        }
        m_vec.pop_back();
        --m_size;
    }
    void swap(Stack<T>& other) noexcept {
        using std::swap;
        swap(*this, other);
    }
    friend void swap(Stack<T>& one, Stack<T>& another) noexcept {
        Stack<T> tmp(one);
        one = another;
        another = tmp;
    }
    // Non-member functions
    bool operator==(const Stack<T>& other) {
        return (*this.m_vec == other.m_vec);
    }
    bool operator!=(const Stack<T>& other) {
        return (*this.m_vec != other.m_vec);
    }
    bool operator>(const Stack<T>& other) {
        return (*this.m_vec > other.m_vec);
    }
    bool operator<(const Stack<T>& other) {
        return (*this.m_vec < other.m_vec);
    }
    bool operator>=(const Stack<T>& other) {
        return (*this.m_vec >= other.m_vec);
    }
    bool operator<=(const Stack<T>& other) {
        return (*this.m_vec <= other.m_vec);
    }

    friend std::ostream& operator<<(std::ostream& os, const Stack<T>& stack) {
        os << "The size of Stack: " << stack.size() << "\nThe elements are: ";
        for (size_t i = 0; i < stack.m_size; i++)
        {
            os << stack.m_vec[i] << " ";
        }
        return os;
    }
private:
    size_t m_size;
    std::vector<T> m_vec;
    std::vector<T> min_vec;
};

#endif