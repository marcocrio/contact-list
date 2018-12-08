
#include "../.include/menu_system.h"


void Menu::listSel()
{
    string sel;
    int fileerror = 0;
    do
    {
        system("clear");
        cout <<endl<< "Please type the name of the contact list you're trying to access" << endl <<flush;
        cin >> sel;
        readf* contact_list = new readf(sel);
        list = contact_list;
        fileerror = list->fexist("read");
        if(fileerror){
            delete list;
        }else{list->filetodt();};
    } while (fileerror);

    choice();

};

void Menu::getContacts(){

};

void Menu::choice(){
    string programexit = "keep";
    while(1){
        system("clear");
        string sel;
        
        cout<< "Please select one of the following options:"<< endl
            <<"           Add [a]            "<<endl
            <<"          Display [d]         "<< endl
            <<"          Search [s]          "<< endl
            <<"           Exit [e]           "<<endl         
            <<endl<<flush;

        cin >> sel;

        if(sel == "a" || sel =="A"){add();};
        if(sel == "d" || sel =="D"){display();};
        if(sel == "s" || sel =="S"){search();};
        if(sel == "e" || sel =="E"){exit(1);};
    };    
};


void Menu::display(){system("clear");list->listContacts();};

void Menu::add(){system("clear"); list->addContact();};

void Menu::search(){
    string name,last;
    system("clear"); 
    cout<< "Search:" << endl
        <<"Name: ";
        cin >> name;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Last name:";
        cin >> last;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        
 

    list->search(name,last);
};