#include <iostream>
#include <clocale>
#include <random>
#include <stdlib.h>
#include <chrono>

#define FIELDSIZE 3     // Размер поля 


//=========================================================
//                              СТРУКТУРЫ

enum XOstuff : char     // Заполнители игрового поля
{
    space = ' ',
    cross = 'X',
    zero = 'O',
    quest = '?'
};

enum XOdifficult 
{
    easy,
    hard
};


struct XOgame           // Основаная структура игры
{
    XOstuff** ppField = { nullptr };
    //XOprogress gameprogress = GameStart;
    size_t turn = 0;            // если 0 то ходит игрок
    XOstuff Human, Ai;
    XOdifficult gameDiff = {easy};
};

//=========================================================
//                              ФУНКЦИИ

// Очистка экрана
void clearScr()
{
    system("cls");
    //std::cout << "\x1B[2J\x1B[H";
}           

// Рандом с заданным диапазоном
int32_t getRandomNum(int32_t min, int32_t max)
{
    const static auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    static std::mt19937_64 generator(seed);
    std::uniform_int_distribution<int32_t> dis(min, max);
    return dis(generator);
}

// Функция отрисовки поля
void XOfieldOut(const XOgame & g)
{
    std::cout << "Игрок: " << g.Human << ", Компьютер: " << g.Ai << "\n";
    std::cout << "Сложность игры: ";
    (g.gameDiff == 0) ? std::cout << "простая\n" : std::cout << "сложная\n";
    std::cout << "  ";
    for (size_t y = 1; y <= FIELDSIZE; y++)
        std::cout << "" << y << "   ";
    std::cout << "\n";                          // Номера строк

    for (size_t y = 0; y < FIELDSIZE; y++)
    {
        std::cout << y + 1 << " ";              // номера столбцов
        for (size_t x = 0; x < FIELDSIZE; x++)
        {
            std::cout << g.ppField[y][x];
            if (x < FIELDSIZE - 1)
                std::cout << " | ";
        }
        std::cout << "\n";
    }
}

// Инициализация игры (выделение памяти, опрос игрока)
void GameInit(XOgame &g)
{
    
    std::string c_des;                                                // Переменная для выбора знака
    std::string c_dif;                                                // Сложность

    // В ходе тестирования выявилась при вводе символа вместо цифры программа уходит в бесконечный цикл
    // Реализую решение - считывается строка (char - не вариант)
   
    g.ppField = new(std::nothrow) XOstuff * [FIELDSIZE];        // Выделение памяти
    for (size_t x = 0; x < FIELDSIZE; x++)
        g.ppField[x] = new(std::nothrow) XOstuff[FIELDSIZE];

    for (size_t y = 0; y < FIELDSIZE; y++)                      // Заполнение поля пустыми символами
        for (size_t x = 0; x < FIELDSIZE; x++)
            g.ppField[y][x] = space;
    
//---------------------------------------------------------  
    // Выбор игрока
    std::cout << "Чем вы жедаете играть? Х или О (Х ходит первым)\n1 - крести\n2 - нолик\n3 - предоставить судьбу великому рандому\n";
    do {                                                        // Начало проверки введённого числа
        std::cin >> c_des;                                      // Ввеод символьной переменной
        if (c_des != "1" and c_des != "2" and c_des != "3")
            std::cout << "Некорректный ввод\nВведите заного ";
    } while (c_des != "1" and c_des != "2" and c_des != "3");   // Конец проверки введённого числа

    if (c_des == "1")                                           // Выбор 'X'
    {
        g.Human = cross;
        g.Ai = zero;
        g.turn = 0;
    }
    else if (c_des == "2")                                      // Выбор 'O'
    {
        g.Ai = cross;
        g.Human = zero;
        g.turn = 1;
    }
    else                                                        // Выбор великого рандома
    {
        if (getRandomNum(0, 3) >= 1)                            // Если 1, 2 игрок - 'X'
        {
            g.Human = cross;
            g.Ai = zero;
            g.turn = 0;
        }
        else                                                    // Если 1, 2 игрок - 'O'
        {
            g.Ai = cross;
            g.Human = zero;
            g.turn = 1;
        }
    }
    
//---------------------------------------------------------
    // Сложность
    std::cout << "Выберите уровень сложности игры\n1 - простая\n2 - кошмар\n";
    do {                                                        // Начало проверки введённого числа
        std::cin >> c_dif;
        if (c_dif == "1" and c_dif == "1")
            std::cout << "Некорректный ввод\nВведите заного ";
    } while (c_dif == "1" and c_dif == "2");                    // Конец проверки введённого числа
    if (c_dif == "1")
    {
        g.gameDiff = easy;
    }
    else
    {
        g.gameDiff = hard;
    }
}

