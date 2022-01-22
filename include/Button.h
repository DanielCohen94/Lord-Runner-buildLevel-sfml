#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class Button
{
public:
	Button();
	~Button() = default;
	void loadTextureName();		//load from text 
	void loadTexture();         //load texturs & sprits menu
	sf::Sprite& getSprite(int);
private:

protected:
	std::string m_texture_name[10]; // button and backround
	std::vector<sf::Texture> m_texture;
	std::vector<sf::Sprite> m_sprite;
};