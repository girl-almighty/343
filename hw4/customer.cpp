/*----------rentalMain.cpp-----------*/
/*                                   */
/*     CSS 343 - Winter 2018         */
/*     Created by: Iris Favoreal     */
/*                                   */
/*     Purpose:                      */
/*                                   */
/*-----------------------------------*/




#include "customer.h"

Customer::Customer()
{
}

Customer::Customer(int id, string fName, string lName)
{
	customerID = id;
	firstName = fName;
	lastName = lName;
}

Customer::~Customer()
{
    for (vector<Trans*>::iterator it = History.begin(); it != History.end(); it++)
        delete *it;
}

ostream & operator<<(ostream & ostream, const Customer & rhs) 
{
    ostream << "Customer ID [" << rhs.getCustomerID() << "] ";
    ostream << "Customer Name [" << rhs.getFirstName() << " ";
    ostream << rhs.getLastName() << "] " << endl;
	
    for (int i = 0; i < rhs.History.size(); i++)
        ostream << "\t" << rhs.History[i] << endl;
    
	return ostream;
}

void Customer::setCustomerData(int id, string l, string f)
{
	customerID = id;
	firstName = f;
	lastName = l;
}

int Customer::getCustomerID() const
{
	return customerID;
}

string Customer::getFirstName() const
{
	return firstName;
}

string Customer::getLastName() const
{
	return lastName;
}

void Customer::printHistory()
{
    cout << endl << "-------------- printing transactions for customer: " << customerID << " ---------------" << endl;
    
    for(vector<Trans*>::iterator it = History.end() - 1; it != History.begin() - 1; --it)
        cout << " " << (*it)->Action << " " << *(*it)->m;
    
    cout << "-----------------------------------------------------------------------" << endl << endl;

}

void Customer::borrowedItem(Movie *movie)
{
    borrowed.push_back(movie);
    Trans * newTrans = new Trans();
    newTrans->Action = 'B';
    newTrans->m = movie;
    History.push_back(newTrans);
}

void Customer::returnedItem(Movie *movie)
{
    for(vector<Movie*>::iterator it = borrowed.begin(); it != borrowed.end(); it++)
    {
        if(*it == movie)
        {
            borrowed.erase(it);
            break;
        }
    }
    
    Trans * newTrans = new Trans();
    newTrans->Action = 'R';
    newTrans->m = movie;
    History.push_back(newTrans);
}

bool Customer::checkedOut(Movie *movie)
{
    for(vector<Movie*>::iterator it = borrowed.begin(); it != borrowed.end(); it++)
    {
        if(*it == movie)
            return true;
    }
    return false;
}
