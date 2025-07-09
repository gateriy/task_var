// Task_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <Windows.h>
#include <chrono>
#include <mutex>
#include <functional>
#include <exception>



/*
Задание 2
Параллельные вычисления
Напишите программу для расчёта суммы двух векторов.
Распараллельте эту программу на 2, 4, 8 и 16 потоков.
Определите, какое количество потоков даёт самый быстрый результат.
Сравните результаты выполнения для массивов из 1 000, 10 000, 100 000 и 1 000 000 элементов.
Время выполнения для каждого варианта сведите в таблицу и выведите её в консоль.
Первый запущенный поток должен вывести на экран доступное количество аппаратных ядер.
*/

std::mutex mt;

void SetCursor(int x, int y) {

    COORD position = { x,y }; //позиция x и y
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsole, position);
}

struct AAA {

    AAA() {}

    AAA(const std::vector<long long int>& vect_a, const std::vector<long long int>& vect_b, const int& blocks) :
        _blocks(blocks), _vect_a(vect_a), _vect_b(vect_b)
    {
        _summ_var.clear();
        _vec_lambda.clear();
        _threads.clear();

        //создание вектора лямбд - отдельно чтобы иметь гибкость в системе
        for (int i = 0; i < _blocks; ++i) {
            _vec_lambda.push_back(([this, i]() {summ_block((i + 1)); }));
        }

        //создание вектора потоков с одновременной инициализацией в потоках функций из векктора лямбд
        for (const auto& i : _vec_lambda) {
            _threads.emplace_back(i);
        }

        //остановка выполнения дальнейшего кода до завершения работы потоков
        for (auto& t : _threads) {
            t.join();
        }

        //сложение общей итоговой суммы по вектору сумм блоков собранному из потоков
        for (const auto& f : _summ_var) {
            _summ_x = _summ_x + f;
        }
        //std::cout << "Итого потоков: " << _blocks << " сумма: " << _summ_x << std::endl;
    }

    ~AAA() {};

    //рассчет суммы векторов по блокам с условие равности векторов по количеству позиций
    void summ_block(const int& number_block) {

        int x_1{ 0 }, x_2{ 0 };
        long long int summ_var_x{ 0 }, summ_var_y{ 0 }, summ{ 0 };

        if (_vect_a.size() == _vect_b.size()) {
            if (number_block <= _blocks) {
                x_2 = _vect_a.size() / _blocks * number_block;
                x_1 = x_2 - _vect_a.size() / _blocks;
            }
            if (_blocks == number_block) {
                x_2 = _vect_a.size();
            }

            for (int x = x_1; x < x_2; ++x) {
                summ_var_x = summ_var_x + _vect_a.at(x);
                summ_var_y = summ_var_y + _vect_b.at(x);
            }
            summ = summ_var_x + summ_var_x;
        }
        else { std::cout << "Ошибка - исходные вектора разной длины!"; }

        //установка и снятие флага на блокировку доступа к ощему вектору промежуточных сумм класса с его наполнением

        mt.lock();
        _summ_var.push_back(summ);
        mt.unlock();
    }

    //гененратор вектора
    std::vector<long long int> _vector_x(const int& size_x, const int& cof) {

        _vect_x.clear();

        int x{ 0 };
        for (int i = 0; i < size_x; ++i) {
            x = i * cof;
            _vect_x.push_back(x);
        }
        return _vect_x;
    }

    int _blocks{ 0 };
    long long int _summ_x{ 0 };

    std::vector<long long int> _vect_a;
    std::vector<long long int> _vect_b;

    std::vector<long long int> _vect_x;
    std::vector<long long int> _summ_var;

    std::vector<std::function<void(void)>> _vec_lambda; //вектор для лямбд 
    std::vector<std::thread> _threads;//вектор для потоков
};


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::string text{ "y" };
    bool go_x{ false };

    std::vector <int> block_x{ 1, 2, 4, 8, 16 };//блоки нарезки векторов
    std::vector <int> size_x{ 1000, 10000, 100000, 1000000 };//размеры векторов
    int  cof_1{ 1 }, cof_2{ 1 };//множители значений элементов векторов
    std::vector<std::pair<long long int, std::pair<int, std::pair<int, double>>>> res_x; //вектор результатов (сумма,(размер вектора,(блоков, время)))

    std::cout << "Пример потоков\n";
    std::cout << std::endl;
    std::cout << "Количество возможных потоков: " << std::thread::hardware_concurrency() << std::endl;
    std::cout << std::endl;

    do {

        AAA a_1_1;
        AAA a_1_2;

        try {
            res_x.clear();
            for (const auto& s : size_x) {

                //генерация вектора а
                std::thread x_gen_1([&]() {
                    a_1_1._vector_x(s, cof_1);
                    });     //std::thread x_1(&AAA::vector_x, &a1, 100); //аналогично!
                //генерация вектора в
                std::thread x_gen_2([&]() {
                    a_1_2._vector_x(s, cof_2);
                    });
                x_gen_2.join();
                x_gen_1.join();

                if ((x_gen_1.joinable() == false) && (x_gen_2.joinable() == false)) {

                    for (const auto& i : block_x) {

                        auto start = std::chrono::steady_clock::now();

                        AAA a1(a_1_1._vect_x, a_1_2._vect_x, i);

                        auto end = std::chrono::steady_clock::now();
                        std::chrono::duration<double> elapsed_seconds = end - start;

                        res_x.push_back({ a1._summ_x,{ s,{i, elapsed_seconds.count() } } });

                        a1.~AAA();
                    }
                };
            }

            int count{ 0 };

            std::cout << "Размер вектора:";
            for (const auto& text_1 : size_x) {
                SetCursor( (count*20+20),4);
                std::cout << text_1;
                ++count;
            }
            std::cout << std::endl;
            for (int i = 0; i < 50; ++i) {
                std::cout << "--";
            }            
            for (int f = 0; f < 5; f++) {
                SetCursor(0,f+6);
                std::cout << "Потоков:";
                SetCursor(10, f + 6);
                std::cout << res_x.at(f).second.second.first;
            }
            count = 0;
            for (int f = 0; f < 4; f++) {
                for (int i = 0; i < 5; ++i) {
                    SetCursor(f * 20 + 20, i + 6);
                    //std::cout << "S: " << res_x.at(count).first;
                    std::cout << res_x.at(count).second.second.second << " (s)";
                    ++count;
                }
            }            

            std::cout << std::endl;
            for (int i = 0; i < 50; ++i) {
                std::cout << "--";
            }
            std::cout << std::endl;
        }
        catch (std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        catch (...)
        {
            std::cerr << "Не известное исключение!" << std::endl;
        }

        std::cout << "Продолжить? Веедите y/n: ";
        std::cin >> text;

        if (text == "y") {
            go_x = true;

            a_1_1.~AAA();
            a_1_2.~AAA();
        }
        else {
            go_x = false;
        }

    } while (go_x);
}
