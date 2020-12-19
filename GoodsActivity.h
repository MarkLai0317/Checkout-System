#ifndef _GOODSACTIVITY_H
#define _GOODSACTIVITY_H

#include "GoodsInventory.h"

class GoodsActivity: {

    public:
    

        GoodsActivity(int id, int quantity, int category, int price, std::string name, time_t t)
            : goods(id, quantity, category, name, price),
             time(t)
        {}
        
        int getYear() const;

        int getMonth() const;
        
        int getDate() const;

        //return the id of the goods
        int getId() const;

        //return the quantity of the goods
        int getQuantity() const;
        

        //return the category of the goods
        int getCategory() const;
        

        int getPrice() const;

        //return the name of the goods
        std::string getName() const;





    private:

        time_t time;
        GoodsInventory goods; 
};