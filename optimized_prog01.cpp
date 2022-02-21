#include <iostream>
#include "optimized_list.hpp"
#include "timer.hpp"
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

string cleanWord(string dirty, int &skipped);
string clean;
int skipped = 0;
unsigned int miscmp = 0;
unsigned int spcmp = 0;
int numcmp = 0;
int dicsz;



int main(){
    ifstream Dict;
    ifstream Book;

    Dict.open("dict.txt");
    if(!(Dict.is_open())){
        cout << "Could not find dict.txt";
        return 0;
    }
    oplist<string> d;
    while(!(Dict.eof()){
        Dict >> clean;
        clean = cleanWord(clean, skipped);

        if(clean.empty());
        else if(clean [0] == 'a') d.insert(clean, d.A);
        else if(clean [0] == 'b') d.insert(clean, d.B);
        else if(clean [0] == 'c') d.insert(clean, d.C);
        else if(clean [0] == 'd') d.insert(clean, d.D);
        else if(clean [0] == 'e') d.insert(clean, d.E);
        else if(clean [0] == 'f') d.insert(clean, d.F);
        else if(clean [0] == 'g') d.insert(clean, d.G);
        else if(clean [0] == 'h') d.insert(clean, d.H);
        else if(clean [0] == 'i') d.insert(clean, d.I);
        else if(clean [0] == 'j') d.insert(clean, d.J);
        else if(clean [0] == 'k') d.insert(clean, d.K);
        else if(clean [0] == 'l') d.insert(clean, d.L);
        else if(clean [0] == 'm') d.insert(clean, d.M);
        else if(clean [0] == 'n') d.insert(clean, d.N);
        else if(clean [0] == 'o') d.insert(clean, d.O);
        else if(clean [0] == 'p') d.insert(clean, d.P);
        else if(clean [0] == 'q') d.insert(clean, d.Q);
        else if(clean [0] == 'r') d.insert(clean, d.R);
        else if(clean [0] == 's') d.insert(clean, d.S);
        else if(clean [0] == 't') d.insert(clean, d.T);
        else if(clean [0] == 'u') d.insert(clean, d.U);
        else if(clean [0] == 'v') d.insert(clean, d.V);
        else if(clean [0] == 'w') d.insert(clean, d.W);
        else if(clean [0] == 'x') d.insert(clean, d.X);
        else if(clean [0] == 'y') d.insert(clean, d.Y);
        else if(clean [0] == 'z') d.insert(clean, d.Z);

        Dict.eof();
    }
    Dict.close();
    dicsz = d.getSize();

    Timer t;
    t.Start();
    Book.open("book.txt");
    if(!(Book.is_open())){
        cout << "Could not find book.txt";
        return 0;
    }
    while(!(Book.eof())){
        Book >> clean;
        clean = cleanWord(clean, skipped);
        numcmp = 0;
        if(clean.is_empty());
        else if(clean [0] == 'a') d.compare(clean, d.A, numcmp, spcmp, miscmp);
        else if(clean [0] == 'b') d.compare(clean, d.B, numcmp, spcmp, miscmp);
        else if(clean [0] == 'c') d.compare(clean, d.C, numcmp, spcmp, miscmp);
    }
    t.Stop();
    
    cout << "Dictionary Size: " << d.getSize() << endl;
    cout << "Finished in Time: " << t.Time() << endl;
    cout << "There are " << d.getSpell << " words found in the dictionary" << endl;
    cout << "       " << spcmp << " compares. Average: " << spcmp/d.getSpell << endl;
    cout << "There are " << d.getMispell << "words NOT found in the dictionary" << endl;
    cout << "       " << miscmp << " compares. Average: " << miscmp/d.getMispell << endl;
    cout << "There were " << skipped << " words skipped.";
}


string cleanWord(string dirty, int &skipped){
    transform(dirty.begin(), dirty.end(), dirty.begin(), :: tolower);
    if(!(isalpha(dirty [0]))){
        skipped += 1;
        dirty.clear();
    }
    else{
        for(char c : dirty){
            if(!(isalpha(c) || c == '\'')){
                dirty.erase(remove(dirty.begin(), dirty.end(), c), dirty.end());
            }
        }
    }
    return dirty;
}

void oplist<T>:: traverse(node<T> * &tmp, node<T> * &head){
    if(strcmp(tmp, head) < 0){
        tmp->next = head;
        head = tmp;
        size++;
        return;
    }
    if(strcmp(tmp, head) > 0){
        if(head->next == nullptr){
            head->next = tmp;
            size++;
            return;
        }
        else{
            traverse(tmp, head->next);
        }
    }
}

void oplist<T>:: insert(T item, node<T> * &head){
    node<T> * tmp = new node<T> (item);
    if(head == nullptr){
        head = tmp;
        delete tmp;
        size++;
        return;
    }
    else{
        traverse(tmp, head);
        return;
    }
}

bool oplist<T>:: compare(string word, node<T> * head, int &numcmp, int &spcmp, int &miscmp){
    if(head == nullptr) return false;
    int compare = strcmp(word, head->data);
    numcmp++;
    if(compare == 0){
        spcmp += numcmp;
        spell++;
        return true;
    }
    else if(head->next == nullptr){
        miscmp += numcmp;
        d.insert(word, d.mis);
        mispell++;
        return false;
    }
    else{
        return compare(word, head->next);
    }
}

int oplist<T>:: getSize(){
    return size;
}

int oplist<T>:: getSpell(){
    return spell;
}

int oplist<T>:: getMispell(){
    return mispell;
}