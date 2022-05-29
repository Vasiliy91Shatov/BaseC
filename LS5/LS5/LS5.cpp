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

	// Задание 3, функция:
void ArrIntFill(int* Arr, int ArrSize)			// Функция заполнения массива
{
	int a = 1;									// Переменная для заполнения массива
	for (int i = 0; i < ArrSize; i++)			// Заполнение массива согласно задания от 1 с шагом 3
	{
		Arr[i] = a;
		a += 3;
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
	std::cout << "Задание 1 :\n\n";
	if (ArrDoublePrint(Arr1, Arr1Size))				// Если функция вернула true - массив напечатан
		std::cout << "\nМассив размером " << Arr1Size << ", корректно напечатан через функцию.\n";
	else											// Иначе ошибка - пустой массив
		std::cerr << "Массив пустой\n";
	std::cout << "\n";

	// Задание 2:
	std::cout << "Задание 2:\n\n";
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

	// Задание 3:
	std::cout << "Задание 3:\n\n";
	const int Arr3Size = 8;								// Размер массива для третьего задания
	int Arr3[Arr3Size] = {NULL};						// Объявление массива 
	ArrIntFill(Arr3, Arr3Size);							// Заполнение массива через функцию
	std::cout << "Заполненниый массив:\n";
	for (int i = 0; i < Arr3Size; i++)
		std::cout << Arr3[i] << " ";
	std::cout << "\n\n";
}