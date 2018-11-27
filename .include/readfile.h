#ifndef READF_H
#define READF_H

#include <iostream>
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
        void readfile();
        int readerror();
        int fexist();
};

#endif
