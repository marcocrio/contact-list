#ifndef MEENU_SYSTEM_H
#define MENU_SYSTEM_H

#include <iostream>
#include <fstream>
#include "data_structure.h"
#include "readfile.h"


using namespace std;

class Menu
{
  private:
    Contact *head, *tail, *cursor; 

  public:
    void listSel();

    //setters
    void setHead(Contact* lhead);
    void setTail(Contact* ltail);
    void setCursor(Contact* lhead);
    void dsinit();
    
    //getters;
    void getContacts();
    Contact* getHead();
    Contact* getTail();
    Contact* getCursor();
    void listContacts();
};

#endif