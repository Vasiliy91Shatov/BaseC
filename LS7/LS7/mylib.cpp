#include <iostream>
#include <clocale>
#define ABS(x) (x = ((x) < 0) ? -(x) : (x));						// ������ �����

namespace mylib
{
	 // ������� 1,5:
	// ������� �������� ����������� �������
	void ArrFloatFill(float* Arr, size_t ArrSize)
	{
		srand(time(NULL));
		for (size_t i = 0; i < ArrSize; i++)
		{
			Arr[i] = ((rand() % 100));	Arr[i] = Arr[i] / 10;		// �� ���� �������� ����� ������ ���������� ����� � ���������� ������
			Arr[i] = (((rand() % 2) == 0) ? -Arr[i] : Arr[i]);		// ��������� �������� ������������� �����
		}
	}
	
	// ������� ��������� ������ �� �����
	void ArrFloatOut(const float* Arr, size_t ArrSize)
	{
		for (size_t i = 0; i < ArrSize; i++)
		{
			std::cout << Arr[i] << ",  ";
		}
	}
	
	// ������� ������������ ���������� ������������� � ������������� ����� � �������
	void ArrFloatNgN(const float* Arr, size_t ArrSize)
	{
		size_t ng = 0;												// ������� ������������� �����
		for (size_t i = 0; i < ArrSize; i++)
		{
			if (Arr[i] < 0)											// ���������� ��������, ���� ����� < 0
				ng++;
		}
		std::cout << "\n���������� ������������ �����: " << ArrSize - ng << " ���������� ������������� �����: " << ng << "\n";
	}

	void task1()
	{
		int Arr1Size;

		std::cout << "������� ������ �������: ";
		do {													// �������� �� 0 ������ �������
			std::cin >> Arr1Size;
			if (Arr1Size == 0)
				std::cout << "������ �� ����� ���� ������� ������, ������� ����� ��������: ";
		} while (Arr1Size == 0);
		if ( Arr1Size < 0)										// �������� �� ������������� ������ �������
		{
			std::cout << "������ �� ����� ���� ������������� ������, �������� ����� �� ������, ����� ��������: ";
			ABS(Arr1Size);
			std::cout << Arr1Size;
		}
		
		float *pArr1 = new (std::nothrow) float[Arr1Size];		// ��������� ������ ��� �������
		
		if (pArr1 != nullptr)									// �������� ��������� ������ 
		{
			mylib::ArrFloatFill(pArr1, Arr1Size);					// ����������
			ArrFloatOut(pArr1, Arr1Size);							// ����� �� �����
			ArrFloatNgN(pArr1, Arr1Size);							// ����������� ���������� ������������� �����
		}
		else
			std::cerr << "�������� ��������� ������"; 

		delete[] pArr1;											// ������ ������
	}

}