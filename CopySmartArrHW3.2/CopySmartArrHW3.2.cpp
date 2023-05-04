#include <iostream>

class smart_array
{
public:
	smart_array(int);//Конструктор
	~smart_array();//Деструктор

	void add_element(int x);//Метод добавляем новый элемент в массив
	int get_element(int x);//Метод возвращает значение в ячейке массива по индексу
	smart_array &operator=(smart_array& rhs);//Метод перегрузки оператора присваивания

private:
	int* arr_obj;//Динамический массив
	int index = 0;//Индекс массива для работы с методом get_element
	int size = 0;//Размер массива
};

smart_array::smart_array(int s)//Создаем конструкор
{
	this->size = s;
	this->arr_obj = new int[size]();
}

smart_array::~smart_array()//Создаем деструктор
{
	if (arr_obj != nullptr) {
		delete[] arr_obj;//Освобождаем память
	}
	
}

void smart_array::add_element(int x)
{
	//Если индекс меньше размера массива добавляем переданное число в первую свободную ячейку
	//затем увеличиваем индекс на единицу
	if (index < size)
	{
		arr_obj[index] = x;
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
		return arr_obj[ind];
	}
	else {//Если индекс не совпадает то выбрасываем ошибку
		throw std::runtime_error("The is no such index in the array!!!");
	}

}

smart_array& smart_array::operator=(smart_array& rhs)
{
	if (this->arr_obj != nullptr)//Делаем проверку на инициализацию
	{
		delete[] this->arr_obj;//Очищаем памать от старого массива
	}

	this->size = rhs.size;//Присваиваем новое значение размеру массива
	this->arr_obj = new int[size];//Создаем новый массив

	for (int i = 0; i < size; i++)//Через цикл For передаем значения созданному массиву
	{
		this->arr_obj[i] = rhs.arr_obj[i];
	}
	return *this;//Возвращаем новый массив
}





int main()
{
	try {

		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);

		smart_array new_array(2);
		new_array.add_element(44);
		new_array.add_element(34);

		arr = new_array;

	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
}

