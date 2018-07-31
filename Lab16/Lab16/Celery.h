#pragma once
#include "ProduceItem.h"

class Celery : public ProduceItem {
public:
	Celery(double w) {
		weight = w;
		costPerPound = 0.79;
		description = "celery";
	}
};
