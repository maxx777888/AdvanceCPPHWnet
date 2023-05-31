#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class big_integer
{
public:
    big_integer() {//Пустой конструктор
        this->num_str = "0";
    }
    explicit big_integer(const std::string val) : num_str(val) {}//Конструктор
    /*this->num_str = val;*/

//Перегрузка оператора умножения на число
    big_integer operator*(int rhs) {

        std::string d = this->num_str;//Число записанное в строке самого объекта
        std::vector<int> this_vec;//Вспомогательный вектор нужен для умножения всех цифр в числе
        std::for_each(d.begin(), d.end(), [&this_vec, rhs](char c) mutable { if (std::isdigit(c)) {

            int num = static_cast<int>(c - '0') * rhs;//Берем каждую цифру и умножаем на наше число
            this_vec.push_back(num);//Складываем в вспомогательный вектор

        }});

        std::string zero;//Строка для добавления нужного кол-ва нулей
        std::string h_str;//Вспомогательная строка
        std::vector<std::string> res_str;//Вектор для хранения всех элементов числа уже с нужным кол-вом нулей
        for (int i = this_vec.size() - 1; i >= 0; i--)
        {
            h_str = std::to_string(this_vec[i]);//Переводим данный из предыдущего вектора в строку
            if (i != this_vec.size() - 1) {//Добавляем нули взависимости от позиции в векторе
                zero += std::to_string(0);
                h_str += zero;
            }
            res_str.push_back(h_str);//Вставляем полученные строки в вектор
        }
        big_integer mul_res;//Вспомогательный объект нашего класса для вывода результата
        for (int i = res_str.size() - 1; i >= 0; i--) {
            //auto h_num = std::move(big_integer(res_str[i]));//Так дольше, хотя по идеи должно быть быстрее
            auto h_num = big_integer(res_str[i]);//Так работает быстрее
            mul_res = h_num + mul_res;
        }
        return mul_res;//Возвращаем результат как объект нашего класса
    }
    //Перегрузка оператора сложения двух объектов класса
    big_integer operator+(big_integer rhs) {

        std::string d = this->num_str;//Строка для удобства 
        std::vector<int> this_vec;//Вектор для дробления каждой цифры в левом числе
        std::for_each(d.begin(), d.end(), [&this_vec](char c) mutable { if (std::isdigit(c)) {

            int num = static_cast<int>(c - '0');//Переводим строку в тип данных int
            this_vec.push_back(num);//Складываем полученную цифру в левый вектор

        }});

        std::string d1 = rhs.num_str;//Строка для удобства 
        std::vector<int> rhs_vec;//Вектор для дробления каждой цифры в правом числе
        std::for_each(d1.begin(), d1.end(), [&rhs_vec](char c) mutable { if (std::isdigit(c)) {

            int num = static_cast<int>(c - '0');//Переводим строку в тип данных int
            rhs_vec.push_back(num);//Складываем полученную цифру в правый вектор

        }});


        bool b = false;//Булевая переменная для хранения остатка от сложения
        std::vector<int> res;//Вектор для хранения сумм полученыйх от сложения цифр между собой
        if (this_vec.size() > rhs_vec.size())//Проверка какое число содержит больше цифр
        {//Если левое число содержит больше членов
            int j = rhs_vec.size() - 1;//Размер правого вектора
            for (int i = this_vec.size() - 1; i >= 0; i--)//Запускаем реверсивный проход по левому вектору
            {
                int l, r, sum; //Вспомогательные переменные левая, правая цифры и сумма
                if (j < 0) {//Проверка если правый вектор уже пустой
                    l = this_vec[i];//Приваемаем цифру левому числу
                    r = 0;//Правая цифра равна нулю
                }
                else {
                    l = this_vec[i];//Левая цифра
                    r = rhs_vec[j];//Правая цифра
                }

                if (b) {//Если есть остаток от суммы двух цифр
                    sum = 1;//Инициализация переменной сумма уже с учтенным остатком
                }
                else {
                    sum = 0;//Инициализируем переменную сумма
                }
                if ((l + r) < 10) {//Проверка если сумма двух цифр меньше 10
                    b = false;//Нет остатка
                    sum += (l + r);//Складываем результат
                    res.push_back(sum);//Вставляем результат в вектор
                }
                else {
                    b = true;//Сохраняем остаток на будещее
                    sum += (l + r);//Складываем результат
                    res.push_back(sum - 10);//Вставляем результат в вектор за вычетом 10
                }
                j--;//Уменьшаем переменную для отслеживания кол-ва элеметов в правом векторе
            }

        }
        else {//Если в правом числе больше элеметов или числа равны

            int j = this_vec.size() - 1;//Размер левого вектора
            for (int i = rhs_vec.size() - 1; i >= 0; i--) //Запускаем реверсивный проход по правому вектору
            {
                int l, r, sum;//Вспомогательные переменные левая, правая цифры и сумма
                if (j < 0) {//Проверка если левый вектор уже пустой
                    r = rhs_vec[i];//Приваемаем цифру правому числу
                    l = 0;//Левая цифра равна нулю
                }
                else {
                    l = this_vec[j];//Левая цифра
                    r = rhs_vec[i];//Правая цифра
                }

                if (b) {//Если есть остаток от суммы двух цифр
                    sum = 1;//Инициализация переменной сумма уже с учтенным остатком
                }
                else {
                    sum = 0;//Инициализируем переменную сумма
                }
                if ((l + r) < 10) {//Проверка если сумма двух цифр меньше 10
                    b = false;//Нет остатка
                    sum += (l + r);//Складываем результат
                    res.push_back(sum);//Вставляем результат в вектор
                }
                else {
                    b = true;//Сохраняем остаток на будещее
                    sum += (l + r);//Складываем результат
                    res.push_back(sum - 10);//Вставляем результат в вектор за вычетом 10
                }
                j--;//Уменьшаем переменную для отслеживания кол-ва элеметов в левом векторе
            }

        }
        std::string str;//Вспомогательная строка
        for (int i = res.size() - 1; i >= 0; i--) //Проходим реверсивным проходом по вектору результатов
        {
            str += std::to_string(res[i]);//Складываем все элементы вектора в одно число
        }

        return big_integer(str);//Возвращаем результат в видет объекта нашего класса
    }
    //Перегруженный оператор вывода на консоль объекта нашего класса
    friend std::ostream& operator << (std::ostream& lhs, const big_integer& rhs)
    {
        return lhs << rhs.num_str;
    }
    ///////////////////////////////////////
    big_integer(const big_integer& other) // конструктор копирования 
    {
        num_str = other.num_str;
    }

    big_integer(big_integer&& other) noexcept // конструктор перемещения
    {
        num_str = other.num_str;
        other.num_str = "0";

    }

    big_integer& operator=(const big_integer& other) // оператор копирующего присваивания
    {
        if (this == &other) {
            return *this;
        }
        return *this = big_integer(other);
    }
    big_integer& operator=(big_integer&& other) noexcept // оператор перемещающего присваивания
    {
        if (this == &other) {
            return *this;
        }
        num_str = other.num_str;
        other.num_str = "0";
        return *this;
    }

private:
    std::string num_str;

};

int main()
{
    setlocale(LC_ALL, "Russian");

    auto number1 = big_integer("114575");
    auto number2 = big_integer("78524");

    auto result = number1 + number2;
    std::cout << result << std::endl; // 193099

    std::cout << "Multiplying a class object by a number " << std::endl;
    int mul_num = 9;
    auto number3 = big_integer("987654321");
    auto res1 = number3 * mul_num;
    std::cout <<number3 << " * " << mul_num << " = " << res1 << std::endl; // 8888888889

}
