#ifndef _GOODACTIVITY_H
#define _GOODACTIVITY_H

#include "GoodInventory.h"

class GoodActivity: public GoodActivity{

    public:
    

        GoodActivity(int id, std::string category, std::string name, int price, int quantity, time_t t);
        
        int getYear() const;

        int getMonth() const;
        
        int getDate() const;


    private:

        time_t time;
        
};


#endif