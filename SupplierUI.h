#ifndef _SUPPLIERUI_H
#define _SUPPLIERUI_H

#include <string>
#include <vector>
#include "UserInterFace.h"
#include "GoodsActivity.h"

class SupplierUI:: public UserInterFace{

	
public:
	void printInterface();

	// Get all the needed iput and put them into GoodsInventory.
	// The Good need to be put into activity_buffer for printing the table
	// ,and return the Goods to the system
	GoodsInvectory getGoods();


private:

	// get input and store the input id
	int inputId();


	// get input and store the input name
	string inputName();


	// get input and store the input quantity
	int inputQuantity();

	// 3 function above is used in getGoods



	// A vector that temporary store the input
	// of user and need to be printed after input a object
	vector<GoodsInventory> activity_buffer;





};




#ifndef