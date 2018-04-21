/*----------rentalMain.cpp-----------*/
/*                                   */
/*     CSS 343 - Winter 2018         */
/*     Created by: Iris Favoreal     */
/*                                   */
/*     Purpose:                      */
/*                                   */
/*-----------------------------------*/



#include <stdio.h>
#include "hashTable.h"

template<class Type>
HashTable<Type>::HashTable()
{
    for(int i = 0; i < SIZE; i++)
        table[i] = NULL;
}

template<class Type>
HashTable<Type>::~HashTable()               
{
    for (int i = 0; i < SIZE; i++)
    {
        if (table[i] != NULL)
        {
            ItemList* openHash = table[i];
            while (table[i] != NULL)
            {
                table[i] = table[i]->next;
                delete openHash->data;
                delete openHash;
                openHash = table[i];
            }
        }
    }
}

template<class Type>
Type* HashTable<Type>::retrieve(int key) const                        // retrieve value in the table
{
    int hashKey = key % SIZE;
    if (table[hashKey] == NULL)
    {
        cout << "The customer does not exist, unfortunately." << endl;
        return NULL;
    }
    
    ItemList *cur = table[hashKey];
    while (cur != NULL)
    {
        if (key == cur->key)
            return cur->data;
        else
            cur = cur->next;
    }
    
    cout << "The customer does not exist, unfortunately." << endl;
    return NULL;
}

template<class Type>
void HashTable<Type>::insert(int key, Type *item)                    // inserts an item to the hashtable
{
    int hashKey = key % SIZE;
    
    ItemList *newItem = new ItemList();
    newItem->data = item;
    newItem->key = key;
    newItem->next = NULL;
    
    if (table[hashKey] == NULL)
        table[hashKey] = newItem;
    else
    {
        ItemList *cur = table[hashKey];
        while (cur->next != NULL)
        {
            if (key == cur->key)
            {
                delete newItem->data;
                delete newItem;
            }
            cur = cur->next;
        }
        cur->next = newItem;
    }
}

template class HashTable<Customer>;
