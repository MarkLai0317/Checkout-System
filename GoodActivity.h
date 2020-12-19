#ifndef _GOODSACTIVITY_H
#define _GOODSACTIVITY_H

#include "GoodInventory.h"

class GoodActivity: public GoodActivity{

    public:
    

        GoodsActivity(std::string category, int id, std::string, int price, int quantity, time_t t);
        
        int getYear() const;

        int getMonth() const;
        
        int getDate() const;


    private:

        time_t time;
        
};


#endif