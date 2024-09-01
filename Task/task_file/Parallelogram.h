//#pragma once
#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H

#include <iostream>
#include <string>

#include "Quadrangle.h"
#include "Figure.h"

class Parallelogram : public Quadrangle {
	//��������������(������� a, c � b, d ������� �����, ���� A, C � B, D ������� �����);
public:
	Parallelogram(double a, double b, double A, double B);

	void print_info() ;
	bool check() ;
};

#endif