#ifndef _CASHIERUI_H
#define _CASHIERUI_H

#include <vector>
#include "../HeaderFile/GoodInventory.h"
#include "../HeaderFile/UserInterface.h"
#include "../HeaderFile/MainSystem.h"





//================in UserInterface==================
//enum status {CATEGORY_STATUS, ID_STATUS, QUANTITY_STATUS, RECIEPT_STATUS};


class CashierUI: public UserInterface{



public:
	
	CashierUI(){}

	void cashierSystem();

private:


	// things to do in category page
	void categoryPage();

	
	void quantityPage();


	// 1.Need to see if we have the chosen category.
	//   If we don't have, print warning and return INVALID
	// 2.Return the valid category input.
	//   Input 'q' means quit, return QUIT.
	//   Input 's' means see receipt, return RECIEPT
	//
	// 3.When implementation, using string to get the input will be easier to identify invalid input
	//   so do other input.
	// 4.if input_invalid == true
	//  --> print some text to tell the user
	int inputCategory();



	// 1.Need to see if we have the chosen Quantity.
	//   If we don't have enough goods, tell customer that the goods has only X left
	//   and return INVALID
	// 	 
	// 2.return the valid id input
	//   input 'b' means back to choose id --> return BACK
	int inputQuantity();


	//  see the size of reciept
	int sizeOfReciept();
	
	// print reciept with reciept format like 7
	// 每項要有編號
	// 最後需要print總價
	void printReciept();


	// fix quntity print in menu
	int quantityFix(int i, std::vector<GoodInventory> &menu);

	// confirm the  receipt
	void confirm();

	// add the good choose to the receipt
	void addReceipt();

	//delete one goods chosen by customer
	void deleteOrder(int order);



private:



	std::vector<GoodInventory> receipt;

	


};

#endif
