#include <iostream>
#include <unistd.h>
#include "../HeaderFile/CashierUI.h"
#include "../HeaderFile/UserInterface.h"

using namespace std;







int main(){

	chdir("desktop/oop_final_project/bin");
	CashierUI ui;

	ui.cashierSystem();

	//cout << ui.page_status << endl;
	system("clear");
	system("pwd");
	return 0;


}

