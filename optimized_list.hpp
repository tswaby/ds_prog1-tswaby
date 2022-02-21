#ifndef OPLIST_H
#define OPLIST_H
#include "node.hpp"
#include <string>

template <class T>
class oplist {
    private:
        int size = 0;
        int spell = 0;
        int mispell = 0;
    public:
        node<T> * mis;
        node<T> * A;
        node<T> * B;
        node<T> * C;
        node<T> * D;
        node<T> * E;
        node<T> * F;
        node<T> * G;
        node<T> * H;
        node<T> * I;
        node<T> * J;
        node<T> * K;
        node<T> * L;
        node<T> * M;
        node<T> * N;
        node<T> * O;
        node<T> * P;
        node<T> * Q;
        node<T> * R;
        node<T> * S;
        node<T> * T;
        node<T> * U;
        node<T> * V;
        node<T> * W;
        node<T> * X;
        node<T> * Y;
        node<T> * Z;
    public:
        oplist()
            {mis = A = B = C = D = E = F = G = H = I = J = K = L = M = N = O = P = Q = R = S = T = U = V = W = X = Y = Z = nullptr;}
        ~oplist();
        void insert (T item, node<T> * &head);
        bool compare (string, node<T> * head, int &numcmp, int &spcmp, int &miscmp);
        void traverse(node<T> * &tmp, node<T> * &head);
        int getSize();
        int getSpell();
        int getMispell();
}

#endif