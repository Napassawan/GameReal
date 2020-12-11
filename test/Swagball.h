#pragma once


#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

enum SwagBallTypes { DEFAULT = 0, DAMAGING, DOUBLE, HEALING, NROFTYPES, DIVIDE };

class Swagball
{
private:


	int type;
	int numItem;
	sf::RectangleShape M1;
	sf::Texture M1Tex;


	float random_between(float min, float max)
	{
		float r = (rand() / (float)RAND_MAX) * (max + 1) + min;
		return r > max ? max : r;
	}

	void initShape(const sf::RenderWindow& window);


public:

	Swagball(const sf::RenderWindow& window, int type);
	virtual ~Swagball();

	const sf::RectangleShape getShape() const;
	const int& getType() const;
	void update();
	void render(sf::RenderTarget& target);
};