#include <iostream>
#include "UserInterface.h"


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

void UserInterface::quantityPage(){

	clearScreen();
	
	// print the good of the chosen id and wait for the input quantity
	vector<GoodInventory> good_of_idnow;
	good_of_idnow.push_back(search.findInventoryOfId(this->id_now));
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
		
		addReciept();
		this->page_status = ID_STATUS;

	}
}

void UserInterface::recieptPage(){

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
		confirm();
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



int UserInterface::inputId(){
	string ID;
	cout << "Please enter the ID of good you want to buy or press b for backing to previous page:";
	getline(cin, ID);
	
	// back command	
	if(ID == "b")
		return BACK;

	vector<GoodInventory> temp = search.findGoodOfCategory(category_string[category_now]);
	int size = temp.size;


	// check whether the input is valid
	for(int i = 0; i < size; ++i){
		int temp_id_int = temp[i].getId();

		// convert id form int to string
		string temp_id = to_string(temp_id_int);

		//compare whether they are same
		if(ID == temp_id){
			id_now = temp_id_int;
			return temp_id_int;
		}
	}

	// no matching ID
	return INVALID;
}



int UserInterface::inputReciept(){
	string cmd;
	cout << "You can enter the number which mean the order of good you want to delete of the reciept." << endl;
	cout << "Press c for confirming the reciept or press b for backing to previous page.\n" << endl;
	cout << "Please choose the service you want:"
	getline(cin, cmd);

	// back command
	if(cmd == "b")
		return BACK;

	// confirm command
	if(cmd == "c")
		return CONFIRM;
	
	// judge whether the command is invalid
	// if the command is invalid(true)
	bool cmd_invalid = false;
	for(int i = 0 ; i < cmd.size(); ++i){
		if(cmd[i] < '0' || cmd[i] > '9'){
			cmd_invalid = true;
			break;
		}
	}
	
	if(cmd_invalid)
		return INVALID;

	// convert the order of good want to delete from string to int
	int order = stoi(cmd);

	// the delete order should start from 1 and can't larger than the total order
	if(order <= 0 || order > reciept.size())
		return INVALID;
		
	// legal input then return the index of vector(order - 1)
	if(order <= reciept.size() && order > 0)
		return (order - 1);
}