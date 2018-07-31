/*
	Jordan Mohler
	Lab 12
	Comp 2355
	20 February 2017
*/

#include <iostream>
#include "LinkedList.h"
#include <cstdint>
#include <string>

int main(int argc, const char * argv[])
{

	{
		LinkedList<uint64_t> list;

		list.Print();

		for (uint64_t i = 0; i < 10; i++)
		{
			list.InsertAtHead(i);
			list.Print();
		}

		list.Print();
		uint64_t h = list.PeekHead();
		std::cout << "Peek Head: " << h << std::endl;
		std::cout << "New List: ";
		list.Print();
		std::cout << "Remove Head: " << list.RemoveHead() << std::endl;
		std::cout << "New List: ";
		list.Print();

		std::cout << "Destructor" << std::endl;
		list.~LinkedList();

		std::cout << "New List: ";
		list.Print();
	}
  
	{
		LinkedList<std::string> list;

		list.Print();
		char* str = { "hello " };
		for (uint64_t i = 0; i < 10; i++)
		{
			list.InsertAtHead(str);
			list.Print();
		}

		list.Print();
		std::string h = list.PeekHead();
		std::cout << "Peek Head: " << h << std::endl;
		std::cout << "New List: ";
		list.Print();
		std::cout << "Remove Head: " << list.RemoveHead() << std::endl;;
		std::cout << "New List: ";
		list.Print();

		std::cout << "Destructor" << std::endl;
		list.~LinkedList();

		std::cout << "New List: ";
		list.Print();
	}

  return 0;
}
