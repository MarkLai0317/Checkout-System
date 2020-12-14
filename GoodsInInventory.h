class GoodsInInventory{
    
    public:

        //Constructor
        GoodsInInventory();
        GoodsInInventory(int id, int quantity, string name);
        
        //return the id of the goods
        int getId() const;


        //return the quantity of the goods
        int getQuantity() const;
        
        //return the name of the goods
        string getName() const;
    private:
  
        int id, quantity;
        string name;

};