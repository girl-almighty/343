/*----------rentalMain.cpp-----------*/
/*                                   */
/*     CSS 343 - Winter 2018         */
/*     Created by: Iris Favoreal     */
/*                                   */
/*     Purpose:                      */
/*                                   */
/*-----------------------------------*/

#include <stdio.h>
#include "history.h"

History::History() {}

History::~History() {}

void History::setCustomer(Customer* c)
{
    cust = c;
}

void History::execute()
{
    cust->printHistory();
}



