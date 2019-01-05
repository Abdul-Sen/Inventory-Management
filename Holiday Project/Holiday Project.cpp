// Holiday Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "Item.h"

//adds a single item
wrk::Item addItem() {
	int id = 0;
	std::string name;
	float price;
	std::cout << "\nProduct ID: ";
	std::cin >> id;
	std::cout << "\nProduct Name: ";
	std::cin >> name;
	//std::getline(std::cin, name);
	std::cout << "\nProduct Price: ";
	std::cin >> price;
	//TODO: Check if id,name, price are correct i.e no other item has this id, name is just char, and price is float
	wrk::Item temp(id, name, price);
	std::fstream ofs("ItemList.csv", std::ios_base::app);
	ofs << "\n" << id << ',' << name << ',' <<price;
	ofs.close();
	return temp;
}

//gets all the items from the .csv file and adds them to the sent array
void GetItems(std::vector<wrk::Item>& VecItems) {
	int id = 0;
	std::string name;
	float price;

	std::ifstream ifs("ItemList.csv", std::ios::in);
	if (ifs.is_open() == false)
		throw "File Could not be opened for reading";
	std::string line;
	std::getline(ifs, line, '\n');//Dumbs first line

	while (!ifs.eof())
	{
		std::getline(ifs, line, '\n');
		if (line.length() != 0)
		{
		id = std::stoi(line.substr(0, ','));
		line = line.substr(line.find(',') + 1);
		name = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 1);
		price = std::stof(line);
		VecItems.push_back(wrk::Item(id, name, price));
		}
	}
}
void ViewItems(std::vector<wrk::Item>& VecItems){
	VecItems[0].display(std::cout, true);
	
	for (std::vector < wrk::Item>::iterator itr = VecItems.begin()+1; itr != VecItems.end(); itr++)
	{
		std::cout << (*itr);
	}
}
int main()
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
			VecItems.push_back(addItem());
			break;
		case(2):
			VecItems.clear();
			GetItems(VecItems);
			ViewItems(VecItems);
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