/*----------rentalMain.cpp-----------*/
/*                                   */
/*     CSS 343 - Winter 2018         */
/*     Created by: Iris Favoreal     */
/*                                   */
/*     Purpose:                      */
/*                                   */
/*-----------------------------------*/

#ifndef history_hpp
#define history_hpp

#include <iostream>
#include <fstream>
#include "action.h"
#include "customer.h"
using namespace std;

class History : public Action
{
public:
    History();							// constructor 
    ~History();							// destructor
    
    void execute();                        // Display history of the customer
    void setCustomer(Customer*);		// sets customer information
    
private:
    Customer* cust;						// the customerID we search for the history
};

#endif
