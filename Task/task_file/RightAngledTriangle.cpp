#include "RightAngledTriangle.h"
#include "My_exception.h"

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
bool RightAngledTriangle::check() {

	if (!(C == 90)) {
		throw My_Exeception(shablon_text + "���� � �� ����� 90 ����.");
	}
	if (!((A + B + C) == 180)) {
		throw My_Exeception(shablon_text + "����� ����� �� ����� 180 ����.");
	}
	

	return ((C == 90) && ((A + B + C) == 180));
}
