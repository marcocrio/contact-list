#ifndef MEENU_SYSTEM_H
#define MENU_SYSTEM_H

#include <iostream>
#include <fstream>
#include "readfile.h"


using namespace std;

class Menu
{
  private:
   readf* list;

  public:
    void listSel();
    void getContacts();
    void choice();

    void add();
    void display();
    void search();
};

#endif