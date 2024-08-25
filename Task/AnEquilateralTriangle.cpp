#include "AnEquilateralTriangle.h"

//�������������� �����������(��� ������� �����, ��� ���� ����� 60);
AnEquilateralTriangle::AnEquilateralTriangle(double a) :
	Triangle(a, b, c, A, B, C)
{
	c = a;
	b = a;
	C = 60;
	A = 60;
	B = 60;
	text_var = "�������������� �����������: ";
	count = 4;
}
//������� ������ � ������� ������������ �� �������� ��� 3 �������
void AnEquilateralTriangle::AnEquilateralTriangle::print_info() {

	std::cout << text_var << std::endl;
	if (check() == true) { std::cout << "����������" << std::endl; }
	else { std::cout << "�� ����������" << std::endl; }
	get_var_task_3(3);
};
//������� �������� ������������ ������������ �� �������� ��� 3 �������
bool AnEquilateralTriangle::check() {

	return ((A == 60) && (B == 60) && (C == 60) && (a == b) && (a == c) && (b == c));
}