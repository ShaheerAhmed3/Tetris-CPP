#include<SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class Tetrimino
{
protected:
	bool check;               //It checks whether the tetrimino is fixed or not
	int x, y;                //The top left-most co-ordinates of position with respect to Well
	int angle;               //The angle of rotation
public:
	Tetrimino()              //Default Constructor
	{
		check=false;
		x = 0, y = 4;
		angle = 0;
	}
	bool getCheck()        //Getter for Check
	{
		return check;
	}
	void setCheck(bool c)  //Setter for Check
	{
		check = c;
	}
	virtual void Rotate(Well const& a) = 0;                                  //Rotates the shape
	virtual void Draw(Well const& a,RenderWindow &window) = 0;               //Draws the shape
	virtual void MoveLeft(Well const& a) = 0;                                //Moves the shape left
	virtual void MoveRight(Well const& a) = 0;                               //Moves the shape right
	virtual void MoveDown(Well & a) = 0;                                     //Moves the shape down
};