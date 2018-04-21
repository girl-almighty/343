/*----------rentalMain.cpp-----------*/
/*                                   */
/*     CSS 343 - Winter 2018         */
/*     Created by: Iris Favoreal     */
/*                                   */
/*     Purpose:                      */
/*                                   */
/*-----------------------------------*/


#ifndef inventory_hpp
#define inventory_hpp

#include <stdio.h>
#include <vector>
#include "BST.h"
#include "action.h"
#include "movie.h"

class Inventory : public Action
{
public:
    Inventory();								// constructor
    Inventory(vector<BST<Movie*> >*&);			// constuctor with vector stores
    ~Inventory();								// destructor
    
    void execute();								// execute the inventory action
private:
    vector<BST<Movie*> >* printMovies;			// vector that stores the each movie genre in BST
};

#endif
