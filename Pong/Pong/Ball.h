#pragma once
#include "Paddle.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <math.h>
#include <cstdlib>
#include <algorithm>


#define PI 3.14159265
#define MAXBOUNCEANGLE 5*PI/12
#define BALL_TEXTURE_FILEPATH "images/ball.png"
#define HIT_SOUND_PATH "assets/Toot02.wav"
#define LOSTPOINT_SOUND_PATH "assets/Error01.wav"

#define SPEED_INCREASE 1.5f
#define MAX_SPEED 800.f
#define WINDOW_WIDTH 800.f
#define WINDOW_HEIGHT 600.f

//functions for the ball in the pong game
using namespace sf;
class Ball
{

public:
	//origin / x and y coordination
	sf::Vector2f position;
	CircleShape ball;
	//texture
	int p1, p2;

	Ball();
	//~Ball();
	void drawBall(RenderWindow& window);
	void move(Time elapsedTime);
	void reverseX();
	void reverseY();
	void checkCollisionWithGameWindow(Paddle paddle1, Paddle paddle2, Text &p1Score, Text &p2Score);
	bool checkCollisionWithPaddles(Paddle paddle);
	void reset();
	void calculateAngle(Paddle paddle);
	void onColiision();
	void onLosePoint();

private:

	float radius;//radius
	float speed;
	Color color;
	Vector2f origin;
	Vector2f direction;//direction
	Texture texture;
	SoundBuffer soundBuffer1;
	SoundBuffer soundBuffer2;
	Sound hit_sound;
	Sound start_sound;
	Sound losePoint_sound;
};

