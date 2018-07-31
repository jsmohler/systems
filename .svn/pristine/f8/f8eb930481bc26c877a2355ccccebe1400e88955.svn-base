#include <iostream>
#include "MyString.h"

/*
	Jordan Mohler
	Comp 2355
	Lab 11
	15 February 2017

*/

MyString::MyString() {
	//Default Constructor
	string = new char[1];
	string[0] = '\0';
}

MyString::MyString(const MyString & source) {
	//Copy Constructor
	string = new char[source.length()+1];
	for (int i = 0; i < source.length(); i++) {
		this->string[i] = source.string[i];
	}
	string[source.length()] = '\0';
}

MyString::MyString(const char * source) {
	//Value constructor
	string = new char[strlen(source)+1];
	for (int i = 0; source[i] != '\0'; i++) {
		this->string[i] = source[i];
	}
	string[strlen(source)] = '\0';
}

MyString::~MyString() {
	//Destructor
	delete[] string;
	string = NULL;
}

MyString& MyString::operator=(const MyString & source) {
	char* temp = new char[source.length() + 1];
	for (int i = 0; i <= source.length(); i++) {
		temp[i] = source.string[i];
	}
	delete[] string;
	string = temp;
	return *this;
}

size_t MyString::length() const {
	return strlen(this->string);
}

const char* MyString::cString() const {
	return string;
}