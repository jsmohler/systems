#include <iostream>
#include <string>
using std::cout;
using std::cin;

int main(int argc, const char* argv[]) {
	cout << "Hello, what is your name? \n";
	std::string answer;
	cin >> answer;
	cout << "Greetings, " + answer + ", from a C++ program.";
	return 0;
}