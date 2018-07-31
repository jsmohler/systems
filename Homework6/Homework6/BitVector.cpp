#include <iostream>
#include <cstdint>
#include "BitVector.h"
#include "MyArray.hpp"

int getByteNumber(int index) {
	return index / 8;
};

uint8_t getBitNumber(int index) {
	return index % 8;
};

BitVector::BitVector(int bits) : model((bits/8) + 1) {
	size = bits;
};


bool BitVector::get(int n) {
	int index = getByteNumber(n);
	uint8_t bits = model.get(index);
	bits = bits >> getBitNumber(n);
	if (bits % 2 == 0) {
		return false;
	}
	else {
		return true;
	}
}

void BitVector::set(int n, bool on) {
	const int index = getByteNumber(n);
	uint8_t bits = model.get(index);
	uint8_t k = 1 << getBitNumber(n);
	if (!get(n) && on) {
		bits = bits | k;
	}
	else if (get(n) && !on) {
		bits = bits & (~k);
	}
	model.set(index, bits);
}

void BitVector::clear() {
	for (int i = 0; i < size / 8; i++) {
		model.set(i, 0);
	}
};

void BitVector::fill() {
	for (int i = 0; i < size / 8; i++) {
		model.set(i, 0xFF);
	}
};

size_t BitVector::sizeOf() {
	return size;
}