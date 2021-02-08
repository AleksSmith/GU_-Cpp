// Алексей Кузнецов <alek-kuzne@yandex.ru>
// Урок 2. Основные понятия. Переменные и типы данных, указатели, массивы. Вычислимость
/*
    1.  Создать и инициализировать переменные пройденных типов данных
    2.  Создать перечисление с возможными вариантами символов для игры в крестики-нолики
    3.  Создать массив, способный содержать значения такого перечисления и инициализировать его.
    4.  * Создать структуру данных «Поле для игры в крестики-нолики» и снабдить его всеми необходимыми свойствами
    5.  ** Создать объединение и структуру с битовыми флагами указывающими какого типа значение в данный момент содержится в объединении

*/

#include<iostream>
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
   // 1.   1.  Создать и инициализировать переменные пройденных типов данных
    char c = 'a';
    int i = 31;
    unsigned int uin = 7'259;
    long int lin = 854'775'807;
    unsigned long int ulin = 744'073'709'551'615;
    float fl = 12.5;
    double db = 3335.1235;

    // cout << "char          " << sizeof(char) << endl;
    // cout << "int           " << sizeof(int) << endl;
    // cout << "long int      " << sizeof(long int) << endl;
    // cout << "float         " << sizeof(float) << endl;
    // cout << "double        " << sizeof(double) << endl;

    cout << "char c=                 " << c << endl;
    cout << "int i=                  " << i << endl;
    cout << "unsigned int uin=       " << uin << endl;
    cout << "long int lin=           " << lin << endl;
    cout << "unsigned long int ulin= " << ulin << endl;
    cout << "float fl=               " << fl << endl;
    cout << "double db=              " << db << endl << endl;
    

    // 2.  Создать перечисление с возможными вариантами символов для игры в крестики-нолики
    
    enum symbol {empty, zero, cross};
    enum symbol sym1 = cross, sym2 = empty, sym3 = zero;

    cout << sym1 << sym2 << sym3 << endl << endl; 

    // 3.  Создать массив, способный содержать значения такого перечисления и инициализировать его.

    enum symbol field[9] = {empty, empty, zero, empty, cross, zero, cross, cross, zero};

    cout << field[4] << endl << endl;

    //  4.  * Создать структуру данных «Поле для игры в крестики-нолики» и снабдить его всеми необходимыми свойствами

    // |1 |2 |3 |
    // ---+--+---
    // |4 |5 |6 |
    // ---+--+---
    // |7 |8 |9 |
    
    //  5.  ** Создать объединение и структуру с битовыми флагами указывающими какого типа значение в данный момент содержится в объединении


    return 0;
}
