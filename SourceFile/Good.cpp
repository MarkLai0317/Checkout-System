#include "../HeaderFile/Good.h"

//Constructor
Good::Good(int input_id, std::string input_category, std::string input_name, int input_price) : id(input_id), 
                                                                                                category(input_category),
                                                                                                name(input_name),
                                                                                                price(input_price)
                                                                                                {}


//return the cotogory of the good
int getCategory() const{
    return category;
}

//return the id of the good
int getId() const{
    return id;
}

//return the name of the good
std::string getName() const{
    return name;
}

// return the price of the good
int getPrice() const{
    return price;
}