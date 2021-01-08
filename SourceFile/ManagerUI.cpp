#include <iostream>
#include <vector>
#include <iomanip>
#include <string.h>
#include "../HeaderFile/ManagerUI.h"

#define PAGE_SIZE 10

using namespace std;

ManagerUI::ManagerUI(){
    //cout << "constructing ManagerUI..." << endl;
    begin = 0;
    this->page_status = INVENTORY_PAGE;
    inventory_result = inventory_table = search.getInventory();
    activity_result = activity_table = search.getActivity();
}

void ManagerUI::managerSystem(){

    cout << "Begin?" << endl; cin.get();

    while( !terminate ){

        this->refreshTable();

        if( page_status == INVENTORY_PAGE ){
            cout << "------------------------------" << begin << "~" << ((begin + PAGE_SIZE)<inventory_result.size() ? begin+PAGE_SIZE : inventory_result.size()) << "--------------------------------" << endl;
        }else if ( page_status == ACTIVITY_PAGE ){
            cout << "------------------------------" << begin << "~" << ((begin + PAGE_SIZE)<activity_result.size() ? begin+PAGE_SIZE : activity_result.size()) << "--------------------------------" << endl;
        }
        
        cout << "Press 1: inventory page, 2: activity page, s: search in this page, q: quit"  << endl;

        this->nextOperation();
    }

}

void ManagerUI::refreshTable(){
    clearScreen();
    if( page_status == INVENTORY_PAGE ){
        this->inventoryPrint();
    }else if( page_status == ACTIVITY_PAGE ){
        this->activityPrint();
    }
}

void ManagerUI::nextOperation(){
    //初始化，才不會卡在搜尋結果
    inventory_result = inventory_table, activity_result = activity_table;

    bool input_success = false;
    while( !input_success ){
        char op = getKeyboardChar();

        input_success = true;
        if(op == '1'){
            begin = 0;
            this->page_status = INVENTORY_PAGE;
        }else if( op == '2' ){
            begin = 0;
            this->page_status = ACTIVITY_PAGE;
        }else if( op == 's'){
            this->searchOp();
        }else if( op =='q' ){
            this->terminate = true;
        }else if( op==',' ){
            if(begin >= PAGE_SIZE) begin -= PAGE_SIZE;
        }else if( op=='.' ){
            if(page_status == INVENTORY_PAGE && begin + PAGE_SIZE <= inventory_result.size())
                begin += PAGE_SIZE;
            else if(page_status == ACTIVITY_PAGE && begin + PAGE_SIZE <= activity_result.size())
                begin += PAGE_SIZE;
        }else{
            input_success = false;
        }
    }
}

void ManagerUI::inventoryPrint(){
    cout << BACK_GROUND_WHITE << FORE_GROUND_BLACK;
    for(int i=begin; i<inventory_result.size() && i<begin+PAGE_SIZE; i++){
        cout << inventory_result[i].getId() << " " << inventory_result[i].getCategory() << " " << inventory_result[i].getName() << " " << inventory_result[i].getPrice() << " " << inventory_result[i].getQuantity() << endl;
    }
    cout << RESET;
}

void ManagerUI::activityPrint(){
    cout << BACK_GROUND_BLUE << FORE_GROUND_BLACK;
    cout << "|" << "       時間        " << "|" << "|" << " supply/purchase "  << "|" << "|" << "   種類   " << "|" << "|" << "      品名      " << "|" << "|" << " 價格 " << "|" << "|" << " 庫存 " << "|" << endl;
    cout << BACK_GROUND_WHITE << FORE_GROUND_BLACK;
    for(int i=begin; i<activity_result.size() && i<begin+PAGE_SIZE; i++){
        for(int j=0; j<activity_result[0].size(); j++){
            //if(j==1) cout << left << "|" << setw(12) << activity_result[i][j] << right << setw(6) << "|" << BACK_GROUND_WHITE << FORE_GROUND_BLACK;
            //else if(j==2) cout << left << "|" << setw(12) << activity_result[i][j] << right << setw(3 - 5+activity_result[i][j].size()/3) << "|" << BACK_GROUND_WHITE << FORE_GROUND_BLACK;
            //else cout << "|" << activity_result[i][j] << "|" << BACK_GROUND_WHITE << FORE_GROUND_BLACK;
            cout << activity_result[i][j] << " " << BACK_GROUND_WHITE << FORE_GROUND_BLACK;
        }
        cout << RESET << endl;
    }
}

