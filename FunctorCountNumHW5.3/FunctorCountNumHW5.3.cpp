#include <iostream>
#include <vector>


class FunctorHW
{
public:
    void operator ()(int val)//Перегрузка оператора двойные скобки - функтор
    {
        if (val % 3 == 0)//Проверка если число делется на 3
        {
            countDev3++;//Увеличиваем счетчик чисел, которые делятся на 3 на 1
            countSum += val;//Суммируем числа, которые делятся на 3
        }
    }
    int get_sum() //Метод возвращает сумму числе которые делятся на 3
    {
        return countSum;
    }
    int get_count() //Метод возвращает кол-во чисел которые делятся на 3
    {
        return countDev3;
    }

private:
    int countSum = 0;//Счетчик суммы чисел
    int countDev3 = 0;//Счетчик кол-ва чисел

};

int main()
{
    std::vector<int> vec { 4, 1, 3, 6, 25, 54 };//Создаем вектор
    FunctorHW f;//Создаем объект класса 

    for (auto el : vec) //Проходимся по вектору 
    {
        f(el);
    }
    //Вывод данных на консоль
    std::cout << "get_sum() = " << f.get_sum() << std::endl;
    std::cout << "get_count() = " << f.get_count() << std::endl;
}
