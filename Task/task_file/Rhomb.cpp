#include "Rhomb.h"
#include "My_exception.h"

//����(��� ������� �����, ���� A, C � B, D ������� �����).
Rhomb::Rhomb(double a, double A, double B) :
	Parallelogram(a, b, A, B)
{
	b = a;
	d = b;
	text_var = "����: ";
	count = 9;
}
//������� ������ � ������� ������������ �� �������� ��� 3 �������
void Rhomb::print_info() {
try{	
	get_var_task_3(count);
	check();
	std::cout << std::endl;
}
catch (const My_Exeception& exp) {
	std::cout << exp.what() << std::endl;
}
catch (...) {
	std::cout << "�� ��������� ������" << std::endl;
}
};
//������� �������� ������������ ������������ �� �������� ��� 3 �������
bool Rhomb::check() {

	if (!(a == c && b == d && c == b)) {
		throw My_Exeception(shablon_text + "c������ �� �����.");
	}
	if (!(A == C && B == D)) {
		throw My_Exeception(shablon_text + "���� A, C � B, D ������� �� �����.");
	}
	if (!((A + C) == (B + D))) {
		throw My_Exeception(shablon_text + "����� ����� A, C � B, D ������� �� �����.");
	}

	return (a == c && b == d && c == b && A == C && B == D && (A + C) == (B + D));
}