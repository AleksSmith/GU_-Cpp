// Алексей Кузнецов <alek-kuzne@yandex.ru>


#include <iostream>

using std::cout;

    void print_arry(int count, int *arr){
        cout << "[";
        for(int i = 0; i < count; i++){
            cout << arr[i] << ((i < count-1) ? (", ") : (""));
        }
        cout <<  "]\n";
    };

// 1. Задать целочисленный массив, состоящий из элементов 0 и 1. Например: [ 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 ]. Написать функцию,
//     заменяющую в принятом массиве 0 на 1, 1 на 0;

    void non_arg(int count, int *arr){
        for(int i = 0; i < count; i++){
            (arr[i] == 0) ? (arr[i] = 1) : (arr[i] = 0);
        }
    };

// 2. Задать пустой целочисленный массив размером 8. Написать функцию, которая с помощью цикла заполнит его значениями 1 4 7 10 13 16 19 22;

    void complet(int count, int *arr){
        for(int i = 0, n = 1; i < count; i++, n+=3){
            arr[i]=n;
        }
    };

// 3.* Написать метод, в который передается не пустой одномерный целочисленный массив, метод должен вернуть истину если в массиве есть место,
//     в котором сумма левой и правой части массива равны. Примеры: checkBalance([1, 1, 1, || 2, 1]) → true, checkBalance ([2, 1, 1, 2, 1]) → false,
//     checkBalance ([10, || 1, 2, 3, 4]) → true. Абстрактная граница показана символами ||, эти символы в массив не входят.
    int checkBalance(int count, int *arr){
        int rsum = 0;
        int lsum = arr[0];
        for (int i = 1; i < count; i++){
            rsum = rsum + arr[i]; 
        }
        for(int i = 1; i < count; i++){
            if(lsum == rsum)
                return true;
            else{
                lsum += arr[i];
                rsum -= arr[i];
                }
            }
            return false;
    };
// 4.* Написать функцию, которой на вход подаётся одномерный массив и число n (может быть положительным, или отрицательным), при этом метод должен
//     циклически сместить все элементы массива на n позиций. 
    void shift(int lenght, int *arr, int sh){
        int tmp;
        if(sh < 0){
            sh = -sh;
            for (int i = 0; i < sh; i++){
                tmp = arr[0];
                for (int j = 0; j < lenght; j++){
                    arr[j]=arr[j+1];
                }
                arr[lenght-1]=tmp;
            }
        }
        else{
            for (int i = 0; i < sh; i++){
                tmp = arr[lenght-1];
                for (int j = lenght-1; j > 0; j--){
                    arr[j]=arr[j-1];
                }
                arr[0]=tmp;
            }
        }
    }
// 5.** Написать функцию из первого задания так, чтобы она работала с аргументом переменной длины.

// 6.** Написать все функции в отдельных файлах в одном пространстве имён, вызвать их на исполнение в основном файле программы используя указатели на функции.



int main(int argc, char const *argv[])
{
//      1. ...

    int length = 10; //  
    int array[] = {1, 1, 0, 0, 1, 0, 1, 1, 0, 0};
    print_arry(length,array);
    non_arg(length,array);
    print_arry(length,array);

//      2. ...
    
    length = 8;
    int array2[length]={0};
    print_arry(length,array2);
    complet(length,array2);
    print_arry(length,array2);

//      3.* ...
    
    length = 5;
    int array3[]={1,2,3,4,10};
    print_arry(length,array3);
    cout << (checkBalance(length,array3) ? ("") : ("no ") ) << "balance in array\n";

//      4.* ... 
    length = 10;
    int array4[] = {0,1,2,3,4,5,6,7,8,9};
    print_arry(length,array4);
    shift(length,array4,5);
    print_arry(length,array4);
//      5.** ...

//      6.** ...
    return 0;
}
