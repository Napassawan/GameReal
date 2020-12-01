#include "Swagball.h"

void Swagball::initShape(const sf::RenderWindow& window)
{
	this->M1.setSize(sf::Vector2f(32.f, 32.f));
	sf::Color color;


	switch (this->type)
	{
	case DEFAULT:
		color = sf::Color::Blue;
		if (!this->M1Tex.loadFromFile("img/Item1.png"))
		{
			printf("ERROR::GAME::ITEM");
		}
		
		this->M1.setOutlineColor(sf::Color::White);
		this->M1.setOutlineThickness(3.f);
		break;
	case DOUBLE:
		color = sf::Color::Yellow;
		this->M1.setOutlineColor(sf::Color::White);
		this->M1.setOutlineThickness(3.f);
		break;
	case DAMAGING:
		color = sf::Color::Red;
		this->M1.setOutlineColor(sf::Color::White);
		this->M1.setOutlineThickness(3.f);
		break;
	case HEALING:
		color = sf::Color::Magenta;
		this->M1.setOutlineColor(sf::Color::White);
		this->M1.setOutlineThickness(3.f);
		break;
	case TEN:
		color = sf::Color::Cyan;
		this->M1.setOutlineColor(sf::Color::White);
		this->M1.setOutlineThickness(3.f);
		break;
	}
	this->M1.setTexture(&this->M1Tex);
	this->M1.setFillColor(color);
	this->M1.setPosition(sf::Vector2f(
		static_cast<float>(random_between(80, 790)),
		static_cast<float>(random_between(170, 540))
	)
	);
}


Swagball::Swagball(const sf::RenderWindow& window, int type)
	:type(type)
{
	this->initShape(window);
}

Swagball::~Swagball()
{
}

const sf::RectangleShape Swagball::getShape() const
{
	return this->M1;
}

const int& Swagball::getType() const
{
	return this->type;
}

void Swagball::update()
{

}

void Swagball::render(sf::RenderTarget& target)
{
	target.draw(this->M1);
}