
#include "../.include/menu_system.h"


void Menu::listSel()
{
    string sel;
    int fileerror = 0;
    do
    {
        cout << "Please type the name of the contact list you're trying to access" << endl;
        cin >> sel;
        readf contact_list(sel);
        fileerror = contact_list.fexist(this);
    } while (fileerror);
};

void Menu::getContacts(){

};


// setters 
void Menu::setHead(Contact* lhead){head=lhead;};
void Menu::setTail(Contact* ltail){tail=ltail;};
void Menu::setCursor(Contact* lcursor){cursor=lcursor;};
void Menu::dsinit(){cursor = new Contact(); head = cursor;};

//getters
Contact* Menu::getHead(){return head;};
Contact* Menu::getTail(){return tail;};
Contact* Menu::getCursor(){return cursor;};

void Menu::listContacts(){
    cursor->traversedprint();
};