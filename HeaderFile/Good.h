#ifndef _GOOD_H_
#define _GOOD_H_
#include <string>

const char *category_string[5] = {"snack", "drink", "daily_product", "clothes", "electronic_product"};

class Good{
    
    public:
 
    
        
        //Constructor
        Good(int input_id, std::string input_category, std::string input_name, int input_price);
        
       
        //return the cotogory of the good
        int getCategory() const;


         //return the id of the good
        int getId() const;


        //return the name of the good
        std::string getName() const;

        // return the price of the good
        int getPrice() const;
    
    protected:

        int id, price;
        std::string category, name;

};

#endif