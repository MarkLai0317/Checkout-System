#ifndef _SUPPLIERUI_H
#define _SUPPLIERUI_H


#include <string>
#include <vector>
#include "../HeaderFile/SearchSystem.h"
#include "../HeaderFile/UserInterface.h"
#include "../HeaderFile/GoodInventory.h"

class SupplierUI : public UserInterface{

	
public:
	
	
	SupplierUI(){}

	void supplierSystem();

	// Get all the needed iput and put them into GoodsInventory.
	// The Good need to be put into activity_buffer for printing the table
	// ,and return the Goods to the system
	//===============uncertain==================
	//GoodsInventory inputGoods();


private:



	void categoryPage();

	void quantityPage();

	void namePage();

	void pricePage();
	// 
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



	// 1.Input the Nth order of the reciept that user want to delete and return N(數字) 
	//   Input 'c' means comfirm the reciept, return CONFIRM.
	//   Input 'b' means back to last page, return BACK.
	//================in UserInterface==================
	//int inputReciept();

	int sizeOfReciept();

	

	//================in UserInterface==================
	//void quantityPage();


	// print out the goods that has been input 
	// into reciept, but don't need to print total price
	void printReciept();


	// confirm the old and new reciept
	void confirm();

	void addReciept();


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
	std::vector<GoodInventory> old_reciept;
	std::vector<GoodInventory> new_reciept;

};

#endif