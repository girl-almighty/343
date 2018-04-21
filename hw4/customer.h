/*----------rentalMain.cpp-----------*/
/*                                   */
/*     CSS 343 - Winter 2018         */
/*     Created by: Iris Favoreal     */
/*                                   */
/*     Purpose:                      */
/*                                   */
/*-----------------------------------*/

#pragma once
#include <vector>
#include <list>
#include <string>
#include "BST.h"
#include "movie.h"

const int ID_LENGTH = 4;

using namespace std;

class Customer
{
	friend ostream& operator<<(ostream &ostream, const Customer &rhs);

public:
	Customer();													// constructor
	Customer(int id, string fName, string lName);				// constructor with parameter
	~Customer();												// destructor

	void setCustomerData(int id, string fName, string lName);	// sets the customer data
	int getCustomerID() const;									// returns customerID
	string getFirstName() const;								// returns customer fist name
	string getLastName() const;									// returns customer last name

	int getHashKey() const;										// hash key generator

	void borrowedItem(Movie *movie);							// add to the item to the borrowed list
	void returnedItem(Movie *movie);                            // remove the item from the borrwed list
    bool checkedOut(Movie*);
    void printHistory();

protected:
    struct Trans												// struct of Trans which contains customer action and movie
    {															// associated with the transaction
        char Action;
        Movie * m;
    };
    
	int customerID;
	string firstName;
	string lastName;
    
	vector<Trans*> History;										  // action history of a customer
    vector<Movie *> borrowed;                                     // borrowed list of items of a customer
};


