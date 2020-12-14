<<<<<<< HEAD
#include <string>
#include <vector>

class GoodsInInventory{
    
    public:
 
        //Default Constructor
        GoodsInInventory(){};
        
        //Constructor
        GoodsInInventory(int id, int quantity, std::string name);
         
        
        //return the id of the goods
        int getId() const;

        //return the quantity of the goods
        int getQuantity() const;
        
        //return the name of the goods
        std::string getName() const;
    
    private:
  
        int id, quantity;
        std::string name;

};