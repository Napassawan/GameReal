#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include "Game.h"
#include "Menu.h"
#include "Textbox.h"

int main()
{
	int gamestate = 0;
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosview;

	sf::Font font;
	font.loadFromFile("font/FSEX300.ttf");

	videoMode = sf::VideoMode(900, 600);
	window = new sf::RenderWindow(videoMode, "The Collector", sf::Style::Close | sf::Style::Titlebar);
	auto image = sf::Image{};
	if (!image.loadFromFile("img/icon.png"))
	{
		printf_s("ERROR::GAME::ICON");
	}

	window->setIcon(64, 64, image.getPixelsPtr());
	window->setVerticalSyncEnabled(true);
	window->setFramerateLimit(60);
	
	sf::Music musicPlay , musicMenu;
	/*if (!musicPlay.openFromFile("sound/play.ogg"))
	{
		printf_s("ERROR::MUSIC");
	}
	musicPlay.setLoop(true);
	musicPlay.setVolume(20.f);
	musicPlay.play();*/

	/*if (!musicMenu.openFromFile("sound/op.ogg"))
	{
		printf_s("ERROR::MUSIC");
	}
	musicMenu.play();*/

	Menu menu(900,600);
	Game game;

	sf::Event e;
	
	Textbox playernametextbox(100, sf::Color::White, true);
	playernametextbox.setFont(font);
	playernametextbox.setPosition({ 500.f,320.f });
	playernametextbox.setlimit(true, 10);

	while (window->isOpen())
	{
		while (window->pollEvent(e))
		{
			switch (e.type)
			{
			case sf::Event::Closed:
				window->close();
			case sf::Event::TextEntered:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
					gamestate = 0;
				}
			}
		}
		window->clear();
		mousePosWindow = sf::Mouse::getPosition(*window);
		mousePosview = window->mapPixelToCoords(mousePosWindow);
		if (gamestate == 0) {
			if (menu.getBounds_0().contains(mousePosview)) {
				menu.buttoncheck(0);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					gamestate = 1;
				}
			}
			else if (menu.getBounds_1().contains(mousePosview)) {
				menu.buttoncheck(1);

			}
			else if (menu.getBounds_2().contains(mousePosview)) {
				menu.buttoncheck(2);
			}
			else if (menu.getBounds_3().contains(mousePosview)) {
				menu.buttoncheck(3);
			}
			menu.Draw(window);
			playernametextbox.drawTo(*window);
		}
		else if (gamestate == 1) {
			game.update(window);
			game.render();
		}
		else if (gamestate == 2) {
			game.update(window);
			game.render();
		}
		else if (gamestate == 3) {
			game.update(window);
			game.render();
		}

		window->display();
	}
	return 0;
}