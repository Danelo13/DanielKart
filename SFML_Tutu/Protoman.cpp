#include "stdafx.h"
#include "Protoman.h"

CDoll::CDoll(Vector2f newOrigin, Color newColor, vector<float> newScale)
{
	Posicion = newOrigin;
	theColor = newColor;
	escalar = newScale;

	vector<float> Pos1 = { 0,0,0,1 };
	vector<float> Pos2 = { 1,0,0,1 };
	vector<float> dir = { 1,0,0,1 };
	vector<float> t_5 = { .5,1,1,1 };
	vector<float> t_8 = { .8f,1,1,1 };
	vector<float> t_15 = { 1.5,1,1,1 };

	//estomago
	Piece[0].Set(NULL, Pos1, Pos2, newColor);
	Piece[0].SetRotacion(-90, 0, 0);
	Piece[0].SetTraslacion(dir);

	//pecho
	Piece[9].Set(&Piece[0], Pos1, Pos2, newColor);
	Piece[9].SetTraslacion(dir);
	
	//pierna derecha
	Piece[1].Set(&Piece[0], Pos1, Pos2, newColor);
	Piece[1].SetRotacion(-90, 0, 0);
	Piece[1].SetScalacion(t_5);

	Piece[2].Set(&Piece[1], Pos1, Pos2, newColor);
	Piece[2].SetRotacion(-90, 0, 0);
	Piece[2].SetTraslacion(dir);
	Piece[2].SetScalacion(t_15);

	Piece[3].Set(&Piece[2], Pos1, Pos2, newColor);
	Piece[3].SetTraslacion(dir);
	Piece[3].SetScalacion(t_15);

	Piece[4].Set(&Piece[3], Pos1, Pos2, newColor);
	Piece[4].SetRotacion(90, 0, 0);
	Piece[4].SetTraslacion(dir);
	Piece[4].SetScalacion(t_5);
	
	//pierna izquierda
	Piece[5].Set(&Piece[0], Pos1, Pos2, newColor);
	Piece[5].SetRotacion(90, 0, 0);
	Piece[5].SetScalacion(t_5);

	Piece[6].Set(&Piece[5], Pos1, Pos2, newColor);
	Piece[6].SetRotacion(90, 0, 0);
	Piece[6].SetTraslacion(dir);
	Piece[6].SetScalacion(t_15);

	Piece[7].Set(&Piece[6], Pos1, Pos2, newColor);
	Piece[7].SetTraslacion(dir);
	Piece[7].SetScalacion(t_15);

	Piece[8].Set(&Piece[7], Pos1, Pos2, newColor);
	Piece[8].SetRotacion(-90, 0, 0);
	Piece[8].SetTraslacion(dir);
	Piece[8].SetScalacion(t_5);

	//brazo derecho
	Piece[10].Set(&Piece[9], Pos1, Pos2, newColor);
	Piece[10].SetRotacion(-90, 0, 0);
	Piece[10].SetTraslacion(dir);
	Piece[10].SetScalacion(t_8);

	Piece[11].Set(&Piece[10], Pos1, Pos2, newColor);
	Piece[11].SetRotacion(-80, 0, 0);
	Piece[11].SetTraslacion(dir);

	Piece[12].Set(&Piece[11], Pos1, Pos2, newColor);
	Piece[12].SetRotacion(-10, 0, 0);
	Piece[12].SetTraslacion(dir);
		   
	Piece[13].Set(&Piece[12], Pos1, Pos2, newColor);
	Piece[13].SetRotacion(-10, 0, 0);
	Piece[13].SetTraslacion(dir);
	Piece[13].SetScalacion(t_5);

	//brazo izquierdo
	Piece[14].Set(&Piece[9], Pos1, Pos2, newColor);
	Piece[14].SetRotacion(90, 0, 0);
	Piece[14].SetTraslacion(dir);
	Piece[14].SetScalacion(t_8);

	Piece[15].Set(&Piece[14], Pos1, Pos2, newColor);
	Piece[15].SetRotacion(80, 0, 0);
	Piece[15].SetTraslacion(dir);

	Piece[16].Set(&Piece[15], Pos1, Pos2, newColor);
	Piece[16].SetRotacion(10, 0, 0);
	Piece[16].SetTraslacion(dir);

	Piece[17].Set(&Piece[16], Pos1, Pos2, newColor);
	Piece[17].SetRotacion(10, 0, 0);
	Piece[17].SetTraslacion(dir);
	Piece[17].SetScalacion(t_5);

	//Cabeza
	Piece[18].Set(&Piece[9], Pos1, Pos2, newColor);
	Piece[18].SetTraslacion(dir);
	Piece[18].SetScalacion(t_5);

	Piece[19].Set(&Piece[18], Pos1, Pos2, newColor);
	Piece[19].SetRotacion(45, 0, 0);
	Piece[19].SetTraslacion(dir);
	Piece[19].SetScalacion(t_5);

	Piece[20].Set(&Piece[18], Pos1, Pos2, newColor);
	Piece[20].SetRotacion(-45, 0, 0);
	Piece[20].SetTraslacion(dir);
	Piece[20].SetScalacion(t_5);

	Piece[21].Set(&Piece[19], Pos1, Pos2, newColor);
	Piece[21].SetRotacion(-90, 0, 0);
	Piece[21].SetTraslacion(dir);
	Piece[21].SetScalacion(t_5);

	Piece[22].Set(&Piece[20], Pos1, Pos2, newColor);
	Piece[22].SetRotacion(90, 0, 0);
	Piece[22].SetTraslacion(dir);
	Piece[22].SetScalacion(t_5);

	for (int i = 0; i < 23; i++)
	{
		Piece[i].SetScalacion(escalar);
	}
}

