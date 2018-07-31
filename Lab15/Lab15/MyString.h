#ifndef MyString_h
#define MyString_h

class MyString {
public:
	MyString();
	MyString(const MyString &);
	MyString(const char *);
	~MyString();
	MyString &operator=(const MyString &);
	MyString &operator+=(const MyString &);
	char operator[](size_t i) const;
	char &operator[](size_t i);
	size_t length() const;
	const char *cString() const;
private:
	char *string;
//	size_t stringLength;  // not required, but handy to keep around
						  // You may add helper functions here if desired
};

MyString operator+(const MyString &s1, const MyString &s2) {
	MyString newString(s1);
	newString += s2;
	return newString;
}

std::ostream& operator<<(std::ostream& os, const MyString& s) {
	os << s.cString();
	return os;
}

MyString::MyString()
{
	string = new char[1];
	string[0] = '\0';
}

MyString::MyString(const MyString& s)
{
	string = new char[s.length() + 1];
	for (int i = 0; i < length(); i++)
	{
		string[i] = s.string[i];
	}
	string[s.length()] = '\0';

}

MyString::MyString(const char *s)
{
	string = new char[strlen(s) + 1];

	for (int i = 0; i < strlen(s); i++)
	{
		string[i] = s[i];
	}
	string[strlen(s)] = '\0';

}

MyString::~MyString()
{
	delete[] string;
	string = NULL;
}

MyString& MyString::operator=(const MyString& s)
{
	if (this == &s) return *this;

	string = new char[s.length() + 1];
	for (int i = 0; i < s.length(); i++)
	{
		string[i] = s.string[i];
	}
	string[s.length()] = '\0';

	return *this;

}

size_t MyString::length() const
{
	return strlen(string);
}

const char* MyString::cString() const
{
	return string;
}

MyString& MyString::operator+=(const MyString & s) {
	char* temp = string;
	int x = length() + s.length() + 1;
	string = new char[x]; 
	int y = strlen(temp);
	for (int i = 0; i < y; i++) {
		string[i] = temp[i];
	}
	for (int j = y; j < x; j++) {
		string[j] = s[j - y];
	}
	string[x-1] = '\0';
	return *this;
}

char MyString::operator[](size_t i) const {
	if (i >= length()) {
		return '\0';
	}
	return string[i];
}

char& MyString::operator[](size_t i) {
	if (i >= length()) {
		return string[length()];
	}
	return string[i];
}

#endif
