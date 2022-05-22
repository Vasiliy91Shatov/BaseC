#include <iostream>
#include <clocale>

int main()
{
    setlocale(LC_ALL, "Russian");   // Руский язык

    // задание 1,4:
    extern const int a;     // Считываем const переменные из другова .срр файла
    extern const int b;
    extern const int c;
    extern const int d;
    std::cout << "Решение через static_cast <float> ():   " << a * (b + (static_cast <float>(c) / d)) << std::endl;
    printf("Решение через float ():\t\t\t%2.3f\n", a * (b + (float(c) / d)));
 }