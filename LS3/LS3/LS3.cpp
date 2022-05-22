#include <iostream>
#include <clocale>

int main()
{
    setlocale(LC_ALL, "Russian");   // Русский язык

    // задание 1,4:
    std::cout << "Задание 1,4:" << std::endl;
    extern const int a;     // Считываем const переменные из другого .срр файла
    extern const int b;
    extern const int c;
    extern const int d;
    std::cout << "Решение через static_cast <float> ():   " << a * (b + (static_cast <float>(c) / d)) << std::endl;
    printf("Решение через float ():\t\t\t%2.3f\n\n", a * (b + (float(c) / d)));

    // задение 2:
    std::cout << "Задание 2:" << std::endl;
    int num = 19;   // Число для сравнения (разница = 2)
    (num <= 21) ? std::cout << "Число меньше, разница = " << 21 - num << std::endl :        // Если число меньше 21 - выводиться разница 
        std::cout << "Число больше, двойная разница = " << 2 * (num - 21) << std::endl;     // Если число меньше 21 - выводиться двойная разница        
    num += 5;       // num = 24 (разница = 3)
    (num <= 21) ? std::cout << "Число меньше, разница = " << 21 - num << std::endl :
        std::cout << "Число больше, двойная разница = " << 2 * (num - 21) << std::endl;

 }