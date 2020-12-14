#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Player
{
private:
	sf::RectangleShape Char;
	sf::Texture ChTex;
	sf::IntRect Frame;
	sf::Clock AnimationTime;

	float movementSpeed;
	int hp;
	int hpMax;
	float width;
	float height;
	float prewidth;
	float preheight;

	bool move;
	int ANum;

	void initVariables();
	void initShape();
	void initAnimation();

	sf::SoundBuffer buffer;
	sf::Sound sound;	
	
	
public:
	Player(float x = 0.f, float y = 0.f);
	virtual ~Player();

	const sf::RectangleShape& getShape() const;
	const int& getHp() const;
	const int& getHpMax() const;

	void takeDamage(const int damage);
	void gainHealth(const int health);

	void setHp(int value);
	void resetposition();

	void updateInput();
	void updateAnimation();
	void updateCollision(const sf::RenderTarget* target);
	void update(const sf::RenderTarget* target);
	void render(sf::RenderTarget* target);
};
