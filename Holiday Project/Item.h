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
		int getID();
		std::string& getName();
		float getPrice();

		void updateID(int ui_id); //u
		void updateName(std::string& ui_name);
		void updatePrice(float ui_price);
		~Item(); //d

	};

	std::ostream& operator<<(std::ostream& os, const Item& i);

	//FREE HELPERS


	//read whole file
	void readFile(std::string fsName, std::vector<wrk::Item>& VecItems);
	//writes to whole file (also used for update)
	void writeFile(std::string fsName, std::vector<wrk::Item>& VecItems);
	//writes one object/row to a file
	void writeOneRow(std::string fsName, Item & VectorItem);

	//view all items on screen in a formatted manner
	void viewItems(std::ostream& os, std::vector<wrk::Item>& VecItems);

	//sorts all objects based on ID
	void sortObjects(std::vector<wrk::Item>& vecItems);

	//deletes a product from vector array based on ID
	void deleteItem(std::vector<wrk::Item>& VecItems);

	//creates a single item with proper validation
	wrk::Item createItem();//TODO: Impliment validation
	
	//Updates 1 item in the object array
	void updateItem(std::vector<wrk::Item>& VecItems);
}
