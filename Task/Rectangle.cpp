#include "Rectangle.h"

//�������������(������� a, c � b, d ������� �����, ��� ���� ����� 90);
Rectangle::Rectangle(double a, double b) :
	Quadrangle(a, b, c, d, A, B, C, D)
{
	c = a;
	d = b;
	C = 90;
	A = 90;
	B = 90;
	D = 90;
	text_var = "�������������: ";
	count = 6;
}
//������� ������ � ������� ������������ �� �������� ��� 3 �������
void Rectangle::print_info() {

	std::cout << text_var << std::endl;
	if (check() == true) { std::cout << "����������" << std::endl; }
	else { std::cout << "�� ����������" << std::endl; }
	get_var_task_3(4);
};
//������� �������� ������������ ������������ �� �������� ��� 3 �������
bool Rectangle::check() {

	return (a == c && b == d && A == 90 && B == 90 && C == 90 && D == 90);
}