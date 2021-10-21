#ifndef GAME_H
#define GAME_H
#include "BaseScene.h"


class Game{
    public:
        void run();
        void switchScene(BaseScene *scene);
        static Game &getInstance();
        static Game &create(const sf::VideoMode &videoMode, BaseScene *scene, const string &name = "");

    private:
        sf::RenderWindow w;
        BaseScene *currentScene, *nextScene;
        void update();
        void draw();
        static Game *instance;
        Game();
        bool pause = false;
};

#endif // GAME_H
