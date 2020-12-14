#include <string>
#include <vector>

using get = std::string (*)(void);

class GoodsInventory{
    
    public:
 
        //Default Constructor
        GoodsInventory(){};
        
        //Constructor
        GoodsInventory(int id, int quantity, std::string name);
         
        
        //return the id of the goods
        std::string getId() const;

        //return the quantity of the goods
        std::string getQuantity() const;
        
        //return the name of the goods
        std::string getName() const;



    
    private:
    
        int id, quantity;

        std::string name, catogory;

         



};