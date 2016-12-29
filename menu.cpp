//Client file
//******************************************************************
//
//   Programador : Isamar López Rodríguez CCOM 3034 Sección 0U1
//   Num. Est.   : 801-08-3174            Primer Semestre 2016-2017
//   Asignación 5                         Prof. R. J. Colorado
//   Archivo     : menu.cpp               Fecha : 14/10/16
//
//******************************************************************
//    Propósito :This file holds the main that finally displays the values
//               of the class SOLList that inherits from UNLList.
//
//******************************************************************
#include <iostream>
#include "SOLList.h"
using namespace std;


int menu();
void execute(SOLList<int>&);

int main(){

    SOLList<int> list;
    execute(list);

    return 0;
}

// Display the menu and get a choice.
int menu(){
    int choice;

    cout << "What do you wish to do with your list?\n\n"
    << "1. Add an element\n"
    << "2. Search for an element\n"
    << "3. Remove an element\n"
    << "4. Display list\n"
    << "5. Size of the list\n"
    << "6. Clear list\n"
    << "7. Quit the Program\n\n"
    << "Enter your choice: ";
    cin >> choice;

return choice;
}

//excecute the given choice between 1 and 6
void execute(SOLList<int>& list){

    int element=0;
    int choice=0;
    do{

    choice=menu();

    switch (choice){
    case 1: cout << "Which integer would you like to insert?\n";
             cin >> element;
             list.insert(element);
    break;
    case 2: cout << "Which integer would you like to search?\n";
            cin >> element;
            if(!list.search(element))
                cout<< "Item not in list.\n";
            else
                cout<<"Item was found.\n";
    break;
    case 3: cout << "Which integer would you like to remove?\n";
            cin >> element;
            list.remove(element);
    break;
    case 4: list.print();
    break;

    case 5: cout<<"The size of the list is: "<< list.length()<<endl;
    break;

    case 6: cout<< "List is now empty.\n";
            list.clear();
    break;
    case 7: cout << "Program ending.\n";
    break;
    default: cout << "The valid choices are 1 through 8. Run the\n"
                  << "program again and select one of those.\n";
    }

    }while(choice !=7);

}
