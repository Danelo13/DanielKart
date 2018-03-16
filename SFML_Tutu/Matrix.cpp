#include "stdafx.h"
#include "Matrix.h"


CMatrix CMatrix::identity()
{
	CMatrix id;
	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			id.M[row][col] = ((col == row) ? 1 : 0);
			//cout << id.M[row][col];
		}
		//cout << endl;
	}
	return id;
}

CMatrix CMatrix::escalacion(vector<float>& tamaño)
{
	CMatrix scale;
	scale = scale.identity();
	scale.M[0][0] = M[0][0] * tamaño[0];
	scale.M[1][1] = M[1][1] * tamaño[1];
	scale.M[2][2] = M[2][2] * tamaño[2];
	return scale;
}

CMatrix CMatrix::Scale(CMatrix &scalefather)
{
	CMatrix res;
	res = res.identity();
	res.M[0][3] = M[0][3] * scalefather.M[0][0];
	res.M[1][3] = M[1][3] * scalefather.M[1][2];
	res.M[2][3] = M[2][3] * scalefather.M[2][2];
	return res;
}

CMatrix CMatrix::traslacion(vector<float>& direccion)
{
	CMatrix tras;
	tras = tras.identity();
	tras.M[0][3] = direccion[0];
	tras.M[1][3] = direccion[1];
	tras.M[2][3] = direccion[2];
	return tras;
}

CMatrix CMatrix::RotacionZ(float theta)
{
	CMatrix rot_z;
	rot_z = rot_z.identity();
	theta = theta*(PI / 180);
	rot_z.M[0][0] = rot_z.M[1][1] = cos(theta);
	rot_z.M[1][0] = sin(theta);
	rot_z.M[0][1] = -sin(theta);
	return rot_z;
}

CMatrix CMatrix::RotacionY(float theta)
{
	CMatrix rot_y;
	rot_y = rot_y.identity();
	theta = theta*(PI / 180);
	rot_y.M[0][0] = rot_y.M[2][2] = cos(theta);
	rot_y.M[0][2] = sin(theta);
	rot_y.M[2][0] = -sin(theta);
	return rot_y;
}

CMatrix CMatrix::RotacionX(float theta)
{
	CMatrix rot_x;
	rot_x = rot_x.identity();
	theta = theta*(PI / 180);
	rot_x.M[1][1] = rot_x.M[2][2] = cos(theta);
	rot_x.M[2][1] = sin(theta);
	rot_x.M[1][2] = -sin(theta);
	return rot_x;
}

void CMatrix::imprimir()
{
	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			cout << M[row][col] << "	";
		}
		cout << endl;
	}
}

vector<float> CMatrix::operator*(vector<float>& vec)
{
	vector<float> res = { 0,0,0,0 };
	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			res[row] += M[row][col] * vec[col];
		}
	}
	return res;
}

CMatrix CMatrix::operator*(CMatrix & matrix)
{
	CMatrix res;
	for (int row = 0; row < 4; row++)
	{
		for(int col=0;col<4;col++)
		{
			for (int it = 0; it < 4; it++)
			{
				res.M[row][col] += M[row][it] * matrix.M[it][col];
			}
		}
	}
	return res;
}

CMatrix::CMatrix()
{
	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			M[row][col] = 0;
		}
	}
}


CMatrix::~CMatrix()
{
}
