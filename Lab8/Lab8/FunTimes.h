#ifndef FunTime_h
#define FunTime_h
using std::cout;
using std::cin;

template <typename T>
void readAndPrint(const char* string) {
	cout << "What " << string << " value would you like to print?\n";
	T answer;
	cin >> answer;
	cout << "Hexadecimal: " << std::hex << answer << "\n";
	cout << "Decimal: " << std::dec << answer << "\n";
	cout << "Size of value: " << sizeof(answer) << "\n";
}

#endif
