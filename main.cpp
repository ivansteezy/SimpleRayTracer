#include "Vector3D.h"

int main()
{
	int nx = 200;
	int ny = 100;

	std::ofstream myfile;
	myfile.open("image.ppm");
	myfile << "P3\n" << nx << " " << ny << "\n255\n";

	for (int j = ny - 1; j >= 0; j--)
	{
		for (int i = 0; i < nx; i++)
		{
			Ray::Vector3D col(static_cast<double>(i) / static_cast<double>(nx), static_cast<double>(j) / static_cast<double>(ny), 0.2);

			int ir = static_cast<int>(255.9 * col[0]);
			int ig = static_cast<int>(255.9 * col[1]);
			int ib = static_cast<int>(255.9 * col[2]);
			myfile << ir << " " << ig << " " << ib << "\n";
		}
	}
	return 0;
}