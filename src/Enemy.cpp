#include "Enemy.h"
#include <SFML/Window/Keyboard.hpp>
#include <cstdlib>

Enemy::Enemy(int x, int y, int vidas){

_vidas=vidas;
txtEnemy.loadFromFile("assets/images/bloquenemigo2.png");
spEnemy.setTexture(txtEnemy);
spEnemy.setPosition(x*60,y*30);
spEnemy.setScale(0.2,0.2);
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


void Enemy::changeColour(){
txtEnemy.loadFromFile("assets/images/bloquenemigo.png");
spEnemy.setTexture(txtEnemy);
}

int Enemy::getVidas(){
return _vidas;
}

void Enemy::disminuir(){
_vidas--;
}

//Enemy::~Enemy(){
//delete Enemy[];
//}
