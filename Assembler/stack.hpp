//
// File: stack.hpp
//
// Programmer:
// Date:       Spring 2023
//
//
// Do not change the names of the classes or methods.  Otherwise, instructor
//  tests will not work.
//
#ifndef CS2_STACK_HPP_
#define CS2_STACK_HPP_

#include <new>
#include <cassert>


template<typename T> 
class Node {
public:
    Node() : next(0) {};
    Node(T item) : data(item), next(0) {};
    //Node(<T> item) : { data(item); next(0);};
    T data;
    Node<T> *next;
};


// CLASS INV:
//
template <typename T>
class stack {
public:
              stack     () : tos(0) {};
              stack     (const stack<T>&);
              ~stack    ();
    void      swap      (stack<T>&);
    stack<T>& operator= (stack<T> rhs) {swap(rhs); return *this; };
    
	bool      empty     () const {return tos == 0;};
	bool      full      () const;
	T         top       () const;
	T         pop       ();
	void      push      (const T&);

private:
	Node<T>   *tos;
};


#endif
