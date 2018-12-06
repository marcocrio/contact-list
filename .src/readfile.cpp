
#include "../.include/readfile.h"
#include <limits>
using namespace std;


void readf::readfile(){
    system("clear");
    string name,last,phone,email;
    dsinit();
    while(filetoread >> name >> last >> phone >> email){
      cursor = cursor->newCont(name,last,phone,email);
    };

    filetoread.close();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');


    cout<< fname << " list was succesfully loaded."<<endl
        << "        press any key       "<< endl;

    getchar();
        
};  


void readf::filetodt(){
    system("clear");
    string name,last,phone,email;
    dsinit();
    while(filetoread >> name >> last >> phone >> email){
      cursor = cursor->newCont(name,last,phone,email);
    };

    filetoread.close();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');


    cout<< fname << " list was succesfully loaded."<<endl
        << "        press any key       "<< endl;

    getchar();
        
};  

int readf::readerror(){
    cerr << "Your file couldn't be opned" 
         << endl 
         << "PLease choose another contact list"
         << endl 
         << endl;
    return EXIT_FAILURE;
};

int readf::fexist(string worr){
    
    if (worr=="write"){
        filetowrite.open(fdestination);
    }
    else if(worr == "read"){
        cout << "here" <<endl;
        filetoread.open(fdestination);
    };
    if(!filetoread) return readerror();
    
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
    system("clear");
    cout << "Your concact was succesfully created"<<endl;

    fexist("write");

    filetowrite << name << last << phone <<email;   

    filetowrite.close();

    fexist("read");

    cursor->traversedprint(); 



};