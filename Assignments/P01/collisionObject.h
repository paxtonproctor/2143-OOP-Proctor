#include <SFML\Graphics.hpp>
#include <vector>

// creates a collision object
class Box {
    private:
    // variable box is created as a
    sf::RectangleShape box;
    public:
    // will create size of box
    Box(sf::Vector2f size);
    // will draw box
    void drawTo(sf::RenderWindow &window);
    // will move box
    void move(sf::Vector2f distance);
    // will set starting position of box
    void setPos(sf::Vector2f newPos);
};