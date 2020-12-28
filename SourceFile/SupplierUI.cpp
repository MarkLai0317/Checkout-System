
#include <iostream>
#include <iostream>
#include "../HeaderFile/SupplierUI.h"
#include "../HeaderFile/GoodInventory.h"


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


void SupplierUI::quantityPage(){

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

void addReciept(){
    if(old_new_status == OLD_GOOD_STATUS){
        for (int i = 0; i < reciept.size(); ++i){
            if (reciept[i].getId() == id_now){
                reciept[i] = GoodInventory(reciept[i].getId(), reciept[i].getCategory(),
                                           reciept[i].getName(), reciept[i].getPrice(),
                                           reciept[i].getQuantity() + quantity_now);
                return;
            }
        }
    }else{
        
        reciept.push_back(search.findInventoryByIdAndSetQuantity(id_now, quantity_now));
    }
}


void SupplierUI::deleteOrder(int chosen_order){


	if(chosen_order < old_reciept.size()){
		old_reciept.erase(old_reciept.begin() + chosen_order);
	}else{
		new_reciept.erase(new_reciept.begin() + chosen_order - old_reciept.size());
	}
}






void SuppilerUI::printReciept(){
    std::vector<GoodInventory> merged_reciept;
    merged_reciept.reserve(old_reciept.size() + new_reciept.size());
    merged_reciept.insert(merged_reciept.end(), old_reciept.begin(), old_reciept.end());
    merged_reciept.insert(merged_reciept.end(), new_reciept.begin(), new_reciept.end());
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
    for (int i = 0; i < merged_reciept.size(); ++i){
        for (int j = 0; j < 10; ++j) tmp.push_back(' ');
        std::string q = std::to_string(merged_reciept[i].quantity);
        std::string p = std::to_string(merged_reciept[i].price);
        std::string pq = std::to_string(merged_reciept[i].price * merged_reciept[i].quantity);
        tmp += q;
        tmp += " x ";
        tmp += merged_reciept[i].name;
        for (int j = 0; j < WIDE - 10 - q.size() - 3 - merged_reciept[i].name.size() - q.size() - 3 - p.size() - 3 - 3 - 5 - 10; ++j) tmp.push_back('.');
        tmp += q;
        tmp += " x ";
        tmp += p;
        tmp += " = ";
        tmp += "NT$";
        tmp += pq;
        for (int j = 0; j < 15 - pq.size(); ++j) tmp.push_back(' ');
        rcp.push_back(tmp);
        total += merged_reciept[i].price * merged_reciept[i].quantity;
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
        if (i % 2)
            printcontent_w(rcp[i]);
        else
            printcontent_b(rcp[i]);
        printborder();
        printborder();
        std::cout << '\n';
    }
} 

















