#include "LimiteGameOver.h"

LimiteGameOver::LimiteGameOver()
{
    limit.setSize(sf::Vector2f(400,1));
    limit.setFillColor(sf::Color::White);
    limit.setPosition(0,410);
}

void LimiteGameOver::update(){
}

void LimiteGameOver::draw(sf::RenderWindow &w){
w.draw(limit);
}

bool LimiteGameOver::isCollision(const Collisionable& _object)const{
   return getBounds().intersects(_object.getBounds());
}

sf::FloatRect LimiteGameOver::getBounds()const{
    sf::FloatRect rect= limit.getGlobalBounds();
    rect.left = limit.getPosition().x;
    rect.top = limit.getPosition().y;
    return rect;}

