//This is the insert function for the linked list class
//creates a new pointer to a node(which containes the passed in parameter T item) called tmp
//has the next pointer of what tmp is pointing to point to where head is pointing
//Then head is set to point where tmp points
//This size of the the dictionary linked list is then incremented by one whenever this insert function is called
//
template<class T>
void list<T>:: insert(T item, node<T> * &head){
    node<T> * tmp = new node<T> (item);
    tmp->next = head;
    head = tmp; 
    size++;
}

//This function is for comparing the book strings against that of the dictionary to see if they are spelled or mispelled
//if the next pointer (head at the beginning) points to nullptr then the word is obviously misspelled because compare never came back with 0 throughout the entire list. 
//This is when the function returns false an the count of misspelled words increases and the number of compares(numcmp) is added to number of compares for mispelled(miscmp)
//however if compare returns 0 then the word is spelled correct and the function returns true and the count of spelled words increases and the number of compares(numcmp) is added to the number of compares for spelled words(spcmp)
//the function continues in the infinite while loop until it returns a bool with an increase of what the head pointer is to the next pointer so it can traverse through the dictionary linked list
//
template<class T>
bool list<T>:: compare(string word, node<T> * head, unsigned int &numcmp, unsigned int &spcmp, unsigned int &miscmp, list<T> &m){
    while(true){
        if(head == nullptr) return false;
        int comp = word.compare(head->data);
        numcmp++;
        if(comp == 0){
            spcmp += numcmp;
            spell++;
            return true;
        }
        else if(head->next == nullptr){
            miscmp += numcmp;
            m.insert(word, m.head);
            mispell++;
            return false;
        }
        else{
            head = head->next;
        }
    }
}

//This function returns the private variable size of the dictionary
//
template<class T>
int list<T>:: getSize(){
    return size;
}

//This function returns the private variable spell, words spelled correctly
//
template<class T>
int list<T>:: getSpell(){
    return spell;
}

//This function returns the private variable mispell, words not spelled
//
template<class T>
int list<T>:: getMispell(){
    return mispell;
}

//This function prints out the mispelled words to a text file
//
template<class T>
void list<T>:: printMis(ofstream &out){
    node<T> * item = head;
    while(item){
        out << item->data << endl;
        item = item->next;
    }
}
