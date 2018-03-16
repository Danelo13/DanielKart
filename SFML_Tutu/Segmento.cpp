#include "stdafx.h"
#include "Segmento.h"

void print_vector(vector<float> vec)
{
	cout << endl << "vector x: " << vec[0]
		<< endl << "vector y: " << vec[1]
		<< endl << "vector z: " << vec[2]<<endl;
}

CMatrix CSegment::GetMatrix()
{
	if (Padre == NULL)
	{
		return (Traslacion*Rotacion);
	}
	else
	{
		CMatrix newtras = Traslacion.Scale(Padre->Escalacion);
		return((Padre->GetMatrix())*(newtras*Rotacion));
	}
}

void CSegment::imprimir()
{
	if (Padre == NULL)
	{
		cout << "TR:" << endl;
		((Traslacion*Rotacion)*Escalacion).imprimir();
	}
	else
	{
		cout << "PTR:" << endl;
		CMatrix newtras = Traslacion.Scale(Padre->Escalacion);
		(((Padre->GetMatrix())*(newtras*Rotacion))*Escalacion).imprimir();
	}
	cout << endl << "imprimiendo puntos:" << endl;
	vector<float> P1aux = { 0,0,0,1 };
	vector<float> P2aux = { 0,0,0,1 };

	if (Padre == NULL)
	{
		P1aux = ((Traslacion*Rotacion)*Escalacion)*P1;
		P2aux = ((Traslacion*Rotacion)*Escalacion)*P2;
	}
	else
	{
		CMatrix newtras = Traslacion.Scale(Padre->Escalacion);
		P1aux = (((Padre->GetMatrix())*(newtras*Rotacion))*Escalacion)*P1;
		P2aux = (((Padre->GetMatrix())*(newtras*Rotacion))*Escalacion)*P2;
	}
	print_vector(P1aux);
	print_vector(P2aux);
}

void CSegment::draw(RenderWindow & window, Vector2f origin)
{
	VertexArray Line(LineStrip, 2);
	for (int i = 0; i < 2; i++)
	{
		Line[i].color = LineColor;
	}
	vector<float> P1aux = { 0,0,0,1 };
	vector<float> P2aux = { 0,0,0,1 };

	if (Padre == NULL)
	{
		P1aux = ((Traslacion*Rotacion)*Escalacion)*P1;
		P2aux = ((Traslacion*Rotacion)*Escalacion)*P2;
	}
	else
	{
		CMatrix newtras = Traslacion.Scale(Padre->Escalacion);
		P1aux = (((Padre->GetMatrix())*(newtras*Rotacion))*Escalacion)*P1;
		P2aux = (((Padre->GetMatrix())*(newtras*Rotacion))*Escalacion)*P2;
	}
	Line[0].position.x = P1aux[0] + origin.x;
	Line[0].position.y = P1aux[1] + origin.y;
	Line[1].position = Vector2f(P2aux[0] + origin.x, P2aux[1] + origin.y);

	window.draw(Line);
}

CSegment::CSegment(CSegment * newPadre, vector<float> p1, vector<float> p2, Color newColor)
{
	Padre = newPadre;
	P1 = p1;
	P2 = p2;
	LineColor = newColor;
	Traslacion = Traslacion.identity();
	Rotacion = Rotacion.identity();
	Escalacion = Escalacion.identity();
}

void CSegment::SetTraslacion(vector<float> direccion)
{
	Traslacion = Traslacion.traslacion(direccion);
	
}

void CSegment::SetScalacion(vector<float> tamaño)
{
	Escalacion = Escalacion.escalacion(tamaño);
	
}

void CSegment::SetRotacion(float z, float y, float x)
{
	Rotacion = Rotacion.RotacionZ(z)*Rotacion.RotacionY(y)*Rotacion.RotacionX(x);
}


void CSegment::Set(CSegment * newPadre, vector<float> p1, vector<float> p2, Color newColor)
{
	Padre = newPadre;
	P1 = p1;
	P2 = p2;
	LineColor = newColor;

}

CSegment::CSegment()
{
	Padre = NULL;
	Traslacion = Traslacion.identity();
	Rotacion = Rotacion.identity();
	Escalacion = Escalacion.identity();
}

CSegment::~CSegment()
{
}






