/*----------rentalMain.cpp-----------*/
/*                                   */
/*     CSS 343 - Winter 2018         */
/*     Created by: Iris Favoreal     */
/*                                   */
/*     Purpose:                      */
/*                                   */
/*-----------------------------------*/



#include "actionfactory.h"


ActionFactory::ActionFactory()
{}

ActionFactory::~ActionFactory()
{}

void ActionFactory::createAction(const char command, ifstream &file, vector<BST<Movie*> > &movies, HashTable<Customer> &customers)
{
	file.get();
    Action * newAction;
	switch(command)
	{
        case 'I':
        {
            vector<BST<Movie*>>* moviePtr = &movies;
            newAction = new Inventory(moviePtr);
            string clear;
            getline(file, clear, '\n');
            break;
        }
        case 'H':
            newAction = createHistory(file, customers);
            break;
        case 'B':
            newAction = createBorrow(file, customers, movies);
            break;
        case 'R':
            newAction = createReturn(file, customers, movies);
            break;
        default:
        {
            cout << "Invalid command: " << command << endl;
            string clear;
            getline(file, clear, '\n');
            newAction = NULL;
        }
    }
    if(newAction != NULL)
        delete newAction;
}

Action *ActionFactory::createHistory(ifstream &file, HashTable<Customer>& customerContainer)
{
    int cusID;
    file >> cusID;
    
    string clear;
    getline(file, clear, '\n');
    
    Customer * c = checkCustomerID(cusID, customerContainer);
    if(c == NULL)
    {
        getline(file, clear, '\n');
        return NULL;
    }
    
    Action* a = new History();
    History* h = dynamic_cast<History*>(a);
    h->setCustomer(c);
    h->execute();
    
    return h;
}

Action *ActionFactory::createBorrow(ifstream &file, HashTable<Customer>& customerContainer, vector<BST<Movie*> >& movieContainer)
{
    int cusID;
    file >> cusID;
    Customer * c = checkCustomerID(cusID, customerContainer);
    if(c == NULL)
    {
        string clear;
        getline(file, clear, '\n');
        return NULL;
    }
    
    char media, genre;
    file >> media >> genre;
    if (validateMovie(media) == false || validateGenre(genre) == false)
    {
        string clear;
        getline(file, clear, '\n');
        return NULL;
    }
    
    Movie *foundMovie = findMedia(genre, file, movieContainer);
    if(foundMovie == NULL)
    {
        cout << "Movie doesn't exist." <<  endl;
        return NULL;
    }
    
    Action* a = new Borrow();
    Borrow* b = dynamic_cast<Borrow*>(a);
    b->setCustomer(c);
    b->setMedia(foundMovie);
    b->execute();
    return b;
}

Action *ActionFactory::createReturn(ifstream & file, HashTable<Customer>& customerContainer, vector<BST<Movie*> >& movieContainer)
{
	int cusID;
	file >> cusID;
    Customer * c = checkCustomerID(cusID, customerContainer);
	if(c == NULL)
    {
        string clear;
        getline(file, clear, '\n');
        return NULL;
    }
    
    char media;
    char genre;
    file >> media >> genre;
    if (validateMovie(media) == false || validateGenre(genre) == false)
    {
        string clear;
        getline(file, clear, '\n');
        return NULL;
    }
    
    Movie *foundMovie = findMedia(genre, file, movieContainer);
    if(foundMovie == NULL)
    {
        cout << "Movie doesn't exist." << endl;
        return NULL;
    }
    
    Action* a = new Return();
    Return* R = dynamic_cast<Return*>(a);
    R->setCustomer(c);
    R->setMedia(foundMovie);
    R->execute();
    return R;
}



Movie* ActionFactory::findMedia(char genre, istream &file, vector<BST<Movie*> >& movieContainer)
{
    switch (genre)
    {
        case 'C':
            return findClassics(file, movieContainer);
        case 'D':
            return findDrama(file, movieContainer);
        case 'F':
            return findComedy(file, movieContainer);
        default:
        {
            cout << "Invalid movie type: " << genre << endl;
            string clear;
            getline(file, clear, '\n');
            return NULL;
        }
    }
}

Movie* ActionFactory::findClassics(istream &file, vector<BST<Movie*> >& movieContainer)
{
    file.get();
    string line;
    getline(file, line, '\n');
    
    Classic* C = new Classic();
    C->setDateandActor(line);
    
    Movie* newC = NULL;
    for (vector<BST<Movie*> >::iterator it = movieContainer.begin(); it != movieContainer.end(); it++)
    {
        if (it->getGenre() == 'C')
            newC = it->retrieve(C);
    }
    delete C;
    return newC;
}

Movie* ActionFactory::findDrama(istream &file, vector<BST<Movie*> >& movieContainer)
{
    file.get();
    string director;
    getline(file, director, ',');
    
    file.get();
    string title;
    getline(file, title, ',');
    string clear;
    getline(file, clear, '\n');
    
    Drama* D = new Drama;
    D->setDirector(director);
    D->setTitle(title);
    
    Movie* newD = NULL;
    for (vector<BST<Movie*> >::iterator it = movieContainer.begin(); it != movieContainer.end(); it++)
    {
        if (it->getGenre() == 'D')
            newD = it->retrieve(D);
    }
    delete D;
    return newD;
}

Movie* ActionFactory::findComedy(istream &file, vector<BST<Movie*> >& movieContainer)
{
    file.get();
    string title;
    getline(file, title, ',');
    
    file.get();
    string year;
    getline(file, year, '\n');
    
    Comedy* F = new Comedy;
    F->setTitle(title);
    F->setYear(year);
    
    Movie * newF = NULL;
    for (vector<BST<Movie*> >::iterator it = movieContainer.begin(); it != movieContainer.end(); it++)
    {
        if (it->getGenre() == 'F')
            newF = it->retrieve(F);
    }
    delete F;
    return newF;
}

Customer* ActionFactory::checkCustomerID(int ID, HashTable<Customer>& cust)
{
	if (ID < 0 || ID > 9999)
	{
		cout << "The customer ID is invalid." << endl;
        return NULL;
	}
    
    Customer * c = cust.retrieve(ID);
    return c;
}

bool ActionFactory::validateMovie(char m)
{
	if (m == 'D')
		return true;
    cout << "Invalid media type: " << m << endl;
	return false;
}

bool ActionFactory::validateGenre(char genre)
{
	if (genre == 'C' || genre == 'D' || genre == 'F')
		return true;
    cout << "Invalid genre type: " << genre << endl;
	return false;
}
