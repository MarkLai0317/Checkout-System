#ifndef _GOOD_H_
#define _GOOD_H_
#include <string>

const char *arr[5] = {"snack", "drink", "daily product", "clothes", "electronic product"};

class Good{
    
    public:
 
    
        
        //Constructor
        Good(std::string category, int id, std::string name, int price);
        
       
        //return the cotogory of the good
        int getCategory() const;


         //return the id of the good
        int getId() const;


        //return the name of the good
        std::string getName() const;

        // return the price of the good
        int getPrice() const
    
    protected:

        int id, price;
        std::string category, name;

};

#endif