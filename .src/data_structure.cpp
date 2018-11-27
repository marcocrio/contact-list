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


        void setData(string name, string last, string phone, string email){
            name  = name;
            last  = last;
            phone = phone;
            email = email;
        };
        void setNext();

        string getData();
        Contact* getNext();

        void printData();
    
};


int main(){

    Contact* head;											//Start of list
	Contact* tail;											//End of list
	Contact* current = new Contact(); 

    head = current; 

    

};