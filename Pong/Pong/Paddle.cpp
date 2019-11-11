#pragma once
#include <iostream>
#include "Paddle.h"

using namespace sf;

Paddle::Paddle(Vector2f position)
{
	this->paddleSize = Vector2f(20.f, 100.f);
	this->origin = this->paddleSize / 2.f;
	this->paddleColor = Color::White;
	this->position = position;
	player_Paddle.setSize(paddleSize);
	player_Paddle.setOrigin(origin);
	player_Paddle.setFillColor(paddleColor);
	player_Paddle.setPosition(position);
	sb.loadFromFile(PADDLE_SOUND);
	paddleSound.setBuffer(sb);
}

void Paddle::drawPaddle(RenderWindow& window)
{
	//std::cout << "Draw a paddle! /n";
	window.draw(player_Paddle);
}

void Paddle::player1Input(Keyboard::Key key, Time dt) 
{	
	if (Keyboard::isKeyPressed(Keyboard::Up)) {
		//move up
		this->velocity = Vector2f(0.f, -100.f* SPEED);
		this->updatePlayer(dt, this->velocity);
		
	}
	else if (Keyboard::isKeyPressed(Keyboard::Down)) {
		//move down
		this->velocity = Vector2f(0.f, 100.f * SPEED);
		this->updatePlayer(dt, this->velocity);
	}
}

void Paddle::player2Input(Keyboard::Key key, Time dt)
{
	 if (Keyboard::isKeyPressed(Keyboard::W)) {
		//move up
		this->velocity = Vector2f(0.f, -100.f * SPEED);
		this->updatePlayer(dt, this->velocity);
	}
	else if (Keyboard::isKeyPressed(Keyboard::S)) {
		//move down
		this->velocity = Vector2f(0.f, 100.f * SPEED);
		this->updatePlayer(dt, this->velocity);
	}
}

void Paddle::updatePlayer(Time dt, Vector2f velocity)
{
	std::cout << "KeyPressed! \n";
	paddleSound.play();
	Vector2f pos = player_Paddle.getPosition();
	player_Paddle.move(velocity * dt.asSeconds());
	if (isCollidedTop()) {
		player_Paddle.setPosition(pos.x, player_Paddle.getOrigin().y);
		std::cout << "Position y : " << pos.y << "\n";
	}
	else if(isCollideBottom()) {
		player_Paddle.setPosition(pos.x, 600 - player_Paddle.getOrigin().y);
		std::cout << "Position y : " << pos.y << "\n";
	}
}

bool Paddle::isCollidedTop()
{
	Vector2f pos = player_Paddle.getPosition();
	if (pos.y - this->origin.y < 0) {
		return true;
	}
	return false;
}

bool Paddle::isCollideBottom() 
{
	Vector2f pos = player_Paddle.getPosition();
	if (pos.y + this->origin.y > 600) {
		return true;
	}
	return false;
}

float Paddle::getWidth()
{
	return this->origin.x * 2;
}

void Paddle::autoMove(Time dt, CircleShape ball, float AIspeed) {
	Vector2f ball_pos = ball.getPosition();
	Vector2f paddle_pos = player_Paddle.getPosition();

	if (ball_pos.y > paddle_pos .y) {

		player_Paddle.move(Vector2f(0.f, 100.f * AIspeed /5) * dt.asSeconds());
		//move down
	}
	else if (ball_pos.y < paddle_pos.y) {

		player_Paddle.move(Vector2f(0.f, -100.f * AIspeed /5) * dt.asSeconds());
		//move up
	}
}


