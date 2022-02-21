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

template<class T>
bool list<T>:: compare(string word, node<T> * head, unsigned int &numcmp, unsigned int &spcmp, unsigned int &miscmp, list<T> &m){
    while(true){
        if(head == nullptr) return false;
        int comp = word.compare(head->data); //strcmp(word.c_str(), (head->data).c_str());
        numcmp++;
        if(comp == 0){
            spcmp += numcmp;
            spell++;
            //cout << "true " << word << " " << head->data << endl;
            return true;
        }
        else if(head->next == nullptr){
            miscmp += numcmp;
            m.insert(word, m.head);
            mispell++;
            //cout << "false" << endl;
            return false;
        }
        else{
            //cout << head->data << endl;
            head = head->next;
            //return compare(word, head->next, numcmp, spcmp, miscmp, m);
        }
    }
}

template<class T>
int list<T>:: getSize(){
    return size;
}

template<class T>
int list<T>:: getSpell(){
    return spell;
}

template<class T>
int list<T>:: getMispell(){
    return mispell;
}

template<class T>
void list<T>:: printMis(ofstream &out){
    node<T> * item = head;
    while(item){
        out << item->data << endl;
        item = item->next;
    }
}