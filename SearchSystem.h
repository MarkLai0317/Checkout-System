#ifndef _SERCHSYSTEM_H
#define _SERCHSYSTEM_H

#include <vector>
#include "Good.h"
#include "GoodInventory.h"
#include "GoodActivity.h"

class SearchSystem{


    public:






        // return all goodInvantory of the input category
        vector<GoodInventory> findGoodsOfCategory(std::string input_category);


        // see if the catogory input exist
        // if exist, return true.
        bool categoryExist(std::string input_category);

        // use id search the quantity of that good
        int findQuantityOfGood(int input_id);




    private:
    
        //find the specific id's good
        Good idToGood(int id);

        GoodInventory findGood(Good target);

        //find the specific category of goods
        vector<Good> categoryToGoods(int category);

        //find the specific id's status in Inventory
        vector<GoodActivity> searchInventory(Good target);

        //find the specific id's activiy
        vector<GoodActivity> searchActivity(Good target);

}

#endif