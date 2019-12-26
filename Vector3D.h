#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <iostream>
#include <vector> //for std::vector
#include <istream> //for std::istream
#include <fstream>

namespace Ray
{
	class Vector3D
	{
	public:
		std::vector<double> vec3;

	public:
		Vector3D() {}
		Vector3D(double e0, double e1, double e2);

		//Getter's
		double x() const { return vec3.at(0); }
		double y() const { return vec3.at(1); }
		double z() const { return vec3.at(2); }
		double r() const { return vec3.at(0); }
		double g() const { return vec3.at(1); }
		double b() const { return vec3.at(2); }

		//Some overloads
		const Vector3D& operator+() const { return *this; }
		Vector3D operator-() const { return Vector3D(-vec3.at(0), -vec3.at(1), -vec3.at(2)); }
		double operator[](int i) const { return vec3.at(i); }
		double& operator[](int i) { return vec3.at(i); }

		Vector3D& operator+=(const Vector3D& vecRes);
		Vector3D& operator-=(const Vector3D& vecRes);
		Vector3D& operator*=(const Vector3D& vecRes);
		Vector3D& operator/=(const Vector3D& vecRes);

		Vector3D& operator*=(const double& t);
		Vector3D& operator/=(const double& t);

		double Length() const;
		double SquareLength() const;
		void MakeUnitVector();
	};
}

#endif 
