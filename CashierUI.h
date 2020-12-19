
#include <vector>
#include "GoodInventory.h"
#include "file"


class CashierUI {



	CashierSystem();





private:

	// 1.Need to see if we have the chosen category.
	//   If we don't have, it's alse a invalid input. need to ask input one more time
	// 2.Return the valid category input.
	//   Input 'q' means quit, return -1.
	//   Input 'd' maens delete one goods have just choose, return -2
	// 3.when implementation, using string to get the input will be easier to identify invalid input
	//   so do other input
	int inputCategory();

	// 1.Need to see if we have the chosen ID
	//   If we don't have, it's alse a invalid input. need to ask input one more time
	// 2.return the valid id input
	//   input 'b' means back to the last page, return -1
	// 3.same as above 3.
	int inputId();


	// 1.Need to see if we have the chosen Quantity.
	//   If we don't have enough goods, it's also an invalid input. 
	//   -->need to ask input one more time and tell customer that the goods hase only X left
	// 	 X is the quantity of that goods in inventory
	// return the valid id input
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