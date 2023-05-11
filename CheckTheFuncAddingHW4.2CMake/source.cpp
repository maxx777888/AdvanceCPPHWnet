#include <iostream>

#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>





struct ListNode
{
public:
    ListNode(int value, ListNode* prev = nullptr, ListNode* next = nullptr)
        : value(value), prev(prev), next(next)
    {
        if (prev != nullptr) prev->next = this;
        if (next != nullptr) next->prev = this;
    }

public:
    int value;
    ListNode* prev;
    ListNode* next;
};


class List
{
public:
    List()
        : m_head(new ListNode(static_cast<int>(0))), m_size(0),
        m_tail(new ListNode(0, m_head))
    {
    }

    virtual ~List()
    {
        Clear();
        delete m_head;
        delete m_tail;
    }

    bool Empty() { return m_size == 0; }

    unsigned long Size() { return m_size; }

    void PushFront(int value)
    {
        new ListNode(value, m_head, m_head->next);
        ++m_size;
    }

    void PushBack(int value)
    {
        new ListNode(value, m_tail->prev, m_tail);
        ++m_size;
    }

    int PopFront()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_head->next->next);
        int ret = node->value;
        delete node;
        return ret;
    }

    int PopBack()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_tail);
        int ret = node->value;
        delete node;
        return ret;
    }

    void Clear()
    {
        auto current = m_head->next;
        while (current != m_tail)
        {
            current = current->next;
            delete extractPrev(current);
        }
    }

private:
    ListNode* extractPrev(ListNode* node)
    {
        auto target = node->prev;
        target->prev->next = target->next;
        target->next->prev = target->prev;
        --m_size;
        return target;
    }

private:
    ListNode* m_head;
    ListNode* m_tail;
    unsigned long m_size;
};


TEST_CASE("List.Method checking")
{
    List my_list;

    SECTION("Pure PushBack check") {
        REQUIRE(my_list.Empty() == 1);//Проверка что List пустой

        my_list.PushBack(66);//Добавляю один элемент в конец
        my_list.PushBack(77);//Добавляю второй элемент в конец
        my_list.PushBack(88);//Добавляю еще один элемент в конец
        //Порядок в списке на данный момент: 66 77 88
        //Проверка, что после удаления последнего элемента останется второй элемент
        CHECK(my_list.PopBack() == 88);
        CHECK(my_list.Size() == 2);//Проверка, что после удаления размер List равен 2
        //Проверка, что после удаления второго элемента останется первый элемент
        CHECK(my_list.PopBack() == 77);
        CHECK(my_list.Size() == 1);//Проверка, что после удаления размер List равен 1

        CHECK(my_list.PopBack() == 66);//Проверка на удаление последнего элемента 
        CHECK(my_list.Size() == 0);//Проверка, что после удаления размер List равен 0

        REQUIRE(my_list.Empty() == 1);//Проверка что List пустой
       // CHECK(my_list.PopBack() == 0);
    }

    SECTION("Pure PushFront check") {

        REQUIRE(my_list.Empty() == 1);//Проверка что List пустой

        my_list.PushFront(55);//Добавляю один элемент в начало
        my_list.PushFront(66);//Добавляю второй элемент в начало
        my_list.PushFront(77);//Добавляю третий элемент в начало
        my_list.PushFront(88);//Добавляю еще один элемент в начало
        //Порядок в списке на данный момент: 88 77 66 55
        //Проверка, что после удаления первого элемента размер уменьшается на один
        CHECK(my_list.PopFront() == 88);
        CHECK(my_list.Size() == 3);//Проверка, что после удаления размер List равен 3
        //Проверка, что после удаления второго элемента размер уменьшается на один
        CHECK(my_list.PopFront() == 77);
        CHECK(my_list.Size() == 2);//Проверка, что после удаления размер List равен 2
        //Проверка, что после удаления третьего элемента размер уменьшается на один
        CHECK(my_list.PopFront() == 66);
        CHECK(my_list.Size() == 1);//Проверка, что после удаления размер List равен 1
        //Проверка, что после удаления последнего элемента размер уменьшается на один
        CHECK(my_list.PopFront() == 55);
        CHECK(my_list.Size() == 0);//Проверка, что после удаления размер List равен 0

        REQUIRE(my_list.Empty() == 1);//Проверка что List пустой

    }

    SECTION("Mixed PushFront && PushBack check") {

        REQUIRE(my_list.Empty() == 1);//Проверка что List пустой

        my_list.PushFront(44);//Добавляю один элемент в начало
        my_list.PushFront(33);//Добавляю второй элемент в начало
        my_list.PushFront(22);//Добавляю третий элемент в начало
        my_list.PushFront(11);//Добавляю еще один элемент в начало

        my_list.PushBack(66);//Добавляю элемент в конец
        my_list.PushBack(77);//Добавляю элемент в конец
        my_list.PushBack(88);//Добавляю еще один элемент в конец

        //Порядок в списке на данный момент: 11 22 33 44 66 77 88
        //Проверка, что после удаления первого элемента размер уменьшается на один
        CHECK(my_list.PopFront() == 11);
        CHECK(my_list.Size() == 6);//Проверка, что после удаления размер List равен 6
        //Проверка, что после удаления последнего элемента размер уменьшается на один
        CHECK(my_list.PopBack() == 88);
        CHECK(my_list.Size() == 5);//Проверка, что после удаления размер List равен 5
        //Проверка, что после удаления третьего элемента размер уменьшается на один
        CHECK(my_list.PopFront() == 22);
        CHECK(my_list.Size() == 4);//Проверка, что после удаления размер List равен 4
        //Проверка, что после удаления второго элемента размер уменьшается на один
        CHECK(my_list.PopBack() == 77);
        CHECK(my_list.Size() == 3);//Проверка, что после удаления размер List равен 3
        //Проверка, что после удаления третьего элемента размер уменьшается на один
        CHECK(my_list.PopFront() == 33);
        CHECK(my_list.Size() == 2);//Проверка, что после удаления размер List равен 2
        //Проверка, что после удаления пятого элемента размер уменьшается на один
        CHECK(my_list.PopBack() == 66);
        CHECK(my_list.Size() == 1);//Проверка, что после удаления размер List равен 1
        //Проверка, что после удаления четвертого элемента размер уменьшается на один
        CHECK(my_list.PopFront() == 44);
        CHECK(my_list.Size() == 0);//Проверка, что после удаления размер List равен 0

        REQUIRE(my_list.Empty() == 1);//Проверка что List пустой

    }
}

TEST_CASE("Tests on an empty list") {
    //Проверка методов на выброс ошибки, в случае если пользователь попробует удалить элементы из пустого списка.
    List lst;
    REQUIRE(lst.Empty() == 1);//Проверка списка на отсутствие элементов 
    INFO("Throwing an error");
    CHECK(lst.PopBack() == 0);//Так как лист пустой должно выкинуть ошибку
    CHECK(lst.PopFront() == 0);//Так как лист пустой должно выкинуть ошибку
}

int main(int argc, char* argv[]) {
    return Catch::Session().run(argc, argv);
}