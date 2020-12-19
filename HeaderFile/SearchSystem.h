#ifndef _SERCHSYSTEM_H
#define _SERCHSYSTEM_H

#include <vector>
#include "Good.h"
#include "GoodInventory.h"
#include "GoodActivity.h"

class SearchSystem{


    public:



        


        // return all goodInvantory of the input category
        vector<GoodInventory> findGoodOfCategory(std::string input_category);

        //return the goodInventory of tech input id
        GoodInventory findGoodOfId(int input_id);


        // Find the good of input id and set the quantity to input_quantity for reciept.     
        GoodInventory findGoodOfIdAndSetQuantity(int input_id, int input_quantity);


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

        //find the specific id's status in Inventory
        vector<GoodActivity> searchInventory(Good target);

        //find the specific id's activiy
        vector<GoodActivity> searchActivity(Good target);

}

#endif