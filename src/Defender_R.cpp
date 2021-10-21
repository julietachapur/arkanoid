#include "../include/Defender_R.h"
#include <SFML/Window/Keyboard.hpp>


Defender_R::Defender_R(const sf::Vector2f &pos){
    /*Aquí cargamos la imagen de la paleta izquierda e indicamos su posicion*/
    texDefender_R.loadFromFile("assets/images/defenderR.png");
    spDefender_R.setTexture(texDefender_R);
    spDefender_R.setPosition(pos);
    spDefender_R.setScale(0.80,0.80);
}

void Defender_R::update(){
    /*Aqui la idea es que si se apreta la tecla a se mueva 45 grados , si se suelta vuelve a su lugar*/
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        spDefender_R.setRotation(60);
        spDefender_R.setPosition(270,340);}
    else{
        spDefender_R.setRotation(0);
        spDefender_R.setPosition(210,390);}
}
void Defender_R::draw(sf::RenderWindow &w){
    w.draw(spDefender_R);
}

sf::Sprite &Defender_R::getSprite(){
    return spDefender_R;}


bool Defender_R::isCollision(const Collisionable& _object)const{
   return getBounds().intersects(_object.getBounds());
}

sf::FloatRect Defender_R::getBounds()const{
    sf::FloatRect rect= spDefender_R.getGlobalBounds();
    rect.left = spDefender_R.getPosition().x;
    rect.top = spDefender_R.getPosition().y;
    return rect;}
