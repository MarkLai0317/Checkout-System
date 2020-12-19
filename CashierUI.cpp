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


void CashierUI::idPage(){

	//this->input_invalid = false;
	
	clearScreen();
	
	// find the goods of chosen category and print it out 
	vector<GoodInventory> good_need_print( search.findGoodOfCategory(string(category_string[category_now])));
	printMenu(good_need_print);

	int chosen_id = inputId();

	while(chosen_id == INVALID){
		

		// need to print the text to warn user
		clearScreen();
		printMenu(good_need_print);	
		cout << "We don't have this product. please choose the valid id.\n";
		chosen_id = inputId();

	}

	if(chosen_id == BACK){
		
		//back to category page
		this->page_status = CATEGORY_STATUS;

	}
	else{

		this->id_now = chosen_id;
		this->page_status = QUANTITY_STATUS;

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









