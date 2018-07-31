#ifndef GroceryItem_h
#define GroceryItem_h

class GroceryItem {
public:
	GroceryItem() { // default constructor
		price = 0;
		description = "grocery item";
		weight = 0;
	} 
	virtual double GetPrice() = 0;
	virtual char* GetDescription() = 0;
protected:
	double weight;
	char* description;
	double price;
};

#endif
