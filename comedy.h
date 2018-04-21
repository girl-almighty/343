/*----------rentalMain.cpp-----------*/
/*                                   */
/*     CSS 343 - Winter 2018         */
/*     Created by: Iris Favoreal     */
/*                                   */
/*     Purpose:                      */
/*                                   */
/*-----------------------------------*/


#pragma once

#include "movie.h"

using namespace std;

class Comedy : public Movie
{
public:
	Comedy();								// constructor
	~Comedy();								// destructor

	void setYear(string year);
	string getYear() const;

	bool operator==(const Movie& rhs) const;
	bool operator!=(const Movie& rhs) const;
	bool operator>(const Movie& rhs) const;
	bool operator<(const Movie& rhs) const;
};



