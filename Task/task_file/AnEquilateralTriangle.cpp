#include "AnEquilateralTriangle.h"
#include "My_exception.h"

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
bool AnEquilateralTriangle::check() {

	if (!((A == 60) && (B == 60) && (C == 60))) {
		throw My_Exeception(shablon_text+"���� �� ����� 60 ����.");
	}
	if (!((a == b) && (a == c) && (b == c))) {
		throw My_Exeception(shablon_text+"����� ������ �� �����.");
	}

	return ((A == 60) && (B == 60) && (C == 60) && (a == b) && (a == c) && (b == c));
}