#ifndef _GOOD_H_
#define _GOOD_H_


const catogoryString;

class GoodsInventory{
    
    public:
 
        //Default Constructor
        GoodsInventory(){}
        
        //Constructor
        GoodsInventory(int ID, string category, string name) : id(id), category(category) name(name){}
        
        //return the id of the goods
        int getId() const;

        //return the cotogory of the goods
        int getCategory() const;

        //return the name of the goods
        std::string getName() const;
    
    private:

        int id;
        string category, name;

};

#endif