//printMenu
#define FORE_GROUND_BLACK "\033[30m"
#define BACK_GROUND_WHITE "\033[47m"
#define BACK_GROUND_GREEN "\033[42m"
#define BACK_GROUND_BLUE "\033[46m"
#define RESET "\033[0m"
#define WIDE 101

void printborder(){
    std::cout << FORE_GROUND_BLACK << BACK_GROUND_GREEN << ' ' << RESET;
}
void printcontent_b(std::string str){
    std::cout << FORE_GROUND_BLACK << BACK_GROUND_BLUE << str << RESET;
}
void printcontent_w(std::string str){
    std::cout << FORE_GROUND_BLACK << BACK_GROUND_WHITE << str << RESET;
}

void printMenu(std::vector <GoodInventory> menu){
    std::string tmp;
    std::vector<std::string> mu;
    for (int i = 0; i < WIDE; ++i) tmp.push_back(' ');
    mu.push_back(tmp);
    tmp.clear();
    for (int i = 0; i < ((WIDE - 1) / 2) - menu[0].getCategory().size()/2; ++i) tmp.push_back(' ');
    tmp += menu[0].getCategory();
    for (int i = 0; i < WIDE - (((WIDE - 1) / 2) - menu[0].getCategory().size()/2); ++i) tmp.push_back(' ');
    mu.push_back(tmp);
    tmp.clear();
    for (int i = 0; i < WIDE; ++i) tmp.push_back(' ');
    mu.push_back(tmp);
    tmp.clear();
    for (int i = 0; i < 10; ++i) tmp.push_back(' ');
    tmp += "ID";
    for (int i = 0; i < 10; ++i) tmp.push_back(' ');
    tmp += "Name";
    for (int i = 0; i < 40; ++i) tmp.push_back(' ');
    tmp += "Price";
    for (int i = 0; i < 20; ++i) tmp.push_back(' ');
    tmp += "Quantity";
    for (int i = 0; i < 21; ++i) tmp.push_back(' ');
    mu.push_back(tmp);
    tmp.clear();
    for (int i = 0; i < WIDE; ++i) tmp.push_back(' ');
    mu.push_back(tmp);
    tmp.clear();
    for (int i = 0; i < menu.size(); ++i){
        for (int j = 0; j < 10; ++j) tmp.push_back(' ');
        std::string q = std::to_string(menu[i].getQuantity());
        std::string p = std::to_string(menu[i].getPrice());
        std::string d = std::to_string(menu[i].getId());
        tmp += d;
        for (int j = 0; j < 10 - d.size(); ++j) tmp.push_back(' ');
        tmp += menu[i].getName();
        for (int j = 0; j < 40 - menu[i].getName().size(); ++j) tmp.push_back(' ');
        tmp += "NT$";
        tmp += p;
        for (int j = 0; j < 20 - p.size() - 3; ++j) tmp.push_back(' ');
        tmp += q;
        for (int j = 0; j < 21 - q.size(); ++j) tmp.push_back(' ');
        mu.push_back(tmp);
        tmp.clear();
        for (int i = 0; i < WIDE; ++i) tmp.push_back(' ');
        mu.push_back(tmp);
        tmp.clear();
    }

    for (int i = 0; i < WIDE - 5 - 10 - 3; ++i) tmp.push_back(' ');
    tmp += "NT$";
    tmp += t;
    for (int j = 0; j < 15 - t.size(); ++j) tmp.push_back(' ');
    mu.push_back(tmp);
    tmp.clear();

    for (int i = 0; i < WIDE; ++i) tmp.push_back(' ');
    mu.push_back(tmp);
    tmp.clear();

    for (int i = 0; i < mu.size(); ++i){
        printborder();
        printborder();
        if (i % 2 == 0)
            printcontent_w(mu[i]);
        else
            printcontent_b(mu[i]);
        printborder();
        printborder();
        std::cout << '\n';
    }
}