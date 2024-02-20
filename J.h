class J :public Tetrimino
{
public:
	J()
	{
		x = 4;
		y = 0;
		angle = 0;
		check = false;
	}
	virtual void Rotate(Well const& a)  //Rotates the shape according to angle
	{
		if (angle == 0)
		{
			if ((x - 1 < 0 || a.well[y][x - 1] != 0) && (x - 1 < 0 || y + 1 > 19 || a.well[y + 1][x - 1] != 0))
			{
				if ((y + 1 < 20 && x + 1 < 10 && a.well[y + 1][x + 1] == 0) && (y + 1 < 20 && x + 2 < 10 && a.well[y + 1][x + 2] == 0))
				{
					angle = angle + 90;
				}
			}
			else if (x + 1 > 9 || y + 1 > 19 || a.well[y + 1][x + 1] != 0)
			{
				if ((x - 2 >= 0 && a.well[y][x - 2] == 0) && (y + 1 < 20 && x - 2 >= 0 && a.well[y + 1][x - 2] == 0))
				{
					angle = angle + 90;
					x = x - 2;
				}
			}
			else
			{
				angle = angle + 90;
				x = x - 1;
			}
		}
		else if (angle == 90)
		{
			if (x + 1 > 9 || a.well[y][x + 1] != 0)
			{
				if (( x - 1 >= 0 && a.well[y][x - 1] == 0) && (y + 1 < 20 && x - 1 >= 0 && a.well[y + 1][x - 1] == 0) && (y + 2 < 20 && x - 1 >= 0 && a.well[y + 2][x - 1] == 0))
				{
					angle = angle + 90;
					x = x - 1;
				}
			}
			else if (x + 2 > 9 || a.well[y][x + 2] != 0)
			{
				if ((y + 2 < 20 && a.well[y + 2][x] == 0))
				{
					angle = angle + 90;
				}
			}
			else if (x + 1 > 9 || y + 2 > 19 || a.well[y + 2][x + 1] != 0)
			{
				if ((y - 1 >= 0 && x + 1 < 10 && a.well[y - 1][x + 1] == 0) && (y - 1 >= 0 && x + 2 < 10 && a.well[y - 1][x + 2] == 0))
				{
					angle = angle + 90;
					y = y - 1;
					x = x + 1;
				}
			}
			else
			{
				angle = angle + 90;
				x = x + 1;
			}
		}
		else if (angle == 180)
		{
			if ((x + 1 > 9 || y + 1 > 19 || a.well[y + 1][x + 1] != 0) || (x + 1 > 9 || y + 2 > 19 || a.well[y + 2][x + 1] != 0))
			{
				if ((y + 1 < 20 && x - 2 >= 0 && a.well[y + 1][x - 2] == 0) && (y + 1 < 20 && x - 1 >= 0 && a.well[y + 1][x - 1] == 0))
				{
					angle = angle + 90;
					y = y + 1;
					x = x - 2;
				}
			}
			else if (y + 1 > 19 || x - 1 < 0 || a.well[y + 1][x - 1] != 0)
			{
				if ((y + 1 < 20 && x + 2 < 10 && a.well[y + 1][x + 2] == 0) && (y + 2 < 20 && x + 2 < 10 && a.well[y + 2][x + 2] == 0))
				{
					angle = angle + 90;
					y = y + 1;
				}
			}
			else
			{
				angle = angle + 90;
				y = y + 1;
				x = x - 1;
			}
		}
		else if (angle == 270)
		{
			if ((x + 1 > 9 || y + 1 > 19 || a.well[y + 1][x + 1] != 0) || (y + 1 > 19 || a.well[y + 1][x] != 0))
			{
				if ((y - 2 >= 0 && x + 1 < 10 && a.well[y - 2][x + 1] == 0) && (y - 1 >= 0 && x + 1 < 10 && a.well[y - 1][x + 1] == 0))
				{
					angle = angle + 90;
					y = y - 2;
					x = x + 1;
				}
			}
			else if (y - 1 < 0 || x + 1 > 9 || a.well[y - 1][x + 1] != 0)
			{
				if ((y + 2 < 20 && x + 1 < 10 && a.well[y + 2][x + 1] == 0) && (y + 2 < 20 < 10 && a.well[y + 2][x] == 0))
				{
					angle = angle + 90;
					x = x + 1;
				}
			}
			else
			{
				angle = angle + 90;
				y = y - 1;
				x = x + 1;
			}
			if (angle == 360)
				angle = 0;
		}
	}
	void Draw(Well const& a, RenderWindow& window)   //Draws the shape using the x y coordinates and the angle
	{
		Texture blue;
		blue.loadFromFile("Blue.jpg", IntRect(0, 0, 40, 40));
		Sprite b1, b2, b3, b4;
		b1.setTexture(blue);
		b2.setTexture(blue);
		b3.setTexture(blue);
		b4.setTexture(blue);

		if (angle == 0)
		{
			b1.setPosition(330 + ((x) * 40), 55 + ((y) * 40));
			b2.setPosition(330 + ((x) * 40), 55 + ((y + 1) * 40));
			b3.setPosition(330 + ((x) * 40), 55 + ((y + 2) * 40));
			b4.setPosition(330 + ((x - 1) * 40), 55 + ((y + 2) * 40));
		}
		else if (angle == 90)
		{
			b1.setPosition(330 + ((x) * 40), 55 + ((y) * 40));
			b2.setPosition(330 + ((x) * 40), 55 + ((y + 1) * 40));
			b3.setPosition(330 + ((x + 1) * 40), 55 + ((y + 1) * 40));
			b4.setPosition(330 + ((x + 2) * 40), 55 + ((y + 1) * 40));
		}
		else if (angle == 180)
		{
			b1.setPosition(330 + ((x) * 40), 55 + ((y) * 40));
			b2.setPosition(330 + ((x) * 40), 55 + ((y + 1) * 40));
			b3.setPosition(330 + ((x) * 40), 55 + ((y + 2) * 40));
			b4.setPosition(330 + ((x + 1) * 40), 55 + ((y) * 40));
		}
		else if (angle == 270)
		{
			b1.setPosition(330 + ((x) * 40), 55 + ((y) * 40));
			b2.setPosition(330 + ((x + 1) * 40), 55 + ((y) * 40));
			b3.setPosition(330 + ((x + 2) * 40), 55 + ((y) * 40));
			b4.setPosition(330 + ((x + 2) * 40), 55 + ((y + 1) * 40));
		}
		window.draw(b1);
		window.draw(b2);
		window.draw(b3);
		window.draw(b4);
	}
	void MoveLeft(Well const& a)   //Moves the shape left
	{
		if (angle == 0)
		{
			if (x - 1 > 0 && a.well[y][x - 1] == 0 && a.well[y + 1][x - 1] == 0 && a.well[y + 2][x - 2] == 0)
				x--;
		}
		else if (angle == 90)
		{
			if (x > 0 && a.well[y][x - 1] == 0 && a.well[y + 1][x - 1] == 0)
				x--;
		}
		else if (angle == 180)
		{
			if (x > 0 && a.well[y][x - 1] == 0 && a.well[y + 1][x - 1] == 0 && a.well[y + 2][x - 1] == 0)
				x--;
		}
		else if (angle == 270)
		{
			if (x > 0 && a.well[y][x - 1] == 0 && a.well[y + 1][x + 1] == 0)
				x--;
		}
	}
	virtual void MoveRight(Well const& a)   //Moves the shape right
	{
		if (angle == 0)
		{
			if (x < 9 && a.well[y][x + 1] == 0 && a.well[y + 1][x + 1] == 0 && a.well[y + 2][x + 1] == 0)
				x++;
		}
		else if (angle == 90)
		{
			if (x + 2 < 9 && a.well[y][x + 1] == 0 && a.well[y + 1][x + 3] == 0)
				x++;
		}
		else if (angle == 180)
		{
			if (x + 1 < 9 && a.well[y][x + 2] == 0 && a.well[y + 1][x + 1] == 0 && a.well[y + 2][x + 1] == 0)
				x++;
		}
		else if (angle == 270)
		{
			if (x + 2 < 9 && a.well[y][x + 3] == 0 && a.well[y + 1][x + 3] == 0)
				x++;
		}
	}
	void MoveDown(Well& a)   //Moves the shape down according to the angle. If there is no space, then fixes the shape in the grid.
	{
		if (angle == 0)
		{
			if ((y + 3 < 20) && a.well[y + 3][x] == 0 && a.well[y + 3][x - 1] == 0)
				y++;
			else
			{
				setCheck(true);
				Fix(a);
			}
		}
		else if (angle == 90)
		{
			if ((y + 2 < 20) && a.well[y + 2][x] == 0 && a.well[y + 2][x + 1] == 0 && a.well[y + 2][x + 2] == 0)
				y++;
			else
			{
				setCheck(true);
				Fix(a);
			}
		}
		else if (angle == 180)
		{
			if ((y + 3 < 20) && a.well[y + 1][x + 1] == 0 && a.well[y + 3][x] == 0)
				y++;
			else
			{
				setCheck(true);
				Fix(a);
			}
		}
		else if (angle == 270)
		{
			if ((y + 2 < 20) && a.well[y + 1][x] == 0 && a.well[y + 1][x + 1] == 0 && a.well[y + 2][x + 2] == 0)
				y++;
			else
			{
				setCheck(true);
				Fix(a);
			}
		}
	}
	void Fix(Well& a)
	{
		if (angle == 0)
		{
			a.well[y][x] = 2;
			a.well[y + 1][x] = 2;
			a.well[y + 2][x] = 2;
			a.well[y + 2][x - 1] = 2;
		}
		else if (angle == 90)
		{
			a.well[y][x] = 2;
			a.well[y + 1][x] = 2;
			a.well[y+1][x + 1] = 2;
			a.well[y+1][x + 2] = 2;
		}
		else if (angle == 180)
		{
			a.well[y][x] = 2;
			a.well[y][x + 1] = 2;
			a.well[y + 1][x] = 2;
			a.well[y + 2][x] = 2;
		}
		else if (angle == 270)
		{
			a.well[y][x] = 2;
			a.well[y][x + 1] = 2;
			a.well[y][x + 2] = 2;
			a.well[y + 1][x + 2] = 2;
		}
	}
};