#include "Task_1.h"



/*
Задача 1. Возведение в квадрат
Описание
Нужно реализовать шаблонную функцию возведения в квадрат, 
которая работает не только с простыми числами, но и с векторами. 
Для этого создайте две реализации шаблонной функции.

Пример правильной работы программы
[IN]: 4
[OUT]: 16
[IN]: -1, 4, 8
[OUT]: 1, 16, 64
*/

template < typename var >
var square(var var_x) {
	return var_x * var_x;

};

template <>
std::vector<int> square(std::vector<int> var_x) {

	std::vector<int> res;

	for (const auto& i : var_x) {
		res.push_back(i * i);
	}
	return res;
}

void Task_1() {
	bool first{ true };
	int var_y{ 5 };
	std::vector <int> vector_x{1, 2, 3, 4, 5};

	std::cout << "[IN]:\t" << var_y << std::endl;
	std::cout << "[OUT]:\t" << square(var_y) << std::endl;

	first = true;
	std::cout << "[IN]:\t";
	for (const auto& i : vector_x) {
		if (first) {
			std::cout << i;
		}
		else {
			std::cout << ", " << i;
		}
		first = false;
	}
	std::cout << std::endl;

	first = true;
	std::cout << "[OUT]:\t";
	for (const auto& i : square(vector_x)) {
		if (first) {
			std::cout << i;
		}
		else {
			std::cout << ", " << i;
		}
		first = false;
	}
	std::cout << std::endl;
	std::cout <<"------------------------------" << std::endl;

};