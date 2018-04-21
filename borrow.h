/*----------rentalMain.cpp-----------*/
/*                                   */
/*     CSS 343 - Winter 2018         */
/*     Created by: Iris Favoreal     */
/*                                   */
/*     Purpose:                      */
/*                                   */
/*-----------------------------------*/

#ifndef borrow_hpp
#define borrow_hpp
#include "action.h"
#include "customer.h"


class Borrow : public Action
{
public:
	Borrow();
	~Borrow();
    
	void execute();
    
	void setMedia(Movie*);
	void setCustomer(Customer*);

protected:
	Movie* m;
	Customer* cust;
};
#endif
