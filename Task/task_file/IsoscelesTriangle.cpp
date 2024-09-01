#include "IsoscelesTriangle.h"
#include "My_exception.h"

//�������������� �����������(������� a � c �����, ���� A � C �����);
IsoscelesTriangle::IsoscelesTriangle(double a, double b, double A, double B) :
	Triangle(a, b, c, A, B, C)
{
	d = 0;
	D = 0;
	c = a;
	C = A;
	text_var = "�������������� �����������: ";
	count = 3;
}
//������� ������ � ������� ������������ �� �������� ��� 3 �������
void IsoscelesTriangle::print_info() {
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
bool IsoscelesTriangle::check() {

	if (!(C == A)) {
		throw My_Exeception(shablon_text+"��� ���� A � C �� �����.");
	}
	if (!((A + B + C) == 180)) {
		throw My_Exeception(shablon_text + "����� ����� �� ����� 180 ����.");
	}
	if (!(a == c)) {
		throw My_Exeception(shablon_text + "��� ������� a � � �� �����.");
	}
	

	return ((C == A) && ((A + B + C) == 180) && (a == c));
}