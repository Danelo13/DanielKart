#pragma once
#include "Segmento.h"
class CDoll
{
private:
	CSegment Piece[23];
	Vector2f Posicion;
	Color theColor;
	vector<float> escalar;
public:

	CDoll();
	CDoll(Vector2f newOrigin, Color newColor, vector<float> newScale);
	void draw(RenderWindow &window);
	void Reset();
	void Rotate(int i, float z, float y, float x);

	void Pose1(); // idle boop
	void Pose2(); // Left arm raise
	void Pose3(); // Right arm Raise
	void Pose4(); // Pre-Jump
	void Pose5(); // Jump?
	~CDoll();
};

