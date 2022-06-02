#include <iostream>
#include <clocale>
	
	// Заданеи 1, функция:
// Функция проверяющая массив на заполненность (как в вебинаре)
bool ArrDoublePrint(double* Arr, int ArrSize)	// В функцию передаются: Arr - массив, ArrSize - размер массива
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
// Функция замены 1 на 0 и обратно, с проверкой на заполненность 
bool ArrIntBinCh(int* Arr, int ArrSize)			// В функцию передаются: Arr - массив, ArrSize - размер массива 
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
// Функция заполнения массива
void ArrIntFill(int* Arr, int ArrSize)			// В функцию передаются: Arr - массив, ArrSize - размер массива 
{
	int a = 1;									// Переменная для заполнения массива
	for (int i = 0; i < ArrSize; i++)			// Заполнение массива согласно задания от 1 с шагом 3
	{
		Arr[i] = a;
		a += 3;
	}
}

	// Задание 4, Функция:
// Функция реализующая сдвиг массива
void ArrIntMoveVar1(int * Arr, int * ArrST, const int ArrSize, int Mv)	// В функцию передаются: Arr - массив, ArrST - массив для временных данных, ArrSize - размер массива, Mv - сдвиг 
{							
	bool Sn = 1;				// Знак переменной Mv (сдвиг)
	
	if (Mv < 0)					// Модуль Mv
	{
		Mv *= -1;
		Sn = 0;
	}

	while (Mv >= ArrSize)		// есзи значение сдвига больше или равно размеру массива - уменьшаем его на размер массива пока сдвиг не будет меньше массива
		Mv -= ArrSize;
	
	if (Sn == 0)				// Если Mv (сдвиг) был отрицательным
		Mv = ArrSize - Mv;		// 1 сдвиг влево = 5 (или ArrSize - 1) сдвигам вправо для массива размером [6]

	if (Mv != 0)				// Если сдвиг не равен 0, то выполняем сдвиг
	{
		for (int i = 0; i < Mv; i++)
			ArrST[i] = Arr[ArrSize - Mv + i];

		for (int i = 0; i < (ArrSize - Mv); i++)
			ArrST[i + Mv] = Arr[i];
		for (int i = 0; i < ArrSize; i++)
		{
			Arr[i] = ArrST[i]; ArrST[i] = 0;
		}
	}
}
// П.С. Не получилось в функции инициализировать массив с размером ArrSize, поэтому в 1 вариант трубуеться передача пустого массива
// Сделал 2й вариант (болле тяжелый) без необходимости передачи в функцию дополнительного пустого массива

// Болле сложная функция без временного массива
void ArrIntMoveVar2(int* Arr, int ArrSize, int Mv)		// В функцию передаются: Arr - массив, ArrSize - размер массива, Mv - сдвиг 
{
	bool MvR = 1;					// флаг направления сдвига. Если 1 то вправо

	if (Mv < 0)						// Если переменная Mv имеет занк "-" то изменяенм направление сдвига
	{
		Mv *= -1;
		MvR = 0;
	}
	while (Mv >= ArrSize)			// есзи значение сдвига больше или равно размеру массива - уменьшаем его на размер массива пока сдвиг не будет меньше массива
	{
		Mv -= ArrSize;
	}
	if (Mv != 0)					// Если сдвиг не равен 0, то выполняем сдвиг
	{	
		if (Mv < (ArrSize / 2))		// Программа не работает корректно, если количество cдвигов меньше половины массива
		{							// В случае если количество сдвигов меньше половины массива потребуются сдвиги в центре массива
			Mv = ArrSize - Mv;		// 1 сдвиг влево = 5 (или ArrSize - 1) сдвигам вправо для массива размером [6]
			MvR = MvR ^ 1;			// меняем знак флага направления сдвига
		}
		if (MvR == 1)				// сдвиг вправо
		{
			for (int i = 0; i < Mv; i++)	// Последовательная замена всех элементов с начала в конец
			{
				Arr[i] = Arr[i] ^ Arr[i + ArrSize - Mv];
				Arr[i + ArrSize - Mv] = Arr[i] ^ Arr[i + ArrSize - Mv];
				Arr[i] = Arr[i] ^ Arr[i + ArrSize - Mv];
			}
		}
		else						// сдвиг влево
		{
			for (int i = ArrSize - 1; i > (ArrSize - Mv - 1); i--) // Последовательная замена всех элементов с конца в начало
			{
				Arr[i] = Arr[i] ^ Arr[i - (ArrSize - Mv)];
				Arr[i - (ArrSize - Mv)] = Arr[i] ^ Arr[i - (ArrSize - Mv)];
				Arr[i] = Arr[i] ^ Arr[i - (ArrSize - Mv)];
			}
		}
	}
}



int main()
{
	setlocale(LC_ALL, "Russian");						// Русский язык

	// Задание 1:
	const int Arr1Size = 10;							// Размер массива для первого задания
	double Arr1[Arr1Size] = {1.1};						// Объявление массива
	for (int i = 1; i < Arr1Size; i++)
		Arr1[i] = Arr1[i - 1] + 0.2;					// Инициализация массива через цикл
	std::cout << "Задание 1 :\n\n";
	if (ArrDoublePrint(Arr1, Arr1Size))					// Если функция вернула true - массив напечатан
		std::cout << "\nМассив размером " << Arr1Size << ", корректно напечатан через функцию.\n";
	else												// Иначе ошибка - пустой массив
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
	int Arr3[Arr3Size] = {NULL};						// Объявление пустого массива
	ArrIntFill(Arr3, Arr3Size);							// Заполнение массива через функцию
	std::cout << "Заполненниый массив:\n";
	for (int i = 0; i < Arr3Size; i++)
		std::cout << Arr3[i] << " ";
	std::cout << "\n\n";

	// Задание 4:
	std::cout << "Задание 4:\n\n";
	const int Arr4Size = 6;								// Размер массива для 4 задания
	int Arr4[Arr4Size] = { 0,1,2,3,4,5,};				// Объявление, инициализация массива
	int ArrSt[Arr4Size] = { NULL };						// Временный массив
	int Mv = 4;											// сдвиг
	std::cout << "Исходный массив:\n";
	for (int i = 0; i < Arr4Size; i++)
		std::cout << Arr4[i] << " ";
	std::cout << "\n";
	std::cout << "Введите число на которое будет сдвинут массив (отрицательное число - сдвиг влево):\n";
	std::cin >> Mv;

	/*std::cout << "Вариант 1:\n";
	ArrIntMoveVar1(Arr4, ArrSt, Arr4Size, Mv);
	for (int i = 0; i < Arr4Size; i++)
		std::cout << Arr4[i] << " ";
	std::cout << "\n";*/
	
	std::cout << "Вариант 2:\n";
	ArrIntMoveVar2(Arr4, Arr4Size, Mv);
	for (int i = 0; i < Arr4Size; i++)
		std::cout << Arr4[i] << " ";
	std::cout << "\n";

}