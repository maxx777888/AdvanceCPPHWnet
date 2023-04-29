#include <iostream>
#include<string>
#include<vector>
#include <variant>
#include <ctime>

std::variant <int, std::string, std::vector<int>> get_variant() {
	srand(time(0));;
	int random_variable = static_cast<int>(std::rand() % 3);

	std::variant<int, std::string, std::vector<int>> result;
	switch (random_variable)
	{
	case 0:
		result = 5;
		break;
	case 1:
		result = "string";
		break;
	case 2:
		result = std::vector<int>{ 1, 2, 3, 4, 5 };
		break;
	default:
		break;
	}
	return result;
}



int main()
{
	std::variant<int, std::string, std::vector<int>> res = get_variant();
	bool is_int = std::holds_alternative<int>(res);//Получили int
	bool is_string = std::holds_alternative<std::string>(res);//Получили string
	bool is_vector= std::holds_alternative<std::vector<int>>(res);//Получили vector

	if (is_int) //Обрабатывается int
	{
		std::cout << (std::get<int>(res) * 2) << std::endl;
	}

	if (is_string) //Обрабатывается string
	{
		std::cout << std::get<std::string>(res) << std::endl;
	}

	if (is_vector) //Обрабатывается vector
	{
		auto v = std::get<std::vector<int>>(res);
		for (int n : v)
		{
			std::cout << n << " ";
		}
		std::cout << std::endl;
	}
}


