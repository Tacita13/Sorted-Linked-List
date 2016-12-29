//Specification/Implementation file
//******************************************************************
//
//   Programador : Isamar López Rodríguez CCOM 3034 Sección 0U1
//   Num. Est.   : 801-08-3174            Primer Semestre 2016-2017
//   Asignación 5                         Prof. R. J. Colorado
//   Archivo     : unllist.h              Fecha : 14/10/16
//
//******************************************************************
//    Propósito :This file contains the UNLList class declaration
//               with its protected and private data members and public member
//               functions to manage a unsorted list.
//
//******************************************************************
#ifndef UNLLIST_H
#define UNLLIST_H

#include<iostream>
using namespace std;

template<class type>
struct Node{
    type info;
    Node<type> * link;
};

template<class type>
class UNLList{
    protected:
        Node<type> * head;

    private:
        void destroyList();
        void copy(const UNLList<type>&);


    public:
        //Constructor
        UNLList();

        //Destructor
        ~UNLList();

        //Copy constructor
        UNLList(const UNLList<type>&);

        //Overloaded assignment operator
        const UNLList<type>& operator=(const UNLList<type>&);

        //Observers

        bool isEmpty() const;
        bool isFull() const;
        int length() const;
        bool search(type) const;
        void print() const;

        //Mutators
        void insert(type);
        void remove(type);
        void clear(); //invoca a destroyList
};

//destroys the list, used in clear() and destructor
template <class type>
void UNLList<type>::destroyList(){
    Node<type> * kod;
    while(head != NULL){
        kod=head;
        head= head->link;
        delete kod;
    }
}

//Constructor
template <class type>
UNLList<type>::UNLList(): head(NULL){}

//Destructor
template <class type>
UNLList<type>::~UNLList(){
    destroyList();
}

//Observers
template <class type>
bool UNLList<type>::isEmpty() const{
    return (head == NULL);
}

//Know if the list is full
template <class type>
bool UNLList<type>::isFull() const{

    bool full;
    Node<type> * temp;

    temp = new Node<type>;
    if(temp == NULL){
        full=true;
    }
    else{
        full=false;
        delete temp;
    }
    return full;
}

//Show the length of the list
template <class type>
int UNLList<type>::length() const{
    int count =0;
    Node<type> * current = head;
    while(current!=NULL){
        count++;
        current =current ->link;
    }
    return count;
}

////Know if an item is in the list
template <class type>
bool UNLList<type>::search(type item) const{
    bool found = false;
    if(isEmpty()){
        cout<<"\nEmpty list. Cannot search.\n";
    }
    else{
        Node<type> * current = head;
        while(current !=NULL && !found){
            if(item==current->info){
                found=true;
            }
            else{
                current = current->link;
            }//end else
        }//end while
    }//end else
   return found;
}

//Displays the entire list
template <class type>
void UNLList<type>::print() const{

    if(isEmpty()){
        cout<<"\nEmpty list. Cannot print.\n";
    }
    else{
        cout<< "The elements in the list are:\n";
        Node<type> * current = head;
        for(int i=1; i<= length(); i++){
            cout<<i<<") "<< current ->info <<endl;
            current=current->link;
        }
    }//end else
}

//Mutators
template <class type>
void UNLList<type>::insert(type item){
    if(!isEmpty() && search(item)){
        cout<<item <<" already in list.\n";
    }
    else{
        Node<type> * nuevo= new Node<type>; // crear nodo
        nuevo->info = item; //llenar
        nuevo->link = NULL;

        //case #1
        if(isEmpty()){
            head=nuevo;
        }
        //case #2
        else{//insertar
            Node<type> * current = head;
            while (current->link !=NULL){

            current = current->link;
            }//end while
           current-> link = nuevo;
        }//end else
    }//end else
}

//Remove an item from the list
template <class type>
void UNLList<type>::remove(type item){
    if(isEmpty()){
        cout<<"Empty list. Cannot remove.\n";
    }
    else if(!search(item)){
        cout<< item << " not in list.\n";
    }//end else
    else{
        //check for removal of first node
        if(head-> info == item){
            Node<type> * kod=head;
            head=head->link;
            delete kod;
        }
        else{
            Node<type> * current=head->link;
            Node<type> * previous= head;

            while(current->info != item){
                previous=current;
                current=current->link;

            }//end while

            //conectar
            previous-> link=current-> link;
            delete current;

        }//end else
    }
}

//Delete the whole list
template <class type>
void UNLList<type>::clear(){ //invoca a destroyList
    destroyList();
}

//copy para copy constructor y OAO
template<class type>
void UNLList<type>::copy(const UNLList<type>& other){
    if(other.isEmpty()){
        head=NULL;
    }
    else{
        //copy first node
        Node<type> * current = other.head;

        head= new Node<type>;
        head->info = current->info;
        head->link = NULL;

        //Copy the rest
        Node<type> * newNode;
        Node<type> * previous = head;
        current = current-> link;

        while(current != NULL){
            //crear nodo
            newNode = new Node<type>;
            newNode-> info = current->info;
            newNode-> link = NULL;

            //Insertar
            previous-> link = newNode;

            //adelantar ambos punteros

            previous = previous -> link;
            current = current->link;
        }//end while
    }//end else

}

//Copy Constructor
template<class type>
UNLList<type>::UNLList(const UNLList<type> & other){

    copy(other);
}

//Overloaded assignment operator
template<class type>
const UNLList<type>& UNLList<type>::operator=(const UNLList<type> & other){
    //avoid self-assignement
    if(this != &other){
        destroyList();
        copy(other);
    }
    return *this;
}

#endif // UNLLIST_H
