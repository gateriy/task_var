п»ї//РїРѕРґРєР»СЋС‡Р°РµРј РјР°РєСЂРѕСЃС‹ catch2
#include "catch_amalgamated.hpp"
#include <cstdint>
#include <iostream>


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


//--------------РїСЂРѕРІРµСЂРєРё------------

//empty
TEST_CASE("Empty test", "[empty]") {
    
    List class_test;
    class_test.PushBack(1);
   
    CHECK(class_test.Empty() == true);
    CHECK(class_test.Empty() == false);

}

//clear
TEST_CASE("Clear test", "[clear]") {

    List class_test;
    class_test.PushBack(1);

    CHECK(class_test.Empty() == true);
    class_test.Clear();

    CHECK(class_test.Empty() == true);
}

//size
TEST_CASE("Size test", "[size]") {  

    std::cout << "Size test" << std::endl;

    List class_test; 

    for (unsigned long i = 0; i < 100; ++i) {

        class_test.PushBack(i);
        REQUIRE(class_test.Size() == i+1);

        if ((i+1) % 10 == 0) {
            std::cout << class_test.Size()<< " = " << i + 1 << " << good!" << std::endl;
        }
    }
      
    class_test.Clear();
    CHECK(class_test.Empty() == true);
    CHECK(class_test.Size() == 0);

    std::cout << "------------------------------------------" << std::endl;
}

//PushBack
TEST_CASE("PushBack test", "[pushback]") {

    std::cout << "PushBack test" << std::endl;

    List class_test;

    for (unsigned long i = 0; i < 100; ++i) {

        class_test.PushBack(i);
        REQUIRE(class_test.Size() == i + 1);

        if ((i + 1) % 10 == 0) {
            std::cout << class_test.Size() << " = " << i + 1 << " << good!" << std::endl;
        }
    }

    CHECK(class_test.Size() == 100);
    class_test.Clear();
    std::cout <<  "------------------------------------------" << std::endl;
}

//PushFront
TEST_CASE("PushFront test", "[pushfront]") {

    std::cout << "PushFront test" << std::endl;

    List class_test;
    class_test.PushBack(100);//1 Р·РЅР°С‡РµРЅРёРµ

    for (unsigned long i = 0; i < 100; ++i) {

        class_test.PushFront(i);
        REQUIRE(class_test.Size() == i + 2);

        if ((i + 2) % 10 == 0) {
            std::cout << class_test.Size() << " = " << i + 2 << " << good!" << std::endl;
        }
    }

    CHECK(class_test.Size() == 101);
    class_test.Clear();
    std::cout << "------------------------------------------" << std::endl;
}


//PopBack
TEST_CASE("PopBack test", "[popback]") {

    std::cout << "PopBack test" << std::endl;

    List class_test;

    for (int i = 0; i < 100; ++i) {
        class_test.PushBack(i);
    }
    std::cout << class_test.Size()  << std::endl;

   // CHECK(class_test.Size() == 100);

    for (int i = 100; i >= 1; --i) {

        class_test.PopBack();
        CHECK(class_test.Size() == i - 1);

        if ((i - 1) % 10 == 0) {
            std::cout << class_test.Size() << " = " << i - 1 << " << good!" << std::endl;
        }
    }

    CHECK(class_test.Size() == 0);
    class_test.Clear();
    std::cout << "------------------------------------------" << std::endl;
}

//PopFront
TEST_CASE("PopFront test", "[PopFront]") {

    std::cout << "PopFront test" << std::endl;

    List class_test;

    for (int i = 0; i < 100; ++i) {
        class_test.PushBack(i);
    }
    std::cout << class_test.Size() << std::endl;


    for (int i = 100; i >= 1; --i) {

        class_test.PopFront();
        CHECK(class_test.Size() == i - 1);

        if ((i - 1) % 10 == 0) {
            std::cout << class_test.Size() << " = " << i - 1 << " << good!" << std::endl;
        }
    }

    CHECK(class_test.Size() == 0);
    class_test.Clear();

  
    std::cout << "------------------------------------------" << std::endl;
}