// Деинициализвция игры (очистка выделенной памяти)
void GameDeInit(XOgame& g)
{
    for (size_t x = 0; x < FIELDSIZE; x++)
        delete[] g.ppField[x];
    delete[] g.ppField;
}

// Условия победы если выполняеться - возвращает 1
bool getWin(XOgame& g)
{
    //Проверка горизонталей
    for (size_t y = 0; y < FIELDSIZE; y++)
    {
        if (g.ppField[y][0] == g.ppField[y][1] and g.ppField[y][0] == g.ppField[y][2] and g.ppField[y][0]!= space)
            return 1;
    }

    //Проверка Вертикалей
    for (size_t x = 0; x < FIELDSIZE; x++)
    {
        if (g.ppField[0][x] == g.ppField[1][x] and g.ppField[0][x] == g.ppField[2][x] and g.ppField[0][x] != space)
            return 1;
    }

    //Проверка диагоналей
    if (g.ppField[1][1] == g.ppField[0][0] and g.ppField[1][1] == g.ppField[2][2] and g.ppField[1][1] != space)
        return 1;
    if (g.ppField[1][1] == g.ppField[2][0] and g.ppField[1][1] == g.ppField[0][2] and g.ppField[1][1] != space)
        return 1;

    return 0;
}

// Условие ничьи если выполняеться - возвращает 1
bool getNoWin(XOgame& g)        
{
    size_t i = 0;     //счетчик
    for (size_t y = 0; y < FIELDSIZE; y++)
    {
        for (size_t x = 0; x < FIELDSIZE; x++)
        {
            if (g.ppField[y][x] != space)
                i++;
        }
    }
    if (i == 9)     // Если всё поле занято возвращает 1
        return 1;

    return 0;
}

// Ход игрока
void Hturn(XOgame& g) 
{
    std::string c_x;
    std::string c_y;
    size_t i_x;
    size_t i_y;
    char shr = '0';                                         // Переменная для опроса пользователя
    std::cout << "Ход игрока \n ";
    


    do {                                                    // Начало провеки корректность ввода клетки

        do {                                                // Начало проверки на занятость клетки

            do {                                            // Начало проверки на коррекное введение строки
                std::cout << "номер строки = ";
                std::cin >> c_x;
                if (c_x != "1" and c_x != "2" and c_x != "3")
                {
                    std::cout << "Некорректный ввод\nВведите заного ";
                }
            } while (c_x != "1" and c_x != "2" and c_x != "3");                   // Коец проверки на коррекное введение строки
            // Просле проверки реализовал перевод из [0] символа из массива string в size_t для дальнейших расчетов
            i_x = static_cast <size_t>(c_x[0]) - 48;                              // Перевод 0 символа из string в int (48 - код символа '0')

            do {                                                                  // Начало проверки на коррекное введение столбца
                std::cout << "номер столбца = ";
                std::cin >> c_y;
                if (c_y != "1" and c_y != "2" and c_y != "3")
                {
                    std::cout << "Некорректный ввод\nВведите заного ";
                }
            } while (c_y != "1" and c_y != "2" and c_y != "3");                   // Конец проверки на коррекное введение столбца
            i_y = static_cast <size_t>(c_y[0]) - 48;

            if (g.ppField[i_y - 1][i_x - 1] != space)
            {
                clearScr();                                 // Рисование поля заного, если ввод не корректный
                XOfieldOut(g);
                std::cout << "Клетка занята\n";
            }
        } while (g.ppField[i_y - 1][i_x - 1] != space);     // Конец проверки на занятость клетки

        // Делее вопрос игроку, что клеткa верная 
        g.ppField[i_y - 1][i_x - 1] = quest;                // В ячейке с координатами введёнными выше рисуется символ '?' 

        clearScr();                                         // Вывод на экран поля с символом '?'                      
        XOfieldOut(g);

        std::cout << "Эта клетка?\n1 - Да\n2 - Нет\n";
        std::cin >> shr;

        g.ppField[i_y - 1][i_x - 1] = space;                // Если игрока не устраивает стирает символ '?' до следующего ввода новых координат

        clearScr();
        XOfieldOut(g);

    } while (shr == '2');                                   // Конец провеки корректность ввода клетки

    // Если игрока не устраивает, символ '?' заменяется ' ' и ввод осуществляется заного
    // Если игрока устраивает, символ '?' заменяется ' ', после этого в ячейку записывается симво игрока

    g.ppField[i_y - 1][i_x - 1] = g.Human;

    g.turn = g.turn ^ 1;                                   // Переход хода (изменение с 1 на 0 и наоборот)
}


