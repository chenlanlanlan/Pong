#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Game.h"
#include "Paddle.h"
#include "Ball.h"
#include "Menu.h"

#define FONT "assets/KenPixel Square.ttf"


using namespace sf;

int main()
{
	Game game;
	game.runGame();
	return 0;
}
