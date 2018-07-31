#pragma once
#include "ProduceItem.h"

class Lettuce : public ProduceItem {
public:
	Lettuce(double w) {
		weight = w;
		costPerPound = 0.49;
		description = "lettuce";
	}
};
