//#pragma once
#ifndef ISOSCELESTRIANGLE_H
#define ISOSCELESTRIANGLE_H

#include <iostream>
#include <string>

#include "Triangle.h"
#include "Figure.h"

class IsoscelesTriangle : public Triangle {
	//�������������� �����������(������� a � c �����, ���� A � C �����)
public:
	IsoscelesTriangle(double a, double b, double A, double B);

	void print_info() ;
	bool check() ;
};

#endif