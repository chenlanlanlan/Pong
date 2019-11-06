//#pragma once
//#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>
//#include <SFML/System.hpp>
//#include "Paddle.h"
//
//using namespace sf;
//
//class Paddle : public Shape
//{
//public:
//	Paddle();
//	~Paddle();
//
//private:
//	Vector2f paddleSize = Vector2f(25.f, 100.f);
//	float paddleX;
//	float paddleY;
//};
//
//Paddle::Paddle()
//{
//	RectangleShape paddle;
//	paddle.setSize(paddleSize - Vector2f(3, 3));
//	paddle.setOutlineThickness(3);
//	paddle.setOutlineColor(sf::Color::Black);
//	paddle.setFillColor(sf::Color(100, 100, 200));
//	paddle.setOrigin(paddleSize / 2.f);
//}
//
//Paddle::~Paddle()
//{
//}