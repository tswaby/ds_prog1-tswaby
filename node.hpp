#ifndef NODE_H
#define NODE_H

using namespace std;

//Creating a template class for the nodes that I will use in my linked list class
//
template <class T>
class node{
    public:
        T data;
        node<T> * next;
        node() { next = nullptr;}
        node(T item) {
            data = item;
            next = nullptr;
        }
};

#endif