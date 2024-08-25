#include "Figure.h"

Figure::Figure() {};
Figure::Figure(double a, double b, double c, double d, double A, double B, double C, double D) :
	a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D)
{}
//������� ������ � ������� ������������ �� �������� ��� 3 �������
void Figure::print_info() {

	std::cout << text_var << std::endl;

	if (check() == true) {
		std::cout << "����������" << std::endl;
	}
	else {
		std::cout << "�� ����������" << std::endl;
	}
	std::cout << "���������� ������: 0" << std::endl;
	std::cout << std::endl;
};
//������� �������� ������������ ������������ �� �������� ��� 3 �������
bool Figure::check() { return true; };
void Figure::get_var_task_3(int number_of_sides) {

	std::cout << "���������� ������: " << number_of_sides << std::endl;

	if (count >= 1 && count < 5) {
		std::cout << "�������: � = " << a << " b = " << b << " c = " << c << std::endl;
		std::cout << "����: A = " << A << " B = " << B << " C = " << C << std::endl;
	}
	if (count >= 5 && count <= 9) {
		std::cout << "�������: � = " << a << " b = " << b << " c = " << c << " d = " << d << std::endl;
		std::cout << "����: A = " << A << " B = " << B << " C = " << C << " D = " << D << std::endl;
	}
	std::cout << std::endl;
}