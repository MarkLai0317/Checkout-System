#ifndef _CASHIER_H
#define _CASHIER_H



#include <vector>
#include "GoodInventory.h"

#define INVALID -100 
#define BACK -1
#define QUIT -2
#define DELETE -3 


class CashierUI {





	
	void CashierSystem();





private:

	// 1.Need to see if we have the chosen category.
	//   If we don't have, print warning and return INVALID
	// 2.Return the valid category input.
	//   Input 'q' means quit, return QUIT.
	//   Input 'd' maens delete one goods have just choose, return DELETE
	// 3.when implementation, using string to get the input will be easier to identify invalid input
	//   so do other input
	int inputCategory();

	// 1.Need to see if we have the chosen ID
	//   If we don't have, it's a invalid input--> return INVALID.
	// 2.return the valid id input
	//   input 'b' means back to the last page, return BACK
	// 3.same as above 3.
	int inputId();


	// 1.Need to see if we have the chosen Quantity.
	//   If we don't have enough goods, tell customer that the goods has only X left
	//   and return INVALID
	// 	 
	// 2.return the valid id input
	//   input 'b' means back to choose id --> return BACK
	int inputQuantity();


	// recieve list of goods and print with nice format
	// need to show id, name, quantity, and price $  
	void printMenu(vector<GoodInventory>);

	// print reciept with reciept format like 7
	void printReciept();


	//delete one goods chosen by customer
	void deleteOneGoodChoosed();

	// delete reciept when purchase is canceled
	// the implement only need to delete reciept
	void purchaseCancel();


	//return the reciept to system and clean the reciept
	vector<GoodInventory> purchaseConfirm();


	// the list of goods that buyer has choose
	vector<GoodInventory> reciept;
	




};