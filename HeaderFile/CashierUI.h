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





//private:

	



	// things to do in category page
	void categoryPage();

	// things to do in id page
	//================in UserInterface==================
	//void idPage();


	// things to do in quantity page
	//================in UserInterface==================
	void quantityPage();



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
	//================in UserInterface==================
	//int inputId();


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
	// recieve list of goods and print with nice format
	// need to show id, name, quantity, and price $  
	//================in UserInterface==================
	//void printMenu(&vector<GoodInventory>);

	// confirm the  reciept
	void confirm();

	// add the good choose to the reciept
	void addReciept();

	//delete one goods chosen by customer
	void deleteOrder(int order);



private:



	std::vector<GoodInventory> reciept;

	//================in UserInterface==================
	//int category_now;

	// check this variable to determine
	// whether to print warning  
    //================in UserInterface==================
    //bool input_invalid = false;
	


    // the recent chose id
	//================in UserInterface==================
	//int id_now;



	//================in UserInterface==================
	//bool terminate = false;

	// 分辨現在在哪一層 
	//================in UserInterface==================
	//status page_status = CATEGORY_STATUS;

	
	// the list of goods that buyer has choose
	//================in UserInterface==================
	//vector<GoodInventory> reciept;

	// use fuction of Main System


	//================in UserInterface==================
	//SearchSystem search;






};

#endif