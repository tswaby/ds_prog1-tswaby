#ifndef LIST_H
#define LIST_H
#include "node.hpp"
#include <string>
#include <cstring>

//Defining the linked list class
//
template <class T>
class list {
    private:
        int size = 0;
        int spell = 0;
        int mispell = 0;
    public:
        node<T> * head;
        list()
            {head = nullptr;}
        ~list(){}
        void insert (T item, node<T> * &head);
        bool compare (string, node<T> * head, unsigned int &numcmp, unsigned int &spcmp, unsigned int &miscmp, list<T> &m);
        void traverse(node<T> * &tmp, node<T> * &head);
        int getSize();
        int getSpell();
        int getMispell();
        void printMis(ofstream &out);
};

#include "list.cpp"

#endif