#include "Enemy.h"
#include <SFML/Window/Keyboard.hpp>

Enemy::Enemy(){
txtEnemy.loadFromFile("assets/images/bloquenemigo.png");
spEnemy.setTexture(txtEnemy);
spEnemy.setPosition(210,120);
spEnemy.setScale(0.3,0.2);
spEnemy.setOrigin(2,2);
}

void Enemy::update(){
}

void Enemy::draw(sf::RenderWindow &w){
w.draw(spEnemy);
}

bool Enemy::isCollision(const Collisionable& _object)const{
   return getBounds().intersects(_object.getBounds());
}

sf::Sprite &Enemy::getSprite(){
    return spEnemy;}

sf::FloatRect Enemy::getBounds()const{
    sf::FloatRect rect= spEnemy.getGlobalBounds();
    rect.left = spEnemy.getPosition().x;
    rect.top = spEnemy.getPosition().y;
    return rect;}


void Enemy::disapear(){
spEnemy.setPosition(-100,0);
}


//Enemy::~Enemy(){
//delete Enemy[];
//}