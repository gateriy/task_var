#include "Figure.h"
#include "My_exception.h"

Figure::Figure() {};
Figure::Figure(double a, double b, double c, double d, double A, double B, double C, double D) :
	a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D)
{}
//������� ������ � ������� ������������ �� �������� ��� 2 �������
void Figure::print_info() {

	std::cout << text_var << " (�������: 0 ����: 0) " << "������!" << std::endl;;

};
//������� �������� ������������ ������������ �� �������� ��� 2 �������
bool Figure::check() { return true; };
void Figure::get_var_task_3(int number_of_sides) {

	//std::cout << "���������� ������: " << number_of_sides << std::endl;
	std::cout << std::endl;


	if (number_of_sides >= 1 && number_of_sides < 5) {
		std::cout << text_var << "(�������: � = " << a << " b = " << b << " c = " << c <<
			" ����: A = " << A << " B = " << B << " C = " << C << ") ������!" << std::endl;;
	}
	if (number_of_sides >= 5 && number_of_sides <= 9) {
		std::cout << text_var << "(�������: � = " << a << " b = " << b << " c = " << c << " d = " << d <<
			" ����: A = " << A << " B = " << B << " C = " << C << " D = " << D << ") ������!" << std::endl;;
	}
	//std::cout << std::endl;
}