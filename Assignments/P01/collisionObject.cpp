#pragma

#include <iostream>
#include <SFML\Graphics.hpp>
#include "collisionObject.h"
#include <vector>

// creation of the size and color of the collision object
Box::Box(sf::Vector2f size) {
    box.setSize(size);
    box.setFillColor(sf::Color::Red);
}

// draws the collision object in the window
void Box::drawTo(sf::RenderWindow &window) {
    window.draw(box);
}

// moves the collision object to a certain position based on distance
void Box::move(sf::Vector2f distance) {
    box.move(distance);
}

// creates collision object postion
void Box::setPos(sf::Vector2f newPos){
    box.setPosition(newPos);
}