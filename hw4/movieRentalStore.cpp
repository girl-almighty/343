/*----------rentalMain.cpp-----------*/
/*                                   */
/*     CSS 343 - Winter 2018         */
/*     Created by: Iris Favoreal     */
/*                                   */
/*     Purpose:                      */
/*                                   */
/*-----------------------------------*/

#include "movieRentalStore.h"
#include "actionfactory.h"


MovieRentalStore::MovieRentalStore()
{
	BST<Movie*> comedyContainer('F');
    BST<Movie*> dramaContainer('D');
	BST<Movie*> classicContainer('C');
	movieContainers.push_back(comedyContainer);
    movieContainers.push_back(dramaContainer);
	movieContainers.push_back(classicContainer);
}

MovieRentalStore::~MovieRentalStore()
{}

vector<BST<Movie*> > MovieRentalStore::getMovies()
{
    return movieContainers;
}

HashTable<Customer> MovieRentalStore::getCustomers()
{
    return customerContainer;
}

void MovieRentalStore::setCustomers(ifstream& file)
{
    cout << endl << "******* CREATING CUSTOMERS *******" << endl;
	for (;;)
	{
		int custID;
		file >> custID;

		if (file.eof())
			break;

		string fName, lName;
		file >> fName >> lName;

		Customer *newCustomer = new Customer();
		newCustomer->setCustomerData(custID, fName, lName);
		customerContainer.insert(newCustomer->getCustomerID(), newCustomer);
        
        cout << *newCustomer;
	}
    cout << endl;
}

void MovieRentalStore::setTransactions(ifstream& file)
{
    cout << endl << "******* CREATING COMMANDS *******" << endl;
	for (;;)
	{
		char command = file.get();
		if (file.eof())
			break;

        ActionFactory::createAction(command, file, movieContainers, customerContainer);
	}
    
    cout << endl;
}

void MovieRentalStore::setMedia(ifstream& file)
{
    cout << endl << "******* CREATING MOVIES *******" << endl;

	for (;;)
	{
		char genre = file.get();
		if (file.eof())
			break;

		Movie* newMovie = MovieFactory::createMovie(genre, file);
		if (newMovie == NULL)
			continue;

		bool inserted = false;
		for (vector<BST<Movie*> >::iterator tree = movieContainers.begin(); tree != movieContainers.end(); tree++)
		{
			if (newMovie->getGenre() == tree->getGenre())
			{
				tree->insert(newMovie);
				inserted = true;
				break;
			}
		}
		if (!inserted)
		{
			BST<Movie*> newContainer(genre);
			newContainer.insert(newMovie);
			movieContainers.push_back(newContainer);
		}
	}
    
    cout << endl;
}
