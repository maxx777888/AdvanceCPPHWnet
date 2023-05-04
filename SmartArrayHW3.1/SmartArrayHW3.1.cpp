#include <iostream>

class smart_array
{
public:
	smart_array(int);//Конструктор
	~smart_array();//Деструктор

	void add_element(int x);//Метод добавляем новый элемент в массив
	int get_element(int x);//Метод возвращает значение в ячейке массива по индексу

private:
	int* arr;//Динамический массив
	int index = 0;//Индекс массива для работы с методом get_element
	int size = 0;//Размер массива
};

smart_array::smart_array(int n)//Создаем конструкор
{
	this->size = n;
	this->arr = new int[size]();
}

smart_array::~smart_array()//Создаем деструктор
{
	delete[] arr;//Освобождаем память
}

void smart_array::add_element(int x)
{
	//Если индекс меньше размера массива добавляем переданное число в первую свободную ячейку
	//затем увеличиваем индекс на единицу
	if (index < size) 
	{
		arr[index] = x;
		index++;
	}
	else {//Если индекс не совпадает то выбрасываем ошибку
		throw std::runtime_error("The array is full, no more space to add!");
	}
	
}

int smart_array::get_element(int ind)
{
	if (ind < size || ind < 0)//Если заданный индекс меньше размера массива, выдаем содержимое в ячейке
	{
		return arr[ind];
	}
	else {//Если индекс не совпадает то выбрасываем ошибку
		throw std::runtime_error("The is no such index in the array!!!");
	}
	
}


int main()
{
	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		std::cout << arr.get_element(1) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
}

  