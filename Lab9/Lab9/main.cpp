#include <iostream>
#include <chrono>
#include <ctime>
using std::cout;

/*
	Jordan Mohler
	Comp 2355
	Lab 9
	8 February 2017
*/

int main(int argc, char* argv[]) {
	const int size = 5000;
	int* data = new int[size*size];

	{
		std::chrono::time_point<std::chrono::system_clock> start, end;
		start = std::chrono::system_clock::now();

		for (int z = 0; z < size; z++) {
			for (int y = 0; y < size; y++) {
				data[z*size + y] += y;
			}
		}

		end = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed_seconds2 = end - start;
		cout << "Elapsed time with call 2D Optimized: " << elapsed_seconds2.count() << "s\n";
	}

	{
		std::chrono::time_point<std::chrono::system_clock> start, end;
		start = std::chrono::system_clock::now();

		for (int y = 0; y < size; y++) {
			for (int z = 0; z < size; z++) {
				data[z*size + y] += y;
			}
		}

		end = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed_seconds2 = end - start;
		cout << "Elapsed time with call 2D Unoptimized: " << elapsed_seconds2.count() << "s\n";
	}

	const int size2 = 100;
	int* threeD = new int[size2*size2*size2];

	{
		std::chrono::time_point<std::chrono::system_clock> start, end;
		start = std::chrono::system_clock::now();

		for (int x = 0; x < size2; x++) {
			for (int y = 0; y < size2; y++) {
				for (int z = 0; z < size2; z++) {
					threeD[size2*size2*x + size2*y + z] += x;
				}
			}
		}

		end = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed_seconds2 = end - start;
		cout << "Elapsed time with call 3D Optimized: " << elapsed_seconds2.count() << "s\n";
	}

	{
		std::chrono::time_point<std::chrono::system_clock> start, end;
		start = std::chrono::system_clock::now();

		for (int y = 0; y < size2; y++) {
			for (int z = 0; z < size2; z++) {
				for (int x = 0; x < size2; x++) {
					threeD[size2*size2*x + size2*y + z] += x;
				}
			}
		}

		end = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed_seconds2 = end - start;
		cout << "Elapsed time with call 3D UnoptimizedY: " << elapsed_seconds2.count() << "s\n";
	}

	{
		std::chrono::time_point<std::chrono::system_clock> start, end;
		start = std::chrono::system_clock::now();

		for (int z = 0; z < size2; z++) {
			for (int y = 0; y < size2; y++) {
				for (int x = 0; x < size2; x++) {
					threeD[size2*size2*x + size2*y + z] += x;
				}
			}
		}

		end = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed_seconds2 = end - start;
		cout << "Elapsed time with call 3D UnoptimizedZ: " << elapsed_seconds2.count() << "s\n";
	}

	return 0;
}