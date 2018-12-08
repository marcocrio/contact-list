
#include "../.include/readfile.h"
#include <limits>
using namespace std;


void readf::readfile(){
    system("clear");
    string name,last,phone,email;
    dsinit();
    while(filetoread >> name >> last >> phone >> email){
        cout << name << " " << last<< " "  << phone<< " "  << email<< endl<<flush;
    };

    filetoread.close();
        
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


    cout<<endl
        <<endl
        <<"         '"<< fname << "' list was succesfully loaded!" 
        <<endl<<"           Press enter to continue...          "<<flush;
        cin.get();
        
};  

int readf::readerror(){
    system("clear");
    cerr<<endl
        <<endl 
        << "       The '" << fname <<"' list wasn't found! Choose another contact list."
        << endl
        <<endl<<"           Press enter to continue...          "
        <<flush;
        cin.get();

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

void readf::fupdate(){
    fexist("write");
    filewrite(head);
    filetowrite.close();

};

//getters
Contact* readf::getHead(){return head;};
Contact* readf::getTail(){return tail;};
Contact* readf::getCursor(){return cursor;};

void readf::listContacts(){  
    cursor->traversedprint();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout <<endl<<"           Press enter to continue...          "<< flush;
    cin.get();
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

    system("clear");
    
    cout<<"         "
        << cursor->getName()
        << " "
        << cursor->getLast()
        << " was succesfully added"
        << endl
        <<endl<<"           Press enter to continue...          "<<flush;
        cin.get();

};

void readf::search(string name, string last){
    string sel;
    cursor = cursor->namesearch(name,last,head);
    head= cursor->getHead();
    while(1){
        system("clear");
        cout <<endl<<"Selected:"<<endl<<endl;
        cursor->printData();
        cout<<endl
            <<"         Delete: [d]            "<< endl
            <<"          Exit: [e]            "<< endl;
        cin >> sel;
        
        if(sel == "e" || sel =="E"){return;};
        if(sel == "d" || sel == "D"){

        cursor->contdel(cursor->getIndex());
        
        fupdate();



        cout<<"         "<< name << " " << last << " was deleted" << endl
        <<"          Press enter to continue...          "<<flush;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cin.get();
        return;
        }
    }



};  