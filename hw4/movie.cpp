/*----------rentalMain.cpp-----------*/
/*                                   */
/*     CSS 343 - Winter 2018         */
/*     Created by: Iris Favoreal     */
/*                                   */
/*     Purpose:                      */
/*                                   */
/*-----------------------------------*/

#include "movie.h"

Movie::Movie()
{
}

Movie::~Movie()
{
}

char Movie::getGenre() const
{
    return genre;
}

bool Movie::borrowIt()
{
    if(stock <= 0)
        return false;
    stock--;
    return true;
}

void Movie::returnIt()
{
    stock++;
}

void Movie::setStock(int s)
{
    stock = s;
}

int Movie::getStock() const
{
    return stock;
}


void Movie::setDirector(string d)
{
    director = d;
}

string Movie::getDirector() const
{
    return director;
}


void Movie::setTitle(string t)
{
    title = t;
}

string Movie::getTitle() const
{
    return title;
}



ostream & operator<<(ostream & ostream, const Movie & rhs)
{
    ostream << rhs.getGenre() << ", " << rhs.getStock() << ", " << rhs.getDirector();
    ostream << ", " << rhs.getTitle() << ", " << rhs.getYear() << endl;
	return ostream;
}
