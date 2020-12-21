#include <iostream>
#include "UserInterface.h"


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