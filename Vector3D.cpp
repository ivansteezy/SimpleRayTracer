#include "Vector3D.h"

namespace Ray
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

	std::istream& operator>>(std::istream& is, const Vector3D& t)
	{
		//is >> t.vec3.at(0) >> t.vec3.at(1) >> t.vec3.at(2); /*TODO*/
		return is;
	}

	std::ostream& operator<<(std::ostream& os, const Vector3D& t)
	{
		os << t.vec3.at(0) << t.vec3.at(1) << t.vec3.at(2);
		return os;
	}

	Vector3D operator+(const Vector3D& v1, const Vector3D& v2)
	{
		return Vector3D(v1.vec3.at(0) + v2.vec3.at(0), v1.vec3.at(1) + v2.vec3.at(1), v1.vec3.at(2) + v2.vec3.at(2));
	}

	Vector3D operator-(const Vector3D& v1, const Vector3D& v2)
	{
		return Vector3D(v1.vec3.at(0) - v2.vec3.at(0), v1.vec3.at(1) - v2.vec3.at(1), v1.vec3.at(2) - v2.vec3.at(2));
	}

	Vector3D operator*(const Vector3D& v1, const Vector3D& v2)
	{
		return Vector3D(v1.vec3.at(0) * v2.vec3.at(0), v1.vec3.at(1) * v2.vec3.at(1), v1.vec3.at(2) * v2.vec3.at(2));
	}

	Vector3D operator/(const Vector3D& v1, const Vector3D& v2)
	{
		return Vector3D(v1.vec3.at(0) / v2.vec3.at(0), v1.vec3.at(1) / v2.vec3.at(1), v1.vec3.at(2) / v2.vec3.at(2));
	}

	Vector3D operator*(double t, const Vector3D& v)
	{
		return Vector3D(t * v.vec3.at(0), t * v.vec3.at(1), t * v.vec3.at(2));
	}

	Vector3D operator/(Vector3D v, double t)
	{
		return Vector3D(v.vec3.at(0) / t, v.vec3.at(1) / t, v.vec3.at(2) / t);
	}

	Vector3D UnitVector(Vector3D v)
	{
		return v / v.Length();
	}

	double DotProduct(const Vector3D& v1, const Vector3D& v2)
	{
		return v1.vec3.at(0) * v2.vec3.at(0) + v1.vec3.at(1) * v2.vec3.at(1) + v1.vec3.at(2) * v2.vec3.at(2);
	}

	Vector3D CrossProduct(const Vector3D& v1, const Vector3D& v2)
	{
		return Vector3D(  (v1.vec3.at(1) * v2.vec3.at(2) - v1.vec3.at(2) * v1.vec3.at(1)),
						(-(v1.vec3.at(0) * v2.vec3.at(2) - v1.vec3.at(2) * v1.vec3.at(0))),
						( (v1.vec3.at(0) * v2.vec3.at(1) - v1.vec3.at(1) * v2.vec3.at(0))));
	}
}