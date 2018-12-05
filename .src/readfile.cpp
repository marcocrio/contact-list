
#include "../.include/readfile.h"

using namespace std;


void readf::readfile(Menu* menu){
    string name,last,phone,email;
    Contact* cursor;
    menu->dsinit();
    cursor=menu->getCursor();
    while(filetoread >> name >> last >> phone >> email){
       cursor= cursor->newCont(name,last,phone,email);
    };
    menu->setCursor(cursor);
    menu->setTail(cursor);
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

int readf::fexist(Menu* menu){
    
    filetoread.open(fdestination);
    if(!filetoread) return readerror();
    
    
    readfile(menu);
    return EXIT_SUCCESS;

};