/*----------rentalMain.cpp-----------*/
/*                                   */
/*     CSS 343 - Winter 2018         */
/*     Created by: Iris Favoreal     */
/*                                   */
/*     Purpose:                      */
/*                                   */
/*-----------------------------------*/

#pragma once

#include <iostream>
#include <string>

using namespace std;

class Movie
{
	friend ostream& operator<<(ostream& ostream, const Movie&rhs);

public:
	Movie();												// constructor
	virtual ~Movie();
    
    char getGenre() const;
    bool borrowIt();
    void returnIt();

    void setStock(int stock);
    int getStock() const;
    
	void setDirector(string director);
    string getDirector() const;

	void setTitle(string title);
    string getTitle() const;

	virtual void setYear(string year) = 0;
    virtual string getYear() const = 0;

	virtual bool operator==(const Movie& rhs) const = 0;
	virtual bool operator!=(const Movie& rhs) const = 0;
	virtual bool operator>(const Movie& rhs) const = 0;
	virtual bool operator<(const Movie& rhs) const = 0;

protected:
    int stock;
    char genre;
	string director;
	string title;
	string year;
};
