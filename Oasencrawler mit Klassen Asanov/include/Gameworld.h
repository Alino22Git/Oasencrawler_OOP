#ifndef GAMEWORLD_H
#define GAMEWORLD_H
#include <iostream>
#include <string>
#include "Person.h"

class Gameworld
{
    public:
        Gameworld();
        Gameworld(int size, int relics, Person *p);
        void createWorld();
        int getFieldOfWorld(int x, int y);
        void printWorld(int posx,int posy);
        void printVillain(int posx,int posy);
        void setField(int x, int y, int fieldtype);

        void SetRelics(int i);
        int GetRelics() const;
        int GetSize() const;
        Person *GetPerson();



    private:
        int fields[22][22];
        int size;
        int relics;
        Person *p;
        };

#endif // GAMEWORLD_H
