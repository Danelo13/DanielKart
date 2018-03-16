#pragma once
#include "Matrix.h"
class CSegment
{
private:
	vector<float> P1 = { 0,0,0,1 };
	vector<float> P2 = { 0,0,0,1 };
	CSegment* Padre;
	CMatrix Traslacion, Rotacion, Escalacion;
	Color LineColor;
public:
	CMatrix GetMatrix();
	void SetTraslacion(vector<float> direccion);
	void SetScalacion(vector<float> tamaño);
	void SetRotacion(float z, float y, float x);
	void draw(RenderWindow &window, Vector2f origin);
	void imprimir();
	void Set(CSegment* newPadre, vector<float> p1, vector<float> p2, Color newColor);
	CSegment();
	CSegment(CSegment* newPadre, vector<float> p1, vector<float> p2, Color newColor);
	~CSegment();
};

