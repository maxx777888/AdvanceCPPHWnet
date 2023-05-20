#include <iostream>

template <class T> 
class table 
{
public:

    table(const int a, const int b) //Конструктор класса
    {
        ROW = a;//Просваиваем массиву кол-во строк
        COL = b;//Просваиваем массиву кол-во столбцов
        arr = new T*[ROW];//Создаем массив строк

        for (int i = 0; i < ROW; i++) {//Создаем массво столбцов
            arr[i] = new T[COL]();
        }
    }
    T* operator[](int i){//Перегрузка оператора квадратные скобки
        return arr[i];
    }
    template <class T>
    const T* operator[](int i) {//Перегрузка оператора квадратные скобки с помощью const
        return arr[i];
    }

    int Size() const{//Метод возвращает размер таблицы
        return ROW * COL;
    }

    ~table() {//Деструктор класса удаляет таблицу из динамической памяти
        for (int i = 0; i < ROW; i++) {
            delete [] arr[i];
        }
        delete[] arr;
    }
private:
    T** arr = nullptr;
    int ROW = 0;
    int COL = 0;

};

int main()
{
    auto test = table<int>(2, 3);//Создаем таблицу
    test[0][0] = 4;//Присваиваем значение первой ячейки
    std::cout << test[0][0];//Выводим данные из первой ячейки на консоль
    std::cout << std::endl;
    std::cout << test.Size() << std::endl;//Выводим размер таблицы на консоль
}
