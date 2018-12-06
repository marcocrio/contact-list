
#include "../.include/menu_system.h"


void Menu::listSel()
{
    string sel;
    int fileerror = 0;
    do
    {
        cout <<endl<< "Please type the name of the contact list you're trying to access" << endl;
        cin >> sel;
        readf* contact_list = new readf(sel);
        list = contact_list;
        fileerror = list->fexist();
        list->readfile();
        if(fileerror){
            delete list;
        };
    } while (fileerror);

    choice();

};

void Menu::getContacts(){

};

void Menu::choice(){
    system("clear");
    string sel;
    
    cout<< "Please select one of the following options:"<< endl
        <<"           Add [a]            "<<endl
        <<"          Display [d]         "<< endl
        <<"          Search [s]          "<< endl<<endl;

    cin >> sel;

    if(sel == "a" || sel =="A"){add();};
    if(sel == "d" || sel =="D"){display();};
    if(sel == "s" || sel =="S"){};    
};


void Menu::display(){system("clear");list->listContacts();};

void Menu::add(){system("clear"); list->addContact();};
