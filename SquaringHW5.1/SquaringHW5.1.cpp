#include <iostream>
#include <vector>


template <class T> 
T square(T a) //Шаблонный метод, который возводит число в квадрат
{
    return a * a;
}

template <class T>//Шаблонный метод, который возводит числа вектора в квадрат
std::vector <T> square (std::vector <T> vec)
{
    for (auto &el : vec)
    {
        el *= el;
    }
    return vec;
}



int main()
{
    int rut4 = square(4);//Получаем квадрат числа через метод
    std::cout << rut4 << std::endl;//Вывод на консоль

    std::vector<int> v{ -1, 4, 8 };//Изначальные данные вектора
    v = square(v);//Получаем квадрат чисел в векторе
    //Выводим данные измененных данных на консоль
    for (auto el : v) {
        std::cout << el << " ";
    }
    std::cout << std::endl;

}

