/*----------rentalMain.cpp-----------*/
/*                                   */
/*     CSS 343 - Winter 2018         */
/*     Created by: Iris Favoreal     */
/*                                   */
/*     Purpose:                      */
/*                                   */
/*-----------------------------------*/



#pragma once
#include <stdio.h>
#include <iostream>
#include "inventory.h"
#include "history.h"
#include "borrow.h"
#include "return.h"
#include "movieRentalStore.h"

using namespace std;

class ActionFactory
{
public:
	ActionFactory();
	~ActionFactory();

    static void createAction(const char command, ifstream &, vector<BST<Movie*> >&, HashTable<Customer>&);
    
private:
    static Action *createHistory(ifstream &, HashTable<Customer>&);
	static Action *createBorrow(ifstream &, HashTable<Customer>&, vector<BST<Movie*> >&);
	static Action *createReturn(ifstream &, HashTable<Customer>&, vector<BST<Movie*> >&);
    
	static Customer* checkCustomerID(int ID, HashTable<Customer>&);
    static Movie* findMedia(char genre, istream &file, vector<BST<Movie*> >&);
    
    static Movie* findClassics(istream&, vector<BST<Movie*> >& movieContainer);
    static Movie* findComedy(istream&, vector<BST<Movie*> >& movieContainer);
    static Movie* findDrama(istream&, vector<BST<Movie*> >& movieContainer);
    
	static bool validateMovie(char m);
	static bool validateGenre(char g);
};

