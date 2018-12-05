
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
        fileerror = contact_list.fexist();
    } while (fileerror);
};

void Menu::getContacts(){

};


