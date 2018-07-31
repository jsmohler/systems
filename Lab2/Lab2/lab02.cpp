#include <iostream>
#include <string>;
using std::cout;

int main(int argc, const char* argv[]) {
	cout << "Bool in bytes: ";
	cout << sizeof(bool);
	cout << "\n Char in bytes: ";
	cout << sizeof(char);
	cout << "\n Short in bytes: ";
	cout << sizeof(short);
	cout << "\n Int in bytes: ";
	cout << sizeof(int);
	cout << "\n Long in bytes: ";
	cout << sizeof(long);
	cout << "\n Long Long in bytes: ";
	cout << sizeof(long long);
	cout << "\n Float in bytes: ";
	cout << sizeof(float);
	cout << "\n Double in bytes: ";
	cout << sizeof(double);
	cout << "\n Long Double in bytes: ";
	cout << sizeof(long double);
	cout << "\n int8 in bytes: ";
	cout << sizeof(int8_t);
	cout << "\n int16 in bytes: ";
	cout << sizeof(int16_t);
	cout << "\n int32 in bytes: ";
	cout << sizeof(int32_t);
	cout << "\n int64 in bytes: ";
	cout << sizeof(int64_t);

	int16_t sixteen = 24;
	int32_t thirtytwo = 255;
	int64_t sixtyfour = 2049;

	
	cout << std::dec << "\n";
	cout << "\n int16_t in decimal: ";
	cout << sixteen;
	cout << "\n int32_t in decimal: ";
	cout << thirtytwo;
	cout << "\n int64_t in decimal: ";
	cout << sixtyfour;

	cout << std::hex;
	cout << "\n int16_t in hex: 0x";
	cout << sixteen;
	cout << "\n int32_t in hex: 0x";
	cout << thirtytwo;
	cout << "\n int64_t in hex: 0x";
	cout << sixtyfour << "\n";


	cout << std::dec << "\n Overflow of int16_t above * 65000: ";
	sixteen = sixteen * 65000;
	cout << sixteen;

	cout << "\n";
	cout << "\n uint32_t Max Value: ";
	uint32_t uTT = 0xFFFFFFFF;
	cout << uTT;
	cout << "\n uint32_t Min Value: ";
	uTT = 0x00000000;
	cout << uTT;

	cout << "\n uint64_t Max Value: ";
	uint64_t uSF = 0xFFFFFFFFFFFFFFFF;
	cout << uSF;
	cout << "\n uint64_t Min Value: ";
	uSF = 0x0000000000000000;
	cout << uSF;

	cout << "\n";
	cout << "\n int32_t Max Value: ";
	uint32_t tT = 0x7FFFFFFF;
	cout << tT;
	cout << "\n int32_t Min Value: -";
	tT = 0x80000000;
	cout << tT;

	cout << "\n int64_t Max Value: ";
	uint64_t sF = 0x7FFFFFFFFFFFFFFF;
	cout << sF;
	cout << "\n int64_t Min Value: -";
	sF = 0x8000000000000000;
	cout << sF << "\n";
	
	cout << "\n";
	cout << int32_t;
	cout << 8 << "\n";
	cout << 7.6 << "\n";
	cout << 3.141 << "\n";
	cout << double << "\n";
	cout << 456789 << "\n";
	cout << 25 << "\n";

	return 0;

}
