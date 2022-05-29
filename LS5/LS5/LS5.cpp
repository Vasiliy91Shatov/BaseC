#include <iostream>
#include <clocale>
	
	// Заданеи 1, функция:
bool ArrDoublePrint(double* Arr, int ArrSize)	// Функция проверяющая массив на заполненность (как в вебинаре)
{
	if ((Arr == nullptr) or (ArrSize == 0))		// Если массив пустой возвращает false
		return false;
	else {										// Если массив не пустой возвращает true
		for (int i = 0; i < ArrSize; i++)		
			std::cout << Arr[i] << " ";
		return true;
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");					// Русский язык
	
	// Задание 1:
	const int Arr1Size = 10;						// Размер массива для первого задания
	double Arr1[Arr1Size] = {1.1};					// Объявление массива
	for (int i = 1; i < Arr1Size; i++)
		Arr1[i] = Arr1[i - 1] + 0.2;				// Инициализация массива через цикл
	std::cout << "Задание 1 :" << std::endl << std::endl;
	if (ArrDoublePrint(Arr1, Arr1Size))				// Если функция вернула true - массив 
		std::cout << std::endl << "Массив размером " << Arr1Size << ", корректно напечатан через функцию" << std::endl;
	else											// Иначе ошибка - пустой массив
		std::cerr << "Массив пустой" << std::endl;
	std::cout << std::endl;
}