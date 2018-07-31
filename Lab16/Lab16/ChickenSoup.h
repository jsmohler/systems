#pragma once
#include "GroceryItem.h"

class ChickenSoup : public GroceryItem {
public:
	ChickenSoup() {
		description = "chicken soup";
		price = 0.99;
		weight = 1.5;
	}
	virtual double GetPrice() { return price; }
	virtual char* GetDescription() { return description; }
};