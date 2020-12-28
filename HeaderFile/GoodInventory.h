#ifndef _GOODINVENTORY_H
#define _GOODINVENTORY_H

#include <vector>
#include <string>
#include "Good.h"


class GoodsInventory: public Good{
    
    public:
 
        
        //Constructor
        GoodInventory(int id, std::string category, std::string name, int price, int quantity);
         
        
   
        //return the quantity of the goods
        int getQuantity() const;

    
    
    protected:

        int quantity;

}

#endif