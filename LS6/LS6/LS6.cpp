#include <iostream>
#include <clocale>
#include <stdlib.h>

 //Задание 1, функции:
// Функция заполнения массива значениями 2^n
void ArrIntFill(int *Arr, size_t ArrSize)		// В функцию передаётся указатель на массив Arr и его размер ArrSzie 
{
	Arr[0] = 2;									// Присваиваем [0] элементу массива значение 2 
	for (size_t i = 1; i < ArrSize; i++)		
		Arr[i] = Arr[i - 1] << 1;				// Следующий элемент в 2 раза больше предыдущего
}

// Функция Вывода массива на экран
void ArrIntOut(int* Arr, size_t ArrSize)		// В функцию передаётся указатель на массив Arr и его размер ArrSzie  
{
	for (size_t i = 0; i < ArrSize; i++)
		std::cout << Arr[i] << ", ";
}


int main()
{
	setlocale(LC_ALL, "Russian");						// Русский язык
	// Зажание 1:
	std::cout << "Задание 1 :\n";
	int* pArr1;											// Указатель массив
	size_t Arr1Size = 0;								// Длинна массива
	std::cout << "Введите длинну массива: ";
	std::cin >> Arr1Size;
	if (Arr1Size > 0)
	{
		pArr1 = new int[Arr1Size];						// Выделение памяпи под массив размером ArrSize
		ArrIntFill(pArr1, Arr1Size);					// Функция заполняющая массив
		ArrIntOut(pArr1, Arr1Size);						// Функция выводящая массив на экран

		delete[] pArr1;									// Освобождение памяти
		std::cout << "\n\n";
	}
	else
		std::cout << "Невозможно создать данный массив\n\n";


}