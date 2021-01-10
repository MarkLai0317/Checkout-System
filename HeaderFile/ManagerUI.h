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

    protected:

        virtual void categoryPage() {}

        virtual void quantityPage() {}

        virtual int inputCategory() {return 0;}

        virtual int inputQuantity() {return 0;}

        virtual int quantityFix(int i, std::vector<GoodInventory> &menu) { return 0; }

        virtual int sizeOfReciept() {return 0;}

        virtual void printReciept() {}

        virtual void confirm() {}

        virtual void addReciept() {}

        virtual void deleteOrder(int chosen_order) {}

    private:

        void refreshTable();

        void inventoryPrint();

        void activityPrint();

        void nextOperation();

        void searchOp();

        void inventorySearch();

        void invIdSearch();

        void invNameSearch();

        void invCategorySearch();

        void activitySearch();

        void actTypeSearch();

        void actNameSearch();

        void actCategorySearch();

        std::vector<GoodInventory> inventory_table, inventory_result;

        std::vector<std::vector<std::string> > activity_table, activity_result;

        int begin;

};

#endif