// Алексей Кузнецов <alek-kuzne@yandex.ru>
// Урок 8. Итоги. Игра в крестики нолики
#include<cstdlib>
#include<iostream>
#include<ctime>
#include<string>

#define SIZE 3

using std::cout;
using std::cin;
using std::endl;
using std::system;
using std::string;
 
// Поле для игры
enum PLAYER {HUMAN='X', AI='O', EMPTY='_'};

typedef struct{
    int szY;
    int szX;
    PLAYER** map;
    int towin; 
} Field;

// Функция установки значения ячейки поля
void setval(PLAYER** array, const int row, const int col, PLAYER value){
    array[row][col] = value;
}

// Функция взятия значения ячейки поля
char getval(PLAYER** array, const int row, const int col){
    return array[row][col];
}

// Функция проверки пустой ячейки
int isempty(Field &field, int x, int y){
    return (field.map[y][x] == EMPTY);
}

// Функция проверки правильности координат поля
int isvalid(Field &field, int x, int y){
    return (((x >= 0)&&(x < field.szX)) && ((y >= 0)&&(y < field.szY)));
}

// Функция вывода игрового поля
void print(Field &field){
    system("clear");
    cout << "----------" << endl;
    for(int y = 0; y < field.szY; y++){
        cout << "|";
        for (int x = 0; x < field.szX; x++){
            cout << getval(field.map, y, x) << "|";
        } 
        cout << endl;              
    }
}

// Функция начальной инициализации игрового поля
void init(Field &field){
    field.towin = SIZE;
    field.szY = SIZE;
    field.szX = SIZE;
    field.map = new PLAYER* [field.szY];
    for (int y = 0; y < field.szY; y++){
        field.map[y] = new PLAYER[field.szX];
        for (int x = 0; x < field.szX; x++){
            setval(field.map, y,x, EMPTY);
        }
    }
}

//  Функция хода игрока
void human(Field &field){
    int x,y;
    do{
       cout << "Введите координаты хода X и Y (от 1 до " << field.szY << ") через пробел >> ";
        cin >> x >> y;
        if(cin.fail()){
            cout << "Координаты должны быть числом!" << endl;
            x = y = 0;
            cin.clear();
            cin.ignore(32767,'\n');
        }
       x--; y--;
    } while (!isvalid(field, x, y)||!isempty(field, x, y));
    setval(field.map, y, x, HUMAN);   
}

// Функция хода компьютера
void ai(Field &field){
    int x,y;
    srand(time(0));
    do{
        x =  rand() % SIZE;
        y =  rand() % SIZE;
    } while (!isempty(field, x, y));
    setval(field.map, y, x, AI);    
}

// Функция проверки линии
int linechk(Field &field, int y, int x, int vx, int vy, int len, PLAYER c){
    const int endx = x +(len-1)*vx;
    const int endy = y +(len-1)*vy;
    if(!isvalid(field, endx, endy)) return 0;
    for (int i = 0; i < len; i++){
        if(getval(field.map, (y + i * vy), (x + i * vx)) != c) return 0;
    }
    return 1;
}

// Функция проверки победы делающего ход
int winchk(Field &field, PLAYER c){
    for (int y = 0; y < field.szY; y++){
        for (int x = 0; x < field.szX; x++){
            if(linechk(field, y, x, 1, 0, field.towin, c)) return 1;
            if(linechk(field, y, x, 1, 1, field.towin, c)) return 1;
            if(linechk(field, y, x, 0, 1, field.towin, c)) return 1;
            if(linechk(field, y, x, 1, -1, field.towin, c)) return 1;
        }
        
    }
    return 0;
}

// Проверка на ничью
int isdraw(Field &field){
    for (int y = 0; y < field.szY; y++){
        for (int x = 0; x < field.szX; x++){
            if(isempty(field, x,y))
                return 0;
        }
    }
    return 1;    
}

// Функция игровой проверки
int gamechk(Field &field, PLAYER dot, const string &WinString){
    if(winchk(field, dot)){
        cout << WinString << endl;
        return 1;
    }
    if(isdraw(field)){
        cout << "Ничья!" << endl;
        return 1;
    }
    return 0;
}

// Функция главного игрового цикла
void tictactoe(){
    Field field;
    while(true){
        init(field);
        print(field);
        while (true){
            human(field);
            print(field);
            if (gamechk(field, HUMAN, "Человек выиграл!")) break;
            ai(field);
            print(field);
            if (gamechk(field, AI, "Компьютер выиграл!")) break;
        }
        string answer;
        cout << "Играем снова? (y or n)";
        cin >> answer;
        if (answer != "y") break;
    }
}


//========================================================================================================================
int main(int argc, char const *argv[]){
   tictactoe();
    return 0;
}

