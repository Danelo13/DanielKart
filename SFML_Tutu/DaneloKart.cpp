

#include "stdafx.h"
#include "Protoman.h"
#include <ctime>

float lerp(float flGoal, float flCurrent, float dt, float Escala)
{
	float flDifference = flGoal - flCurrent;

	if (flDifference > (dt*Escala))
	{
		return flCurrent + (dt)*Escala;
	}
	if (flDifference < -(dt*Escala))
	{
		return flCurrent - (dt)*Escala;
	}
	return flGoal;
}



int main()
{
	RenderWindow window(VideoMode(1000, 1000), "Inteligencia Artificial");


	Vector2f origenp(500, 500);

	vector <float> nscale = { 50,50,1,1 };


	// CTron Player(origenp, Color::White, nscale);


	// Player.Reset();

	int cuadro = 0;
	sf:Clock clock;
	Time Tiempo;
	float DT = 0.1f;
	bool jump = false;

	while (window.isOpen())
	{
		Event event;
		
		Tiempo = clock.getElapsedTime();

		if (Tiempo.asSeconds() > DT) {
			clock.restart();
			
			if (cuadro < 15) {
				cuadro++;
			}
			else {
				cuadro = 0;
			}
		}


		

		

		while (window.pollEvent(event))
		{
			//if (event.type == Event::Closed)
			//{
			//	window.close();
			//}
			//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			//{
			//	Player.MoveLeft();
			//}
			//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			//{
			//	Player.MoveRight();
			//}
			//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			//{
			//	Player.SkipJump();
			//	jump = true;
			//}

		}

		window.clear();

		//Player.draw(window);

		window.display();
	}
	return 0;
}