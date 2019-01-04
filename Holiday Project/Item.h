#pragma once
#include <string>

namespace wrk {
	class Item {
		int i_ID;
		std::string i_name;
		float i_price;
	public:
		Item();//c
		Item(int ui_id, std::string& ui_name, float ui_price); 

		void display(std::ostream&, bool headingWanted) const; // r

		void updateID(int ui_id); //u
		void updateName(std::string& ui_name);
		void updatePrice(float ui_price);
		~Item(); //d

	};

	std::ostream& operator<<(std::ostream& os, const Item& i);
}


