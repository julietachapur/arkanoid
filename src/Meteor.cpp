#include "../include/Meteor.h"


Meteor::Meteor(){
    /*Aquí cargamos la imagen del meteorito e indicamos su posicion*/
    texMeteor.loadFromFile("assets/images/meteor.png");
    spMeteor.setTexture(texMeteor);
    spMeteor.setOrigin(spMeteor.getLocalBounds().width/2.0f, spMeteor.getLocalBounds().height/2.0f);
    spMeteor.setScale(0.25,0.25);
    srand(time(0)); //que se mueva random
    spMeteor.setPosition(rand()%200, 200);
    velMeteor.x = 2+rand()%3;
    velMeteor.y = 2+rand()%3;
}

void Meteor::update(){
    /* Aquí iniciamos en un lugar random el meteorito y luego lo mantenemos
    en un rango para que no se escape de la pantalla.*/
    spMeteor.move(velMeteor);
    sf::Vector2f meteorPos = spMeteor.getPosition();

    if(meteorPos.x < 0){
        spMeteor.setPosition(0.25, meteorPos.y);
        velMeteor.x *= -1;
    }
    if(meteorPos.x > 388 ){
        spMeteor.setPosition(388, meteorPos.y);
        velMeteor.x *= -1;
        spMeteor.setRotation(rand()%360);
    }
    if(meteorPos.y < 0){
        spMeteor.setPosition(meteorPos.x,0.25);
        velMeteor.y *= -1;
    }
    if(meteorPos.y > 381){
        spMeteor.setPosition(meteorPos.x,381);
        velMeteor.y *= -1;
        spMeteor.setRotation(360);
    }
    velMeteor.y += 0.02;
    spMeteor.move(velMeteor);

}
void Meteor::moveMeteor(const Collisionable& p){
    sf::Vector2f velMeteor = getVelocity();

    if(velMeteor.y >0){
        float diferencia = getBounds().top + getBounds().height - p.getBounds().top;
        spMeteor.move(0,diferencia);
        velMeteor.y *= -1;
    }

    if(velMeteor.y < 0){
        float diferencia = p.getBounds().top + p.getBounds().height - getBounds().top;
        spMeteor.move(0,-diferencia);
        velMeteor.y *= -1;
    }
}
const sf::Vector2f& Meteor::getVelocity()const{
    return velMeteor;
}

void Meteor::draw(sf::RenderWindow &w){
    w.draw(spMeteor);
}

sf::Sprite &Meteor::getSprite(){
    return spMeteor;}


bool Meteor::isCollision(const Collisionable& _object)const{
    bool collision = getBounds().intersects(_object.getBounds());
   return collision;
}

sf::FloatRect Meteor::getBounds()const{
    sf::FloatRect rect= spMeteor.getGlobalBounds();
    rect.left = spMeteor.getPosition().x;
    rect.top = spMeteor.getPosition().y;
    return rect;}

