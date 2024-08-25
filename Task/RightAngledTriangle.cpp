#include "RightAngledTriangle.h"

//������������� �����������(���� C ������ ����� 90);
RightAngledTriangle::RightAngledTriangle(double a, double b, double c, double A, double B) :
	Triangle(a, b, c, A, B, 90)
{
	d = 0;
	D = 0;
	//C = 90;
	text_var = "������������� �����������: ";
	count = 2;
}
//������� ������ � ������� ������������ �� �������� ��� 3 �������
void RightAngledTriangle::print_info() {

	std::cout << text_var << std::endl;
	if (check() == true) { std::cout << "����������" << std::endl; }
	else { std::cout << "�� ����������" << std::endl; }
	get_var_task_3(3);
};
//������� �������� ������������ ������������ �� �������� ��� 3 �������
bool RightAngledTriangle::check() {

	return ((C == 90) && ((A + B + C) == 180));
}
