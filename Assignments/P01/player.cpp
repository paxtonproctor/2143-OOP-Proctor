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
#include "player.h"
#include <vector>

// creation of the size and color of the player
player::player(sf::Vector2f size) {
    Player.setSize(size);
    Player.setFillColor(sf::Color::Green);
}

// draws the player in the window
void player::drawTo(sf::RenderWindow &window) {
    window.draw(Player);
}

// moves the player to a certain position based on distance
void player::move(sf::Vector2f distance) {
    Player.move(distance);
    x += distance.x;
    y += distance.y;
}

// creates player postion
void player::setPos(sf::Vector2f newPos){
    Player.setPosition(newPos);
    x = newPos.x;
    y = newPos.y;
}

float player::getPosX(){
    return x;
}

float player::getPosY(){
    return y;
}