void ManagerUI::searchOp(){
    if( page_status ==  INVENTORY_PAGE ){
        this->inventorySearch();
    }else if( page_status == ACTIVITY_PAGE ){
        this->activitySearch();
    }
}

void ManagerUI::inventorySearch(){
    inventory_result.clear();
    cout << "--------------------------------------------------------------" << endl;
    cout << "Search by i: id, n: name, c: category, b: back" << endl;

    bool input_success = false;
    while( !input_success ){
        char op = getKeyboardChar();

        input_success = true;
        if(op == 'i'){
            this->invIdSearch();
        }else if( op == 'n' ){
            this->invNameSearch();
        }else if( op == 'c'){
            this->invCategorySearch();
        }else if( op == 'b' ){
            this->page_status = INVENTORY_PAGE;
            inventory_result = inventory_table;
        }else{
            input_success = false;
        }
    }
}

void ManagerUI::invIdSearch(){
    string input;
    cout << "Input ID: "; cin >> input;

    for(int i=0; i<inventory_table.size(); i++){
        if( inventory_table[i].getId() ==  stoi(input)){
            inventory_result.push_back( inventory_table[i] );
            return ;
        }
    }
}

void ManagerUI::invNameSearch(){
    string input;
    cout << "Input Name: "; cin >> input;

    for(int i=0; i<inventory_table.size(); i++){
        if( inventory_table[i].getName() ==  input){
            inventory_result.push_back( inventory_table[i] );
            return ;
        }
    }
}

void ManagerUI::invCategorySearch(){
    string input;
    cout << "Input Category: "; cin >> input;

    for(int i=0; i<inventory_table.size(); i++){
        if( inventory_table[i].getCategory() ==  input){
            inventory_result.push_back( inventory_table[i] );
        }
    }
}

void ManagerUI::activitySearch(){
    activity_result.clear();
    cout << "--------------------------------------------------------------" << endl;
    cout << "Search by t: type, n: name, c: category, b: back" << endl;

    bool input_success = false;
    while( !input_success ){
        char op = getKeyboardChar();

        input_success = true;
        if(op == 't'){
            this->actTypeSearch();
        }else if( op == 'n' ){
            this->actNameSearch();
        }else if( op == 'c'){
            this->actCategorySearch();
        }else if( op == 'b' ){
            this->page_status = ACTIVITY_PAGE;
            activity_result = activity_table;
        }else{
            input_success = false;
        }
    }
}

void ManagerUI::actTypeSearch(){
    string input;
    cout << "--------------------------------------------------------------" << endl;
    cout << "p: purchase s: supply" << flush;

    bool input_success = false;
    while( !input_success ){
        char op = getKeyboardChar();

        input_success = true;
        if(op == 'p'){
            input = "purchase";
        }else if( op == 's' ){
            input = "supply";
        }else{
            input_success = false;
        }
    }


    for(int i=0; i<activity_table.size(); i++){
        if( activity_table[i][1] ==  input){
            activity_result.push_back( activity_table[i] );
        }
    }
}

void ManagerUI::actNameSearch(){
    string input;
    cout << "Input Name: "; cin >> input;

    for(int i=0; i<activity_table.size(); i++){
        if( activity_table[i][3] ==  input){
            activity_result.push_back( activity_table[i] );
        }
    }
}

void ManagerUI::actCategorySearch(){
    string input;
    cout << "Input Category: "; cin >> input;

    for(int i=0; i<activity_table.size(); i++){
        if( activity_table[i][2] ==  input){
            activity_result.push_back( activity_table[i] );
        }
    }
}