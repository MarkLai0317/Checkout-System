#include <iostream>
#include <vector>
#include "../HeaderFile/FileConnector.h"
#include "../HeaderFile/MainSystem.h"

using namespace std;

int main(){


    system("./data_init");

    //declaration of ss
    MainSystem sys;
    //declaraion of supply
    vector<GoodInventory> _old, _new;

    cout << "type enter to supply new product: "; cin.get();

    //supply new product
    _new.push_back( GoodInventory(123, "罐裝泡麵", "味味排骨", 1000, 100) );
    _new.push_back( GoodInventory(123, "罐裝泡麵", "統一牛肉", 1200, 100) );
    _new.push_back( GoodInventory(123, "包裝餅乾", "湖池屋", 10, 1000) );
    sys.supplyConfirm(_old, _new);
    _old.clear(); _new.clear();

    cout << "type enter to add new purchase: "; cin.get();
    //add new purchase
    vector<GoodInventory> reciept;
    reciept.push_back( GoodInventory(3, "包裝餅乾", "湖池屋", 10, 90) );
    reciept.push_back( GoodInventory(2, "碗裝泡麵", "統一牛肉", 1200, 10) );
    sys.purchaseConfirm( reciept );

    cout << "type enter to supply new and old product: "; cin.get();
    //supply new and old product
    _old.push_back( GoodInventory(1, "碗裝泡麵", "味味排骨", 1000, 100) );
    _old.push_back( GoodInventory(2, "碗裝泡麵", "統一牛肉", 1200, 100) );
    _old.push_back( GoodInventory(3, "包裝餅乾", "湖池屋", 10, 1000) );
    _new.push_back( GoodInventory(123, "包裝餅乾", "點心麵", 10000, 3) );
    sys.supplyConfirm(_old, _new);

    cout << "system close" << endl;


}