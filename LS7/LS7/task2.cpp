#include <iostream>

// �����-������� ������������ ������ �� ����� num � ������� � 0, �� end
#define RANGE(num , end) ((((num) >= 0) and (num < end)) ? "true" : "false");
 
namespace mylib
{
	void task2()
	{
		float num2;								// ������������ ����������
		const size_t rend = 10;					// ����� ���������
		std::cout << "������� �����: ";
		std::cin >> num2;
		std::cout << "����� " << num2 << " ������ � �������� � 0, �� " << rend << " ? ";
		std::cout << RANGE(num2, rend);
	}
}