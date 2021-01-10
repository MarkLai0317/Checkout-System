#include <iostream>
#include "../HeaderFile/SupplierUI.h"
#include "../HeaderFile/GoodInventory.h"

using namespace std;


static const char* category_string[] = {"碗裝泡麵", "包裝餅乾", "利樂包", "寶特瓶", "酒"};

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
		chosen_quantity = inputQuantity();

	}
	if(chosen_quantity == BACK && old_new_status == OLDGOOD_STATUS){
		// set the page_status to go back to the last page
		this->page_status = ID_STATUS;
	}
    else if(chosen_quantity == BACK && old_new_status == NEWGOOD_STATUS){

        this->page_status = PRICE_STATUS;
    }
	else{

		// put the chosen good to the reciept vector.
		quantity_now = chosen_quantity;
		addReciept();
		if(old_new_status == OLDGOOD_STATUS)this->page_status = ID_STATUS;
        else if(old_new_status == NEWGOOD_STATUS)this->page_status = CATEGORY_STATUS;

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


int SupplierUI::inputCategory(){
    string choose;
    
    cout << '\n';
    // remind supplier the adding mode
    if(old_new_status == OLDGOOD_STATUS){
        for(int i = 0 ; i < 62; ++i)
            cout << " " ;
        cout << "Supply Mode : Old" << endl;
    }

    if(old_new_status == NEWGOOD_STATUS){
        for(int i = 0 ; i < 62; ++i)
            cout << " " ;
        cout << "Supply Mode : New" << endl;
    }
            

    cout << '\n';

    //Print the category with color by using some witchcraft
    
    std::vector <string> cgy;
    std::string tmp;
    
    for(int i = 0; i < (WIDE/5/2) - 1 - 2; ++i){
   	for(int j = 0; j < WIDE; ++j) tmp.push_back(' ');
    	cgy.push_back(tmp);
    	tmp.clear();
    }

    for(int i = 0; i < 5; ++i){
    	for(int j = 0; j < (WIDE/5/2) ; ++j) tmp.push_back(' ');
    	tmp += std::to_string(i+1);
	tmp += ".";
	for(int j = 0; j < (WIDE/5/2) - 1 - 1; ++j) tmp.push_back(' ');
    }
    tmp.push_back(' ');
    cgy.push_back(tmp);
    tmp.clear();
    

    for(int i = 0; i < (WIDE/5/2) - 1 - 2; ++i){
        for(int j = 0; j < WIDE; ++j) tmp.push_back(' ');
        cgy.push_back(tmp);
        tmp.clear();
    }

    for(int i = 0; i < cgy.size(); ++i){
	for(int j = 0; j < 30; ++j) std::cout << " ";
	if (i == 6){ 
		std::cout << FORE_GROUND_BLACK << BACK_GROUND_RED << "     " << category_string[0] << "    " << BACK_GROUND_GREEN << "    " << category_string[1] << "    " <<  BACK_GROUND_BLUE <<  "     " << category_string[2] << "     " << BACK_GROUND_BROWN <<  "     " << category_string[3] << "     " << BACK_GROUND_WHITE <<  "       " << category_string[4] << "       " << RESET << '\n';
		for(int j = 0; j < 30; ++j) std::cout << " ";
	}
	for(int j = 0; j < cgy[i].size(); ++j){
		string stmp;
		stmp.push_back(cgy[i][j]);
		if(j > (WIDE/5)*4) printcontent_w(stmp);
		else if (j > (WIDE/5)*3) printcontent_br(stmp);
		else if (j > (WIDE/5)*2) printcontent_b(stmp);
		else if (j > (WIDE/5)) printcontent_g(stmp);
		else printcontent_r(stmp);
	}
	std::cout << '\n';
    }

    std::cout << '\n';


    for(int i = 0 ; i < 42; ++i)
            cout << " " ;


    if(old_new_status == OLDGOOD_STATUS)
        cout << "n : Switch to New Mode";   

    if(old_new_status == NEWGOOD_STATUS)  
        cout << "o : Switch to Old Mode";   

    cout << "    s : Check the supply list    q : Quit\n" << endl;
    

    if(!input_invalid){
        for(int i = 0 ; i < 52; ++i)
            cout << " " ;
        cout << "Your option : ";
    }


    // error message
    if(input_invalid){
        for(int i = 0 ; i < 53; ++i)
            cout << " " ;	
            cout << "Your option is invalid, please try again : ";
    }

    choose = getKeyboardChar();

    if(choose == "1")
		return SNACK;

	else if(choose == "2")
		return DRINK;

	else if(choose == "3")
		return DAILY;
	
	else if(choose == "4")
		return CLOTHES;
	
	else if(choose == "5")
		return ELECTRONIC;
	

    else if(choose == "o")
        return OLDGOOD;
    

    else if(choose == "n")
        return NEWGOOD;

    else if(choose == "s")
        return RECIEPT;

    else if(choose == "q")
        return QUIT;

    else
        return INVALID;
}

int SupplierUI::inputName(){

    cout << '\n';

    if(old_new_status == OLDGOOD_STATUS){
        for(int i = 0 ; i < 65; ++i)
            cout << " " ;
        cout << "Supply Mode : Old" << endl;
    }

    if(old_new_status == NEWGOOD_STATUS){
        for(int i = 0 ; i < 65; ++i)
            cout << " " ;
        cout << "Supply Mode : New" << endl;
    }

    cout << '\n';

    for(int i = 0 ; i < 66; ++i)
            cout << " " ;

    if(category_now == SNACK)
        cout << "Category : " << category_string[0] << endl;
    if(category_now == DRINK)
        cout << "Category : " << category_string[1] << endl;
    if(category_now == DAILY)
        cout << "Category : " << category_string[2] << endl;
    if(category_now == CLOTHES)
        cout << "Category : " << category_string[3] << endl;
    if(category_now == ELECTRONIC)
        cout << "Category : " << category_string[4] << endl;


    cout << '\n';

    for(int i = 0 ; i < 58; ++i)
            cout << " " ;
    cout << "Name of good(only Chinese) , b (Back) : ";
    string name;
    getline(cin, name);

    // back command
    if(name == "b")
        return BACK;
    
    if(name.size() > 30)
        return INVALID;

    for(int i = 0 ; i < name.size(); ++i){
        if(name[i] >= 0 && name[i] <= 127){
            return INVALID;
        }
        else
            i ++;
    }

    GoodInventory temp = search.findInventoryByName(name);

    if(temp.getId() == -1){
        name_now = name;
        return VALID;
    }
    return INVALID;
}

int SupplierUI::inputPrice(){
    
    if(old_new_status == OLDGOOD_STATUS)
        cout << "Mode : Old Good" << endl;
    if(old_new_status == NEWGOOD_STATUS)
        cout << "Mode : New Good" << endl;
        


    if(category_now == SNACK)
        cout << "Category : " << category_string[0] << endl;
    if(category_now == DRINK)
        cout << "Category : " << category_string[1] << endl;
    if(category_now == DAILY)
        cout << "Category : " << category_string[2] << endl;
    if(category_now == CLOTHES)
        cout << "Category : " << category_string[3] << endl;
    if(category_now == ELECTRONIC)
        cout << "Category : " << category_string[4] << endl;
    cout << "Name : " << name_now << endl;

    cout << "Please input the price you want to sell, or press b for backing to previous page:";
    string price_str;
    getline(cin, price_str);

    // back command
    if(price_str == "b")
        return BACK;

    for(int i = 0; i < price_str.size(); ++i){
        // if supplier input has not number character or the first number is 0, then it is invalid
        if(price_str[i] < '0' || price_str[i] > '9'|| price_str[0] == '0')
            return INVALID;
    }

    // convert price_str from string to int
    int price = stoi(price_str);

    if(price > 0)
        return price;
    
    else
        return INVALID;
    
}


int SupplierUI::inputQuantity(){ 
    // old: category id
    // new: category name price

    if(old_new_status == OLDGOOD_STATUS){
        for(int i = 0 ; i < 65; ++i)
            cout << " " ;
		cout << "Supply Mode : Old" << endl;
        for(int i = 0 ; i < 64; ++i)
            cout << " " ;
		cout << "Category : " << category_string[category_now] << endl;
        for(int i = 0 ; i < 70; ++i)
            cout << " " ;
		cout << "ID : " << id_now << endl;
	}
	
	if(old_new_status == NEWGOOD_STATUS){
		cout << "Supply Mode : New" << endl;
		cout << "Category : " << category_string[category_now] << endl;
		cout << "Name : " << name_now << endl;
		cout << "Price : " << price_now << endl;
	}
    cout << endl;
    for(int i = 0 ; i < 47; ++i)
            cout << " " ;
    cout << "Quantity of good (b : back) : ";
    string quantity_str;
    getline(cin, quantity_str);

    // back command
    if(quantity_str == "b")
        return BACK;

    for(int i = 0; i < quantity_str.size(); ++i){
        // create a temporary name and compare it with the name which supplier input
        if(quantity_str[i] < '0' || quantity_str[i] > '9' || quantity_str[0] == '0')
            return INVALID;
    }
    // convert quantity_str from string to int
    int quantity = stoi(quantity_str);
    
    if(quantity > 0)
        return quantity;
    
    else
        return INVALID;
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
        for (int i = 0; i < old_reciept.size(); ++i){
            if (old_reciept[i].getId() == id_now){
                old_reciept[i] = GoodInventory(old_reciept[i].getId(),old_reciept[i].getCategory(), 
                                               old_reciept[i].getName(), old_reciept[i].getPrice(), 
                                               old_reciept[i].getQuantity()+ quantity_now);
                return;
            }
        }
        old_reciept.push_back(search.findInventoryByIdAndSetQuantity(id_now, quantity_now));
    }else{
        for (int i = 0; i < new_reciept.size(); ++i){
            if (new_reciept[i].getName() == name_now){
                new_reciept[i] = GoodInventory(new_reciept[i].getId(),new_reciept[i].getCategory(), 
                                               new_reciept[i].getName(), new_reciept[i].getPrice(), 
                                               new_reciept[i].getQuantity()+ quantity_now);
                return;
            }
        }
        new_reciept.push_back(GoodInventory(-1, category_string[category_now], name_now, price_now, quantity_now));
    }
}



