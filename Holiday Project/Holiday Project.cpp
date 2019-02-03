// Holiday Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Item.h"


int main(int argc, char *argv[])
{
	//Item container
	std::vector<wrk::Item> VecItems;

	std::cout << "------=========Inventory Management=========------" << std::endl;
	int option = 0;
	while (option != 5)
	{
		std::cout << "Select:\n1-) Add Product\n2-) View Products\n3-) Update Product\n4-) Delete Product\n5-) Exit\n\n";
		std::cout << ">> ";
		std::cin >> option;


		switch (option)
		{
		case(1): //add product
			VecItems.push_back(wrk::createItem());
			wrk::writeOneRow(argv[1], VecItems.back());
			break;

		case(2):// view products
			VecItems.clear();
			wrk::readFile(argv[1], VecItems);
			wrk::viewItems(std::cout, VecItems);
			break;

		case(3):
			wrk::updateItem(VecItems);
			wrk::writeFile(argv[1], VecItems);
			break;
		case(4)://delete product
			wrk::deleteItem(VecItems);	
			wrk::sortObjects(VecItems); //sort objects by ID before writing to file
			wrk::writeFile(argv[1], VecItems);
			break;
		case(5):
			std::cout << "\nGood Bye!";
			break;
		default:
			std::cout << "\nPlease select number 1 to 5";
			break;
		}
	}
}