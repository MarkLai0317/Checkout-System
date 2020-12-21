
#include <iostream>
#include <iostream>
#include "SupplierUI.h"
#include "GoodInventory"


void SupplierUI::supplierSystem(){

	while(!terminate){

		if(this->page_status == OLDGOOD_STATUS || this->page_status == NEWGOOD_STATUS) {

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
		else if(this->page_status == NAME_STATUS){
			name_status();
		}
	}
}

void SupplierUI::confirm(){


	// return all reciept and resize them
	search.supplyConfirm(old_reciept, new_reciept);
	old_reciept.resize(0);
	new_reciept.resize(0);

}

void addReciept(){

	if(old_new_status == OLDGOOD_STATUS){
		old_reciept.push_back(search.findInventoryOfIdAndSetQuantity(id_now, chosen_quantity));
	}else{
		old_reciept.push_back(search.findInventoryOfIdAndSetQuantity(id_now, chosen_quantity));
	}

}

void SupplierUI::categoryPage(){

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
		
		this->terminate = true;
			
	}
	// user choose to see the reciept
	else if(chosen_category == RECIEPT){
		
		this->page_status = RECIEPT_STATUS;

	}
	// user choose a valid category
	// --> move on to the next page 
	//    --> change page_status to id status
	else if(chosen_category == OLDGOOD){
		
		//this->page_status = CATEGORY;
		this->old_new_status = OLDGOOD_STATUS;

	}
	else if(chosen_category == NEWGOOD){

		//this->page_status = CATEGORY;
		this->old_new_status = NEWGOOD_STATUS;
	}
	else{
		
		// set the category_now to the chosen category
		category_now = chosen_category;
		
		// if user add old good, go to idPage
		if(old_new_status == OLDGOOD_STATUS){
			this->page_status = ID_STATUS;
		}
		// if user add new good, go to namePage
		else{
			this->page_status = NAME_STATUS;
		}
	}

}


















