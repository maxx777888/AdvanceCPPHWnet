#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <map>





int main()
{
    std::string str = "Hello world!!";//Изначальный текст для поиска

    std::multiset<char> multiM;//Контейнер для перевода текста в отдельные символы
    std::map<char, int> m;//Контейнер для удаления повторяющихся символов
    std::vector<std::pair<int, char>> v;//Контейнер для вывода на консоль в нужном порядке

    //Переводим текст в символы и записываем в контейнер
    for (auto u : str) {
        multiM.insert(u);
    }   
    //Записываем символы в словарь с кол-вом появления символа в тексте 
    for (const auto& el : multiM) {
        m[el] = multiM.count(el);
    }
    //Переписываем символы в контейнер для последующей сортировки по убыванию
    for (const auto& el : m) {
        int x = el.second;
        char y = el.first;
        v.push_back({ x, y });
    }
    //Сортируем контейнер по убыванию частоты появления символов в тексте
    std::sort(v.begin(), v.end(),
        [](const auto& el1, const auto& el2)
        {
            return el1.first > el2.first;
        });
    std::cout << "[IN]: " << str << std::endl;
    //Выводим на консоль данные отсортированного контейнера
    std::cout << "[OUT]: "<< std::endl;
    for (const auto& el : v) {
        std::cout << el.second << ": " << el.first << std::endl;
    }
    
    std::cout << std::endl;
}
