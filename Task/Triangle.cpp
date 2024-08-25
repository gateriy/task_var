#include "Triangle.h"

//�����������(������� � ���� ������������, ���������� ������ ����� 3, ����� ����� ����� 180);
Triangle::Triangle(double a, double b, double c, double A, double B, double C) :
	Figure(a, b, c, 0, A, B, C, 0)
{
	//d = 0;
	//D = 0;
	text_var = "�����������: ";
	count = 1;
}
//������� ������ � ������� ������������ �� �������� ��� 3 �������
void Triangle::print_info() {

	std::cout << text_var << std::endl;
	if (check() == true) { std::cout << "����������" << std::endl; }
	else { std::cout << "�� ����������" << std::endl; }
	get_var_task_3(3);
};
//������� �������� ������������ ������������ �� �������� ��� 3 �������
bool Triangle::check() {

	return ((A + B + C) == 180);
}