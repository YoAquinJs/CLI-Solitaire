# Terminal-Solitarie

### Classic solitarie game for my Object oriented Programming class

Using g++ compiler (version 13). Commands to compile:

* Windows

`g++ gameLogic/*.cpp classes/*.cpp -o main main.cpp`

* Linux

`g++-13 gameLogic/*.cpp classes/*.cpp -o main main.cpp`

#### How to play

The game contains 2 cursors, one blue which represents the origin card, and a yellow one which represents the destination position of a movement.

To play insert a command or direction for the cursors:
* Directions: (**w**) up | (**a**) left | (**s**) down | (**d**) right
* (**l**) To lock the blue cursor, this unlocks the yellow cursor and the movement commands are now for the yellow cursor.
* (**k**) To unlock the blue cursor, which locks the yellow cursor and restore the movement commands to the blue cursor
* (**j**) To perform a movement from blue cursor to yellow cursor, or to get a card from the draw pile (only action which doesn't require the yellow cursor to be unlocked)