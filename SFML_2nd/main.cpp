/*
*   Classname or filename
*
*   Version information
*   Author:
*   Date:
* 
*   Copyright notice
*/

#include "Game.h"

#include<time.h>

int main() {
    // Initialize random variable
    srand(time(0));

    // Create game class
    Game game;

    // Game loop
    game.run();

    // End of application
    return 0;
}