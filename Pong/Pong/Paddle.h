#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <stdlib.h>   
#include <time.h> 

//#include "Ball.h"

#define SPEED 350
#define PADDLE_SOUND "assets/Tap01.wav"

using namespace sf;

class Paddle
{
public:

	RectangleShape player_Paddle;
	Paddle(Vector2f position);
	void drawPaddle(RenderWindow& window);
	void player1Input(Keyboard::Key key, Time dt);
	void player2Input(Keyboard::Key key, Time dt);
	void updatePlayer(Time dt, Vector2f velocity);
	void autoMove(Time dt, CircleShape ball, float AIspeed);
	bool isCollidedTop();
	bool isCollideBottom();
	float getWidth();


private:
	Vector2f velocity;
	Vector2f speed;
	Vector2f position;
	Vector2f paddleSize;
	Vector2f origin;
	Color paddleColor;
	SoundBuffer sb;
	Sound paddleSound;

};

