#include "../include/Defender_L.h"
#include <SFML/Window/Keyboard.hpp>
#include "math.h"
Defender_L::Defender_L(const sf::Vector2f &pos){
    /*Aquí cargamos la imagen de la paleta izquierda e indicamos su posicion*/
    texDefender_L.loadFromFile("assets/images/defenderL.png");
    spDefender_L.setTexture(texDefender_L);
    spDefender_L.setPosition(pos);
    spDefender_L.setScale(0.80,0.80);


}

void Defender_L::update(){

    /*Aqui la idea es que si se apreta la tecla a se mueva 45 grados , si se suelta vuelve a su lugar*/
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        spDefender_L.setRotation(-60);
        spDefender_L.setPosition(100,405);
        }
    else{
        spDefender_L.setRotation(0);
        spDefender_L.setPosition(100,390);
    }
}
void Defender_L::draw(sf::RenderWindow &w){
    w.draw(spDefender_L);
}

sf::Sprite &Defender_L::getSprite(){
    return spDefender_L;}

bool Defender_L::isCollision(const Collisionable& _object)const{
   return getBounds().intersects(_object.getBounds());
}

sf::FloatRect Defender_L::getBounds()const{
    sf::FloatRect rect= spDefender_L.getGlobalBounds();
    rect.left = spDefender_L.getPosition().x;
    rect.top = spDefender_L.getPosition().y;
    return rect;}
