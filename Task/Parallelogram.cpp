#include "Parallelogram.h"

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

	std::cout << text_var << std::endl;
	if (check() == true) { std::cout << "����������" << std::endl; }
	else { std::cout << "�� ����������" << std::endl; }
	get_var_task_3(4);
};
//������� �������� ������������ ������������ �� �������� ��� 3 �������
bool Parallelogram::check() {

	return (a == c && b == d && (a + c) == (b + d) && A == C && B == D && (A + C) == (B + D));
}