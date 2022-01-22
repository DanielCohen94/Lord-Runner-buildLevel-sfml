#include <vector>
#include "Board.h"
#include "Controller.h"
#include "Menu.h"
#include "macros.h"

Controller::Controller() // constuctor
{
	m_dim.x = 670;
	m_dim.y = 1005;
	m_fts = 60;
	m_title = "LORD RUNNER : level editor";
}

//=========================================================
void Controller::build_map()
{
	auto window = sf::RenderWindow(sf::VideoMode(m_dim.x, m_dim.y), m_title,sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
	window.setFramerateLimit(m_fts);

	Menu menu;
	Board board(window);

	controllerLoop(window, menu, board);
}

//=========================================================
void Controller::controllerLoop(sf::RenderWindow& window, Menu& menu, Board& board)
{
	sf::Sprite mousePicture;
	char c;

	//load background
	sf::Texture Texture;	
	Texture.loadFromFile("background.png");
	sf::Sprite background;
	background.setTexture(Texture);

	while (window.isOpen())
	{
		// draw background, menu, board, mouse 
		window.clear();
		window.draw(background);
		menu.printMenu(window);
		board.printBoard(window);
		window.draw(mousePicture);
		
		if (m_havecursorImg)
		{
			// handele mouse cursor picture 
			mousePicture.setPosition
			(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
			mousePicture.setOrigin(sf::Vector2f(mousePicture.getTexture()->getSize() / 2u));
			mousePicture.setColor(sf::Color(255, 255, 255, 130));
		}
		window.display();

		controller_window(window, mousePicture, menu, board, c);
	}
}

//=========================================================
void Controller::controller_window
(sf::RenderWindow& window, sf::Sprite& mousePicture, Menu& menu, Board& board, char& c)
{
	if (auto event = sf::Event{}; window.waitEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonReleased:
				eventMouse(event, mousePicture, window, menu, board, c);	//events
				break;
		}
	}
}

//=========================================================
void Controller::eventMouse
(sf::Event& event, sf::Sprite& mousePicture,
 sf::RenderWindow& window,Menu& menu, Board& board, char& c)
{
	auto location = window.mapPixelToCoords(
		{ event.mouseButton.x - 5, event.mouseButton.y + 3 });
	// board location on window
	if (location.x > 130 && location.x < 650 && location.y > 100 && location.y < 900)
	{
		//  avarage size cell
		int width = 520 / board.getCols();
		int length = 805 / board.getRows();

		// get place of cell in char vector
		int i = (int)((location.y - 100.f) / (float)length);
		int j = (int)((location.x - 140.f) / (float)width);
		
		// draw just one player
		if (c != PLAYER)
			board.setChar(i, j, c);
		else if (!board.getExistHero())
		{
			board.setChar(i, j, c);
			board.setExistHero(true);
		}
	}
	// menu location on window
	else if (location.x < 150 && location.x > 33 && location.y > 100 && location.y < 905)
	{
		sethavecursorImg(true);
		// update mouse coursor, and char to print 
		if (menu.getSpriteByIndex(PLAYER_OP).getGlobalBounds().contains(location))
		{
			mousePicture = menu.getSpriteByIndex(PLAYER_OP);
			c = PLAYER;
		}
		else if (menu.getSpriteByIndex(MONSTER_OP).getGlobalBounds().contains(location))
		{
			mousePicture = menu.getSpriteByIndex(MONSTER_OP);
			c = MONSTER;
		}
		else if (menu.getSpriteByIndex(COIN_OP).getGlobalBounds().contains(location))
		{
			mousePicture = menu.getSpriteByIndex(COIN_OP);
			c = COIN;
		}
		else if (menu.getSpriteByIndex(FLOOR_OP).getGlobalBounds().contains(location))
		{
			mousePicture = menu.getSpriteByIndex(FLOOR_OP);
			c = FLOOR;
		}
		else if (menu.getSpriteByIndex(ROPES_OP).getGlobalBounds().contains(location))
		{
			mousePicture = menu.getSpriteByIndex(ROPES_OP);
			c = ROPES;
		}
		else if (menu.getSpriteByIndex(LADDER_OP).getGlobalBounds().contains(location))
		{
			mousePicture = menu.getSpriteByIndex(LADDER_OP);
			c = LADDER;
		}
		else if (menu.getSpriteByIndex(EMPTY_OP).getGlobalBounds().contains(location))
		{
			mousePicture = menu.getSpriteByIndex(EMPTY_OP);
			c = EMPTY;
		}
		else if (menu.getSpriteByIndex(REFRESH_OP).getGlobalBounds().contains(location))
		{
			board.refresh(window);
			c = EMPTY;
			sethavecursorImg(false);
		}
		else if (menu.getSpriteByIndex(SAVE_OP).getGlobalBounds().contains(location))
		{
			board.saveBoardToFile();
		}
	}
}

//=========================================================
void Controller::sethavecursorImg(bool b)
{
	m_havecursorImg = b;
}

