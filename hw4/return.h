/*----------rentalMain.cpp-----------*/
/*                                   */
/*     CSS 343 - Winter 2018         */
/*     Created by: Iris Favoreal     */
/*                                   */
/*     Purpose:                      */
/*                                   */
/*-----------------------------------*/

#pragma once
#include "action.h"
#include "movie.h"
#include "customer.h"


class Return : public Action
{
public:
	Return();
	virtual	~Return();
    
	void execute();						
	
    void setMedia(Movie*);
	void setCustomer(Customer*);
    
protected:
	Movie* m;
	Customer* cust;
};

