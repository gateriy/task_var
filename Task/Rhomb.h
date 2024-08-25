//#pragma once
#ifndef RHOMB_H
#define RHOMB_H

#include <iostream>
#include <string>

#include "Parallelogram.h"
#include "Quadrangle.h"
#include "Figure.h"

class Rhomb : public Parallelogram {
	//����(��� ������� �����, ���� A, C � B, D ������� �����).
public:
	Rhomb(double a, double A, double B);

	void print_info() ;
	bool check() ;
};

#endif