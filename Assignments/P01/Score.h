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
            - ScoreBoard - a default constructor that will take in a font and create
            a score header
            - drawto  - a function that displays the score in the window
            - Increment  - a default constructor function that will increase score by 1
            - Decrement  - a default constructor function that will increase score by 1
** Member Variable:
        - text -    text
        - font   -    font
        - Points -    item changes score by concatenation
        - Scoreheader -    string that lets me implement a title for score
*/


#pragma

#include <iostream>
#include <SFML\Graphics.hpp>
#include <string>

// creates scoreboard
class Scoreboard {
    private:
        sf::Text text;
        sf::Font font;
        int Points;
        std::string Scoreheader;
    public:
        Scoreboard();
        void drawTo(sf::RenderWindow &window);
        void Increment();
        void Decrement();
};