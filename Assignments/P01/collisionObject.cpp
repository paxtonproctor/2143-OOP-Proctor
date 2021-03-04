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
            - Box - a default constructor that will create size, color, and position
            - drawto  - a function that displays the debris in the window
            - move  - a constructor that allows the box to move
            - setPos  - sets default position and new position of box
            - getPosX  - gets box position of x
            - getPosY  - gets box position of Y
** Member Variable:
        - x -    position of debris x
        - y -    position of debris y
        - Speed -    item sets speed of debris
*/

#pragma

#include <iostream>
#include <SFML\Graphics.hpp>
#include "collisionObject.h"
#include <vector>


// creation of the size and color of the collision object
Box::Box() {
    sf::Vector2f size(20,20);
    box.setSize(size);
    box.setFillColor(sf::Color::Red);
    speed = 0.1;
    x = 50;
    y = 50;
}

// creation of the size and color of the collision object
Box::Box(sf::Vector2f size) {
    box.setSize(size);
    box.setFillColor(sf::Color::Red);
    speed = 0.2;
    x = 50;
    y = 50;
}

// draws the collision object in the window
void Box::drawTo(sf::RenderWindow &window) {
    window.draw(box);
}

void Box::movex(){
    x -= speed;

    if(x < 0){
        x = 600;
        y = (rand() % 555) + 25;
    }
    //std::cout<<x<<std::endl;
    box.setPosition(x,y);
}

// moves the collision object to a certain position based on distance
void Box::move(sf::Vector2f distance) {
    box.move(distance);
}

// creates collision object postion
void Box::setPos(sf::Vector2f newPos){
    box.setPosition(newPos);
    x = newPos.x;
    y = newPos.y;
}

// gets the position of x
float Box::getPosX(){
    return x;
}

// gets the position of y
float Box::getPosY(){
    return y;
}

// gets the speed
float Box::getSpeed(){
    return speed;
}