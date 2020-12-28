

#define FORE_GROUND_BLACK "\033[30m"
#define BACK_GROUND_WHITE "\033[47m"
#define BACK_GROUND_GREEN "\033[42m"
#define BACK_GROUND_BLUE "\033[46m"
#define RESET "\033[0m"
#define WIDE 101

void printborder(){
    std::cout << FORE_GROUND_BLACK << BACK_GROUND_WHITE << ' ' << RESET;
}
void printcontent_b(std::string str){
    std::cout << FORE_GROUND_BLACK << BACK_GROUND_BLUE << str << RESET;
}
void printcontent_w(std::string str){
    std::cout << FORE_GROUND_BLACK << BACK_GROUND_WHITE << str << RESET;
}

//printRecirpt in CashierUI
void CasherUI::printReciept(){
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

//printRecirpt in SupplierUI
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