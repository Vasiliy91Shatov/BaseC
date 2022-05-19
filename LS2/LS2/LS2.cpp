
#include <iostream>

// Задание 1: Создать и инициализировать переменные
short int g_ia = 10'000;
unsigned int g_nb = 4'000'000'000;
long long g_llc = 9'000'000'000'000'000'000;
char g_ad[6] = "Hello"/*{'H','e','l','l','o',0}*/;
bool g_be = false;
float g_f = 3.141'592'653;
double g_g = 3.141'592'653'589'793'238'462;

// Задание 2: Создать перечисление (enum) с возможными вариантами символов для игры в крестики - нолики
enum CrossZero : char
{
    space = ' ',
    cross = 'X',
    zero = 'O'
};


int main()
{
    // Задание 3: Создать массив, способный содержать значения такого перечисления и инициализировать его.
    CrossZero acell[3][3] = 
    {   {space, cross, zero},
        {cross, space, zero},
        {cross, zero, space}};
    /*for (int i = 0; i < 3; i++)   // тестирование инициализации
        std::cout << acell[i][0] << " | " << acell[i][1] << " | " << acell[i][2] << std::endl;*/

}
