#pragma once

#include <iostream>
#include <string>

class MyVector3
{
private:
	double x;
	double y;
	double z;

public:
	MyVector3();
	~MyVector3();
	MyVector3(double X, double Y, double Z);
	double getX();
	double getY();
	double getZ();
	double length();
	double lengthSquared();
	void normalise();
	MyVector3 operator +(MyVector3 V2);
	MyVector3 operator -(MyVector3 V2);
	MyVector3 operator -();
	double operator *(MyVector3 V2);
	MyVector3 operator *(double k);
	MyVector3 operator *(float k);
	MyVector3 operator *(int k);
	MyVector3 operator ^(MyVector3 V2);
	//std::string toString();
};
