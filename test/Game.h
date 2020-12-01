#pragma once

#include <iostream>
#include <ctime>
#include <vector>
#include <sstream>
#include <map>
#include "Player.h"
#include "Swagball.h"
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

class Game
{
private:
	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	bool endGame;
	sf::Event sfmlEvent;

	Player player;

	int points;

	sf::Font font;
	sf::Text guiText;
	sf::Text endGameText;

	sf::Texture worldBackgroundTex;
	sf::Sprite worldBackground;

	sf::Texture heartTex;
	sf::Sprite heart;

	sf::Texture worldSkyTex;
	sf::Sprite worldSky;

	sf::Shader parallaxShader;
	sf::Clock clockbg;
	float offset = 0.0f;

	std::vector<Swagball> swagBalls;
	float spawnTimerMax;
	float spawnTimer;
	int maxSwagBalls;

	void initVariables();
	void initWindow();
	void initWorld();
	void initSoundBG();
	void initHeart();
	void initSky();
	void initFont();
	void initText();

public:
	Game();
	~Game();

	const bool& getEndGame() const;
	void pollEvent();

	void spawnSwagBalls();
	const int randomballType() const;
	void updatePlayer();
	void updateCollision();
	void updateGUI();
	void updateWorld();
	void update(sf::RenderWindow* window);

	void renderGUI(sf::RenderTarget* target);
	void renderSky();
	void renderWorld();
	void renderHeart();
	void render();
};