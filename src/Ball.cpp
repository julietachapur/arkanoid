#include "Ball.h"
#include <SFML/Graphics/Texture.hpp>
Ball::Ball(){
    texBall.loadFromFile("assets/images/meteor.png");
    spBall.setTexture(texBall);
    spBall.scale(0.2,0.2);
    spBall.setOrigin(2,2);
    srand(time(0)); //que se mueva random
    spBall.setPosition(rand()%200, 200);


    velBall.x = 2+rand()%3;
    velBall.y = 2+rand()%3;
}

void Ball::update(){

    spBall.move(velBall);
    sf::Vector2f ballPos = spBall.getPosition();

    if(ballPos.x < 0){
        spBall.setPosition(10, ballPos.y);
        velBall.x *= -1;
    }
    if(ballPos.x >380){
        spBall.setPosition(380-10, ballPos.y);
        velBall.x *= -1;
    }
    if(ballPos.y < 0){
        spBall.setPosition(ballPos.x,10);
        velBall.y *= -1;
    }
    if(ballPos.y > 480){
        spBall.setPosition(ballPos.x,480-10);
        velBall.y *= -1;
    }
    //velBall.y += 0.02;
    spBall.move(velBall);

}
void Ball::moveBall(const Collisionable& p){
    sf::Vector2f velBall = getVelocity();

    if(velBall.y >0){
        float diferencia = getBounds().top + getBounds().height - p.getBounds().top;
        spBall.move(0,diferencia);
        velBall.y *= -1;
    }

    if(velBall.y < 0){
        float diferencia = p.getBounds().top + p.getBounds().height - getBounds().top;
        spBall.move(0,-diferencia);
        velBall.y *= -1;
    }
}
const sf::Vector2f& Ball::getVelocity()const{
    return velBall;
}

void Ball::draw(sf::RenderWindow &w){
    w.draw(spBall);
}

sf::Sprite &Ball::getSprite(){
    return spBall;}


bool Ball::isCollision(const Collisionable& _object)const{
    bool collision = getBounds().intersects(_object.getBounds());
   return collision;
}

sf::FloatRect Ball::getBounds()const{
    sf::FloatRect rect = spBall.getGlobalBounds();
    rect.left = spBall.getPosition().x;
    rect.top = spBall.getPosition().y;
    return rect;}
