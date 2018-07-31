#pragma once
#include "GroceryItem.h"

class ProduceItem : public GroceryItem {
public:
	ProduceItem::ProduceItem(double cpp = 0) {
		costPerPound = cpp;
		price = costPerPound * weight;
	}
	virtual double GetPrice() { return costPerPound * weight; }
	virtual char* GetDescription() { return description; }

protected:
	double costPerPound;
};