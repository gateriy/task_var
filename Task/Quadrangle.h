//#pragma once
#ifndef QUADRANGLE_H
#define QUADRANGLE_H

#include <iostream>
#include <string>

#include "Figure.h"

class Quadrangle : public Figure {
	//��������������(������� � ���� ������������, ���������� ������ ����� 4, ����� ����� ����� 360);
public:
	Quadrangle(double a, double b, double c, double d, double A, double B, double C, double D);

	void print_info() override;
	bool check() override;
};

#endif