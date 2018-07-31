#ifndef BitVector_h
#define BitVector_h
#include <iostream>
#include <cstdint>
#include "MyArray.hpp"

class BitVector {
public:
	BitVector(int);
	void fill();
	void clear();
	bool get(int);
	void set(int, bool);
	size_t sizeOf();
private:
	MyArray<uint8_t> model;
	int size;
};


#endif
