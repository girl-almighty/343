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
#include "comedy.h"
#include "drama.h"
#include "classic.h"


class MovieFactory
{
public:
	MovieFactory();
	~MovieFactory();

	static Movie* createMovie(const char type, istream&);
};
