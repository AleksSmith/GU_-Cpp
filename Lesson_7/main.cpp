// Алексей Кузнецов <alek-kuzne@yandex.ru>
// Урок 7. Препроцессинг

#include<iostream>
using namespace std;
#define LINES 10
#define COLUMNS 5






// 1. Описать макрокоманду, проверяющую, входит ли переданное ей число в диапазон от нуля (включительно) до переданного ей второго аргумента (исключительно)

#define INTERVAL(X,Y) (((X)>=0)&&((X)<(Y)))?(1):(0)

// 2. Описать макрокоманду, получающую доступ к элементу двумерного массива (организованного динамически) посредством разыменования указателей

#define CONTENT(L,C) *(*(array+(L))+(C))

// 3.* Описать макрокоманду, возвращающую количество элементов локального массива, принимающую на вход ссылку на массив и его тип


void print_arr(int **arr, int lines, int columns){
    for (int i=0, n=0; i<lines; i++ ){
        for (int j=0; j<columns; j++)
            cout << arr[i][j] << " ";
            cout << endl;
        }
}

 int main(int argc, char const *argv[])
 {  
   
    // 1.
     int x,y;
     cout << "Введите число и границу интервала: ";
     cin >> x >> y;
     cout << x << ((INTERVAL(x,y))?(" "):(" не ")) << "входит в интервал [0," << y << ")" << endl;
  
    // 2.
    int **array = new int*[LINES]; // Динамически выделяем двухмерный массив
    for(int i=0; i<LINES; i++ ){
        array[i] = new int[COLUMNS];
    }
     
    for (int i=0, n=0; i<LINES; i++ ){ // Заполняем массив
        for (int j=0; j<COLUMNS; j++){
            array[i][j]= ++n;
        }
    }
    print_arr(array,LINES,COLUMNS);
    cout << "Элемент array[5][3] = "<< CONTENT(5,3) << endl;

    for (int i=0; i<LINES; i++){   // Освобождаем динамически выделенную память
        delete[] array[i];
    }
     return 0;
 }
 