#include "Quaternion.h"

Quaternion::Quaternion()
{
	w = 0; 
	x = 0;
	y = 0;
	z = 0;
};

Quaternion::~Quaternion() {};

Quaternion::Quaternion(double _w, double _x, double _y, double _z)
{
	w = _w;
	x = _x;
	y = _y;
	z = _z;
};

Quaternion::Quaternion(double _w, MyVector3 v)
{
	w = _w;
	x = v.getX();
	y = v.getY();
	z = v.getZ();
};

double Quaternion::modulus()
{
	return std::sqrt(w*w + x*x + y*y + z*z);
};

Quaternion Quaternion::normalise()
{
	double m = w * w + x * x + y * y + z * z;
	if (m > 0.001)
	{
		m = std::sqrt(m);
		return Quaternion(w / m, x / m, y / m, z / m);
	}
	else
	{
		return Quaternion(1, 0, 0, 0);
	}
};

Quaternion Quaternion::conjugate()
{
	return Quaternion(w, -x, -y, -z);
};

void Quaternion::fromAxisAngle(MyVector3 axis, double angleRadian)
{
	double m = axis.length();
	if (m > 0.0001)
	{
		double ca = std::cos(angleRadian / 2);
		double sa = std::sin(angleRadian / 2);
		x = axis.getX() / m * sa;
		y = axis.getY() / m * sa;
		z = axis.getZ() / m * sa;
		w = ca;
	}
	else
	{
		w = 1; x = 0; y = 0; z = 0;
	}
};

Quaternion Quaternion::multiply(Quaternion _q)
{
	double nw = _q.w *  w - _q.x *  x - _q.y *  y - _q.z *  z;
	double nx = _q.w *  x + _q.x *  w + _q.y *  z - _q.z *  y;
	double ny = _q.w *  y + _q.y *  w + _q.z *  x - _q.x *  z;
	double nz = _q.w *  z + _q.z *  w + _q.x *  y - _q.y *  x;
	return Quaternion(nw, nx, ny, nz);
};

Quaternion Quaternion::copy()
{
	return Quaternion(x, y, z, w);
};

MyVector3 Quaternion::rotate(MyVector3 pt, int _angle)
{
	;
	Quaternion axis(normalise());
	double angleRad = PI / 180 * _angle;
	Quaternion qRotate = Quaternion(std::cos(angleRad / 2), std::sin(angleRad / 2) * axis.x, std::sin(angleRad / 2) * axis.y, std::sin(angleRad / 2) * axis.z);
	Quaternion conjugate = qRotate.conjugate();
	Quaternion qNode = Quaternion(0, pt.getX(), pt.getY(), pt.getZ());
	Quaternion answer = qRotate * qNode * conjugate;
	return MyVector3(answer.x, answer.y, answer.z);
};

/// <summary>
/// Adding two quaternions together
/// </summary>
/// <param name="q2"></param>
/// <returns></returns>
Quaternion Quaternion::operator +(Quaternion q2)
{
	return Quaternion(w + q2.w, x + q2.x, y + q2.y, z + q2.z);
};

Quaternion Quaternion::operator -()
{
	return Quaternion(-w, -x, -y, -z);
};

Quaternion Quaternion::operator -(Quaternion q2)
{
	return Quaternion(w - q2.w, x - q2.x, y - q2.y, z - q2.z);
};

Quaternion Quaternion::operator *(float s)
{
	return Quaternion(w * s, x * s, y * s, z * s);
};

Quaternion Quaternion::operator *(double s)
{
	return Quaternion(w * s, x * s, y * s, z * s);
};

Quaternion Quaternion::operator *(int s)
{
	return Quaternion(w * s, x * s, y * s, z * s);
};

Quaternion Quaternion::operator *(Quaternion q2)
{
	double nw = w * q2.w - x * q2.x - y * q2.y - z * q2.z;
	double nx = w * q2.x + x * q2.w + y * q2.z - z * q2.y;
	double ny = w * q2.y + y * q2.w + z * q2.x - x * q2.z;
	double nz = w * q2.z + z * q2.w + x * q2.y - y * q2.x;
	return Quaternion(nw, nx, ny, nz);
};