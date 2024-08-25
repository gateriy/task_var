#include "IsoscelesTriangle.h"

//�������������� �����������(������� a � c �����, ���� A � C �����);
IsoscelesTriangle::IsoscelesTriangle(double a, double b, double A, double B) :
	Triangle(a, b, c, A, B, C)
{
	d = 0;
	D = 0;
	c = a;
	C = A;
	text_var = "�������������� �����������: ";
	count = 3;
}
//������� ������ � ������� ������������ �� �������� ��� 3 �������
void IsoscelesTriangle::print_info() {

	std::cout << text_var << std::endl;
	if (check() == true) { std::cout << "����������" << std::endl; }
	else { std::cout << "�� ����������" << std::endl; }
	get_var_task_3(3);
};
//������� �������� ������������ ������������ �� �������� ��� 3 �������
bool IsoscelesTriangle::check() {

	return ((C == A) && ((A + B + C) == 180) && (a == c));
}