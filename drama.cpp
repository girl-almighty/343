/*----------rentalMain.cpp-----------*/
/*                                   */
/*     CSS 343 - Winter 2018         */
/*     Created by: Iris Favoreal     */
/*                                   */
/*     Purpose:                      */
/*                                   */
/*-----------------------------------*/


#include "drama.h"


Drama::Drama()
{
    genre = 'D';
}

Drama::~Drama()
{}

void Drama::setYear(string y)
{
	year = y;
}

string Drama::getYear() const
{
	return year;
}

bool Drama::operator==(const Movie& rhs) const
{
	return director == rhs.getDirector() && title == rhs.getTitle();
}

bool Drama::operator!=(const Movie& rhs) const
{
	if (*this == rhs)
		return false;
	return true;
}

bool Drama::operator>(const Movie& rhs) const
{
	if (director > rhs.getDirector())
		return true;
	else if (director == rhs.getDirector())
	{
		if (title > rhs.getTitle())
			return true;
		else
			return false;
	}
	else
		return false;
}

bool Drama::operator<(const Movie & rhs) const
{
	if (*this == rhs)
		return false;
	else if (*this > rhs)
		return false;
	else
		return true;
}

