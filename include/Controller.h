#pragma once
#include "SFML/Graphics.hpp"
#include "Button.h"
#include "Board.h"
#include "Menu.h"
class Controller
{
public:
	Controller(); 
	~Controller() = default;
	void build_map();
	void controllerLoop(sf::RenderWindow&, Menu&, Board&);
	void controller_window(sf::RenderWindow&, sf::Sprite&, Menu&, Board&, char&);
	void eventMouse
	(sf::Event&, sf::Sprite&, sf::RenderWindow& window, Menu& menu, Board& board, char&);
	void sethavecursorImg(bool);

private:
	bool m_havecursorImg = false;
	sf::Vector2u m_dim; // size of window
	std::string m_title;
	int m_fts;
};
