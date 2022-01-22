#include <vector>
#include "Menu.h"
#include "macros.h"

Menu::Menu() // constuctor
{
	SetOriginalPlace();
}

//=========================================================
void Menu::SetOriginalPlace() // set the button to right place
{
	for (int i = 0; i < NUM_BUTTONS; i++)
		m_sprite[i].setPosition(0.f + 33.f, (float)(i * 90) + 85.f);
}

//=========================================================
void Menu::printMenu(sf::RenderWindow& window) // draw menu
{
	for (int i = 0; i < NUM_BUTTONS; i++)
		window.draw(m_sprite[i]);
}

//=========================================================
sf::Sprite& Menu::getSpriteByIndex(int i) // use button function
{
	return getSprite(i);
}