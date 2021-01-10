#ifndef _SUPPLIERUI_H
#define _SUPPLIERUI_H


#include <string>
#include <vector>

#include "UserInterface.h"
#include "GoodInventory.h"

class SupplierUI : public UserInterface{

	
public:
	
	
	SupplierUI(){}

	void supplierSystem();


private:


	void categoryPage();

	void quantityPage();

	void namePage();

	void pricePage();

	// 1.Need to see if we have the chosen category.
	//   If we don't have, print warning and return INVALID
	//
	// 2.return valid input
	//   Input 'o' means add good that already exist, return OLDGOOD
	//   Input 'n' means user want to add new goods that didn't exist in database
	//   --> return NEWGOOD.
	//   Input 'q' means quit system, return QUIT.
    //   Inpur 's' means see the supply list, return RECIEPT.
	//
	// 3. If input valid category, return the category defined in UserInterface.   
	int inputCategory();


	// 1. Need to see if the Name  already exist
	//    if exist, return Invalid
	// 2. Input 'b', return "BACK".
	// 
	// 3. if inputName is valid,assign the name to name_now and return VALID.
	int inputName();

	// 1. if input is positive integer, return the price.
	//    else return INVAID.
	int inputPrice();


	// 1. if input is positive integer, return the price.
	//    else return INVAID.
	int inputQuantity();


	int sizeOfReceipt();


	// print out the goods that has been input 
	// into receipt, but don't need to print total price
	void printReceipt();

	int quantityFix(int i, std::vector<GoodInventory> &menu);

	// confirm the old and new receipt
	void confirm();

	void addReceipt();


	void deleteOrder(int chosen_order);



private:


	std::string name_now;

	int price_now;
	
	//add new good or old good status
	// if old ->OLDGOOD
	//else if new -> NEWGOOD
	status old_new_status = OLDGOOD_STATUS;


	// A vector that temporary store the input
	// of user and need to be printed after input a object

	std::vector<GoodInventory> old_receipt;
	
	std::vector<GoodInventory> new_receipt;


};

#endif