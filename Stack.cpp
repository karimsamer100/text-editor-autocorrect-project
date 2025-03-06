#include "Stack.h"
#include <stdexcept>

template <typename T>
Stack<T>::Stack() : capacity(10), topIndex(-1) {
    stackArray = new T[capacity];
}

template <typename T>
Stack<T>::~Stack() {
    delete[] stackArray;
}

template <typename T>
void Stack<T>::resizeArray(int newSize) {
    T* newArray = new T[newSize];

    for (int i = 0; i <= topIndex; ++i) {
        newArray[i] = stackArray[i];
    }

    delete[] stackArray;
    stackArray = newArray;
    capacity = newSize;
}

template <typename T>
void Stack<T>::push(const T& item) {
    if (topIndex + 1 >= capacity) {
        resizeArray(capacity * 2);
    }

    stackArray[++topIndex] = item;
}

template <typename T>
void Stack<T>::pop() {
    if (isEmpty()) {
        throw std::underflow_error("Stack is empty");
    }

    --topIndex;
}

template <typename T>
T Stack<T>::top() const {
    if (isEmpty()) {
        throw std::underflow_error("Stack is empty");
    }

    return stackArray[topIndex];
}

template <typename T>
bool Stack<T>::isEmpty() const {
    return topIndex == -1;
}

template <typename T>
void Stack<T>::resize(int newSize) {
    if (newSize > capacity) {
        resizeArray(newSize);
    }
}

template class Stack<std::string>;
