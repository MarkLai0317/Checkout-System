#ifndef _MANAGERUI_H
#define _MANAGERUI_H

#include "Good.h"
#include "GoodInventory.h"
#include "GoodActivity.h"
#include "UserInterface.h"
#include "MainSystem.h"

class ManagerUI : public UserInterface{

    public:

        ManagerUI();

        void managerSystem();

    private:

        //刷新
        void refreshTable();

        //輸出
        void inventoryPrint();

        void activityPrint();

        //吃行為
        void nextOperation();

        void searchOp();

        //搜尋倉庫
        void inventorySearch();

        void invIdSearch();

        void invNameSearch();

        void invCategorySearch();

        //搜尋活動
        void activitySearch();

        void actTypeSearch();

        void actNameSearch();

        void actCategorySearch();


        //紀錄全部東西的table跟搜尋結果的table
        std::vector<GoodInventory> inventory_table, inventory_result;

        std::vector<std::vector<std::string> > activity_table, activity_result;

        //紀錄開始頁碼
        int begin;

    
    protected:
        //UserInterface繼承下來不會用到的 virtual function

        virtual void categoryPage() {}

        virtual void quantityPage() {}

        virtual int inputCategory() {return 0;}

        virtual int inputQuantity() {return 0;}

        virtual int quantityFix(int i, std::vector<GoodInventory> &menu) { return 0; }

        virtual int sizeOfReceipt() {return 0;}

        virtual void printReceipt() {}

        virtual void confirm() {}

        virtual void addReceipt() {}

        virtual void deleteOrder(int chosen_order) {}

};

#endif