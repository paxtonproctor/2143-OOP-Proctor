#include <iostream>
#include <SFML/Graphics.hpp>
#include "player.h"
#include "collisionObject.h"
#include <vector>

// C:\Users\Paxton\Desktop\Code>g++ -c *.cpp -Lsrc/include

// C:\Users\Paxton\Desktop\Code>g++ *.o -o sfml-hold -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system 

int main()
{
    // creation of a window that will be placed in the center of the screen
    sf::RenderWindow window;
    sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width /2) - 445,
    (sf::VideoMode::getDesktopMode().height / 2) - 390);

    window.create(sf::VideoMode(900,400), "SFML GAME Paxton Proctor", sf::Style::Titlebar | sf::Style::Close);
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

    // creation of window and events within window
    while (window.isOpen())
    {
        sf::Event event;

        // movement speed of player
        const float moveSpeed = 0.2;

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

        // event to close the window and for key release with bool
        while (window.pollEvent(event)) {
            switch (event.type){
            
            case sf::Event::Closed:
                window.close();

            case sf::Event::KeyReleased:
                moving = false;
            }
        }
        
        window.clear();
        // draws both player and collision object
        Player.drawTo(window);
        box.drawTo(window);
        // displays the objects
        window.display();
    }

    return 0;
}

