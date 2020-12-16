#include "Game.h"

void Game::initVariables()
{
	this->endGame = false;
	this->spawnTimerMax = 20.f;
	this->spawnTimer = this->spawnTimerMax;
	this->maxSwagBalls = 20;
	this->points = 0;

}

void Game::initWindow()
{
	this->videoMode = sf::VideoMode(900, 600);
	this->window = new sf::RenderWindow(this->videoMode, "The Collector", sf::Style::Close | sf::Style::Titlebar);
	auto image = sf::Image{};
	if (!image.loadFromFile("img/icon.png"))
	{
		printf_s("ERROR::GAME::ICON");
	}
	this->window->setIcon(64, 64, image.getPixelsPtr());
	this->window->setVerticalSyncEnabled(true);
	this->window->setFramerateLimit(60);

}

void Game::initWorld()
{
	if (!this->worldBackgroundTex.loadFromFile("img/bg.png"))
	{
		printf("ERROR::GAME::BACKGROUND");
	}

	this->worldBackground.setTexture(this->worldBackgroundTex);
}

void Game::initSoundBG()
{

}

void Game::initHeart()
{
	if (!this->heartTex.loadFromFile("img/heart.png"))
	{
		printf("ERROR::GAME::HEART");
	}
	this->heart.setTexture(this->heartTex);
	this->heart.setScale(1.5f, 1.5f);
	this->heart.setPosition(5.f, 22.f);
}

void Game::initSky()
{
	if (!this->worldSkyTex.loadFromFile("img/sky.png"))
	{
		printf("ERROR::GAME::SKY");
	}
	worldSkyTex.setRepeated(true);
	this->parallaxShader.loadFromMemory(
		"uniform float offset;"

		"void main() {"
		"    gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;"
		"    gl_TexCoord[0] = -gl_TextureMatrix[0] * gl_MultiTexCoord0;"
		"    gl_TexCoord[0].x = gl_TexCoord[0].x + offset;" // magic
		"    gl_FrontColor = gl_Color;"
		"}"
		, sf::Shader::Vertex);

	this->worldSky.setTexture(this->worldSkyTex);
}

void Game::initFont()
{
	if (!this->font.loadFromFile("font/FSEX300.ttf"))
	{
		printf_s("ERROR::GAME::INITFONT");
	}
}

void Game::initText()
{
	this->guiText.setFont(this->font);
	this->guiText.setFillColor(sf::Color::White);
	this->guiText.setCharacterSize(25);

	this->endGameText.setFont(this->font);
	this->endGameText.setFillColor(sf::Color::Red);
	this->endGameText.setCharacterSize(60);
	this->endGameText.setPosition(350.f, 250.f);
	this->endGameText.setString("GAMEOVER");
}


Game::Game()
{
	this->initVariables();
	this->initSky();
	this->initWorld();
	this->initFont();
	this->initText();
	this->initHeart();

}

Game::~Game()
{
	delete this->window;
}

const bool& Game::getEndGame() const
{
	return this->endGame;
}


void Game::pollEvent()
{
	//while (this->window->pollEvent(this->sfmlEvent))
	//{
	//	switch (this->sfmlEvent.type)
	//	{
	//	case sf::Event::Closed:
	//		this->window->close();
	//		break;
	//	case sf::Event::KeyPressed:
	//		if (this->sfmlEvent.key.code == sf::Keyboard::Escape)
	//			this->window->close();
	//		break;
	//	}
	//}
}

void Game::spawnSwagBalls()
{
	if (this->spawnTimer < this->spawnTimerMax)
		this->spawnTimer += 1.f;
	else
	{
		if (this->swagBalls.size() < this->maxSwagBalls)
		{
			this->swagBalls.push_back(Swagball(*this->window, this->randomballType()));

			this->spawnTimer = 0.f;

		}

	}
}

const int Game::randomballType() const
{
	int type = SwagBallTypes::DEFAULT;

	int randValue = rand() % 100 + 1;
	if (randValue > 45 && randValue <= 60)
		type = SwagBallTypes::DAMAGING;
	else if (randValue > 65 && randValue <= 80)
		type = SwagBallTypes::HEALING;
	else if (randValue > 96 && randValue <= 98)
		type = SwagBallTypes::DOUBLE;
	else if (randValue > 98 && randValue <= 100)
		type = SwagBallTypes::DIVIDE;
	return type;
}

