#pragma

#include <iostream>
#include <SFML\Graphics.hpp>
#include <vector>

// creates a player
class player {
    private:
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
};