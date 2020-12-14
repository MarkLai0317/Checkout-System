#include <string>
#include <vector>

class GoodsInventory{
    
    public:
 
        //Default Constructor
        GoodsInventory(){};
        
        //Constructor
        GoodsInventory(int id, int quantity, std::string name);
         
        
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