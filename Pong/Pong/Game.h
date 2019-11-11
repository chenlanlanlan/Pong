#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include<iostream>
#include "Ball.h"
#include "Paddle.h"

#define BACKGROUND_IMAGE "images/background.png"
#define FONT "assets/KenPixel Square.ttf"
#define START_SOUND_PATH "assets/BucketTap01.wav"
#define WIN_SOUND_PATH "assets/BossFound.wav"
#define PLAYER1_POSITION Vector2f(10.f, 300.f)
#define PLAYER2_POSITION Vector2f(790.f, 300.f)

using namespace sf;

class Game
{
public:
	Game();
	void runGame();

private:
	RenderWindow game_window;
	Texture background_texture;
	Sprite background;
	Ball ball;
	Paddle player1, player2;
	Text p1Score, p2Score;
	Font font;
	SoundBuffer sb1;
	SoundBuffer sb2;
	Sound start_sound;
	Sound win_sound;
	float AIspeed;
	bool isGameOver;
	bool isPVP;
	void renderGame();
	void handleUserInput(Time deltaTime);
	void restartGame();
};

