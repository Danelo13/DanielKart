#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include <math.h>
using namespace sf;
using namespace std;

#define PI 3.14159265

class CMatrix
{
protected:
	float M[4][4];
public:
	CMatrix identity();
	CMatrix traslacion(vector<float> &direccion);
	CMatrix escalacion(vector<float> &tamaño);
	CMatrix RotacionX(float theta);
	CMatrix RotacionY(float theta);
	CMatrix RotacionZ(float theta);
	CMatrix Scale(CMatrix &scalefather);
	void imprimir();
	vector <float> operator*(vector<float> &vec);
	CMatrix operator*(CMatrix &matrix);
	CMatrix();
	~CMatrix();
};

