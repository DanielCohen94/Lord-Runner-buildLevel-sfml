#pragma once
#include <fstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Button.h"

class Board : protected Button // inheritance from button
{
public:
	Board(sf::RenderWindow &);
	~Board() = default;
	bool loadLevel();
	void resizeBoard(); 
	void printBoard(sf::RenderWindow& );
	void newRowAndColVal();		//open terminal
	sf::Sprite& getSprite(int); // using Button get Sprite
	void fullByEmpty(); 
	void setRows(int);
	int getRows() const;
	void setCols(int);
	int getCols() const;
	void setChar(int i, int j,char);
	void loadStartbackground(sf::RenderWindow& );
	void saveBoardToFile();
	void refresh(sf::RenderWindow& ); // using also to refresh button 
	void setExistHero(bool); 
	bool getExistHero() const;

private:
	std::vector<std::vector<char>> m_saveBoard;
	bool m_existHero = false; 
	int m_rows;
	int m_cols;
};