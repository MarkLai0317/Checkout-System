#include <iostream>
#include "../HeaderFile/SearchSystem.h"
#include "../HeaderFile/FileConnector.h"
#include "../HeaderFile/ConvertorOfTimeAndString.h"

//return the goodInventory of tech input id
GoodInventory SearchSystem::findInventoryById(int input_id){
    FileConnector file("Inventory.csv");
    file.search("id", std::to_string(input_id));

    return tableToInventories(file.getResult())[0];
}

GoodInventory SearchSystem::findInventoryByName(std::string input_name){
    FileConnector file("Inventory.csv");
    file.search("name", input_name);

    return tableToInventories(file.getResult())[0];
}

// Find the good of input id and set the quantity to input_quantity for reciept.     
GoodInventory SearchSystem::findInventoryByIdAndSetQuantity(int input_id, int input_quantity){
    GoodInventory tmp = findInventoryById(input_id);

    return GoodInventory(tmp.getId(), tmp.getCategory(), tmp.getName(), tmp.getPrice(), input_quantity);
}

// return all goodInvantory of the input category
std::vector<GoodInventory> SearchSystem::findInventoriesByCategory(std::string input_category){
    FileConnector file("Inventory.csv");
    file.search("category", input_category);

    return tableToInventories(file.getResult());
}

// use id search the quantity of that good
int SearchSystem::findQuantityOfGood(int input_id){
    return findInventoryById(input_id).getQuantity();
}

// put the reciept to database for processing 
void SearchSystem::purchaseConfirm(std::vector<GoodInventory> the_reciept){
    FileConnector inventory_file("Inventory.csv");

    for(int i=0; i<the_reciept.size(); i++){
        std::string target_id = std::to_string(the_reciept[i].getId());
        inventory_file.search("id", target_id);
        std::vector<std::string> result = inventory_file.getResult()[0];
        inventory_file.update("id", target_id, "quantity", std::to_string(stoi(result[4]) - the_reciept[i].getQuantity()));
    }

    //file.close():

    FileConnector activity_file("Activity.csv");

    for(GoodInventory i : the_reciept){
        activity_file.append(addActivity(i, "purchase"));
    }

    //file.close();
}

void SearchSystem::supplyConfirm(std::vector<GoodInventory> old_reciept, std::vector<GoodInventory> new_reciept){
    std::cout << "opening Inventory.cvs" << std::endl;
    FileConnector inventory_file("Inventory.csv");

    std::cout << "Inserting old good into Inventory..." << std::endl;
    for(int i=0; i<old_reciept.size(); i++){
        std::string target_id = std::to_string(old_reciept[i].getId());
        inventory_file.search("id", target_id);
        std::vector<std::string> result = inventory_file.getResult()[0];
        inventory_file.update("id", target_id, "quantity", std::to_string(stoi(result[4]) + old_reciept[i].getQuantity()));
    }

    std::cout << "Appending new good into Inventory..." << std::endl;
    for(int i=0; i<new_reciept.size(); i++){
        std::cout << "Inventory size is " << inventory_file.getResult().size() << std::endl;
        std::string id = std::to_string(inventory_file.getResult().size())
             , category = new_reciept[i].getCategory()
             , name = new_reciept[i].getName()
             , price = std::to_string(new_reciept[i].getPrice())
             , quantity = std::to_string(new_reciept[i].getQuantity());


        inventory_file.append( {id, category, name, price, quantity} );

    }

    //file.close();
    
    std::cout << "Appending new activity..." << std::endl;
    FileConnector activity_file("Activity.csv");

    for(GoodInventory i : old_reciept){
        activity_file.append(addActivity(i, "supply"));
    }
    for(GoodInventory i : new_reciept){
        activity_file.append(addActivity(i, "supply"));
    }

    //file.close();
}

std::vector<std::string> SearchSystem::addActivity(GoodInventory input_good, std::string input_type){
    std::vector<std::string> tmp;
    tmp.push_back( getTimeString() );
    tmp.push_back( input_type );
    tmp.push_back(           input_good.getCategory() );
    tmp.push_back(           input_good.getName() );
    tmp.push_back( std::to_string(input_good.getPrice()) );
    tmp.push_back( std::to_string(input_good.getQuantity()) );
    return tmp;
}

std::vector<Good> SearchSystem::tableToGoods(std::vector<std::vector<std::string> > input){
    std::vector<Good> tmp;

    for(int i=0; i<input.size(); i++){
        // id(int), name(string), category(string), price(int)
        tmp.push_back( Good(stoi(input[i][0]), input[i][1], input[i][2], stoi(input[i][3])) );
    }

    if(tmp.size())
        return tmp;
    else
    {
        std::cout << "empty search!" << std::endl;
        tmp.push_back(Good(-1, "-1", "-1", -1));
        return tmp;
    }
    
}

std::vector<GoodInventory> SearchSystem::tableToInventories(std::vector<std::vector<std::string> > input){
    std::vector<GoodInventory> tmp;

    for(int i=0; i<input.size(); i++){
        // id(int), name(string), category(string), price(int)
        tmp.push_back( GoodInventory(stoi(input[i][0]), input[i][1], input[i][2], stoi(input[i][3]), stoi(input[i][4])) );
    }

    if(tmp.size())
        return tmp;
    else
    {
        std::cout << "empty search!" << std::endl;
        tmp.push_back(GoodInventory(-1, "-1", "-1", -1, -1));
        return tmp;
    }
}

std::vector<GoodActivity> SearchSystem::tableToActivities(std::vector<std::vector<std::string> > input){
    std::vector<GoodActivity> tmp;

    for(int i=0; i<input.size(); i++){
        // id(int), name(string), category(string), price(int)
        tmp.push_back( GoodActivity(stoi(input[i][0]), input[i][1], input[i][2], stoi(input[i][3]), stoi(input[i][4]), StringToDatetime(input[i][5])) );
    }

    if(tmp.size())
        return tmp;
    else
    {
        std::cout << "empty search!" << std::endl;
        tmp.push_back(GoodActivity(-1, "-1", "-1", -1, -1, StringToDatetime(getTimeString())));
        return tmp;
    }
}