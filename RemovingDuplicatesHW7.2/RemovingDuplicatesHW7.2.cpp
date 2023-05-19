#include <iostream>
#include <vector>
#include <set>
#include <algorithm>


int main()
{
    std::cout << "[IN]: " << std::endl;
    int numIn = 0;//Число кол-во элементов
    std::cout << "Enter the number of values" << std::endl;
    std::cin >> numIn;
    std::set<int> setConteiner;//Контейнер для хранения уникальных элементов
    std::vector<int> v;//Контейнер для вывода на консоль элементов в нужном порядке
    //Цикл поступления чисел из потока и записи их в контейнер с уникальными элементами
    for (int i = 0; i < numIn; i++) 
    {
        std::cout << "Enter a number\n";
        if (numIn - i == 1) {
            std::cout << "Left to enter the last number" << std::endl;
        }
        else {
            std::cout << "Left to enter " << (numIn - i) << " numbers" << std::endl;
        }
        
        int num;
        std::cin >> num;
        setConteiner.insert(num);
        
    }
    //Запись в контейнер для сортировки
    for (const auto& el : setConteiner) 
    { 
        v.push_back(el);
    }
    //Сортируем контейнер по убыванию значений элементов
    std::sort(v.begin(), v.end(),
        [](const auto& el1, const auto& el2)
        {
            return el1 > el2;
        });
    //Выводим на консоль данные отсортированного контейнера
    std::cout << "[OUT]: " << std::endl;
    for (const auto& el : v) {
        std::cout << el << std::endl;
    }
    std::cout << std::endl;
}
