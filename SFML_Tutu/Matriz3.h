#pragma once
#include <math.h>
#include <iostream>
#include <vector>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#define M_PI 3.141592

using namespace std;

struct Vector_3
{

	union
	{
		struct
		{

			float x, y, z, w;
		};
		float v[4];
	};
	float ix, iy, iz, iw;
	void Assign()
	{
		ix = x;
		iy = y;
		iz = z;
		iw = w;
	}
	void Initials()
	{
		x = ix;
		y = iy;
		z = iz;
		w = iw;
	}
};

class Matriz3
{
public:
	float angle;
	Vector_3 tras;
	struct
	{
		union
		{
			struct
			{
				float x0, x1, x2, x3;
				float y0, y1, y2, y3;
				float z0, z1, z2, z3;
				float w0, w1, w2, w3;
			};
			float m[4][4];
			Vector_3 vec[4];
			float v[16];
		};
	};

	Matriz3();
	~Matriz3();

	Matriz3 Identidad();
	Matriz3 Translacion(float dx, float dy, float dz);
	Matriz3 RotacionX(float a);
	Matriz3 RotacionY(float a);
	Matriz3 RotacionZ(float a);
	Matriz3 Escala(float ex, float ey, float ez);

	void Impresion();

private:

};

Matriz3 operator*(Matriz3& A, Matriz3& B);
Vector_3 operator*(Matriz3& A, Vector_3& V);
Vector_3 operator*(Vector_3& V, Matriz3& A);
void Impresion(Vector_3& V);