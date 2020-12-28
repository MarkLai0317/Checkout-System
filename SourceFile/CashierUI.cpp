#include <vector>
#include <iostream>
#include <cstdlib>
#include "../HeaderFile/CashierUI.h"

//for


using namespace std;



void CashierUI::cashierSystem(){
	

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


//correct
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



void CashierUI::quantityPage(){

	clearScreen();
	
	// print the good of the chosen id and wait for the input quantity
	vector<GoodInventory> good_of_idnow;
	good_of_idnow.push_back(search.findInventoryById(this->id_now));
	printMenu(good_of_idnow);


	// ask user to input the quantity he or she wnat
	int chosen_quantity = inputQuantity();
	
	// if the user input is invalid, ask user to input one more time
	while(chosen_quantity == INVALID){
			
		clearScreen();
		printMenu(good_of_idnow);	
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




int CashierUI::intputCategory(){
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


int CashierUI::inputQuantity(){
	// the quantity customer want or back command
	string quantity;

	cout << "Please enter the quantity of good you want to buy or press b for backing to previous page:";
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


int CashierUI::sizeOfReciept(){
	return this->reciept.size();
}



void CashierUI::confirm(){
	// return the reciept and resize the reciept to 0
	search.purchaseConfirm(this->reciept);
	this->reciept.resize(0);
}

/*void Cashier::addReciept(){

	reciept.push_back(search.findInventoryOfIdAndSetQuantity(id_now, chosen_quantity));
}*/

void CashierUI::addReciept(){
    for(int i=0; i<reciept.size(); ++i) {
        if(reciept[i].id == id_now){
            reciept[i].quantity += quantity_now;
            return; 
        }
    }
    reciept.push_back(search.findInventoryByIdAndSetQuantity(id_now, quantity_now));
}



void CashierUI::deleteOrder(int chosen_order){

	this->reciept.erase(this->reciept.begin()+chosen_order);

}




void printReciept(){
    std::vector<std::string> rcp;
    std::string tmp;
    for (int i = 0; i < WIDE; ++i) tmp.push_back(' ');
    rcp.push_back(tmp);
    tmp.clear();
    for (int i = 0; i < ((WIDE - 1) / 2) - 3; ++i) tmp.push_back(' ');
    tmp += "Reciept";
    for (int i = 0; i < ((WIDE - 1) / 2) - 3; ++i) tmp.push_back(' ');
    rcp.push_back(tmp);
    tmp.clear();
    for (int i = 0; i < WIDE; ++i) tmp.push_back(' ');
    rcp.push_back(tmp);
    tmp.clear();
    for (int i = 0; i < 10; ++i) tmp.push_back(' ');
    tmp += "Description";
    for (int i = 0; i < WIDE - 10 - 10 - 11 - 5; ++i) tmp.push_back(' ');
    tmp += "Price";
    for (int i = 0; i < 10; ++i) tmp.push_back(' ');
    rcp.push_back(tmp);
    tmp.clear();
    for (int i = 0; i < WIDE; ++i) tmp.push_back(' ');
    rcp.push_back(tmp);
    tmp.clear();
    int total = 0;
    for (int i = 0; i < reciept.size(); ++i){
        for (int j = 0; j < 10; ++j) tmp.push_back(' ');
        std::string q = std::to_string(reciept[i].quantity);
        std::string p = std::to_string(reciept[i].price);
        std::string pq = std::to_string(reciept[i].price * reciept[i].quantity);
        tmp += q;
        tmp += " x ";
        tmp += reciept[i].name;
        for (int j = 0; j < WIDE - 10 - q.size() - 3 - reciept[i].name.size() - q.size() - 3 - p.size() - 3 - 3 - 5 - 10; ++j) tmp.push_back('.');
        tmp += q;
        tmp += " x ";
        tmp += p;
        tmp += " = ";
        tmp += "NT$";
        tmp += pq;
        for (int j = 0; j < 15 - pq.size(); ++j) tmp.push_back(' ');
        rcp.push_back(tmp);
        total += reciept[i].price * reciept[i].quantity;
        tmp.clear();
        for (int i = 0; i < WIDE; ++i) tmp.push_back(' ');
        rcp.push_back(tmp);
        tmp.clear();
    }

    std::string t = std::to_string(total);
    for (int i = 0; i < WIDE - 5 - 10 - 3; ++i) tmp.push_back(' ');
    tmp += "NT$";
    tmp += t;
    for (int j = 0; j < 15 - t.size(); ++j) tmp.push_back(' ');
    rcp.push_back(tmp);
    tmp.clear();

    for (int i = 0; i < WIDE; ++i) tmp.push_back(' ');
    rcp.push_back(tmp);
    tmp.clear();

    for (int i = 0; i < rcp.size(); ++i){
        printborder();
        printborder();
        if(i%2) printcontent_w(rcp[i]);
        else printcontent_b(rcp[i]);
        printborder();
        printborder();
        std::cout << '\n';
    }
} 



