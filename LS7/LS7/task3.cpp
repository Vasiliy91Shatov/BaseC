#include <iostream>

#define ArrSize 5							// ������ �������
#define SWAP(x, y) (std::swap(x, y));		// ���� ������� ������ (������� �� ��������� =))
/*#define SWAP(x, y) x = x + y; \
y = x - y; \
x = x - y;	*/								// ������ ������� ������

#define ABS(x) (x = ((x) < 0) ? -(x) : (x));

namespace mylib
{
	// ������� ������ ������� �� �����
	void ArrIntOut(const int* arr)
	{
		for (size_t i = 0; i < ArrSize; i++)
			std::cout << arr[i] << ", ";
	}

	// ������� ���������� ������� ������� "��������"
	void ArrIntSort(int* arr)
	{
		size_t sch = 0;									// �������
		size_t nArrSize = ArrSize;						// ���������� ��� ����������� ������ ���������� "���������"
		// ������: ��� ������� 1 ����� ���������� "���������" � ����� ������� ������������ ����� ������� ��������
		// ���������� ����� ����� ��������� ����� ���������� ������� �� 1
		size_t ch = 0;								    // ���������� ��� �������� ������� ������������
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
			nArrSize -= 1;								// ���������� ������ ������� ���������� ����� 
			//ArrIntOut(arr);							  // ���������� ���������
			//std::cout << "\n";
			if (ch == 0)
				break;									// ���� ���� ���� �� ���� �����������
		}
		//std::cout << "���������� ������������: " << sch; // ������� ���������� ������������
	}
	
	// ������� ������������� ������� �������������
	void ArrIntFill(int* arr)
	{
		for (size_t i = 0; i < ArrSize; i++)
		{
			std::cout << "������� " << i + 1 << "� ������� ������� ";
			std::cin >> arr[i];
		}
	}

	void task3()
	{
		int arr[ArrSize] = {0};
		
		ArrIntFill(arr);

		std::cout << "�������� ������\n";
		ArrIntOut(arr);
		std::cout << "\n";

		ArrIntSort(arr);
		std::cout << "\n";

		std::cout << "��������������� ������\n";
		ArrIntOut(arr);
		std::cout << "\n";

	}
}