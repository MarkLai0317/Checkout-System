#ifndef _CASHIER_H
#define _CASHIER_H



#include <vector>
#include "GoodInventory.h"



#define SNACK 0
#define DRINK 1
#define DAILY 2
#define CLOTHES 3
#define ELECTRONIC 4
#define INVALID -100 
#define BACK -1
#define QUIT -2
#define DELETE -3
#define CONFIRM -4 
#define RECIEPT -5


<<<<<<< Updated upstream
<<<<<<< Updated upstream

enum status {CATEGORY_STATUS, ID_STATUS, QUANTITY_STATUS, RECIEPT_STATUS};

=======
enum status {CATEGORY_STATUS, ID_STATUS, QUANTITY_STATUS, RECIEPT};
>>>>>>> Stashed changes
=======
enum status {CATEGORY_STATUS, ID_STATUS, QUANTITY_STATUS, RECIEPT};
>>>>>>> Stashed changes

class CashierUI {





	
	void CashierSystem();





private:

	// 1.Need to see if we have the chosen category.
	//   If we don't have, print warning and return INVALID
	// 2.Return the valid category input.
	//   Input 'q' means quit, return QUIT.
	//   Input 's' means see reciept, return RECIEPT
	//
	// 3.When implementation, using string to get the input will be easier to identify invalid input
	//   so do other input.
	// 4.if input_invalid == true
	//  --> print some text to tell the user
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

    
	//1.Input 'd' means delete a chose good, return DELETE.
	//  Input 'c' means comfirm the reciept, return CONFIRM.
	//  Input 'b' means back to last page, return BACK.
    int inputReciept();


	// recieve list of goods and print with nice format
	// need to show id, name, quantity, and price $  
	void printMenu(vector<GoodInventory>);

	// print reciept with reciept format like 7
	void printReciept();




	// things to do in quantity page
	void recieptPage();

	// things to do in quantity page
	void recieptPage();

	// things to do in quantity page
	void recieptPage();

	//delete one goods chosen by customer
	void deleteOneGoodChoosed();

	// delete reciept when purchase is canceled
	// the implement only need to delete reciept
	void purchaseCancel();

	// caculate the total price
    int caculateTotalPrice();

    // after choose the quantity
    int addToReciept(int quantity);

	//return the reciept to system and clean the reciept
	vector<GoodInventory> purchaseConfirm();


	int category_now;
<<<<<<< Updated upstream
<<<<<<< Updated upstream

=======
    
>>>>>>> Stashed changes
=======
    
>>>>>>> Stashed changes
	// check this variable to determine
	// whether to print warning  
    bool input_invalid = false;
	
    // the recent chose id
	int id_now;

	status page_status = CATEGORY_STATUS;

	// the list of goods that buyer has choose
	vector<GoodInventory> reciept;

	// use fuction of SearchSystem
<<<<<<< Updated upstream
<<<<<<< Updated upstream
	SearchSystem search;
=======
	SearchSystem search
>>>>>>> Stashed changes
=======
	SearchSystem search
>>>>>>> Stashed changes




};