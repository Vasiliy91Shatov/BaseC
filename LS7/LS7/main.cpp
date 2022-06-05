#include <iostream>
#include <clocale>
#include "mylib.h"

//#define ABS(x) (x = ((x) < 0) ? -(x) : (x));


int main()
{
	setlocale(LC_ALL, "Russian");						// Русский язык

	//Задание 1,5:
	std::cout << "Задание 1:\n";
	mylib::task1();
	std::cout << "\n";

	// Задание 2:
	std::cout << "Задание 2:\n";
	mylib::task2();
	std::cout << "\n";

}