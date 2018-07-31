//  Edits by Walker Rainford for Systems Programming Lab
//  Coding for SpreadBits was derived from a stack-exchange solution
//  main.cpp
//  Lab3
//
//  Created by Nathan Sturtevant on 1/11/16.
//  Copyright © 2016 AI For Traditional Games. All rights reserved.
//
// Edits made by Jordan Mohler
// COMP 2355
// 11 January 2017
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cassert>
#ifndef voxel_h
#include "voxel.h"
#endif
/*
 Function that extracts and returns bits from input as follows:
 You extract bits starting from the location "first" (starting from least significant bit) and take the bit at every "step".
 For example if input is 10110111, first is 0 and step is 2
 then the program returns 0111 because it started at 1 and skipped every other bit.
 */
uint32_t ExtractBits(uint32_t input, int first, int step)
{
	uint32_t temp;
	uint32_t last = 0x00;
	for (int i = 0; i < ((32-first)/step); i++) {
		temp = ((input >> i*step) & 1) << i;
		last = last | temp;
	}

	return last;
}

//Return the x value encoded in the morton code
uint32_t DecodeMorton3X(uint32_t code)
{
  return ExtractBits(code, 0, 3);
}

//Return the y value encoded in the morton code
uint32_t DecodeMorton3Y(uint32_t code)
{
  return ExtractBits(code, 1, 3);
}

//Return the z value encoded in the morton code
uint32_t DecodeMorton3Z(uint32_t code)
{
  return ExtractBits(code, 2, 3);
  
}

/*
 Function used to perform Morton encoding.  This will set the bits of the result using bits from input skipping every step.
 */
uint32_t SpreadBits(uint32_t input, int step)
{
	uint32_t last = 0x00;
	uint32_t temp;
	for (int i = 0; i < 10; i++) {
		temp = ((input >> i) & 1) << step*i;
		last = last | temp;
	}
	return last;
}

//Encode morton value from x, y, z data
//Only take 10 bits from each coordinate.
uint32_t EncodeMorton3D(uint32_t x, uint32_t y, uint32_t z)
{
  uint32_t result;
  result = SpreadBits(x, 3)|(SpreadBits(y, 3)<<1)|(SpreadBits(z, 3)<<2);
  return result;
}

//This function tests whether the decoding and encoding work
//Take the
void TestMorton3D()
{
  std::cout<<"Start Test!\n";
  for (int x = 0; x < 1024; x+=3)
  {
    for (int y = 0; y < 1024; y+=3)
    {
      for (int z = 0; z < 1024; z+=3)
      {
        uint32_t value = EncodeMorton3D(x, y, z);
        assert(DecodeMorton3X(value) == x);
        assert(DecodeMorton3Y(value) == y);
        assert(DecodeMorton3Z(value) == z);
      }
    }
  }
  std::cout<<"Test Passed!\n";
}
int main(int argc, const char * argv[])
{
  ImportAndExportVoxelMap("Simple_test3dnav.3dnav", "simple.txt");
  ImportAndExportVoxelMap("Complex_test3dnav.3dnav", "complex.txt");
  TestMorton3D();
  return 0;
}
