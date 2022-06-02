#include <iostream>
#include <clocale>
#include <fstream>


 // Задание 1, функции:
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

 // Задание 2, функции:
// Функция рандомного заполнения массива Y на Х 
void ArrYXIntRandFill(int** Arr, size_t ArrxSize, size_t ArrySize)	// В функцию предаётся массив указателей на одномерные массивы Arr и его размеры ArrySize, ArrxSize 
{
	srand(time(NULL));												// Инициируем рандом
	for (size_t i = 0; i < ArrySize; i++)							// Шаг по столбцам
		for (size_t ii = 0 ; ii < ArrxSize; ii++)					// Шаг по трокам
			*(*(Arr + i) + ii) = (rand() % 10);						// Заполняем рандомными числами от 0 до 10
}

// Функция Вывода двумерного массива на экран
void ArrYXIntOut(int** Arr, size_t ArrxSize, size_t ArrySize)		// В функцию предаётся массив указателей на одномерные массивы Arr и его размеры ArrySize, ArrxSize 
{
	for (size_t i = 0; i < ArrySize; i++)							// Шаг по столбцам
	{
		std::cout << "\n";
		for (size_t ii = 0; ii < ArrxSize; ii++)					// Шаг по трокам
			std::cout << Arr[i][ii] << " ";							// Вывод на экран [i][ii] элемента массива
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");						// Русский язык
	// Задание 1:
	std::cout << "Задание 1 :\n";
	int* pArr1;											// Указатель на массив
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
	
	// Задание 2:
	std::cout << "Задание 2:\n";

	int **pArr2;										// Массив указателей на одномерные массивы
	const size_t Arr2xSize = 4;							// Длинна массива
	const size_t Arr2ySize = 4;							// Ширина массива

	pArr2 = new int * [Arr2ySize];						// Массив указателей 
	for (size_t i = 0; i < Arr2ySize; i++)
		pArr2[i] = new int[Arr2xSize];					// В каждом iтом массиве указателей выделяем память на массив

	ArrYXIntRandFill(pArr2, Arr2xSize, Arr2ySize);		// Функция рандомного заполнения
	ArrYXIntOut(pArr2, Arr2xSize, Arr2ySize);			// Функция выводящая массив на экран

	for (size_t i = 0; i < Arr2ySize; i++)
		delete[] pArr2[i];								// Очищаем каждый iтый массив указателей
	delete[] pArr2;										// Очищаем указатель на массив
	std::cout << "\n\n";
	
	// Задание 3:

	std::cout << "Задание 3:\n";
	std::string FileName1, FileName2;					// Объявление переменных дkя имени файла
	
	std::cout << "Введите имя первого файла (латиницей) \n";
	std::cin >> FileName1;								// Ввод имени первого файла 
	FileName1 = FileName1 + ".txt";						// Добавление расширения
		
	std::ofstream fout;									
	fout.open(FileName1);								// Создание первого файла

	if (fout.is_open())									// Проверка на корректное открытие
	{
		fout << "There will come soft rains and the smell of the ground," << "\n";
		fout << "And swallows circling with their shimmering sound;" << "\n";
		fout << "And frogs in the pool singing at night," << "\n";
		fout << "And wild plum trees in tremulous white;" << "\n";
		fout << "Robins will wear their feathery fire," << "\n";
		fout << "Whistling their whims on a low fence-wire;" << "\n";
		fout.close();
		std::cout << "Файл " << FileName1 << " создан\n";
	}
	else
		std::cerr << "Ошибка создания файла";			
	
	std::cout << "Введите имя второго файла (латиницей) \n";
	
	do													// Проверка на совпадение имён
	{
		std::cin >> FileName2;
		FileName2 = FileName2 + ".txt";
		if (FileName1 == FileName2)
			std::cout << "Имена совпадают, введите другое имя\n";
	} while (FileName1 == FileName2);

	fout.open(FileName2);								// Создание второго файла

	if (fout.is_open())									// Проверка на корректное открытие
	{
		fout << "And not one will know of the war, not one," << "\n";
		fout << "Will care at last when it is done." << "\n";
		fout << "Not one would mind, neither bird nor tree," << "\n";
		fout << "If mankind perished utterly;" << "\n";
		fout << "And Spring herself when she woke at dawn" << "\n";
		fout << "Would scarcely know that we were gone." << "\n";
		fout << "\t" << " Sara Teasdale  1920" << "\n";
		fout.close();
		std::cout << "Файл " << FileName2 << " создан";
	}
	else
		std::cerr << "Ошибка создания файла";
}
