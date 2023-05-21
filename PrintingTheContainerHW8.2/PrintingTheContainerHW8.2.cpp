#include <iostream>
#include <set>
#include <vector>
#include <list>
#include <string>

template <class T>
void print_container(const T c)
{
    std::cout << "{ ";

    int i = 0;
    for (const auto& el : c)
    {
        if (i == (c.size() - 1))
        {
            std::cout << el << " }";
        }
        else {
            std::cout << el << ", ";
        }
        i++;
    }
    std::cout << std::endl;
}

int main()
{
    std::set<std::string> test_set = { "one", "two", "three", "four" };
    std::cout << "Set = ";
    print_container(test_set);

    std::list<std::string> test_list = { "one", "two", "three", "four" };
    std::cout << "List = ";
    print_container(test_list); 

    std::vector<std::string> test_vector = { "one", "two", "three", "four" };
    std::cout << "Vector = ";
    print_container(test_vector); 
}
