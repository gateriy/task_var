#include "Quadrangle.h"

//��������������(������� � ���� ������������, ���������� ������ ����� 4, ����� ����� ����� 360);
Quadrangle::Quadrangle(double a, double b, double c, double d, double A, double B, double C, double D) :
	Figure(a, b, c, d, A, B, C, D)
{
	text_var = "���������������";
	count = 5;
}
//������� ������ � ������� ������������ �� �������� ��� 3 �������
void Quadrangle::print_info() {
	std::cout << text_var << std::endl;
	if (check() == true) { std::cout << "����������" << std::endl; }
	else { std::cout << "�� ����������" << std::endl; }
	get_var_task_3(4);
};
//������� �������� ������������ ������������ �� �������� ��� 3 �������
bool Quadrangle::check() {

	return ((A + B + C + D) == 360);
}