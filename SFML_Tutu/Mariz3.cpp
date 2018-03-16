
#include "Matriz3.h"

Matriz3::Matriz3()
{
	x0 = x1 = x2 = x3 = y0 = y1 = y2 = y3 = z0 = z1 = z3 = w0 = w1 = w2 = 0;
	z2 = w3 = 1;
}

Matriz3::~Matriz3()
{
}

Matriz3 Matriz3::Identidad()
{
	Matriz3 I;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			I.m[j][i] = (i == j) ? 1 : 0;
		}
	}
	return I;
}

Matriz3 Matriz3::Translacion(float dx, float dy, float dz)
{
	Matriz3 T = Identidad();
	T.tras = { dx,dy,dz,1 };
	T.x3 = dx;
	T.y3 = dy;
	T.z3 = dz;
	return T;
}

Matriz3 Matriz3::RotacionX(float a)
{
	Matriz3 R = Identidad();
	a *= (M_PI / 180);
	R.angle = a;
	R.y1 = R.z2 = cos(a);
	if (R.y1 < 0.0001 && R.z2 < 0.0001)
	{
		R.x0 = R.y1 = 0;
	}
	R.y2 = -sin(a);
	R.z1 = sin(a);
	return R;
}

Matriz3 Matriz3::RotacionY(float a)
{
	Matriz3 R = Identidad();
	a *= (M_PI / 180);
	R.angle = a;
	R.x0 = R.z2 = cos(a);
	if (R.x0 < 0.0001 && R.z2 < 0.0001)
	{
		R.x0 = R.y1 = 0;
	}
	R.x2 = sin(a);
	R.z0 = -sin(a);
	return R;
}

Matriz3 Matriz3::RotacionZ(float a)
{
	Matriz3 R = Identidad();
	a *= (M_PI / 180);
	R.angle = a;
	R.x0 = R.y1 = cos(a);
	if (R.x0 < 0.0001 && R.y1 < 0.0001)
	{
		R.x0 = R.y1 = 0;
	}
	R.x1 = -sin(a);
	R.y0 = sin(a);
	return R;
}

Matriz3 Matriz3::Escala(float ex, float ey, float ez)
{
	Matriz3 E = Identidad();
	E.x0 = ex;
	E.y1 = ey;
	E.z2 = ez;
	return E;
}

void Matriz3::Impresion()
{
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			cout << m[i][j] << ", ";
		}
		cout << endl;
	}
	cout << endl;
}

Matriz3 operator*(Matriz3 & A, Matriz3 & B)
{
	Matriz3 R;
	R.z2 = R.w3 = 0;
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int k = 0; k < 4; k++)
			{
				R.m[j][i] += A.m[j][k] * B.m[k][i];
			}
		}
	}
	return R;
}

Vector_3 operator*(Matriz3 & A, Vector_3 & V)
{
	Vector_3 R = { 0, 0, 0, 0 };
	R.ix = V.ix;
	R.iy = V.iy;
	R.iz = V.iz;
	R.iw = V.iw;
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			R.v[j] += A.m[j][i] * V.v[i];
		}
	}
	return R;
}

Vector_3 operator*(Vector_3 & V, Matriz3 & A)
{
	Vector_3 R = { 0, 0, 0, 0 };
	R.ix = V.ix;
	R.iy = V.iy;
	R.iz = V.iz;
	R.iw = V.iw;
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			R.v[j] += A.m[j][i] * V.v[i];
		}
	}
	return R;
}

void Impresion(Vector_3 & V)
{
	for (int i = 0; i < 4; i++)
	{
		cout << V.v[i] << ", ";
	}
	cout << endl << endl;
}
