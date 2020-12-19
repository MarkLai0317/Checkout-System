#ifndef _GOODSINVENTORY_H_
#define _GOODSINVENTORY_H_

#include <vector>

using get = std::string (*)(void);

class GoodsInventory{
    
    public:
 
        //Default Constructor
        GoodsInventory(){};
        
        //Constructor
        GoodsInventory(Good good, int quantity) : object(good) {}

        //return the quantity of the goods
        int getQuantity() const;
    
    private:

        Good good;
        int quantity;

};


#endif