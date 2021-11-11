#ifndef GLOBALSCORE_H
#define GLOBALSCORE_H


class GlobalScore
{
    public:
        GlobalScore();
       void setHighScore(int n);
       void setLastScore(int n);

       void setCero();

       int getHighScore();
       int getLastScore():

    private:

        int highScore;
        int lastScore;
};

#endif // GLOBALSCORE_H
