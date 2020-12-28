#include <iostream>
#include "../HeaderFile/UserInterface.h"
#include "../HeaderFile/CashierUI.h"
using namespace std;
//correct


char* category_string[5] = {"",}


void UserInterface::clearScreen(){
    std::cout << std::flush;
    system("clear");
 }


//correct
void UserInterface::idPage(){

	//this->input_invalid = false;
	
	clearScreen();
	
	// find the goods of chosen category and print it out 
	vector<GoodInventory> good_need_print( search.findGoodOfCategory(string(category_string[category_now])));
	
	//printMenu(good_need_print);
	cout << "MENU\n";
	int chosen_id = inputId();

	while(chosen_id == INVALID){
		

		// need to print the text to warn user
		clearScreen();
		//printMenu(good_need_print);/////////////////////////
		cout << "MENU\n";
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




void UserInterface::recieptPage(){

	this->input_invalid = false;
	clearScreen();
	//virtual
	printReciept();

	int chosen_order = inputReceipt();

	while(chosen_order == INVALID){
		this->input_invalid = true;
		clearScreen();
		printReciept();

		//cout << "Please input Valid choice!\n\n";
		chosen_order = inputReceipt();
	}

	// when user choose to confirm the purchase
	if(chosen_order == CONFIRM){

		// return reciept to system and clear the reciept
		
		//virtual
		confirm();

		// go back to choose category
		this->page_status = CATEGORY_STATUS;

	}
	// go back to choose category
	else if(chosen_order == BACK){

		this->page_status = CATEGORY_STATUS;
	}
	
	// user choose to delete a good chose before
	else {
		
		//virtual
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

	vector<GoodInventory> temp = search.findInventoriesByCategory(category_string[category_now]);
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
	if(order <= 0 || order > sizeOfReciept())
		return INVALID;
		
	// legal input then return the index of vector(order - 1)
	if(order <= sizeOfReciept() && order > 0)
		return (order - 1);

}



void UserInterface::printborder(){
    std::cout << FORE_GROUND_BLACK << BACK_GROUND_WHITE << ' ' << RESET;
}
void UserInterface::printcontent_b(std::string str){
    std::cout << FORE_GROUND_BLACK << BACK_GROUND_BLUE << str << RESET;
}
void UserInterface::printcontent_w(std::string str){
    std::cout << FORE_GROUND_BLACK << BACK_GROUND_WHITE << str << RESET;
}