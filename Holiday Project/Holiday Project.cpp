// Holiday Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Item.h"


int main(int argc, char *argv[])
{
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
		case(1):
		   VecItems.push_back(wrk::createItem());
		   wrk::writeOneRow(argv[0],VecItems.back());
			break;
		case(2):
			VecItems.clear();
			wrk::readFile(argv[0], VecItems);

			//GetItems(VecItems);
			//ViewItems(VecItems);
			break;
		case(3):
			//UpdateProduct(VecItems);
			break;
		case(4):
			//deleteProduct(VecItems);
		case(5):
			std::cout << "\nGood Bye!";
			break;
		default:
			std::cout << "\nPlease select number 1 to 5";
			break;
		}
	}
}