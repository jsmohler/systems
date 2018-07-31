#include <iostream>
#include "MyString.h"

/*
	Jordan Mohler
	Comp 2355
	Lab 15
	1 March 2017
*/

//define function to test MyString on heap heap
void testHeap(MyString* s, MyString* m) {
	std::cout << "Empty: '" << *s << "'\n";
	*s = "hello";
	std::cout << "After operator=: '" << *s << "'\n";
	{
		MyString t(*s);
		std::cout << "After copy: '" << t << "'\n";
		*s = t;
	}

	std::cout << "After constructor: '" << *m << "'\n";
	*m = *s;
	std::cout << "After operator=: '" << *m << "'\n";
	*m = *m;
	std::cout << "After operator=: '" << *m << "'\n";

	*s += ",";
	*s += *m;
	std::cout << "After operator +=: " << *s << "\n";
	*s += ",goodbye";
	std::cout << "After operator +=: " << *s << "\n";
}

int main(int argc, const char * argv[])
{
	MyString s;
	std::cout << "Empty: '" << s << "'\n";
	s = "hello";
	std::cout << "After operator=: '" << s << "'\n";
	{
		MyString t(s);
		std::cout << "After copy: '" << t << "'\n";
		s = t;
	}

	MyString m(" world");
	std::cout << "After constructor: '" << m << "'\n";
	m = s;
	std::cout << "After operator=: '" << m << "'\n";
	m = m;
	std::cout << "After operator=: '" << m << "'\n";

	s += ",";
	s += m;
	std::cout << "After operator +=: " << s << "\n";
	s += ",goodbye";
	std::cout << "After operator +=: " << s << "\n";

	MyString abc("abc");
	std::cout << abc.cString();
	abc += abc;
	std::cout << "After operator += to self: " << abc << "\n";

	MyString sum = MyString("2+2") + "=5?";
	std::cout << "After operator +: " << sum << "\n";

	sum[4] = '4';
	sum[5] = '!';
	std::cout << "After operator []:" << sum << "\n";

	const MyString u("A const string.");
	std::cout << "Using const []: ";
	for (size_t i = 0; i < u.length(); ++i) {
		std::cout << u[i];
	}
	std::cout << "\n";
	std::cout << "\nHeap Test: \n";

	//test heap
	MyString *j = new MyString("hello");
	MyString *k = new MyString(" world");

	testHeap(j, k);

	return 0;
}