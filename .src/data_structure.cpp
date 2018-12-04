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
        ):index(index),name(name),last(last),phone(phone),email(email),head(head),cursor(this),next(next){
            
        };


        // Setters --------------------------------------------------------------
        void setData(string sname, string slast, string sphone, string semail, Contact *shead){
            name  = sname;
            last  = slast;
            phone = sphone;
            email = semail;
            head  = shead;
        };

        void setNext(Contact* link){next=link;}
        void setHead(Contact* newhead){head=newhead;}

        // Sets the data for the next node and moves the cursor to that node
        Contact* newCont(string sname, string slast, string sphone, string semail){
            if(name=="Undefined" && last=="Undefined" && phone=="Undefined" && email=="Undefined" ){
                name=sname; last=slast; phone=sphone; email=semail;
                return cursor;
            }
            Contact* lastnode=cursoradjust("lastnode");
            int indx = lastnode->index;
            if( lastnode->next == nullptr ) { 
                next = new Contact(++indx,sname, slast, sphone, semail, head);
                next->cursor = next; 
                return next;
            };
        };

        //updates head if head is deleted
        void updatehead(Contact* newhead){
            updatehead(newhead,head);
        }

        Contact* updatehead(Contact* newhead, Contact* node){
                if(node->next==nullptr){return nullptr;};
                head=newhead;
                node->head = newhead;
                updatehead(newhead,node->next );
                return newhead;
        };


        //updates the index when node deleted
        void indexuptade(){
            indexuptade(0, head);
        }
        void indexuptade(int indx, Contact* node){
            if(node==nullptr){return;};
            node->index = indx;
            indexuptade(indx+1, node->next );
        };

        

        // Getters ---------------------------------------------------------------
        int getIndex(){return index;};
        Contact* getHead(){return head;};
        Contact* getNext(){return next;};
        string getData(){return index + " " +name + " " + last + " " + email;};


        void traversedprint(){
            cout<< "Displaying all contacs"<< endl;
            traversedprint(head);
        }

        void traversedprint(Contact* current){
            if(current == nullptr){return;}
            current->printData();
            traversedprint(current->next);
            
        };

        void printData(){
            //cursor->status();
            cout << index << " "
                 << name  << " "
                 << last  << " "
                 << phone << " "
                 << email <<endl<< endl;
        };

        //Prints the status of a the cursor
        void status(){
            cout <<"| Index:"<<index << " | Head: " << head << " | Cursor:" << cursor << " | Next:" << next << " |"<< endl;
        };

        
        //returns the address of a targeted node

        auto cursoradjust(int indx){
            return cursoradjust(indx, head);
        }

        Contact* cursoradjust(string lastnode){
                Contact* endnode = head; 
                while(endnode->next!=nullptr){
                    endnode = endnode->next;
                }
                return endnode;
        };

        Contact* cursoradjust(int indx, Contact* target){
            if(target==nullptr){ cout << "This contact doesn't exist"<< endl; return nullptr;};
            if(indx == target->getIndex()){return target;}
            else{
                cursoradjust(indx,target->getNext());
            };
            
        };  

        

        //desctructors -----------------------------------------------------------------------------------------
        
        //Adjust the cursor and deletes the targeted node, moves the cursor to de previous node of the deleted.
        Contact* contdel(int indx){
            Contact* todel, *link;
            //Selects delet target
            if(indx==0){
                if(head->next==nullptr){cout<< "Your list is empty now"<< endl;
                todel =head;
                Contact* newhead = new Contact();
                newhead->setHead(newhead);
                cout <<"Head if only one node"<< todel << " " << newhead->head <<endl;
                indexuptade();
                return newhead;
             }
                todel = head;
                updatehead(head->next); 
                indexuptade();
                return head;
            }
            link=cursoradjust(indx-1);
            todel=cursoradjust(indx);
            if(todel==nullptr || link==nullptr){cout << "--- Nothing was deleted---"<<endl; return head;};
            link->next= todel->next;
            delete todel;
            indexuptade();
            return link;
        };

            void delall(){
                delall(head);
            } 

            void delall(Contact* toedelete){
                if(cursor->next == nullptr){return;};
                Contact* delnext = cursor->next;
                delete cursor;
                delall(delnext);
            };

};


int main(){

    Contact* head;											//Start of list
	Contact* tail;											//End of list
	Contact* cursor = new Contact(); 

    head = cursor; 

    
    cursor->setData("Marco", "Ramirez", "9157040545", "maramirez25@miners.utep", head);
    cursor = cursor->newCont("Aleksya", "Monkey", "990030304", "maramirez@miners.con" );
    cursor = cursor->newCont("Marcus", "Monkey", "990030304", "elmonkeyramirez@miners.con" );
    cursor = cursor->newCont("Jovanna", "Cacarez", "90030304", "lajovas@miners.con" );

    tail=cursor;
   
    cursor->traversedprint();

    cout <<endl<<"pointer adjust" << endl;
    cursor=cursor->cursoradjust(2); 
    !cursor ? cursor=head: cursor=cursor;
    cursor->printData();

    cout <<endl<<"Delete"<< endl;
    cursor=cursor->contdel(0);
    cout << "Cursor after delete" << endl;
    cursor->printData();

    


    
    cout <<endl<<"Delete"<< endl;
    cursor=cursor->contdel(2);
    cout << "Cursor after delete" << endl;
    cursor->printData();
    cout <<endl<<"Traverse print after delete"<<endl;
    cursor->traversedprint();

    cout<< "Create new contact"<<endl;
    cursor = cursor->newCont("Raul", "Perron", "990030304", "Rarara@miners.con" );
    cursor->printData();
    cout <<endl<<"Traverse print"<<endl;
    cursor->traversedprint();

    cout << "delete all"<< endl;
    cursor->delall();

     cursor->traversedprint();


};