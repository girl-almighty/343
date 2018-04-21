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

class Drama : public Movie
{
public:
	Drama();
	~Drama();

	//setters
	void setYear(string year);
	string getYear() const;

	//operator overloads
	bool operator==(const Movie& rhs) const;
	bool operator!=(const Movie& rhs) const;
	bool operator>(const Movie& rhs) const;
	bool operator<(const Movie& rhs) const;
};


