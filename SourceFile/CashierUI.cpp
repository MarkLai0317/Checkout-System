#include <vector>
#include <iostream>
#include <cstdlib>
#include "CashierUI.h"



using namespace std;

void CshierUI::cashierSystem(){
	

	while(!terminate){

		if(this->page_status == CATEGORY_STATUS){

			categoryPage();
		}
		else if(this->page_status == ID_STATUS){

			idPage();
		}
		else if(this->page_status == QUANTITY_STATUS){

			quantityPage();
		}
		else if(this->page_status == RECIEPT){

			recieptPage();
		}
		
	}
}


void CashierUI::categoryPage(){

	
	clearScreen();
	this->input_invalid = false;
	// get first input category of user
	int chosen_category = inputCategory();
			
	// if the input is invalid
	// ask for input one more time
	while(chosen_category == INVALID){
		// need to print the text to warn user
		this->input_invalid = true;
		clearScreen();		
		chosen_category = inputCategory();
	}

	// if user input quit
	// -->terminate the program 
	if(chosen_category == QUIT){
		
		this->input_invalid = false;
		this->terminate = true;
			
	}
	// user choose to see the reciept
	else if(chosen_category == RECIEPT){
		
		this->input_invalid = false;
		this->page_status = RECIEPT_STATUS;

	}
	// user choose a valid category
	// --> move on to the next page 
	//    --> change page_status to id status
	else{
		
		this->input_invalid = false;
		// choose one category
		this->category_now = chosen_category;
		// step to next page to choose id
		this->page_status = ID_STATUS;

	}
		
}





void quantityPage(){

	clearScreen();
	
	// print the good of the chosen id and wait for the input quantity
	vector<GoodInventory> good_of_idnow;
	good_of_idnow.push_back(search.findGoodOfId(this->id_now));
	printMenu(good_of_idnow);


	// ask user to input the quantity he or she wnat
	int chosen_quantity = inputQuantity();
	
	// if the user input is invalid, ask user to input one more time
	while(chosen_quantity == INVALID){
			
		clearScreen();
		printMenu(good_of_idnow);	
		// need to print the text to warn user
		cout << "Please input the Valid quantity or type 'b' to go back to the last page.\n\n";
		// input one more time
		chosen_id = inputQuantity();

	}
	if(chosen_quantity == BACK){
		// set the page_status to go back to the last page
		this->page_status = ID_STATUS;
	}
	else{

		// put the chosen good to the reciept vector.
		reciept.push_back(search.findGoodOfIdAndSetQuantity(id_now, chosen_quantity));
		this->page_status = ID_STATUS;

	}
}

void CashierUI::recieptPage(){

	clearScreen();
	printReciept();

	int chosen_order = inputReceipt();

	while(chosen_order == INVALID){

		clearScreen();
		printReciept();

		cout << "Please input Valid choice!\n\n";
		chosen_order = inputReceipt();
	}

	// when user choose to confirm the purchase
	if(chosen_order == CONFIRM){

		// return reciept to system and clear the reciept
		search.purchaseConfirm(this->reciept);
		reciept.resize(0);

		// go back to choose category
		this->page_status = CATEGORY_STATUS;

	}
	// go back to choose category
	else if(chosen_order == BACK){

		this->page_status = CATEGORY_STATUS;
	}
	
	// user choose to delete a good chose before
	else {
		
		deleteOrder(chosen_order);
		
	}


}

int UserInterface::intputCategory(){
	// customer choose
	string choose;

	// print all categories for customer to chooose
	cout << "Press 1 for finding Snack." << endl;
	cout << "Press 2 for finding Drink." << endl;
	cout << "Press 3 for finding Daily Product." << endl;
	cout << "Press 4 for finding Clothes." << endl;
	cout << "Press 5 for finding  Electronic Product." << endl;
	cout << "Press q for quiting." << endl;
	cout << "Press s for checking your reciept." << endl;
	cout << "Please choose the service you want:";

	// error message
	if(input_invalid)
		cout << "Your input is invalid, please try again:"

	getline(cin, choose);

	// judge whether the choose is valid
	if(choose == "1"){
		category_now = SNACK;
		return SNACK;
	}

	else if(choose == "2"){
		category_now = DRINK;
		return DRINK;
	}

	else if(choose == "3"){
		category_now = DAILY;
		return DAILY;
	}

	else if(choose == "4"){
		category_now = CLOTHES;
		return CLOTHES;
	}

	else if(choose == "5"){
		category_now = ELECTRONIC;
		return ELECTRONIC;
	}

	else if(choose == "q")
		return QUIT;

	else if(choose == "s")
		return RECIEPT;

	else
		return INVALID;
}


int UserInterface::inputQuantity(){
	// the quantity customer want or back command
	string quantity;

	cout << "Please enter the quantity of good you want to buy or press b for backing to previous page:"
	getline(cin, quantity);

	// back command
	if(quantity == "b")
		return BACK;
	
	// judge whether the input quantity is valid
	// if the quantity is invalid(true)
	bool quantity_invalid = false;
	for(int i = 0 ; i < quantity.size(); ++i){
		// if the input quantity have the char which is not number then it is invalid
		if(quantity[i] < '0' || quantity[i] > '9'){
			quantity_invalid = true;
			break;
		}
	}

	if(quantity_invalid)
		return INVALID;

	GoodInventory temp = search.findGoodOfId(id_now);

	// convert the quantity customer want from string to int
	int quantity_want = stoi(quantity);

	// the quantity in inventory
	int quantity_have = temp.getQuantity();
		
	// invalid quantity(<=0) or too much quantity
	if(quantity_want <= 0 || quantity_want > quantity_have)
		return INVALID;

	if(qunatity_want <= quantity_have && quantity_want > 0)
		return quantity_want;	
}


