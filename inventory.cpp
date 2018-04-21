/*----------rentalMain.cpp-----------*/
/*                                   */
/*     CSS 343 - Winter 2018         */
/*     Created by: Iris Favoreal     */
/*                                   */
/*     Purpose:                      */
/*                                   */
/*-----------------------------------*/

#include "inventory.h"


Inventory::Inventory()
{}

Inventory::Inventory(vector<BST<Movie*> >*& movies) : Action()
{
    printMovies = movies;
    execute();
}

Inventory::~Inventory()
{}

void Inventory::execute()
{
    cout << endl << "----------------------------- INVENTORY ------------------------------" << endl;
    
    for(vector<BST<Movie*> >::iterator it = printMovies->begin(); it != printMovies->end(); it++)
        it->print();
    
    cout << "-----------------------------------------------------------------------" << endl << endl;
}
