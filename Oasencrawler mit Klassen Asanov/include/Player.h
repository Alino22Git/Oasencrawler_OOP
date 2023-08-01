#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>
#include "Gameworld.h"

class Player
{
    public:
        Player(int lifepoints, Gameworld *world);
        void playerInfo();
        int move(char direction);
        void findItem();
        void react();
        int odds(int odd,int probability,int type);
        void storytelling(int story);
        void reactToSpring();
        void reactToDanger();
                void increaseLevel();



        int Getx() const;
        int Gety() const;
        int GetLifepoints() const;
        int GetItem() const;
        Gameworld* GetWorld();
        void SetWorld(Gameworld* gw);
        int GetLevel() const;
        int GetRespectpoints() const;
        std::string GetPlayerLog();

    protected:

    private:
        int x;
        int y;
        int lifepoints;
        int respectpoints;
        int item;
        int level = 1;
        Gameworld *world;
        std::string playerlog;
        };

#endif // PLAYER_H
