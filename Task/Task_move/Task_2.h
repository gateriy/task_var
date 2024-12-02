//#pragma once
#ifndef TASK_2_H
#define TASK_2_H

#include "AllConfigTask.h"

class big_intger {
	
public:

	big_intger() {
//		std::cout << "construction()" << std::endl;
	};

	big_intger(const std::string& a) : _text(a) {
//		std::cout << "construction(x)" << std::endl;
	};

	big_intger(big_intger&& other) noexcept // конструктор перемещения
		: _text(std::exchange(other._text, nullptr)) {
//		std::cout << "construction(move)" << std::endl;
	};

	~big_intger() {
	//	std::cout << "distuction" << std::endl;
	};

	big_intger operator + (big_intger& other) {

//		std::cout << "(+)" << std::endl;
		return summ_y(this->_text, other._text);
	}

	big_intger operator * (big_intger& other) {
 
//		std::cout << "(*)" << std::endl;
		return multi(this->_text, other._text);
	}

	big_intger& operator = (big_intger&& other) noexcept // оператор перемещающего присваивания
	{
		std::swap(_text, other._text);
//		std::cout << "(=move)" << std::endl;

		return 	 *this;
	}



	std::string get();

	bool check(const std::string& x, const std::string& text);

private:
	std::string _text;	

	std::string summ_y(const std::string& xx, const std::string& yy);

	std::string multi(const std::string& str_a, const std::string& str_b);

	std::vector<int> _transfor_vector(const std::string& var);

	std::vector<int> _summ_x(const std::vector<int>& a);

};

void Task_2();

#endif