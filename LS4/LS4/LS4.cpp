﻿#include <iostream>
#include <clocale>


int main()
{
	setlocale(LC_ALL, "Russian");
	
	// Задание 1:
	
	int num1, num2;
	std::cout << "Задние 1:" << std::endl << std::endl;
	std::cout << "Введите первое целое число: ";
	std::cin >> num1;
	std::cout << "Введите второе целое число: ";
	std::cin >> num2;
	std::cout << "Суммма этих чисел (" << num1 + num2 << ") лежит в пределах от 10 до 20 ? ";
	if ((num1 + num2) >= 10 && (num1 + num2) <= 20)
		std::cout << "Ture" << std::endl << std::endl;
	else
		std::cout << "False" << std::endl << std::endl;

	// Задание 2:
	
	std::cout << "Задание 2:" << std::endl << std::endl;
	const int con1 = 10;
	const int con2 = 10;	// объявление целочисленных констант
	std::cout << "Первая целочисленная константа: " << con1 << std::endl << "Вторая целочисленная константа: " << con2 << std::endl;
	std::cout << "O6e константы равны 10 или их сумма равна 10? ";
	if ((con1 == 10) && (con2 == 10))
		std::cout << "True" << std::endl << std::endl;
	else if ((con1 + con2) == 10)
		std::cout << "True" << std::endl << std::endl;
	else
		std::cout << "False" << std::endl << std::endl;
}