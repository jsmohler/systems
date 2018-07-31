#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdint>


/*
	Jordan Mohler
	Comp 2355
	8 March 2017
	Lab 17
*/

int main(int argc, char* argv[]) {
	std::vector<uint64_t> fib;
	fib.push_back(0);
	fib.push_back(1);
	fib.push_back(1);

	std::unordered_map<uint64_t, int> fibMap;
	fibMap[1] = 2;

	for (int i = 3; i < 94; i++) {
		uint64_t n = fib[i - 1] + fib[i - 2];
		fib.push_back(n);
		fibMap[n] = i;
	}

	int index = 0;
	std::cout << "Fibonacci numbers in order:\n";
	for (auto i = fib.begin(); i != fib.end(); i++) {
		std::cout << index << " " << *i << "\n";
		index++;
	}

	std::cout << "\nFibonacci numbers and indices, unordered:\n";
	for (auto i = fibMap.begin(); i != fibMap.end(); i++) {
		std::cout << i->second << " " << i->first << "\n";
	}

	std::cout << "\nTesting Fibonacci numbers from 1 to 15:\n";
	for (int i = 1; i <= 15; i++) {
		if (fibMap.find(i) != fibMap.end()) {
			std::cout << i << " " << fibMap.find(i)->second << "\n";
		}
		else {
			std::cout << i << " no\n";
		}
	}

	return 0;
}