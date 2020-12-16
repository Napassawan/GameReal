#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include "Game.h"
#include "Menu.h"
#include "Textbox.h"
#include<utility>
#include<algorithm>
#include<vector>
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

void showhighscore(int x, int y, string word, sf::RenderWindow& window, sf::Font* font)
{
	sf::Text text;
	text.setFont(*font);
	text.setPosition(x, y);
	text.setString(word);
	text.setCharacterSize(65); //setsize
	window.draw(text);
}
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
	
	sf::Music musicPlay , musicMenu ;

	if (!musicPlay.openFromFile("sound/play.ogg"))
	{
		printf_s("ERROR::MUSIC");
	}
	musicPlay.setLoop(true);
	musicPlay.setVolume(20.f);

	if (!musicMenu.openFromFile("sound/op.wav"))
	{
		printf_s("ERROR::MUSIC");
	}
	musicMenu.setVolume(20.f);
	musicMenu.setLoop(true);
	musicMenu.play();

	Menu menu(900,600);
	Game game;

	bool cangetnewscores ;
	bool firstendgames = false;
	sf::Clock dietimes;
	int pointkeep;

	sf::Event e;
	
	Textbox playernametextbox(80, sf::Color::White, true);
	playernametextbox.setFont(font);
	playernametextbox.setPosition({ 350.f,250.f }); //position textbox
	playernametextbox.setlimit(true, 10);

	FILE* fp;
	char temp[255];
	int score[6];
	string name[6];
	vector<pair<int, string>>userScore;

	int j = 0;

	fp = fopen("./score.txt", "r");
	for (int i = 0; i < 5; i++) {
		fscanf(fp, "%s", &temp);
		name[i] = temp;
		fscanf(fp, "%d", &score[i]);
		userScore.push_back(make_pair(score[i], name[i]));
	}
	fclose(fp);

	while (window->isOpen())
	{
		while (window->pollEvent(e))
		{
			switch (e.type)
			{
			case sf::Event::Closed:
				window->close();
			case sf::Event::TextEntered:
				if (gamestate == 4) {
					playernametextbox.typeOn(e);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
					gamestate = 0;
				}
			}
		}
		window->clear();
		mousePosWindow = sf::Mouse::getPosition(*window);
		mousePosview = window->mapPixelToCoords(mousePosWindow);
		if (gamestate == 0) {
			menu.Drawmenu(window);
			if (menu.getBounds_0().contains(mousePosview)) {
				menu.buttoncheck(0);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					gamestate = 4;
				}
			}
			else if (menu.getBounds_1().contains(mousePosview)) {
				menu.buttoncheck(1);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					gamestate = 2;
				}
			}
			else if (menu.getBounds_2().contains(mousePosview)) {
				menu.buttoncheck(2);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					gamestate = 3;
				}
			}
			else if (menu.getBounds_3().contains(mousePosview)) {
				menu.buttoncheck(3);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					window->close();
				}
			}
			menu.Draw(window);
		}
		else if (gamestate == 1) {
			musicMenu.pause();
			if (game.returnHp() != 0) {
				game.update(window);
				game.render();
				cangetnewscores = false;
			}
			else if (game.returnHp() == 0 && cangetnewscores == false) {
				menu.Drawdie(window);
				cangetnewscores = true;
				dietimes.restart();
			}
			else if (game.returnHp() == 0 && cangetnewscores && dietimes.getElapsedTime().asSeconds() > 3.f) {
				j++;
				pointkeep = game.returnScore();
				fp = fopen("./score.txt", "r");
				score[5] = pointkeep;
				userScore.push_back(make_pair(score[5], name[5]));
				sort(userScore.begin(), userScore.end());
				fclose(fp);
				fopen("./score.txt", "w");
				for (int i = 4 + j; i >= 0 + j; i--) {
					strcpy(temp, userScore[i].second.c_str());
					fprintf(fp, "%s %d\n", temp, userScore[i].first);
				}
				fclose(fp);
				cangetnewscores = false;
				game.restart();
				musicMenu.play();
				musicPlay.pause();
				gamestate = 0;
			}
		}
		else if (gamestate == 2) {
			menu.Drawhowto(window);
		}
		else if (gamestate == 3) {
			menu.Drawhigh(window);
			if (firstendgames == false) {
				showhighscore(630, 120, to_string(userScore[0].first), *window, &font);
				showhighscore(120, 120, userScore[0].second, *window, &font);
				showhighscore(630, 200, to_string(userScore[1].first), *window, &font);
				showhighscore(120, 200, userScore[1].second, *window, &font);
				showhighscore(630, 280, to_string(userScore[2].first), *window, &font);
				showhighscore(120, 280, userScore[2].second, *window, &font);
				showhighscore(630, 360, to_string(userScore[3].first), *window, &font);
				showhighscore(120, 360, userScore[3].second, *window, &font);
				showhighscore(630, 440, to_string(userScore[4].first), *window, &font);
				showhighscore(120, 440, userScore[4].second, *window, &font);
			}
			else if (firstendgames == true) {
				showhighscore(0, 10, to_string(userScore[4+j].first), *window, &font);
				showhighscore(100, 10, userScore[4 + j].second, *window, &font);
				showhighscore(0, 20, to_string(userScore[3 + j].first), *window, &font);
				showhighscore(100, 20, userScore[3 + j].second, *window, &font);
				showhighscore(0, 30, to_string(userScore[2 + j].first), *window, &font);
				showhighscore(100, 30, userScore[2 + j].second, *window, &font);
				showhighscore(0, 40, to_string(userScore[1 + j].first), *window, &font);
				showhighscore(100, 40, userScore[1 + j].second, *window, &font);
				showhighscore(0, 50, to_string(userScore[j].first), *window, &font);
				showhighscore(100, 50, userScore[j].second, *window, &font);
			}
		}
		else if (gamestate == 4) {
			menu.Drawname(window);
			playernametextbox.drawTo(*window);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
				name[5] = playernametextbox.gettext();
				gamestate = 1;
				musicPlay.play();
			}
		}
		window->display();
	}
	return 0;
}