// Ход компьютера
void Aturn(XOgame& g)       
{
    if (g.gameDiff == 0)                                // Если сложность = easy
    {
        size_t x;
        size_t y;
        do {
            y = (getRandomNum(0, 2));
            x = (getRandomNum(0, 2));
        } while (g.ppField[y][x] != space);

        g.ppField[y][x] = g.Ai;
    }
//---------------------------------------------------------
    else                                                // Если сложность  = hard
    {
        bool stop = 0;                                  // флаг остановки цикла

        if (g.ppField[1][1] == space)                   // Проверяем центр
        {
            g.ppField[1][1] = g.Ai;
            stop = 1;                                   // ход сделан
        }
//---------------------------------------------------------
        if (stop == 0)                                  // Если в предыдущей части не было сделано замены 
        {
            // Цикл проверки победного хода
           // В цикле производится проверка в каждой ячейке возможности победы компьютера
            for (size_t y = 0; y < FIELDSIZE; y++)
            {
                for (size_t x = 0; x < FIELDSIZE; x++)
                {
                    if (g.ppField[y][x] == space)           // Если ячейка пустая
                    {
                        g.ppField[y][x] = g.Ai;
                        if (getWin(g) == 1)                 // Если выполняется условие победы компьютера
                        {
                            stop = 1;                       // Если условие выполнено - цикл оставливается, ячейка уже заменена
                            break;
                        }
                        else                                // Если не выполняется условие - вовращается значение ячейки - space
                        {
                            g.ppField[y][x] = space;
                        }
                    }
                }
                if (stop == 1)
                    break;
            }
        }
//---------------------------------------------------------               
        if (stop == 0)                                  // Если в предыдущей части хот не был сделан
        {
            // Цикл противодействия игроку
           // В цикле производится проверка в каждой ячейке возможности победы игрока
            for (size_t y = 0; y < FIELDSIZE; y++)
            {
                for (size_t x = 0; x < FIELDSIZE; x++)
                {
                    if (g.ppField[y][x] == space)           // Если ячейка пустая
                    {
                        g.ppField[y][x] = g.Human;          // Подставляем символ игрока
                        if (getWin(g) == 1)                 // Если выполняется условие победы игрока 
                        {
                            g.ppField[y][x] = g.Ai;         // Заносим в ячейку символ компьютера
                            stop = 1;
                            break;                          // Стоп вложенный цикл
                        }
                        else                                // Если не выполняется условие - вовращается значение ячейки - space
                        {
                            g.ppField[y][x] = space;
                        }
                    }
                }
                if (stop == 1)
                    break;
            }
        }
//---------------------------------------------------------
        if (stop == 0)                                      // Если ничего из предыдущего не сработало - рандомный ход
        {
            size_t x;
            size_t y;
            do {
                y = (getRandomNum(0, 2));
                x = (getRandomNum(0, 2));
            } while (g.ppField[y][x] != space);

            g.ppField[y][x] = g.Ai;
        }
    }

    g.turn = g.turn ^ 1;                                // Переход хода (изменение с 1 на 0 и наоборот)
}


// Сама игра
void Game()
{
    XOgame(game);
    GameInit(game);               // Инициализация игры (выделение динамической памяти для массива и опрос игрока)
    clearScr();                   // Очиска экрана
    XOfieldOut(game);             // Рисование поля
    
    do {
        if (game.turn == 0)       //Ход игрока
        {
            Hturn(game);
            clearScr();
            XOfieldOut(game);
        }
        else                      // Ход коимпьютера
        {
            Aturn(game);
            clearScr();
            XOfieldOut(game);
        }
        
    } while(getWin(game) == 0 and getNoWin(game) == 0);         // Цикл выполняется пока не выполнилось условие победы или ничьи

    if (getWin(game) == 1)                                      // Если победа
    {
        if (game.turn == 1)                                     // Победил игрок
        {
            clearScr();
            XOfieldOut(game);
            std::cout << "\nПобедил игрок!\n";
        }
        else                                                    // Победил компьютер
        {
            clearScr();
            XOfieldOut(game);
            std::cout << "\nПобедил компьютер!\n";
        }
    }
    else                                                        // Если ничья
    {
        clearScr();
        XOfieldOut(game);
        std::cout << "\nПобедила дружба!\n";
    }


    GameDeInit(game);                                           // Де инициализация (cтирание выделенной памяти)

}

//=========================================================
//                              MAIN ФУНКЦИЯ

int main()
{
    setlocale(LC_ALL, "Russian");// Русский язык

    char cont;                   // Переменная для повторения

    do {

        clearScr();              // Очистка экрана
        Game();                  // Игра
        std::cout << "\nПовторить игру?\n1 - да\n2 - Нет\n";
        std::cin >> cont;

    } while (cont == '1');

}
