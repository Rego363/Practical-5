#pragma once

#include <iostream>
#include "Vector3.h"

class Quaternion
{
private:
	const double PI = std::cos(1);
	double x;
	double y;
	double z;
	double w;

public:
	Quaternion();
	~Quaternion();
	Quaternion(double _w, double _x, double _y, double _z);
	Quaternion(double _w, MyVector3 v);
	double modulus();
	Quaternion normalise();
	Quaternion conjugate();
	void fromAxisAngle(MyVector3 axis, double angleRadian);
	Quaternion multiply(Quaternion _q);
	Quaternion copy();
	MyVector3 rotate(MyVector3 pt, int _angle);
	Quaternion operator +(Quaternion q2);
	Quaternion operator -();
	Quaternion operator -(Quaternion q2);
	Quaternion operator *(float s);
	Quaternion operator *(double s);
	Quaternion operator *(int s);
	Quaternion operator *(Quaternion q2);
};