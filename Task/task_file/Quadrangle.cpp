#include "Quadrangle.h"
#include "My_exception.h"

//��������������(������� � ���� ������������, ���������� ������ ����� 4, ����� ����� ����� 360);
Quadrangle::Quadrangle(double a, double b, double c, double d, double A, double B, double C, double D) :
	Figure(a, b, c, d, A, B, C, D)
{
	text_var = "���������������: ";
	count = 5;
}
//������� ������ � ������� ������������ �� �������� ��� 3 �������
void Quadrangle::print_info() {
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
bool Quadrangle::check() {

	if (!((A + B + C + D) == 360)) {
		throw My_Exeception(shablon_text + "����� ����� �� ����� 360 ����.");
	}
	
	return ((A + B + C + D) == 360);
}