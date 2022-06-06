#include <iostream>

#define ArrSize 5							// Размер массива
#define SWAP(x, y) (std::swap(x, y));		// Один вариант замены (спасибо за подсказку =))
/*#define SWAP(x, y) x = x + y; \
y = x - y; \
x = x - y;	*/								// Другой вариант замены

#define ABS(x) (x = ((x) < 0) ? -(x) : (x));

namespace mylib
{
	// функция вывода массива на экран
	void ArrIntOut(const int* arr)
	{
		for (size_t i = 0; i < ArrSize; i++)
			std::cout << arr[i] << ", ";
	}

	// функция сортировки массива методом "пузырька"
	void ArrIntSort(int* arr)
	{
		size_t sch = 0;									// Счетчик
		size_t nArrSize = ArrSize;						// Переменная для уменьшенния циклов сортировки "пузырьком"
		// Логика: при проходе 1 цикла сортировки "пузырьком" в конце массива оказываеться самое большое значение
		// Вследствии этого можно сокращать динну следующего прохода на 1
		size_t ch = 0;								    // Переменная для проверки наличия перестановок
		for (size_t i = 0; i < ArrSize - 1; i++)
		{
			ch = 0;								
			for (size_t ii = 1; ii < nArrSize; ii++)
			{
				if (arr[ii] < arr[ii - 1])
				{
					SWAP(arr[ii], arr[ii - 1])
					ch = 1;
					sch++;
				}
			}
			nArrSize -= 1;								// Уменьшение длинны прохода вложенного цикла 
			//ArrIntOut(arr);							  // Отладочные сообщения
			//std::cout << "\n";
			if (ch == 0)
				break;									// Стоп цикл если не было перстановок
		}
		//std::cout << "Количкство перестановок: " << sch; // счетчик количества перестановок
	}
	
	// функция инициализации массива пользователем
	void ArrIntFill(int* arr)
	{
		for (size_t i = 0; i < ArrSize; i++)
		{
			std::cout << "Введите " << i + 1 << "й элемент массива ";
			std::cin >> arr[i];
		}
	}

	void task3()
	{
		int arr[ArrSize] = {0};
		
		ArrIntFill(arr);

		std::cout << "Введённый массив\n";
		ArrIntOut(arr);
		std::cout << "\n";

		ArrIntSort(arr);
		std::cout << "\n";

		std::cout << "Отсортированный массив\n";
		ArrIntOut(arr);
		std::cout << "\n";

	}
}