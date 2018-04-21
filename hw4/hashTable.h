/*----------rentalMain.cpp-----------*/
/*                                   */
/*     CSS 343 - Winter 2018         */
/*     Created by: Iris Favoreal     */
/*                                   */
/*     Purpose:                      */
/*                                   */
/*-----------------------------------*/



#include <fstream>
#include "customer.h"

using namespace std;

template <class Type>
class HashTable
{
	static const int SIZE = 53;							// prime number, more than twice larger than customer size
    
public:
    HashTable();
    ~HashTable();
    
    void insert(int key, Type *item);
    Type* retrieve(int key) const;						// retrieve value in the table

private:
	struct ItemList							// the struct in the hashtable 
	{
		Type* data;
		int key;
		ItemList* next;
	};
    
	ItemList *table[SIZE];					// hashtable
};


