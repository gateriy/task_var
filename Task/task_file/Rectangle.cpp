#include "Rectangle.h"
#include "My_exception.h"

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
try{

	get_var_task_3(count);
	check();
}
catch (const My_Exeception& exp) {
	std::cout << exp.what() << std::endl;
}
catch (...) {
	std::cout << "�� ��������� ������" << std::endl;
}
};
//������� �������� ������������ ������������ �� �������� ��� 3 �������
bool Rectangle::check() {

	if (!(a == c && b == d)) {
		throw My_Exeception(shablon_text + "c������ a,c � b,d ������� �� �����.");
	}
	if (!(A == 90 && B == 90 && C == 90 && D == 90)) {
		throw My_Exeception(shablon_text + "���� ��� ��������� ����� �� ����� 90 ����.");
	}


	return (a == c && b == d && A == 90 && B == 90 && C == 90 && D == 90);
}