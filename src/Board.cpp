#include "Board.h"
#include "macros.h"

using std::string;
using std::ifstream;

Board::Board(sf::RenderWindow & window) // constructor
{
	if (loadLevel())
		printBoard(window);
	else
	{
		refresh(window);
	}
}

//=========================================================
void Board::loadStartbackground(sf::RenderWindow& window)
{
	sf::Texture Texture;
	Texture.loadFromFile("start_background.png");
	sf::Sprite background;
	background.setTexture(Texture);
	window.draw(background);
	window.display();
}

//=========================================================
void Board::refresh(sf::RenderWindow& window)
{
	loadStartbackground(window);
	newRowAndColVal();	//open terminal
	resizeBoard();
	fullByEmpty();
	setExistHero(false);
}

//=========================================================
void Board::fullByEmpty()
{
	for (int i = 0;i < getRows();i++)
		for (int j = 0; j < getCols();j++)
		{
			m_saveBoard[i][j] = EMPTY;
		}
}

//=========================================================
void Board::newRowAndColVal()	//read from terminal
{
	std::cout << "Please Enter Number of Rows: ";
	std::cin  >> m_rows;
	std::cout << std::endl << "Please Enter Number of Cols: ";
	std::cin  >> m_cols;
}

//=========================================================
void Board::printBoard(sf::RenderWindow& window)
{
	int x, y;
	x = y = 0;
	sf::RectangleShape rec;
	
	// avarage cell
	float width_s = 520.f / float(m_cols);
	float lentgh_s = 805.f / float (m_rows);

	rec.setSize(sf::Vector2f(width_s, lentgh_s));

	for (int i = 0;i < getRows();i++)
	{
		for (int j = 0; j < getCols();j++)
		{
			rec.setPosition(140.f + (float)(x * width_s), 100.f + (float)(y * lentgh_s));
			// for every cell draw on window
			switch (m_saveBoard[i][j])
			{	
				case PLAYER:
					rec.setTexture((m_sprite[0].getTexture()));
					window.draw(rec);
					break;
				case MONSTER:
					rec.setTexture(m_sprite[1].getTexture());
					window.draw(rec);
					break;
				case COIN:
					rec.setTexture(m_sprite[2].getTexture());
					window.draw(rec);
					break;
				case FLOOR:
					rec.setTexture(m_sprite[3].getTexture());
					window.draw(rec);
					break;
				case ROPES:
					rec.setTexture(m_sprite[4].getTexture());
					window.draw(rec);
					break;
				case LADDER:
					rec.setTexture(m_sprite[5].getTexture());
					window.draw(rec);
					break;
				case EMPTY:
					rec.setTexture(m_sprite[9].getTexture());
					window.draw(rec);
					break;
			}

			// loop on board
			if (x < getCols())
				x++;
			if (x == getCols())
			{
				if (y < getRows())
					y++;
				x = 0;
			}
		}
	}
}

//=========================================================
bool Board::loadLevel()
{
	ifstream file_if("Board.txt");

	if (!file_if.is_open())	// file not found
		return false;

	string num;
	char c;
	int x = 0, y = 0;

	// get rows and cols from terminal
	file_if >> num;
	setRows(stoi(num));

	file_if >> num;
	setCols(stoi(num));

	resizeBoard();

	file_if.get(c); // eat '\n'

	for (int i = 0; i < getRows();i++)
	{
		for (int j = 0; j < getCols();j++)
		{
			file_if.get(c);
			if (c == PLAYER)
				setExistHero(true);
			m_saveBoard[i][j] = c;
		}
		file_if.get(c);
	}

	file_if.close();

	return true;
}

//=========================================================
void Board::resizeBoard()
{
	m_saveBoard.resize(getRows());

	for (int i = 0; i < getRows(); i++)
		m_saveBoard[i].resize(getCols());
}

//=========================================================
sf::Sprite& Board::getSprite(int i)
{
	return m_sprite[i];
}

//=========================================================
int Board::getRows() const
{
	return m_rows;
}

//=========================================================
int Board::getCols() const
{
	return m_cols;
}

//=========================================================
void Board::setChar(int i, int j, char c)
{
	if (i < getRows() && j < getCols())
	{
		if (c == EMPTY && m_saveBoard[i][j] == PLAYER) // delete hero
			setExistHero(false);

		if(m_saveBoard[i][j] == EMPTY || c == EMPTY) // empty cell or delete
			m_saveBoard[i][j] = c;
	}
}

//=========================================================
void Board::saveBoardToFile()	//save Board.txt to 'out' folder
{
	std::ofstream file_of;
	file_of.open("Board.txt"); 

	file_of << getRows() << " " << getCols() << std::endl;

	for (int i = 0; i < getRows(); i++)
	{
		for (int j = 0; j < getCols(); j++)
		{
			file_of << m_saveBoard[i][j];
		}
		file_of << std::endl;
	}
	file_of.close();

	std::cout << "File saved!\n";
}

//=========================================================
void Board::setExistHero(bool b)
{
	m_existHero = b;
}

//=========================================================
bool Board::getExistHero() const
{
	return m_existHero;
}

//=========================================================
void Board::setRows(int num)
{
	m_rows = num;
}

//=========================================================
void Board::setCols(int num)
{
	m_cols = num;
}