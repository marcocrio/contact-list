#include <iostream>
#include "../.include/data_structure.h"
using namespace std;
// Setters --------------------------------------------------------------
void Contact::setData(string sname, string slast, string sphone, string semail, Contact *shead)
{
    name = sname;
    last = slast;
    phone = sphone;
    email = semail;
    head = shead;
};

void Contact::setNext(Contact *link) { next = link; }
void Contact::setHead(Contact *newhead) { head = newhead; }

// Sets the data for the next node and moves the cursor to that node
Contact *Contact::newCont(string sname, string slast, string sphone, string semail)
{
    if(head==nullptr){head=this;};
    if (name == "Undefined" && last == "Undefined" && phone == "Undefined" && email == "Undefined")
    {
        name = sname;
        last = slast;
        phone = sphone;
        email = semail;
        return cursor;
    };
    Contact *lastnode = cursoradjust("lastnode");
    int indx = lastnode->index;
    if (lastnode->next == nullptr)
    {
        next = new Contact(++indx, sname, slast, sphone, semail, head);
        next->cursor = next;
        return next;
    };
};

//updates head if head is deleted
void Contact::updatehead(Contact *newhead)
{
    updatehead(newhead, head);
}

Contact *Contact::updatehead(Contact *newhead, Contact *node)
{
    if (node->next == nullptr)
    {
        return nullptr;
    };
    head = newhead;
    node->head = newhead;
    updatehead(newhead, node->next);
    return newhead;
};

//updates the index when node deleted
void Contact::indexuptade()
{
    indexuptade(0, head);
}
void Contact::indexuptade(int indx, Contact *node)
{
    if (node == nullptr)
    {
        return;
    };
    node->index = indx;
    indexuptade(indx + 1, node->next);
};

// Getters ---------------------------------------------------------------

 

void Contact::traversedprint()
{
    cout << "Displaying all contacs" << endl<<endl;
    traversedprint(head);
    cout << endl;
}

void Contact::traversedprint(Contact *current)
{
    if (current == nullptr)
    {
        return;
    }
    current->printData();
    traversedprint(current->next);
};

void Contact::printData()
{
    cursor->status();
    cout << index << " ~ "
         << name << " "
         << last << " "
         << phone << " "
         << email << endl;
};

//Prints the status of a the cursor
void Contact::status()
{
    cout << "| Index:" << index << " | Head: " << head << " | Cursor:" << cursor << " | Next:" << next << " |" << endl;
};

//returns the address of a targeted node

Contact* Contact::cursoradjust(int indx)
{
    return cursoradjust(indx, head);
};

Contact* Contact::cursoradjust(string lastnode)
{
    Contact *endnode = head;
    while (endnode->next != nullptr)
    {
        endnode = endnode->next;
    }
    return endnode;
};

Contact* Contact::cursoradjust(int indx, Contact *target)
{
    if (target == nullptr)
    {
        cout << "This contact doesn't exist" << endl;
        return nullptr;
    };
    if (indx == target->getIndex())
    {
        return target;
    }
    else
    {
        cursoradjust(indx, target->getNext());
    };
};


// search by name (doesnt check for repeated contacts)
Contact* Contact::namesearch(string sname, string slast){
    return namesearch(sname, slast, head);
};

Contact* Contact::namesearch(string sname, string slast , Contact* target){

    if(target->getNext()==nullptr){
        return target->getCursor();
    }
    if(sname == target->getName() && slast == target->getLast()){
        return target->getCursor();
    }

    namesearch(sname, slast, head->getNext());

};

//desctructors -----------------------------------------------------------------------------------------

//Adjust the cursor and deletes the targeted node, moves the cursor to de previous node of the deleted.
Contact* Contact::contdel(int indx)
{
    Contact *todel, *link;
    //Selects delet target
    if (indx == 0)
    {
        if (head->next == nullptr)
        {
            cout << "Your list is empty now" << endl;
            todel = head;
            Contact *newhead = new Contact();
            newhead->setHead(newhead);
            cout << "Head if only one node" << todel << " " << newhead->head << endl;
            indexuptade();
            return newhead;
        }
        todel = head;
        updatehead(head->next);
        indexuptade();
        return head;
    }
    link = cursoradjust(indx - 1);
    todel = cursoradjust(indx);
    if (todel == nullptr || link == nullptr)
    {
        cout << "--- Nothing was deleted---" << endl;
        return head;
    };
    link->next = todel->next;
    delete todel;
    indexuptade();
    return link;
};

/*
void Contact::delall()
{
    delall(head);
}

void Contact::delall(Contact *toedelete)
{   // needs review
    if (cursor->next == nullptr)
    {
        return;
    };
    Contact *delnext = cursor->next;
    delete cursor;
    delall(delnext);
};

*/