#include <iostream>
#include <vector>

template<class T> 
class MyVector 
{
public:
	
	MyVector();//Почему-то VS выдает предупреждение, что не найдено определение функции MyVector
	~MyVector();//Почему-то VS предупреждение, что не найдено определение функции ~MyVector

	void push_back(T value);//Метод добавлят новый элемент 
	T at(int index);//Метод возвращает значение из ячейке по индексу
	int size();//Метод возвращает кол-во элементов
	int capacity();//Метод возвращает кол-во свободных ячеек до момента расширения памяти

private:
	T* vec;//Вектор
	int index = 0;//Индекс 
	int sizeVec = 0;//Размер 
	int capacityVec = 1;//Свободная память
};

template<class T>
MyVector<T>::MyVector()//Конструктор
{
	vec = new T[capacityVec];
}

template<class T>
MyVector<T>::~MyVector()//Деструктор
{
	delete[] vec;
}

template<class T>
void MyVector<T>::push_back(T value)
{
	if (sizeVec >= capacityVec)//Проверка на отсутствие свободного места
	{	
		capacityVec *= 2;//Увеличиваем место в два раза
		T* newVec = new T [capacityVec];//Создаем технический массив
		for (int i = 0; i < sizeVec; i++) {//Перенос информации из старого в новый массив
			newVec[i] = vec[i];
		}
		newVec[sizeVec] = value;//Добавление нового элемента в конец
		sizeVec++;//Увеличение заполненых ячеек на 1
		delete[] vec;//Удаляем старый массив
		vec = newVec;//Меняем указатели 
	}
	else {//Если свободное место есть в наличии
		vec[sizeVec] = value;//Добавляем новый элеменет на первое свободное место в конце
		sizeVec++;//Увеличение заполненых ячеек на 1
	}
}
template<class T>
T MyVector<T>::at(int index)
{
	if (index < sizeVec || index > 0)//Если заданный индекс меньше размера массива, выдаем содержимое в ячейке
	{
		return vec[index];
	}
	else {//Если индекс не совпадает то выбрасываем ошибку
		throw std::runtime_error("The is no such index in the vector!!!");
	}

}

template<class T>
int MyVector<T>::size()
{
	return sizeVec;
}

template<class T>
int MyVector<T>::capacity()
{
	return capacityVec - sizeVec;
}


int main()
{
	try {
		MyVector <int> v;
		std::cout << "Capacity = " << v.capacity() << std::endl;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		std::cout << "Capacity = " << v.capacity() << std::endl;
		std::cout << "Size = " << v.size() << std::endl;
		std::cout << "Vector = {";
		for (int i = 0; i < v.size(); i++ ) {
			if (i == v.size() - 1) {
				std::cout << v.at(i) << "}";
			}
			else {
				std::cout << v.at(i) << ", ";
			}	
		}

	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	
}

