class System{


    private:
    
        //find the specific id's good
        Good idToGood(int id);

        GoodsInventory findGood(Good target);

        //find the specific category of goods
        vector<Good> categoryToGoods(int category);

        //find the specific id's status in Inventory
        vector<GoodsActivity> searchActivity(Good target);

        //find the specific id's activiy
        vector<GoodsActivity> searchActivity(Good target);

}