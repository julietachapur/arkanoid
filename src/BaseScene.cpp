 #include "BaseScene.h"
#include <string>
#include <iostream>
#include <sstream>

BaseScene::BaseScene(){
}

void BaseScene::update() {
    for(auto o: objects){
        o-> update();
    }
}

void BaseScene::draw(sf::RenderWindow &w){
    for(auto o: objects){
        o-> draw(w);
    }
}

void BaseScene::add(Object *o){
    objects.push_back(o);
}
