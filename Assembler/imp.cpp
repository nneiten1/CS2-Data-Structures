//
//
//
//
//

#include "stack.hpp"
#include <cassert>
#include <iostream>


template <typename T>
T stack<T>::top() const {
    return tos->data;
}



template <typename T>
void stack<T>::push(const T& item) {
    //assert(!full());
    Node<T> *temp = new Node<T>(item);
    temp->next = tos;
    tos = temp;    
}

template <typename T>
T stack<T>::pop() {
    //assert(!empty());
    T result = tos->data;
    Node<T> *temp = tos;
    tos = tos->next;
    delete temp;
    return result;
}


template <typename T>
stack<T>::~stack() {
    Node<T> *temp;
    while(tos != 0){
        temp = tos;
        tos = tos->next;
        delete temp;
    }
}

template <typename T>
stack<T>::stack(const stack<T>& actual) : stack() {
    //std::cout << "Copy Ctor Stack" << std::endl;
    Node<T> *temp = actual.tos;
    Node<T> *bottom;
    while(temp != 0){
        //std::cout << "While" << std::endl;
        if(tos == 0){
            //std::cout << "If" << std::endl;
            tos = new Node<T>(temp->data);
            bottom = tos;
        }
        else {
            //std::cout << "Else" << std::endl;
            bottom->next = new Node<T>(temp->data);
            bottom = bottom->next;
        }
        temp = temp->next;
    }
}

template <typename T>
void stack<T>::swap(stack<T>& rhs){
    Node<T> *temp = tos;
    tos = rhs.tos;
    rhs.tos = temp;
}

template <typename T>
bool stack<T>::full() const {
    Node<T> *temp = new Node<T>();
    if(temp == 0) return true;
    delete temp;
    return false;
}
