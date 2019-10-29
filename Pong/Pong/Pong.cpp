#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Ball.cpp"

using namespace std;
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(800, 600), "GAME-230 Pong!", Style::Close);
	window.setVerticalSyncEnabled(true);

	Vector2f paddleSize = Vector2f(25.f, 100.f);
	Ball ball;
	sf::RectangleShape leftPaddle;
	leftPaddle.setSize(paddleSize - sf::Vector2f(3, 3));
	leftPaddle.setOutlineThickness(3);
	leftPaddle.setOutlineColor(sf::Color::Blue);
	leftPaddle.setFillColor(sf::Color(100, 100, 200));
	leftPaddle.setOrigin(paddleSize / 2.f);
	leftPaddle.setPosition(20, 300);

	sf::RectangleShape rightPaddle;
	rightPaddle.setSize(paddleSize - sf::Vector2f(3, 3));
	rightPaddle.setOutlineThickness(3);
	rightPaddle.setOutlineColor(sf::Color::Green);
	rightPaddle.setFillColor(sf::Color(200, 100, 100));
	rightPaddle.setOrigin(paddleSize / 2.f);
	rightPaddle.setPosition(780, 300);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(leftPaddle);
		//window.draw(ball);
		window.draw(rightPaddle);
		window.display();
	}

	return 0;
}
