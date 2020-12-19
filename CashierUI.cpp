#include <vector>
#include <iostream>
#include <cstdlib>
#include "CashierUI.h"



using namespace std;

void CshierUI::cashierSystem(){
	

	while(1){

		if(page_status == CATEGORY_STATUS){

			categoryPage();
		}
		else if(page_status == ID_STATUS){

			idPage();

		}
		else if(page_status == QUANTITY_STATUS){

			quantityPage();

		}
		
	}
}

void CashierUI::categoryPage(){

	
	clearScreen();
				
	// get first input category of user
	int chosen_category = inputCategory();
			
	// if the input is invalid
	// ask for input one more time
	while(chosen_category == INVALID){
		// need to print the text to warn user
		this->category_invalid = true;
		clearScreen();		
		chosen_category = inputCategory();
	}

	// if user input quit
	// -->terminate the program 
	if(chosen_category == QUIT){
		
		this->category_invalid = false;
		break;
			
	}
	// user choose to delete a good he or she choosed
	else if(chosen_category == DELETE){
		
		this->category_invalid = false;
		deleteOneGoodChoosed();

	}
	// user choose a valid category
	// --> move on to the next page 
	//    --> change page_status to id status
	else{
		
		category_invalid = false;
		this->category_now = chosen_category;
		this->page_status = ID_STATUS;

	}
		
}


void CashierUI::idPage(){


	clearScreen();
	// find the goods of chosen category and print it out 
	vector<GoodInventory> good_need_print = findGoodsOfCategory(string(category_string[category_now]));
	printMenu(good_need_print);

	int chosen_id = inputId();

	while(chosen_category == INVALID){
		// need to print the text to warn user
		clearScreen();
		printMenu(good_need_print);	
		cout << "We don't have this product. please choose the valid id.\n";
		chosen_category = inputCategory();

	}




}









