#include "Game.h"

Game::Game() :
	game_window(VideoMode(800, 600), "GAME-230 Pong!", Style::Close),
	player1(PLAYER1_POSITION),
	player2(PLAYER2_POSITION),
	ball(),
	font()
{
	this->background_texture.loadFromFile(BACKGROUND_IMAGE);
	this->background_texture.setSmooth(true);

	this->background.setTexture(background_texture);
	this->background.setTextureRect(sf::IntRect(140, 10, 800, 600));
	
	sb1.loadFromFile(START_SOUND_PATH);
	start_sound.setBuffer(sb1);
	sb2.loadFromFile(WIN_SOUND_PATH);
	win_sound.setBuffer(sb2);

	font.loadFromFile(FONT);
	p1Score.setCharacterSize(32);
	p2Score.setCharacterSize(32);
	p1Score.setFont(font);
	p2Score.setFont(font);
	p1Score.setPosition(380.f, 20.f);
	p2Score.setPosition(420.f, 20.f);
	p1Score.setFillColor(Color::White);
	p2Score.setFillColor(Color::White);
	p1Score.setString("0");
	p2Score.setString("0");
	
	AIspeed = 200.f;
	isGameOver = true;
	isPVP = false;
}

void Game::runGame()
{
	Clock clock;
	int num;

	while (game_window.isOpen()) {
		Time deltaTime = clock.restart();
		srand(time(NULL));
		num = rand() % 100 + 1;

		handleUserInput(deltaTime);
		if (!isGameOver) {
			//update ball position
			ball.move(deltaTime);
			//PVP MODE
			if (!isPVP) {
				if (num <= 50) {
					std::cout << "num: " << num << std::endl;
					player2.autoMove(deltaTime, ball.ball, 0);
				}
				else
					player2.autoMove(deltaTime, ball.ball, AIspeed);
			}
			ball.checkCollisionWithGameWindow(player1, player2, p1Score, p2Score);
		}
		renderGame();
		if (std::stoi((std::wstring)p1Score.getString()) >= 5 ||
			std::stoi((std::wstring)p2Score.getString()) >= 5) {
			win_sound.play();
			std::cout << "game End ! \n";
			restartGame();
		}
	}
}

void Game::restartGame() {
	isGameOver = true;
	ball.p1 = 0;
	ball.p2 = 0;
	p1Score.setString("0");
	p2Score.setString("0");
	player1.player_Paddle.setPosition(PLAYER1_POSITION);
	player2.player_Paddle.setPosition(PLAYER2_POSITION);
}

void Game::handleUserInput(Time deltaTime) {
	Event event;
	while (game_window.pollEvent(event)) //game loop
	{
		switch (event.type)
		{
		case Event::Closed:
			game_window.close(); //close the window
			break;
		case Event::KeyPressed:
			if (isGameOver && event.key.code == Keyboard::Space) {
				start_sound.play();
				std::cout << "start! \n";
				isGameOver = false;
 				std::cout << isGameOver << std::endl;
			}
			else if (event.key.code == Keyboard::K) {
				isPVP = true;
			}
			else if(!isGameOver){
				player1.player1Input(event.key.code, deltaTime);
				if (isPVP) {
					player2.player2Input(event.key.code, deltaTime);
				}
			}
		}
	}
}

void Game::renderGame() {
	
	game_window.clear();
	game_window.draw(background);
	game_window.draw(p1Score);
	game_window.draw(p2Score);
	ball.drawBall(game_window);
	player1.drawPaddle(game_window);
	player2.drawPaddle(game_window);
	//menu.draw(game_window);

	game_window.display();
}