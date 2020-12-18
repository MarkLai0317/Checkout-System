#ifndef _GOODSINVENTORY_H_
#define _GOODSINVENTORY_H_

#include <string>
#include <vector>

using get = std::string (*)(void);

class GoodsInventory{
    
    public:
 
        //Default Constructor
        GoodsInventory(){};
        
        //Constructor
        GoodsInventory(int id, int quantity, int category, int price, std::string name);
         
        
        //return the id of the goods
        int getId() const;

        //return the quantity of the goods
        int getQuantity() const;
        

        //return the cotogory of the goods
        int getCategoy() const;
        

        //return the price of the good
        int getPrice() const;


        //return the name of the goods
        std::string getName() const;
    
    
    private:

        int id, quantity, category, price;
        std::string name;

};


#endif