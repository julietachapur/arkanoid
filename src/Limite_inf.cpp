#include "Limite_inf.h"

Limite_inf::Limite_inf(const sf::Vector2f &pos)
{
  limit.setSize(pos);
  limit.setFillColor(sf::Color::White);
  limit.setScale(0.2,0.2);
  limit.setOrigin(2,2);
  limit.setPosition(150,390);
  }


void Limite_inf::draw(sf::RenderWindow &w){
    w.draw(limit);
}


sf::FloatRect Limite_inf::getBounds()const{
    sf::FloatRect rect = limit.getGlobalBounds();
    rect.left = limit.getPosition().x;
    rect.top = limit.getPosition().y;
    return rect;}

bool Limite_inf::isCollision(const Collisionable& _object)const{
    bool collision = getBounds().intersects(_object.getBounds());
    return collision;
}
