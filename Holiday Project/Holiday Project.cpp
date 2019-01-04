// Holiday Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "Item.h"
wrk::Item addItem() {
	int id = 0;
	std::string name;
	float price;
	std::cout << "\nProduct ID: ";
	std::cin >> id;
	std::cout << "\nProduct Name: ";
	std::cin >> name;
	std::cout << "\nProduct Price: ";
	std::cin >> price;
	//TODO: Check if id,name, price are correct i.e no other item has this id, name is just char, and price is float
	wrk::Item temp(id, name, price);
	temp.display(std::cout, true);
	return temp;
}
int main()
{
	std::vector<wrk::Item> VecItems;

	std::cout << "------=========Inventory Management=========------" << std::endl;
	std::cout << "Select:\n1-) Add Product\n2-) View Products\n3-) Update Product\n4-) Delete Product\n5-) Exit\n\n";
	int option = 0;
	std::cin >> option;
	switch (option)
	{
	case(1):
		VecItems.push_back(addItem());
		break;
	default:
		break;
	}
}