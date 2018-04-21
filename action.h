/*----------rentalMain.cpp-----------*/
/*                                   */
/*     CSS 343 - Winter 2018         */
/*     Created by: Iris Favoreal     */
/*                                   */
/*     Purpose:                      */
/*                                   */
/*-----------------------------------*/



#ifndef action_hpp
#define action_hpp

#include <stdio.h>

class Action
{
public:
    Action();
    virtual ~Action();
    
    virtual void execute() = 0;
};
#endif 
