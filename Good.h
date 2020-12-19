#ifndef _GOOD_H_
#define _GOOD_H_

class GoodsInventory{
    
    public:
 
        //Default Constructor
        GoodsInventory(){};
        
        //Constructor
        GoodsInventory(int id, int category, string name);
        
        //return the id of the goods
        int getId() const;

        //return the cotogory of the goods
        int getCategory() const;

        //return the name of the goods
        std::string getName() const;
    
    private:

        int id, category;
        string name;

};

#endif