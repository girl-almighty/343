/*----------rentalMain.cpp-----------*/
/*                                   */
/*     CSS 343 - Winter 2018         */
/*     Created by: Iris Favoreal     */
/*                                   */
/*     Purpose:                      */
/*                                   */
/*-----------------------------------*/


#include <stdio.h>
#include "comedy.h"

Comedy::Comedy()
{
    genre = 'F';
}


Comedy::~Comedy()
{}

void Comedy::setYear(string y)
{
	year = y;
}

string Comedy::getYear() const
{
	return year;
}

bool Comedy::operator==(const Movie & rhs) const
{
	return title == rhs.getTitle() && year == rhs.getYear();
}

bool Comedy::operator!=(const Movie & rhs) const
{
	if (*this == rhs)
		return false;
	return true;
}

bool Comedy::operator>(const Movie & rhs) const
{
	if (title > rhs.getTitle())
		return true;
	else if (title == rhs.getTitle())
	{
		if (year > rhs.getYear())
			return true;
		else
			return false;
	}
	return false;
}

bool Comedy::operator<(const Movie & rhs) const
{
	if (*this == rhs)
		return false;
	else if (*this > rhs)
		return false;
	return true;
}
