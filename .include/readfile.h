#ifndef READF_H
#define READF_H

#include <iostream>
#include <fstream>
#include "data_structure.h"
using namespace std;

class readf{
    private:
        Contact *head, *tail, *cursor; 
        string fname;
        string fdestination;
        ifstream filetoread;

    public:
        readf(string name = "undefined"):fname(name){
            fdestination = ".resources/" + name;
        };
        void readfile();
        int readerror();
        int fexist();


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
