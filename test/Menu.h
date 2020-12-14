#pragma once
#include "SFML\Graphics.hpp"
#include <iostream>
using namespace sf;

#define NUM_OF_LINE 4

class Menu
{
public:
    Menu(float width, float height);
    ~Menu();
    void buttoncheck(const int button);

    const sf::FloatRect getBounds_0() const;
    const sf::FloatRect getBounds_1() const;
    const sf::FloatRect getBounds_2() const;
    const sf::FloatRect getBounds_3() const;
    void Draw(RenderWindow* window);
    void Drawhowto(RenderWindow* window);
    void Drawhigh(RenderWindow* window);
    void Drawname(RenderWindow* window);
    void Drawmenu(RenderWindow* window);

    void MoveUp();
    void MovedDown();
    void MenuUpdate(float dt);
    int GetLine();

private:
    int currentLineIndex;
    Font font;
    Text text[NUM_OF_LINE];
    float KeyTimer;
    float KeyLapse;

    sf::Texture menutextures;
    sf::Sprite menusprite;

    sf::Texture howtotextures;
    sf::Sprite howtosprite;

    sf::Texture hightextures;
    sf::Sprite highsprite;

    sf::Texture nametextures;
    sf::Sprite namesprite;
};