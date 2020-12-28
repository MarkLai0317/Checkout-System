#include <iostream>
#include <fstream>
using namespace std;

int main(){

    system("rm ../data/Activity.csv");
    system("rm ../data/Inventory.csv");

    fstream activity("../data/Activity.csv", fstream::out);
    activity << "time,action,category,name,price,quantity";
    activity.close();

    fstream inventory("../data/Inventory.csv", fstream::out);
    inventory << "id,category,name,price,quantity";
    inventory.close();

}