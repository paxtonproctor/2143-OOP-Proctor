/*  
**  Name:               Paxton Proctor
**  Assignments:        P01 - Game
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
*/
#include <iostream>
#include <SFML/Graphics.hpp>
#include "player.h"
#include "collisionObject.h"
#include <vector>
#include "Score.h"

// C:\Users\Paxton\Desktop\Code>g++ -c *.cpp -Lsrc/include

// C:\Users\Paxton\Desktop\Code>g++ *.o -o sfml-hold -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system 

int main()
{
    // creation of a window that will be placed in the center of the screen
    sf::RenderWindow window;
    sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width /2) - 445,
    (sf::VideoMode::getDesktopMode().height / 2) - 390);

    window.create(sf::VideoMode(600,600), "SFML GAME Paxton Proctor", sf::Style::Titlebar | sf::Style::Close);
    window.setPosition(centerWindow);

    window.setKeyRepeatEnabled(true);

    // player object and the position and size
    player Player({ 20,20 });
    Player.setPos({ 50,80 });
    // this bool will determine if a key is pressed or not
    bool moving = false;

    // Collision object and the position and size
    Box box({ 20,20});
    box.setPos({100,180});
    float randY;

    // creation of scoreboard
    Scoreboard scoreBoard;

    // creation of window and events within window
    while (window.isOpen())
    {
        sf::Event event;

        // movement speed of player
        const float moveSpeed = 0.1;

        // creates a keybind for the player to move up or down
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            //player movement up
            Player.move({0, -moveSpeed });
            // changes the bool to true since key is pressed
            moving = true;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
             //player movement down
            Player.move({0, moveSpeed });
            // changes the bool to true since key is pressed
            moving = true;
        }

        //will create a x and y collision boundary between the player and collision object
        //std::cout << Player.getPosY()<< " Paxtonwashere";
        if (box.getPosY() - 20 <= Player.getPosY() && Player.getPosY() <= box.getPosY() + 20){
            //std::cout << "Paxtonwashere";
            if(Player.getPosX() - 20 <= box.getPosX() && box.getPosX() <= Player.getPosX() + 20){
                //std::cout << "Paxtonwashere";
                //Decrements 1 from the score when player collides with object
                scoreBoard.Decrement();

                // Creates a rand debris spawn
                randY = (rand() % 555) + 25;
                box.setPos({600,randY});
            }
        }
        // Increments 1 from the score when object exits the window
        if (box.getPosX() <= box.getSpeed()){
            scoreBoard.Increment();
        }
        // event to close the window and for key release with bool
        while (window.pollEvent(event)) {
            switch (event.type){
            
            case sf::Event::Closed:
                window.close();

            case sf::Event::KeyReleased:
                moving = false;
            }
        }
        // moves the debris
        box.movex();
        
        window.clear();
        // draws both player and collision object
        Player.drawTo(window);
        box.drawTo(window);
        scoreBoard.drawTo(window);
        // displays the objects
        window.display();
    }

    return 0;
}

