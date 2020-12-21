//return the goodInventory of tech input id
GoodInventory findInventoryById(int input_id){
    FileConnector file("../data/Inventory.csv");
    file.search("id", input_id)

    return tableToInventories(file.getResult())[0];
}

// Find the good of input id and set the quantity to input_quantity for reciept.     
GoodInventory findInventoriesByIdAndSetQuantity(int input_id, int input_quantity){
    GoodInventory tmp = findInventoryById(input_id);

    return GoodInventory(tmp.getId(), tmp.getCategory(), tmp.getName(), tmp.getPrice(), input_quantity());
}

// return all goodInvantory of the input category
vector<GoodInventory> findInventoriesByCategory(std::string input_category){
    FileConnector file("Inventory.csv");
    file.search("category", input_category);

    return tableToInventories(file.getResult());
}

// use id search the quantity of that good
int findQuantityOfGood(int input_id){
    return findInventoryById(input_id).getQuantity();
}

// put the reciept to database for processing 
void purchaseConfirm(vector<GoodInventory> the_reciept){
    FileConnector file("Inventory.csv");
    for(int i=0; i<the_reciept.size(); i++){
        string 
        file.update();
    }
}

// see if the catogory input exist
// if exist, return true.
bool categoryExist(std::string input_category);




std::vector<Good> tableToGoods(std::vector<std::string>);
std::vector<GoodInventory> tableToInventories(std::vector<std::string>);
std::vector<GoodActivity> tableToActivities(std::vector<std::string>);

