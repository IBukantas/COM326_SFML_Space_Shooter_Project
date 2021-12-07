/*
*   COM326 - SFML space shooter game with player interaction, and auditory & visual feedback/output
*
*   Using SFML libraries and C++
*   Author: Group Irmanluk
*   Date: 07/12/2021
*/

 /*
 *  References
 *  https://www.sfml-dev.org/learn.php
 *  https://www.youtube.com/watch?v=BySDfVNljG8&list=PL6xSOsbVA1eb_QqMTTcql_3PdOiE928up
 *  https://mixkit.co/free-sound-effects
 *  https://freesound.org
 *  https://zintoki.itch.io/space-breaker 
 *  https://www.rustafied.com/component-system-guide
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