#include "Square.h"

//�������(��� ������� �����, ��� ���� ����� 90);
Square::Square(double a) :
	Rectangle(a, b)
{
	b = a;
	d = a;
	text_var = "�������: ";
	count = 7;
}
//������� ������ � ������� ������������ �� �������� ��� 3 �������
void Square::print_info() {

	std::cout << text_var << std::endl;
	if (check() == true) { std::cout << "����������" << std::endl; }
	else { std::cout << "�� ����������" << std::endl; }
	get_var_task_3(4);
};
//������� �������� ������������ ������������ �� �������� ��� 3 �������
bool Square::check() {

	return (a == c && b == d && c == b && A == 90 && B == 90 && C == 90 && D == 90);
}