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
}

// creates player postion
void player::setPos(sf::Vector2f newPos){
    Player.setPosition(newPos);
}