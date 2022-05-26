#include <iostream>
#include <clocale>

// Задание 4 функция:
void PrNum(int num)				// функция определяющая являеться ли число простым, и выводящая на экран соответствующую строку
{
	int n = 0;					// счетчик количества делений числа
	for (int i = 1; i <= num; i++)
	{
		if (n == 3)
			break;				// прерываем цикл, если n = 3 (чило уже не является простым, и дальнейшии вычисления не нужны)
		else if (num % i == 0)	// если число делится на i, то n увеличивается на 1
			n++;
	}
	(n < 3) ? std::cout << "Число является простым" : std::cout << "Число не является простым"; 
}

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

	// Задание 3:

	std::cout << "Задание 3:" << std::endl << std::endl;
	int MaxNum = 50;		// Максимальный диапазон
	std::cout << "Нечетные числа от 1 до " << MaxNum << std::endl;
	for (int i = 1; i <= MaxNum; i += 2)
		std::cout << i << ", ";
	std::cout << std::endl << std::endl;

	// Задание 4:

	int num;
	std::cout << "Задание 4:" << std::endl << std::endl;
	std::cout << "Введите целое положительное число: ";
	std::cin >> num;
	PrNum(num);
	std::cout << std::endl << std::endl;

	// Задание 5:

	int year;
	bool ly = 0;					// флаг высокосного года
	std::cout << "Задание 5:" << std::endl << std::endl;
	std::cout << "Введите целое положительное число (год): ";
	std::cin >> year;
	if (year % 4 == 0)				// проверяем на кратность 4
	{
		ly = 1;
		if (year % 100 == 0)		// исключаем из предыдущей провески все числа кратные 100
		{
			ly = 0;
			if (year % 400 == 0)	// искичение для чисел кратных 400
				ly = 1;
		}
	}
	(ly == 0) ? std::cout << "Год не високосный" : std::cout << "Год високосный";
}