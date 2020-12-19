#ifndef _GOODSINVENTORY_H_
#define _GOODSINVENTORY_H_

#include <vector>
#include <string>
#include "Good.h"


class GoodsInventory: public Good{
    
    public:
 
        
        //Constructor

        GoodsInventory(std::string category, int id, std::string, int price, int quantity);
         
        
   
        //return the quantity of the goods
        int getQuantity() const;

    
    
    protected:


        int quantity;

}

#endif