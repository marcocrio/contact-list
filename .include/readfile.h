#ifndef READF_H
#define READF_H

#include <iostream>
#include <fstream>
#include "data_structure.h"
#include "menu_system.h"
using namespace std;

class readf{
    private:
        string fname;
        string fdestination;
        ifstream filetoread;

    public:
        readf(string name = "undefined"):fname(name){
            fdestination = ".resources/" + name;
        };
        void readfile(Menu* menu);
        int readerror();
        int fexist(Menu* menu);
};

#endif
