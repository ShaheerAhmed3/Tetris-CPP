class O :public Tetrimino
{
public:
	O()     //Angle is zero
	{
		x = 4;
		y = 0;
		angle = 0;
		check = false;
	}
	void Rotate(Well const& a){}                     //Rotates the shape
	void Draw(Well const& a, RenderWindow& window)   //Draws the shape using the x y coordinates and the angle
	{
		Texture yellow;
		yellow.loadFromFile("Yellow.jpg", IntRect(0, 0, 40, 40));
		Sprite b1, b2, b3, b4;
		b1.setTexture(yellow);
		b2.setTexture(yellow);
		b3.setTexture(yellow);
		b4.setTexture(yellow);

		b1.setPosition(330 + ((x) * 40), 55 + ((y) * 40));
		b2.setPosition(330 + ((x) * 40), 55 + ((y + 1) * 40));
		b3.setPosition(330 + ((x + 1) * 40), 55 + ((y) * 40));
		b4.setPosition(330 + ((x + 1) * 40), 55 + ((y + 1) * 40));

		window.draw(b1);
		window.draw(b2);
		window.draw(b3);
		window.draw(b4);
	}
	void MoveLeft(Well const& a)  //Moves the shape left
	{
		if (x > 0 && a.well[y][x - 1] == 0 && a.well[y + 1][x - 1] == 0)
			x--;
	}
	void MoveRight(Well const& a) //Moves the shape right
	{
		if (x+1 < 9 && a.well[y][x + 2] == 0 && a.well[y + 1][x + 2] == 0 )
			x++;
	}
	void MoveDown(Well & a)  //Moves the shape down. If there is no space, then fixes the shape in the grid.
	{
		if ((y + 2 < 20) && a.well[y + 2][x] == 0 && a.well[y + 2][x + 1] == 0)
			y++;
		else
		{
			setCheck(true);
			Fix(a);
		}
	}
	void Fix(Well& a)
	{
		a.well[y][x] = 4;
		a.well[y][x + 1] = 4;
		a.well[y + 1][x] = 4;
		a.well[y + 1][x + 1] = 4;
	}
};