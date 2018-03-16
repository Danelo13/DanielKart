
#include "Auxiliar.h"
#include <iostream>
#include <string>
#include <SFML\Graphics.hpp>

using namespace std;
using namespace sf;

void Auxiliar::Draw() {
	xMouseCoord.setString(to_string(theMouse.getPosition(theWindow).x));
	yMouseCoord.setString(to_string(theMouse.getPosition(theWindow).y));
	theWindow.draw(xMouseCoord);
	theWindow.draw(yMouseCoord);
}

Auxiliar::Auxiliar(RenderWindow& newWindow, Mouse& newMouse) :
	theWindow(newWindow), theMouse(newMouse)
{
	FontColor.r = 0;
	FontColor.g = 255;
	FontColor.b = 0;
	xMouseCoord.setFont(d_font);
	yMouseCoord.setFont(d_font);
	yMouseCoord.setFillColor(FontColor);
	xMouseCoord.setFillColor(FontColor);
	xMouseCoord.setCharacterSize(16);
	yMouseCoord.setCharacterSize(16);
	xMouseCoord.setPosition(1800, 930);
	yMouseCoord.setPosition(1850, 930);
	if (!d_font.loadFromFile("arial.ttf"))
		cout << "Error: Font no encontrada en Clase Auxiliar" << endl;
}


Auxiliar::~Auxiliar()
{
}
