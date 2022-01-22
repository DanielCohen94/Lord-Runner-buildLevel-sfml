#pragma once
#include "Button.h"
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

class Menu : protected Button // inheritance from button
{
public:
	Menu();
	~Menu() = default; 
	void printMenu(sf::RenderWindow &); // draw to window
	sf::Sprite& getSpriteByIndex(int i); 
	void SetOriginalPlace(); // to button of menu

private:

};