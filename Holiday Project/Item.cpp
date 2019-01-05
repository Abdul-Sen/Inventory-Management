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

}

std::ostream & wrk::operator<<(std::ostream & os, const Item & i)
{
	i.display(os, false);
	return os;
}