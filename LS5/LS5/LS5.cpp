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

	// Задание 2, функция:
bool ArrIntBinCh(int* Arr, int ArrSize)			// Функция замены 1 на 0 и обратно, с проверкой на заполненность 
{
	if ((Arr == nullptr) or (ArrSize == 0))		// Если массив пустой возвращает false
		return false;
	else {										// Если массив не пустой возвращает true
		for (int i = 0; i < ArrSize; i++)
			Arr[i] = Arr[i] ^ 1;				// Или не с 1 меняет 1 на 0 и обратно
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
	if (ArrDoublePrint(Arr1, Arr1Size))				// Если функция вернула true - массив напечатан
		std::cout << std::endl << "Массив размером " << Arr1Size << ", корректно напечатан через функцию" << std::endl;
	else											// Иначе ошибка - пустой массив
		std::cerr << "Массив пустой" << std::endl;
	std::cout << std::endl;

	// Задание 2:
	const int Arr2Size = 11;							// Размер массива для второго задания
	int Arr2[Arr2Size] = { 1,0,1,0,0,1,1,1,0,1,0 };		// Объявление, инициализация массива
	std::cout << "Изначальный массив:\n";
	for (int i = 0; i < Arr2Size; i++)					// Вывод массива
		std::cout << Arr2[i] << " ";
	std::cout << std::endl;
	if (ArrIntBinCh(Arr2, Arr2Size))					// Если функция вернула true - массив изменён
		std::cout << "Изменённиый массив:\n";
	else												// Иначе ошибка - пустой массив
		std::cerr << "Массив пустой\n";
	for (int i = 0; i < Arr2Size; i++)					// Вывод массива после изменения
		std::cout << Arr2[i] << " ";
	std::cout << "\n\n";
}