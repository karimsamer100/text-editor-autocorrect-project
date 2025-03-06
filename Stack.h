#ifndef STACK_H
#define STACK_H

#include <stdexcept>

template <typename T>
class Stack {
private:
    T* stackArray;
    int capacity;
    int topIndex;

    void resizeArray(int newSize);

public:
    Stack();
    ~Stack();

    void push(const T& item);
    void pop();
    T top() const;
    bool isEmpty() const;

    void resize(int newSize);
};

#endif
