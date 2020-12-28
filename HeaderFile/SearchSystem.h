#ifndef _SEARCHSYSTEM_H
#define _SEARCHSYSTEM_H

#include <vector>
#include "Good.h"
#include "GoodInventory.h"
#include "GoodActivity.h"

class SearchSystem{


    public:

        // return all goodInvantory of the input category
        vector<GoodInventory> findInventoryOfCategory(std::string input_category);

        //return the goodInventory of tech input id
        GoodInventory findInventoryOfId(int input_id);


        // Find the good of input id and set the quantity to input_quantity for reciept.     
        GoodInventory findInventoryOfIdAndSetQuantity(int input_id, int input_quantity);

        

        // put the reciept to database for processing 
        void purchaseConfirm(vector<GoodInventory> the_reciept);

        // see if the catogory input exist
        // if exist, return true.
        bool categoryExist(std::string input_category);


        // use id search the quantity of that good
        int findQuantityOfGood(int input_id);




    private:
    

        //find the specific id's good
        Good idToGood(int id);

        GoodInventory findGood(Good target);

        //find the specific category of goods, return empty vector if category is not exsist
        vector<Good> categoryToGoods(string category);

        vector<GoodActivity> searchInventory(Good target);

        vector<GoodActivity> searchActivity(Good target);

        vector<Good> tableToGoods(std::vector<std::string>);
        vector<GoodInventory> tableToInventories(std::vector<std::string>);
        vector<GoodActivity> tableToActivities(std::vector<std::string>);

}

#endif