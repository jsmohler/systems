#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

/*
    Jordan Mohler
    Comp 2355
    Lab 7
    30 January 2017
*/

void crash(char * p) {
	char a[] = "Hello world!";
	p = a;
	crash(p);
}

char * reverseString(char * word) {
	int x = strlen(word);
	char *p = new char[x];
	for (int i = 0; i < x; i++) {
		p[i] = word[x - i - 1];
	}
	p[x] = '\0';
	return p;
}

int main(int argc, char* argv[]) {
	char a[] = "Hello World";
	//crash(a);
	std::cout << "Original String: " << a << "\n";
	char *p = reverseString(a);
	std::cout << "Reverse String: " << p << "\n";

	char c[] = "\0";
	std::cout << "Null String: " << c << "\n";
	p = reverseString(c);
	std::cout << "Reverse Null String: " << p << "\n";

	char b[] = "";
	std::cout << "Empty String: " << b << "\n";
	p = reverseString(b);
	std::cout << "Reverse Empty String: " << p << "\n";

	return 0;
}