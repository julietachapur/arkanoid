#include <iostream>
using namespace std;
#include "Global.h"

Global::Global(){
}
void Global::setCero(){
    highScore = 0;
    lastScore = 0;
    cout<<highScore;
    cout<<lastScore;
}
void Global::setHighScore(int h){
    highScore=h;
}
void Global::setLastScore(int l){
    lastScore=l;
}
int Global::getHighScore(){
    return highScore;
}
int Global::getLastScore(){
    return lastScore;
}
