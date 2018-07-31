#include <iostream>

#include "PackedArray.h"

/*
	Jordan Mohler
	Comp 2355
	Lab 6
	25 January 2017
*/

// Create the array; initialize memory
PackedArray CreateArray(int aSize)
{
	PackedArray arr = { new uint64_t[aSize], aSize };
	return arr;
}

// Frees memory for the array
void FreeArray(PackedArray &array)
{
	delete [] array.rows;
}

// Sets all entries in the array to value parameter
void FillArray(PackedArray &array, uint64_t value)
{
	for (int j = 0; j < array.numRows; j++) {
		for (int i = 0; i < 32; i++) {
			SetEntry(array, j, i, value);
		}
	}
}

// Clears all entries to 0 in the array
void ClearArray(PackedArray &array)
{
	for (int j = 0; j < array.numRows; j++) {
		array.rows[j] = 0;
	}
}

// Get the value of the entry at the specified row and col.
// If row or col are outside of the range for this PackedArray,
// returns 0.
int GetEntry(const PackedArray &array, int row, int col)
{
	if (row > array.numRows || col > 31) {
		return 0;
	}
	uint64_t r = array.rows[row];
	r <<= 62 - (col*2);
	r >>= 62;
	return r;
}

// Sets entry in the location row, col to the specified value.
// If row or col are outside of the range for this PackedArray,
// function has no effect.
void SetEntry(PackedArray &array, int row, int col, uint64_t value)
{
	if (! (row > array.numRows || col > 31)) {
		uint64_t x = 3;
		x <<= col * 2;
		uint64_t temp = array.rows[row];
		temp &= ~x;
		value <<= col * 2;
		temp |= value;
		array.rows[row] = temp;
	}
}

// Sum all the entries in the array
int SumEntries(const PackedArray &array)
{
	int sum = 0;
	for (int j = 0; j < array.numRows; j++) {
		for (int i = 0; i < 32; i++) {
			sum += GetEntry(array, j, i);
		}
	}
	return sum;
}