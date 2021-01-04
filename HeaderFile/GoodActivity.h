#ifndef _GOODACTIVITY_H
#define _GOODACTIVITY_H

#include "GoodInventory.h"

class GoodActivity: public GoodInventory{

    public:
    
        GoodActivity(){}

        GoodActivity(int input_id, std::string input_category, std::string input_name, int input_price, int input_quantity, time_t input_t);
        
        time_t getTime() const;


    private:

        time_t time;
        
};


#endif