#include <iostream>
#include <fstream>
#include "../.include/readfile.h"

using namespace std;


void readf::readfile(){
    string name,last,phone,email;

    while(filetoread >> name >> last >> phone >> email){
        cout << name << " " << last << " " << phone << " " << email << endl;
    };

    filetoread.close();
};

int readf::readerror(){
    cerr << "Your file couldn't be opned" 
         << endl 
         << "PLease choose another contact list"
         << endl 
         << endl;
    return EXIT_FAILURE;
};

int readf::fexist(){
    
    filetoread.open(fdestination);
    if(!filetoread) return readerror();
    
    
    readfile();
    return EXIT_SUCCESS;

};