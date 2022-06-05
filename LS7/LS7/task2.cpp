#include <iostream>

// макро-функци€ определ€юща€ входит ли число num в дипазон с 0, до end
#define RANGE(num , end) ((((num) >= 0) and (num < end)) ? "true" : "false");
 
namespace mylib
{
	void task2()
	{
		float num2;								// сравниваема€ переменна€
		const size_t rend = 10;					// конец диапазона
		std::cout << "¬ведите число: ";
		std::cin >> num2;
		std::cout << "„исло " << num2 << " входит в диапазон с 0, до " << rend << " ? ";
		std::cout << RANGE(num2, rend);
	}
}