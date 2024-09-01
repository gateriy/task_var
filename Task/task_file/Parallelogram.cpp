#include "Parallelogram.h"
#include "My_exception.h"

//��������������(������� a, c � b, d ������� �����, ���� A, C � B, D ������� �����);
Parallelogram::Parallelogram(double a, double b, double A, double B) :
	Quadrangle(a, b, c, d, A, B, C, D)
{
	c = a;
	d = b;
	C = A;
	D = B;
	text_var = "��������������: ";
	count = 8;
}
//������� ������ � ������� ������������ �� �������� ��� 3 �������
void Parallelogram::print_info() {

try{
	get_var_task_3(count);
	check();
}
catch (const My_Exeception& exp) {
	std::cout << exp.what() << std::endl;
}
catch (...) {
	std::cout << "�� ��������� ������" << std::endl;
}
};

//������� �������� ������������ ������������ �� �������� ��� 3 �������
bool Parallelogram::check() {

	if (!(a == c && b == d)) {
		throw My_Exeception(shablon_text + "c������ a,c � b,d ������� �� �����.");
	}
	if (!((a + c) == (b + d))) {
		throw My_Exeception(shablon_text + "����� ���� ������ a,c � b,d �� �����.");
	}
	if (!(A == C && B == D)) {
		throw My_Exeception(shablon_text + "���� A,C � B,D ������� �� �����.");
	}
	if (!((A + C) == (B + D))) {
		throw My_Exeception(shablon_text + "����� ����� A,C � B,D  �� �����.");
	}


	return (a == c && b == d && (a + c) == (b + d) && A == C && B == D && (A + C) == (B + D));
}