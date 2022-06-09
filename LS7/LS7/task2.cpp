#include <iostream>
#include <clocale>

// макро-функция определяющая входит ли число num в дипазон от 0 (включительно), до end
#define RANGE(num , end) ((((num) >= 0) and (num < end)) ? true : false);
 
namespace mylib
{
	void task2()
	{
		float num;												// сравниваемая переменная
		const size_t rend = 10;									// конец диапазона
		std::cout << "Введите число: ";
		std::cin >> num;
		std::cout << "Число " << num << " входит в диапазон с 0, до " << rend << " ? ";
		bool fl = RANGE(num, rend);								// логическая переменная считывающая значенеи макрофункции RANGE
		std::cout << ((fl == 0) ? "false" : "true") << "\n";	// Вывод на экран false или true в зависимости от того, что вернула макрофункция RANGE
	}
}