const int Game::returnHp() const
{
	return this->player.getHp();
}

const int Game::returnScore() const
{
	return this->points;
}

void Game::updatePlayer()
{
	this->player.update(this->window);

	if (this->player.getHp() <= 0)
		this->endGame = true;
}

void Game::updateCollision()
{
	for (size_t i = 0; i < this->swagBalls.size(); i++)
	{
		if (this->player.getShape().getGlobalBounds().intersects(this->swagBalls[i].getShape().getGlobalBounds()))
		{
			switch (this->swagBalls[i].getType())
			{
			case SwagBallTypes::DEFAULT:
				this->points = points + 100;
				if (!getP.loadFromFile("sound/getPoint.wav"))
				{
					printf_s("ERROR::SOUND EFFECT");
				}
				soundP.setBuffer(getP);
				soundP.setVolume(10.f);
				soundP.play();
				break;
			case SwagBallTypes::HEALING:
				this->player.gainHealth(1);
				this->points = points + 50;
				if (!getHP.loadFromFile("sound/getHP.wav"))
				{
					printf_s("ERROR::SOUND EFFECT");
				}
				soundHP.setBuffer(getHP);
				soundHP.setVolume(10.f);
				soundHP.play();
				break;
			case SwagBallTypes::DAMAGING:
				this->player.takeDamage(1);
				this->points = points - 50;				
				if (!getDMG.loadFromFile("sound/getDmg.wav"))
				{
					printf_s("ERROR::SOUND EFFECT");
				}
				soundDMG.setBuffer(getDMG);
				soundDMG.setVolume(10.f);
				soundDMG.play();
				break;
			case SwagBallTypes::DOUBLE:
				this->points = points * 2;
				if (!getDOU.loadFromFile("sound/getDou.wav"))
				{
					printf_s("ERROR::SOUND EFFECT");
				}
				soundDOU.setBuffer(getDOU);
				soundDOU.setVolume(10.f);
				soundDOU.play();
			
				break;
			case SwagBallTypes::DIVIDE:
				if (!getDIV.loadFromFile("sound/getDiv.wav"))
				{
					printf_s("ERROR::SOUND EFFECT");
				}
				soundDIV.setBuffer(getDIV);
				soundDIV.setVolume(10.f);
				soundDIV.play();
				this->points = points / 2;
				break;
			}
			this->swagBalls.erase(this->swagBalls.begin() + i);
		}
		if (this->player.getHp() == 0) {
			if (swagBalls.size() == 1) {
				this->swagBalls.erase(this->swagBalls.begin());
			}
			else {
				if (i == 0) {
					this->swagBalls.erase(this->swagBalls.begin());
				}
				this->swagBalls.erase(this->swagBalls.begin() + i);
			}
		}
	}
}

void Game::updateGUI()
{

	std::stringstream ss;

	ss << " Points : " << this->points << "\n" << "    : " << this->player.getHp() << " / " << this->player.getHpMax() << "\n";

	this->guiText.setString(ss.str());
}

void Game::updateWorld()
{
}

void Game::update(sf::RenderWindow* window)
{
	this->window = window;
	//this->pollEvent();

	if (this->endGame == false)
	{
		this->spawnSwagBalls();
		this->updatePlayer();
		this->updateCollision();
		this->updateGUI();
		this->updateWorld();
	}
}

void Game::restart()
{
	this->updateCollision();
	this->player.setHp(10);
	this->points = 0;
	this->player.resetposition();
}

void Game::renderGUI(sf::RenderTarget* target)
{
	target->draw(this->guiText);
}


void Game::renderSky()
{
	parallaxShader.setUniform("offset", offset += clockbg.restart().asSeconds() / 50);
	this->window->draw(this->worldSky, &parallaxShader);
}

void Game::renderWorld()
{
	this->window->draw(this->worldBackground);
}

void Game::renderHeart()
{
	this->window->draw(this->heart);
}

void Game::render()
{
	
	this->renderSky();
	this->renderWorld();

	this->player.render(this->window);

	for (auto i : this->swagBalls)
	{
		i.render(*this->window);
	}

	this->renderGUI(this->window);
	this->renderHeart();
	if (this->endGame == true)
		this->window->draw(this->endGameText);


}