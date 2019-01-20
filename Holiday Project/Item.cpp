#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include "Item.h"


namespace { //annon namespace
	static const int FW = 20; //sets field width for item displaying purpose
}
//default constructor
wrk::Item::Item()
{
	i_ID = 0;
	i_name = "";
	i_price = 0;
}

wrk::Item::Item(int ui_id, std::string& ui_name, float ui_price)
{
	i_ID = ui_id;
	i_name = ui_name;
	i_price = ui_price;
}

//displays current item
void wrk::Item::display(std::ostream & os,bool headingWanted) const
{
	if (headingWanted)
	{
		os.width(5);
		os << "ID";
		os.width(FW);
		os << "Name";
		os.width(FW);
		os << "Price \n";
	}
	os.width(5);
	os << this->i_ID;
	os.width(FW);
	os << this->i_name;
	os.width(FW);
	os << this->i_price;
	os << "\n";
}

int wrk::Item::getID()
{
	return i_ID;
}

std::string & wrk::Item::getName()
{
	return i_name;
}

float wrk::Item::getPrice()
{
	return i_price;
}

void wrk::Item::updateID(int ui_id)
{
	this->i_ID = ui_id;
}

void wrk::Item::updateName(std::string & ui_name)
{
	this->i_name = ui_name;
}

void wrk::Item::updatePrice(float ui_price)
{
	this->i_price = ui_price;
}


wrk::Item::~Item()
{
	this->i_ID = 0;
	this->i_name = "";
	this->i_price = 0;
}

std::ostream & wrk::operator<<(std::ostream & os, const Item & i)
{
	i.display(os, false);
	return os;
}

void wrk::readFile(std::string fsName, std::vector<wrk::Item> VecItems)
{
	int id = 0;
	std::string name;
	float price;

	std::ifstream ifs(fsName, std::ios::in);
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

//writes all the Item objects to a file in .csv format
void wrk::writeFile(std::string fsName, std::vector<wrk::Item>& VecItems)
{
	std::fstream ofs(fsName, std::ios_base::out);
	for (Item& vectorItem : VecItems)
	{
		ofs << "\n" << vectorItem.getID() << ',' << vectorItem.getName() << ',' << vectorItem.getPrice();
	}
	ofs.close();
}


//writes one Item object to a file in .csv format
void wrk::writeOneRow(std::string fsName,Item & VectorItem)
{
	std::fstream ofs(fsName, std::ios_base::app);
	ofs << "\n" << VectorItem.getID() << ',' << VectorItem.getName() << ',' << VectorItem.getPrice();
	ofs.close();

}

void wrk::viewItems(std::ofstream & ifs, std::vector<wrk::Item>& VecItems)
{
	VecItems[0].display(ifs, true);
	for (std::vector < wrk::Item>::iterator itr = VecItems.begin() + 1; itr != VecItems.end(); itr++)
	{
		ifs << (*itr);
	}
}

//sorts vector of item objects based on ID
void wrk::sortObjects(std::vector<wrk::Item>& vecItems)
{
	std::sort(vecItems.begin(), vecItems.end(), [](wrk::Item current, wrk::Item next) {
		return current.getID() < next.getID();
	});

}

//deletes a single Item from a vector of products
void wrk::deleteItem(std::vector<wrk::Item>& VecItems, std::ostream & os, std::istream & is)
{
	os << "Enter Product ID >> ";
	int pid;
	is >> pid;
	for (std::vector<wrk::Item>::iterator itr = VecItems.begin(); itr != VecItems.end(); itr++)
	{
		if ((*itr).getID() == pid)
		{
			(*itr).display(os, true);
			VecItems.erase(itr);
			break;
		}
	}
}

wrk::Item wrk::createItem()
{
	int id = 0;
	std::string name;
	float price;
	std::cout << "\nProduct ID: ";
	std::cin >> id;
	std::cout << "\nProduct Name: ";
	std::cin.ignore(1);
	std::getline(std::cin, name);
	std::cout << "\nProduct Price: ";
	std::cin >> price;
	//TODO: Check if id,name, price are correct i.e no other item has this id, name is just char, and price is float
	return Item(id, name, price);
}
