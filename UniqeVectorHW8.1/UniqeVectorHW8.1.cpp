#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

//Метод убирает дубликаты с помощью контейнера unordered_set
std::vector<int> remove_duplicates_using_set(std::vector<int>& v)
{
    std::unordered_set<int> s;//Создаю контейнер класса unordered_set
    for(const auto & el : v)//Переношу значения из вектора в контейнер, тем самым убирая дубликаты
    {
        s.insert(el); 
    }
    v.clear();//Очищаю вектор от старых значений
    for (const auto& el : s)//Переношу значения в вектор без дубликатов
    {
        v.push_back(el);
    }

    return v;
}
//Метод убирает дубликаты с помощью сортировки вектора
std::vector<int> remove_duplicates_using_std_unique(std::vector<int>& v)
{
    //Сортируем контейнер
    std::sort(v.begin(), v.end(),
        [](const auto& el1, const auto& el2)
        {
            return el1 < el2;
        });
    //Убераем подряд идущие дубликаты
    auto it = std::unique(v.begin(), v.end());
    v.erase(it, v.end());

    return v;
}

//Метод выводит элементы вектора на консоль
void print_vec(const std::vector<int> v) 
{
    std::cout << "{";
    
    int i = 0;
    for (const auto& el : v)
    {
        if (i == (v.size() - 1))
        {
            std::cout << el << "}";
        }
        else {
            std::cout << el << ", ";
        }
        i++;
    }
}

int main()
{
    //First method to remove duplicates
    std::vector<int> vec1 = { 1, 1, 2, 5, 6, 1, 2, 4 };
    std::cout << "The Old Vector = ";
    print_vec(vec1);
    std::cout << std::endl;
    remove_duplicates_using_set(vec1);
    std::cout << "The New Vector after first method = ";
    print_vec(vec1);
    std::cout << std::endl;
    std::cout << "====================================================" << std::endl;
    //Second method to remove duplicates
    std::vector<int> vec2 = { 1, 1, 2, 5, 6, 1, 2, 4 };
    std::cout << "The Old Vector = ";
    print_vec(vec2);
    std::cout << std::endl;
    remove_duplicates_using_std_unique(vec2);
    std::cout << "The New Vector after Second method = ";
    print_vec(vec2);
    std::cout << std::endl;
}
