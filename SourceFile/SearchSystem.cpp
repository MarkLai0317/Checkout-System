#include "SearchSystem.h"

//return the goodInventory of tech input id
GoodInventory SearchSystem::findInventoryById(int input_id){
    FileConnector file("Inventory.csv");
    file.search("id", input_id)

    return tableToInventories(file.getResult())[0];
}

// Find the good of input id and set the quantity to input_quantity for reciept.     
GoodInventory SearchSystem::findInventoriesByIdAndSetQuantity(int input_id, int input_quantity){
    GoodInventory tmp = findInventoryById(input_id);

    return GoodInventory(tmp.getId(), tmp.getCategory(), tmp.getName(), tmp.getPrice(), input_quantity());
}

// return all goodInvantory of the input category
vector<GoodInventory> SearchSystem::findInventoriesByCategory(std::string input_category){
    FileConnector file("Inventory.csv");
    file.search("category", input_category);

    return tableToInventories(file.getResult());
}

// use id search the quantity of that good
int SearchSystem::findQuantityOfGood(int input_id){
    return findInventoryById(input_id).getQuantity();
}

// put the reciept to database for processing 
void SearchSystem::purchaseConfirm(vector<GoodInventory> the_reciept){
    FileConnector file("Inventory.csv");

    for(int i=0; i<the_reciept.size(); i++){
        string target_id = to_string(the_reciept[i].getId())
        file.search("id", target_id);
        std::vector<std::string> result = file.getResult()[0];
        file.update("id", target, "quantity", to_string(stoi(result[3]) - the_reciept.getQuantiy()));
    }

    file.cose():

    FileConnector file("Activity.csv");

    for(GoodInventory i : the_reciept){
        file.append(addActivity(i, "purchase"));
    }

    file.close();
}

void SearchSystem::supplyConfirm(vector<GoodInventory> old_reciept, vector<GoodInventory> new_reciept){
    FileConnector file("Inventory.csv");

    for(int i=0; i<old_reciept.size(); i++){
        string target_id = to_string(old_reciept[i].getId())
        file.search("id", target_id);
        std::vector<std::string> result = file.getResult()[0];
        file.update("id", target, "quantity", to_string(stoi(result[3]) - old_reciept.getQuantiy()));
    }

    for(int i=0; i<new_reciept.size(); i++){
        string id = to_string(new_reciept[i].getId())
             , category = new_reciept[i].getCategory()
             , name = new_reciept[i].getCategory()
             , price = to_string(new_reciept[i].getPrice())
             , quantity = to_string(new_reciept[i].getQuantity());
        file.append( vector<string> (id, category, name, price, quantity) );
    }

    file.close();
    
    FileConnector file("Activity.csv");

    for(GoodInventory i : old_reciept){
        file.append(addActivity(i, "supply"));
    }
    for(GoodInventory i : new_reciept){
        file.append(addActivity(i, "supply"));
    }

    file.close();
}

std::vector<std::string> SearchSystem::addActivity(GoodInventory input_good, string input_type){
    std::vector<std::string> tmp;
    tmp.push_back( getTimeString() );
    tmp.push_back( input_type );
    tmp.push_back(           input_good.getCategory() );
    tmp.push_back(           input_good.getName() );
    tmp.push_back( to_string(input_good.getPrice()) );
    tmp.push_back( to_string(input_good.getQuantity()) );
    return tmp;
}

std::vector<Good> SearchSystem::tableToGoods(std::vector<std::vector<std::string> > input){
    std::vector<Good> tmp;

    for(int i=0; i<input.size(); i++){
        // id(int), name(string), category(string), price(int)
        tmp.push_back( Good(stoi(input[i][0]), input[i][1], input[i][2], stoi(input[i][3])) );
    }

    return tmp;
}

std::vector<GoodInventory> SearchSystem::tableToInventories(std::vector<std::vector<std::string> > input){
    std::vector<GoodInventory> tmp;

    for(int i=0; i<input.size(); i++){
        // id(int), name(string), category(string), price(int)
        tmp.push_back( GoodInventory(stoi(input[i][0]), input[i][1], input[i][2], stoi(input[i][3]), stoi(input[i][4])) );
    }

    return tmp;
}

std::vector<GoodActivity> SearchSystem::tableToActivities(std::vector<std::vector<std::string> > input){
    std::vector<GoodInventory> tmp;

    for(int i=0; i<input.size(); i++){
        // id(int), name(string), category(string), price(int)
        tmp.push_back( GoodInventory(stoi(input[i][0]), input[i][1], input[i][2], stoi(input[i][3]), stoi(input[i][4]), StringToDatetime(input[i][5])) );
    }

    return tmp;
}

