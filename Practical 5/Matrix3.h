#pragma once

#include <iostream>
#include "Vector3.h"
#define _USE_MATH_DEFINES
#include <cmath>

class Matrix3
{
private:
	const double PI = std::cos(1);
	double A11;
	double A12;
	double A13;
	double A21;
	double A22;
	double A23;
	double A31;
	double A32;
	double A33;

public:
	Matrix3();
	~Matrix3();
	Matrix3(MyVector3 Row1, MyVector3 Row2, MyVector3 Row3);
	Matrix3(double _A11, double _A12, double _A13,
		double _A21, double _A22, double _A23,
		double _A31, double _A32, double _A33);
	void setMatrix(MyVector3 Row1, MyVector3 Row2, MyVector3 Row3);
	MyVector3 operator *(MyVector3 V1);
	Matrix3 transpose();
	Matrix3 operator +(Matrix3 M2);
	Matrix3 operator -(Matrix3 M2);
	Matrix3 operator *(double x);
	Matrix3 operator *(Matrix3 M2);
	double determinant();
	MyVector3 row(int i);
	MyVector3 column(int i);
	Matrix3 inverse();
	Matrix3 rotation(int _angle);
	Matrix3 translate(int dx, int dy);
	Matrix3 scale(int dx, int dy);
	Matrix3 operator -();
	Matrix3 rotationX(int _angle);
	Matrix3 rotationY(int _angle);
	Matrix3 rotationZ(int _angle);
	Matrix3 Scale3D(int dx);
};