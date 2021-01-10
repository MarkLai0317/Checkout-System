#include <iostream>
#include <vector>
#include <iomanip>
#include <string.h>
#include "../HeaderFile/ManagerUI.h"

#define PAGE_SIZE 10
#define CHINESE_LEN 2/3

#define INVENTORY_ROW_LEN 92
#define ACTIVITY_ROW_LEN 132

using namespace std;

ManagerUI::ManagerUI(){
    //cout << "constructing ManagerUI..." << endl;
    begin = 0;
    //cout << "Initialize to Inventory Page" << endl;
    this->page_status = INVENTORY_PAGE;
    inventory_result = inventory_table = search.getInventory();
    activity_result = activity_table = search.getActivity();
}

void ManagerUI::managerSystem(){

    //cout << "Begin?" << endl; cin.get();

    while( !terminate ){

        this->refreshTable();

        if( page_status == INVENTORY_PAGE ){
            cout << "------------------------------" << begin << "~" << ((begin + PAGE_SIZE)<inventory_result.size() ? begin+PAGE_SIZE : inventory_result.size()) << "--------------------------------" << endl;
        }else if ( page_status == ACTIVITY_PAGE ){
            cout << "------------------------------" << begin << "~" << ((begin + PAGE_SIZE)<activity_result.size() ? begin+PAGE_SIZE : activity_result.size()) << "--------------------------------" << endl;
        }
        
        cout << "Press 1: 庫存頁面, 2: 進出貨紀錄頁面, s: 搜尋, q: 退出"  << endl;

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

    bool input_success = false;
    while( !input_success ){
        char op = getKeyboardChar();

        input_success = true;
        if(op == '1'){
            //初始化，才不會卡在搜尋結果
            inventory_result = inventory_table, activity_result = activity_table;
            begin = 0;
            this->page_status = INVENTORY_PAGE;
        }else if( op == '2' ){
            //初始化，才不會卡在搜尋結果
            inventory_result = inventory_table, activity_result = activity_table;
            begin = 0;
            this->page_status = ACTIVITY_PAGE;
        }else if( op == 's'){
            // 要做 Search
            this->searchOp();
        }else if( op =='q' ){
            //要退出
            this->terminate = true;
        }else if( op==',' ){
            //上一頁
            if(begin >= PAGE_SIZE)
                begin -= PAGE_SIZE;
        }else if( op=='.' ){
            //下一頁
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
    cout << "|" << "   ID   " << "|" <<  "|" << "     種類     " << "|" << "|" << "          品名          " << "|" << "|"<< "       價格       " << "|" << "|" << "       庫存       "  << "|" << RESET << endl;

    for(int i=begin; i<inventory_result.size() && i<begin+PAGE_SIZE; i++){
        printborder( INVENTORY_ROW_LEN );
        cout << endl;

        string tmp="", conv;

        conv = to_string(inventory_result[i].getId());
        tmp.push_back(' ');
        tmp += conv;
        for (int cnt = 0; cnt < 9 - conv.size(); cnt++) 
            tmp.push_back(' ');
        conv.clear();

        conv = inventory_result[i].getCategory();
        tmp.push_back(' ');
        tmp += conv;
        for (int cnt = 0; cnt < 15 - conv.size()*CHINESE_LEN; cnt++)
            tmp.push_back(' ');
        conv.clear();

        conv = inventory_result[i].getName();
        tmp.push_back(' ');
        tmp += conv;
        for (int cnt = 0; cnt < 25 - conv.size()*CHINESE_LEN; cnt++)
            tmp.push_back(' ');
        conv.clear();

        conv = to_string(inventory_result[i].getPrice());
        tmp.push_back(' ');
        tmp += conv;
        for (int cnt = 0; cnt < 19 - conv.size(); cnt++)
            tmp.push_back(' ');
        conv.clear();

        conv = to_string(inventory_result[i].getQuantity());
        tmp.push_back(' ');
        tmp += conv;
        for (int cnt = 0; cnt < 19 - conv.size(); cnt++)
            tmp.push_back(' ');
        conv.clear();

        printcontent_w(tmp);
        cout << endl;

    }
    
}

void ManagerUI::activityPrint(){
    cout << BACK_GROUND_WHITE << FORE_GROUND_BLACK;
    cout << "|" << "        時間        " << "|" << "|" << "   supply/purchase  "  << "|" << "|" << "        種類        " << "|" << "|" << "        品名        " << "|" << "|" << "        價格        " << "|" << "|" << "       進貨量       " << "|" << RESET << endl;

    for(int i=begin; i<activity_result.size() && i<begin+PAGE_SIZE; i++){
        printborder( ACTIVITY_ROW_LEN );
        cout << endl;
        
        string tmp;
        for(int j=0; j<activity_result[0].size(); j++){  
            tmp.push_back(' ');
            tmp += activity_result[i][j];
            if(j == 2 || j == 3)
                for (int cnt=0; cnt< 21 - activity_result[i][j].size()*CHINESE_LEN; cnt++)
                    tmp.push_back(' ');
            else
                for (int cnt=0; cnt < 21 - activity_result[i][j].size(); cnt++)
                    tmp.push_back(' ');
        }
        printcontent_w(tmp);
        cout << endl;
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
    cout << "搜尋方式 i: ID, n: 品名, c: 種類, b: 上一頁" << endl;

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
    cout << "輸入 ID: "; cin >> input;

    for(int i=0; i<inventory_table.size(); i++){
        if( inventory_table[i].getId() ==  stoi(input)){
            inventory_result.push_back( inventory_table[i] );
            return ;
        }
    }
}

void ManagerUI::invNameSearch(){
    string input;
    cout << "輸入 名稱: "; cin >> input;

    for(int i=0; i<inventory_table.size(); i++){
        if( inventory_table[i].getName() ==  input){
            inventory_result.push_back( inventory_table[i] );
            return ;
        }
    }
}

void ManagerUI::invCategorySearch(){
    string input;
    cout << "輸入 種類: "; cin >> input;

    for(int i=0; i<inventory_table.size(); i++){
        if( inventory_table[i].getCategory() ==  input){
            inventory_result.push_back( inventory_table[i] );
        }
    }
}

void ManagerUI::activitySearch(){
    activity_result.clear();
    cout << "--------------------------------------------------------------" << endl;
    cout << "搜尋 t: 進/出貨, n: 名字, c: 種類, b: 上一頁" << endl;

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
    cout << "p: 賣出 s: 進貨" << flush;

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
    cout << "輸入名稱: "; cin >> input;

    for(int i=0; i<activity_table.size(); i++){
        if( activity_table[i][3] ==  input){
            activity_result.push_back( activity_table[i] );
        }
    }
}

void ManagerUI::actCategorySearch(){
    string input;
    cout << "輸入種類: "; cin >> input;

    for(int i=0; i<activity_table.size(); i++){
        if( activity_table[i][2] ==  input){
            activity_result.push_back( activity_table[i] );
        }
    }
}