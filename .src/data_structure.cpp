#include <iostream> 
using namespace std;


class Contact{
    private:
        string name, last, phone, email;
        Contact *head, *tail, *next = nullptr;
    public:
        Contact(
            string name  = "undefined",
            string last  = "Undefined",
            string phone = "Undefined",
            string email = "Undefined"
        ):name(name),last(last),phone(phone),email(email){};


        void setData(string sname, string slast, string sphone, string semail){
            name  = sname;
            last  = slast;
            phone = sphone;
            email = semail;
        };
        void setNext(){
            next == nullptr ? cout << next << endl : cout << "nomame" << endl;
        };

        string getData();
       
        Contact* getNext();

        void printData(){
            cout << name << endl
                 << last << endl
                 << phone << endl
                 << email << endl;
        };


    
};


int main(){

    Contact* head;											//Start of list
	Contact* tail;											//End of list
	Contact* current = new Contact(); 

    head = current; 

    current->setData("Marco", "Ramirez", "9157040545", "maramirez25@miners.utep");

    current->printData();
    current->setNext();

    delete current;

};