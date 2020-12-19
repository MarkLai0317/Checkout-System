#ifndef _GOODSACTIVITY_H
#define _GOODSACTIVITY_H

#include "GoodsInventory.h"

class GoodsActivity: {

    public:
    
        GoodsActivity(Good good, int quantity, time_t t)
            : goods(good, quantity),
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
        

        //return the name of the goods
        std::string getName() const;



    private:

        time_t time;
        GoodsInventory goods; 
};