#include <iostream>
#include <string>
#include <vector>

template<class T> //Шаблонный метод перемещения значений из одного вектора в другой
void move_vectors(std::vector <T>& lhs, std::vector <T>& rhs)
{
    //Используется std::move() для перевода значений из lvalue в rvalue
    //Во избежания излишнего копирования. 
    std::vector<T> tmp = std::move(lhs);
    lhs = std::move(rhs);
    rhs = std::move(tmp);

}

template<class T>//Метод выводит на консоль данные в векторе
void print_vec(const std::vector <T> vec)
{
    for (const auto& it : vec) {
        std::cout << it << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector <std::string> one = { "test_string1", "test_string2" };
    //std::vector <int> one = { 1, 2, 3, 4, 5}; //Тут была проверка на других типах данных
    std::cout << "Vector one = ";
    print_vec(one);
    std::vector <std::string> two;
    //std::vector <int> two; //Тут была проверка на других типах данных
    move_vectors(one, two);
    std::cout << "Vector two = ";
    print_vec(two);
}
