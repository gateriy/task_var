//#pragma once
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <string>

#include "Figure.h"
#include "Quadrangle.h"

class Rectangle : public Quadrangle {
	//�������������(������� a, c � b, d ������� �����, ��� ���� ����� 90);
public:
	Rectangle(double a, double b);

	void print_info() override;
	bool check() override;
};

#endif