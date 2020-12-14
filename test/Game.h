#pragma once

#include <iostream>
#include <ctime>
#include <vector>
#include <sstream>
#include <map>
#include "Player.h"
#include "Swagball.h"
#include "Menu.h"
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

	sf::SoundBuffer getP;
	sf::Sound soundP;

	sf::SoundBuffer getHP;
	sf::Sound soundHP;

	sf::SoundBuffer getDMG;
	sf::Sound soundDMG;

	sf::SoundBuffer getDOU;
	sf::Sound soundDOU;

	sf::SoundBuffer getDIV;
	sf::Sound soundDIV;

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
	const int returnHp() const;
	const int returnScore() const;
	void updatePlayer();
	void updateCollision();
	void updateGUI();
	void updateWorld();
	void update(sf::RenderWindow* window);
	void restart();

	void renderGUI(sf::RenderTarget* target);
	void renderSky();
	void renderWorld();
	void renderHeart();
	void render();

};