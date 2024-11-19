# Dans ce document nous vous présentons comment fonctione l'interface du jeu (terminal)


#### initialization of the game

Once you start the game you will have an input in wich you can indicate the number of players

you will have this display :
===============================
Please indicate how many players are participating : <input here>

once you have entered the number of players you will have to enter the name for each player :


you will have this display :
exemple for 2 players
============================== 
Initializing Game...
Initializing Players...
Enter the name of the player 0 : <input here>
Enter the name of the player 1 : <input here>

#### start of the game 

once you entered the name of all the players you will to set the base for each one on the board

you will have this display :
===============================
Player A's turn :
        A B C D E F G H I J K L M N O P Q R S T

A       . . . . . . . . . . . E . . . . . . . . 
B       . . . . . . . . . . . . . . . . . . . . 
C       . . . . . . . . . . . . . . . . . . . . 
D       . . . . . . . . . . . . . R . . . . . . 
E       . . . . . . . . . . . . . . . . . . . . 
F       . . . . . . . . . . . . . . . . . . . . 
G       . . . . . . . . . . . . . . . . . . E . 
H       . . . . . . . . . . . . . . . . . . . . 
I       . . . . . . . . . . . . . . . . . . . . 
J       . . . . . . . . . . . . . . . . . . . . 
K       . . . . . . . . . . . . . . . . . . . . 
L       . . . . . . . . . . . . . . E . . . . . 
M       . . . . . . . . . . . . . . . . . . . . 
N       . . . . . . . . . . . . . . . . . . . . 
O       . . . . . . . . . . . . . . . . . . . . 
P       . . . . . . . . . . . . . . . . . . . . 
Q       . . . . . . . . . . . . . . . . . . . . 
R       . . . . . . . . . . S . . . . . . . . . 
S       . . . . . . . . . . . . . . . . . . . . 
T       . . . . . . . . . . . . . . . . . . . R 

Please enter the coordinates of the square you'd like to place your starting tile on x (columns) and y (lines)
x : 
y :


#### main loop 

once all bases have been placed the game will start

you will have in the display the current tile and the next 5 tiles in queue

you will have this display :
============================
exemple : 
Current tile : 
..000.
..0...
..0...
..0...
..0...
000...



 Next tiles :
Tile 1 : 
0.....
00....
0.....
0.....
0.....
......


Tile 2 : 
.0....
.0....
00....
0.....
0.....
......


Tile 3 : 
.00...
.0....
.0....
00....
......
......


Tile 4 :
.0....
.0....
000...
.0....
.0....
......


Tile 5 :
00....
00....
.00...
.0....
.0....
.0....

you will also have a menu with wich you can choose wich action you would like to do

you will have this display :
============================
turns left : 18
Player A's turn :

1- Exchange tile (total : 1)
2- Place tile
3- Rotate tile
4- Flip tile (horizontally)
5- Flip tile (vertically)
6- End turn

Choose your action (1, 2, 3, 4, 5, 6):



1 - if you have a tile exchange coupon you can change the current tile you have with one that is in the queue
your turn doesn't end after this

2 - you can place the current tile you have on the board
after this action you end your turn

3 - you can rotate the current tile you have 
your turn doesn't end after this

4 - you can flip the current tile horizontally
your turn doesn't end after this

5 - you can flip the current tile vertically
your turn doesn't end after this

6 - end your turn 


once there is no more turns left

you will have an option to buy a 1x1 grass tile using a tile exchange coupon

you will have this display :
========================
Game Ended
Last Actions !

Player A's turn :
Player A has 1 exchange coupons
Player A can buy : 1 grass tile(s)

Please enter the coordinates of the square you'd like to place your grass tile on x (columns) and y (lines)
x : 
y :



once the last actions are done the game checks who wins based on who has the largest territory 


GG WP