#include <iostream>
#include <clocale>
#include "mylib.h"


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

	// Задание 3:
	std::cout << "Задание 3:\n";
	mylib::task3();
	std::cout << "\n";
}