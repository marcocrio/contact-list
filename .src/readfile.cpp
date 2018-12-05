
#include "../.include/readfile.h"

using namespace std;


void readf::readfile(){
    string name,last,phone,email;
    dsinit();
    
    while(filetoread >> name >> last >> phone >> email){
      cursor = cursor->newCont(name,last,phone,email);
    };

    cursor->printData();

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
void readf::dsinit(){
    Contact* list = new Contact();
    head = list;
    head->setHead(head);
    cursor = head;
};

//getters
Contact* readf::getHead(){return head;};
Contact* readf::getTail(){return tail;};
Contact* readf::getCursor(){return cursor;};

void readf::listContacts(){
    cursor->traversedprint();
};