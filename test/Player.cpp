#include "Player.h"


void Player::initVariables()
{
	this->movementSpeed = 5.f;
	this->hpMax = 10;
	this->hp = hpMax;
	this->prewidth = 18.f;
	this->preheight = 16.f;
	this->width = 39.f;
	this->height = 60.f;
	this->move = false;
	this->ANum = 1;
	this->buffer.loadFromFile("sound/walk.wav");
	this->sound.setBuffer(this->buffer);
}

void Player::initShape()
{
	this->Char.setSize(sf::Vector2f(39.f, 60.f));
	if (!this->ChTex.loadFromFile("img/Ch.png"))
	{
		printf_s("ERROR::GAME::CHAR");
	}
	this->Frame = sf::IntRect(prewidth, preheight, width, height);
	this->Char.setTexture(&this->ChTex);
	this->Char.setScale(1.5f, 1.5f);
	this->Char.setTextureRect(this->Frame);
}

void Player::initAnimation()
{
	this->AnimationTime.restart();
}

Player::Player(float x, float y)
{
	this->Char.setPosition(415, 250);

	this->initVariables();
	this->initShape();
	this->initAnimation();
}

Player::~Player()
{
}

const sf::RectangleShape& Player::getShape() const
{
	return this->Char;
}

const int& Player::getHp() const
{
	return this->hp;
}

const int& Player::getHpMax() const
{
	return this->hpMax;
}

void Player::takeDamage(const int damage)
{
	if (this->hp > 0)
		this->hp -= damage;

	if (this->hp < 0)
		this->hp = 0;
}

void Player::gainHealth(const int health)
{
	if (this->hp < this->hpMax)
		this->hp += health;
	if (this->hp > this->hpMax)
		this->hp = this->hpMax;
}

void Player::setHp(int value)
{
	this->hp = value;
}

void Player::resetposition()
{
	this->Char.setPosition(415, 250);
}

void Player::updateInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->Char.move(-this->movementSpeed, 0.f);
		this->move = true;
		
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->Char.move(this->movementSpeed, 0.f);
		this->move = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->Char.move(0.f, -this->movementSpeed);
		this->move = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->Char.move(0.f, this->movementSpeed);
		this->move = true;
	
	}
	else
	{
		this->move = false;
	}

}

void Player::updateAnimation()
{
	if (this->ANum >= 9)
	{
		ANum = 1;
	}
	if (this->AnimationTime.getElapsedTime().asSeconds() >= 0.1f)
	{
		if (move == false)
		{
			this->preheight = 319.f;
			this->width = 39.f;

			switch (ANum)
			{
			case 1: this->prewidth = 97.f;
				break;
			case 2: this->prewidth = 176.f;
				break;
			case 3: this->prewidth = 251.f;
				break;
			case 4: this->prewidth = 330.f;
				break;
			case 5: this->prewidth = 405.f;
				break;
			case 6: this->prewidth = 483.f;
				break;
			case 7: this->prewidth = 559.f;
				break;
			case 8: this->prewidth = 18.f;
				break;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				this->preheight = 93.f;
				this->width = 39.f;
				switch (ANum)
				{
				case 1: this->prewidth = 97.f;
					break;
				case 2: this->prewidth = 176.f;
					break;
				case 3: this->prewidth = 251.f;
					break;
				case 4: this->prewidth = 330.f;
					break;
				case 5: this->prewidth = 405.f;
					break;
				case 6: this->prewidth = 483.f;
					break;
				case 7: this->prewidth = 559.f;
					break;
				case 8: this->prewidth = 18.f;
					break;
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				this->preheight = 170.f;
				this->width = 39.f;
				switch (ANum)
				{
				case 1: this->prewidth = 97.f;
					break;
				case 2: this->prewidth = 176.f;
					break;
				case 3: this->prewidth = 251.f;
					break;
				case 4: this->prewidth = 330.f;
					break;
				case 5: this->prewidth = 405.f;
					break;
				case 6: this->prewidth = 483.f;
					break;
				case 7: this->prewidth = 559.f;
					break;
				case 8: this->prewidth = 18.f;
					break;
				}
			}
			this->Frame = sf::IntRect(prewidth, preheight, width, height);
			this->Char.setTextureRect(this->Frame);
			this->ANum++;
		}
		else if (move == true)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				this->preheight = 248.f;
				this->width = 39.f;
				switch (ANum)
				{
				case 1: this->prewidth = 97.f;
					break;
				case 2: this->prewidth = 176.f;
					break;
				case 3: this->prewidth = 251.f;
					break;
				case 4: this->prewidth = 330.f;
					break;
				case 5: this->prewidth = 405.f;
					break;
				case 6: this->prewidth = 483.f;
					break;
				case 7: this->prewidth = 559.f;
					break;
				case 8: this->prewidth = 18.f;
					break;
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				this->preheight = 16.f;
				this->width = 39.f;
				switch (ANum)
				{
				case 1: this->prewidth = 97.f;
					break;
				case 2: this->prewidth = 176.f;
					break;
				case 3: this->prewidth = 251.f;
					break;
				case 4: this->prewidth = 330.f;
					break;
				case 5: this->prewidth = 405.f;
					break;
				case 6: this->prewidth = 483.f;
					break;
				case 7: this->prewidth = 559.f;
					break;
				case 8: this->prewidth = 18.f;
					break;
				}
			}
			this->Frame = sf::IntRect(prewidth, preheight, width, height);
			this->Char.setTextureRect(this->Frame);
			this->ANum++;
		}
		this->AnimationTime.restart();
	}
}

void Player::updateCollision(const sf::RenderTarget* target)
{
	//L
	if (this->Char.getGlobalBounds().left <= 0.f)
		this->Char.setPosition(0.f, this->Char.getGlobalBounds().top);
	//R
	if (this->Char.getGlobalBounds().left + this->Char.getGlobalBounds().width >= target->getSize().x)
		this->Char.setPosition(target->getSize().x - this->Char.getGlobalBounds().width, this->Char.getGlobalBounds().top);
	//T
	if (this->Char.getGlobalBounds().top <= 80.f)
		this->Char.setPosition(this->Char.getGlobalBounds().left, 80.f);
	//B
	if (this->Char.getGlobalBounds().top + this->Char.getGlobalBounds().height >= target->getSize().y)
		this->Char.setPosition(this->Char.getGlobalBounds().left, target->getSize().y - this->Char.getGlobalBounds().height);
}

void Player::update(const sf::RenderTarget* target)
{
	this->updateInput();
	this->updateAnimation();
	this->updateCollision(target);
}

void Player::render(sf::RenderTarget* target)
{
	target->draw(this->Char);
}