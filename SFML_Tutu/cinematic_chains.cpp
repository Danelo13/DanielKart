// cinematic_chains.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Protoman.h"


int main()
{
	RenderWindow window(VideoMode(1000, 1000), "lines everywere");
	Vector2f origen(500, 500);
	vector <float> nscale = { 50,50,1,1 };
	CProtoman mijo(origen, Color::White, nscale);

	
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}
		window.clear();
		mijo.draw(window);
		window.display();
	}
	return 0;
}