void SupplierUI::deleteOrder(int chosen_order){


	if(chosen_order < old_reciept.size()){
		old_reciept.erase(old_reciept.begin() + chosen_order);
	}else{
		new_reciept.erase(new_reciept.begin() + chosen_order - old_reciept.size());
	}
}






void SupplierUI::printReciept(){
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
    for (int i = 0; i < 5; ++i) tmp.push_back(' ');
    tmp += "ID";

    for (int i = 0; i < 5; ++i) tmp.push_back(' ');

    tmp += "Description";
    for (int i = 0; i < WIDE - 10 - 10 - 11 - 5 - 2; ++i) tmp.push_back(' ');
    tmp += "Price";
    for (int i = 0; i < 10; ++i) tmp.push_back(' ');
    rcp.push_back(tmp);
    tmp.clear();
    for (int i = 0; i < WIDE; ++i) tmp.push_back(' ');
    rcp.push_back(tmp);
    tmp.clear();
    int total = 0;
    for (int i = 0; i < merged_reciept.size(); ++i){
        for (int j = 0; j < 5; ++j) tmp.push_back(' ');
        std::string o = std::to_string(i+1);
        tmp += o;
        for (int j = 0; j < 7 - o.size(); ++j) tmp.push_back(' ');
        std::string q = std::to_string(merged_reciept[i].getQuantity());
        std::string p = std::to_string(merged_reciept[i].getPrice());
        std::string pq = std::to_string(merged_reciept[i].getPrice() * merged_reciept[i].getQuantity());
        tmp += q;
        tmp += " x ";
        tmp += merged_reciept[i].getName();
        for (int j = 0; j < WIDE - 10 - q.size() - 2 - 3 - merged_reciept[i].getName().size()*2/3 - q.size() - 3 - p.size() - 3 - 3 - 5 - 10; ++j) tmp.push_back('.');
        tmp += q;
        tmp += " x ";
        tmp += p;
        tmp += " = ";
        tmp += "NT$";
        tmp += pq;
        for (int j = 0; j < 15 - pq.size(); ++j) tmp.push_back(' ');
        rcp.push_back(tmp);
        total += merged_reciept[i].getPrice() * merged_reciept[i].getQuantity();
        tmp.clear();
        for (int i = 0; i < WIDE; ++i) tmp.push_back(' ');
        rcp.push_back(tmp);
        tmp.clear();
    }

    std::string t = std::to_string(total);
    for (int i = 0; i < WIDE - 5 - 10 - 3 - 6; ++i) tmp.push_back(' ');
    tmp += "Total";
    tmp += " ";
    tmp += "NT$";
    tmp += t;
    for (int j = 0; j < 15 - t.size(); ++j) tmp.push_back(' ');
    rcp.push_back(tmp);
    tmp.clear();

    for (int i = 0; i < WIDE; ++i) tmp.push_back(' ');
    rcp.push_back(tmp);
    tmp.clear();

    for (int i = 0; i < WIDE; ++i) tmp.push_back('-');
    rcp.push_back(tmp);
    tmp.clear();
    
    std::cout << '\n';

    for (int i = 0; i < rcp.size(); ++i){
	    for(int j = 0; j < 30 ; j++) std::cout << " ";
        printborder(2);
        if (i % 2)
            printcontent_w(rcp[i]);
        else
            printcontent_b(rcp[i]);
        printborder(2);
        std::cout << '\n';
    }
    std::cout << '\n';
}

int SupplierUI::quantityFix(int i, std::vector<GoodInventory> &menu){
    return 0;
}
