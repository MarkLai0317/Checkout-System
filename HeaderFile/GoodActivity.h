#ifndef _GOODACTIVITY_H
#define _GOODACTIVITY_H

#include "GoodInventory.h"

class GoodActivity: public GoodInventory{

    public:
    

        GoodActivity(int id, std::string category, std::string name, int price, int quantity, time_t t);
        
        time_t getTime();


    private:

        time_t time;
        
};


#endif