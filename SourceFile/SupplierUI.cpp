
#include <iostream>
#include <iostream>
#include "SupplierUI.h"
#include "GoodInventory"


void SupplierUI::supplierSystem(){

	while(!terminate){

		if(this->page_status == CATEGORY_STATUS) {

			categoryPage();
		}
		else if(this->page_status == ID_STATUS){

			idPage();
		}
		else if(this->page_status == QUANTITY_STATUS){

			quantityPage();
		}
		else if(this->page_status == RECIEPT_STATUS){

			recieptPage();
		}
		else if(this->page_status == NAME_STATUS){
			namePage();
		}
		else if(this->page_status == PRICE_STATUS){
			pricePage();
		}
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


void UserInterface::quantityPage(){

	clearScreen();
	
	// print the good of the chosen id and wait for the input quantity



	// ask user to input the quantity he or she wnat
	int chosen_quantity = inputQuantity();
	
	// if the user input is invalid, ask user to input one more time
	while(chosen_quantity == INVALID){
			
		clearScreen();
		// need to print the text to warn user
		//cout << "Please input the Valid quantity or type 'b' to go back to the last page.\n\n";
		// input one more time
		chosen_id = inputQuantity();

	}
	if(chosen_quantity == BACK){
		// set the page_status to go back to the last page
		this->page_status = ID_STATUS;
	}
	else{

		// put the chosen good to the reciept vector.
		quantity_now = chosen_quantity;
		addReciept();
		this->page_status = ID_STATUS;

	}
}


void SupplierUI::namePage(){


	clearScreen();
	input_invalid = false;
	int chosen_name = inputName();

	while(chosen_name == INVALID){
		input_invalid = true;
		clearScreen();
		chosen_name = inputName();
	}

	if(chosen_name == BACK){
		page_status = CATEGORY_STATUS;
	}
	else{

		page_status = PRICE_STATUS;
	}
}


void SupplierUI::pricePage(){

	clearScreen();
	input_invalid = false;
	int chosen_price = inputPrice();

	while(chosen_price == INVALID){
		input_invalid = true;
		clearScreen();
		chosen_price = inputPrice();
	}

	if(chosen_price == BACK){
		this->page_status = NAME_STATUS;
	}
	else{

		
		this->price_now = chosen_price;
		
		this->page_status = QUANTITY_STATUS;
	}
}

int SupplierUI::sizeOfReciept(){
	return (old_reciept.size() + new_reciept.size());
}



void SupplierUI::confirm(){


	// return all reciept and resize them
	search.supplyConfirm(old_reciept, new_reciept);
	old_reciept.resize(0);
	new_reciept.resize(0);

}

void SupplierUI::addReciept(){

	if(old_new_status == OLDGOOD_STATUS){
		old_reciept.push_back(search.findInventoryOfIdAndSetQuantity(id_now, chosen_quantity));
	}else{
		new_reciept.push_back(search.findInventoryOfIdAndSetQuantity(id_now, chosen_quantity));
	}

}

void SupplierUI::deleteOrder(int chosen_order){


	if(chosen_order < old_reciept.size()){
		old_reciept.erase(old_reciept.begin() + chosen_order);
	}else{
		new_reciept.erase(new_reciept.begin() + chosen_order - old_reciept.size());
	}
}

















