#include "Triangle.h"
#include "My_exception.h"

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
bool Triangle::check() {

	if (!(A + B + C)) {
		throw My_Exeception(shablon_text + "���� �� �����.");
	}
	
	return ((A + B + C) == 180);
}