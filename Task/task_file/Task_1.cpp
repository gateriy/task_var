#include "Task_1.h"


/*
������ 1. ������� ����������
� ���� ������� �� ���������� ��������� � ���������� ����������.
�������� ������� int function(std::string str, int forbidden_length). 
��� ������� ������ ���������� ����� ���������� ������, ���� ��� ����� 
�� ����� �������� ����������� ��������� forbidden_length. 
� ��������� ������ ��� ������ ����������� ���������� bad_length.

��� �������� ������� ����������� ������ � �������������. 
� ������ ������� ��������� �����, � ����� ���������� ���������������� 
������ � �������� �� ����� �� ��� ���, ���� ������������ �� ����� ������ ��������� �����. 
����� ����� �������� ���, ��� �� ��� ������ ��������� �����, � ��������� ���������.

������ ������ ��������� �������

������� ��������� �����: 5
������� �����: ������
����� ����� "������" ����� 6
������� �����: ���
����� ����� "���" ����� 3
������� �����: �����
�� ����� ����� ��������� �����! �� ��������

---��� ������������ ��� �������.---
��� ���������� ����� ������ ����������� ����� ������ std::string � length.
��� �������� ���������� ����������� �������� ����� throw.
��� �������� ���������� ����������� �������� ����� try.
��� ��������� ���������� ����������� �������� ����� catch.
*/



int function(const std::string& str, const int& forbidden_length) {
		
	if (forbidden_length != (str.length())) {
		return static_cast<int>(str.length());
	}
	else {
		throw My_Exeception("�� ����� ����� ��������� �����! �� ��������");
	};
}

int StringToInt(const std::string& text_var) {
	
	std::string simbol{ "0123456789 "};
	std::string var_t{""};
	bool err{ false };

	for (const char& i : text_var) {
		err = false;		 
		for (const char& simvol_x : simbol) {

			if (i == simvol_x) { 
				var_t = var_t + i;
				err = true;
			}
		}
			if (err == false) {
				throw My_Exeception("�� ����� �� ������������� ������! �� ��������");
			}
	}
	return std::stoi(var_t);
}

void Task_1() {
		std::string size_text{};
		std::string text{};	
		int s_text{ 0 }, x_var{ 0 };
	try
	{			
		std::cout << "������� ��������� �����: ";
		std::cin >> size_text;
		s_text = StringToInt(size_text);
		std::cout << std::endl;


		do {
			std::cout << "������� �����: ";
			std::cin >> text;
			x_var = function(text, s_text);
			std::cout << "����� ����� " << text << " ����� " << x_var << std::endl;
		} while (true);
		
	}
	catch (const My_Exeception& exp) {	
		std::cout << std::endl;
		std::cout << exp.what() << std::endl; }

	catch (...) { 
		std::cout << std::endl;
		std::cout << "�� ��������� ������" << std::endl; }

};