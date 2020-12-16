#include "Menu.h"

Menu::Menu(float width, float height)
{
    this->KeyTimer = 0.f;
    this->KeyLapse = 1.f;

    this->font.loadFromFile("font/FSEX300.ttf");
    text[0].setFont(font);
    text[0].setFillColor(Color::White);
    text[0].setOutlineColor(sf::Color::White);
    text[0].setOutlineThickness(1.f);
    text[0].setString("New Game");
    text[0].setCharacterSize(32);
    text[0].setPosition(Vector2f(50, 110));

    text[1].setFont(font);
    text[1].setFillColor(Color::White);
    text[1].setOutlineColor(sf::Color::White);
    text[1].setOutlineThickness(1.f);
    text[1].setString("How to play");
    text[1].setCharacterSize(32);
    text[1].setPosition(Vector2f(50, 160));

    text[2].setFont(font);
    text[2].setFillColor(Color::White);
    text[2].setOutlineColor(sf::Color::White);
    text[2].setOutlineThickness(1.f);
    text[2].setString("High Score");
    text[2].setCharacterSize(32);
    text[2].setPosition(Vector2f(50, 210));

    text[3].setFont(font);
    text[3].setFillColor(Color::White);
    text[3].setOutlineColor(sf::Color::White);
    text[3].setOutlineThickness(1.f);
    text[3].setString("Quit");
    text[3].setCharacterSize(32);
    text[3].setPosition(Vector2f(50, 260));

    currentLineIndex = 0;

    this->menutextures.loadFromFile("img/bgMenu.png");
    this->menusprite.setTexture(this->menutextures);

    this->hightextures.loadFromFile("img/bgHighsc.png");
    this->highsprite.setTexture(this->hightextures);

    this->howtotextures.loadFromFile("img/Howto.png");
    this->howtosprite.setTexture(this->howtotextures);

    this->nametextures.loadFromFile("img/bgName.png");
    this->namesprite.setTexture(this->nametextures);

    this->dietextures.loadFromFile("img/gameover.png");
    this->diesprite.setTexture(this->dietextures);
}

Menu::~Menu()
{
}

void Menu::buttoncheck(const int button)
{
    for (int i = 0; i < NUM_OF_LINE; i++) {
        if (button == i) {
            currentLineIndex = button;
            text[currentLineIndex].setFillColor(sf::Color::Red);
        }
        else {
           text[i].setFillColor(sf::Color::White);
        }
    }
}

const sf::FloatRect Menu::getBounds_0() const
{
    return this->text[0].getGlobalBounds();
}

const sf::FloatRect Menu::getBounds_1() const
{
    return this->text[1].getGlobalBounds();
}

const sf::FloatRect Menu::getBounds_2() const
{
    return this->text[2].getGlobalBounds();
}

const sf::FloatRect Menu::getBounds_3() const
{
    return this->text[3].getGlobalBounds();
}


void Menu::Draw(RenderWindow* window)
{
    for (int i = 0; i < NUM_OF_LINE; i++)
    {
        window->draw(text[i]);
    }
}

void Menu::Drawhowto(RenderWindow* window)
{
    window->draw(this->howtosprite);
}

void Menu::Drawhigh(RenderWindow* window)
{
    window->draw(this->highsprite);
}

void Menu::Drawname(RenderWindow* window)
{
    window->draw(this->namesprite);
}

void Menu::Drawmenu(RenderWindow* window)
{
    window->draw(this->menusprite);
}

void Menu::Drawdie(RenderWindow* window)
{
    window->draw(this->diesprite);
}

void Menu::MoveUp()
{
    if (currentLineIndex > 0)
    {
        text[currentLineIndex].setFillColor(Color::White);
        text[currentLineIndex].setOutlineColor(sf::Color::White);
        text[currentLineIndex].setOutlineThickness(1.f);
        currentLineIndex--;
        text[currentLineIndex].setFillColor(Color::Red);
        text[currentLineIndex].setOutlineColor(sf::Color::White);
        text[currentLineIndex].setOutlineThickness(1.f);
    }
}

void Menu::MovedDown()
{
    if (currentLineIndex < NUM_OF_LINE - 1)
    {
        text[currentLineIndex].setFillColor(Color::White);
        text[currentLineIndex].setOutlineColor(sf::Color::White);
        text[currentLineIndex].setOutlineThickness(1.f);
        currentLineIndex++;
        text[currentLineIndex].setFillColor(Color::Red);
        text[currentLineIndex].setOutlineColor(sf::Color::White);
        text[currentLineIndex].setOutlineThickness(1.f);
    }
}

void Menu::MenuUpdate(float dt)
{
    KeyTimer += dt;
    if (Keyboard::isKeyPressed(Keyboard::Down) && KeyTimer > KeyLapse)
    {
        KeyTimer -= KeyLapse;
        MovedDown();
    }
}

int Menu::GetLine()
{
    return this->currentLineIndex;
}