/*----------rentalMain.cpp-----------*/
/*                                   */
/*     CSS 343 - Winter 2018         */
/*     Created by: Iris Favoreal     */
/*                                   */
/*     Purpose:                      */
/*                                   */
/*-----------------------------------*/

#include "return.h"
#include <iostream>
using namespace std;

Return::Return()
{}

Return::~Return() 
{}

void Return::execute()
{
	if (cust->checkedOut(m) == false)
	{
		cout << "Cannot return a movie that was never checked out." << endl;
		return;
	}
	m->returnIt();
	cust->returnedItem(m);
}

void Return::setMedia(Movie *newM)
{
	m = newM;
}

void Return::setCustomer(Customer *newC)
{
	cust = newC;
}
