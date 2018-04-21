/*----------rentalMain.cpp-----------*/
/*                                   */
/*     CSS 343 - Winter 2018         */
/*     Created by: Iris Favoreal     */
/*                                   */
/*     Purpose:                      */
/*                                   */
/*-----------------------------------*/


#ifndef MovieRentalStore_h
#define MovieRentalStore_h


#include "BST.h"
#include "moviefactory.h"
#include "hashTable.h"
#include "customer.h"
#include <vector>
#include <iostream>

using namespace std;

class MovieRentalStore
{
public:
	MovieRentalStore();
    ~MovieRentalStore();
    
	void setCustomers(ifstream&);
    void setTransactions(ifstream&);
	void setMedia(ifstream&);
    
    vector<BST<Movie*> > getMovies();
    HashTable<Customer> getCustomers();

private:
	vector<BST<Movie*> > movieContainers;
	HashTable<Customer> customerContainer;
};

#endif
