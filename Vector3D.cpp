#include "Vector3D.h"

namespace Raytracing
{
	Vector3D::Vector3D(double e0, double e1, double e2)
	{
		vec3.resize(3);
		vec3.at(0) = e0;
		vec3.at(1) = e1;
		vec3.at(2) = e2;
	}

	Vector3D& Vector3D::operator+=(const Vector3D& v)
	{
		vec3.at(0) += v.vec3.at(0);
		vec3.at(1) += v.vec3.at(1);
		vec3.at(2) += v.vec3.at(2);
		return *this;
	}

	Vector3D& Vector3D::operator-=(const Vector3D& v)
	{
		vec3.at(0) -= v.vec3.at(0);
		vec3.at(1) -= v.vec3.at(1);
		vec3.at(2) -= v.vec3.at(2);
		return *this;
	}

	Vector3D& Vector3D::operator*=(const Vector3D& v)
	{
		vec3.at(0) *= v.vec3.at(0);
		vec3.at(1) *= v.vec3.at(1);
		vec3.at(2) *= v.vec3.at(2);
		return *this;
	}

	Vector3D& Vector3D::operator*=(const double& t)
	{
		vec3.at(0) *= t;
		vec3.at(1) *= t;
		vec3.at(2) *= t;
		return *this;
	}

	Vector3D& Vector3D::operator/=(const double& t)
	{
		vec3.at(0) /= t;
		vec3.at(1) /= t;
		vec3.at(2) /= t;
		return *this;
	}

	Vector3D& Vector3D::operator/=(const Vector3D& v)
	{
		vec3.at(0) /= v.vec3.at(0);
		vec3.at(1) /= v.vec3.at(1);
		vec3.at(2) /= v.vec3.at(2);
		return *this;
	}

	void Vector3D::MakeUnitVector()
	{
		double k = 1.0 / sqrt(vec3.at(0) * vec3.at(0) + vec3.at(1) * vec3.at(1) + vec3.at(2) * vec3.at(2));
		vec3.at(0) *= k;
		vec3.at(1) *= k;
		vec3.at(2) *= k;
	}

	double Vector3D::Length() const
	{
		return sqrt(vec3.at(0) * vec3.at(0) + vec3.at(1) * vec3.at(1) + vec3.at(2) * vec3.at(2));
	}

	double Vector3D::SquareLength() const
	{
		return vec3.at(0) * vec3.at(0) + vec3.at(1) * vec3.at(1) + vec3.at(2) * vec3.at(2);
	}
}