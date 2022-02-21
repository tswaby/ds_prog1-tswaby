//Tera Swaby
//COSC 2030
//Program 01
//

#include <iostream>
#include "list.hpp"
#include "timer.hpp"
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;


//Establishing functions and variables
//
string cleanWord(string dirty);
string clean;
int skipped = 0;
unsigned int miscmp = 0;
unsigned int spcmp = 0;
unsigned int numcmp = 0;



int main(){

    ifstream Dict;
    ifstream Book;

    //Opening the Dictionary, checking that it is open
    //
    Dict.open("dict.txt");
    if(!(Dict)){
        cout << "Could not find dict.txt";
        return 0;
    }

    //Creating an object of the list class templetized on string for the dictionary 
    //Then getting each word from dictionary (seperated by white space) with >> while not at the end of the dictionary file
    //Sending each dictionary word through the clean word function
    //When it returns with the new clean word it is checked for beginning with a non-letter so it can be counted as skipped
    //Now, if the clean string is not empty it can be passed into the insert function of the dictionary list class
    //
    list<string> d;
    while(Dict){
        Dict >> clean;
        if(Dict){
            clean = cleanWord(clean);
            if(clean.empty());
            else if(!isalpha(clean[0])){
                skipped += 1;
                clean.clear();
            }
            else{d.insert(clean, d.head);}
        }
    }
    Dict.close();

    //Now the timer starts because the book is about to be opened and read from
    //The book is opened and if it failed to do so the brogram will end as a check
    //Then a new object of the list class is created for misspelled word
    //Then getting each word from book (seperated by white space) with >> while not at the end of the book file
    //Sending each book word through the clean word function
    //When it returns with the new clean word it is checked for beginning with a non-letter so it can be counted as skipped
    //Now, if the clean string is not empty it can be passed into the compare function of the dictionary 
    //(with the mispelled class object as a parameter passed by reference so it can be added to as words are found misspelled in the compare function)
    //
    Timer t;
    t.Start();
    Book.open("book.txt");
    if(!(Book)){
        cout << "Could not find book.txt";
        return 0;
    }
    list<string> m;
    while(Book){
        Book >> clean;
        if(Book){
            clean = cleanWord(clean);
            numcmp = 0;
            if(clean.empty());
            else if(!isalpha(clean[0])){
                skipped += 1;
                clean.clear();
            }
            else{d.compare(clean, d.head, numcmp, spcmp, miscmp, m);}
        }
    }
    t.Stop();
    Book.close();

    //This is what opens the file for misspelled words and calls on the printMis function of the linked list of misspelled words so they can be printed to this file
    //
    ofstream wrong;
    wrong.open("mispelled.txt");
    m.printMis(wrong);
    wrong.close();

    //This is the final output of the program
    //
    cout << "Dictionary Size: " << d.getSize() << endl;
    cout << "Finished in Time: " << t.Time() << endl;
    cout << "There are " << d.getSpell() << " words found in the dictionary" << endl;
    cout << "       " << spcmp << " compares. Average: " << spcmp/d.getSpell() << endl;
    cout << "There are " << d.getMispell() << " words NOT found in the dictionary" << endl;
    cout << "       " << miscmp << " compares. Average: " << miscmp/d.getMispell() << endl;
    cout << "There were " << skipped << " words skipped." << endl;
}

//The function transforms the whole string it is given to lowercase
//Then it runs through a for in range loop with char c set to each char in the lowercase string
//if char is NOT alphanumeric or an apostrophe nothing happens
//when this not the case however the char is added to a new string called clean
//The final product of the clean word, after the for in range loop, is then returned from the function
//
string cleanWord(string dirty){
    transform(dirty.begin(), dirty.end(), dirty.begin(), :: tolower);
    string clean;
    for(char c : dirty){
        if(!(isalnum(c) || c == '\'')){
            //dirty.erase(remove(dirty.begin(), dirty.end(), c), dirty.end());
        }
        else{
            clean += c;
        }
    }
    return clean;
}
