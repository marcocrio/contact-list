
#include "../.include/readfile.h"

using namespace std;


void readf::readfile(){
    string name,last,phone,email;
    Contact* list = new Contact();
    head = list;
    cursor = head;
    while(filetoread >> name >> last >> phone >> email){
       cursor = cursor->newCont(name,last,phone,email);
    };
    tail = cursor;
    filetoread.close();
};

int readf::readerror(){
    cerr << "Your file couldn't be opned" 
         << endl 
         << "PLease choose another contact list"
         << endl 
         << endl;
    return EXIT_FAILURE;
};

int readf::fexist(){
    
    filetoread.open(fdestination);
    if(!filetoread) return readerror();
    
    
    readfile();
    return EXIT_SUCCESS;

};


// setters 
void readf::setHead(Contact* lhead){head=lhead;};
void readf::setTail(Contact* ltail){tail=ltail;};
void readf::setCursor(Contact* lcursor){cursor=lcursor;};
void readf::dsinit(){cursor = new Contact(); head = cursor;};

//getters
Contact* readf::getHead(){return head;};
Contact* readf::getTail(){return tail;};
Contact* readf::getCursor(){return cursor;};

void readf::listContacts(){
    cursor->traversedprint();
};