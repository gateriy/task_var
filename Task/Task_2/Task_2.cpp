
#include<iostream>
#include<vector>
#include<random>
#include<functional>
#include<Windows.h>
#include<string>
#include<thread>
#include<mutex>
#include<future>
//#include <algorithm>


template<typename Iterator, typename Function_x>

void for_each_x(Iterator first, Iterator last, Function_x f) {
    //определение размера контейнера
    unsigned long const size_x = std::distance(first, last);

    //завершение рекурсии когда кончилась дистанция
    if (!size_x) { return; }

    //количество блоков по физически возможным потокам
    unsigned const min_thread = std::thread::hardware_concurrency(); 

    //если размер контейнера равен или меньше количества потоков то запускаем в основном потоке
    if (size_x < min_thread) {

        std::for_each(first, last, f); 

    }
    else {
        //деление диапазона на поплам
        Iterator const mid_point = first + size_x / 2;
        //запуск от начала до середины диапазона через future
        std::future<void> first_half = std::async(&for_each_x<Iterator, Function_x>, first, mid_point, f);
        //прямой запуск в основном потоке от середины до конца диапазона
        for_each_x(mid_point, last, f);
        //вывод результата future
        first_half.get();
    }
}

/*

void for_each_x(std::vector<int>::iterator begin, std::vector<int>::iterator end, const std::function<void(int)>& function_x) {
    //ограничение на запуск для одного потока от количества элементов в контейнере
    if (std::distance(begin, end) <= 1) {
        function_x(*begin);
        return;
    }

    int thr_count = std::thread::hardware_concurrency(); //количество блоков по физически возможным потокам
    int block_size = (std::distance(begin, end) / thr_count) + 1; //размер блока

    std::vector<std::thread> threads;//ветор потоков
    std::vector<decltype(begin)> block_start(thr_count - 1);//вектор итераторов начал для блоков

    for (int i = 1; i < thr_count; ++i) {
        block_start[i - 1] = begin;
        std::advance(block_start[i - 1], block_size);
    }

    for (int i = 0; i < (thr_count - 1); ++i) {
        //begin = block_start[i];
        //end = std::next(begin, block_size);
        threads.emplace_back([begin = block_start[i], end = std::next(begin, block_size), function_x]() {for_each_x(begin, end, function_x); });
    }

    function_x(*std::next(begin, block_size - 1));
    //function_x(end);
    //for (auto& it = begin; it != end; ++it) {

        //std::cout << *it<<" ";
      //  function_x(*it,"www");
    //}

    for (auto& th : threads) {
        th.join();
    }

}
*/

std::mutex mt;
void print_arr_1(int i) {
    mt.lock();
    std::cout << "[" << i*2 << "]\t";
    mt.unlock();
}

void print_arr(const std::vector<int>& vec_x) {
    for (auto& i : vec_x) {
        std::cout << "[" << i << "]\t";
    }
    std::cout << std::endl;
}

int main()
{

    std::vector<int> a;

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int size_x{ 100 };

    for (int i = 0; i < size_x; ++i) {
        a.push_back(std::rand() % 100);
    }
    std::cout << "Исходный массив: " << std::endl;
    print_arr(a);

    /*
    auto b = [&](int i) {
        mt.lock();
        std::cout << "[" << i * 2 << "]" << "\t";
        mt.unlock(); };
    */
    std::cout << std::endl;
    std::cout << "Обработатнный массив (умножение на 2 и вывод в процессе обработки): " << std::endl;
    for_each_x(a.begin(), a.end(), print_arr_1);
    //for_each_x(a.begin(), a.end(), b);

    std::cout << std::endl;

   
}