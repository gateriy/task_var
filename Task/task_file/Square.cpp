#include "Square.h"
#include "My_exception.h"

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
bool Square::check() {

	if (!(a == c && b == d && c == b)) {
		throw My_Exeception(shablon_text + "c������ �� �����.");
	}
	if (!(A == 90 && B == 90 && C == 90 && D == 90)) {
		throw My_Exeception(shablon_text + "���� ��� ��������� ����� �� ����� 90 ����.");
	}

	return (a == c && b == d && c == b && A == 90 && B == 90 && C == 90 && D == 90);
}