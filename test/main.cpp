#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include "Game.h"

int main()
{
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
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
	musicPlay.play();*/

	/*if (!musicMenu.openFromFile("sound/play.ogg"))
	{
		printf_s("ERROR::MUSIC");
	}
	musicMenu.play();*/


	Game game;
	
	while (window->isOpen())
	{
		game.update(window);
		game.render();
	}
	return 0;
}