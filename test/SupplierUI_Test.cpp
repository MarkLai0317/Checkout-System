#include <iostream>
#include <unistd.h>
#include "../HeaderFile/SupplierUI.h"

int main(){

	chdir("desktop/oop_final_project/bin");
	SupplierUI ui;

	ui.supplierSystem();

	return 0;
}