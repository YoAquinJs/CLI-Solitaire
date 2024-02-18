# CLI-Solitaire

### Classic solitaire game for my Object-oriented Programming class

Using g++ compiler (version 13). Commands to compile:

* Windows

`g++ gameLogic/*.cpp classes/*.cpp -o main main.cpp`

* Linux

`g++-13 gameLogic/*.cpp classes/*.cpp -o main main.cpp`

#### How to play

The game contains 2 cursors, one blue representing the origin card, and a yellow representing the movement's destination position.

To play insert a command or direction for the cursors:
* Directions: (**w**) up | (**a**) left | (**s**) down | (**d**) right
* (**k**) To lock the blue cursor, which shows the yellow cursor
* (**k**) To unlock the blue cursor, which hides the yellow cursor
* (**j**) To perform a movement from blue cursor to yellow cursor, or to get a card from the draw pile (only action which doesn't require the yellow cursor to be unlocked)
