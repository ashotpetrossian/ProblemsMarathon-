// three Stacks represented in only one array
// all deleters are handled manually
// max size of each stack 100 sizeof(T)

#ifndef THREESTACKS_H_
#define THREESTACKS_H_

#include <iostream>

template<typename T>
class threeStacks {
public:
    // Member functions
    threeStacks() : m_count1(-1), m_count2(m_max_size - 1), m_count3(m_max_size * 2 - 1), 
                    m_size1(0), m_size2(0), m_size3(0) {
                        m_arr = new T[whole_size_limit]{};
                    }
    threeStacks(const threeStacks& ts) {
        m_count1 = ts.m_count1;
        m_count2 = ts.m_count2;
        m_count3 = ts.m_count3;
        m_size1 = ts.m_size1;
        m_size2 = ts.m_size2;
        m_size3 = ts.m_size3;
        T* tmp_arr = new T[whole_size_limit];
        for (size_t i = 0; i < whole_size_limit; i++)
        {
            tmp_arr[i] = ts.m_arr[i];
        }
        m_arr = tmp_arr;
        tmp_arr = nullptr;
    }
    threeStacks(threeStacks&& ts) {
        m_count1 = ts.m_count1; ts.m_count1 = 0;
        m_count2 = ts.m_count2; ts.m_count2 = 0;
        m_count3 = ts.m_count3; ts.m_count3 = 0;
        m_size1 = ts.m_size1;   ts.m_size1 = 0;
        m_size2 = ts.m_size2;   ts.m_size2 = 0;
        m_size3 = ts.m_size3;   ts.m_size3 = 0;
        T* tmp_arr = new T[whole_size_limit];
        for (size_t i = 0; i < whole_size_limit; i++)
        {
            tmp_arr[i] = ts.m_arr[i];
        }
        m_arr = tmp_arr;
        tmp_arr = nullptr;
        delete [] ts.m_arr;
        ts.m_arr = nullptr;
    }
    threeStacks& operator=(const threeStacks& other) {
        if (this == &other) { return *this; }
        m_count1 = other.m_count1;
        m_count2 = other.m_count2;
        m_count3 = other.m_count3;
        m_size1 = other.m_size1;
        m_size2 = other.m_size2;
        m_size3 = other.m_size3;
        T* tmp_arr = new T[whole_size_limit];
        for (size_t i = 0; i < whole_size_limit; i++)
        {
            tmp_arr[i] = other.m_arr[i];
        }
        m_arr = tmp_arr;
        tmp_arr = nullptr;
        return *this;
    }
    threeStacks& operator=(threeStacks&& other) {
        if (this == &other) { return *this; }
        m_count1 = other.m_count1; other.m_count1 = 0;
        m_count2 = other.m_count2; other.m_count2 = 0;
        m_count3 = other.m_count3; other.m_count3 = 0;
        m_size1 = other.m_size1;   other.m_size1 = 0;
        m_size2 = other.m_size2;   other.m_size2 = 0;
        m_size3 = other.m_size3;   other.m_size3 = 0;
        T* tmp_arr = new T[whole_size_limit];
        for (size_t i = 0; i < whole_size_limit; i++)
        {
            tmp_arr[i] = other.m_arr[i];
        }
        m_arr = tmp_arr;
        tmp_arr = nullptr;
        delete [] other.m_arr;
        other.m_arr = nullptr;
        return *this;
    }
    // Element access
    T& top_of_whole_stack() {
        if (m_size3 != 0) {
            return m_arr[m_count3];
        } else if (m_size2 != 0) {
            return m_arr[m_count2];
        } else if (m_size1 != 0) {
            return m_arr[m_count1];
        } else {
            throw std::invalid_argument("There is no element in the stack\n");
        }
    }
    T& top_stack1() {
        if (m_size1 != 0) {
            return m_arr[m_count1];
        } else {
            throw std::invalid_argument("There is no element in the stack1\n");
        }
    }
    T& top_stack2() {
        if (m_size2 != 0) {
            return m_arr[m_count2];
        } else {
            throw std::invalid_argument("There is no element in the stack2\n");
        }
    }
    T& top_stack3() {
        if (m_size3 != 0) {
            return m_arr[m_count3];
        } else {
            throw std::invalid_argument("There is no element in the stack3\n");
        }
    }
    // Capacity
    bool whole_stack_is_empty() const {
        if ((m_size1 == 0) && (m_size2 == 0) && (m_size3 == 0)) {
            return true;
        }
        return false;
    }
    bool stack1_is_empty() const {
        return m_size1 == 0;
    }
    bool stack2_is_empty() const {
        return m_size2 == 0;
    }
    bool stack3_is_empty() const {
        return m_size3 == 0;
    }
    int whole_size() const {
        return (m_size1 + m_size2 + m_size3);
    }
    int size_of_stack1() const {
        return m_size1;
    }
    int size_of_stack2() const {
        return m_size2;
    }
    int size_of_stack3() const {
        return m_size3;
    }
    ~threeStacks() {
        delete [] m_arr;
    }
    // Modifiers
    void push_in_stack1(const T& value) {
        if (m_size1 == m_max_size) { throw std::logic_error("The stack1 is already full\n");}
        ++m_count1;
        ++m_size1;
        m_arr[m_count1] = value;
    }
    void push_in_stack1(T&& value) {
        if (m_size1 == m_max_size) { throw std::logic_error("The stack1 is already full\n");}
        ++m_count1;
        ++m_size1;
        m_arr[m_count1] = std::move(value);
    }
    void push_in_stack2(const T& value) {
        if (m_size2 == m_max_size) { throw std::logic_error("The stack2 is already full\n");}
        ++m_count2;
        ++m_size2;
        m_arr[m_count2] = value;
    }
    void push_in_stack2(T&& value) {
        if (m_size2 == m_max_size) { throw std::logic_error("The stack2 is already full\n");}
        ++m_count2;
        ++m_size2;
        m_arr[m_count2] = std::move(value);
    }
    void push_in_stack3(const T& value) {
        if (m_size3 == m_max_size) { throw std::logic_error("The stack3 is already full\n");}
        ++m_count3;
        ++m_size3;
        m_arr[m_count3] = value;
    }
    void push_in_stack3(T&& value) {
        if (m_size3 == m_max_size) { throw std::logic_error("The stack3 is already full\n");}
        ++m_count3;
        ++m_size3;
        m_arr[m_count3] = std::move(value);
    }
    void pop_from_stack1() {
        if (m_size1 == 0) { throw std::logic_error("The stack1 is empty\n");}
        m_arr[m_count1] = 0;
        --m_count1;
        --m_size1;
    }
    void pop_from_stack2() {
        if (m_size2 == 0) { throw std::logic_error("The stack1 is empty\n");}
        m_arr[m_count2] = 0;
        --m_count2;
        --m_size2;
    }
    void pop_from_stack3() {
        if (m_size3 == 0) { throw std::logic_error("The stack1 is empty\n");}
        m_arr[m_count3] = 0;
        --m_count3;
        --m_size3;
    }
    void swap_stack1_stack2() noexcept {
        T* tmp_arr = new T[m_max_size];
        for (int i = 0; i < m_max_size; ++i) {
            tmp_arr[i] = m_arr[i];
        }
        int tmp_count = m_count1;
        int tmp_size = m_size1;
        for (int j = 0, i = m_max_size; j < m_max_size, i < m_max_size * 2; ++j, ++i)
        {
            m_arr[j] = m_arr[i];
        }
        for (int j = 0, i = m_max_size; j < m_max_size, i < m_max_size * 2; ++j, ++i)
        {
            m_arr[i] = tmp_arr[j];
        }
        m_count1 = m_count2 - m_max_size;
        m_size1 = m_size2;
        m_count2 = tmp_count + m_max_size;
        m_size2 = tmp_size;
        delete [] tmp_arr;
        tmp_arr = nullptr;
    }
    void swap_stack2_stack3() noexcept {
        T* tmp_arr = new T[m_max_size];
        for (int i = 0, j = m_max_size; i < m_max_size, j < m_max_size * 2; ++j, ++i) {
            tmp_arr[i] = m_arr[j];
        }
        int tmp_count = m_count2;
        int tmp_size = m_size2;
        for (int j = m_max_size, i = m_max_size * 2; j < m_max_size * 2, i < m_max_size * 3; ++j, ++i)
        {
            m_arr[j] = m_arr[i];
        }
        for (int j = 0, i = m_max_size * 2; j < m_max_size, i < m_max_size * 3; ++j, ++i)
        {
            m_arr[i] = tmp_arr[j];
        }
        m_count2 = m_count3 - m_max_size;
        m_size2 = m_size3;
        m_count3 = tmp_count + m_max_size;
        m_size3 = tmp_size;
        delete [] tmp_arr;
        tmp_arr = nullptr;
    }
    void swap_stack3_stack1() noexcept {
        T* tmp_arr = new T[m_max_size];
        for (int i = 0; i < m_max_size; ++i) {
            tmp_arr[i] = m_arr[i];
        }
        int tmp_count = m_count1;
        int tmp_size = m_size1;
        for (int j = 0, i = m_max_size * 2; j < m_max_size, i < m_max_size * 3; ++j, ++i)
        {
            m_arr[j] = m_arr[i];
        }
        for (int j = 0, i = m_max_size * 2; j < m_max_size, i < m_max_size * 3; ++j, ++i)
        {
            m_arr[i] = tmp_arr[j];
        }
        m_count1 = m_count3 - m_max_size * 2;
        m_size1 = m_size3;
        m_count3 = tmp_count + m_max_size * 2;
        m_size3 = tmp_size;
        delete [] tmp_arr;
        tmp_arr = nullptr;
    }
    // show functions 
    void show_stack1() {
        std::cout << "The Stack1:\n";
        for (int i = 0; i < m_max_size; i++)
        {
            std::cout << m_arr[i] << " ";
            if ( (i + 1) % 50 == 0) { std::cout << std::endl; }
        }
        std::cout << std::endl;
    }
    void show_stack2() {
        std::cout << "The Stack2:\n";
        for (int i = m_max_size; i < m_max_size * 2; i++)
        {
            std::cout << m_arr[i] << " ";
            if ( (i + 1) % 50 == 0) { std::cout << std::endl; }
        }
        std::cout << std::endl;
    }
    void show_stack3() {
        std::cout << "The Stack3:\n";
        for (int i = m_max_size * 2; i < m_max_size * 3; i++)
        {
            std::cout << m_arr[i] << " ";
            if ( (i + 1) % 50 == 0) { std::cout << std::endl; }
        }
        std::cout << std::endl;
    }
    void show_whole_stack() {
        std::cout << "Your whole Stack:\n";
        for (int i = 0; i < m_max_size * 3; i++)
        {
            std::cout << m_arr[i] << " ";
            if ( (i + 1) % 50 == 0) { std::cout << std::endl; }
        }
        std::cout << std::endl;
    }
    void show_counts() {
        std::cout << m_count1 << " " << m_count2 << " " << m_count3 << std::endl;
    }
private:
    T* m_arr;
    int m_count1;
    int m_count2;
    int m_count3;
    int m_size1;
    int m_size2;
    int m_size3;
    static const int m_max_size{100};
    static const int whole_size_limit{300};
};

#endif