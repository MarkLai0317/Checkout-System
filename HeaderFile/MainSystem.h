#ifndef _MAINSYSTEM_H
#define _MAINSYSTEM_H

#include <vector>
#include "../HeaderFile/Good.h"
#include "../HeaderFile/GoodInventory.h"
#include "../HeaderFile/GoodActivity.h"

class MainSystem{


    public:

        //return all in inventory
        std::vector< GoodInventory > getInventory();
        //return all in actibity
        std::vector< std::vector<std::string> > getActivity();
        
        
        // return all goodInvantory of the input category
        GoodInventory findInventoryById(int input_id);

        GoodInventory findInventoryByName(std::string input_name);

        //return the goodInventory of tech input id
        GoodInventory findInventoryByIdAndSetQuantity(int input_id, int input_quantity);

        // Find the good of input id and set the quantity to input_quantity for receipt.     
        std::vector<GoodInventory> findInventoriesByCategory(std::string input_category);

        // use id search the quantity of that good
        int findQuantityOfGood(int input_id);

        // put the receipt to database for processing 
        void purchaseConfirm(std::vector<GoodInventory>);
        
        void supplyConfirm(std::vector<GoodInventory>, std::vector<GoodInventory>);


    private:
    

        std::vector<std::string> addActivity(GoodInventory good, std::string op_type);

        std::vector<Good> tableToGoods(std::vector< std::vector<std::string> >);
        std::vector<GoodInventory> tableToInventories( std::vector< std::vector<std::string> > );
        //std::vector<GoodActivity> tableToActivities( std::vector< std::vector<std::string> > );

};

#endif