#include <iostream>
#include <clocale>

// �����-������� ������������ ������ �� ����� num � ������� � 0, �� end
#define RANGE(num , end) ((((num) >= 0) and (num < end)) ? "true" : "false");
 
namespace mylib
{
	void task2()
	{
		float num;								// ������������ ����������
		const size_t rend = 10;					// ����� ���������
		std::cout << "������� �����: ";
		std::cin >> num;
		std::cout << "����� " << num << " ������ � �������� � 0, �� " << rend << " ? ";
		std::cout << RANGE(num, rend);
	}
}