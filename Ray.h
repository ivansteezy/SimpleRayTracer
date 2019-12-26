#ifndef RAY_H
#define RAY_H
#include "Vector3D.h"
#include "Calculations.h"

namespace Raytracing
{
	class Ray
	{
	public:
		Vector3D A;
		Vector3D B;

	public:
		Ray() {}
		Ray(const Vector3D& a, const Vector3D& b) { A = a; B = b; }
		Vector3D Origin() const { return A; }
		Vector3D Direction() const { return B; }
		Vector3D PointAtParameter(double t) const { return A + t * B; }
	};
}

#endif 
