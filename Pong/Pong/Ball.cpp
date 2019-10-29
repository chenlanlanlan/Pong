#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

using namespace sf;

class Ball : public CircleShape
{
public:
	Ball();
//	~Ball();
	float ballX;
	float ballY;
	float speed;
	int direction;

private:
	const float ballRadius = 10.f;
};

Ball::Ball()
{
	this->setRadius(ballRadius);
	ballX = 400;
	ballY = 300;
	this->setOutlineThickness(3);
	this->setOutlineColor(Color::White);
	this->setFillColor(Color::White);
	this->setOrigin(ballRadius / 2, ballRadius / 2);
}

//Ball::~Ball()
//{
//}
