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
	//RenderWindow game_window(VideoMode(800, 600), "GAME-230 Pong!", Style::Close);

	//Texture background_texture;
	//background_texture.loadFromFile("images/background.png");
	//background_texture.setSmooth(true);
	//Sprite background;
	//background.setTexture(background_texture);
	//background.setTextureRect(sf::IntRect(140, 10, 800, 600));

	/////Menu menu(game_window.getSize().x, game_window.getSize().y);

	//Ball ball;
	//Paddle player1(Vector2f(10.f, 300.f));
	//Paddle player2(Vector2f(790.f, 300.f)); //AI
	//
	////SET SCORE

	//Text p1Score, p2Score;
	//Font font;
	//font.loadFromFile(FONT);
	//p1Score.setCharacterSize(32);
	//p2Score.setCharacterSize(32);
	//p1Score.setFont(font);
	//p2Score.setFont(font);
	//p1Score.setPosition(380.f, 20.f);
	//p2Score.setPosition(420.f, 20.f);
	//p1Score.setFillColor(Color::White);
	//p2Score.setFillColor(Color::White);
	//p1Score.setString("0");
	//p2Score.setString("0");

	//Clock clock;

	//bool isPlaying = false; // slap space -- start game

	//while (game_window.isOpen())
	//{
	//	Time deltaTime = clock.restart();

	//	//update ball position
	//	ball.move(deltaTime);
	//	player2.autoMove(deltaTime, ball.ball);
	//	ball.checkCollisionWithGameWindow(player1, player2, p1Score, p2Score);

	//	Event event;
	//	while (game_window.pollEvent(event)) //game loop
	//	{
	//		switch (event.type)
	//		{
	//		case Event::Closed:
	//			game_window.close(); //close the window
	//			break;
	//		case Event::KeyPressed:
	//			player1.playerInput(event.key.code, deltaTime);
	//		}

	//	}

	//	game_window.clear();
	//	game_window.draw(background);
	//	game_window.draw(p1Score);
	//	game_window.draw(p2Score);
	//	ball.drawBall(game_window);
	//	player1.drawPaddle(game_window);
	//	player2.drawPaddle(game_window);
	//	//menu.draw(game_window);
	//	
	//	game_window.display();
	//}

	return 0;
}
