//Specification/Implementation file
//******************************************************************
//
//   Programador : Isamar López Rodríguez 
//   Archivo     : SOLList.h              Fecha : 14/10/16
//
//******************************************************************
//    Propósito :This file contains the SOLList class declaration
//               with its two public member
//               functions to manage a sorted list.
//
//******************************************************************
#include "unllist.h"
#ifndef SOLLIST_H
#define SOLLIST_H


template<class type>
class SOLList: public UNLList<type> {

public:

    bool search(type)const;
    void insert(type);
};

//search an item in the list
template<class type>
bool SOLList<type>::search(type item)const{
    bool found=false;
    if(UNLList<type>::isEmpty()){
        cout<< "The list is empty. Cannot search for item.\n";
    }
    else{
        Node<type> * current=UNLList<type>::head;
        bool stopSearch =false;
        while(current !=NULL && !stopSearch){
            if(item <= current-> info)
                stopSearch=true;
            else{
                    current= current->link;
                }//end else
            if(stopSearch && current->info == item){
                    found=true;
                }
            }//end while
    }//end else
    return found;
}//end function

//insert an item in the list
template<class type>
void SOLList<type>::insert(type item){


    if(!UNLList<type>::isEmpty() && search(item)){
       cout<<"Item already in list.\n";
    }
    else{
        //create and fill a new node
        Node<type> * newNode = new Node<type>;
        newNode->info=item;
        newNode->link=NULL;

        //empty list
        if(UNLList<type>::isEmpty()){
            UNLList<type>::head=newNode;
        }
        else{
            Node<type> * current=UNLList<type>::head;
            Node<type> * trail =NULL;

            bool stopSearch=false;
            while(current !=NULL && !stopSearch){
                if(item <= current-> info)
                    stopSearch=true;
                else{
                        trail=current;
                        current= current->link;
                    }//end else

            }//End while
           //item va antes del primero
            if(current == UNLList<type>::head ){
                newNode-> link = UNLList<type>:: head;
                UNLList<type>:: head= newNode;
            }
            else{
                trail->link =newNode;
                newNode-> link = current;
            }//end else
        }//end while
    }//end else

}


#endif // SOLLIST_H
