#include<SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class Well       //The Main Grid is of 20 X 10
{	
public:
	int** well;
	Well()       //Default Constructor
	{
		well = new int* [20];
		for (int i = 0; i < 20; i++)
			well[i] = new int[10];
		for (int i = 0; i < 20; i++)
			for (int j = 0; j < 10; j++)
				well[i][j] = 0;
	}
	void Draw(RenderWindow &window)   //Draws the well.
	{
		Texture block;
		Sprite b;
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (well[i][j] == 1)
				{
					block.loadFromFile("Violet.jpg");
					b.setTexture(block);
					b.setPosition(330 + (j * 40), 55 + (i * 40));
					window.draw(b);
				}
				else if (well[i][j] == 2)
				{
					block.loadFromFile("Blue.jpg");
					b.setTexture(block);
					b.setPosition(330 + (j * 40), 55 + (i * 40));
					window.draw(b);
				}
				else if (well[i][j] == 3)
				{
					block.loadFromFile("Orange.jpg");
					b.setTexture(block);
					b.setPosition(330 + (j * 40), 55 + (i * 40));
					window.draw(b);
				}
				else if (well[i][j] == 4)
				{
					block.loadFromFile("Yellow.jpg");
					b.setTexture(block);
					b.setPosition(330 + (j * 40), 55 + (i * 40));
					window.draw(b);
				}
				else if (well[i][j] == 5)
				{
					block.loadFromFile("Green.jpg");
					b.setTexture(block);
					b.setPosition(330 + (j * 40), 55 + (i * 40));
					window.draw(b);
				}
				else if (well[i][j] == 6)
				{
					block.loadFromFile("Purple.jpg");
					b.setTexture(block);
					b.setPosition(330 + (j * 40), 55 + (i * 40));
					window.draw(b);
				}
				else if (well[i][j] == 7)
				{
					block.loadFromFile("Red.jpg");
					b.setTexture(block);
					b.setPosition(330 + (j * 40), 55 + (i * 40));
					window.draw(b);
				}
			}
		}
	}
	void LineChecker(int &s,int &l,int &lvl)   //If a line is completed, it ends the line.
	{
		int count = 0;               //Variable to check the line
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 10; j++)
				if (well[i][j] != 0)
					count++;
			if (count == 10)
			{
				for (int k = i; k > 0; k--)
				{
					for (int l = 0; l < 10; l++)
					{
						well[k][l]= well[k-1][l];
					}
				}
				s += 100;   //Increases Scores
				l++;        //Increases the number of lines
				if (l == 10)
				{
					l = 0;
					lvl++;
					if (lvl == 9)   //If lvl becomes 9, game moves to the first lvl
					{
						lvl = 1;
					}
				}
			}
			count = 0;
		}
	}
	bool gameEnd()  //Checks whether the top line of the well is empty
	{
		bool check = false;
		for (int i = 0; i < 10 && check==false; i++)
			if (well[0][i] != 0)
				check = true;
		return check;
	}
	~Well()          //Destructor For Well
	{
		for (int i = 0; i < 20; i++)
			delete[]well[i];
		delete[]well;
	}
};