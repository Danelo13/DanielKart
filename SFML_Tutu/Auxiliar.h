#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;

class Auxiliar
{
private:
	RenderWindow& theWindow;
	Mouse& theMouse;
	Font d_font;
	Color FontColor;
	Text xMouseCoord, yMouseCoord;
public:
	void Draw();
	Auxiliar(RenderWindow& newWindow, Mouse& newMouse);
	~Auxiliar();
};

