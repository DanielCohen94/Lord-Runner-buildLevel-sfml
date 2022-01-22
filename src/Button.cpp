#include "Button.h"
#include <iostream>

Button::Button() // constructor
{
	loadTextureName();
	loadTexture();
}

//====================================================
void Button::loadTextureName()		//load from text 
{
	m_texture_name[0] = "hero.png";
	m_texture_name[1] = "monster.png";
	m_texture_name[2] = "coin.png";
	m_texture_name[3] = "wall.png";
	m_texture_name[4] = "ropes.png";
	m_texture_name[5] = "ladder.png";
	m_texture_name[6] = "delete.png";
	m_texture_name[7] = "save.png";
	m_texture_name[8] = "refresh.png";
	m_texture_name[9] = "empty.png";
}

//====================================================
void Button::loadTexture()		//load texturs & sprits menu
{
	for (int i = 0; i < sizeof( m_texture_name ) / sizeof( m_texture_name[ 0 ] ); i++)
	{
		sf::Texture objTexture;
		objTexture.loadFromFile(m_texture_name[i]);
		m_texture.push_back(objTexture);
	}

	for (int i = 0; i < sizeof(m_texture_name) / sizeof(m_texture_name[0]); i++)
	{
		sf::Sprite objSprite;
		objSprite.setTexture(m_texture[i]);
		m_sprite.push_back(objSprite);
		m_sprite[i].setPosition(300.f, (float)(i*100));
	}
}

//====================================================
sf::Sprite& Button::getSprite(int i)
{
	return m_sprite[i];
}