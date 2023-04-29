#include <iostream>
#include <vector>

int main()
{
    //Необходимые настройки консоли, для правильной работы с русским языком.
    setlocale(LC_ALL, "Russian");

    // Создаём вектор, содержащий целые числа
    std::vector<int> v = { 4, 7, 9, 14, 12 };

    // Выводим начальные данные на экран
    std::cout << "Входные данные: ";
    for (int n : v) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
  
    // Выводим конечные данные на экран
    auto func = [v]() {
        std::cout << "Выходные данные: ";
        for (int n : v) {
            if (n % 2 == 0)
                std::cout << n << " ";
            else
                std::cout << (n * 3) << " ";
        }
    };
    func();
    
    

    
}


