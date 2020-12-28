//Constructor
GoodInventory(int input_id, std::string input_category, std::string input_name, int input_price, int input_quantity) : Good(input_id, input_category, input_name, input_price),
                                                                                                                        quantity(input_quantity)
                                                                                                                        {}

//return the quantity of the goods
int getQuantity() const{
    return quantity;
}