a)  Game Information:
  1)  The game is entirely written in C++ and SFML.
  2)  In order to run this on Visual Studio, SFML must be installed and integrated with it.
  3)  All the pngs for the tetris blocks are custom made.

b)  Game Instructions:
  1)  This is the classic Tetris we all know and love but with some tweaks.
  2)  This program will allow the user to play the game Tetris with the well of size 20x10 squares.
  3)   A randomly chosen Tetrimino fall in the well and user can shift its position right or left using arrow keys.
  4)   User can also rotate the falling Tetrimino using the Up key and increase the speed of descent using down key.
  5)   Up arrow: rotate the falling Tetrimino clockwise by 90 degrees
  6)   Left arrow: move left the falling Tetrimino by one square to the left if possible
  7)   Right arrow: move right the falling Tetrimino by one square to the right if possible
  8)   Down arrow: Increase the speed of falling Tetrimino
  9)   At every step during the fall, the game checks whether it should stop the fall of current Tetrimino or not.
  10)   If yes then it also checks for the completion of horizontal line in the well. If the line has completed then move all the squares above that line one square down
  11)   Otherwise a new Tetrimino is chosen randomly to fall
  12)   The game should end if no more Tetrimino can be placed in the well from above
  13)   On completion of each horizontal line, the player will earn 100 points
  14)   Upon completion of 10 lines the user will be promoted to next level of the game
  15)   Initially the Tetrimeno will descent at the rate of 1 sec per square fall
  16)   At each successive level the speed of Tetrimeno descent will be increased by 10%
  17)   After completion of 8 levels the game will continue at level 1
