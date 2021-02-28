// Алексей Кузнецов <alek-kuzne@yandex.ru>
// Урок 6. Управление памятью
#include<iostream>
#include<fstream>

using namespace std;

// 1. Написать программу, которая создаст два текстовых файла, примерно по 50-100 символов в каждом
// (особого значения не имеет);

// 2. Написать функцию, «склеивающую» эти файлы, предварительно буферизуя их содержимое в динамически
// выделенный сегмент памяти нужного размера.

void copy_second_to_first (string& name1, string& name2){     // Функция добавления данных из второго файла в конец первого
    ofstream out (name1,ios_base::app);                         // Открываем поток для записи в файл name1
    if (!out){
        cout << "Невозможно открыть для записи файл :" << name1;
        return;
    } 
    ifstream in (name2,ios_base::in);                           // Открываем поток для чтения из файла name2
    if (!in){
        cout << "Невозможно открыть для чтения файл :" << name2;
        return;
    } 
    char *buf = new char[50];                                   // Динамически выделяем память под буфер элементов char размером 50 байт  
    if(!buf){
        cout << "Ошибка выделения памяти";
        return;
    }
    else{
        in >> buf;          // Читаем данные из name2 в buf
        out << buf;         // Записываем данные из buf в name1
        delete[] buf;       // Явно освобождаем динамически выделенную память
    }
}   

// 3. * Написать программу, которая проверяет присутствует ли указанное пользователем при запуске
// программы слово в указанном пользователем файле (для простоты работаем только с латиницей).


int main(int argc, char const *argv[])
{
  
//   1.
    string name1 = "first.txt";
    ofstream first(name1);
    if(!first){
        cerr << "Ошибка открытия файла :" << name1 << endl ; 
    }
        else {
            for (char ch = 'A'; ch <= 'Z'; ch++){
                first << ch;
            }
        }
     first.close(); //Явное закрытие потока
     first.clear();

    string name2 = "second.txt";
    ofstream second(name2);
    if(!second){
        cerr << "Ошибка открытия файла :" << name2 << endl ; 
    }
        else {
            for (char ch = 'a'; ch <= 'z'; ch++){
                second << ch;
            }
        }
     second.close(); //Явное закрытие потока
     second.clear();
        

//  2.
    copy_second_to_first(name1, name2);
    return 0;
}
