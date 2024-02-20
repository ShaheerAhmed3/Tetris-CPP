#include<iostream>
#include<string>
#include<fstream>
#include<time.h>
#include"Well.h"
#include"I.h"
#include"J.h"
#include"L.h"
#include"O.h"
#include"S.h"
#include"T.h"
#include"Z.h"
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
using namespace std;
using namespace sf;
class Game
{
private:
	RenderWindow window;
	Well grid;            //The Main Well
	Clock clock;          //Clock to measure time for different lvls
	Event event;          //Event to store the input on keyboard from user
	string name;          //The name of the user
	int lines;            
	int score;
	int level;
public:
	Game();                                                   //Default Constructor
	void run();                                               //Runs the game
	void processEvents(Tetrimino*& tptr);                     //Manages the Events
	void render(Tetrimino*& tptr,Sprite);                     //Draws the updated game
	void inputName();                                         //Takes input of name from the user
	void scoreHandling();                                     //Handles the top 5 scores
	void displayEndScreen();                                  //Displays the end score and leaderboard
};
Game::Game():window(VideoMode(1600, 900), "Tetris", Style::Default)     //Default Constructor    
{
	lines = 0;
	score = 0;
	level = 1;
	clock.restart();
	name = "";
}
void Game::inputName()
{
	Font font;                                    //Font
	font.loadFromFile("Font.otf");

	Texture background;                                   //Loads the background image for the name screen
	background.loadFromFile("nameBackground.jpg");
	Sprite b;
	b.setTexture(background);
	b.setPosition(0,0);

	int x = 800, y = 430;                         //The user's input
	Text playerText(name, font, 50);
	playerText.setPosition(x, y);

	string n = "Please Enter Your Name";         //The Enter your name text
	Text text(n, font, 50);
	text.setPosition(375, 350);

	Vector2f s(980, 220);                        //The black box with white border on name screen
	RectangleShape box(s);
	box.setPosition(325, 330);
	box.setOutlineColor(Color::White);
	box.setOutlineThickness(5);
	box.setFillColor(Color::Black);

	Vector2f size(880,80);
	RectangleShape box1(size);                  //The Name Box
	box1.setPosition(375, 425);
	box1.setOutlineThickness(5);
	box1.setOutlineColor(Color::Red);
	box1.setFillColor(Color::Transparent);

	window.pollEvent(event);
	while (event.key.code != Keyboard::Enter)
	{
		while (window.pollEvent(event))
		{
			if (event.key.code == Keyboard::Escape)
				window.close();
			if (event.key.code == Keyboard::Enter || event.key.code == Keyboard::BackSpace)  //To remove the last charachter if user presses backspace
			{
				if (event.key.code == Keyboard::BackSpace && name!="")
				{
					name.pop_back();
					x = x + 20;
				}
			}
			if (event.type == sf::Event::TextEntered)     //Storing User's Input in the variable 'name'
			{
				name += event.text.unicode;
				playerText.setString(name);
				x = x - 20;
				playerText.setPosition(x, y);
			}
			window.clear();                           //Drawing
			window.draw(b);
			window.draw(box);
			window.draw(box1);
			window.draw(text);
			window.draw(playerText);
			window.display();
		}
		window.clear();
		window.draw(b);
		window.draw(box);
		window.draw(box1);
		window.draw(text);
		window.draw(playerText);
		window.display();
	}
	name.pop_back();
	clock.restart();
}
void Game::run()
{
	Texture background;                              //Background behind the game
	background.loadFromFile("Background.jpg");
	Sprite b;
	b.setTexture(background);
	b.setPosition(-500, -500);

	inputName();
	Tetrimino* tptr = nullptr;               //Pointer to store the shape
	Time time_lvl = seconds(1);              //Time variable for implemnting time on different levels
	int temp_lvl = level;                    //Temporary variable used to know when the level is changed
	while (window.isOpen() && grid.gameEnd()==false)
	{
		srand(time(NULL));
		int id;                      //Tells which shape to draw
		if (tptr == nullptr || (*tptr).getCheck() == true)
		{
			id = rand() % 7;
			if (id == 0)
			{
				I shape;
				tptr = &shape;
			}
			else if (id == 1)
			{
				J shape;
				tptr = &shape;
			}
			else if (id == 2)
			{
				L shape;
				tptr = &shape;
			}
			else if (id == 3)
			{
				O shape;
				tptr = &shape;
			}
			else if (id == 4)
			{
				S shape;
				tptr = &shape;
			}
			else if (id == 5)
			{
				T shape;
				tptr = &shape;
			}
			else if (id == 6)
			{
				Z shape;
				tptr = &shape;
			}
		}
		if (level != temp_lvl)  //When level changes, the game becomes faster by 10 percent
		{
			time_lvl = seconds(time_lvl.asSeconds() - 0.1 * time_lvl.asSeconds());
			if (level == 1)
			{
				time_lvl = seconds(1);
			}
			temp_lvl = level;
		}
		if (clock.getElapsedTime().asSeconds() >= time_lvl.asSeconds())  //Moves the tetrimino down after a certain time(according to lvl)
		{
			tptr->MoveDown(grid);
			cout << clock.getElapsedTime().asSeconds() << endl;
			grid.LineChecker(score,lines,level);
			clock.restart();
		}
		processEvents(tptr);
		render(tptr,b);
	}
	scoreHandling();
	displayEndScreen();
}
void Game::processEvents(Tetrimino*& tptr)
{
	while (window.pollEvent(event))
	{
		if(event.type==Event::Closed)                  //Calls the function of the shape respective to the button pressed
			window.close();
		else if (event.type == Event::KeyPressed)
		{
			if (event.key.code == Keyboard::Escape)
				window.close();
			if (event.key.code == Keyboard::Up)
			{
				tptr->Rotate(grid);
			}
			else if (event.key.code == Keyboard::Left)
			{
				tptr->MoveLeft(grid);
			}
			else if (event.key.code == Keyboard::Right)
			{
				tptr->MoveRight(grid);
			}
			else if (event.key.code == Keyboard::Down)
			{
				tptr->MoveDown(grid);
				grid.LineChecker(score,lines,level);
				clock.restart();
			}
		}
	}
}
void Game::render(Tetrimino* &tptr,Sprite b)
{                       
	Texture tetris;                                               //The Tetris Image
	tetris.loadFromFile("Tetris Image.png",IntRect(0,0,410,110));
	Sprite t;
	t.setTexture(tetris);
	t.setPosition(960, 145);

	Font font;                                                   //Font
	font.loadFromFile("Font.otf");
	
	Text text1("Name : "+ name, font, 33);                               //The Name text
	text1.setPosition(920, 300);

	Text text2("Lines : "+ to_string(lines), font, 33);                             //The Lines text
	text2.setPosition(920, 425);

	Text text3("Score : "+ to_string(score), font, 33);                             //The Score text
	text3.setPosition(920, 550);

	Text text4("Level : "+ to_string(level), font, 33);                            //
	text4.setPosition(920, 675);

	int x=900, y=275;                               //Variables For Mapping
	Vector2f size(407, 807);
	Vector2f boxSize(400, 100);
	Vector2f pos(325, 50);

	RectangleShape well(size);                     //The Main grid (well)
	well.setPosition(pos);
	well.setOutlineThickness(5);
	well.setFillColor(Color::Black);

	RectangleShape box1(boxSize);                  //The Name Box
	box1.setPosition(x,y);
	box1.setOutlineThickness(5);
	box1.setOutlineColor(Color::Red);
	box1.setFillColor(Color::Black);

	RectangleShape box2(boxSize);                  //The Line Box
	box2.setPosition(x, y+125);
	box2.setOutlineThickness(5);
	box2.setOutlineColor(Color::Yellow);
	box2.setFillColor(Color::Black);

	RectangleShape box3(boxSize);                  //The Score Box
	box3.setPosition(x, y + 250);
	box3.setOutlineThickness(5);
	box3.setOutlineColor(Color::Blue);
	box3.setFillColor(Color::Black);

	RectangleShape box4(boxSize);                  //The level Box
	box4.setPosition(x, y + 375);
	box4.setOutlineThickness(5);
	box4.setOutlineColor(Color::Green);
	box4.setFillColor(Color::Black);

	window.clear();                 //Clears Old Frame

	window.draw(b);                 //Draws Background
	window.draw(t);                 //Draws the tetris image

	window.draw(well);
	window.draw(box1);
	window.draw(box2);              //Draws all the white outline boxes
	window.draw(box3);
	window.draw(box4);

	window.draw(text1);             //Draws the name, score, level and lines
	window.draw(text2);
	window.draw(text3);
	window.draw(text4);      

	grid.Draw(window);              //Draws the grid
	tptr->Draw(grid,window);        //Draws the shape

	window.display();               //Tells the Game, We're Done Drawing and displays
}
void Game::scoreHandling()
{
	ifstream fin("Scores.txt");
	ifstream fin_n("Names.txt");
	ofstream fout("tempScore.txt");     //File to copy scores
	ofstream fout_n("tempName.txt");    //File to copy names
	bool check = false;
	string tempName;                    //Stores the lines from Names.txt
	string s_num;                       //Stores the lines from Scores.txt
	int i = 0;
	while (getline(fin,s_num) && i<5)
	{
		getline(fin_n, tempName);
		int num = stoi(s_num);
		if (score > num && check==false) 
		{
			fout << score << endl;
			fout_n << name << endl;
			check = true;
			i++;
		}
		else if(check==false)
		{
			fout << num << endl;
			fout_n << tempName << endl;
			i++;
		}
		if (check == true && i!=5)
		{
			fout << num << endl;
			fout_n << tempName << endl;
			i++;
		}
	}
	fin.close();                               //Closes all the files
	fin_n.close();
	fout.close();
	fout_n.close();
	remove("Scores.txt");                      //Deletes the old files
	remove("Names.txt");
	rename("tempName.txt", "Names.txt");       //Renames the new files
	rename("tempScore.txt", "Scores.txt");
}
void Game::displayEndScreen()
{
	Texture background;                               //The background
	background.loadFromFile("nameBackground.jpg");
	Sprite b;
	b.setTexture(background);
	b.setPosition(0, 0);

	ifstream fin;                                     //Reading to print leaderboard
	ifstream fin_n;
	string tempName, num;

	Font font;                                    //Font
	font.loadFromFile("Font.otf");

	Text text1("Score : "+to_string(score), font, 60);       //Score text
	text1.setPosition(550, 100);

	Text text2("Leaderboard", font, 60);                     //Leaderboard text
	text2.setPosition(500, 200);

	Text text3;                                              //Text used in for loop below to print scores and names of leaderboard.
	text3.setCharacterSize(60);
	text3.setFont(font);

	Vector2f s(900, 710);                                    //The black box with the white outline
	RectangleShape box(s);
	box.setPosition(325, 90);
	box.setOutlineColor(Color::White);
	box.setOutlineThickness(5);
	box.setFillColor(Color::Black);

	while (window.isOpen())
	{
		window.pollEvent(event);
		if (event.type == Event::Closed)
				window.close();
		if (event.key.code == Keyboard::Escape)
			window.close();
		window.clear();
		window.draw(b);
		window.draw(box);
		window.draw(text1);
		window.draw(text2);
		fin.open("Scores.txt");
		fin_n.open("Names.txt");
		for (int i = 0; i < 5; i++)
		{
			getline(fin, num);
			getline(fin_n, tempName);
			if (tempName == name && score==stoi(num))
				tempName += "*";
			text3.setString(tempName);
			text3.setPosition(350,300+i*100);
			window.draw(text3);
			text3.setString(":");
			text3.setPosition(830,300+i*100);
			window.draw(text3);
			text3.setString(num);
			text3.setPosition(1000, 300 + i * 100);
			window.draw(text3);
		}
		fin.close();
		fin_n.close();
		window.display();
	}
}