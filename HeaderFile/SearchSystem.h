#ifndef _SERCHSYSTEM_H
#define _SERCHSYSTEM_H

#include <vector>
#include "../HeaderFile/Good.h"
#include "../HeaderFile/GoodInventory.h"
#include "../HeaderFile/GoodActivity.h"

#include "../HeaderFile/SearchSystem.h"

class SearchSystem{


    public:

        // return all goodInvantory of the input category
        GoodInventory findInventoryById(int input_id);

        //return the goodInventory of tech input id
        GoodInventory findInventoryByIdAndSetQuantity(int input_id, int input_quantity);

        // Find the good of input id and set the quantity to input_quantity for reciept.     
        vector<GoodInventory> findInventoriesByCategory(std::string input_category);

        // use id search the quantity of that good
        int findQuantityOfGood(int input_id);

        // put the reciept to database for processing 
        void purchaseConfirm(std::vector<GoodInventory>);

        
        void supplyConfirm(std::vector<GoodInventory>, std::vector<GoodInventory>);


    private:
    

        void addActivity();

        std::vector<Good> tableToGoods(std::vector<std::string>);
        std::vector<GoodInventory> tableToInventories(std::vector<std::string>);
        std::vector<GoodActivity> tableToActivities(std::vector<std::string>);

}

#endif