#include <iostream>
#include <clocale>


int main()
{
	setlocale(LC_ALL, "Russian");
	
	// Задание 1:
	
	int num1, num2;
	std::cout << "Введите первое целое число: ";
	std::cin >> num1;
	std::cout << "Введите второе целое число: ";
	std::cin >> num2;
	std::cout << "Суммма этих чисел (" << num1 + num2 << ") лежит в пределах от 10 до 20 ? ";
	if ((num1 + num2) >= 10 && (num1 + num2) <= 20)
		std::cout << "Ture";
	else
		std::cout << "False";
}