#include "Rhomb.h"

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

	std::cout << text_var << std::endl;
	if (check() == true) { std::cout << "����������" << std::endl; }
	else { std::cout << "�� ����������" << std::endl; }
	get_var_task_3(4);
};
//������� �������� ������������ ������������ �� �������� ��� 3 �������
bool Rhomb::check() {

	return (a == c && b == d && c == b && A == C && B == D && (A + C) == (B + D));
}