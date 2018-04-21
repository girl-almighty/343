/*----------rentalMain.cpp-----------*/
/*                                   */
/*     CSS 343 - Winter 2018         */
/*     Created by: Iris Favoreal     */
/*                                   */
/*     Purpose:                      */
/*                                   */
/*-----------------------------------*/


#ifndef BST_h
#define BST_h
#include "movie.h"

template <class DVDGenre>
class BST
{
    friend ostream& operator<<(ostream& ostream, const Movie&rhs);
    
public:
    BST(char g);
    ~BST();
    char getGenre();
    
    void insert(DVDGenre);
    // bool remove(DVDGenre);
    DVDGenre retrieve(DVDGenre);
    
    void print();
    
private:
    struct Node
    {
        DVDGenre data;
        Node * left;
        Node * right;
    };
    
    Node* root;
    char genre;
    
    void insertHelper(Node*, Node*&);
    DVDGenre retrieveHelper(DVDGenre, Node*&);
    void printHelper(Node*&);
    void emptyTree(Node*&);
};

#endif 

