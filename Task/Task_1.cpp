#include "Task_1.h"

/*
� ���� ������� �� �������� �������������� ������� � ��������� ����.
���� ��������� ������������� �������: ��������, ���������, ���������, �������, ���������� � �������.
��� ����� ���������� �� � ��������� ����� ��������� ���� � ��������������� ��� �� ������� main.
��������� ������������ ������ ��� ����� � ������� ��������. �������� ��������� ��� �� �������.

������ ������ ���������
�������
������� ������ �����: 20
������� ������ �����: 2
�������� �������� (1 - ��������, 2 ���������, 3 - ���������, 4 - �������, 5 - ���������� � �������): 5
20 � ������� 2 = 400
*/


	double InputVar(std::string text) {
		double var{ 0 };
		std::cout << text;
		std::cin >> var;
		std::cout << std::endl;
		return var;
	}

	int InputOperat(std::string text) {
		double var{ 0 };
		std::cout << text;
		std::cin >> var;
		std::cout << std::endl;
		return var;
	}

	void Mathem_x() {

		double x{ 0 }, y{ 0 }, res{ 0 };
		int oper_var{ 0 };
		bool next{ true };
		std::vector <std::string> text_out{
			"������� �", "������� �", "�������� ��", "��������� ��", "� �������" };

		x = InputVar("������� ������ �����: ");
		y = InputVar("������� ������ �����: ");

		do {
		oper_var = InputOperat("�������� �������� (1 - ��������, 2 ���������, 3 - ���������, 4 - �������, 5 - ���������� � �������): ");

			switch (oper_var)
			{
			case (1):
				res = x + y;
				next = false;
				break;
			case (2):
				res = x - y;
				next = false;
				break;
			case (3):
				res = x * y;
				next = false;
				break;
			case (4):
				res = x / y;
				next = false;
				break;
			case (5):
				res = pow(x, y);
				next = false;
				break;

			default:
				std::cout << "�� ���������� �����. ��������� ����" << std::endl;
				std::cout <<  std::endl;
				next = true;
				break;
			}
		} while (next);
		std::cout << x <<" "<< text_out[oper_var - 1] <<" " << y << " = " << res << std::endl;
		std::cout << std::endl;

	}

void Task_1() {
	
	Mathem_x();

};
