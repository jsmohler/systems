#include <iostream>

/*
	Jordan Mohler
	COMP 2355
	Assignment 1
	11 January 2017
*/


using std::cout;
using std::cin;

int main(int argc, const char*argv[]) {
	int numbers[10];
	int numSize = sizeof(numbers) / sizeof(*numbers);
	cout << "Please input " << numSize << " numbers\n";

	int answer;

	for (int i = 0; i < numSize; i++) {
		cin >> answer;
		numbers[i] = answer;
	}

	//Print the array before sorting
	cout << "Numbers before sort:";
	for (int i = 0; i < numSize; i++) {
		cout << " " << numbers[i];
	}
	cout << "\n";

	//Sort the array
	for (int i = 1; i < numSize; i++) {
		int temp = numbers[i];
		int j = i - 1;
		while (j >= 0 && numbers[j] > temp) {
			numbers[j + 1] = numbers[j];
			--j;
		}
		numbers[j + 1] = temp;
	}

	//Print the array after sorting
	cout << "Numbers after sort:";
	for (int i = 0; i < numSize; i++) {
		cout << " " << numbers[i];
	}
	cout << "\n";

	return 0;
}