#include <iostream>
#include <fstream>
using namespace std;

int main(){

    system("rm ../data/Activity.csv");
    system("rm ../data/Inventory.csv");

    ofstream inventory("../data/Inventory.csv");
    inventory << "id,category,name,price,quantity";
    inventory.close();

    ofstream activity("../data/Activity.csv");
    if( activity.is_open() ) cout << "Activity.csv open success! " << endl;
    activity << "time,action,category,name,price,quantity";
    activity.close();

}