#ifndef DATA_STRUCT_H
#define DATA_STRUCT_H

#include <iostream>
using namespace std;

class Contact{
    private:
        int index; 
        string name, last, phone, email;
        Contact *head, *next, *cursor;
    public:
        Contact(
            int index = 0,
            string name     = "Undefined",
            string last     = "Undefined",
            string phone    = "Undefined",
            string email    = "Undefined",
            Contact *head   = nullptr,
            Contact *cursor = nullptr,
            Contact *next   = nullptr
        ):index(index),name(name),last(last),phone(phone),email(email),head(head),cursor(this),next(next){};

    //Setters------------------------------
    void setData(string sname, string slast, string sphone, string semail, Contact *shead);
    void setNext(Contact *link);
    void setHead(Contact *newhead);

    Contact* newCont(string sname, string slast, string sphone, string semail);

    void updatehead(Contact* newhead);
    Contact* updatehead(Contact* newhead, Contact* node);
    
    void indexuptade();
    void indexuptade(int indx, Contact* node);

    //Getters-------------------------------
    int getIndex(){return index;};
    Contact* getHead(){return head;};
    Contact* getNext(){return next;};
    string getData(){return index + " " +name + " " + last + " " + email;}

    void traversedprint();
    void traversedprint(Contact* current);

     void printData();
     void status();

     Contact* cursoradjust(int indx);
     Contact* cursoradjust(string lastnode);
     Contact* cursoradjust(int indx, Contact* target);


    Contact* contdel(int indx);
    void delall();
    void delall(Contact* toedelete);
};

#endif