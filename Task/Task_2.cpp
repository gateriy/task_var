#include"Task_2.h"

template <typename text, typename data>
void Output(const text& A, const  data& B) {
	//std::cout << std::endl;
	std::cout << A << B << std::endl;
	//std::cout << std::endl;
}

/*
�������� ����� Counter. ����� ������ ��������� ������� ��������, ��� ����� �� ������ �������������:

����������� ��������� ��� �������� �� 1
����������� ��������� ��� �������� �� 1
����������� ���������� ��� ������� ��������
����������� �������� ���������� ������ � ��������� ��������� �� ��������� (1)
����������� �������� ���������� ������ � ���������������� ��������� ���������

�������� �������� �� ��, ��� � �������� ���� �� ������ ���� ����������� �������� ���������� ��������
�������� ��������

�������� ���, ��������������� ������ ������ Counter. �������� � ������������, ����� �� �� �������
��������� �������� ��� ��������. ���� �����, ����� ��� ����������� ��� �������. ����� ������������
������������ ����������� ������� �������:

+: ��������� ������� �� 1
-: ��������� ������� �� 1
=: �������� ������� �������� ��������
x: ��������� ������ ���������
*/

	Counter::Counter(const int& _count)
	{
		this->_count = _count;
	};

	Counter::Counter() {
		_count = 1;
	};

	int Counter::LookCount() {
		return _count;
	}

	int Counter::AddCount() {
		return ++_count;
	}

	int Counter::SubtractCount() {
		return --_count;
	}

int FestCounter() {
	int counter_x{ 0 };

	do
	{
		std::string Y_N{};
		std::cout << "�� ������ ������� ��������� �������� ��������? ������� �� ��� ���: ";
		std::cin >> Y_N;
		std::cout << std::endl;

		if (Y_N == "�" || Y_N == "�" || Y_N == "��") {
			std::cout << "������� ��������� �������� ��������: ";
			std::cin >> counter_x;
			break;
		}
		else if (Y_N == "�" || Y_N == "�" || Y_N == "���") {
			counter_x = 1;
			break;
		}
		else {
			std::cout << "Incorrect data!" << std::endl;
			continue;
		}
	} while (true);
	return counter_x;
}

void Task_2() {

	Counter counter(FestCounter());
	char comm{ };
	do {
		std::cout << "������� ������� ('+', '-', '=' ��� 'x'): ";
		std::cin >> comm;
		if (comm == '+') {
			counter.AddCount();
		}
		else if (comm == '-') {
			counter.SubtractCount();
		}
		else if (comm == '=') {
			Output("������� �������� ��������: ", counter.LookCount());
		}
		else if (comm == 'x' || comm == '�') {
			std::cout << "�� ��������!" << std::endl;
			std::cout << std::endl;
			break;
		}
		else {
			std::cout << "�� ���������� ������! ������� �������� ��������." << std::endl;
			std::cout << std::endl;
		}

	} while (true);

}

















