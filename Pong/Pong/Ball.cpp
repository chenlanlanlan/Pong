#pragma once
#include <iostream>
#include"Ball.h"

using namespace sf;

Ball::Ball()
{
	p1 = p2 = 0;
	this->direction = Vector2f(-1.f,0.f);
	this->radius = 25.f;
	this->position = Vector2f(410.f, 300.f);
	this->origin.x = radius;
	this->origin.y = radius;
	this->texture.loadFromFile(BALL_TEXTURE_FILEPATH);
	this->soundBuffer1.loadFromFile(HIT_SOUND_PATH);
	this->speed = 200.f;
	hit_sound.setBuffer(soundBuffer1);
	this->soundBuffer2.loadFromFile(LOSTPOINT_SOUND_PATH);
	losePoint_sound.setBuffer(soundBuffer2);
	ball.setRadius(this->radius);
	ball.setOrigin(this->origin);
	ball.setPosition(this->position);
	ball.setTexture(&texture);
}

void Ball::drawBall(RenderWindow &window) 
{
	window.draw(ball);
}

void Ball::move(Time elapsedTime) 
{
	Vector2f pos = ball.getPosition();
	float offsetX, offsetY;
	offsetX = speed * direction.x * elapsedTime.asSeconds();
	offsetY = speed * direction.y * elapsedTime.asSeconds();
	ball.setPosition(pos.x + offsetX, pos.y + offsetY);
	//std::cout << "Speed: " << this->speed<<std::endl;
	//std::cout << "position x : " << ball.getPosition().x << std::endl;
	//std::cout << "position y : " << ball.getPosition().y << std::endl;
}

void Ball::reverseX()
{
	this->direction.x = -this->direction.x;
	if (speed <= MAX_SPEED) {
		speed = speed + 5;
	}
}

void Ball::reverseY()
{
	this->direction.y = -this->direction.y;
	if (speed <= MAX_SPEED) {
		speed = speed + 5;
	}
}

void Ball::checkCollisionWithGameWindow(Paddle paddle1, Paddle paddle2, Text &p1Score, Text &p2Score)
{
	Vector2f pos = ball.getPosition();
		
	if (pos.y - ball.getRadius() < 0) {
		onColiision();
		ball.setPosition(pos.x, ball.getRadius());
		reverseY();
	}
	else if(pos.y + ball.getRadius() >= WINDOW_HEIGHT){
		onColiision();
		ball.setPosition(pos.x, WINDOW_HEIGHT - ball.getRadius());
		reverseY();
	}

	if (pos.x - ball.getRadius() < 0) {
		if (checkCollisionWithPaddles(paddle1)) {
			onColiision(); //sound effect
			reverseX();
			calculateAngle(paddle1);
			ball.setPosition(ball.getRadius() + paddle1.getWidth(), pos.y);
		}
		else {
			p2++;
			p2Score.setString(std::to_string(p2));
			onLosePoint();
			std::cout << "P2 Score!\n";
			reset();
		}
	}
	else if(pos.x + ball.getRadius() >= WINDOW_WIDTH){
		if (checkCollisionWithPaddles(paddle2)) {
			calculateAngle(paddle2);
			reverseX();
			onColiision();
			ball.setPosition(WINDOW_WIDTH - ball.getRadius() - paddle1.getWidth(), pos.y);
		}
		else {
			p1++;
			p1Score.setString(std::to_string(p1));
			onLosePoint();
			std::cout << "P1 Score!\n";
			reset();
		}
	}
}

bool Ball::checkCollisionWithPaddles(Paddle paddle)
{
	std::cout << "Check!!\n";

	Vector2f paddle_pos = paddle.player_Paddle.getPosition();
	Vector2f paddle_ori = paddle.player_Paddle.getOrigin();
	Vector2f ball_pos = ball.getPosition();
	Vector2f paddleRightTop = Vector2f(paddle_pos.x + paddle_ori.x, paddle_pos.y - paddle_ori.y);

	Vector2f dis_a, dis_b, dis_c;
	dis_a = Vector2f(abs(ball_pos.x - paddle_pos.x), abs(ball_pos.y - paddle_pos.y)); //distance from the circle to the rect
	dis_b = paddle_pos - paddleRightTop ; //distance from the rect origin to the corner
	dis_c = Vector2f(std::max((dis_a.x - dis_b.x), 0.f), std::max((dis_a.y - dis_b.y), 0.f)); //distance from the nearest position on the rec to the circle

	float dotProductOf_DisC = dis_c.x * dis_c.x + dis_c.y * dis_c.y;
	
	float dotProductof_DisA_Yunit = dis_a.x * 1;
	float d_DisA_Yunit = sqrt(dis_a.x * dis_a.x + dis_a.y * dis_a.y);
	bool result = dotProductOf_DisC <= radius * radius;
	return dotProductOf_DisC <= radius * radius;
}

void Ball::reset()
{
	ball.setPosition(410.f, 300.f);
	this->reverseX();
	this->reverseY();
	this->speed = 200.f;
	this->direction = Vector2f(-1.f, 0.f);
}

void Ball::calculateAngle(Paddle paddle) {
	Vector2f ball_pos = ball.getPosition();
	Vector2f paddle_pos = paddle.player_Paddle.getPosition();
	Vector2f paddle_ori = paddle.player_Paddle.getOrigin();
	Vector2f paddleRightTop = Vector2f(paddle_pos.x + 10, paddle_pos.y - 50);
	Vector2f paddleLeftBottom = Vector2f(paddle_pos.x + 10, paddle_pos.y + 50);

	float intersectPointY;
	intersectPointY = sqrt((ball_pos.x * ball_pos.x + ball_pos.y * ball_pos.y) - radius * radius);
	std::cout << "intersectPointY: " << intersectPointY << std::endl;
	float angle = (paddle_pos.y + paddle_ori.y) - intersectPointY / (paddle_ori.y * MAXBOUNCEANGLE);
	std::cout << "angle: " << angle << std::endl;
	this->direction.y = -sin(angle * PI / 180.f);
}

void Ball::onColiision()
{
	hit_sound.setPitch(2);
	hit_sound.play();
}

void Ball::onLosePoint() {
	hit_sound.setPitch(3);
	losePoint_sound.play();
}



