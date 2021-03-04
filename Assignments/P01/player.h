/*  
**  Name:               Paxton Proctor
**  Assignments:        P01 - game
**  Date:               March, Wednesday 3rd, 2020
**  Course:             OOP - CMPS 2143
**  Professor:          Dr. Griffin
**  About the program:  
**      - a simple program will create a game.
**  How it works:    
        0. Compile and run the program
        1. Program will create a window that has player,debris, and score
        2. Pragram will allow player to move up or down
        3. then will concatenate
**  Member Functions:
        - Public Functions: 
            - player - a constructor that will take create a size of player
            - drawto  - a function that displays the player in the window
            - move  - a constructor that allows the player to move
            - setPos  - sets default position and new position of player
            - getPosX  - gets players position of x
            - getPosY  - gets players position of Y
** Member Variable:
        - x -    position of player x
        - y -    position of player y
        - Player -    item changes score by concatenation
*/
#pragma

#include <iostream>
#include <SFML\Graphics.hpp>
#include <vector>

// creates a player
class player {
    private:
    float x, y;
    // rectangle shape player
    sf::RectangleShape Player;
    public:
    // vector size of player
    player(sf::Vector2f size);

    // will draw player
    void drawTo(sf::RenderWindow &window);

    // will allow player to move
    void move(sf::Vector2f distance);

    // will know the new position everytime the player moves
    void setPos(sf::Vector2f newPos);

    // gets player position
    float getPosX();
    float getPosY();
};