void CDoll::draw(RenderWindow &window)
{
	for (int i = 0; i < 23; i++)
	{
		Piece[i].draw(window, Posicion);
	}
}

void CDoll::Reset()
{
	//estomago
	Piece[0].SetRotacion(-90, 0, 0);

	//pecho
	Piece[9].SetRotacion(0, 0, 0);

	//pierna derecha
	Piece[1].SetRotacion(-90, 0, 0);
	
	Piece[2].SetRotacion(-90, 0, 0);

	Piece[3].SetRotacion(0, 0, 0);

	Piece[4].SetRotacion(90, 0, 0);

	//pierna izquierda
	Piece[5].SetRotacion(90, 0, 0);

	Piece[6].SetRotacion(90, 0, 0);

	Piece[7].SetRotacion(0, 0, 0);

	Piece[8].SetRotacion(-90, 0, 0);

	//brazo derecho
	Piece[10].SetRotacion(-90, 0, 0);

	Piece[11].SetRotacion(-80, 0, 0);

	Piece[12].SetRotacion(-10, 0, 0);

	Piece[13].SetRotacion(-10, 0, 0);

	//brazo izquierdo
	Piece[14].SetRotacion(90, 0, 0);

	Piece[15].SetRotacion(80, 0, 0);

	Piece[16].SetRotacion(10, 0, 0);

	Piece[17].SetRotacion(10, 0, 0);

	//Cabeza
	Piece[18].SetRotacion(0, 0, 0);

	Piece[19].SetRotacion(45, 0, 0);

	Piece[20].SetRotacion(-45, 0, 0);

	Piece[21].SetRotacion(-90, 0, 0);

	Piece[22].SetRotacion(90, 0, 0);
}

void CDoll::Rotate(int i, float z, float y, float x)
{
	Piece[i].SetRotacion(z, y, x);
}

void CDoll::Pose1() {
	Piece[1].SetRotacion(-90, 0, 0);

	Piece[2].SetRotacion(-80, 0, 0);

	Piece[3].SetRotacion(-20, 0, 0);

	Piece[4].SetRotacion(100, 0, 0);

	//pierna izquierda
	Piece[5].SetRotacion(90, 0, 0);

	Piece[6].SetRotacion(80, 0, 0);

	Piece[7].SetRotacion(20, 0, 0);

	Piece[8].SetRotacion(-100, 0, 0);

	// brazo derecho
	Piece[10].SetRotacion(-100, 0, 0);

	Piece[11].SetRotacion(-70, 0, 0);

	Piece[14].SetRotacion(100, 0, 0);

	Piece[15].SetRotacion(70, 0, 0);

	Piece[18].SetRotacion(0, 30, 0);
}  // idle boop
void CDoll::Pose2() {
	//brazo derecho
	Piece[10].SetRotacion(-70, 0, 0);

	Piece[11].SetRotacion(50, 0, 0);

	Piece[12].SetRotacion(-10, 0, 0);

	Piece[13].SetRotacion(45, 0, 0);
}
void CDoll::Pose3() {
	Piece[14].SetRotacion(70, 0, 0);

	Piece[15].SetRotacion(-50, 0, 0);

	Piece[16].SetRotacion(-10, 0, 0);

	Piece[17].SetRotacion(-45, 0, 0);
}
void CDoll::Pose4() {
	Piece[1].SetRotacion(-70, 0, 0);

	Piece[2].SetRotacion(-100, 0, 0);

	Piece[3].SetRotacion(-20, 0, 0);

	Piece[4].SetRotacion(100, 0, 0);

	//pierna izquierda
	Piece[5].SetRotacion(70, 0, 0);

	Piece[6].SetRotacion(100, 0, 0);

	Piece[7].SetRotacion(20, 0, 0);

	Piece[8].SetRotacion(-100, 0, 0);
}
void CDoll::Pose5() {
	Piece[1].SetRotacion(-70, 0, 10);

	Piece[2].SetRotacion(-80, 45, 0);

	Piece[3].SetRotacion(-40, -90, 0);

	Piece[4].SetRotacion(100, 0, 0);

	//pierna izquierda
	Piece[5].SetRotacion(70, 0, 10);

	Piece[6].SetRotacion(80, 45, 0);

	Piece[7].SetRotacion(40, -90, 0);

	Piece[8].SetRotacion(-100, 0, 0);
}

CDoll::CDoll()
{
}

CDoll::~CDoll() {

}