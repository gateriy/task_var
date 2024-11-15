//#pragma once
#ifndef TASK_2_H
#define TASK_2_H

#include <iostream>
#include <string>

template<typename T> 
class Two_Array
{
public:
	Two_Array(int r, int c) : _row(r), _cel(c) {

			_table = new T*[_row];
		for (int i = 0; i < _row; ++i) {
			_table[i] = new T [_cel];
		}

		
	};

	~Two_Array() {

		for (int i = 0; i < _row; ++i) {
			delete[] _table[i];
		}	
		delete[] _table;
		//std::cout << "array destruction" << std::endl;
	};

	T** _table;
private:

	int _row{ 0 }, _cel{ 0 };
};



void Task_2();

#endif