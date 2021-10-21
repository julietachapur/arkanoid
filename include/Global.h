#ifndef GLOBAL_H
#define GLOBAL_H


class Global
{
    public:
        Global();
        void setHighScore(int h);
        void setLastScore(int l);
        void setCero();
        int getHighScore();
        int getLastScore();
    private:
        int highScore;
        int lastScore;
};



#endif // GLOBAL_H
