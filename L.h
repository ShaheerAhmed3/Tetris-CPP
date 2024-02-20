class L :public Tetrimino
{
public:
	L()
	{
		x = 4;
		y = 0;
		angle = 0;
		check = false;
	}
	void Rotate(Well const& a)   //Rotates the shape according to angle
	{
		if (angle == 0)
		{
			if ((x - 1 < 0 || y + 1 > 19 || a.well[y + 1][x - 1] != 0) || (x - 1 < 0 || y + 2 > 19 || a.well[y + 2][x - 1] != 0))
			{
				if ((y + 1 < 20 && x + 1 < 10 && a.well[y + 1][x + 1] == 0) && (y + 1 < 20 && x + 2 < 10 && a.well[y + 1][x+2] == 0))
				{
					angle = angle + 90;
					y = y + 1;
				}
			}
			else if (x + 1 > 9 || y + 1 > 19 || a.well[y + 1][x + 1] != 0)
			{
				if ((y + 1 < 20 && x - 2 >= 0 && a.well[y + 1][x - 2] == 0) && (y + 2 < 20 && x - 2 >= 0 && a.well[y + 2][x - 2] == 0))
				{
					angle = angle + 90;
					y = y + 1;
					x = x - 2;
				}
			}
			else
			{
				angle = angle + 90;
				x = x - 1;
				y = y + 1;
			}
		}
		else if (angle == 90)
		{
			if (x + 1 > 9 || y - 1 < 0 || a.well[y - 1][x + 1] != 0)
			{
				if ((y - 1 >= 0 && x + 2 < 10 && a.well[y-1][x + 2] == 0) && (y - 1 >= 0 && x + 3 < 10 && a.well[y - 1][x + 3] == 0) && (x + 3 < 10 && a.well[y][x+3] == 0) && (y + 1 < 20 && x + 3 < 10 && a.well[y + 1][x+3] == 0))
				{
					angle = angle + 90;
					y = y - 1;
					x = x + 2;
				}
			}
			else if (y - 1 < 0 || a.well[y - 1][x] != 0)
			{
				if ((y - 1 >= 0 && x + 2 < 10 && a.well[y - 1][x + 2] == 0) && (y + 1 < 20 && x + 2 < 10 && a.well[y + 1][x + 2] == 0))
				{
					angle = angle + 90;
					y = y - 1;
					x = x + 1;
				}
			}
			else if (x + 1 > 9 || y + 1 > 19 || a.well[y + 1][x + 1] != 0)
			{
				if ((y - 2 >= 0 && a.well[y - 2][x] == 0) && (y - 2 >= 0 && x + 1 < 10 && a.well[y - 2][x + 1] == 0))
				{
					angle = angle + 90;
					y = y - 2;
				}
			}
			else
			{
				angle = angle + 90;
				y = y - 1;
			}
		}
		else if (angle == 180)
		{
			if ((x + 2 > 9 || a.well[y][x + 2] != 0) || (x + 2 > 9 || y + 1 > 19 || a.well[y + 1][x + 2] != 0))
			{
				if ((y + 1 < 20 && a.well[y + 1][x] == 0) && (y + 1 < 20 && x - 1 >= 0 && a.well[y + 1][x - 1] == 0))
				{
					angle = angle + 90;
					y = y + 1;
					x = x - 1;
				}
			}
			else if (y + 1 > 19 || a.well[y + 1][x] != 0)
			{
				if ((x + 3 < 10 && a.well[y][x + 3] == 0) && (y + 1 < 20 && x + 3 < 10 && a.well[y + 1][x + 3] == 0))
				{
					angle = angle + 90;
					y = y + 1;
					x = x + 1;
				}
			}
			else
			{
				angle = angle + 90;
				y = y + 1;
			}
		}
		else if (angle == 270)
		{
			if ((x + 1 > 9 || y + 1 > 19 || a.well[y + 1][x + 1] != 0) || (x + 2 > 9 || y + 1 > 19 || a.well[y + 1][x + 2] != 0))
			{
				if ((y - 2 >= 0 && x + 1 < 10 && a.well[y - 2][x + 1] == 0) && (y - 1 >= 0 && x + 1 < 10 && a.well[y - 1][x + 1] == 0))
				{
					angle = angle + 90;
					y = y - 2;
					x = x - 1;
				}
			}
			else if (y - 1 < 0 || x + 1 > 9 || a.well[y - 1][x + 1] != 0)
			{
				if ((y + 2 < 20 && x + 1 < 10 && a.well[y + 2][x + 1] == 0) && (y + 2 < 20 && x + 2 < 10 && a.well[y + 2][x + 2] == 0))
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
		Texture orange;
		orange.loadFromFile("Orange.jpg", IntRect(0, 0, 40, 40));
		Sprite b1, b2, b3, b4;
		b1.setTexture(orange);
		b2.setTexture(orange);
		b3.setTexture(orange);
		b4.setTexture(orange);

		if (angle == 0)
		{
			b1.setPosition(330 + ((x) * 40), 55 + ((y) * 40));
			b2.setPosition(330 + ((x) * 40), 55 + ((y+1) * 40));
			b3.setPosition(330 + ((x) * 40), 55 + ((y+2) * 40));
			b4.setPosition(330 + ((x + 1) * 40), 55 + ((y + 2) * 40));
		}
		else if (angle == 90)
		{
			b1.setPosition(330 + ((x) * 40), 55 + ((y) * 40));
			b2.setPosition(330 + ((x) * 40), 55 + ((y + 1) * 40));
			b3.setPosition(330 + ((x+1) * 40), 55 + ((y) * 40));
			b4.setPosition(330 + ((x + 2) * 40), 55 + ((y) * 40));
		}
		else if (angle == 180)
		{
			b1.setPosition(330 + ((x) * 40), 55 + ((y) * 40));
			b2.setPosition(330 + ((x+1) * 40), 55 + ((y) * 40));
			b3.setPosition(330 + ((x+1) * 40), 55 + ((y + 1) * 40));
			b4.setPosition(330 + ((x + 1) * 40), 55 + ((y+2) * 40));
		}
		else if (angle == 270)
		{
			b1.setPosition(330 + ((x) * 40), 55 + ((y) * 40));
			b2.setPosition(330 + ((x+1) * 40), 55 + ((y) * 40));
			b3.setPosition(330 + ((x+2) * 40), 55 + ((y) * 40));
			b4.setPosition(330 + ((x + 2) * 40), 55 + ((y - 1) * 40));
		}
		window.draw(b1);
		window.draw(b2);
		window.draw(b3);
		window.draw(b4);
	}
	void MoveLeft(Well const& a)    //Moves the shape left
	{
		if (angle == 0)
		{
			if (x > 0 && a.well[y][x - 1] == 0 && a.well[y + 1][x-1] == 0 && a.well[y + 2][x - 1] == 0)
				x--;
		}
		else if (angle == 90)
		{
			if (x > 0 && a.well[y][x - 1] == 0 && a.well[y + 1][x - 1] == 0)
				x--;
		}
		else if (angle == 180)
		{
			if (x > 0 && a.well[y][x - 1] == 0 && a.well[y + 1][x] == 0 && a.well[y + 2][x] == 0)
				x--;
		}
		else if (angle == 270)
		{
			if (x > 0 && a.well[y][x - 1] == 0 && a.well[y - 1][x + 1] == 0)
				x--;
		}
	}
	void MoveRight(Well const& a)      //Moves the shapes right
	{
		if (angle == 0)
		{
			if (x + 1 < 9 && a.well[y][x + 1] == 0 && a.well[y + 1][x + 1] == 0 && a.well[y + 2][x + 2] == 0)
				x++;
		}
		else if (angle == 90)
		{
			if (x + 2 < 9 && a.well[y+1][x + 1] == 0 && a.well[y][x + 3] == 0)
				x++;
		}
		else if (angle == 180)
		{
			if (x + 1 < 9 && a.well[y][x + 2] == 0 && a.well[y + 1][x + 2] == 0 && a.well[y + 2][x + 2] == 0)
				x++;
		}
		else if (angle == 270)
		{
			if (x + 2 < 9 && a.well[y][x + 3] == 0 && a.well[y - 1][x + 3] == 0)
				x++;
		}
	}
	void MoveDown(Well& a)   //Moves the shape down according to the angle. If there is no space, then fixes the shape in the grid.
	{
		if (angle == 0)
		{
			if ((y + 3 < 20) && a.well[y + 3][x] == 0 && a.well[y + 3][x + 1] == 0)
				y++;
			else
			{
				setCheck(true);
				Fix(a);
			}
		}
		else if (angle == 90)
		{
			if ((y + 2 < 20) && a.well[y + 2][x] == 0 && a.well[y + 1][x + 1] == 0 && a.well[y + 1][x + 2] == 0)
				y++;
			else
			{
				setCheck(true);
				Fix(a);
			}
		}
		else if (angle == 180)
		{
			if ((y + 3 < 20) && a.well[y + 1][x] == 0 && a.well[y + 3][x + 1] == 0 )
				y++;
			else
			{
				setCheck(true);
				Fix(a);
			}
		}
		else if (angle == 270)
		{
			if ((y + 1 < 20) && a.well[y + 1][x] == 0 && a.well[y + 1][x + 1] == 0 && a.well[y + 1][x + 2] == 0)
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
			a.well[y][x] = 3;
			a.well[y+1][x] = 3;
			a.well[y+2][x] = 3;
			a.well[y + 2][x + 1] = 3;
		}
		else if (angle == 90)
		{
			a.well[y][x] = 3;
			a.well[y + 1][x] = 3;
			a.well[y][x+1] = 3;
			a.well[y][x + 2] = 3;
		}
		else if (angle == 180)
		{
			a.well[y][x] = 3;
			a.well[y][x + 1] = 3;
			a.well[y+1][x + 1] = 3;
			a.well[y + 2][x + 1] = 3;
		}
		else if (angle == 270)
		{
			a.well[y][x] = 3;
			a.well[y][x+1] = 3;
			a.well[y][x+2] = 3;
			a.well[y - 1][x + 2] = 3;
		}
	}
};