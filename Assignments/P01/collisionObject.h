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

#include <SFML\Graphics.hpp>
#include <vector>

// creates a collision object
class Box {
    private:
    float x;
    float y;
    float speed;
    // variable box is created as a
    sf::RectangleShape box;
    public:
    Box();
    // will create size of box
    Box(sf::Vector2f size);
    // will draw box
    void drawTo(sf::RenderWindow &window);
    // will move box
    void move(sf::Vector2f distance);
    void movex();
    void movey();
    // will set starting position of box
    void setPos(sf::Vector2f newPos);

    // gets positions and speed
    float getPosX();
    float getPosY();
    float getSpeed();
};