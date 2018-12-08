
#include "../.include/readfile.h"
#include <limits>
using namespace std;


void readf::readfile(){
    system("CLS");
    string name,last,phone,email;
    dsinit();
    while(filetoread >> name >> last >> phone >> email){
        cout << name << " " << last<< " "  << phone<< " "  << email<< endl<<flush;
    };

    filetoread.close();
        
};  


void readf::filetodt(){
    system("CLS");
    string name,last,phone,email;
    dsinit();
    while(filetoread >> name >> last >> phone >> email){
      cursor = cursor->newCont(name,last,phone,email);
    };

    filetoread.close();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');


    cout<<endl
        <<endl
        <<"         '"<< fname << "' list was succesfully loaded!" 
        <<endl<<"           "<<flush;
        system("PAUSE");
        
};  

int readf::readerror(){
    system("CLS");
    cerr<<endl
        <<endl 
        << "       The '" << fname <<"' list wasn't found! Choose another contact list."
        << endl
        << "                "
        <<flush;
        system("PAUSE");

    return EXIT_FAILURE;
};

int readf::fexist(string worr){
    
    if (worr=="write"){
        filetowrite.open(fdestination);
        if(!filetowrite) return readerror();
    }
    else if(worr == "read"){
        filetoread.open(fdestination);
        if(!filetoread) return readerror();
    };
    
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

Contact* readf::filewrite(Contact* node){
    if(node==nullptr){return node;};
    filetowrite << node->dataToFile() <<endl;   
    filewrite(node->getNext());
};

//getters
Contact* readf::getHead(){return head;};
Contact* readf::getTail(){return tail;};
Contact* readf::getCursor(){return cursor;};

void readf::listContacts(){  
    cursor->traversedprint();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << flush;
    system("PAUSE");
};


void readf::addContact(){
    string name,last,phone,email;
    cout<<"Please enter the following information:"<<endl
        << "Name: ";
    cin >> name;
    cout<< "Last Name: ";
    cin>>last;
    cout<< "Phone Number: ";
    cin>>phone;
    cout<< "Email: ";
    cin>>email;

    cursor = cursor->newCont(name,last,phone,email);

    fexist("write");

    filewrite(head);
    filetowrite.close();

    system("CLS");
    cout<<"         "
        << cursor->getName()
        << " "
        << cursor->getLast()
        << " was succesfully added"
        << endl
        <<"           "
        <<flush;

    system("PAUSE");
};

void readf::search(string name, string last){
    cursor = cursor->namesearch(name,last);
    cursor->printData();
    system("PAUSE");
};  