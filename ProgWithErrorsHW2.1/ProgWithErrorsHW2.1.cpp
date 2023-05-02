//Задание номер 2.
//Синтактическая ошибка - ошибка написанния операторов
//Семантическая ошибка - если в if (...) не использовать скобки, то легко ошибиться перенеся условие
//следующую строку. 
//Ошибка линковки - не добавил нужную библиотеку, например чтобы пользоваться функцией std::for_each 
//надо добавить библиотеку <algorithm> 

#include <iostream>
using namespace std;

struct point {
	double m_x;
	double m_y;
	point(double x, double y) {
		m_x = x;
		m_y = y; //Исправлено название переменной
	}
};//Нехватало точки с запятой

void print_point(const point& point_object) {
	std::cout << "x:" << point_object.m_x << ", y: "; //Нехватало точки с запятой
	std::cout << point_object.m_y << std::endl; // Добавил std::cout
}

int main()//main написано с большой буквы
{
	int i;
	for (i = 0; i < 5; i++) {//Лишняя точка с запятой
		point my_point(i, 2 * i);
		print_point(my_point);
	}
	return 0;
}

//void print_point(const point& point_object) { //Функция определена дважды 
//	std::cout << "x:" << point_object.m_x << ", y: "
//		<< point_object.m_y << std::endl;
//}