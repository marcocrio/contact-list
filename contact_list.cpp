#include <iostream>
#include <fstream>
using namespace std;

#include ".include/readfile.h"



int main(){

    string cl;
    int fileerror=0;

    do{ 
        cout << "Please type the name of the contact list you're trying to access" << endl;
        cin >> cl;
        readf contact_list(cl);
        fileerror = contact_list.fexist();
    }while(fileerror);


return EXIT_SUCCESS;

}
