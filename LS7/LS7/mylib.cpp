#include <iostream>
#include <clocale>
#define ABS(x) (x = ((x) < 0) ? -(x) : (x));						// Модуль числа

namespace mylib
{
	 // Задание 1,5:
	// Функция рандомно заполняющая массива
	void ArrFloatFill(float* Arr, size_t ArrSize)
	{
		srand(time(NULL));
		for (size_t i = 0; i < ArrSize; i++)
		{
			Arr[i] = ((rand() % 100));	Arr[i] = Arr[i] / 10;		// На ходу придумал такой способ рандомного числа с десятичной частью
			Arr[i] = (((rand() % 2) == 0) ? -Arr[i] : Arr[i]);		// Рандомное создание отрицательных чисел
		}
	}
	
	// Функция выводящая массив на экран
	void ArrFloatOut(const float* Arr, size_t ArrSize)
	{
		for (size_t i = 0; i < ArrSize; i++)
		{
			std::cout << Arr[i] << ",  ";
		}
	}
	
	// Функция определяющая количество положительных и отрицательных чисел в массиве
	void ArrFloatNgN(const float* Arr, size_t ArrSize)
	{
		size_t ng = 0;												// Счетчик отрицмтельных чисел
		for (size_t i = 0; i < ArrSize; i++)
		{
			if (Arr[i] < 0)											// Увеличение счетчика, если число < 0
				ng++;
		}
		std::cout << "\nКоличестко положительнх чисел: " << ArrSize - ng << " Количестко отрицательных чисел: " << ng << "\n";
	}

	void task1()
	{
		int Arr1Size;

		std::cout << "Введите длинну массива: ";
		do {													// Проверка на 0 длинну массива
			std::cin >> Arr1Size;
			if (Arr1Size == 0)
				std::cout << "Массив не может быть нулевой длинны, введите новое значение: ";
		} while (Arr1Size == 0);
		if ( Arr1Size < 0)										// Проверка на отрицательную длинну массива
		{
			std::cout << "Массив не может быть отрицательной длинны, значение взято по модулю, новое значение: ";
			ABS(Arr1Size);
			std::cout << Arr1Size;
		}
		
		float *pArr1 = new (std::nothrow) float[Arr1Size];		// Выделение памяти для массива
		
		if (pArr1 != nullptr)									// Проверка выделения памяти 
		{
			mylib::ArrFloatFill(pArr1, Arr1Size);					// Заполнение
			ArrFloatOut(pArr1, Arr1Size);							// Вывод на экран
			ArrFloatNgN(pArr1, Arr1Size);							// Определение количества отрицательных чисел
		}
		else
			std::cerr << "Проблема выделения памяти"; 

		delete[] pArr1;											// Очиска памяти
	}

}