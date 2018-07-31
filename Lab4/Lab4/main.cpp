
/*
	Jordan Mohler
	COMP 2355
	18 January 2016
	Lab4
*/

#include <iostream>
#include <chrono>
#include <ctime>
using std::cout;

//Part I(a) of Lab 4
void swap_value(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}

void swap_reference(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void swap_pointer(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

//Part II(a) of Lab4
struct pair {
	int one, two;
};

void swap_value(pair p) {
	int temp = p.one;
	p.one = p.two;
	p.two = temp;
}

void swap_reference(pair& p) {
	int temp = p.one;
	p.one = p.two;
	p.two = temp;
}


void swap_pointer(pair *p) {
	int temp = (*p).one;
	(*p).one = (*p).two;
	(*p).two = temp;
}

//Part III(a) of Lab4
struct myStruct {
	int arr[500];
};


int main(int argc, char* argv[]) {

	//Part I(b) of Lab4
	cout << "Part I:\n\n";
	int c = 1;
	int d = 2;
	int &e = c;
	int &f = d;
	int *g = &c;
	int *h = &d;

	swap_value(c, d);
	cout << "C: " << c << " D: " << d << "\n";
	swap_reference(e, f);
	cout << "C: " << c << " D: " << d << "\n";
	swap_pointer(g, h);
	cout << "C: " << c << " D: " << d << "\n";

	//Part II of Lab 4
	cout << "\nPart II:\n\n";

	pair p;
	p.one = 3;
	p.two = 4;

	swap_value(p);
	cout << "One: " << p.one << " Two: " << p.two << "\n";
	swap_reference(p);
	cout << "One: " << p.one << " Two: " << p.two << "\n";
	swap_pointer(&p);
	cout << "One: " << p.one << " Two: " << p.two << "\n\n";

	//Part III of Lab4



	myStruct s;

	for (int i = 0; i < 500; i++) {
		s.arr[i] = i;
	}

	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();

	int sum = 0;
	for (int i = 0; i < 10000; i++) {
		for (int j = 0; j < 500; j++) {
			sum = sum + s.arr[j];
		}
	}

	end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	cout << "Elapsed time with call by value: " << elapsed_seconds.count() << "s\n";

	start = std::chrono::system_clock::now();

	sum = 0;
	for (int i = 0; i < 10000; i++) {
		while(*s.arr) {
			(*s.arr)++;
			sum = sum + *s.arr;

		}
	}

	end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds2 = end - start;
	cout << "Elapsed time with call by const: " << elapsed_seconds2.count() << "s\n";

	return 0;
}
